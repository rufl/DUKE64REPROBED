#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void dmulscale6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090414: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009041C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090420: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090424: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090428: jal         0x800BB8F8
    // 0x8009042C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8009042C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090430: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090434: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090438: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8009043C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090440: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090444: jal         0x800BB8F8
    // 0x80090448: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090448: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x8009044C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090450: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090454: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090458: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x8009045C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090460: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090464: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090468: jal         0x800BBA24
    // 0x8009046C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x8009046C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_2:
    // 0x80090470: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090474: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090478: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009047C: jr          $ra
    // 0x80090480: nop

    return;
    // 0x80090480: nop

;}
RECOMP_FUNC void dmulscale15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090804: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009080C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090810: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090814: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090818: jal         0x800BB8F8
    // 0x8009081C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8009081C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090820: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090824: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090828: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8009082C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090830: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090834: jal         0x800BB8F8
    // 0x80090838: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090838: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x8009083C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090840: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090844: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090848: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x8009084C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090850: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090854: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090858: jal         0x800BBA24
    // 0x8009085C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x8009085C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_2:
    // 0x80090860: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090864: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090868: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009086C: jr          $ra
    // 0x80090870: nop

    return;
    // 0x80090870: nop

;}
RECOMP_FUNC void alHeapInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF890: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x800BF894: andi        $t6, $a1, 0xF
    ctx->r14 = ctx->r5 & 0XF;
    // 0x800BF898: subu        $v0, $v1, $t6
    ctx->r2 = SUB32(ctx->r3, ctx->r14);
    // 0x800BF89C: beq         $v1, $v0, L_800BF8AC
    if (ctx->r3 == ctx->r2) {
        // 0x800BF8A0: addu        $t7, $a1, $v0
        ctx->r15 = ADD32(ctx->r5, ctx->r2);
            goto L_800BF8AC;
    }
    // 0x800BF8A0: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x800BF8A4: b           L_800BF8B0
    // 0x800BF8A8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_800BF8B0;
    // 0x800BF8A8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_800BF8AC:
    // 0x800BF8AC: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_800BF8B0:
    // 0x800BF8B0: lw          $t8, 0x0($a0)
    ctx->r24 = S32(MEM_W(ctx->r4, 0X0));
    // 0x800BF8B4: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x800BF8B8: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800BF8BC: jr          $ra
    // 0x800BF8C0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    return;
    // 0x800BF8C0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void RNCDecompress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070BAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80070BB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80070BB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80070BB8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80070BBC: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80070BC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80070BC4: bne         $t6, $at, L_80070BEC
    if (ctx->r14 != ctx->r1) {
        // 0x80070BC8: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80070BEC;
    }
    // 0x80070BC8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80070BCC: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    // 0x80070BD0: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x80070BD4: bne         $t7, $at, L_80070BEC
    if (ctx->r15 != ctx->r1) {
        // 0x80070BD8: nop
    
            goto L_80070BEC;
    }
    // 0x80070BD8: nop

    // 0x80070BDC: lbu         $t8, 0x2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2);
    // 0x80070BE0: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x80070BE4: beql        $t8, $at, L_80070BF8
    if (ctx->r24 == ctx->r1) {
        // 0x80070BE8: lbu         $t0, 0x4($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X4);
            goto L_80070BF8;
    }
    goto skip_0;
    // 0x80070BE8: lbu         $t0, 0x4($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X4);
    skip_0:
L_80070BEC:
    // 0x80070BEC: b           L_80070C94
    // 0x80070BF0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80070C94;
    // 0x80070BF0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80070BF4: lbu         $t0, 0x4($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X4);
L_80070BF8:
    // 0x80070BF8: lbu         $t9, 0x7($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7);
    // 0x80070BFC: lbu         $t3, 0x5($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X5);
    // 0x80070C00: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
    // 0x80070C04: lbu         $a0, 0x3($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X3);
    // 0x80070C08: sll         $t1, $t0, 24
    ctx->r9 = S32(ctx->r8 << 24);
    // 0x80070C0C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80070C10: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80070C14: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80070C18: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80070C1C: beq         $a0, $zero, L_80070C44
    if (ctx->r4 == 0) {
        // 0x80070C20: or          $a2, $t5, $t7
        ctx->r6 = ctx->r13 | ctx->r15;
            goto L_80070C44;
    }
    // 0x80070C20: or          $a2, $t5, $t7
    ctx->r6 = ctx->r13 | ctx->r15;
    // 0x80070C24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80070C28: beq         $a0, $at, L_80070C58
    if (ctx->r4 == ctx->r1) {
        // 0x80070C2C: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80070C58;
    }
    // 0x80070C2C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80070C30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80070C34: beq         $a0, $at, L_80070C68
    if (ctx->r4 == ctx->r1) {
        // 0x80070C38: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80070C68;
    }
    // 0x80070C38: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80070C3C: b           L_80070C78
    // 0x80070C40: ori         $v1, $zero, 0xFFFE
    ctx->r3 = 0 | 0XFFFE;
        goto L_80070C78;
    // 0x80070C40: ori         $v1, $zero, 0xFFFE
    ctx->r3 = 0 | 0XFFFE;
L_80070C44:
    // 0x80070C44: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80070C48: jal         0x8005A490
    // 0x80070C4C: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    fastmemcpy(rdram, ctx);
        goto after_0;
    // 0x80070C4C: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    after_0:
    // 0x80070C50: b           L_80070C78
    // 0x80070C54: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80070C78;
    // 0x80070C54: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80070C58:
    // 0x80070C58: jal         0x8007099C
    // 0x80070C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    RNCDecompress1(rdram, ctx);
        goto after_1;
    // 0x80070C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80070C60: b           L_80070C78
    // 0x80070C64: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
        goto L_80070C78;
    // 0x80070C64: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_80070C68:
    // 0x80070C68: jal         0x8007070C
    // 0x80070C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    RNCDecompress2(rdram, ctx);
        goto after_2;
    // 0x80070C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80070C70: b           L_80070C78
    // 0x80070C74: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
        goto L_80070C78;
    // 0x80070C74: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_80070C78:
    // 0x80070C78: beq         $v1, $zero, L_80070C88
    if (ctx->r3 == 0) {
        // 0x80070C7C: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80070C88;
    }
    // 0x80070C7C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80070C80:
    // 0x80070C80: b           L_80070C80
    pause_self(rdram);
    // 0x80070C84: nop

L_80070C88:
    // 0x80070C88: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80070C8C: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80070C90: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80070C94:
    // 0x80070C94: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80070C98: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80070C9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80070CA0: jr          $ra
    // 0x80070CA4: nop

    return;
    // 0x80070CA4: nop

;}
RECOMP_FUNC void checkcursectnums(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACE04: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x800ACE08: lw          $v0, -0x540C($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, -0X540C));
    // 0x800ACE0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800ACE10: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800ACE14: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800ACE18: blez        $v0, L_800ACE80
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800ACE1C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800ACE80;
    }
    // 0x800ACE1C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800ACE20: lui         $a2, 0x802A
    ctx->r6 = S32(0X802A << 16);
    // 0x800ACE24: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x800ACE28: addiu       $a1, $a1, 0x6BA8
    ctx->r5 = ADD32(ctx->r5, 0X6BA8);
    // 0x800ACE2C: addiu       $a2, $a2, 0x5770
    ctx->r6 = ADD32(ctx->r6, 0X5770);
    // 0x800ACE30: addiu       $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
    // 0x800ACE34: addiu       $a3, $zero, 0x38C
    ctx->r7 = ADD32(0, 0X38C);
L_800ACE38:
    // 0x800ACE38: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ACE3C: mflo        $t8
    ctx->r24 = lo;
    // 0x800ACE40: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x800ACE44: lh          $t1, 0x2E0($t9)
    ctx->r9 = S32(MEM_H(ctx->r25, 0X2E0));
    // 0x800ACE48: multu       $t1, $t0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ACE4C: mflo        $t2
    ctx->r10 = lo;
    // 0x800ACE50: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x800ACE54: lh          $t4, 0x10($t3)
    ctx->r12 = S32(MEM_H(ctx->r11, 0X10));
    // 0x800ACE58: bnel        $a0, $t4, L_800ACE6C
    if (ctx->r4 != ctx->r12) {
        // 0x800ACE5C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800ACE6C;
    }
    goto skip_0;
    // 0x800ACE5C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x800ACE60: jr          $ra
    // 0x800ACE64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800ACE64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800ACE68: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800ACE6C:
    // 0x800ACE6C: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x800ACE70: sra         $v1, $t5, 16
    ctx->r3 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800ACE74: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800ACE78: bne         $at, $zero, L_800ACE38
    if (ctx->r1 != 0) {
        // 0x800ACE7C: nop
    
            goto L_800ACE38;
    }
    // 0x800ACE7C: nop

L_800ACE80:
    // 0x800ACE80: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800ACE84: jr          $ra
    // 0x800ACE88: nop

    return;
    // 0x800ACE88: nop

;}
RECOMP_FUNC void func_8004D664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D664: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004D668: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8004D66C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004D670: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x8004D674: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x8004D678: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8004D67C: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x8004D680: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x8004D684: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8004D688: addiu       $t9, $t9, -0x6C30
    ctx->r25 = ADD32(ctx->r25, -0X6C30);
    // 0x8004D68C: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x8004D690: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004D694: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x8004D698: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x8004D69C: addiu       $s1, $zero, 0x100
    ctx->r17 = ADD32(0, 0X100);
    // 0x8004D6A0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8004D6A4: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x8004D6A8: addiu       $s4, $zero, 0x20
    ctx->r20 = ADD32(0, 0X20);
    // 0x8004D6AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004D6B0: addiu       $t5, $zero, 0x200
    ctx->r13 = ADD32(0, 0X200);
    // 0x8004D6B4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8004D6B8: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8004D6BC: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
    // 0x8004D6C0: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x8004D6C4: addiu       $t0, $zero, 0x400
    ctx->r8 = ADD32(0, 0X400);
L_8004D6C8:
    // 0x8004D6C8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8004D6CC: addu        $a0, $a1, $t6
    ctx->r4 = ADD32(ctx->r5, ctx->r14);
    // 0x8004D6D0: lw          $a2, 0x0($a0)
    ctx->r6 = S32(MEM_W(ctx->r4, 0X0));
    // 0x8004D6D4: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
    // 0x8004D6D8: sltiu       $at, $a3, 0x201
    ctx->r1 = ctx->r7 < 0X201 ? 1 : 0;
    // 0x8004D6DC: bne         $at, $zero, L_8004D6FC
    if (ctx->r1 != 0) {
        // 0x8004D6E0: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_8004D6FC;
    }
    // 0x8004D6E0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8004D6E4: beql        $a3, $t0, L_8004D77C
    if (ctx->r7 == ctx->r8) {
        // 0x8004D6E8: sw          $t4, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r12;
            goto L_8004D77C;
    }
    goto skip_0;
    // 0x8004D6E8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    skip_0:
    // 0x8004D6EC: beql        $a3, $t1, L_8004D770
    if (ctx->r7 == ctx->r9) {
        // 0x8004D6F0: sw          $t3, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r11;
            goto L_8004D770;
    }
    goto skip_1;
    // 0x8004D6F0: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    skip_1:
    // 0x8004D6F4: b           L_8004D7CC
    // 0x8004D6F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8004D7CC;
    // 0x8004D6F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8004D6FC:
    // 0x8004D6FC: sltiu       $at, $a3, 0x101
    ctx->r1 = ctx->r7 < 0X101 ? 1 : 0;
    // 0x8004D700: bnel        $at, $zero, L_8004D71C
    if (ctx->r1 != 0) {
        // 0x8004D704: sltiu       $at, $a3, 0x21
        ctx->r1 = ctx->r7 < 0X21 ? 1 : 0;
            goto L_8004D71C;
    }
    goto skip_2;
    // 0x8004D704: sltiu       $at, $a3, 0x21
    ctx->r1 = ctx->r7 < 0X21 ? 1 : 0;
    skip_2:
    // 0x8004D708: beql        $a3, $t5, L_8004D788
    if (ctx->r7 == ctx->r13) {
        // 0x8004D70C: sw          $s0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r16;
            goto L_8004D788;
    }
    goto skip_3;
    // 0x8004D70C: sw          $s0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r16;
    skip_3:
    // 0x8004D710: b           L_8004D7CC
    // 0x8004D714: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8004D7CC;
    // 0x8004D714: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004D718: sltiu       $at, $a3, 0x21
    ctx->r1 = ctx->r7 < 0X21 ? 1 : 0;
L_8004D71C:
    // 0x8004D71C: bne         $at, $zero, L_8004D734
    if (ctx->r1 != 0) {
        // 0x8004D720: addiu       $t7, $a3, -0x1
        ctx->r15 = ADD32(ctx->r7, -0X1);
            goto L_8004D734;
    }
    // 0x8004D720: addiu       $t7, $a3, -0x1
    ctx->r15 = ADD32(ctx->r7, -0X1);
    // 0x8004D724: beql        $a3, $s1, L_8004D794
    if (ctx->r7 == ctx->r17) {
        // 0x8004D728: sw          $s2, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r18;
            goto L_8004D794;
    }
    goto skip_4;
    // 0x8004D728: sw          $s2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r18;
    skip_4:
    // 0x8004D72C: b           L_8004D7CC
    // 0x8004D730: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8004D7CC;
    // 0x8004D730: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8004D734:
    // 0x8004D734: sltiu       $at, $t7, 0x20
    ctx->r1 = ctx->r15 < 0X20 ? 1 : 0;
    // 0x8004D738: beq         $at, $zero, L_8004D7C8
    if (ctx->r1 == 0) {
        // 0x8004D73C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8004D7C8;
    }
    // 0x8004D73C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004D740: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8004D744: addu        $at, $at, $t7
    gpr jr_addend_8004D74C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8004D748: lw          $t7, 0x27D0($at)
    ctx->r15 = ADD32(ctx->r1, 0X27D0);
    // 0x8004D74C: jr          $t7
    // 0x8004D750: nop

    switch (jr_addend_8004D74C >> 2) {
        case 0: goto L_8004D7C0; break;
        case 1: goto L_8004D7B4; break;
        case 2: goto L_8004D7C8; break;
        case 3: goto L_8004D7A8; break;
        case 4: goto L_8004D7C8; break;
        case 5: goto L_8004D7C8; break;
        case 6: goto L_8004D7C8; break;
        case 7: goto L_8004D79C; break;
        case 8: goto L_8004D7C8; break;
        case 9: goto L_8004D7C8; break;
        case 10: goto L_8004D7C8; break;
        case 11: goto L_8004D7C8; break;
        case 12: goto L_8004D7C8; break;
        case 13: goto L_8004D7C8; break;
        case 14: goto L_8004D7C8; break;
        case 15: goto L_8004D760; break;
        case 16: goto L_8004D7C8; break;
        case 17: goto L_8004D7C8; break;
        case 18: goto L_8004D7C8; break;
        case 19: goto L_8004D7C8; break;
        case 20: goto L_8004D7C8; break;
        case 21: goto L_8004D7C8; break;
        case 22: goto L_8004D7C8; break;
        case 23: goto L_8004D7C8; break;
        case 24: goto L_8004D7C8; break;
        case 25: goto L_8004D7C8; break;
        case 26: goto L_8004D7C8; break;
        case 27: goto L_8004D7C8; break;
        case 28: goto L_8004D7C8; break;
        case 29: goto L_8004D7C8; break;
        case 30: goto L_8004D7C8; break;
        case 31: goto L_8004D754; break;
        default: switch_error(__func__, 0x8004D74C, 0x801027D0);
    }
    // 0x8004D750: nop

L_8004D754:
    // 0x8004D754: sw          $s3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r19;
    // 0x8004D758: b           L_8004D7C8
    // 0x8004D75C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
        goto L_8004D7C8;
    // 0x8004D75C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
L_8004D760:
    // 0x8004D760: sw          $s4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r20;
    // 0x8004D764: b           L_8004D7C8
    // 0x8004D768: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
        goto L_8004D7C8;
    // 0x8004D768: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8004D76C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
L_8004D770:
    // 0x8004D770: b           L_8004D7C8
    // 0x8004D774: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
        goto L_8004D7C8;
    // 0x8004D774: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8004D778: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
L_8004D77C:
    // 0x8004D77C: b           L_8004D7C8
    // 0x8004D780: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
        goto L_8004D7C8;
    // 0x8004D780: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8004D784: sw          $s0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r16;
L_8004D788:
    // 0x8004D788: b           L_8004D7C8
    // 0x8004D78C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
        goto L_8004D7C8;
    // 0x8004D78C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8004D790: sw          $s2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r18;
L_8004D794:
    // 0x8004D794: b           L_8004D7C8
    // 0x8004D798: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
        goto L_8004D7C8;
    // 0x8004D798: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
L_8004D79C:
    // 0x8004D79C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8004D7A0: b           L_8004D7C8
    // 0x8004D7A4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
        goto L_8004D7C8;
    // 0x8004D7A4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
L_8004D7A8:
    // 0x8004D7A8: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8004D7AC: b           L_8004D7C8
    // 0x8004D7B0: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
        goto L_8004D7C8;
    // 0x8004D7B0: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
L_8004D7B4:
    // 0x8004D7B4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8004D7B8: b           L_8004D7C8
    // 0x8004D7BC: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
        goto L_8004D7C8;
    // 0x8004D7BC: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
L_8004D7C0:
    // 0x8004D7C0: sw          $s1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r17;
    // 0x8004D7C4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
L_8004D7C8:
    // 0x8004D7C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8004D7CC:
    // 0x8004D7CC: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x8004D7D0: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004D7D4: and         $t8, $v1, $t2
    ctx->r24 = ctx->r3 & ctx->r10;
    // 0x8004D7D8: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x8004D7DC: or          $t9, $a2, $t8
    ctx->r25 = ctx->r6 | ctx->r24;
    // 0x8004D7E0: bne         $at, $zero, L_8004D6C8
    if (ctx->r1 != 0) {
        // 0x8004D7E4: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_8004D6C8;
    }
    // 0x8004D7E4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8004D7E8: lw          $s0, 0x4($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X4));
    // 0x8004D7EC: lw          $s1, 0x8($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X8));
    // 0x8004D7F0: lw          $s2, 0xC($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0XC));
    // 0x8004D7F4: lw          $s3, 0x10($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X10));
    // 0x8004D7F8: lw          $s4, 0x14($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8004D7FC: jr          $ra
    // 0x8004D800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8004D800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void reportandexit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_80071FA8:
    // 0x80071FA8: b           L_80071FA8
    pause_self(rdram);
    // 0x80071FAC: nop

    // 0x80071FB0: jr          $ra
    // 0x80071FB4: nop

    return;
    // 0x80071FB4: nop

;}
RECOMP_FUNC void ceilingspace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007561C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80075620: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80075624: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80075628: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8007562C: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x80075630: addiu       $t9, $t9, -0x1988
    ctx->r25 = ADD32(ctx->r25, -0X1988);
    // 0x80075634: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80075638: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8007563C: lh          $t0, 0xC($v0)
    ctx->r8 = S32(MEM_H(ctx->r2, 0XC));
    // 0x80075640: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80075644: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80075648: beql        $t1, $zero, L_80075680
    if (ctx->r9 == 0) {
        // 0x8007564C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80075680;
    }
    goto skip_0;
    // 0x8007564C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80075650: lbu         $t2, 0x23($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X23);
    // 0x80075654: bnel        $t2, $zero, L_80075680
    if (ctx->r10 != 0) {
        // 0x80075658: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80075680;
    }
    goto skip_1;
    // 0x80075658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8007565C: lh          $v1, 0x10($v0)
    ctx->r3 = S32(MEM_H(ctx->r2, 0X10));
    // 0x80075660: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x80075664: beq         $v1, $at, L_80075674
    if (ctx->r3 == ctx->r1) {
        // 0x80075668: addiu       $at, $zero, 0x54
        ctx->r1 = ADD32(0, 0X54);
            goto L_80075674;
    }
    // 0x80075668: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x8007566C: bnel        $v1, $at, L_80075680
    if (ctx->r3 != ctx->r1) {
        // 0x80075670: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80075680;
    }
    goto skip_2;
    // 0x80075670: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
L_80075674:
    // 0x80075674: jr          $ra
    // 0x80075678: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80075678: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007567C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80075680:
    // 0x80075680: jr          $ra
    // 0x80075684: nop

    return;
    // 0x80075684: nop

;}
RECOMP_FUNC void deletespritestat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092850: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80092854: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80092858: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8009285C: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80092860: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x80092864: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80092868: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8009286C: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x80092870: addiu       $t9, $t9, 0x6BA8
    ctx->r25 = ADD32(ctx->r25, 0X6BA8);
    // 0x80092874: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80092878: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8009287C: lh          $v0, 0x12($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X12));
    // 0x80092880: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x80092884: lui         $t2, 0x8027
    ctx->r10 = S32(0X8027 << 16);
    // 0x80092888: bne         $t1, $v0, L_80092898
    if (ctx->r9 != ctx->r2) {
        // 0x8009288C: addiu       $t2, $t2, 0x2858
        ctx->r10 = ADD32(ctx->r10, 0X2858);
            goto L_80092898;
    }
    // 0x8009288C: addiu       $t2, $t2, 0x2858
    ctx->r10 = ADD32(ctx->r10, 0X2858);
    // 0x80092890: jr          $ra
    // 0x80092894: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80092894: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80092898:
    // 0x80092898: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x8009289C: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    // 0x800928A0: lh          $t5, 0x0($a1)
    ctx->r13 = S32(MEM_H(ctx->r5, 0X0));
    // 0x800928A4: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x800928A8: addiu       $t3, $t3, 0x4000
    ctx->r11 = ADD32(ctx->r11, 0X4000);
    // 0x800928AC: bne         $a0, $t5, L_800928C8
    if (ctx->r4 != ctx->r13) {
        // 0x800928B0: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_800928C8;
    }
    // 0x800928B0: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x800928B4: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800928B8: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x800928BC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800928C0: lh          $t7, 0x5F40($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X5F40));
    // 0x800928C4: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
L_800928C8:
    // 0x800928C8: addu        $a3, $t3, $v0
    ctx->r7 = ADD32(ctx->r11, ctx->r2);
    // 0x800928CC: lh          $t0, 0x0($a3)
    ctx->r8 = S32(MEM_H(ctx->r7, 0X0));
    // 0x800928D0: lui         $t8, 0x8027
    ctx->r24 = S32(0X8027 << 16);
    // 0x800928D4: addiu       $t8, $t8, 0x5F40
    ctx->r24 = ADD32(ctx->r24, 0X5F40);
    // 0x800928D8: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    // 0x800928DC: bltz        $t0, L_800928F4
    if (SIGNED(ctx->r8) < 0) {
        // 0x800928E0: lh          $a2, 0x0($a1)
        ctx->r6 = S32(MEM_H(ctx->r5, 0X0));
            goto L_800928F4;
    }
    // 0x800928E0: lh          $a2, 0x0($a1)
    ctx->r6 = S32(MEM_H(ctx->r5, 0X0));
    // 0x800928E4: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x800928E8: addu        $t4, $t9, $t8
    ctx->r12 = ADD32(ctx->r25, ctx->r24);
    // 0x800928EC: sh          $a2, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r6;
    // 0x800928F0: lh          $a2, 0x0($a1)
    ctx->r6 = S32(MEM_H(ctx->r5, 0X0));
L_800928F4:
    // 0x800928F4: bltz        $a2, L_80092908
    if (SIGNED(ctx->r6) < 0) {
        // 0x800928F8: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_80092908;
    }
    // 0x800928F8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800928FC: sll         $t5, $a2, 1
    ctx->r13 = S32(ctx->r6 << 1);
    // 0x80092900: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80092904: sh          $t0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r8;
L_80092908:
    // 0x80092908: lh          $a2, 0x800($t2)
    ctx->r6 = S32(MEM_H(ctx->r10, 0X800));
    // 0x8009290C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80092910: bltz        $a2, L_80092920
    if (SIGNED(ctx->r6) < 0) {
        // 0x80092914: sll         $t7, $a2, 1
        ctx->r15 = S32(ctx->r6 << 1);
            goto L_80092920;
    }
    // 0x80092914: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x80092918: addu        $t9, $t3, $t7
    ctx->r25 = ADD32(ctx->r11, ctx->r15);
    // 0x8009291C: sh          $a0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r4;
L_80092920:
    // 0x80092920: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
    // 0x80092924: sh          $a2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r6;
    // 0x80092928: sh          $a0, 0x800($t2)
    MEM_H(0X800, ctx->r10) = ctx->r4;
    // 0x8009292C: sh          $t1, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r9;
    // 0x80092930: jr          $ra
    // 0x80092934: nop

    return;
    // 0x80092934: nop

;}
RECOMP_FUNC void func_8005BB64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BB64: lh          $t6, 0x0($a0)
    ctx->r14 = S32(MEM_H(ctx->r4, 0X0));
    // 0x8005BB68: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x8005BB6C: lh          $t4, -0x9DC($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, -0X9DC));
    // 0x8005BB70: bgez        $t6, L_8005BB80
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005BB74: sra         $t7, $t6, 2
        ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
            goto L_8005BB80;
    }
    // 0x8005BB74: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x8005BB78: addiu       $at, $t6, 0x3
    ctx->r1 = ADD32(ctx->r14, 0X3);
    // 0x8005BB7C: sra         $t7, $at, 2
    ctx->r15 = S32(SIGNED(ctx->r1) >> 2);
L_8005BB80:
    // 0x8005BB80: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8005BB84: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x8005BB88: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005BB8C: swc1        $f6, -0x3C90($at)
    MEM_W(-0X3C90, ctx->r1) = ctx->f6.u32l;
    // 0x8005BB90: lh          $t8, 0x2($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0X2));
    // 0x8005BB94: bgez        $t8, L_8005BBA4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8005BB98: sra         $t9, $t8, 2
        ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
            goto L_8005BBA4;
    }
    // 0x8005BB98: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x8005BB9C: addiu       $at, $t8, 0x3
    ctx->r1 = ADD32(ctx->r24, 0X3);
    // 0x8005BBA0: sra         $t9, $at, 2
    ctx->r25 = S32(SIGNED(ctx->r1) >> 2);
L_8005BBA4:
    // 0x8005BBA4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8005BBA8: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x8005BBAC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005BBB0: swc1        $f10, -0x3C8C($at)
    MEM_W(-0X3C8C, ctx->r1) = ctx->f10.u32l;
    // 0x8005BBB4: lh          $t0, 0x8($a0)
    ctx->r8 = S32(MEM_H(ctx->r4, 0X8));
    // 0x8005BBB8: bgez        $t0, L_8005BBC8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8005BBBC: sra         $t1, $t0, 2
        ctx->r9 = S32(SIGNED(ctx->r8) >> 2);
            goto L_8005BBC8;
    }
    // 0x8005BBBC: sra         $t1, $t0, 2
    ctx->r9 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8005BBC0: addiu       $at, $t0, 0x3
    ctx->r1 = ADD32(ctx->r8, 0X3);
    // 0x8005BBC4: sra         $t1, $at, 2
    ctx->r9 = S32(SIGNED(ctx->r1) >> 2);
L_8005BBC8:
    // 0x8005BBC8: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8005BBCC: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x8005BBD0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005BBD4: swc1        $f18, -0x3C88($at)
    MEM_W(-0X3C88, ctx->r1) = ctx->f18.u32l;
    // 0x8005BBD8: lh          $t2, 0xA($a0)
    ctx->r10 = S32(MEM_H(ctx->r4, 0XA));
    // 0x8005BBDC: bgez        $t2, L_8005BBEC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8005BBE0: sra         $t3, $t2, 2
        ctx->r11 = S32(SIGNED(ctx->r10) >> 2);
            goto L_8005BBEC;
    }
    // 0x8005BBE0: sra         $t3, $t2, 2
    ctx->r11 = S32(SIGNED(ctx->r10) >> 2);
    // 0x8005BBE4: addiu       $at, $t2, 0x3
    ctx->r1 = ADD32(ctx->r10, 0X3);
    // 0x8005BBE8: sra         $t3, $at, 2
    ctx->r11 = S32(SIGNED(ctx->r1) >> 2);
L_8005BBEC:
    // 0x8005BBEC: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8005BBF0: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x8005BBF4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005BBF8: swc1        $f6, -0x3C84($at)
    MEM_W(-0X3C84, ctx->r1) = ctx->f6.u32l;
    // 0x8005BBFC: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8005BC00: beq         $at, $zero, L_8005BC18
    if (ctx->r1 == 0) {
        // 0x8005BC04: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8005BC18;
    }
    // 0x8005BC04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005BC08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005BC0C: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x8005BC10: jr          $ra
    // 0x8005BC14: swc1        $f8, -0x3C80($at)
    MEM_W(-0X3C80, ctx->r1) = ctx->f8.u32l;
    return;
    // 0x8005BC14: swc1        $f8, -0x3C80($at)
    MEM_W(-0X3C80, ctx->r1) = ctx->f8.u32l;
L_8005BC18:
    // 0x8005BC18: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8005BC1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005BC20: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x8005BC24: swc1        $f10, -0x3C80($at)
    MEM_W(-0X3C80, ctx->r1) = ctx->f10.u32l;
    // 0x8005BC28: jr          $ra
    // 0x8005BC2C: nop

    return;
    // 0x8005BC2C: nop

;}
RECOMP_FUNC void func_8004B704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B704: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8004B708: addiu       $t3, $t3, 0x4418
    ctx->r11 = ADD32(ctx->r11, 0X4418);
    // 0x8004B70C: lw          $v1, 0x0($t3)
    ctx->r3 = S32(MEM_W(ctx->r11, 0X0));
    // 0x8004B710: lui         $a0, 0x3E
    ctx->r4 = S32(0X3E << 16);
    // 0x8004B714: addiu       $a0, $a0, -0x5800
    ctx->r4 = ADD32(ctx->r4, -0X5800);
    // 0x8004B718: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8004B71C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8004B720: lui         $t7, 0xFE00
    ctx->r15 = S32(0XFE00 << 16);
    // 0x8004B724: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8004B728: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x8004B72C: lw          $v1, 0x0($t3)
    ctx->r3 = S32(MEM_W(ctx->r11, 0X0));
    // 0x8004B730: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x8004B734: ori         $t4, $t4, 0x1402
    ctx->r12 = ctx->r12 | 0X1402;
    // 0x8004B738: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8004B73C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8004B740: lui         $t9, 0x30
    ctx->r25 = S32(0X30 << 16);
    // 0x8004B744: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8004B748: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8004B74C: lw          $v1, 0x0($t3)
    ctx->r3 = S32(MEM_W(ctx->r11, 0X0));
    // 0x8004B750: lui         $t6, 0xFF10
    ctx->r14 = S32(0XFF10 << 16);
    // 0x8004B754: ori         $t6, $t6, 0x13F
    ctx->r14 = ctx->r14 | 0X13F;
    // 0x8004B758: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8004B75C: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8004B760: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x8004B764: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8004B768: lw          $v1, 0x0($t3)
    ctx->r3 = S32(MEM_W(ctx->r11, 0X0));
    // 0x8004B76C: lui         $t9, 0xFFFC
    ctx->r25 = S32(0XFFFC << 16);
    // 0x8004B770: ori         $t9, $t9, 0xFFFC
    ctx->r25 = ctx->r25 | 0XFFFC;
    // 0x8004B774: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8004B778: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8004B77C: lui         $t8, 0xF700
    ctx->r24 = S32(0XF700 << 16);
    // 0x8004B780: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8004B784: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8004B788: lw          $v1, 0x0($t3)
    ctx->r3 = S32(MEM_W(ctx->r11, 0X0));
    // 0x8004B78C: lui         $t6, 0xF64F
    ctx->r14 = S32(0XF64F << 16);
    // 0x8004B790: ori         $t6, $t6, 0xC3BC
    ctx->r14 = ctx->r14 | 0XC3BC;
    // 0x8004B794: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8004B798: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8004B79C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8004B7A0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8004B7A4: lw          $v1, 0x0($t3)
    ctx->r3 = S32(MEM_W(ctx->r11, 0X0));
    // 0x8004B7A8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8004B7AC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8004B7B0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8004B7B4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8004B7B8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8004B7BC: lw          $v1, 0x0($t3)
    ctx->r3 = S32(MEM_W(ctx->r11, 0X0));
    // 0x8004B7C0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8004B7C4: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8004B7C8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8004B7CC: jr          $ra
    // 0x8004B7D0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    return;
    // 0x8004B7D0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
;}
RECOMP_FUNC void dmulscale19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800909C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800909C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800909CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800909D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800909D4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800909D8: jal         0x800BB8F8
    // 0x800909DC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x800909DC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800909E0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800909E4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800909E8: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800909EC: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800909F0: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800909F4: jal         0x800BB8F8
    // 0x800909F8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x800909F8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x800909FC: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090A00: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090A04: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090A08: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x80090A0C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090A10: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090A14: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090A18: jal         0x800BBA24
    // 0x80090A1C: addiu       $a3, $zero, 0x13
    ctx->r7 = ADD32(0, 0X13);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x80090A1C: addiu       $a3, $zero, 0x13
    ctx->r7 = ADD32(0, 0X13);
    after_2:
    // 0x80090A20: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090A24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090A28: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090A2C: jr          $ra
    // 0x80090A30: nop

    return;
    // 0x80090A30: nop

;}
RECOMP_FUNC void guMtxCatF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3C50: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800C3C54: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C3C58: addiu       $v1, $sp, 0x1C
    ctx->r3 = ADD32(ctx->r29, 0X1C);
    // 0x800C3C5C: addiu       $t3, $sp, 0x5C
    ctx->r11 = ADD32(ctx->r29, 0X5C);
    // 0x800C3C60: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C3C64: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800C3C68: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
L_800C3C6C:
    // 0x800C3C6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C3C70: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800C3C74: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x800C3C78: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800C3C7C: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = S32(MEM_W(ctx->r9, 0X0));
    // 0x800C3C80: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = S32(MEM_W(ctx->r7, 0X0));
    // 0x800C3C84: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C3C88: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = S32(MEM_W(ctx->r5, 0X0));
    // 0x800C3C8C: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800C3C90: beql        $a0, $t2, L_800C3D14
    if (ctx->r4 == ctx->r10) {
        // 0x800C3C94: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_800C3D14;
    }
    goto skip_0;
    // 0x800C3C94: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_0:
    // 0x800C3C98: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_800C3C9C:
    // 0x800C3C9C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C3CA0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800C3CA4: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800C3CA8: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x800C3CAC: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = S32(MEM_W(ctx->r7, 0X4));
    // 0x800C3CB0: lwc1        $f12, 0xC($t1)
    ctx->f12.u32l = S32(MEM_W(ctx->r9, 0XC));
    // 0x800C3CB4: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = S32(MEM_W(ctx->r5, -0X4));
    // 0x800C3CB8: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800C3CBC: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800C3CC0: swc1        $f12, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f12.u32l;
    // 0x800C3CC4: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = S32(MEM_W(ctx->r7, 0X8));
    // 0x800C3CC8: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = S32(MEM_W(ctx->r9, 0X1C));
    // 0x800C3CCC: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = S32(MEM_W(ctx->r5, -0X4));
    // 0x800C3CD0: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800C3CD4: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x800C3CD8: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x800C3CDC: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = S32(MEM_W(ctx->r7, 0XC));
    // 0x800C3CE0: lwc1        $f14, 0x2C($t1)
    ctx->f14.u32l = S32(MEM_W(ctx->r9, 0X2C));
    // 0x800C3CE4: lwc1        $f12, -0x4($a1)
    ctx->f12.u32l = S32(MEM_W(ctx->r5, -0X4));
    // 0x800C3CE8: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800C3CEC: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800C3CF0: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = S32(MEM_W(ctx->r5, 0X0));
    // 0x800C3CF4: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800C3CF8: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x800C3CFC: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = S32(MEM_W(ctx->r7, 0X0));
    // 0x800C3D00: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = S32(MEM_W(ctx->r9, 0X0));
    // 0x800C3D04: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800C3D08: bnel        $a0, $t2, L_800C3C9C
    if (ctx->r4 != ctx->r10) {
        // 0x800C3D0C: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_800C3C9C;
    }
    goto skip_1;
    // 0x800C3D0C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_1:
    // 0x800C3D10: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_800C3D14:
    // 0x800C3D14: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800C3D18: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800C3D1C: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x800C3D20: lwc1        $f12, 0xC($t1)
    ctx->f12.u32l = S32(MEM_W(ctx->r9, 0XC));
    // 0x800C3D24: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = S32(MEM_W(ctx->r7, 0X4));
    // 0x800C3D28: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = S32(MEM_W(ctx->r5, -0X4));
    // 0x800C3D2C: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800C3D30: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800C3D34: swc1        $f12, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f12.u32l;
    // 0x800C3D38: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = S32(MEM_W(ctx->r9, 0X1C));
    // 0x800C3D3C: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = S32(MEM_W(ctx->r7, 0X8));
    // 0x800C3D40: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = S32(MEM_W(ctx->r5, -0X4));
    // 0x800C3D44: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800C3D48: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x800C3D4C: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x800C3D50: lwc1        $f14, 0x2C($t1)
    ctx->f14.u32l = S32(MEM_W(ctx->r9, 0X2C));
    // 0x800C3D54: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = S32(MEM_W(ctx->r7, 0XC));
    // 0x800C3D58: lwc1        $f12, -0x4($a1)
    ctx->f12.u32l = S32(MEM_W(ctx->r5, -0X4));
    // 0x800C3D5C: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800C3D60: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800C3D64: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x800C3D68: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800C3D6C: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x800C3D70: bne         $at, $zero, L_800C3C6C
    if (ctx->r1 != 0) {
        // 0x800C3D74: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_800C3C6C;
    }
    // 0x800C3D74: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800C3D78: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800C3D7C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800C3D80: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
L_800C3D84:
    // 0x800C3D84: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = S32(MEM_W(ctx->r4, 0X0));
    // 0x800C3D88: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800C3D8C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800C3D90: swc1        $f6, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f6.u32l;
    // 0x800C3D94: lwc1        $f8, -0xC($a0)
    ctx->f8.u32l = S32(MEM_W(ctx->r4, -0XC));
    // 0x800C3D98: swc1        $f8, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f8.u32l;
    // 0x800C3D9C: lwc1        $f16, -0x8($a0)
    ctx->f16.u32l = S32(MEM_W(ctx->r4, -0X8));
    // 0x800C3DA0: swc1        $f16, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f16.u32l;
    // 0x800C3DA4: lwc1        $f10, -0x4($a0)
    ctx->f10.u32l = S32(MEM_W(ctx->r4, -0X4));
    // 0x800C3DA8: bne         $a0, $v0, L_800C3D84
    if (ctx->r4 != ctx->r2) {
        // 0x800C3DAC: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_800C3D84;
    }
    // 0x800C3DAC: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x800C3DB0: jr          $ra
    // 0x800C3DB4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800C3DB4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void prelevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB350: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x800AB354: lui         $a2, 0x802B
    ctx->r6 = S32(0X802B << 16);
    // 0x800AB358: lw          $a2, -0x540C($a2)
    ctx->r6 = S32(MEM_W(ctx->r6, -0X540C));
    // 0x800AB35C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AB360: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x800AB364: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AB368: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AB36C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AB370: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AB374: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AB378: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    // 0x800AB37C: blez        $a2, L_800AB3C0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800AB380: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800AB3C0;
    }
    // 0x800AB380: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AB384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AB388:
    // 0x800AB388: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x800AB38C: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AB390: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800AB394: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x800AB398: jal         0x800AB188
    // 0x800AB39C: sb          $v1, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r3;
    resetprestat(rdram, ctx);
        goto after_0;
    // 0x800AB39C: sb          $v1, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r3;
    after_0:
    // 0x800AB3A0: lbu         $v1, 0x57($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X57);
    // 0x800AB3A4: lui         $a2, 0x802B
    ctx->r6 = S32(0X802B << 16);
    // 0x800AB3A8: lw          $a2, -0x540C($a2)
    ctx->r6 = S32(MEM_W(ctx->r6, -0X540C));
    // 0x800AB3AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AB3B0: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800AB3B4: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800AB3B8: bne         $at, $zero, L_800AB388
    if (ctx->r1 != 0) {
        // 0x800AB3BC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800AB388;
    }
    // 0x800AB3BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800AB3C0:
    // 0x800AB3C0: lui         $t2, 0x802B
    ctx->r10 = S32(0X802B << 16);
    // 0x800AB3C4: lh          $t2, -0x5378($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, -0X5378));
    // 0x800AB3C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AB3CC: addiu       $ra, $zero, 0x7FFF
    ctx->r31 = ADD32(0, 0X7FFF);
    // 0x800AB3D0: blez        $t2, L_800AB4F4
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800AB3D4: addiu       $t5, $zero, 0x16
        ctx->r13 = ADD32(0, 0X16);
            goto L_800AB4F4;
    }
    // 0x800AB3D4: addiu       $t5, $zero, 0x16
    ctx->r13 = ADD32(0, 0X16);
    // 0x800AB3D8: lui         $a3, 0x802A
    ctx->r7 = S32(0X802A << 16);
    // 0x800AB3DC: addiu       $a3, $a3, 0x5770
    ctx->r7 = ADD32(ctx->r7, 0X5770);
    // 0x800AB3E0: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x800AB3E4: addiu       $t3, $zero, 0x100
    ctx->r11 = ADD32(0, 0X100);
    // 0x800AB3E8: addiu       $t0, $zero, 0x38C
    ctx->r8 = ADD32(0, 0X38C);
    // 0x800AB3EC: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
L_800AB3F0:
    // 0x800AB3F0: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x800AB3F4: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800AB3F8: addiu       $t9, $t9, -0x1988
    ctx->r25 = ADD32(ctx->r25, -0X1988);
    // 0x800AB3FC: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800AB400: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x800AB404: lh          $v0, 0x18($t1)
    ctx->r2 = S32(MEM_H(ctx->r9, 0X18));
    // 0x800AB408: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800AB40C: sh          $t3, 0x1C($t1)
    MEM_H(0X1C, ctx->r9) = ctx->r11;
    // 0x800AB410: beq         $v0, $t4, L_800AB420
    if (ctx->r2 == ctx->r12) {
        // 0x800AB414: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800AB420;
    }
    // 0x800AB414: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800AB418: bne         $v1, $t5, L_800AB440
    if (ctx->r3 != ctx->r13) {
        // 0x800AB41C: nop
    
            goto L_800AB440;
    }
    // 0x800AB41C: nop

L_800AB420:
    // 0x800AB420: lw          $t6, 0x0($t1)
    ctx->r14 = S32(MEM_W(ctx->r9, 0X0));
    // 0x800AB424: lw          $t7, 0x4($t1)
    ctx->r15 = S32(MEM_W(ctx->r9, 0X4));
    // 0x800AB428: ori         $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 | 0X8000;
    // 0x800AB42C: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800AB430: beql        $at, $zero, L_800AB4E4
    if (ctx->r1 == 0) {
        // 0x800AB434: sll         $t6, $s0, 16
        ctx->r14 = S32(ctx->r16 << 16);
            goto L_800AB4E4;
    }
    goto skip_0;
    // 0x800AB434: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    skip_0:
    // 0x800AB438: b           L_800AB4E0
    // 0x800AB43C: sh          $t8, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r24;
        goto L_800AB4E0;
    // 0x800AB43C: sh          $t8, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r24;
L_800AB440:
    // 0x800AB440: bne         $ra, $v0, L_800AB484
    if (ctx->r31 != ctx->r2) {
        // 0x800AB444: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800AB484;
    }
    // 0x800AB444: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AB448: blez        $a2, L_800AB4E0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800AB44C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800AB4E0;
    }
    // 0x800AB44C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800AB450:
    // 0x800AB450: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB454: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AB458: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x800AB45C: slt         $at, $t8, $a2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800AB460: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800AB464: mflo        $t9
    ctx->r25 = lo;
    // 0x800AB468: addu        $v0, $a3, $t9
    ctx->r2 = ADD32(ctx->r7, ctx->r25);
    // 0x800AB46C: lbu         $t6, 0x365($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X365);
    // 0x800AB470: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800AB474: bne         $at, $zero, L_800AB450
    if (ctx->r1 != 0) {
        // 0x800AB478: sb          $t7, 0x365($v0)
        MEM_B(0X365, ctx->r2) = ctx->r15;
            goto L_800AB450;
    }
    // 0x800AB478: sb          $t7, 0x365($v0)
    MEM_B(0X365, ctx->r2) = ctx->r15;
    // 0x800AB47C: b           L_800AB4E4
    // 0x800AB480: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
        goto L_800AB4E4;
    // 0x800AB480: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
L_800AB484:
    // 0x800AB484: bnel        $v0, $at, L_800AB4E4
    if (ctx->r2 != ctx->r1) {
        // 0x800AB488: sll         $t6, $s0, 16
        ctx->r14 = S32(ctx->r16 << 16);
            goto L_800AB4E4;
    }
    goto skip_1;
    // 0x800AB488: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    skip_1:
    // 0x800AB48C: blez        $a2, L_800AB4E0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800AB490: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800AB4E0;
    }
    // 0x800AB490: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AB494: lh          $t9, 0x8($t1)
    ctx->r25 = S32(MEM_H(ctx->r9, 0X8));
    // 0x800AB498: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800AB49C: addiu       $t7, $t7, 0x61A8
    ctx->r15 = ADD32(ctx->r15, 0X61A8);
    // 0x800AB4A0: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x800AB4A4: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x800AB4A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AB4AC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800AB4B0: lw          $a0, 0x0($v0)
    ctx->r4 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800AB4B4: lw          $a1, 0x4($v0)
    ctx->r5 = S32(MEM_W(ctx->r2, 0X4));
L_800AB4B8:
    // 0x800AB4B8: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB4BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AB4C0: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x800AB4C4: slt         $at, $t9, $a2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800AB4C8: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800AB4CC: mflo        $t8
    ctx->r24 = lo;
    // 0x800AB4D0: addu        $v0, $a3, $t8
    ctx->r2 = ADD32(ctx->r7, ctx->r24);
    // 0x800AB4D4: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x800AB4D8: bne         $at, $zero, L_800AB4B8
    if (ctx->r1 != 0) {
        // 0x800AB4DC: sw          $a1, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r5;
            goto L_800AB4B8;
    }
    // 0x800AB4DC: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
L_800AB4E0:
    // 0x800AB4E0: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
L_800AB4E4:
    // 0x800AB4E4: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800AB4E8: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800AB4EC: bnel        $at, $zero, L_800AB3F0
    if (ctx->r1 != 0) {
        // 0x800AB4F0: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_800AB3F0;
    }
    goto skip_2;
    // 0x800AB4F0: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    skip_2:
L_800AB4F4:
    // 0x800AB4F4: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x800AB4F8: lh          $s0, 0x2858($s0)
    ctx->r16 = S32(MEM_H(ctx->r16, 0X2858));
    // 0x800AB4FC: lui         $a3, 0x802A
    ctx->r7 = S32(0X802A << 16);
    // 0x800AB500: addiu       $a3, $a3, 0x5770
    ctx->r7 = ADD32(ctx->r7, 0X5770);
    // 0x800AB504: bltz        $s0, L_800AB6C0
    if (SIGNED(ctx->r16) < 0) {
        // 0x800AB508: addiu       $t0, $zero, 0x38C
        ctx->r8 = ADD32(0, 0X38C);
            goto L_800AB6C0;
    }
    // 0x800AB508: addiu       $t0, $zero, 0x38C
    ctx->r8 = ADD32(0, 0X38C);
    // 0x800AB50C: lui         $s3, 0x8027
    ctx->r19 = S32(0X8027 << 16);
    // 0x800AB510: lui         $s1, 0x8024
    ctx->r17 = S32(0X8024 << 16);
    // 0x800AB514: addiu       $s1, $s1, 0x6BA8
    ctx->r17 = ADD32(ctx->r17, 0X6BA8);
    // 0x800AB518: addiu       $s3, $s3, 0x5F40
    ctx->r19 = ADD32(ctx->r19, 0X5F40);
    // 0x800AB51C: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
    // 0x800AB520: addiu       $s2, $zero, 0x2C
    ctx->r18 = ADD32(0, 0X2C);
L_800AB524:
    // 0x800AB524: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB528: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x800AB52C: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x800AB530: lh          $t6, 0x0($t9)
    ctx->r14 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800AB534: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AB538: sh          $t6, 0xE4($sp)
    MEM_H(0XE4, ctx->r29) = ctx->r14;
    // 0x800AB53C: mflo        $t7
    ctx->r15 = lo;
    // 0x800AB540: addu        $t1, $s1, $t7
    ctx->r9 = ADD32(ctx->r17, ctx->r15);
    // 0x800AB544: lh          $a1, 0x1E($t1)
    ctx->r5 = S32(MEM_H(ctx->r9, 0X1E));
    // 0x800AB548: bnel        $a1, $at, L_800AB5B0
    if (ctx->r5 != ctx->r1) {
        // 0x800AB54C: lh          $v1, 0xE($t1)
        ctx->r3 = S32(MEM_H(ctx->r9, 0XE));
            goto L_800AB5B0;
    }
    goto skip_3;
    // 0x800AB54C: lh          $v1, 0xE($t1)
    ctx->r3 = S32(MEM_H(ctx->r9, 0XE));
    skip_3:
    // 0x800AB550: lh          $t8, 0xC($t1)
    ctx->r24 = S32(MEM_H(ctx->r9, 0XC));
    // 0x800AB554: lui         $a2, 0x802B
    ctx->r6 = S32(0X802B << 16);
    // 0x800AB558: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x800AB55C: beql        $t9, $zero, L_800AB5B0
    if (ctx->r25 == 0) {
        // 0x800AB560: lh          $v1, 0xE($t1)
        ctx->r3 = S32(MEM_H(ctx->r9, 0XE));
            goto L_800AB5B0;
    }
    goto skip_4;
    // 0x800AB560: lh          $v1, 0xE($t1)
    ctx->r3 = S32(MEM_H(ctx->r9, 0XE));
    skip_4:
    // 0x800AB564: lw          $a2, -0x540C($a2)
    ctx->r6 = S32(MEM_W(ctx->r6, -0X540C));
    // 0x800AB568: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AB56C: blezl       $a2, L_800AB6B8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800AB570: lh          $s0, 0xE4($sp)
        ctx->r16 = S32(MEM_H(ctx->r29, 0XE4));
            goto L_800AB6B8;
    }
    goto skip_5;
    // 0x800AB570: lh          $s0, 0xE4($sp)
    ctx->r16 = S32(MEM_H(ctx->r29, 0XE4));
    skip_5:
    // 0x800AB574: lw          $a0, 0x0($t1)
    ctx->r4 = S32(MEM_W(ctx->r9, 0X0));
    // 0x800AB578: lw          $a1, 0x4($t1)
    ctx->r5 = S32(MEM_W(ctx->r9, 0X4));
L_800AB57C:
    // 0x800AB57C: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB580: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AB584: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x800AB588: slt         $at, $t7, $a2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800AB58C: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800AB590: mflo        $t6
    ctx->r14 = lo;
    // 0x800AB594: addu        $v0, $a3, $t6
    ctx->r2 = ADD32(ctx->r7, ctx->r14);
    // 0x800AB598: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x800AB59C: bne         $at, $zero, L_800AB57C
    if (ctx->r1 != 0) {
        // 0x800AB5A0: sw          $a1, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r5;
            goto L_800AB57C;
    }
    // 0x800AB5A0: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // 0x800AB5A4: b           L_800AB6B8
    // 0x800AB5A8: lh          $s0, 0xE4($sp)
    ctx->r16 = S32(MEM_H(ctx->r29, 0XE4));
        goto L_800AB6B8;
    // 0x800AB5A8: lh          $s0, 0xE4($sp)
    ctx->r16 = S32(MEM_H(ctx->r29, 0XE4));
    // 0x800AB5AC: lh          $v1, 0xE($t1)
    ctx->r3 = S32(MEM_H(ctx->r9, 0XE));
L_800AB5B0:
    // 0x800AB5B0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800AB5B4: lui         $a2, 0x802B
    ctx->r6 = S32(0X802B << 16);
    // 0x800AB5B8: beq         $v1, $at, L_800AB600
    if (ctx->r3 == ctx->r1) {
        // 0x800AB5BC: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800AB600;
    }
    // 0x800AB5BC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800AB5C0: bne         $v1, $at, L_800AB6B4
    if (ctx->r3 != ctx->r1) {
        // 0x800AB5C4: sll         $a0, $s0, 16
        ctx->r4 = S32(ctx->r16 << 16);
            goto L_800AB6B4;
    }
    // 0x800AB5C4: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800AB5C8: lh          $t8, 0x10($t1)
    ctx->r24 = S32(MEM_H(ctx->r9, 0X10));
    // 0x800AB5CC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x800AB5D0: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AB5D4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800AB5D8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800AB5DC: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800AB5E0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800AB5E4: sh          $a1, -0x196C($at)
    MEM_H(-0X196C, ctx->r1) = ctx->r5;
    // 0x800AB5E8: jal         0x80092728
    // 0x800AB5EC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    deletesprite(rdram, ctx);
        goto after_1;
    // 0x800AB5EC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x800AB5F0: lui         $a3, 0x802A
    ctx->r7 = S32(0X802A << 16);
    // 0x800AB5F4: addiu       $a3, $a3, 0x5770
    ctx->r7 = ADD32(ctx->r7, 0X5770);
    // 0x800AB5F8: b           L_800AB6B4
    // 0x800AB5FC: addiu       $t0, $zero, 0x38C
    ctx->r8 = ADD32(0, 0X38C);
        goto L_800AB6B4;
    // 0x800AB5FC: addiu       $t0, $zero, 0x38C
    ctx->r8 = ADD32(0, 0X38C);
L_800AB600:
    // 0x800AB600: lh          $a2, -0x55A4($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, -0X55A4));
    // 0x800AB604: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800AB608: addiu       $a0, $a0, -0x7D40
    ctx->r4 = ADD32(ctx->r4, -0X7D40);
    // 0x800AB60C: slti        $at, $a2, 0x100
    ctx->r1 = SIGNED(ctx->r6) < 0X100 ? 1 : 0;
    // 0x800AB610: bne         $at, $zero, L_800AB630
    if (ctx->r1 != 0) {
        // 0x800AB614: nop
    
            goto L_800AB630;
    }
    // 0x800AB614: nop

    // 0x800AB618: jal         0x80099460
    // 0x800AB61C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    gameexit(rdram, ctx);
        goto after_2;
    // 0x800AB61C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_2:
    // 0x800AB620: lw          $t1, 0x44($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800AB624: lui         $a2, 0x802B
    ctx->r6 = S32(0X802B << 16);
    // 0x800AB628: lh          $a2, -0x55A4($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, -0X55A4));
    // 0x800AB62C: lh          $a1, 0x1E($t1)
    ctx->r5 = S32(MEM_H(ctx->r9, 0X1E));
L_800AB630:
    // 0x800AB630: multu       $a2, $s4
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB634: lh          $v1, 0x10($t1)
    ctx->r3 = S32(MEM_H(ctx->r9, 0X10));
    // 0x800AB638: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x800AB63C: addiu       $t8, $t8, -0x900
    ctx->r24 = ADD32(ctx->r24, -0X900);
    // 0x800AB640: lb          $t9, 0x24($t1)
    ctx->r25 = S32(MEM_B(ctx->r9, 0X24));
    // 0x800AB644: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800AB648: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x800AB64C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800AB650: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800AB654: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800AB658: mflo        $t7
    ctx->r15 = lo;
    // 0x800AB65C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800AB660: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800AB664: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x800AB668: lh          $t9, 0x14($t1)
    ctx->r25 = S32(MEM_H(ctx->r9, 0X14));
    // 0x800AB66C: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
    // 0x800AB670: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800AB674: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x800AB678: lb          $t7, -0x1962($t7)
    ctx->r15 = S32(MEM_B(ctx->r15, -0X1962));
    // 0x800AB67C: lh          $t8, 0x20($t1)
    ctx->r24 = S32(MEM_H(ctx->r9, 0X20));
    // 0x800AB680: xori        $t6, $t9, 0x600
    ctx->r14 = ctx->r25 ^ 0X600;
    // 0x800AB684: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800AB688: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x800AB68C: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
    // 0x800AB690: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x800AB694: addiu       $t7, $a2, 0x1
    ctx->r15 = ADD32(ctx->r6, 0X1);
    // 0x800AB698: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AB69C: sh          $t7, -0x55A4($at)
    MEM_H(-0X55A4, ctx->r1) = ctx->r15;
    // 0x800AB6A0: jal         0x80092728
    // 0x800AB6A4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    deletesprite(rdram, ctx);
        goto after_3;
    // 0x800AB6A4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_3:
    // 0x800AB6A8: lui         $a3, 0x802A
    ctx->r7 = S32(0X802A << 16);
    // 0x800AB6AC: addiu       $a3, $a3, 0x5770
    ctx->r7 = ADD32(ctx->r7, 0X5770);
    // 0x800AB6B0: addiu       $t0, $zero, 0x38C
    ctx->r8 = ADD32(0, 0X38C);
L_800AB6B4:
    // 0x800AB6B4: lh          $s0, 0xE4($sp)
    ctx->r16 = S32(MEM_H(ctx->r29, 0XE4));
L_800AB6B8:
    // 0x800AB6B8: bgez        $s0, L_800AB524
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800AB6BC: nop
    
            goto L_800AB524;
    }
    // 0x800AB6BC: nop

L_800AB6C0:
    // 0x800AB6C0: lui         $s1, 0x8024
    ctx->r17 = S32(0X8024 << 16);
    // 0x800AB6C4: lui         $s3, 0x8027
    ctx->r19 = S32(0X8027 << 16);
    // 0x800AB6C8: addiu       $s3, $s3, 0x5F40
    ctx->r19 = ADD32(ctx->r19, 0X5F40);
    // 0x800AB6CC: addiu       $s1, $s1, 0x6BA8
    ctx->r17 = ADD32(ctx->r17, 0X6BA8);
    // 0x800AB6D0: addiu       $s2, $zero, 0x2C
    ctx->r18 = ADD32(0, 0X2C);
    // 0x800AB6D4: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
    // 0x800AB6D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AB6DC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_800AB6E0:
    // 0x800AB6E0: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB6E4: mflo        $t6
    ctx->r14 = lo;
    // 0x800AB6E8: addu        $t1, $s1, $t6
    ctx->r9 = ADD32(ctx->r17, ctx->r14);
    // 0x800AB6EC: lh          $t7, 0x12($t1)
    ctx->r15 = S32(MEM_H(ctx->r9, 0X12));
    // 0x800AB6F0: slti        $at, $t7, 0x400
    ctx->r1 = SIGNED(ctx->r15) < 0X400 ? 1 : 0;
    // 0x800AB6F4: beql        $at, $zero, L_800AB734
    if (ctx->r1 == 0) {
        // 0x800AB6F8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800AB734;
    }
    goto skip_6;
    // 0x800AB6F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_6:
    // 0x800AB6FC: lh          $t8, 0xE($t1)
    ctx->r24 = S32(MEM_H(ctx->r9, 0XE));
    // 0x800AB700: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800AB704: bnel        $t3, $t8, L_800AB720
    if (ctx->r11 != ctx->r24) {
        // 0x800AB708: sll         $a1, $s0, 16
        ctx->r5 = S32(ctx->r16 << 16);
            goto L_800AB720;
    }
    goto skip_7;
    // 0x800AB708: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    skip_7:
    // 0x800AB70C: lh          $t9, 0x1E($t1)
    ctx->r25 = S32(MEM_H(ctx->r9, 0X1E));
    // 0x800AB710: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800AB714: beql        $t9, $at, L_800AB734
    if (ctx->r25 == ctx->r1) {
        // 0x800AB718: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800AB734;
    }
    goto skip_8;
    // 0x800AB718: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_8:
    // 0x800AB71C: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
L_800AB720:
    // 0x800AB720: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800AB724: jal         0x8009D240
    // 0x800AB728: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    spawn(rdram, ctx);
        goto after_4;
    // 0x800AB728: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_4:
    // 0x800AB72C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AB730: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800AB734:
    // 0x800AB734: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x800AB738: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800AB73C: slti        $at, $s0, 0x7D0
    ctx->r1 = SIGNED(ctx->r16) < 0X7D0 ? 1 : 0;
    // 0x800AB740: bne         $at, $zero, L_800AB6E0
    if (ctx->r1 != 0) {
        // 0x800AB744: nop
    
            goto L_800AB6E0;
    }
    // 0x800AB744: nop

    // 0x800AB748: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AB74C:
    // 0x800AB74C: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB750: mflo        $t9
    ctx->r25 = lo;
    // 0x800AB754: addu        $t1, $s1, $t9
    ctx->r9 = ADD32(ctx->r17, ctx->r25);
    // 0x800AB758: lh          $t6, 0x12($t1)
    ctx->r14 = S32(MEM_H(ctx->r9, 0X12));
    // 0x800AB75C: slti        $at, $t6, 0x400
    ctx->r1 = SIGNED(ctx->r14) < 0X400 ? 1 : 0;
    // 0x800AB760: beql        $at, $zero, L_800AB7A0
    if (ctx->r1 == 0) {
        // 0x800AB764: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800AB7A0;
    }
    goto skip_9;
    // 0x800AB764: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_9:
    // 0x800AB768: lh          $t7, 0xE($t1)
    ctx->r15 = S32(MEM_H(ctx->r9, 0XE));
    // 0x800AB76C: bnel        $t3, $t7, L_800AB7A0
    if (ctx->r11 != ctx->r15) {
        // 0x800AB770: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800AB7A0;
    }
    goto skip_10;
    // 0x800AB770: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_10:
    // 0x800AB774: lh          $t8, 0x1E($t1)
    ctx->r24 = S32(MEM_H(ctx->r9, 0X1E));
    // 0x800AB778: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800AB77C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800AB780: bnel        $t8, $at, L_800AB7A0
    if (ctx->r24 != ctx->r1) {
        // 0x800AB784: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800AB7A0;
    }
    goto skip_11;
    // 0x800AB784: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_11:
    // 0x800AB788: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x800AB78C: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800AB790: jal         0x8009D240
    // 0x800AB794: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    spawn(rdram, ctx);
        goto after_5;
    // 0x800AB794: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_5:
    // 0x800AB798: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AB79C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800AB7A0:
    // 0x800AB7A0: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x800AB7A4: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800AB7A8: slti        $at, $s0, 0x7D0
    ctx->r1 = SIGNED(ctx->r16) < 0X7D0 ? 1 : 0;
    // 0x800AB7AC: bne         $at, $zero, L_800AB74C
    if (ctx->r1 != 0) {
        // 0x800AB7B0: nop
    
            goto L_800AB74C;
    }
    // 0x800AB7B0: nop

    // 0x800AB7B4: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x800AB7B8: lh          $v0, 0x2858($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X2858));
    // 0x800AB7BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AB7C0: lui         $t0, 0x8028
    ctx->r8 = S32(0X8028 << 16);
    // 0x800AB7C4: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800AB7C8: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800AB7CC: bltz        $t8, L_800AB9B0
    if (SIGNED(ctx->r24) < 0) {
        // 0x800AB7D0: or          $s0, $t8, $zero
        ctx->r16 = ctx->r24 | 0;
            goto L_800AB9B0;
    }
    // 0x800AB7D0: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x800AB7D4: addiu       $t2, $zero, 0x48
    ctx->r10 = ADD32(0, 0X48);
    // 0x800AB7D8: addiu       $t0, $t0, -0x5C00
    ctx->r8 = ADD32(ctx->r8, -0X5C00);
    // 0x800AB7DC: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
L_800AB7E0:
    // 0x800AB7E0: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB7E4: mflo        $t9
    ctx->r25 = lo;
    // 0x800AB7E8: addu        $t1, $s1, $t9
    ctx->r9 = ADD32(ctx->r17, ctx->r25);
    // 0x800AB7EC: lh          $v1, 0xE($t1)
    ctx->r3 = S32(MEM_H(ctx->r9, 0XE));
    // 0x800AB7F0: slti        $at, $v1, 0x362
    ctx->r1 = SIGNED(ctx->r3) < 0X362 ? 1 : 0;
    // 0x800AB7F4: bne         $at, $zero, L_800AB824
    if (ctx->r1 != 0) {
        // 0x800AB7F8: addiu       $at, $zero, 0x457
        ctx->r1 = ADD32(0, 0X457);
            goto L_800AB824;
    }
    // 0x800AB7F8: addiu       $at, $zero, 0x457
    ctx->r1 = ADD32(0, 0X457);
    // 0x800AB7FC: beq         $v1, $at, L_800AB99C
    if (ctx->r3 == ctx->r1) {
        // 0x800AB800: addiu       $at, $zero, 0x458
        ctx->r1 = ADD32(0, 0X458);
            goto L_800AB99C;
    }
    // 0x800AB800: addiu       $at, $zero, 0x458
    ctx->r1 = ADD32(0, 0X458);
    // 0x800AB804: beq         $v1, $at, L_800AB8AC
    if (ctx->r3 == ctx->r1) {
        // 0x800AB808: addiu       $at, $zero, 0x462
        ctx->r1 = ADD32(0, 0X462);
            goto L_800AB8AC;
    }
    // 0x800AB808: addiu       $at, $zero, 0x462
    ctx->r1 = ADD32(0, 0X462);
    // 0x800AB80C: beq         $v1, $at, L_800AB99C
    if (ctx->r3 == ctx->r1) {
        // 0x800AB810: addiu       $at, $zero, 0x463
        ctx->r1 = ADD32(0, 0X463);
            goto L_800AB99C;
    }
    // 0x800AB810: addiu       $at, $zero, 0x463
    ctx->r1 = ADD32(0, 0X463);
    // 0x800AB814: beq         $v1, $at, L_800AB8AC
    if (ctx->r3 == ctx->r1) {
        // 0x800AB818: nop
    
            goto L_800AB8AC;
    }
    // 0x800AB818: nop

    // 0x800AB81C: b           L_800AB9A0
    // 0x800AB820: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
        goto L_800AB9A0;
    // 0x800AB820: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
L_800AB824:
    // 0x800AB824: slti        $at, $v1, 0x2C9
    ctx->r1 = SIGNED(ctx->r3) < 0X2C9 ? 1 : 0;
    // 0x800AB828: bne         $at, $zero, L_800AB86C
    if (ctx->r1 != 0) {
        // 0x800AB82C: slti        $at, $v1, 0x2CA
        ctx->r1 = SIGNED(ctx->r3) < 0X2CA ? 1 : 0;
            goto L_800AB86C;
    }
    // 0x800AB82C: slti        $at, $v1, 0x2CA
    ctx->r1 = SIGNED(ctx->r3) < 0X2CA ? 1 : 0;
    // 0x800AB830: bne         $at, $zero, L_800AB858
    if (ctx->r1 != 0) {
        // 0x800AB834: addiu       $t6, $v1, -0x35C
        ctx->r14 = ADD32(ctx->r3, -0X35C);
            goto L_800AB858;
    }
    // 0x800AB834: addiu       $t6, $v1, -0x35C
    ctx->r14 = ADD32(ctx->r3, -0X35C);
    // 0x800AB838: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x800AB83C: beq         $at, $zero, L_800AB99C
    if (ctx->r1 == 0) {
        // 0x800AB840: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800AB99C;
    }
    // 0x800AB840: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AB844: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800AB848: addu        $at, $at, $t6
    gpr jr_addend_800AB850 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800AB84C: lw          $t6, -0x7C70($at)
    ctx->r14 = ADD32(ctx->r1, -0X7C70);
    // 0x800AB850: jr          $t6
    // 0x800AB854: nop

    switch (jr_addend_800AB850 >> 2) {
        case 0: goto L_800AB99C; break;
        case 1: goto L_800AB8AC; break;
        case 2: goto L_800AB99C; break;
        case 3: goto L_800AB8AC; break;
        case 4: goto L_800AB99C; break;
        case 5: goto L_800AB8AC; break;
        default: switch_error(__func__, 0x800AB850, 0x80108390);
    }
    // 0x800AB854: nop

L_800AB858:
    // 0x800AB858: addiu       $at, $zero, 0x2C9
    ctx->r1 = ADD32(0, 0X2C9);
    // 0x800AB85C: beq         $v1, $at, L_800AB8AC
    if (ctx->r3 == ctx->r1) {
        // 0x800AB860: nop
    
            goto L_800AB8AC;
    }
    // 0x800AB860: nop

    // 0x800AB864: b           L_800AB9A0
    // 0x800AB868: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
        goto L_800AB9A0;
    // 0x800AB868: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
L_800AB86C:
    // 0x800AB86C: slti        $at, $v1, 0xA6
    ctx->r1 = SIGNED(ctx->r3) < 0XA6 ? 1 : 0;
    // 0x800AB870: bne         $at, $zero, L_800AB88C
    if (ctx->r1 != 0) {
        // 0x800AB874: addiu       $t7, $v1, -0x82
        ctx->r15 = ADD32(ctx->r3, -0X82);
            goto L_800AB88C;
    }
    // 0x800AB874: addiu       $t7, $v1, -0x82
    ctx->r15 = ADD32(ctx->r3, -0X82);
    // 0x800AB878: addiu       $at, $zero, 0x2C8
    ctx->r1 = ADD32(0, 0X2C8);
    // 0x800AB87C: beql        $v1, $at, L_800AB9A0
    if (ctx->r3 == ctx->r1) {
        // 0x800AB880: sll         $t9, $s0, 1
        ctx->r25 = S32(ctx->r16 << 1);
            goto L_800AB9A0;
    }
    goto skip_12;
    // 0x800AB880: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    skip_12:
    // 0x800AB884: b           L_800AB9A0
    // 0x800AB888: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
        goto L_800AB9A0;
    // 0x800AB888: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
L_800AB88C:
    // 0x800AB88C: sltiu       $at, $t7, 0x24
    ctx->r1 = ctx->r15 < 0X24 ? 1 : 0;
    // 0x800AB890: beq         $at, $zero, L_800AB99C
    if (ctx->r1 == 0) {
        // 0x800AB894: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800AB99C;
    }
    // 0x800AB894: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800AB898: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800AB89C: addu        $at, $at, $t7
    gpr jr_addend_800AB8A4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800AB8A0: lw          $t7, -0x7C58($at)
    ctx->r15 = ADD32(ctx->r1, -0X7C58);
    // 0x800AB8A4: jr          $t7
    // 0x800AB8A8: nop

    switch (jr_addend_800AB8A4 >> 2) {
        case 0: goto L_800AB99C; break;
        case 1: goto L_800AB99C; break;
        case 2: goto L_800AB99C; break;
        case 3: goto L_800AB8AC; break;
        case 4: goto L_800AB99C; break;
        case 5: goto L_800AB8AC; break;
        case 6: goto L_800AB99C; break;
        case 7: goto L_800AB8AC; break;
        case 8: goto L_800AB99C; break;
        case 9: goto L_800AB8AC; break;
        case 10: goto L_800AB99C; break;
        case 11: goto L_800AB8AC; break;
        case 12: goto L_800AB99C; break;
        case 13: goto L_800AB99C; break;
        case 14: goto L_800AB99C; break;
        case 15: goto L_800AB99C; break;
        case 16: goto L_800AB99C; break;
        case 17: goto L_800AB99C; break;
        case 18: goto L_800AB99C; break;
        case 19: goto L_800AB99C; break;
        case 20: goto L_800AB99C; break;
        case 21: goto L_800AB99C; break;
        case 22: goto L_800AB99C; break;
        case 23: goto L_800AB99C; break;
        case 24: goto L_800AB99C; break;
        case 25: goto L_800AB99C; break;
        case 26: goto L_800AB99C; break;
        case 27: goto L_800AB99C; break;
        case 28: goto L_800AB99C; break;
        case 29: goto L_800AB99C; break;
        case 30: goto L_800AB99C; break;
        case 31: goto L_800AB99C; break;
        case 32: goto L_800AB99C; break;
        case 33: goto L_800AB8AC; break;
        case 34: goto L_800AB99C; break;
        case 35: goto L_800AB8AC; break;
        default: switch_error(__func__, 0x800AB8A4, 0x801083A8);
    }
    // 0x800AB8A8: nop

L_800AB8AC:
    // 0x800AB8AC: blez        $a2, L_800AB8E4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800AB8B0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800AB8E4;
    }
    // 0x800AB8B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AB8B4: lh          $a1, 0x1E($t1)
    ctx->r5 = S32(MEM_H(ctx->r9, 0X1E));
    // 0x800AB8B8: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
L_800AB8BC:
    // 0x800AB8BC: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x800AB8C0: lh          $t6, 0x0($t9)
    ctx->r14 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800AB8C4: beq         $a1, $t6, L_800AB8E4
    if (ctx->r5 == ctx->r14) {
        // 0x800AB8C8: nop
    
            goto L_800AB8E4;
    }
    // 0x800AB8C8: nop

    // 0x800AB8CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AB8D0: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x800AB8D4: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800AB8D8: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800AB8DC: bnel        $at, $zero, L_800AB8BC
    if (ctx->r1 != 0) {
        // 0x800AB8E0: sll         $t8, $v1, 1
        ctx->r24 = S32(ctx->r3 << 1);
            goto L_800AB8BC;
    }
    goto skip_13;
    // 0x800AB8E0: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    skip_13:
L_800AB8E4:
    // 0x800AB8E4: bne         $v1, $a2, L_800AB99C
    if (ctx->r3 != ctx->r6) {
        // 0x800AB8E8: sll         $t6, $a2, 1
        ctx->r14 = S32(ctx->r6 << 1);
            goto L_800AB99C;
    }
    // 0x800AB8E8: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x800AB8EC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800AB8F0: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x800AB8F4: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800AB8F8: lh          $t9, 0x1E($t1)
    ctx->r25 = S32(MEM_H(ctx->r9, 0X1E));
    // 0x800AB8FC: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800AB900: slti        $at, $t6, 0x41
    ctx->r1 = SIGNED(ctx->r14) < 0X41 ? 1 : 0;
    // 0x800AB904: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x800AB908: bne         $at, $zero, L_800AB940
    if (ctx->r1 != 0) {
        // 0x800AB90C: sh          $t9, 0x0($t7)
        MEM_H(0X0, ctx->r15) = ctx->r25;
            goto L_800AB940;
    }
    // 0x800AB90C: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
    // 0x800AB910: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800AB914: addiu       $a0, $a0, -0x7D24
    ctx->r4 = ADD32(ctx->r4, -0X7D24);
    // 0x800AB918: sh          $t6, 0xDC($sp)
    MEM_H(0XDC, ctx->r29) = ctx->r14;
    // 0x800AB91C: jal         0x80099460
    // 0x800AB920: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    gameexit(rdram, ctx);
        goto after_6;
    // 0x800AB920: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_6:
    // 0x800AB924: lui         $t0, 0x8028
    ctx->r8 = S32(0X8028 << 16);
    // 0x800AB928: addiu       $t0, $t0, -0x5C00
    ctx->r8 = ADD32(ctx->r8, -0X5C00);
    // 0x800AB92C: lh          $a2, 0xDC($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0XDC));
    // 0x800AB930: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    // 0x800AB934: lw          $t1, 0x44($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800AB938: addiu       $t2, $zero, 0x48
    ctx->r10 = ADD32(0, 0X48);
    // 0x800AB93C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_800AB940:
    // 0x800AB940: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x800AB944: lh          $v1, 0x285E($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X285E));
    // 0x800AB948: bltzl       $v1, L_800AB9A0
    if (SIGNED(ctx->r3) < 0) {
        // 0x800AB94C: sll         $t9, $s0, 1
        ctx->r25 = S32(ctx->r16 << 1);
            goto L_800AB9A0;
    }
    goto skip_14;
    // 0x800AB94C: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    skip_14:
L_800AB950:
    // 0x800AB950: multu       $v1, $s2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB954: mflo        $t9
    ctx->r25 = lo;
    // 0x800AB958: addu        $v0, $s1, $t9
    ctx->r2 = ADD32(ctx->r17, ctx->r25);
    // 0x800AB95C: lh          $t7, 0x1E($v0)
    ctx->r15 = S32(MEM_H(ctx->r2, 0X1E));
    // 0x800AB960: bnel        $s4, $t7, L_800AB98C
    if (ctx->r20 != ctx->r15) {
        // 0x800AB964: sll         $t8, $v1, 1
        ctx->r24 = S32(ctx->r3 << 1);
            goto L_800AB98C;
    }
    goto skip_15;
    // 0x800AB964: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    skip_15:
    // 0x800AB968: lh          $t8, 0x20($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X20));
    // 0x800AB96C: lh          $t6, 0x1E($t1)
    ctx->r14 = S32(MEM_H(ctx->r9, 0X1E));
    // 0x800AB970: bnel        $t8, $t6, L_800AB98C
    if (ctx->r24 != ctx->r14) {
        // 0x800AB974: sll         $t8, $v1, 1
        ctx->r24 = S32(ctx->r3 << 1);
            goto L_800AB98C;
    }
    goto skip_16;
    // 0x800AB974: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    skip_16:
    // 0x800AB978: multu       $v1, $t2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB97C: mflo        $t9
    ctx->r25 = lo;
    // 0x800AB980: addu        $t7, $t0, $t9
    ctx->r15 = ADD32(ctx->r8, ctx->r25);
    // 0x800AB984: sw          $t3, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r11;
    // 0x800AB988: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
L_800AB98C:
    // 0x800AB98C: addu        $t6, $s3, $t8
    ctx->r14 = ADD32(ctx->r19, ctx->r24);
    // 0x800AB990: lh          $v1, 0x0($t6)
    ctx->r3 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800AB994: bgez        $v1, L_800AB950
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800AB998: nop
    
            goto L_800AB950;
    }
    // 0x800AB998: nop

L_800AB99C:
    // 0x800AB99C: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
L_800AB9A0:
    // 0x800AB9A0: addu        $t7, $s3, $t9
    ctx->r15 = ADD32(ctx->r19, ctx->r25);
    // 0x800AB9A4: lh          $s0, 0x0($t7)
    ctx->r16 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800AB9A8: bgez        $s0, L_800AB7E0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800AB9AC: nop
    
            goto L_800AB7E0;
    }
    // 0x800AB9AC: nop

L_800AB9B0:
    // 0x800AB9B0: lui         $s4, 0x802B
    ctx->r20 = S32(0X802B << 16);
    // 0x800AB9B4: addiu       $s4, $s4, -0x55A0
    ctx->r20 = ADD32(ctx->r20, -0X55A0);
    // 0x800AB9B8: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
    // 0x800AB9BC: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x800AB9C0: lh          $t8, -0x5376($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X5376));
    // 0x800AB9C4: lui         $s3, 0x802B
    ctx->r19 = S32(0X802B << 16);
    // 0x800AB9C8: addiu       $s3, $s3, -0x6940
    ctx->r19 = ADD32(ctx->r19, -0X6940);
    // 0x800AB9CC: blez        $t8, L_800ABD50
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800AB9D0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800ABD50;
    }
    // 0x800AB9D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AB9D4: lui         $s1, 0x802B
    ctx->r17 = S32(0X802B << 16);
    // 0x800AB9D8: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x800AB9DC: addiu       $t0, $t0, 0x61A8
    ctx->r8 = ADD32(ctx->r8, 0X61A8);
    // 0x800AB9E0: addiu       $s1, $s1, -0x55AC
    ctx->r17 = ADD32(ctx->r17, -0X55AC);
    // 0x800AB9E4: addiu       $s2, $zero, 0x24
    ctx->r18 = ADD32(0, 0X24);
    // 0x800AB9E8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800AB9EC: addiu       $a3, $zero, 0x230
    ctx->r7 = ADD32(0, 0X230);
L_800AB9F0:
    // 0x800AB9F0: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB9F4: mflo        $t6
    ctx->r14 = lo;
    // 0x800AB9F8: addu        $a1, $t0, $t6
    ctx->r5 = ADD32(ctx->r8, ctx->r14);
    // 0x800AB9FC: lh          $t9, 0x12($a1)
    ctx->r25 = S32(MEM_H(ctx->r5, 0X12));
    // 0x800ABA00: bnel        $a3, $t9, L_800ABABC
    if (ctx->r7 != ctx->r25) {
        // 0x800ABA04: lh          $v0, 0x0($s1)
        ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
            goto L_800ABABC;
    }
    goto skip_17;
    // 0x800ABA04: lh          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
    skip_17:
    // 0x800ABA08: lh          $t7, 0xE($a1)
    ctx->r15 = S32(MEM_H(ctx->r5, 0XE));
    // 0x800ABA0C: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x800ABA10: beql        $t8, $zero, L_800ABABC
    if (ctx->r24 == 0) {
        // 0x800ABA14: lh          $v0, 0x0($s1)
        ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
            goto L_800ABABC;
    }
    goto skip_18;
    // 0x800ABA14: lh          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
    skip_18:
    // 0x800ABA18: lh          $t6, 0x0($s4)
    ctx->r14 = S32(MEM_H(ctx->r20, 0X0));
    // 0x800ABA1C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800ABA20: lh          $v1, 0xC($a1)
    ctx->r3 = S32(MEM_H(ctx->r5, 0XC));
    // 0x800ABA24: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x800ABA28: bne         $at, $zero, L_800ABA54
    if (ctx->r1 != 0) {
        // 0x800ABA2C: addiu       $a0, $a0, -0x7D04
        ctx->r4 = ADD32(ctx->r4, -0X7D04);
            goto L_800ABA54;
    }
    // 0x800ABA2C: addiu       $a0, $a0, -0x7D04
    ctx->r4 = ADD32(ctx->r4, -0X7D04);
    // 0x800ABA30: sh          $v1, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = ctx->r3;
    // 0x800ABA34: jal         0x80099460
    // 0x800ABA38: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    gameexit(rdram, ctx);
        goto after_7;
    // 0x800ABA38: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_7:
    // 0x800ABA3C: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x800ABA40: addiu       $t0, $t0, 0x61A8
    ctx->r8 = ADD32(ctx->r8, 0X61A8);
    // 0x800ABA44: lh          $v1, 0xE2($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0XE2));
    // 0x800ABA48: lw          $a1, 0x48($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800ABA4C: addiu       $a3, $zero, 0x230
    ctx->r7 = ADD32(0, 0X230);
    // 0x800ABA50: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_800ABA54:
    // 0x800ABA54: bltz        $v1, L_800ABAB8
    if (SIGNED(ctx->r3) < 0) {
        // 0x800ABA58: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_800ABAB8;
    }
    // 0x800ABA58: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800ABA5C: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x800ABA60: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800ABA64: addiu       $t7, $t7, -0x1988
    ctx->r15 = ADD32(ctx->r15, -0X1988);
    // 0x800ABA68: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800ABA6C: addu        $a0, $t9, $t7
    ctx->r4 = ADD32(ctx->r25, ctx->r15);
    // 0x800ABA70: lh          $t8, 0x10($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0X10));
    // 0x800ABA74: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800ABA78: beql        $a3, $t8, L_800ABABC
    if (ctx->r7 == ctx->r24) {
        // 0x800ABA7C: lh          $v0, 0x0($s1)
        ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
            goto L_800ABABC;
    }
    goto skip_19;
    // 0x800ABA7C: lh          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
    skip_19:
    // 0x800ABA80: lh          $a2, 0x0($s4)
    ctx->r6 = S32(MEM_H(ctx->r20, 0X0));
    // 0x800ABA84: sh          $a3, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r7;
    // 0x800ABA88: sh          $a3, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r7;
    // 0x800ABA8C: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800ABA90: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800ABA94: sh          $s0, -0x6A40($at)
    MEM_H(-0X6A40, ctx->r1) = ctx->r16;
    // 0x800ABA98: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800ABA9C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800ABAA0: sh          $v1, -0x69C0($at)
    MEM_H(-0X69C0, ctx->r1) = ctx->r3;
    // 0x800ABAA4: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x800ABAA8: sh          $t6, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r14;
    // 0x800ABAAC: lui         $a1, 0x802B
    ctx->r5 = S32(0X802B << 16);
    // 0x800ABAB0: b           L_800ABD34
    // 0x800ABAB4: lh          $a1, -0x5376($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, -0X5376));
        goto L_800ABD34;
    // 0x800ABAB4: lh          $a1, -0x5376($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, -0X5376));
L_800ABAB8:
    // 0x800ABAB8: lh          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
L_800ABABC:
    // 0x800ABABC: slti        $at, $v0, 0x200
    ctx->r1 = SIGNED(ctx->r2) < 0X200 ? 1 : 0;
    // 0x800ABAC0: bne         $at, $zero, L_800ABAEC
    if (ctx->r1 != 0) {
        // 0x800ABAC4: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_800ABAEC;
    }
    // 0x800ABAC4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800ABAC8: addiu       $a0, $a0, -0x7CE8
    ctx->r4 = ADD32(ctx->r4, -0X7CE8);
    // 0x800ABACC: jal         0x80099460
    // 0x800ABAD0: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    gameexit(rdram, ctx);
        goto after_8;
    // 0x800ABAD0: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_8:
    // 0x800ABAD4: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x800ABAD8: addiu       $t0, $t0, 0x61A8
    ctx->r8 = ADD32(ctx->r8, 0X61A8);
    // 0x800ABADC: lw          $a1, 0x48($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800ABAE0: addiu       $a3, $zero, 0x230
    ctx->r7 = ADD32(0, 0X230);
    // 0x800ABAE4: lh          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
    // 0x800ABAE8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_800ABAEC:
    // 0x800ABAEC: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800ABAF0: addu        $a0, $s3, $t9
    ctx->r4 = ADD32(ctx->r19, ctx->r25);
    // 0x800ABAF4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800ABAF8: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x800ABAFC: lh          $v1, 0x12($a1)
    ctx->r3 = S32(MEM_H(ctx->r5, 0X12));
    // 0x800ABB00: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x800ABB04: beq         $v1, $at, L_800ABBB0
    if (ctx->r3 == ctx->r1) {
        // 0x800ABB08: addiu       $at, $zero, 0x197
        ctx->r1 = ADD32(0, 0X197);
            goto L_800ABBB0;
    }
    // 0x800ABB08: addiu       $at, $zero, 0x197
    ctx->r1 = ADD32(0, 0X197);
    // 0x800ABB0C: beq         $v1, $at, L_800ABB40
    if (ctx->r3 == ctx->r1) {
        // 0x800ABB10: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_800ABB40;
    }
    // 0x800ABB10: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800ABB14: addiu       $at, $zero, 0x19C
    ctx->r1 = ADD32(0, 0X19C);
    // 0x800ABB18: beq         $v1, $at, L_800ABB40
    if (ctx->r3 == ctx->r1) {
        // 0x800ABB1C: addiu       $at, $zero, 0x297
        ctx->r1 = ADD32(0, 0X297);
            goto L_800ABB40;
    }
    // 0x800ABB1C: addiu       $at, $zero, 0x297
    ctx->r1 = ADD32(0, 0X297);
    // 0x800ABB20: beq         $v1, $at, L_800ABB58
    if (ctx->r3 == ctx->r1) {
        // 0x800ABB24: addiu       $at, $zero, 0x298
        ctx->r1 = ADD32(0, 0X298);
            goto L_800ABB58;
    }
    // 0x800ABB24: addiu       $at, $zero, 0x298
    ctx->r1 = ADD32(0, 0X298);
    // 0x800ABB28: beq         $v1, $at, L_800ABB58
    if (ctx->r3 == ctx->r1) {
        // 0x800ABB2C: addiu       $at, $zero, 0x299
        ctx->r1 = ADD32(0, 0X299);
            goto L_800ABB58;
    }
    // 0x800ABB2C: addiu       $at, $zero, 0x299
    ctx->r1 = ADD32(0, 0X299);
    // 0x800ABB30: beql        $v1, $at, L_800ABB5C
    if (ctx->r3 == ctx->r1) {
        // 0x800ABB34: lb          $t9, 0x1C($a1)
        ctx->r25 = S32(MEM_B(ctx->r5, 0X1C));
            goto L_800ABB5C;
    }
    goto skip_20;
    // 0x800ABB34: lb          $t9, 0x1C($a1)
    ctx->r25 = S32(MEM_B(ctx->r5, 0X1C));
    skip_20:
    // 0x800ABB38: b           L_800ABBCC
    // 0x800ABB3C: lh          $a2, 0x10($a1)
    ctx->r6 = S32(MEM_H(ctx->r5, 0X10));
        goto L_800ABBCC;
    // 0x800ABB3C: lh          $a2, 0x10($a1)
    ctx->r6 = S32(MEM_H(ctx->r5, 0X10));
L_800ABB40:
    // 0x800ABB40: lh          $t7, 0xE($t0)
    ctx->r15 = S32(MEM_H(ctx->r8, 0XE));
    // 0x800ABB44: sh          $s0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r16;
    // 0x800ABB48: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x800ABB4C: ori         $t8, $t7, 0x41
    ctx->r24 = ctx->r15 | 0X41;
    // 0x800ABB50: b           L_800ABBC8
    // 0x800ABB54: sh          $t8, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r24;
        goto L_800ABBC8;
    // 0x800ABB54: sh          $t8, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r24;
L_800ABB58:
    // 0x800ABB58: lb          $t9, 0x1C($a1)
    ctx->r25 = S32(MEM_B(ctx->r5, 0X1C));
L_800ABB5C:
    // 0x800ABB5C: slti        $at, $t9, 0x20
    ctx->r1 = SIGNED(ctx->r25) < 0X20 ? 1 : 0;
    // 0x800ABB60: bnel        $at, $zero, L_800ABB74
    if (ctx->r1 != 0) {
        // 0x800ABB64: lh          $t7, 0xE($a1)
        ctx->r15 = S32(MEM_H(ctx->r5, 0XE));
            goto L_800ABB74;
    }
    goto skip_21;
    // 0x800ABB64: lh          $t7, 0xE($a1)
    ctx->r15 = S32(MEM_H(ctx->r5, 0XE));
    skip_21:
    // 0x800ABB68: b           L_800ABB7C
    // 0x800ABB6C: sh          $zero, 0xE($a1)
    MEM_H(0XE, ctx->r5) = 0;
        goto L_800ABB7C;
    // 0x800ABB6C: sh          $zero, 0xE($a1)
    MEM_H(0XE, ctx->r5) = 0;
    // 0x800ABB70: lh          $t7, 0xE($a1)
    ctx->r15 = S32(MEM_H(ctx->r5, 0XE));
L_800ABB74:
    // 0x800ABB74: ori         $t8, $t7, 0x155
    ctx->r24 = ctx->r15 | 0X155;
    // 0x800ABB78: sh          $t8, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r24;
L_800ABB7C:
    // 0x800ABB7C: lh          $v1, 0x14($a1)
    ctx->r3 = S32(MEM_H(ctx->r5, 0X14));
    // 0x800ABB80: beql        $v1, $zero, L_800ABBA8
    if (ctx->r3 == 0) {
        // 0x800ABB84: lh          $v0, 0x0($s1)
        ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
            goto L_800ABBA8;
    }
    goto skip_22;
    // 0x800ABB84: lh          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
    skip_22:
    // 0x800ABB88: lh          $v0, 0xA($a1)
    ctx->r2 = S32(MEM_H(ctx->r5, 0XA));
    // 0x800ABB8C: bltzl       $v0, L_800ABBA8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800ABB90: lh          $v0, 0x0($s1)
        ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
            goto L_800ABBA8;
    }
    goto skip_23;
    // 0x800ABB90: lh          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
    skip_23:
    // 0x800ABB94: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ABB98: mflo        $t6
    ctx->r14 = lo;
    // 0x800ABB9C: addu        $t9, $t0, $t6
    ctx->r25 = ADD32(ctx->r8, ctx->r14);
    // 0x800ABBA0: sh          $v1, 0x14($t9)
    MEM_H(0X14, ctx->r25) = ctx->r3;
    // 0x800ABBA4: lh          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
L_800ABBA8:
    // 0x800ABBA8: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800ABBAC: addu        $a0, $s3, $t7
    ctx->r4 = ADD32(ctx->r19, ctx->r15);
L_800ABBB0:
    // 0x800ABBB0: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x800ABBB4: sh          $s0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r16;
    // 0x800ABBB8: sh          $t8, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r24;
    // 0x800ABBBC: lui         $a1, 0x802B
    ctx->r5 = S32(0X802B << 16);
    // 0x800ABBC0: b           L_800ABD34
    // 0x800ABBC4: lh          $a1, -0x5376($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, -0X5376));
        goto L_800ABD34;
    // 0x800ABBC4: lh          $a1, -0x5376($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, -0X5376));
L_800ABBC8:
    // 0x800ABBC8: lh          $a2, 0x10($a1)
    ctx->r6 = S32(MEM_H(ctx->r5, 0X10));
L_800ABBCC:
    // 0x800ABBCC: sh          $t1, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r9;
    // 0x800ABBD0: slti        $at, $a2, 0x151
    ctx->r1 = SIGNED(ctx->r6) < 0X151 ? 1 : 0;
    // 0x800ABBD4: bne         $at, $zero, L_800ABC40
    if (ctx->r1 != 0) {
        // 0x800ABBD8: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_800ABC40;
    }
    // 0x800ABBD8: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800ABBDC: slti        $at, $v1, 0x50A
    ctx->r1 = SIGNED(ctx->r3) < 0X50A ? 1 : 0;
    // 0x800ABBE0: bne         $at, $zero, L_800ABC24
    if (ctx->r1 != 0) {
        // 0x800ABBE4: slti        $at, $v1, 0x513
        ctx->r1 = SIGNED(ctx->r3) < 0X513 ? 1 : 0;
            goto L_800ABC24;
    }
    // 0x800ABBE4: slti        $at, $v1, 0x513
    ctx->r1 = SIGNED(ctx->r3) < 0X513 ? 1 : 0;
    // 0x800ABBE8: bne         $at, $zero, L_800ABC10
    if (ctx->r1 != 0) {
        // 0x800ABBEC: addiu       $t6, $v1, -0x1018
        ctx->r14 = ADD32(ctx->r3, -0X1018);
            goto L_800ABC10;
    }
    // 0x800ABBEC: addiu       $t6, $v1, -0x1018
    ctx->r14 = ADD32(ctx->r3, -0X1018);
    // 0x800ABBF0: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x800ABBF4: beq         $at, $zero, L_800ABD2C
    if (ctx->r1 == 0) {
        // 0x800ABBF8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800ABD2C;
    }
    // 0x800ABBF8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800ABBFC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800ABC00: addu        $at, $at, $t6
    gpr jr_addend_800ABC08 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800ABC04: lw          $t6, -0x7BC8($at)
    ctx->r14 = ADD32(ctx->r1, -0X7BC8);
    // 0x800ABC08: jr          $t6
    // 0x800ABC0C: nop

    switch (jr_addend_800ABC08 >> 2) {
        case 0: goto L_800ABD0C; break;
        case 1: goto L_800ABD2C; break;
        case 2: goto L_800ABD2C; break;
        case 3: goto L_800ABD0C; break;
        case 4: goto L_800ABD2C; break;
        case 5: goto L_800ABD0C; break;
        case 6: goto L_800ABD2C; break;
        case 7: goto L_800ABD0C; break;
        case 8: goto L_800ABD0C; break;
        case 9: goto L_800ABD0C; break;
        default: switch_error(__func__, 0x800ABC08, 0x80108438);
    }
    // 0x800ABC0C: nop

L_800ABC10:
    // 0x800ABC10: addiu       $at, $zero, 0x512
    ctx->r1 = ADD32(0, 0X512);
    // 0x800ABC14: beql        $v1, $at, L_800ABCE4
    if (ctx->r3 == ctx->r1) {
        // 0x800ABC18: sh          $a2, 0x18($a1)
        MEM_H(0X18, ctx->r5) = ctx->r6;
            goto L_800ABCE4;
    }
    goto skip_24;
    // 0x800ABC18: sh          $a2, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r6;
    skip_24:
    // 0x800ABC1C: b           L_800ABD2C
    // 0x800ABC20: nop

        goto L_800ABD2C;
    // 0x800ABC20: nop

L_800ABC24:
    // 0x800ABC24: addiu       $at, $zero, 0x500
    ctx->r1 = ADD32(0, 0X500);
    // 0x800ABC28: beq         $v1, $at, L_800ABCE0
    if (ctx->r3 == ctx->r1) {
        // 0x800ABC2C: addiu       $at, $zero, 0x509
        ctx->r1 = ADD32(0, 0X509);
            goto L_800ABCE0;
    }
    // 0x800ABC2C: addiu       $at, $zero, 0x509
    ctx->r1 = ADD32(0, 0X509);
    // 0x800ABC30: beql        $v1, $at, L_800ABCE4
    if (ctx->r3 == ctx->r1) {
        // 0x800ABC34: sh          $a2, 0x18($a1)
        MEM_H(0X18, ctx->r5) = ctx->r6;
            goto L_800ABCE4;
    }
    goto skip_25;
    // 0x800ABC34: sh          $a2, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r6;
    skip_25:
    // 0x800ABC38: b           L_800ABD2C
    // 0x800ABC3C: nop

        goto L_800ABD2C;
    // 0x800ABC3C: nop

L_800ABC40:
    // 0x800ABC40: slti        $at, $v1, 0x7B
    ctx->r1 = SIGNED(ctx->r3) < 0X7B ? 1 : 0;
    // 0x800ABC44: bne         $at, $zero, L_800ABC88
    if (ctx->r1 != 0) {
        // 0x800ABC48: slti        $at, $v1, 0x132
        ctx->r1 = SIGNED(ctx->r3) < 0X132 ? 1 : 0;
            goto L_800ABC88;
    }
    // 0x800ABC48: slti        $at, $v1, 0x132
    ctx->r1 = SIGNED(ctx->r3) < 0X132 ? 1 : 0;
    // 0x800ABC4C: bne         $at, $zero, L_800ABC68
    if (ctx->r1 != 0) {
        // 0x800ABC50: addiu       $t9, $v1, -0x107
        ctx->r25 = ADD32(ctx->r3, -0X107);
            goto L_800ABC68;
    }
    // 0x800ABC50: addiu       $t9, $v1, -0x107
    ctx->r25 = ADD32(ctx->r3, -0X107);
    // 0x800ABC54: addiu       $at, $zero, 0x150
    ctx->r1 = ADD32(0, 0X150);
    // 0x800ABC58: beq         $v1, $at, L_800ABD2C
    if (ctx->r3 == ctx->r1) {
        // 0x800ABC5C: nop
    
            goto L_800ABD2C;
    }
    // 0x800ABC5C: nop

    // 0x800ABC60: b           L_800ABD2C
    // 0x800ABC64: nop

        goto L_800ABD2C;
    // 0x800ABC64: nop

L_800ABC68:
    // 0x800ABC68: sltiu       $at, $t9, 0x2B
    ctx->r1 = ctx->r25 < 0X2B ? 1 : 0;
    // 0x800ABC6C: beq         $at, $zero, L_800ABD2C
    if (ctx->r1 == 0) {
        // 0x800ABC70: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800ABD2C;
    }
    // 0x800ABC70: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800ABC74: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800ABC78: addu        $at, $at, $t9
    gpr jr_addend_800ABC80 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800ABC7C: lw          $t9, -0x7BA0($at)
    ctx->r25 = ADD32(ctx->r1, -0X7BA0);
    // 0x800ABC80: jr          $t9
    // 0x800ABC84: nop

    switch (jr_addend_800ABC80 >> 2) {
        case 0: goto L_800ABD0C; break;
        case 1: goto L_800ABD0C; break;
        case 2: goto L_800ABD0C; break;
        case 3: goto L_800ABD0C; break;
        case 4: goto L_800ABD0C; break;
        case 5: goto L_800ABCC0; break;
        case 6: goto L_800ABCC0; break;
        case 7: goto L_800ABCC0; break;
        case 8: goto L_800ABD0C; break;
        case 9: goto L_800ABD0C; break;
        case 10: goto L_800ABD0C; break;
        case 11: goto L_800ABD0C; break;
        case 12: goto L_800ABD0C; break;
        case 13: goto L_800ABD2C; break;
        case 14: goto L_800ABD2C; break;
        case 15: goto L_800ABD2C; break;
        case 16: goto L_800ABD2C; break;
        case 17: goto L_800ABD2C; break;
        case 18: goto L_800ABD2C; break;
        case 19: goto L_800ABD2C; break;
        case 20: goto L_800ABD2C; break;
        case 21: goto L_800ABD2C; break;
        case 22: goto L_800ABD2C; break;
        case 23: goto L_800ABD2C; break;
        case 24: goto L_800ABD2C; break;
        case 25: goto L_800ABD2C; break;
        case 26: goto L_800ABD2C; break;
        case 27: goto L_800ABD2C; break;
        case 28: goto L_800ABD2C; break;
        case 29: goto L_800ABD2C; break;
        case 30: goto L_800ABCA4; break;
        case 31: goto L_800ABD2C; break;
        case 32: goto L_800ABD2C; break;
        case 33: goto L_800ABD2C; break;
        case 34: goto L_800ABCA4; break;
        case 35: goto L_800ABD2C; break;
        case 36: goto L_800ABD2C; break;
        case 37: goto L_800ABD2C; break;
        case 38: goto L_800ABCA4; break;
        case 39: goto L_800ABD2C; break;
        case 40: goto L_800ABD2C; break;
        case 41: goto L_800ABD2C; break;
        case 42: goto L_800ABCA4; break;
        default: switch_error(__func__, 0x800ABC80, 0x80108460);
    }
    // 0x800ABC84: nop

L_800ABC88:
    // 0x800ABC88: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800ABC8C: beq         $v1, $at, L_800ABD2C
    if (ctx->r3 == ctx->r1) {
        // 0x800ABC90: addiu       $at, $zero, 0x7A
        ctx->r1 = ADD32(0, 0X7A);
            goto L_800ABD2C;
    }
    // 0x800ABC90: addiu       $at, $zero, 0x7A
    ctx->r1 = ADD32(0, 0X7A);
    // 0x800ABC94: beq         $v1, $at, L_800ABD2C
    if (ctx->r3 == ctx->r1) {
        // 0x800ABC98: nop
    
            goto L_800ABD2C;
    }
    // 0x800ABC98: nop

    // 0x800ABC9C: b           L_800ABD2C
    // 0x800ABCA0: nop

        goto L_800ABD2C;
    // 0x800ABCA0: nop

L_800ABCA4:
    // 0x800ABCA4: lh          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
    // 0x800ABCA8: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800ABCAC: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x800ABCB0: sh          $s0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r16;
    // 0x800ABCB4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800ABCB8: b           L_800ABD2C
    // 0x800ABCBC: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
        goto L_800ABD2C;
    // 0x800ABCBC: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
L_800ABCC0:
    // 0x800ABCC0: lh          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
    // 0x800ABCC4: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800ABCC8: addu        $a0, $s3, $t9
    ctx->r4 = ADD32(ctx->r19, ctx->r25);
    // 0x800ABCCC: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800ABCD0: sh          $s0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r16;
    // 0x800ABCD4: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x800ABCD8: b           L_800ABD2C
    // 0x800ABCDC: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
        goto L_800ABD2C;
    // 0x800ABCDC: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
L_800ABCE0:
    // 0x800ABCE0: sh          $a2, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r6;
L_800ABCE4:
    // 0x800ABCE4: lh          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
    // 0x800ABCE8: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x800ABCEC: addu        $a0, $s3, $t8
    ctx->r4 = ADD32(ctx->r19, ctx->r24);
    // 0x800ABCF0: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x800ABCF4: sh          $s0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r16;
    // 0x800ABCF8: lh          $t6, 0x10($a1)
    ctx->r14 = S32(MEM_H(ctx->r5, 0X10));
    // 0x800ABCFC: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x800ABD00: sh          $t9, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r25;
    // 0x800ABD04: b           L_800ABD2C
    // 0x800ABD08: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
        goto L_800ABD2C;
    // 0x800ABD08: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
L_800ABD0C:
    // 0x800ABD0C: lh          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
    // 0x800ABD10: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800ABD14: addu        $a0, $s3, $t7
    ctx->r4 = ADD32(ctx->r19, ctx->r15);
    // 0x800ABD18: sh          $s0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r16;
    // 0x800ABD1C: lh          $t8, 0x10($a1)
    ctx->r24 = S32(MEM_H(ctx->r5, 0X10));
    // 0x800ABD20: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800ABD24: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x800ABD28: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
L_800ABD2C:
    // 0x800ABD2C: lui         $a1, 0x802B
    ctx->r5 = S32(0X802B << 16);
    // 0x800ABD30: lh          $a1, -0x5376($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, -0X5376));
L_800ABD34:
    // 0x800ABD34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800ABD38: sll         $t9, $s0, 16
    ctx->r25 = S32(ctx->r16 << 16);
    // 0x800ABD3C: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800ABD40: slt         $at, $s0, $a1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800ABD44: bne         $at, $zero, L_800AB9F0
    if (ctx->r1 != 0) {
        // 0x800ABD48: nop
    
            goto L_800AB9F0;
    }
    // 0x800ABD48: nop

    // 0x800ABD4C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800ABD50:
    // 0x800ABD50: lh          $a2, 0x0($s4)
    ctx->r6 = S32(MEM_H(ctx->r20, 0X0));
    // 0x800ABD54: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x800ABD58: addiu       $t0, $t0, 0x61A8
    ctx->r8 = ADD32(ctx->r8, 0X61A8);
    // 0x800ABD5C: addiu       $a3, $zero, 0x230
    ctx->r7 = ADD32(0, 0X230);
    // 0x800ABD60: blez        $a2, L_800ABDF8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800ABD64: addiu       $s2, $zero, 0x24
        ctx->r18 = ADD32(0, 0X24);
            goto L_800ABDF8;
    }
    // 0x800ABD64: addiu       $s2, $zero, 0x24
    ctx->r18 = ADD32(0, 0X24);
    // 0x800ABD68: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
L_800ABD6C:
    // 0x800ABD6C: lui         $t6, 0x802B
    ctx->r14 = S32(0X802B << 16);
    // 0x800ABD70: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x800ABD74: lh          $t6, -0x69C0($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X69C0));
    // 0x800ABD78: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800ABD7C: addiu       $t7, $t7, -0x1988
    ctx->r15 = ADD32(ctx->r15, -0X1988);
    // 0x800ABD80: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800ABD84: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x800ABD88: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800ABD8C: addu        $a1, $t9, $t7
    ctx->r5 = ADD32(ctx->r25, ctx->r15);
    // 0x800ABD90: lh          $v0, 0x8($a1)
    ctx->r2 = S32(MEM_H(ctx->r5, 0X8));
    // 0x800ABD94: lh          $t8, 0xA($a1)
    ctx->r24 = S32(MEM_H(ctx->r5, 0XA));
    // 0x800ABD98: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800ABD9C: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x800ABDA0: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
    // 0x800ABDA4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800ABDA8: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800ABDAC: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800ABDB0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800ABDB4: beq         $at, $zero, L_800ABDE4
    if (ctx->r1 == 0) {
        // 0x800ABDB8: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_800ABDE4;
    }
    // 0x800ABDB8: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_800ABDBC:
    // 0x800ABDBC: multu       $v1, $s2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ABDC0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800ABDC4: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x800ABDC8: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800ABDCC: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800ABDD0: mflo        $t8
    ctx->r24 = lo;
    // 0x800ABDD4: addu        $v0, $t0, $t8
    ctx->r2 = ADD32(ctx->r8, ctx->r24);
    // 0x800ABDD8: sh          $a3, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r7;
    // 0x800ABDDC: bne         $at, $zero, L_800ABDBC
    if (ctx->r1 != 0) {
        // 0x800ABDE0: sh          $a3, 0x12($v0)
        MEM_H(0X12, ctx->r2) = ctx->r7;
            goto L_800ABDBC;
    }
    // 0x800ABDE0: sh          $a3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r7;
L_800ABDE4:
    // 0x800ABDE4: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x800ABDE8: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800ABDEC: slt         $at, $s0, $a2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800ABDF0: bnel        $at, $zero, L_800ABD6C
    if (ctx->r1 != 0) {
        // 0x800ABDF4: sll         $t8, $s0, 1
        ctx->r24 = S32(ctx->r16 << 1);
            goto L_800ABD6C;
    }
    goto skip_26;
    // 0x800ABDF4: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    skip_26:
L_800ABDF8:
    // 0x800ABDF8: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800ABDFC: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800ABE00: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800ABE04: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800ABE08: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800ABE0C: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800ABE10: jr          $ra
    // 0x800ABE14: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x800ABE14: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void __allocParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2570: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x800C2574: lw          $v0, 0x2140($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, 0X2140));
    // 0x800C2578: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C257C: lw          $a0, 0x2C($v0)
    ctx->r4 = S32(MEM_W(ctx->r2, 0X2C));
    // 0x800C2580: beq         $a0, $zero, L_800C2598
    if (ctx->r4 == 0) {
        // 0x800C2584: nop
    
            goto L_800C2598;
    }
    // 0x800C2584: nop

    // 0x800C2588: lw          $t6, 0x0($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X0));
    // 0x800C258C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C2590: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x800C2594: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800C2598:
    // 0x800C2598: jr          $ra
    // 0x800C259C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C259C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void controllerThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C1F8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8004C1FC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8004C200: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8004C204: addiu       $fp, $fp, 0x3668
    ctx->r30 = ADD32(ctx->r30, 0X3668);
    // 0x8004C208: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8004C20C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8004C210: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004C214: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8004C218: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8004C21C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8004C220: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8004C224: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8004C228: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8004C22C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8004C230: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004C234: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8004C238: addiu       $a1, $a1, 0x36F8
    ctx->r5 = ADD32(ctx->r5, 0X36F8);
    // 0x8004C23C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8004C240: jal         0x800BB760
    // 0x8004C244: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8004C244: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x8004C248: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004C24C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004C250: addiu       $a1, $a1, 0x35D8
    ctx->r5 = ADD32(ctx->r5, 0X35D8);
    // 0x8004C254: addiu       $a0, $a0, -0xCB8
    ctx->r4 = ADD32(ctx->r4, -0XCB8);
    // 0x8004C258: jal         0x8004C57C
    // 0x8004C25C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    osScAddClient(rdram, ctx);
        goto after_1;
    // 0x8004C25C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_1:
    // 0x8004C260: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004C264: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8004C268: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x8004C26C: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8004C270: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004C274: addiu       $s4, $s4, 0x38B4
    ctx->r20 = ADD32(ctx->r20, 0X38B4);
    // 0x8004C278: addiu       $s5, $s5, 0x36C8
    ctx->r21 = ADD32(ctx->r21, 0X36C8);
    // 0x8004C27C: addiu       $s7, $s7, 0x3638
    ctx->r23 = ADD32(ctx->r23, 0X3638);
    // 0x8004C280: addiu       $s6, $zero, 0xE
    ctx->r22 = ADD32(0, 0XE);
    // 0x8004C284: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8004C288: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x8004C28C: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
    // 0x8004C290: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8004C294:
    // 0x8004C294: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
L_8004C298:
    // 0x8004C298: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8004C29C: jal         0x800BB440
    // 0x8004C2A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8004C2A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x8004C2A4: lw          $t6, 0x4C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8004C2A8: lh          $v0, 0x0($t6)
    ctx->r2 = S32(MEM_H(ctx->r14, 0X0));
    // 0x8004C2AC: beq         $v0, $s0, L_8004C2CC
    if (ctx->r2 == ctx->r16) {
        // 0x8004C2B0: nop
    
            goto L_8004C2CC;
    }
    // 0x8004C2B0: nop

    // 0x8004C2B4: beq         $v0, $s2, L_8004C2DC
    if (ctx->r2 == ctx->r18) {
        // 0x8004C2B8: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8004C2DC;
    }
    // 0x8004C2B8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8004C2BC: beq         $v0, $s3, L_8004C2F0
    if (ctx->r2 == ctx->r19) {
        // 0x8004C2C0: nop
    
            goto L_8004C2F0;
    }
    // 0x8004C2C0: nop

    // 0x8004C2C4: b           L_8004C298
    // 0x8004C2C8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
        goto L_8004C298;
    // 0x8004C2C8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
L_8004C2CC:
    // 0x8004C2CC: jal         0x80051AF8
    // 0x8004C2D0: nop

    updatecontrollers(rdram, ctx);
        goto after_3;
    // 0x8004C2D0: nop

    after_3:
    // 0x8004C2D4: b           L_8004C298
    // 0x8004C2D8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
        goto L_8004C298;
    // 0x8004C2D8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
L_8004C2DC:
    // 0x8004C2DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004C2E0: jal         0x800BB610
    // 0x8004C2E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8004C2E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8004C2E8: b           L_8004C298
    // 0x8004C2EC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
        goto L_8004C298;
    // 0x8004C2EC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
L_8004C2F0:
    // 0x8004C2F0: jal         0x800BBA50
    // 0x8004C2F4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    osViSetYScale_recomp(rdram, ctx);
        goto after_5;
    // 0x8004C2F4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_5:
    // 0x8004C2F8: jal         0x800BAAE0
    // 0x8004C2FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_6;
    // 0x8004C2FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8004C300: sb          $s0, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r16;
    // 0x8004C304: b           L_8004C294
    // 0x8004C308: sb          $s6, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r22;
        goto L_8004C294;
    // 0x8004C308: sb          $s6, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r22;
    // 0x8004C30C: nop

    // 0x8004C310: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8004C314: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8004C318: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8004C31C: lw          $s1, 0x24($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8004C320: lw          $s2, 0x28($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8004C324: lw          $s3, 0x2C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8004C328: lw          $s4, 0x30($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8004C32C: lw          $s5, 0x34($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X34));
    // 0x8004C330: lw          $s6, 0x38($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X38));
    // 0x8004C334: lw          $s7, 0x3C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x8004C338: lw          $fp, 0x40($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X40));
    // 0x8004C33C: jr          $ra
    // 0x8004C340: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8004C340: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void alHeapDBAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF830: lw          $t6, 0x10($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X10));
    // 0x800BF834: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BF838: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BF83C: multu       $a3, $t6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BF840: lw          $t9, 0x8($a2)
    ctx->r25 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800BF844: lw          $t8, 0x0($a2)
    ctx->r24 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800BF848: lw          $a0, 0x4($a2)
    ctx->r4 = S32(MEM_W(ctx->r6, 0X4));
    // 0x800BF84C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800BF850: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800BF854: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BF858: mflo        $v0
    ctx->r2 = lo;
    // 0x800BF85C: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x800BF860: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x800BF864: addu        $t1, $a0, $t7
    ctx->r9 = ADD32(ctx->r4, ctx->r15);
    // 0x800BF868: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x800BF86C: bne         $at, $zero, L_800BF87C
    if (ctx->r1 != 0) {
        // 0x800BF870: addu        $t2, $a0, $t7
        ctx->r10 = ADD32(ctx->r4, ctx->r15);
            goto L_800BF87C;
    }
    // 0x800BF870: addu        $t2, $a0, $t7
    ctx->r10 = ADD32(ctx->r4, ctx->r15);
    // 0x800BF874: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800BF878: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
L_800BF87C:
    // 0x800BF87C: jr          $ra
    // 0x800BF880: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800BF880: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void FTA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099868: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x8009986C: lw          $t8, -0x5474($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X5474));
    // 0x80099870: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80099874: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80099878: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8009987C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80099880: bne         $t8, $at, L_800998CC
    if (ctx->r24 != ctx->r1) {
        // 0x80099884: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800998CC;
    }
    // 0x80099884: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80099888: lh          $t9, 0x2CC($a1)
    ctx->r25 = S32(MEM_H(ctx->r5, 0X2CC));
    // 0x8009988C: slti        $at, $t7, 0x73
    ctx->r1 = SIGNED(ctx->r15) < 0X73 ? 1 : 0;
    // 0x80099890: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x80099894: blezl       $t9, L_800998C8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80099898: sh          $t0, 0x2CC($a1)
        MEM_H(0X2CC, ctx->r5) = ctx->r8;
            goto L_800998C8;
    }
    goto skip_0;
    // 0x80099898: sh          $t0, 0x2CC($a1)
    MEM_H(0X2CC, ctx->r5) = ctx->r8;
    skip_0:
    // 0x8009989C: bne         $at, $zero, L_800998AC
    if (ctx->r1 != 0) {
        // 0x800998A0: slti        $at, $t7, 0x77
        ctx->r1 = SIGNED(ctx->r15) < 0X77 ? 1 : 0;
            goto L_800998AC;
    }
    // 0x800998A0: slti        $at, $t7, 0x77
    ctx->r1 = SIGNED(ctx->r15) < 0X77 ? 1 : 0;
    // 0x800998A4: bnel        $at, $zero, L_800998C8
    if (ctx->r1 != 0) {
        // 0x800998A8: sh          $t0, 0x2CC($a1)
        MEM_H(0X2CC, ctx->r5) = ctx->r8;
            goto L_800998C8;
    }
    goto skip_1;
    // 0x800998A8: sh          $t0, 0x2CC($a1)
    MEM_H(0X2CC, ctx->r5) = ctx->r8;
    skip_1:
L_800998AC:
    // 0x800998AC: lh          $v0, 0x2CE($a1)
    ctx->r2 = S32(MEM_H(ctx->r5, 0X2CE));
    // 0x800998B0: slti        $at, $v0, 0x73
    ctx->r1 = SIGNED(ctx->r2) < 0X73 ? 1 : 0;
    // 0x800998B4: bne         $at, $zero, L_800998C4
    if (ctx->r1 != 0) {
        // 0x800998B8: slti        $at, $v0, 0x77
        ctx->r1 = SIGNED(ctx->r2) < 0X77 ? 1 : 0;
            goto L_800998C4;
    }
    // 0x800998B8: slti        $at, $v0, 0x77
    ctx->r1 = SIGNED(ctx->r2) < 0X77 ? 1 : 0;
    // 0x800998BC: bne         $at, $zero, L_800998CC
    if (ctx->r1 != 0) {
        // 0x800998C0: nop
    
            goto L_800998CC;
    }
    // 0x800998C0: nop

L_800998C4:
    // 0x800998C4: sh          $t0, 0x2CC($a1)
    MEM_H(0X2CC, ctx->r5) = ctx->r8;
L_800998C8:
    // 0x800998C8: sh          $a0, 0x2CE($a1)
    MEM_H(0X2CE, ctx->r5) = ctx->r4;
L_800998CC:
    // 0x800998CC: jr          $ra
    // 0x800998D0: nop

    return;
    // 0x800998D0: nop

;}
RECOMP_FUNC void alFxParamHdl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0C78: addiu       $v1, $a1, -0x2
    ctx->r3 = ADD32(ctx->r5, -0X2);
    // 0x800D0C7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D0C80: andi        $t6, $v1, 0x7
    ctx->r14 = ctx->r3 & 0X7;
    // 0x800D0C84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D0C88: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x800D0C8C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D0C90: beq         $at, $zero, L_800D0EC0
    if (ctx->r1 == 0) {
        // 0x800D0C94: lw          $t0, 0x0($a2)
        ctx->r8 = S32(MEM_W(ctx->r6, 0X0));
            goto L_800D0EC0;
    }
    // 0x800D0C94: lw          $t0, 0x0($a2)
    ctx->r8 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800D0C98: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D0C9C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800D0CA0: addu        $at, $at, $t6
    gpr jr_addend_800D0CA8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800D0CA4: lw          $t6, -0x5E70($at)
    ctx->r14 = ADD32(ctx->r1, -0X5E70);
    // 0x800D0CA8: jr          $t6
    // 0x800D0CAC: nop

    switch (jr_addend_800D0CA8 >> 2) {
        case 0: goto L_800D0CB0; break;
        case 1: goto L_800D0CE4; break;
        case 2: goto L_800D0D44; break;
        case 3: goto L_800D0D18; break;
        case 4: goto L_800D0D70; break;
        case 5: goto L_800D0D9C; break;
        case 6: goto L_800D0E04; break;
        case 7: goto L_800D0E7C; break;
        default: switch_error(__func__, 0x800D0CA8, 0x8010A190);
    }
    // 0x800D0CAC: nop

L_800D0CB0:
    // 0x800D0CB0: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D0CB4: and         $t7, $t0, $at
    ctx->r15 = ctx->r8 & ctx->r1;
    // 0x800D0CB8: lw          $t8, 0x20($a3)
    ctx->r24 = S32(MEM_W(ctx->r7, 0X20));
    // 0x800D0CBC: bgez        $v1, L_800D0CCC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D0CC0: sra         $t9, $v1, 3
        ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800D0CCC;
    }
    // 0x800D0CC0: sra         $t9, $v1, 3
    ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800D0CC4: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800D0CC8: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_800D0CCC:
    // 0x800D0CCC: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800D0CD0: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800D0CD4: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800D0CD8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800D0CDC: b           L_800D0EC0
    // 0x800D0CE0: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
        goto L_800D0EC0;
    // 0x800D0CE0: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
L_800D0CE4:
    // 0x800D0CE4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D0CE8: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x800D0CEC: lw          $t4, 0x20($a3)
    ctx->r12 = S32(MEM_W(ctx->r7, 0X20));
    // 0x800D0CF0: bgez        $v1, L_800D0D00
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D0CF4: sra         $t5, $v1, 3
        ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800D0D00;
    }
    // 0x800D0CF4: sra         $t5, $v1, 3
    ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800D0CF8: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800D0CFC: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_800D0D00:
    // 0x800D0D00: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800D0D04: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800D0D08: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800D0D0C: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x800D0D10: b           L_800D0EC0
    // 0x800D0D14: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
        goto L_800D0EC0;
    // 0x800D0D14: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
L_800D0D18:
    // 0x800D0D18: lw          $t8, 0x20($a3)
    ctx->r24 = S32(MEM_W(ctx->r7, 0X20));
    // 0x800D0D1C: bgez        $v1, L_800D0D2C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D0D20: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800D0D2C;
    }
    // 0x800D0D20: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800D0D24: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800D0D28: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_800D0D2C:
    // 0x800D0D2C: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x800D0D30: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x800D0D34: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800D0D38: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x800D0D3C: b           L_800D0EC0
    // 0x800D0D40: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
        goto L_800D0EC0;
    // 0x800D0D40: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
L_800D0D44:
    // 0x800D0D44: lw          $t5, 0x20($a3)
    ctx->r13 = S32(MEM_W(ctx->r7, 0X20));
    // 0x800D0D48: bgez        $v1, L_800D0D58
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D0D4C: sra         $t4, $v1, 3
        ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800D0D58;
    }
    // 0x800D0D4C: sra         $t4, $v1, 3
    ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800D0D50: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800D0D54: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_800D0D58:
    // 0x800D0D58: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800D0D5C: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800D0D60: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800D0D64: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x800D0D68: b           L_800D0EC0
    // 0x800D0D6C: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
        goto L_800D0EC0;
    // 0x800D0D6C: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
L_800D0D70:
    // 0x800D0D70: lw          $t9, 0x20($a3)
    ctx->r25 = S32(MEM_W(ctx->r7, 0X20));
    // 0x800D0D74: bgez        $v1, L_800D0D84
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D0D78: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800D0D84;
    }
    // 0x800D0D78: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800D0D7C: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800D0D80: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_800D0D84:
    // 0x800D0D84: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x800D0D88: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x800D0D8C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800D0D90: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x800D0D94: b           L_800D0EC0
    // 0x800D0D98: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
        goto L_800D0EC0;
    // 0x800D0D98: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
L_800D0D9C:
    // 0x800D0D9C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800D0DA0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800D0DA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D0DA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D0DAC: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x800D0DB0: lw          $t2, 0x2140($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, 0X2140));
    // 0x800D0DB4: lw          $t5, 0x20($a3)
    ctx->r13 = S32(MEM_W(ctx->r7, 0X20));
    // 0x800D0DB8: lw          $t4, 0x44($t2)
    ctx->r12 = S32(MEM_W(ctx->r10, 0X44));
    // 0x800D0DBC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800D0DC0: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800D0DC4: nop

    // 0x800D0DC8: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800D0DCC: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800D0DD0: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x800D0DD4: div.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f4.d);
    // 0x800D0DD8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800D0DDC: bgez        $v1, L_800D0DEC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D0DE0: sra         $t6, $v1, 3
        ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800D0DEC;
    }
    // 0x800D0DE0: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800D0DE4: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800D0DE8: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_800D0DEC:
    // 0x800D0DEC: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x800D0DF0: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x800D0DF4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800D0DF8: addu        $t1, $t5, $t3
    ctx->r9 = ADD32(ctx->r13, ctx->r11);
    // 0x800D0DFC: b           L_800D0EC0
    // 0x800D0E00: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
        goto L_800D0EC0;
    // 0x800D0E00: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
L_800D0E04:
    // 0x800D0E04: lw          $t9, 0x20($a3)
    ctx->r25 = S32(MEM_W(ctx->r7, 0X20));
    // 0x800D0E08: bgez        $v1, L_800D0E18
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D0E0C: sra         $t8, $v1, 3
        ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800D0E18;
    }
    // 0x800D0E0C: sra         $t8, $v1, 3
    ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800D0E10: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800D0E14: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_800D0E18:
    // 0x800D0E18: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800D0E1C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800D0E20: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800D0E24: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x800D0E28: lw          $t2, 0x4($v0)
    ctx->r10 = S32(MEM_W(ctx->r2, 0X4));
    // 0x800D0E2C: lw          $t4, 0x0($v0)
    ctx->r12 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800D0E30: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800D0E34: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800D0E38: subu        $t6, $t2, $t4
    ctx->r14 = SUB32(ctx->r10, ctx->r12);
    // 0x800D0E3C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800D0E40: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D0E44: bgez        $t6, L_800D0E5C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800D0E48: cvt.d.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
            goto L_800D0E5C;
    }
    // 0x800D0E48: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x800D0E4C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D0E50: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D0E54: nop

    // 0x800D0E58: add.d       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f18.d + ctx->f16.d;
L_800D0E5C:
    // 0x800D0E5C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800D0E60: ldc1        $f10, -0x5E50($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X5E50);
    // 0x800D0E64: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800D0E68: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800D0E6C: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x800D0E70: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800D0E74: b           L_800D0EC0
    // 0x800D0E78: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
        goto L_800D0EC0;
    // 0x800D0E78: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
L_800D0E7C:
    // 0x800D0E7C: bgez        $v1, L_800D0E8C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D0E80: sra         $v0, $v1, 3
        ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800D0E8C;
    }
    // 0x800D0E80: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800D0E84: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800D0E88: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_800D0E8C:
    // 0x800D0E8C: lw          $t3, 0x20($a3)
    ctx->r11 = S32(MEM_W(ctx->r7, 0X20));
    // 0x800D0E90: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800D0E94: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x800D0E98: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800D0E9C: addu        $t1, $t3, $t5
    ctx->r9 = ADD32(ctx->r11, ctx->r13);
    // 0x800D0EA0: lw          $a1, 0x20($t1)
    ctx->r5 = S32(MEM_W(ctx->r9, 0X20));
    // 0x800D0EA4: beql        $a1, $zero, L_800D0EC4
    if (ctx->r5 == 0) {
        // 0x800D0EA8: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800D0EC4;
    }
    goto skip_0;
    // 0x800D0EA8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x800D0EAC: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x800D0EB0: lw          $t8, 0x20($a3)
    ctx->r24 = S32(MEM_W(ctx->r7, 0X20));
    // 0x800D0EB4: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x800D0EB8: jal         0x800CC270
    // 0x800D0EBC: lw          $a0, 0x20($t9)
    ctx->r4 = S32(MEM_W(ctx->r25, 0X20));
    init_lpfilter(rdram, ctx);
        goto after_0;
    // 0x800D0EBC: lw          $a0, 0x20($t9)
    ctx->r4 = S32(MEM_W(ctx->r25, 0X20));
    after_0:
L_800D0EC0:
    // 0x800D0EC0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800D0EC4:
    // 0x800D0EC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D0EC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D0ECC: jr          $ra
    // 0x800D0ED0: nop

    return;
    // 0x800D0ED0: nop

;}
RECOMP_FUNC void changespritesect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092938: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009293C: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80092940: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80092944: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80092948: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009294C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80092950: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80092954: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80092958: bltz        $t9, L_8009296C
    if (SIGNED(ctx->r25) < 0) {
        // 0x8009295C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009296C;
    }
    // 0x8009295C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092960: slti        $at, $t9, 0x292
    ctx->r1 = SIGNED(ctx->r25) < 0X292 ? 1 : 0;
    // 0x80092964: bne         $at, $zero, L_80092974
    if (ctx->r1 != 0) {
        // 0x80092968: sll         $t0, $a0, 2
        ctx->r8 = S32(ctx->r4 << 2);
            goto L_80092974;
    }
    // 0x80092968: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
L_8009296C:
    // 0x8009296C: b           L_800929E0
    // 0x80092970: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800929E0;
    // 0x80092970: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80092974:
    // 0x80092974: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80092978: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8009297C: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80092980: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80092984: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x80092988: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8009298C: lh          $v0, 0x6BB8($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X6BB8));
    // 0x80092990: addiu       $at, $zero, 0x291
    ctx->r1 = ADD32(0, 0X291);
    // 0x80092994: bne         $a1, $v0, L_800929A4
    if (ctx->r5 != ctx->r2) {
        // 0x80092998: nop
    
            goto L_800929A4;
    }
    // 0x80092998: nop

    // 0x8009299C: b           L_800929E0
    // 0x800929A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800929E0;
    // 0x800929A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800929A4:
    // 0x800929A4: bne         $v0, $at, L_800929B4
    if (ctx->r2 != ctx->r1) {
        // 0x800929A8: nop
    
            goto L_800929B4;
    }
    // 0x800929A8: nop

    // 0x800929AC: b           L_800929E0
    // 0x800929B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800929E0;
    // 0x800929B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800929B4:
    // 0x800929B4: jal         0x80092768
    // 0x800929B8: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    deletespritesect(rdram, ctx);
        goto after_0;
    // 0x800929B8: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    after_0:
    // 0x800929BC: bgez        $v0, L_800929CC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800929C0: lh          $a1, 0x1E($sp)
        ctx->r5 = S32(MEM_H(ctx->r29, 0X1E));
            goto L_800929CC;
    }
    // 0x800929C0: lh          $a1, 0x1E($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X1E));
    // 0x800929C4: b           L_800929E0
    // 0x800929C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800929E0;
    // 0x800929C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800929CC:
    // 0x800929CC: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x800929D0: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800929D4: jal         0x80092588
    // 0x800929D8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    insertspritesect(rdram, ctx);
        goto after_1;
    // 0x800929D8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_1:
    // 0x800929DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800929E0:
    // 0x800929E0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800929E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800929E8: jr          $ra
    // 0x800929EC: nop

    return;
    // 0x800929EC: nop

;}
RECOMP_FUNC void alResamplePull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD57C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800CD580: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CD584: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800CD588: lw          $t1, 0x0($a0)
    ctx->r9 = S32(MEM_W(ctx->r4, 0X0));
    // 0x800CD58C: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x800CD590: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800CD594: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x800CD598: bne         $a2, $zero, L_800CD5A8
    if (ctx->r6 != 0) {
        // 0x800CD59C: sh          $t6, 0x46($sp)
        MEM_H(0X46, ctx->r29) = ctx->r14;
            goto L_800CD5A8;
    }
    // 0x800CD59C: sh          $t6, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r14;
    // 0x800CD5A0: b           L_800CD774
    // 0x800CD5A4: lw          $v0, 0x60($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X60));
        goto L_800CD774;
    // 0x800CD5A4: lw          $v0, 0x60($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X60));
L_800CD5A8:
    // 0x800CD5A8: lw          $t7, 0x1C($t0)
    ctx->r15 = S32(MEM_W(ctx->r8, 0X1C));
    // 0x800CD5AC: lw          $t8, 0x60($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800CD5B0: beql        $t7, $zero, L_800CD61C
    if (ctx->r15 == 0) {
        // 0x800CD5B4: lwc1        $f2, 0x18($t0)
        ctx->f2.u32l = S32(MEM_W(ctx->r8, 0X18));
            goto L_800CD61C;
    }
    goto skip_0;
    // 0x800CD5B4: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = S32(MEM_W(ctx->r8, 0X18));
    skip_0:
    // 0x800CD5B8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800CD5BC: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800CD5C0: lw          $t9, 0x4($t1)
    ctx->r25 = S32(MEM_W(ctx->r9, 0X4));
    // 0x800CD5C4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CD5C8: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x800CD5CC: jalr        $t9
    // 0x800CD5D0: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CD5D0: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_0:
    // 0x800CD5D4: lh          $t3, 0x46($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X46));
    // 0x800CD5D8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CD5DC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CD5E0: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800CD5E4: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800CD5E8: lw          $t2, 0x58($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X58));
    // 0x800CD5EC: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800CD5F0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800CD5F4: lw          $t6, 0x54($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X54));
    // 0x800CD5F8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800CD5FC: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800CD600: lh          $t8, 0x0($t6)
    ctx->r24 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800CD604: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800CD608: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800CD60C: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x800CD610: b           L_800CD770
    // 0x800CD614: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_800CD770;
    // 0x800CD614: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800CD618: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = S32(MEM_W(ctx->r8, 0X18));
L_800CD61C:
    // 0x800CD61C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CD620: ldc1        $f4, -0x5F68($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X5F68);
    // 0x800CD624: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800CD628: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CD62C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x800CD630: nop

    // 0x800CD634: bc1fl       L_800CD64C
    if (!c1cs) {
        // 0x800CD638: lui         $at, 0x4700
        ctx->r1 = S32(0X4700 << 16);
            goto L_800CD64C;
    }
    goto skip_1;
    // 0x800CD638: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    skip_1:
    // 0x800CD63C: lwc1        $f8, -0x5F60($at)
    ctx->f8.u32l = S32(MEM_W(ctx->r1, -0X5F60));
    // 0x800CD640: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x800CD644: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = S32(MEM_W(ctx->r8, 0X18));
    // 0x800CD648: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
L_800CD64C:
    // 0x800CD64C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800CD650: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CD654: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x800CD658: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800CD65C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800CD660: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800CD664: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800CD668: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800CD66C: nop

    // 0x800CD670: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CD674: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800CD678: swc1        $f4, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f4.u32l;
    // 0x800CD67C: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = S32(MEM_W(ctx->r8, 0X18));
    // 0x800CD680: div.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800CD684: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = S32(MEM_W(ctx->r8, 0X20));
    // 0x800CD688: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x800CD68C: lwc1        $f10, 0x18($t0)
    ctx->f10.u32l = S32(MEM_W(ctx->r8, 0X18));
    // 0x800CD690: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800CD694: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800CD698: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800CD69C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800CD6A0: nop

    // 0x800CD6A4: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x800CD6A8: nop

    // 0x800CD6AC: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800CD6B0: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800CD6B4: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    // 0x800CD6B8: lw          $t3, 0x60($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800CD6BC: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800CD6C0: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800CD6C4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800CD6C8: lw          $t9, 0x4($t1)
    ctx->r25 = S32(MEM_W(ctx->r9, 0X4));
    // 0x800CD6CC: jalr        $t9
    // 0x800CD6D0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CD6D0: nop

    after_1:
    // 0x800CD6D4: lw          $t0, 0x50($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800CD6D8: lh          $t5, 0x46($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0X46));
    // 0x800CD6DC: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800CD6E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CD6E4: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = S32(MEM_W(ctx->r8, 0X18));
    // 0x800CD6E8: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CD6EC: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800CD6F0: lw          $t2, 0x58($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X58));
    // 0x800CD6F4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CD6F8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CD6FC: lw          $t8, 0x54($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X54));
    // 0x800CD700: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800CD704: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x800CD708: lh          $t9, 0x0($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X0));
    // 0x800CD70C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800CD710: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800CD714: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x800CD718: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800CD71C: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CD720: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800CD724: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800CD728: lw          $t3, 0x24($t0)
    ctx->r11 = S32(MEM_W(ctx->r8, 0X24));
    // 0x800CD72C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800CD730: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800CD734: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x800CD738: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x800CD73C: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x800CD740: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800CD744: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800CD748: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800CD74C: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x800CD750: lw          $a0, 0x14($t0)
    ctx->r4 = S32(MEM_W(ctx->r8, 0X14));
    // 0x800CD754: jal         0x800BF6F0
    // 0x800CD758: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800CD758: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_2:
    // 0x800CD75C: lw          $t8, 0x28($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800CD760: lw          $t0, 0x50($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800CD764: lw          $a1, 0x48($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800CD768: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x800CD76C: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
L_800CD770:
    // 0x800CD770: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800CD774:
    // 0x800CD774: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800CD778: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800CD77C: jr          $ra
    // 0x800CD780: nop

    return;
    // 0x800CD780: nop

;}
RECOMP_FUNC void moveweapons(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088444: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x80088448: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8008844C: lui         $s5, 0x8027
    ctx->r21 = S32(0X8027 << 16);
    // 0x80088450: lh          $s5, 0x2860($s5)
    ctx->r21 = S32(MEM_H(ctx->r21, 0X2860));
    // 0x80088454: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80088458: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8008845C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80088460: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80088464: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80088468: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8008846C: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80088470: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80088474: bltz        $s5, L_800897B0
    if (SIGNED(ctx->r21) < 0) {
        // 0x80088478: sw          $s0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r16;
            goto L_800897B0;
    }
    // 0x80088478: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8008847C: lui         $s7, 0x8024
    ctx->r23 = S32(0X8024 << 16);
    // 0x80088480: lui         $s6, 0x8010
    ctx->r22 = S32(0X8010 << 16);
    // 0x80088484: addiu       $s6, $s6, -0x9A0
    ctx->r22 = ADD32(ctx->r22, -0X9A0);
    // 0x80088488: addiu       $s7, $s7, 0x6BA8
    ctx->r23 = ADD32(ctx->r23, 0X6BA8);
    // 0x8008848C: addiu       $fp, $zero, 0x2C
    ctx->r30 = ADD32(0, 0X2C);
L_80088490:
    // 0x80088490: multu       $s5, $fp
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088494: sll         $t6, $s5, 1
    ctx->r14 = S32(ctx->r21 << 1);
    // 0x80088498: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x8008849C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800884A0: lh          $t7, 0x5F40($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X5F40));
    // 0x800884A4: sll         $t3, $s5, 3
    ctx->r11 = S32(ctx->r21 << 3);
    // 0x800884A8: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x800884AC: addu        $t3, $t3, $s5
    ctx->r11 = ADD32(ctx->r11, ctx->r21);
    // 0x800884B0: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800884B4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800884B8: mflo        $t8
    ctx->r24 = lo;
    // 0x800884BC: addu        $s3, $s7, $t8
    ctx->r19 = ADD32(ctx->r23, ctx->r24);
    // 0x800884C0: lh          $t9, 0x10($s3)
    ctx->r25 = S32(MEM_H(ctx->r19, 0X10));
    // 0x800884C4: lui         $t4, 0x8028
    ctx->r12 = S32(0X8028 << 16);
    // 0x800884C8: sh          $t7, 0xC8($sp)
    MEM_H(0XC8, ctx->r29) = ctx->r15;
    // 0x800884CC: bgezl       $t9, L_800884E8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800884D0: lw          $t5, 0x0($s3)
        ctx->r13 = S32(MEM_W(ctx->r19, 0X0));
            goto L_800884E8;
    }
    goto skip_0;
    // 0x800884D0: lw          $t5, 0x0($s3)
    ctx->r13 = S32(MEM_W(ctx->r19, 0X0));
    skip_0:
    // 0x800884D4: jal         0x80092728
    // 0x800884D8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    deletesprite(rdram, ctx);
        goto after_0;
    // 0x800884D8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_0:
    // 0x800884DC: b           L_800897A8
    // 0x800884E0: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
        goto L_800897A8;
    // 0x800884E0: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
    // 0x800884E4: lw          $t5, 0x0($s3)
    ctx->r13 = S32(MEM_W(ctx->r19, 0X0));
L_800884E8:
    // 0x800884E8: addiu       $t4, $t4, -0x5C00
    ctx->r12 = ADD32(ctx->r12, -0X5C00);
    // 0x800884EC: addu        $s2, $t3, $t4
    ctx->r18 = ADD32(ctx->r11, ctx->r12);
    // 0x800884F0: sw          $t5, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r13;
    // 0x800884F4: lw          $t6, 0x4($s3)
    ctx->r14 = S32(MEM_W(ctx->r19, 0X4));
    // 0x800884F8: sw          $t6, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r14;
    // 0x800884FC: lw          $t7, 0x8($s3)
    ctx->r15 = S32(MEM_W(ctx->r19, 0X8));
    // 0x80088500: sw          $t7, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r15;
    // 0x80088504: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
    // 0x80088508: slti        $at, $v1, 0x9DA
    ctx->r1 = SIGNED(ctx->r3) < 0X9DA ? 1 : 0;
    // 0x8008850C: bne         $at, $zero, L_80088554
    if (ctx->r1 != 0) {
        // 0x80088510: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_80088554;
    }
    // 0x80088510: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80088514: slti        $at, $t0, 0xA2E
    ctx->r1 = SIGNED(ctx->r8) < 0XA2E ? 1 : 0;
    // 0x80088518: bne         $at, $zero, L_80088534
    if (ctx->r1 != 0) {
        // 0x8008851C: addiu       $t8, $t0, -0xA23
        ctx->r24 = ADD32(ctx->r8, -0XA23);
            goto L_80088534;
    }
    // 0x8008851C: addiu       $t8, $t0, -0xA23
    ctx->r24 = ADD32(ctx->r8, -0XA23);
    // 0x80088520: addiu       $at, $zero, 0xF01
    ctx->r1 = ADD32(0, 0XF01);
    // 0x80088524: beql        $t0, $at, L_800888DC
    if (ctx->r8 == ctx->r1) {
        // 0x80088528: addiu       $at, $zero, 0x550
        ctx->r1 = ADD32(0, 0X550);
            goto L_800888DC;
    }
    goto skip_1;
    // 0x80088528: addiu       $at, $zero, 0x550
    ctx->r1 = ADD32(0, 0X550);
    skip_1:
    // 0x8008852C: b           L_800897A8
    // 0x80088530: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
        goto L_800897A8;
    // 0x80088530: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
L_80088534:
    // 0x80088534: sltiu       $at, $t8, 0xB
    ctx->r1 = ctx->r24 < 0XB ? 1 : 0;
    // 0x80088538: beq         $at, $zero, L_800897A4
    if (ctx->r1 == 0) {
        // 0x8008853C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800897A4;
    }
    // 0x8008853C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80088540: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80088544: addu        $at, $at, $t8
    gpr jr_addend_8008854C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80088548: lw          $t8, 0x59E0($at)
    ctx->r24 = ADD32(ctx->r1, 0X59E0);
    // 0x8008854C: jr          $t8
    // 0x80088550: nop

    switch (jr_addend_8008854C >> 2) {
        case 0: goto L_80089778; break;
        case 1: goto L_80089778; break;
        case 2: goto L_80089778; break;
        case 3: goto L_80089778; break;
        case 4: goto L_80089778; break;
        case 5: goto L_800897A4; break;
        case 6: goto L_800897A4; break;
        case 7: goto L_800897A4; break;
        case 8: goto L_800897A4; break;
        case 9: goto L_800897A4; break;
        case 10: goto L_800888D8; break;
        default: switch_error(__func__, 0x8008854C, 0x801059E0);
    }
    // 0x80088550: nop

L_80088554:
    // 0x80088554: slti        $at, $t0, 0x687
    ctx->r1 = SIGNED(ctx->r8) < 0X687 ? 1 : 0;
    // 0x80088558: bne         $at, $zero, L_80088570
    if (ctx->r1 != 0) {
        // 0x8008855C: addiu       $at, $zero, 0x9D9
        ctx->r1 = ADD32(0, 0X9D9);
            goto L_80088570;
    }
    // 0x8008855C: addiu       $at, $zero, 0x9D9
    ctx->r1 = ADD32(0, 0X9D9);
    // 0x80088560: beql        $t0, $at, L_800885B4
    if (ctx->r8 == ctx->r1) {
        // 0x80088564: sll         $a0, $s5, 16
        ctx->r4 = S32(ctx->r21 << 16);
            goto L_800885B4;
    }
    goto skip_2;
    // 0x80088564: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    skip_2:
    // 0x80088568: b           L_800897A8
    // 0x8008856C: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
        goto L_800897A8;
    // 0x8008856C: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
L_80088570:
    // 0x80088570: slti        $at, $t0, 0x551
    ctx->r1 = SIGNED(ctx->r8) < 0X551 ? 1 : 0;
    // 0x80088574: bne         $at, $zero, L_8008859C
    if (ctx->r1 != 0) {
        // 0x80088578: addiu       $t9, $t0, -0x659
        ctx->r25 = ADD32(ctx->r8, -0X659);
            goto L_8008859C;
    }
    // 0x80088578: addiu       $t9, $t0, -0x659
    ctx->r25 = ADD32(ctx->r8, -0X659);
    // 0x8008857C: sltiu       $at, $t9, 0x2E
    ctx->r1 = ctx->r25 < 0X2E ? 1 : 0;
    // 0x80088580: beq         $at, $zero, L_800897A4
    if (ctx->r1 == 0) {
        // 0x80088584: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800897A4;
    }
    // 0x80088584: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80088588: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8008858C: addu        $at, $at, $t9
    gpr jr_addend_80088594 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80088590: lw          $t9, 0x5A0C($at)
    ctx->r25 = ADD32(ctx->r1, 0X5A0C);
    // 0x80088594: jr          $t9
    // 0x80088598: nop

    switch (jr_addend_80088594 >> 2) {
        case 0: goto L_800888D8; break;
        case 1: goto L_800897A4; break;
        case 2: goto L_800897A4; break;
        case 3: goto L_800897A4; break;
        case 4: goto L_800897A4; break;
        case 5: goto L_800897A4; break;
        case 6: goto L_800897A4; break;
        case 7: goto L_800897A4; break;
        case 8: goto L_800897A4; break;
        case 9: goto L_800897A4; break;
        case 10: goto L_800897A4; break;
        case 11: goto L_800888D8; break;
        case 12: goto L_800897A4; break;
        case 13: goto L_800897A4; break;
        case 14: goto L_800897A4; break;
        case 15: goto L_800897A4; break;
        case 16: goto L_800897A4; break;
        case 17: goto L_800897A4; break;
        case 18: goto L_800897A4; break;
        case 19: goto L_800897A4; break;
        case 20: goto L_800897A4; break;
        case 21: goto L_800888D8; break;
        case 22: goto L_800885C8; break;
        case 23: goto L_800897A4; break;
        case 24: goto L_800897A4; break;
        case 25: goto L_800897A4; break;
        case 26: goto L_800897A4; break;
        case 27: goto L_800897A4; break;
        case 28: goto L_800897A4; break;
        case 29: goto L_800897A4; break;
        case 30: goto L_800897A4; break;
        case 31: goto L_800897A4; break;
        case 32: goto L_800897A4; break;
        case 33: goto L_800897A4; break;
        case 34: goto L_800897A4; break;
        case 35: goto L_800897A4; break;
        case 36: goto L_800897A4; break;
        case 37: goto L_800897A4; break;
        case 38: goto L_800897A4; break;
        case 39: goto L_800897A4; break;
        case 40: goto L_800897A4; break;
        case 41: goto L_800897A4; break;
        case 42: goto L_800897A4; break;
        case 43: goto L_800897A4; break;
        case 44: goto L_800897A4; break;
        case 45: goto L_800885B0; break;
        default: switch_error(__func__, 0x80088594, 0x80105A0C);
    }
    // 0x80088598: nop

L_8008859C:
    // 0x8008859C: addiu       $at, $zero, 0x550
    ctx->r1 = ADD32(0, 0X550);
    // 0x800885A0: beql        $t0, $at, L_800888DC
    if (ctx->r8 == ctx->r1) {
        // 0x800885A4: addiu       $at, $zero, 0x550
        ctx->r1 = ADD32(0, 0X550);
            goto L_800888DC;
    }
    goto skip_3;
    // 0x800885A4: addiu       $at, $zero, 0x550
    ctx->r1 = ADD32(0, 0X550);
    skip_3:
    // 0x800885A8: b           L_800897A8
    // 0x800885AC: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
        goto L_800897A8;
    // 0x800885AC: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
L_800885B0:
    // 0x800885B0: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
L_800885B4:
    // 0x800885B4: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800885B8: jal         0x80092728
    // 0x800885BC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    deletesprite(rdram, ctx);
        goto after_1;
    // 0x800885BC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_1:
    // 0x800885C0: b           L_800897A8
    // 0x800885C4: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
        goto L_800897A8;
    // 0x800885C4: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
L_800885C8:
    // 0x800885C8: lw          $a0, 0x34($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X34));
    // 0x800885CC: andi        $t3, $a0, 0x7FF
    ctx->r11 = ctx->r4 & 0X7FF;
    // 0x800885D0: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800885D4: addu        $t5, $s6, $t4
    ctx->r13 = ADD32(ctx->r22, ctx->r12);
    // 0x800885D8: lh          $t6, 0x0($t5)
    ctx->r14 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800885DC: addiu       $t8, $a0, 0x20
    ctx->r24 = ADD32(ctx->r4, 0X20);
    // 0x800885E0: slti        $at, $t8, 0x800
    ctx->r1 = SIGNED(ctx->r24) < 0X800 ? 1 : 0;
    // 0x800885E4: sra         $t7, $t6, 9
    ctx->r15 = S32(SIGNED(ctx->r14) >> 9);
    // 0x800885E8: sw          $t7, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r15;
    // 0x800885EC: bne         $at, $zero, L_8008860C
    if (ctx->r1 != 0) {
        // 0x800885F0: sw          $t8, 0x34($s2)
        MEM_W(0X34, ctx->r18) = ctx->r24;
            goto L_8008860C;
    }
    // 0x800885F0: sw          $t8, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r24;
    // 0x800885F4: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x800885F8: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800885FC: jal         0x80092728
    // 0x80088600: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    deletesprite(rdram, ctx);
        goto after_2;
    // 0x80088600: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_2:
    // 0x80088604: b           L_800897A8
    // 0x80088608: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
        goto L_800897A8;
    // 0x80088608: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
L_8008860C:
    // 0x8008860C: lh          $t3, 0x16($s3)
    ctx->r11 = S32(MEM_H(ctx->r19, 0X16));
    // 0x80088610: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x80088614: multu       $t3, $fp
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088618: mflo        $t4
    ctx->r12 = lo;
    // 0x8008861C: addu        $a0, $s7, $t4
    ctx->r4 = ADD32(ctx->r23, ctx->r12);
    // 0x80088620: lh          $t5, 0x12($a0)
    ctx->r13 = S32(MEM_H(ctx->r4, 0X12));
    // 0x80088624: bnel        $t5, $at, L_80088654
    if (ctx->r13 != ctx->r1) {
        // 0x80088628: lh          $t7, 0x16($s3)
        ctx->r15 = S32(MEM_H(ctx->r19, 0X16));
            goto L_80088654;
    }
    goto skip_4;
    // 0x80088628: lh          $t7, 0x16($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X16));
    skip_4:
    // 0x8008862C: jal         0x80099ED4
    // 0x80088630: nop

    badguy(rdram, ctx);
        goto after_3;
    // 0x80088630: nop

    after_3:
    // 0x80088634: bne         $v0, $zero, L_80088650
    if (ctx->r2 != 0) {
        // 0x80088638: sll         $a0, $s5, 16
        ctx->r4 = S32(ctx->r21 << 16);
            goto L_80088650;
    }
    // 0x80088638: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x8008863C: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80088640: jal         0x80092728
    // 0x80088644: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    deletesprite(rdram, ctx);
        goto after_4;
    // 0x80088644: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_4:
    // 0x80088648: b           L_800897A8
    // 0x8008864C: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
        goto L_800897A8;
    // 0x8008864C: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
L_80088650:
    // 0x80088650: lh          $t7, 0x16($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X16));
L_80088654:
    // 0x80088654: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x80088658: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008865C: multu       $t7, $fp
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088660: mflo        $t8
    ctx->r24 = lo;
    // 0x80088664: addu        $a0, $s7, $t8
    ctx->r4 = ADD32(ctx->r23, ctx->r24);
    // 0x80088668: lh          $t9, 0x14($a0)
    ctx->r25 = S32(MEM_H(ctx->r4, 0X14));
    // 0x8008866C: sh          $t9, 0x14($s3)
    MEM_H(0X14, ctx->r19) = ctx->r25;
    // 0x80088670: lw          $t2, 0x0($a0)
    ctx->r10 = S32(MEM_W(ctx->r4, 0X0));
    // 0x80088674: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x80088678: lw          $t3, 0x4($a0)
    ctx->r11 = S32(MEM_W(ctx->r4, 0X4));
    // 0x8008867C: sw          $t3, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r11;
    // 0x80088680: lh          $t4, 0xE($a0)
    ctx->r12 = S32(MEM_H(ctx->r4, 0XE));
    // 0x80088684: bnel        $t4, $at, L_8008869C
    if (ctx->r12 != ctx->r1) {
        // 0x80088688: lw          $t7, 0x30($s2)
        ctx->r15 = S32(MEM_W(ctx->r18, 0X30));
            goto L_8008869C;
    }
    goto skip_5;
    // 0x80088688: lw          $t7, 0x30($s2)
    ctx->r15 = S32(MEM_W(ctx->r18, 0X30));
    skip_5:
    // 0x8008868C: lw          $t5, 0x8($a0)
    ctx->r13 = S32(MEM_W(ctx->r4, 0X8));
    // 0x80088690: addiu       $t6, $t5, -0x2200
    ctx->r14 = ADD32(ctx->r13, -0X2200);
    // 0x80088694: sw          $t6, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r14;
    // 0x80088698: lw          $t7, 0x30($s2)
    ctx->r15 = S32(MEM_W(ctx->r18, 0X30));
L_8008869C:
    // 0x8008869C: blez        $t7, L_800887C0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800886A0: nop
    
            goto L_800887C0;
    }
    // 0x800886A0: nop

L_800886A4:
    // 0x800886A4: jal         0x80091A50
    // 0x800886A8: lh          $a0, 0x1C($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X1C));
    ksgn(rdram, ctx);
        goto after_5;
    // 0x800886A8: lh          $a0, 0x1C($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X1C));
    after_5:
    // 0x800886AC: lh          $v1, 0x1C($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0X1C));
    // 0x800886B0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800886B4: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800886B8: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800886BC: mflo        $t8
    ctx->r24 = lo;
    // 0x800886C0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800886C4: blez        $t8, L_800886D4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800886C8: negu        $t0, $v1
        ctx->r8 = SUB32(0, ctx->r3);
            goto L_800886D4;
    }
    // 0x800886C8: negu        $t0, $v1
    ctx->r8 = SUB32(0, ctx->r3);
    // 0x800886CC: b           L_800886D4
    // 0x800886D0: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
        goto L_800886D4;
    // 0x800886D0: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
L_800886D4:
    // 0x800886D4: lh          $v0, 0x14($s3)
    ctx->r2 = S32(MEM_H(ctx->r19, 0X14));
    // 0x800886D8: lw          $t8, 0x0($s3)
    ctx->r24 = S32(MEM_W(ctx->r19, 0X0));
    // 0x800886DC: lh          $a0, 0x10($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
    // 0x800886E0: addiu       $t9, $v0, 0x200
    ctx->r25 = ADD32(ctx->r2, 0X200);
    // 0x800886E4: andi        $t2, $t9, 0x7FF
    ctx->r10 = ctx->r25 & 0X7FF;
    // 0x800886E8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800886EC: addu        $t4, $s6, $t3
    ctx->r12 = ADD32(ctx->r22, ctx->r11);
    // 0x800886F0: lh          $t5, 0x0($t4)
    ctx->r13 = S32(MEM_H(ctx->r12, 0X0));
    // 0x800886F4: andi        $t9, $v0, 0x7FF
    ctx->r25 = ctx->r2 & 0X7FF;
    // 0x800886F8: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x800886FC: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088700: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x80088704: lh          $t4, 0x0($t3)
    ctx->r12 = S32(MEM_H(ctx->r11, 0X0));
    // 0x80088708: lw          $t2, 0x8($s3)
    ctx->r10 = S32(MEM_W(ctx->r19, 0X8));
    // 0x8008870C: addiu       $t3, $zero, 0x66F
    ctx->r11 = ADD32(0, 0X66F);
    // 0x80088710: mflo        $t6
    ctx->r14 = lo;
    // 0x80088714: sra         $t7, $t6, 9
    ctx->r15 = S32(SIGNED(ctx->r14) >> 9);
    // 0x80088718: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8008871C: multu       $t4, $s0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088720: lw          $t7, 0x4($s3)
    ctx->r15 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80088724: sll         $t4, $s0, 1
    ctx->r12 = S32(ctx->r16 << 1);
    // 0x80088728: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008872C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80088730: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80088734: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80088738: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8008873C: mflo        $t5
    ctx->r13 = lo;
    // 0x80088740: sra         $t6, $t5, 9
    ctx->r14 = S32(SIGNED(ctx->r13) >> 9);
    // 0x80088744: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x80088748: multu       $t0, $s0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008874C: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80088750: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80088754: addiu       $t5, $t4, -0x28
    ctx->r13 = ADD32(ctx->r12, -0X28);
    // 0x80088758: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8008875C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80088760: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80088764: mflo        $t8
    ctx->r24 = lo;
    // 0x80088768: nop

    // 0x8008876C: nop

    // 0x80088770: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088774: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80088778: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8008877C: mflo        $t9
    ctx->r25 = lo;
    // 0x80088780: addu        $a3, $t9, $t2
    ctx->r7 = ADD32(ctx->r25, ctx->r10);
    // 0x80088784: jal         0x8009B028
    // 0x80088788: nop

    EGS(rdram, ctx);
        goto after_6;
    // 0x80088788: nop

    after_6:
    // 0x8008878C: multu       $v0, $fp
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088790: lw          $t6, 0x30($s2)
    ctx->r14 = S32(MEM_W(ctx->r18, 0X30));
    // 0x80088794: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80088798: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x8008879C: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800887A0: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x800887A4: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x800887A8: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800887AC: mflo        $t9
    ctx->r25 = lo;
    // 0x800887B0: addu        $v1, $s7, $t9
    ctx->r3 = ADD32(ctx->r23, ctx->r25);
    // 0x800887B4: sh          $t2, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r10;
    // 0x800887B8: bne         $at, $zero, L_800886A4
    if (ctx->r1 != 0) {
        // 0x800887BC: sb          $t3, 0x25($v1)
        MEM_B(0X25, ctx->r3) = ctx->r11;
            goto L_800886A4;
    }
    // 0x800887BC: sb          $t3, 0x25($v1)
    MEM_B(0X25, ctx->r3) = ctx->r11;
L_800887C0:
    // 0x800887C0: jal         0x80091A50
    // 0x800887C4: lh          $a0, 0x1C($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X1C));
    ksgn(rdram, ctx);
        goto after_7;
    // 0x800887C4: lh          $a0, 0x1C($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X1C));
    after_7:
    // 0x800887C8: lh          $v1, 0x1C($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0X1C));
    // 0x800887CC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800887D0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800887D4: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800887D8: mflo        $t7
    ctx->r15 = lo;
    // 0x800887DC: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800887E0: blez        $t7, L_800887F0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800887E4: negu        $t0, $v1
        ctx->r8 = SUB32(0, ctx->r3);
            goto L_800887F0;
    }
    // 0x800887E4: negu        $t0, $v1
    ctx->r8 = SUB32(0, ctx->r3);
    // 0x800887E8: b           L_800887F0
    // 0x800887EC: or          $t0, $t7, $zero
    ctx->r8 = ctx->r15 | 0;
        goto L_800887F0;
    // 0x800887EC: or          $t0, $t7, $zero
    ctx->r8 = ctx->r15 | 0;
L_800887F0:
    // 0x800887F0: lh          $v0, 0x14($s3)
    ctx->r2 = S32(MEM_H(ctx->r19, 0X14));
    // 0x800887F4: lw          $t7, 0x0($s3)
    ctx->r15 = S32(MEM_W(ctx->r19, 0X0));
    // 0x800887F8: lh          $a0, 0x10($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
    // 0x800887FC: addiu       $t8, $v0, 0x200
    ctx->r24 = ADD32(ctx->r2, 0X200);
    // 0x80088800: andi        $t9, $t8, 0x7FF
    ctx->r25 = ctx->r24 & 0X7FF;
    // 0x80088804: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x80088808: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x8008880C: lh          $t4, 0x0($t3)
    ctx->r12 = S32(MEM_H(ctx->r11, 0X0));
    // 0x80088810: andi        $t8, $v0, 0x7FF
    ctx->r24 = ctx->r2 & 0X7FF;
    // 0x80088814: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80088818: multu       $t4, $s0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008881C: addu        $t2, $s6, $t9
    ctx->r10 = ADD32(ctx->r22, ctx->r25);
    // 0x80088820: lh          $t3, 0x0($t2)
    ctx->r11 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80088824: lw          $t9, 0x8($s3)
    ctx->r25 = S32(MEM_W(ctx->r19, 0X8));
    // 0x80088828: addiu       $t2, $zero, 0x744
    ctx->r10 = ADD32(0, 0X744);
    // 0x8008882C: mflo        $t5
    ctx->r13 = lo;
    // 0x80088830: sra         $t6, $t5, 9
    ctx->r14 = S32(SIGNED(ctx->r13) >> 9);
    // 0x80088834: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80088838: multu       $t3, $s0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008883C: lw          $t6, 0x4($s3)
    ctx->r14 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80088840: addiu       $t3, $zero, -0x28
    ctx->r11 = ADD32(0, -0X28);
    // 0x80088844: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80088848: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008884C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80088850: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80088854: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80088858: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008885C: mflo        $t4
    ctx->r12 = lo;
    // 0x80088860: sra         $t5, $t4, 9
    ctx->r13 = S32(SIGNED(ctx->r12) >> 9);
    // 0x80088864: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x80088868: multu       $t0, $s0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008886C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80088870: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80088874: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x80088878: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8008887C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80088880: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80088884: mflo        $t7
    ctx->r15 = lo;
    // 0x80088888: nop

    // 0x8008888C: nop

    // 0x80088890: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088894: mflo        $t8
    ctx->r24 = lo;
    // 0x80088898: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x8008889C: jal         0x8009B028
    // 0x800888A0: nop

    EGS(rdram, ctx);
        goto after_8;
    // 0x800888A0: nop

    after_8:
    // 0x800888A4: multu       $v0, $fp
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800888A8: lw          $a0, 0x34($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X34));
    // 0x800888AC: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x800888B0: slti        $at, $a0, 0x201
    ctx->r1 = SIGNED(ctx->r4) < 0X201 ? 1 : 0;
    // 0x800888B4: mflo        $t7
    ctx->r15 = lo;
    // 0x800888B8: addu        $v1, $s7, $t7
    ctx->r3 = ADD32(ctx->r23, ctx->r15);
    // 0x800888BC: bne         $at, $zero, L_800897A4
    if (ctx->r1 != 0) {
        // 0x800888C0: sh          $t8, 0xC($v1)
        MEM_H(0XC, ctx->r3) = ctx->r24;
            goto L_800897A4;
    }
    // 0x800888C0: sh          $t8, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r24;
    // 0x800888C4: slti        $at, $a0, 0x400
    ctx->r1 = SIGNED(ctx->r4) < 0X400 ? 1 : 0;
    // 0x800888C8: beq         $at, $zero, L_800897A4
    if (ctx->r1 == 0) {
        // 0x800888CC: addiu       $t9, $zero, 0x745
        ctx->r25 = ADD32(0, 0X745);
            goto L_800897A4;
    }
    // 0x800888CC: addiu       $t9, $zero, 0x745
    ctx->r25 = ADD32(0, 0X745);
    // 0x800888D0: b           L_800897A4
    // 0x800888D4: sh          $t9, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r25;
        goto L_800897A4;
    // 0x800888D4: sh          $t9, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r25;
L_800888D8:
    // 0x800888D8: addiu       $at, $zero, 0x550
    ctx->r1 = ADD32(0, 0X550);
L_800888DC:
    // 0x800888DC: bne         $v1, $at, L_80088904
    if (ctx->r3 != ctx->r1) {
        // 0x800888E0: lui         $t2, 0x802A
        ctx->r10 = S32(0X802A << 16);
            goto L_80088904;
    }
    // 0x800888E0: lui         $t2, 0x802A
    ctx->r10 = S32(0X802A << 16);
    // 0x800888E4: lw          $t2, 0x12EC($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, 0X12EC));
    // 0x800888E8: sll         $a1, $s5, 16
    ctx->r5 = S32(ctx->r21 << 16);
    // 0x800888EC: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800888F0: bne         $t2, $zero, L_80088904
    if (ctx->r10 != 0) {
        // 0x800888F4: addiu       $a0, $zero, 0x7E
        ctx->r4 = ADD32(0, 0X7E);
            goto L_80088904;
    }
    // 0x800888F4: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    // 0x800888F8: jal         0x80059034
    // 0x800888FC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    spritesound(rdram, ctx);
        goto after_9;
    // 0x800888FC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_9:
    // 0x80088900: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
L_80088904:
    // 0x80088904: addiu       $at, $zero, 0xA2D
    ctx->r1 = ADD32(0, 0XA2D);
    // 0x80088908: bnel        $v1, $at, L_8008895C
    if (ctx->r3 != ctx->r1) {
        // 0x8008890C: lh          $s0, 0x18($s3)
        ctx->r16 = S32(MEM_H(ctx->r19, 0X18));
            goto L_8008895C;
    }
    goto skip_6;
    // 0x8008890C: lh          $s0, 0x18($s3)
    ctx->r16 = S32(MEM_H(ctx->r19, 0X18));
    skip_6:
    // 0x80088910: lh          $t4, 0x10($s3)
    ctx->r12 = S32(MEM_H(ctx->r19, 0X10));
    // 0x80088914: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x80088918: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008891C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80088920: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80088924: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x80088928: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8008892C: lh          $t6, -0x1970($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X1970));
    // 0x80088930: bnel        $t6, $at, L_8008895C
    if (ctx->r14 != ctx->r1) {
        // 0x80088934: lh          $s0, 0x18($s3)
        ctx->r16 = S32(MEM_H(ctx->r19, 0X18));
            goto L_8008895C;
    }
    goto skip_7;
    // 0x80088934: lh          $s0, 0x18($s3)
    ctx->r16 = S32(MEM_H(ctx->r19, 0X18));
    skip_7:
    // 0x80088938: lh          $s0, 0x18($s3)
    ctx->r16 = S32(MEM_H(ctx->r19, 0X18));
    // 0x8008893C: lh          $s1, 0x1C($s3)
    ctx->r17 = S32(MEM_H(ctx->r19, 0X1C));
    // 0x80088940: sra         $t7, $s0, 1
    ctx->r15 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80088944: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80088948: sra         $t2, $s1, 1
    ctx->r10 = S32(SIGNED(ctx->r17) >> 1);
    // 0x8008894C: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80088950: b           L_80088960
    // 0x80088954: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
        goto L_80088960;
    // 0x80088954: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x80088958: lh          $s0, 0x18($s3)
    ctx->r16 = S32(MEM_H(ctx->r19, 0X18));
L_8008895C:
    // 0x8008895C: lh          $s1, 0x1C($s3)
    ctx->r17 = S32(MEM_H(ctx->r19, 0X1C));
L_80088960:
    // 0x80088960: lw          $t3, 0x0($s3)
    ctx->r11 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80088964: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80088968: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8008896C: sw          $t3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r11;
    // 0x80088970: lw          $t4, 0x4($s3)
    ctx->r12 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80088974: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80088978: sw          $t4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r12;
    // 0x8008897C: lw          $t5, 0x8($s3)
    ctx->r13 = S32(MEM_W(ctx->r19, 0X8));
    // 0x80088980: jal         0x800898D0
    // 0x80088984: sw          $t5, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r13;
    getglobalz(rdram, ctx);
        goto after_10;
    // 0x80088984: sw          $t5, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r13;
    after_10:
    // 0x80088988: lh          $t7, 0xE($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0XE));
    // 0x8008898C: addiu       $at, $zero, 0xA2D
    ctx->r1 = ADD32(0, 0XA2D);
    // 0x80088990: bnel        $t7, $at, L_80088B24
    if (ctx->r15 != ctx->r1) {
        // 0x80088994: lh          $v0, 0x14($s3)
        ctx->r2 = S32(MEM_H(ctx->r19, 0X14));
            goto L_80088B24;
    }
    goto skip_8;
    // 0x80088994: lh          $v0, 0x14($s3)
    ctx->r2 = S32(MEM_H(ctx->r19, 0X14));
    skip_8:
    // 0x80088998: lh          $t8, 0x2($s2)
    ctx->r24 = S32(MEM_H(ctx->r18, 0X2));
    // 0x8008899C: addiu       $at, $zero, 0xA96
    ctx->r1 = ADD32(0, 0XA96);
    // 0x800889A0: beql        $t8, $at, L_80088A10
    if (ctx->r24 == ctx->r1) {
        // 0x800889A4: lh          $v1, 0x18($s3)
        ctx->r3 = S32(MEM_H(ctx->r19, 0X18));
            goto L_80088A10;
    }
    goto skip_9;
    // 0x800889A4: lh          $v1, 0x18($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0X18));
    skip_9:
    // 0x800889A8: lh          $t9, 0x10($s3)
    ctx->r25 = S32(MEM_H(ctx->r19, 0X10));
    // 0x800889AC: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x800889B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800889B4: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800889B8: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x800889BC: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800889C0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800889C4: lh          $t3, -0x1970($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, -0X1970));
    // 0x800889C8: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x800889CC: beql        $t3, $at, L_80088A10
    if (ctx->r11 == ctx->r1) {
        // 0x800889D0: lh          $v1, 0x18($s3)
        ctx->r3 = S32(MEM_H(ctx->r19, 0X18));
            goto L_80088A10;
    }
    goto skip_10;
    // 0x800889D0: lh          $v1, 0x18($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0X18));
    skip_10:
    // 0x800889D4: lh          $t4, -0x9DC($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, -0X9DC));
    // 0x800889D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800889DC: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x800889E0: bne         $t4, $at, L_80088A0C
    if (ctx->r12 != ctx->r1) {
        // 0x800889E4: sra         $t5, $a0, 16
        ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
            goto L_80088A0C;
    }
    // 0x800889E4: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800889E8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800889EC: jal         0x8009D240
    // 0x800889F0: addiu       $a1, $zero, 0x919
    ctx->r5 = ADD32(0, 0X919);
    spawn(rdram, ctx);
        goto after_11;
    // 0x800889F0: addiu       $a1, $zero, 0x919
    ctx->r5 = ADD32(0, 0X919);
    after_11:
    // 0x800889F4: multu       $v0, $fp
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800889F8: mflo        $t6
    ctx->r14 = lo;
    // 0x800889FC: addu        $v1, $s7, $t6
    ctx->r3 = ADD32(ctx->r23, ctx->r14);
    // 0x80088A00: lw          $t7, 0x8($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X8));
    // 0x80088A04: addiu       $t8, $t7, 0x100
    ctx->r24 = ADD32(ctx->r15, 0X100);
    // 0x80088A08: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
L_80088A0C:
    // 0x80088A0C: lh          $v1, 0x18($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0X18));
L_80088A10:
    // 0x80088A10: lh          $v0, 0x14($s3)
    ctx->r2 = S32(MEM_H(ctx->r19, 0X14));
    // 0x80088A14: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80088A18: slti        $at, $v1, 0x280
    ctx->r1 = SIGNED(ctx->r3) < 0X280 ? 1 : 0;
    // 0x80088A1C: beq         $at, $zero, L_80088AB0
    if (ctx->r1 == 0) {
        // 0x80088A20: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80088AB0;
    }
    // 0x80088A20: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80088A24: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x80088A28: beq         $v1, $at, L_80088A70
    if (ctx->r3 == ctx->r1) {
        // 0x80088A2C: lui         $v1, 0x802B
        ctx->r3 = S32(0X802B << 16);
            goto L_80088A70;
    }
    // 0x80088A2C: lui         $v1, 0x802B
    ctx->r3 = S32(0X802B << 16);
    // 0x80088A30: lw          $v1, -0x5370($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, -0X5370));
    // 0x80088A34: sll         $t9, $v1, 5
    ctx->r25 = S32(ctx->r3 << 5);
    // 0x80088A38: andi        $t2, $t9, 0x7FF
    ctx->r10 = ctx->r25 & 0X7FF;
    // 0x80088A3C: addiu       $t7, $t9, 0x200
    ctx->r15 = ADD32(ctx->r25, 0X200);
    // 0x80088A40: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80088A44: andi        $t8, $t7, 0x7FF
    ctx->r24 = ctx->r15 & 0X7FF;
    // 0x80088A48: addu        $t4, $s6, $t3
    ctx->r12 = ADD32(ctx->r22, ctx->r11);
    // 0x80088A4C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80088A50: addu        $t2, $s6, $t9
    ctx->r10 = ADD32(ctx->r22, ctx->r25);
    // 0x80088A54: lh          $t5, 0x0($t4)
    ctx->r13 = S32(MEM_H(ctx->r12, 0X0));
    // 0x80088A58: lh          $t3, 0x0($t2)
    ctx->r11 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80088A5C: sra         $t6, $t5, 9
    ctx->r14 = S32(SIGNED(ctx->r13) >> 9);
    // 0x80088A60: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x80088A64: addu        $t0, $t6, $v0
    ctx->r8 = ADD32(ctx->r14, ctx->r2);
    // 0x80088A68: b           L_80088AB0
    // 0x80088A6C: addu        $a3, $t4, $s1
    ctx->r7 = ADD32(ctx->r12, ctx->r17);
        goto L_80088AB0;
    // 0x80088A6C: addu        $a3, $t4, $s1
    ctx->r7 = ADD32(ctx->r12, ctx->r17);
L_80088A70:
    // 0x80088A70: lui         $v1, 0x802B
    ctx->r3 = S32(0X802B << 16);
    // 0x80088A74: lw          $v1, -0x5370($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, -0X5370));
    // 0x80088A78: sll         $t5, $v1, 5
    ctx->r13 = S32(ctx->r3 << 5);
    // 0x80088A7C: addiu       $t6, $t5, 0x200
    ctx->r14 = ADD32(ctx->r13, 0X200);
    // 0x80088A80: andi        $t7, $t6, 0x7FF
    ctx->r15 = ctx->r14 & 0X7FF;
    // 0x80088A84: andi        $t4, $t5, 0x7FF
    ctx->r12 = ctx->r13 & 0X7FF;
    // 0x80088A88: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80088A8C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80088A90: addu        $t9, $s6, $t8
    ctx->r25 = ADD32(ctx->r22, ctx->r24);
    // 0x80088A94: addu        $t6, $s6, $t5
    ctx->r14 = ADD32(ctx->r22, ctx->r13);
    // 0x80088A98: lh          $t2, 0x0($t9)
    ctx->r10 = S32(MEM_H(ctx->r25, 0X0));
    // 0x80088A9C: lh          $t7, 0x0($t6)
    ctx->r15 = S32(MEM_H(ctx->r14, 0X0));
    // 0x80088AA0: sra         $t3, $t2, 9
    ctx->r11 = S32(SIGNED(ctx->r10) >> 9);
    // 0x80088AA4: sra         $t8, $t7, 4
    ctx->r24 = S32(SIGNED(ctx->r15) >> 4);
    // 0x80088AA8: addu        $t0, $t3, $v0
    ctx->r8 = ADD32(ctx->r11, ctx->r2);
    // 0x80088AAC: addu        $a3, $t8, $s1
    ctx->r7 = ADD32(ctx->r24, ctx->r17);
L_80088AB0:
    // 0x80088AB0: addiu       $t2, $t0, 0x200
    ctx->r10 = ADD32(ctx->r8, 0X200);
    // 0x80088AB4: andi        $t3, $t2, 0x7FF
    ctx->r11 = ctx->r10 & 0X7FF;
    // 0x80088AB8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80088ABC: addu        $t5, $s6, $t4
    ctx->r13 = ADD32(ctx->r22, ctx->r12);
    // 0x80088AC0: lh          $t6, 0x0($t5)
    ctx->r14 = S32(MEM_H(ctx->r13, 0X0));
    // 0x80088AC4: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80088AC8: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80088ACC: multu       $t6, $s0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088AD0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80088AD4: andi        $t8, $t0, 0x7FF
    ctx->r24 = ctx->r8 & 0X7FF;
    // 0x80088AD8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80088ADC: addu        $t2, $s6, $t9
    ctx->r10 = ADD32(ctx->r22, ctx->r25);
    // 0x80088AE0: lh          $t3, 0x0($t2)
    ctx->r11 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80088AE4: lui         $t5, 0x100
    ctx->r13 = S32(0X100 << 16);
    // 0x80088AE8: ori         $t5, $t5, 0x40
    ctx->r13 = ctx->r13 | 0X40;
    // 0x80088AEC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80088AF0: mflo        $a1
    ctx->r5 = lo;
    // 0x80088AF4: sra         $t7, $a1, 14
    ctx->r15 = S32(SIGNED(ctx->r5) >> 14);
    // 0x80088AF8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80088AFC: multu       $t3, $s0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088B00: mflo        $a2
    ctx->r6 = lo;
    // 0x80088B04: sra         $t4, $a2, 14
    ctx->r12 = S32(SIGNED(ctx->r6) >> 14);
    // 0x80088B08: jal         0x80075C50
    // 0x80088B0C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    movesprite(rdram, ctx);
        goto after_12;
    // 0x80088B0C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_12:
    // 0x80088B10: sll         $s4, $v0, 16
    ctx->r20 = S32(ctx->r2 << 16);
    // 0x80088B14: sra         $t6, $s4, 16
    ctx->r14 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80088B18: b           L_80088B94
    // 0x80088B1C: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
        goto L_80088B94;
    // 0x80088B1C: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x80088B20: lh          $v0, 0x14($s3)
    ctx->r2 = S32(MEM_H(ctx->r19, 0X14));
L_80088B24:
    // 0x80088B24: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80088B28: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80088B2C: addiu       $t8, $v0, 0x200
    ctx->r24 = ADD32(ctx->r2, 0X200);
    // 0x80088B30: andi        $t9, $t8, 0x7FF
    ctx->r25 = ctx->r24 & 0X7FF;
    // 0x80088B34: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x80088B38: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x80088B3C: lh          $t4, 0x0($t3)
    ctx->r12 = S32(MEM_H(ctx->r11, 0X0));
    // 0x80088B40: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80088B44: andi        $t6, $v0, 0x7FF
    ctx->r14 = ctx->r2 & 0X7FF;
    // 0x80088B48: multu       $t4, $s0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088B4C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80088B50: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x80088B54: lh          $t9, 0x0($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X0));
    // 0x80088B58: lui         $t3, 0x100
    ctx->r11 = S32(0X100 << 16);
    // 0x80088B5C: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x80088B60: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80088B64: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80088B68: mflo        $a1
    ctx->r5 = lo;
    // 0x80088B6C: sra         $t5, $a1, 14
    ctx->r13 = S32(SIGNED(ctx->r5) >> 14);
    // 0x80088B70: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x80088B74: multu       $t9, $s0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088B78: mflo        $a2
    ctx->r6 = lo;
    // 0x80088B7C: sra         $t2, $a2, 14
    ctx->r10 = S32(SIGNED(ctx->r6) >> 14);
    // 0x80088B80: jal         0x80075C50
    // 0x80088B84: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    movesprite(rdram, ctx);
        goto after_13;
    // 0x80088B84: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_13:
    // 0x80088B88: sll         $s4, $v0, 16
    ctx->r20 = S32(ctx->r2 << 16);
    // 0x80088B8C: sra         $t4, $s4, 16
    ctx->r12 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80088B90: or          $s4, $t4, $zero
    ctx->r20 = ctx->r12 | 0;
L_80088B94:
    // 0x80088B94: lh          $t5, 0xE($s3)
    ctx->r13 = S32(MEM_H(ctx->r19, 0XE));
    // 0x80088B98: addiu       $at, $zero, 0xA2D
    ctx->r1 = ADD32(0, 0XA2D);
    // 0x80088B9C: bnel        $t5, $at, L_80088CEC
    if (ctx->r13 != ctx->r1) {
        // 0x80088BA0: lh          $a0, 0x10($s3)
        ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
            goto L_80088CEC;
    }
    goto skip_11;
    // 0x80088BA0: lh          $a0, 0x10($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
    skip_11:
    // 0x80088BA4: lh          $v0, 0x1A($s3)
    ctx->r2 = S32(MEM_H(ctx->r19, 0X1A));
    // 0x80088BA8: bltzl       $v0, L_80088CEC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80088BAC: lh          $a0, 0x10($s3)
        ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
            goto L_80088CEC;
    }
    goto skip_12;
    // 0x80088BAC: lh          $a0, 0x10($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
    skip_12:
    // 0x80088BB0: lh          $t7, 0x18($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X18));
    // 0x80088BB4: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80088BB8: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80088BBC: slti        $at, $t7, 0x280
    ctx->r1 = SIGNED(ctx->r15) < 0X280 ? 1 : 0;
    // 0x80088BC0: beq         $at, $zero, L_80088CA8
    if (ctx->r1 == 0) {
        // 0x80088BC4: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_80088CA8;
    }
    // 0x80088BC4: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80088BC8: multu       $t6, $fp
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088BCC: lw          $t2, 0x0($s3)
    ctx->r10 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80088BD0: lw          $t4, 0x4($s3)
    ctx->r12 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80088BD4: mflo        $t8
    ctx->r24 = lo;
    // 0x80088BD8: addu        $s0, $s7, $t8
    ctx->r16 = ADD32(ctx->r23, ctx->r24);
    // 0x80088BDC: lw          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80088BE0: lw          $t3, 0x4($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X4));
    // 0x80088BE4: subu        $a0, $t9, $t2
    ctx->r4 = SUB32(ctx->r25, ctx->r10);
    // 0x80088BE8: jal         0x80092024
    // 0x80088BEC: subu        $a1, $t3, $t4
    ctx->r5 = SUB32(ctx->r11, ctx->r12);
    getangle(rdram, ctx);
        goto after_14;
    // 0x80088BEC: subu        $a1, $t3, $t4
    ctx->r5 = SUB32(ctx->r11, ctx->r12);
    after_14:
    // 0x80088BF0: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x80088BF4: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80088BF8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x80088BFC: jal         0x800878E0
    // 0x80088C00: lh          $a0, 0x14($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X14));
    getanglediff(rdram, ctx);
        goto after_15;
    // 0x80088C00: lh          $a0, 0x14($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X14));
    after_15:
    // 0x80088C04: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x80088C08: bne         $at, $zero, L_80088C18
    if (ctx->r1 != 0) {
        // 0x80088C0C: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80088C18;
    }
    // 0x80088C0C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80088C10: b           L_80088C18
    // 0x80088C14: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
        goto L_80088C18;
    // 0x80088C14: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
L_80088C18:
    // 0x80088C18: slti        $at, $t0, -0x14
    ctx->r1 = SIGNED(ctx->r8) < -0X14 ? 1 : 0;
    // 0x80088C1C: beql        $at, $zero, L_80088C30
    if (ctx->r1 == 0) {
        // 0x80088C20: slti        $at, $v0, 0x15
        ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
            goto L_80088C30;
    }
    goto skip_13;
    // 0x80088C20: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    skip_13:
    // 0x80088C24: b           L_80088C44
    // 0x80088C28: addiu       $v0, $zero, -0x14
    ctx->r2 = ADD32(0, -0X14);
        goto L_80088C44;
    // 0x80088C28: addiu       $v0, $zero, -0x14
    ctx->r2 = ADD32(0, -0X14);
    // 0x80088C2C: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
L_80088C30:
    // 0x80088C30: bne         $at, $zero, L_80088C40
    if (ctx->r1 != 0) {
        // 0x80088C34: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_80088C40;
    }
    // 0x80088C34: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80088C38: b           L_80088C40
    // 0x80088C3C: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
        goto L_80088C40;
    // 0x80088C3C: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
L_80088C40:
    // 0x80088C40: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80088C44:
    // 0x80088C44: lh          $t6, 0x14($s3)
    ctx->r14 = S32(MEM_H(ctx->r19, 0X14));
    // 0x80088C48: lw          $a1, 0x8($s3)
    ctx->r5 = S32(MEM_W(ctx->r19, 0X8));
    // 0x80088C4C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80088C50: sh          $t7, 0x14($s3)
    MEM_H(0X14, ctx->r19) = ctx->r15;
    // 0x80088C54: lw          $t8, 0x8($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X8));
    // 0x80088C58: subu        $v0, $t8, $a1
    ctx->r2 = SUB32(ctx->r24, ctx->r5);
    // 0x80088C5C: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
    // 0x80088C60: slti        $at, $v0, 0x401
    ctx->r1 = SIGNED(ctx->r2) < 0X401 ? 1 : 0;
    // 0x80088C64: bne         $at, $zero, L_80088C74
    if (ctx->r1 != 0) {
        // 0x80088C68: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80088C74;
    }
    // 0x80088C68: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80088C6C: b           L_80088C74
    // 0x80088C70: addiu       $t0, $zero, 0x400
    ctx->r8 = ADD32(0, 0X400);
        goto L_80088C74;
    // 0x80088C70: addiu       $t0, $zero, 0x400
    ctx->r8 = ADD32(0, 0X400);
L_80088C74:
    // 0x80088C74: slti        $at, $t0, -0x400
    ctx->r1 = SIGNED(ctx->r8) < -0X400 ? 1 : 0;
    // 0x80088C78: beql        $at, $zero, L_80088C8C
    if (ctx->r1 == 0) {
        // 0x80088C7C: slti        $at, $v0, 0x401
        ctx->r1 = SIGNED(ctx->r2) < 0X401 ? 1 : 0;
            goto L_80088C8C;
    }
    goto skip_14;
    // 0x80088C7C: slti        $at, $v0, 0x401
    ctx->r1 = SIGNED(ctx->r2) < 0X401 ? 1 : 0;
    skip_14:
    // 0x80088C80: b           L_80088CA0
    // 0x80088C84: addiu       $v0, $zero, -0x400
    ctx->r2 = ADD32(0, -0X400);
        goto L_80088CA0;
    // 0x80088C84: addiu       $v0, $zero, -0x400
    ctx->r2 = ADD32(0, -0X400);
    // 0x80088C88: slti        $at, $v0, 0x401
    ctx->r1 = SIGNED(ctx->r2) < 0X401 ? 1 : 0;
L_80088C8C:
    // 0x80088C8C: bne         $at, $zero, L_80088C9C
    if (ctx->r1 != 0) {
        // 0x80088C90: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_80088C9C;
    }
    // 0x80088C90: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80088C94: b           L_80088C9C
    // 0x80088C98: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
        goto L_80088C9C;
    // 0x80088C98: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
L_80088C9C:
    // 0x80088C9C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80088CA0:
    // 0x80088CA0: addu        $t9, $a1, $v0
    ctx->r25 = ADD32(ctx->r5, ctx->r2);
    // 0x80088CA4: sw          $t9, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r25;
L_80088CA8:
    // 0x80088CA8: multu       $s1, $fp
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088CAC: lw          $t3, 0x0($s3)
    ctx->r11 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80088CB0: lw          $t5, 0x4($s3)
    ctx->r13 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80088CB4: mflo        $t2
    ctx->r10 = lo;
    // 0x80088CB8: addu        $s0, $s7, $t2
    ctx->r16 = ADD32(ctx->r23, ctx->r10);
    // 0x80088CBC: lw          $t4, 0x0($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80088CC0: lw          $t6, 0x4($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X4));
    // 0x80088CC4: subu        $a0, $t3, $t4
    ctx->r4 = SUB32(ctx->r11, ctx->r12);
    // 0x80088CC8: jal         0x800993E0
    // 0x80088CCC: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
    FindDistance2D(rdram, ctx);
        goto after_16;
    // 0x80088CCC: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
    after_16:
    // 0x80088CD0: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80088CD4: beql        $at, $zero, L_80088CEC
    if (ctx->r1 == 0) {
        // 0x80088CD8: lh          $a0, 0x10($s3)
        ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
            goto L_80088CEC;
    }
    goto skip_15;
    // 0x80088CD8: lh          $a0, 0x10($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
    skip_15:
    // 0x80088CDC: ori         $s4, $s1, 0xC000
    ctx->r20 = ctx->r17 | 0XC000;
    // 0x80088CE0: sll         $t7, $s4, 16
    ctx->r15 = S32(ctx->r20 << 16);
    // 0x80088CE4: sra         $s4, $t7, 16
    ctx->r20 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80088CE8: lh          $a0, 0x10($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
L_80088CEC:
    // 0x80088CEC: andi        $t2, $s4, 0xC000
    ctx->r10 = ctx->r20 & 0XC000;
    // 0x80088CF0: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x80088CF4: bgez        $a0, L_80088D14
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80088CF8: nop
    
            goto L_80088D14;
    }
    // 0x80088CF8: nop

    // 0x80088CFC: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80088D00: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80088D04: jal         0x80092728
    // 0x80088D08: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    deletesprite(rdram, ctx);
        goto after_17;
    // 0x80088D08: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_17:
    // 0x80088D0C: b           L_800897A8
    // 0x80088D10: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
        goto L_800897A8;
    // 0x80088D10: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
L_80088D14:
    // 0x80088D14: beq         $t2, $at, L_80088DC0
    if (ctx->r10 == ctx->r1) {
        // 0x80088D18: addiu       $t5, $zero, 0xF05
        ctx->r13 = ADD32(0, 0XF05);
            goto L_80088DC0;
    }
    // 0x80088D18: addiu       $t5, $zero, 0xF05
    ctx->r13 = ADD32(0, 0XF05);
    // 0x80088D1C: lw          $a1, 0x8($s3)
    ctx->r5 = S32(MEM_W(ctx->r19, 0X8));
    // 0x80088D20: lw          $t3, 0x18($s2)
    ctx->r11 = S32(MEM_W(ctx->r18, 0X18));
    // 0x80088D24: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80088D28: slt         $at, $a1, $t3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80088D2C: beql        $at, $zero, L_80088D4C
    if (ctx->r1 == 0) {
        // 0x80088D30: lw          $v1, 0x14($s2)
        ctx->r3 = S32(MEM_W(ctx->r18, 0X14));
            goto L_80088D4C;
    }
    goto skip_16;
    // 0x80088D30: lw          $v1, 0x14($s2)
    ctx->r3 = S32(MEM_W(ctx->r18, 0X14));
    skip_16:
    // 0x80088D34: ori         $s4, $a0, 0x4000
    ctx->r20 = ctx->r4 | 0X4000;
    // 0x80088D38: sll         $t4, $s4, 16
    ctx->r12 = S32(ctx->r20 << 16);
    // 0x80088D3C: sra         $s4, $t4, 16
    ctx->r20 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80088D40: b           L_80088DC0
    // 0x80088D44: sh          $t6, 0x1C($s3)
    MEM_H(0X1C, ctx->r19) = ctx->r14;
        goto L_80088DC0;
    // 0x80088D44: sh          $t6, 0x1C($s3)
    MEM_H(0X1C, ctx->r19) = ctx->r14;
    // 0x80088D48: lw          $v1, 0x14($s2)
    ctx->r3 = S32(MEM_W(ctx->r18, 0X14));
L_80088D4C:
    // 0x80088D4C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80088D50: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80088D54: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80088D58: beq         $at, $zero, L_80088D74
    if (ctx->r1 == 0) {
        // 0x80088D5C: sll         $t7, $t7, 4
        ctx->r15 = S32(ctx->r15 << 4);
            goto L_80088D74;
    }
    // 0x80088D5C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80088D60: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x80088D64: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80088D68: lh          $v0, -0x1970($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X1970));
    // 0x80088D6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80088D70: bne         $v0, $at, L_80088DA4
    if (ctx->r2 != ctx->r1) {
        // 0x80088D74: addiu       $t8, $v1, 0x1000
        ctx->r24 = ADD32(ctx->r3, 0X1000);
            goto L_80088DA4;
    }
L_80088D74:
    // 0x80088D74: addiu       $t8, $v1, 0x1000
    ctx->r24 = ADD32(ctx->r3, 0X1000);
    // 0x80088D78: slt         $at, $t8, $a1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80088D7C: beq         $at, $zero, L_80088DC0
    if (ctx->r1 == 0) {
        // 0x80088D80: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_80088DC0;
    }
    // 0x80088D80: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80088D84: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x80088D88: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80088D8C: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x80088D90: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80088D94: lh          $v0, -0x1970($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X1970));
    // 0x80088D98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80088D9C: bnel        $v0, $at, L_80088DC4
    if (ctx->r2 != ctx->r1) {
        // 0x80088DA0: lh          $v1, 0xE($s3)
        ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
            goto L_80088DC4;
    }
    goto skip_17;
    // 0x80088DA0: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
    skip_17:
L_80088DA4:
    // 0x80088DA4: ori         $s4, $a0, 0x4000
    ctx->r20 = ctx->r4 | 0X4000;
    // 0x80088DA8: sll         $t2, $s4, 16
    ctx->r10 = S32(ctx->r20 << 16);
    // 0x80088DAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80088DB0: beq         $v0, $at, L_80088DC0
    if (ctx->r2 == ctx->r1) {
        // 0x80088DB4: sra         $s4, $t2, 16
        ctx->r20 = S32(SIGNED(ctx->r10) >> 16);
            goto L_80088DC0;
    }
    // 0x80088DB4: sra         $s4, $t2, 16
    ctx->r20 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80088DB8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80088DBC: sh          $t4, 0x1C($s3)
    MEM_H(0X1C, ctx->r19) = ctx->r12;
L_80088DC0:
    // 0x80088DC0: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
L_80088DC4:
    // 0x80088DC4: addiu       $at, $zero, 0xA2D
    ctx->r1 = ADD32(0, 0XA2D);
    // 0x80088DC8: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x80088DCC: bne         $v1, $at, L_80088E30
    if (ctx->r3 != ctx->r1) {
        // 0x80088DD0: addiu       $t7, $zero, 0x20
        ctx->r15 = ADD32(0, 0X20);
            goto L_80088E30;
    }
    // 0x80088DD0: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80088DD4: lh          $a0, 0x10($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
    // 0x80088DD8: lw          $a1, 0x0($s3)
    ctx->r5 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80088DDC: lw          $a2, 0x4($s3)
    ctx->r6 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80088DE0: lw          $a3, 0x8($s3)
    ctx->r7 = S32(MEM_W(ctx->r19, 0X8));
    // 0x80088DE4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80088DE8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80088DEC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80088DF0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80088DF4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80088DF8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80088DFC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80088E00: lh          $t8, 0x16($s3)
    ctx->r24 = S32(MEM_H(ctx->r19, 0X16));
    // 0x80088E04: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80088E08: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80088E0C: jal         0x8009B028
    // 0x80088E10: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    EGS(rdram, ctx);
        goto after_18;
    // 0x80088E10: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_18:
    // 0x80088E14: multu       $v0, $fp
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088E18: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80088E1C: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    // 0x80088E20: mflo        $t3
    ctx->r11 = lo;
    // 0x80088E24: addu        $t4, $s7, $t3
    ctx->r12 = ADD32(ctx->r23, ctx->r11);
    // 0x80088E28: sh          $t2, 0xC($t4)
    MEM_H(0XC, ctx->r12) = ctx->r10;
    // 0x80088E2C: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
L_80088E30:
    // 0x80088E30: addiu       $at, $zero, 0x659
    ctx->r1 = ADD32(0, 0X659);
    // 0x80088E34: bne         $v1, $at, L_80088F58
    if (ctx->r3 != ctx->r1) {
        // 0x80088E38: addiu       $s0, $zero, -0x3
        ctx->r16 = ADD32(0, -0X3);
            goto L_80088F58;
    }
    // 0x80088E38: addiu       $s0, $zero, -0x3
    ctx->r16 = ADD32(0, -0X3);
L_80088E3C:
    // 0x80088E3C: jal         0x80091A50
    // 0x80088E40: lh          $a0, 0x1C($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X1C));
    ksgn(rdram, ctx);
        goto after_19;
    // 0x80088E40: lh          $a0, 0x1C($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X1C));
    after_19:
    // 0x80088E44: lh          $v1, 0x1C($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0X1C));
    // 0x80088E48: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80088E4C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80088E50: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80088E54: mflo        $t5
    ctx->r13 = lo;
    // 0x80088E58: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x80088E5C: blez        $t5, L_80088E6C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80088E60: negu        $t0, $v1
        ctx->r8 = SUB32(0, ctx->r3);
            goto L_80088E6C;
    }
    // 0x80088E60: negu        $t0, $v1
    ctx->r8 = SUB32(0, ctx->r3);
    // 0x80088E64: b           L_80088E6C
    // 0x80088E68: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
        goto L_80088E6C;
    // 0x80088E68: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
L_80088E6C:
    // 0x80088E6C: lh          $v0, 0x14($s3)
    ctx->r2 = S32(MEM_H(ctx->r19, 0X14));
    // 0x80088E70: lw          $t5, 0x0($s3)
    ctx->r13 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80088E74: lh          $a0, 0x10($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
    // 0x80088E78: addiu       $t6, $v0, 0x200
    ctx->r14 = ADD32(ctx->r2, 0X200);
    // 0x80088E7C: andi        $t7, $t6, 0x7FF
    ctx->r15 = ctx->r14 & 0X7FF;
    // 0x80088E80: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80088E84: addu        $t9, $s6, $t8
    ctx->r25 = ADD32(ctx->r22, ctx->r24);
    // 0x80088E88: lh          $t3, 0x0($t9)
    ctx->r11 = S32(MEM_H(ctx->r25, 0X0));
    // 0x80088E8C: andi        $t6, $v0, 0x7FF
    ctx->r14 = ctx->r2 & 0X7FF;
    // 0x80088E90: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80088E94: multu       $t3, $s0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088E98: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x80088E9C: lh          $t9, 0x0($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X0));
    // 0x80088EA0: lw          $t7, 0x8($s3)
    ctx->r15 = S32(MEM_W(ctx->r19, 0X8));
    // 0x80088EA4: addiu       $t8, $zero, 0x659
    ctx->r24 = ADD32(0, 0X659);
    // 0x80088EA8: mflo        $t2
    ctx->r10 = lo;
    // 0x80088EAC: sra         $t4, $t2, 9
    ctx->r12 = S32(SIGNED(ctx->r10) >> 9);
    // 0x80088EB0: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x80088EB4: multu       $t9, $s0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088EB8: lw          $t4, 0x4($s3)
    ctx->r12 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80088EBC: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80088EC0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80088EC4: mflo        $t3
    ctx->r11 = lo;
    // 0x80088EC8: sra         $t2, $t3, 9
    ctx->r10 = S32(SIGNED(ctx->r11) >> 9);
    // 0x80088ECC: addiu       $t3, $t9, -0x28
    ctx->r11 = ADD32(ctx->r25, -0X28);
    // 0x80088ED0: multu       $t0, $s0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088ED4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80088ED8: addu        $a2, $t2, $t4
    ctx->r6 = ADD32(ctx->r10, ctx->r12);
    // 0x80088EDC: lbu         $t2, 0x27($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X27);
    // 0x80088EE0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80088EE4: lbu         $t4, 0x28($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X28);
    // 0x80088EE8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80088EEC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80088EF0: mflo        $t5
    ctx->r13 = lo;
    // 0x80088EF4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80088EF8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80088EFC: multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088F00: lh          $t5, 0x16($s3)
    ctx->r13 = S32(MEM_H(ctx->r19, 0X16));
    // 0x80088F04: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80088F08: mflo        $t6
    ctx->r14 = lo;
    // 0x80088F0C: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x80088F10: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80088F14: jal         0x8009B028
    // 0x80088F18: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    EGS(rdram, ctx);
        goto after_20;
    // 0x80088F18: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    after_20:
    // 0x80088F1C: multu       $v0, $fp
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088F20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80088F24: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80088F28: sll         $t3, $s0, 16
    ctx->r11 = S32(ctx->r16 << 16);
    // 0x80088F2C: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    // 0x80088F30: sra         $s0, $t3, 16
    ctx->r16 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80088F34: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x80088F38: mflo        $t7
    ctx->r15 = lo;
    // 0x80088F3C: addu        $v1, $s7, $t7
    ctx->r3 = ADD32(ctx->r23, ctx->r15);
    // 0x80088F40: sh          $t8, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r24;
    // 0x80088F44: lbu         $t9, 0x25($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X25);
    // 0x80088F48: bne         $at, $zero, L_80088E3C
    if (ctx->r1 != 0) {
        // 0x80088F4C: sb          $t9, 0x25($v1)
        MEM_B(0X25, ctx->r3) = ctx->r25;
            goto L_80088E3C;
    }
    // 0x80088F4C: sb          $t9, 0x25($v1)
    MEM_B(0X25, ctx->r3) = ctx->r25;
    // 0x80088F50: b           L_80088F7C
    // 0x80088F54: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
        goto L_80088F7C;
    // 0x80088F54: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
L_80088F58:
    // 0x80088F58: addiu       $at, $zero, 0x664
    ctx->r1 = ADD32(0, 0X664);
    // 0x80088F5C: bne         $v1, $at, L_80088F7C
    if (ctx->r3 != ctx->r1) {
        // 0x80088F60: nop
    
            goto L_80088F7C;
    }
    // 0x80088F60: nop

    // 0x80088F64: lh          $v0, 0x1C($s3)
    ctx->r2 = S32(MEM_H(ctx->r19, 0X1C));
    // 0x80088F68: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x80088F6C: beq         $at, $zero, L_80088F7C
    if (ctx->r1 == 0) {
        // 0x80088F70: addiu       $t4, $v0, 0x40
        ctx->r12 = ADD32(ctx->r2, 0X40);
            goto L_80088F7C;
    }
    // 0x80088F70: addiu       $t4, $v0, 0x40
    ctx->r12 = ADD32(ctx->r2, 0X40);
    // 0x80088F74: sh          $t4, 0x1C($s3)
    MEM_H(0X1C, ctx->r19) = ctx->r12;
    // 0x80088F78: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
L_80088F7C:
    // 0x80088F7C: beq         $s4, $zero, L_800896D4
    if (ctx->r20 == 0) {
        // 0x80088F80: addiu       $at, $zero, 0x550
        ctx->r1 = ADD32(0, 0X550);
            goto L_800896D4;
    }
    // 0x80088F80: addiu       $at, $zero, 0x550
    ctx->r1 = ADD32(0, 0X550);
    // 0x80088F84: bne         $v1, $at, L_80088FD4
    if (ctx->r3 != ctx->r1) {
        // 0x80088F88: andi        $s0, $s4, 0xC000
        ctx->r16 = ctx->r20 & 0XC000;
            goto L_80088FD4;
    }
    // 0x80088F88: andi        $s0, $s4, 0xC000
    ctx->r16 = ctx->r20 & 0XC000;
    // 0x80088F8C: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x80088F90: bne         $s0, $at, L_80088FCC
    if (ctx->r16 != ctx->r1) {
        // 0x80088F94: andi        $v0, $s4, 0xFFF
        ctx->r2 = ctx->r20 & 0XFFF;
            goto L_80088FCC;
    }
    // 0x80088F94: andi        $v0, $s4, 0xFFF
    ctx->r2 = ctx->r20 & 0XFFF;
    // 0x80088F98: multu       $v0, $fp
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088F9C: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x80088FA0: mflo        $t5
    ctx->r13 = lo;
    // 0x80088FA4: addu        $t6, $s7, $t5
    ctx->r14 = ADD32(ctx->r23, ctx->r13);
    // 0x80088FA8: lh          $t7, 0xE($t6)
    ctx->r15 = S32(MEM_H(ctx->r14, 0XE));
    // 0x80088FAC: beq         $t7, $at, L_80088FCC
    if (ctx->r15 == ctx->r1) {
        // 0x80088FB0: slti        $at, $v0, 0x7D0
        ctx->r1 = SIGNED(ctx->r2) < 0X7D0 ? 1 : 0;
            goto L_80088FCC;
    }
    // 0x80088FB0: slti        $at, $v0, 0x7D0
    ctx->r1 = SIGNED(ctx->r2) < 0X7D0 ? 1 : 0;
    // 0x80088FB4: bne         $at, $zero, L_800897A4
    if (ctx->r1 != 0) {
        // 0x80088FB8: lui         $a0, 0x8010
        ctx->r4 = S32(0X8010 << 16);
            goto L_800897A4;
    }
    // 0x80088FB8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80088FBC: jal         0x80099460
    // 0x80088FC0: addiu       $a0, $a0, 0x59A0
    ctx->r4 = ADD32(ctx->r4, 0X59A0);
    gameexit(rdram, ctx);
        goto after_21;
    // 0x80088FC0: addiu       $a0, $a0, 0x59A0
    ctx->r4 = ADD32(ctx->r4, 0X59A0);
    after_21:
    // 0x80088FC4: b           L_800897A8
    // 0x80088FC8: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
        goto L_800897A8;
    // 0x80088FC8: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
L_80088FCC:
    // 0x80088FCC: sh          $zero, 0x18($s3)
    MEM_H(0X18, ctx->r19) = 0;
    // 0x80088FD0: sh          $zero, 0x1C($s3)
    MEM_H(0X1C, ctx->r19) = 0;
L_80088FD4:
    // 0x80088FD4: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x80088FD8: bne         $s0, $at, L_800891C8
    if (ctx->r16 != ctx->r1) {
        // 0x80088FDC: andi        $t8, $s4, 0xFFF
        ctx->r24 = ctx->r20 & 0XFFF;
            goto L_800891C8;
    }
    // 0x80088FDC: andi        $t8, $s4, 0xFFF
    ctx->r24 = ctx->r20 & 0XFFF;
    // 0x80088FE0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80088FE4: sra         $s4, $t9, 16
    ctx->r20 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80088FE8: slti        $at, $s4, 0x7D0
    ctx->r1 = SIGNED(ctx->r20) < 0X7D0 ? 1 : 0;
    // 0x80088FEC: bne         $at, $zero, L_80088FFC
    if (ctx->r1 != 0) {
        // 0x80088FF0: lui         $a0, 0x8010
        ctx->r4 = S32(0X8010 << 16);
            goto L_80088FFC;
    }
    // 0x80088FF0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80088FF4: jal         0x80099460
    // 0x80088FF8: addiu       $a0, $a0, 0x59C0
    ctx->r4 = ADD32(ctx->r4, 0X59C0);
    gameexit(rdram, ctx);
        goto after_22;
    // 0x80088FF8: addiu       $a0, $a0, 0x59C0
    ctx->r4 = ADD32(ctx->r4, 0X59C0);
    after_22:
L_80088FFC:
    // 0x80088FFC: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
    // 0x80089000: sll         $a1, $s5, 16
    ctx->r5 = S32(ctx->r21 << 16);
    // 0x80089004: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80089008: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8008900C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80089010: jal         0x800B177C
    // 0x80089014: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    checkhitsprite(rdram, ctx);
        goto after_23;
    // 0x80089014: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_23:
    // 0x80089018: multu       $s4, $fp
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008901C: sll         $a1, $s4, 16
    ctx->r5 = S32(ctx->r20 << 16);
    // 0x80089020: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x80089024: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80089028: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8008902C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80089030: mflo        $t5
    ctx->r13 = lo;
    // 0x80089034: addu        $v0, $s7, $t5
    ctx->r2 = ADD32(ctx->r23, ctx->r13);
    // 0x80089038: lh          $t6, 0xE($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0XE));
    // 0x8008903C: bnel        $t6, $at, L_80089384
    if (ctx->r14 != ctx->r1) {
        // 0x80089040: lh          $v1, 0xE($s3)
        ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
            goto L_80089384;
    }
    goto skip_18;
    // 0x80089040: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
    skip_18:
    // 0x80089044: jal         0x80059034
    // 0x80089048: lh          $s2, 0x1A($v0)
    ctx->r18 = S32(MEM_H(ctx->r2, 0X1A));
    spritesound(rdram, ctx);
        goto after_24;
    // 0x80089048: lh          $s2, 0x1A($v0)
    ctx->r18 = S32(MEM_H(ctx->r2, 0X1A));
    after_24:
    // 0x8008904C: lh          $t8, 0xE($s3)
    ctx->r24 = S32(MEM_H(ctx->r19, 0XE));
    // 0x80089050: addiu       $at, $zero, 0x664
    ctx->r1 = ADD32(0, 0X664);
    // 0x80089054: sll         $t9, $s2, 3
    ctx->r25 = S32(ctx->r18 << 3);
    // 0x80089058: bne         $t8, $at, L_80089380
    if (ctx->r24 != ctx->r1) {
        // 0x8008905C: subu        $t9, $t9, $s2
        ctx->r25 = SUB32(ctx->r25, ctx->r18);
            goto L_80089380;
    }
    // 0x8008905C: subu        $t9, $t9, $s2
    ctx->r25 = SUB32(ctx->r25, ctx->r18);
    // 0x80089060: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80089064: addu        $t9, $t9, $s2
    ctx->r25 = ADD32(ctx->r25, ctx->r18);
    // 0x80089068: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008906C: subu        $t9, $t9, $s2
    ctx->r25 = SUB32(ctx->r25, ctx->r18);
    // 0x80089070: lui         $t3, 0x802A
    ctx->r11 = S32(0X802A << 16);
    // 0x80089074: addiu       $t3, $t3, 0x5770
    ctx->r11 = ADD32(ctx->r11, 0X5770);
    // 0x80089078: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008907C: addu        $s0, $t9, $t3
    ctx->r16 = ADD32(ctx->r25, ctx->r11);
    // 0x80089080: lw          $t2, 0x220($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X220));
    // 0x80089084: lw          $t6, 0x210($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X210));
    // 0x80089088: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8008908C: addiu       $t4, $t2, 0x20
    ctx->r12 = ADD32(ctx->r10, 0X20);
    // 0x80089090: sw          $t4, 0x220($s0)
    MEM_W(0X220, ctx->r16) = ctx->r12;
    // 0x80089094: bne         $t6, $zero, L_80089380
    if (ctx->r14 != 0) {
        // 0x80089098: sb          $t5, 0x36C($s0)
        MEM_B(0X36C, ctx->r16) = ctx->r13;
            goto L_80089380;
    }
    // 0x80089098: sb          $t5, 0x36C($s0)
    MEM_B(0X36C, ctx->r16) = ctx->r13;
    // 0x8008909C: lui         $t7, 0x802A
    ctx->r15 = S32(0X802A << 16);
    // 0x800890A0: lw          $t7, 0x158C($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, 0X158C));
    // 0x800890A4: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    // 0x800890A8: bgtz        $t7, L_800890B8
    if (SIGNED(ctx->r15) > 0) {
        // 0x800890AC: nop
    
            goto L_800890B8;
    }
    // 0x800890AC: nop

    // 0x800890B0: jal         0x80059034
    // 0x800890B4: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    spritesound(rdram, ctx);
        goto after_25;
    // 0x800890B4: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_25:
L_800890B8:
    // 0x800890B8: jal         0x8009800C
    // 0x800890BC: nop

    krand2(rdram, ctx);
        goto after_26;
    // 0x800890BC: nop

    after_26:
    // 0x800890C0: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x800890C4: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x800890C8: sll         $s4, $v1, 16
    ctx->r20 = S32(ctx->r3 << 16);
    // 0x800890CC: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x800890D0: sra         $t8, $s4, 16
    ctx->r24 = S32(SIGNED(ctx->r20) >> 16);
    // 0x800890D4: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800890D8: addiu       $t3, $zero, 0x60
    ctx->r11 = ADD32(0, 0X60);
    // 0x800890DC: or          $s4, $t8, $zero
    ctx->r20 = ctx->r24 | 0;
    // 0x800890E0: sw          $t9, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = ctx->r25;
    // 0x800890E4: sw          $t3, 0x210($s0)
    MEM_W(0X210, ctx->r16) = ctx->r11;
    // 0x800890E8: blez        $t9, L_80089380
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800890EC: sw          $zero, 0xB0($sp)
        MEM_W(0XB0, ctx->r29) = 0;
            goto L_80089380;
    }
    // 0x800890EC: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
    // 0x800890F0: sll         $t2, $s2, 3
    ctx->r10 = S32(ctx->r18 << 3);
    // 0x800890F4: subu        $t2, $t2, $s2
    ctx->r10 = SUB32(ctx->r10, ctx->r18);
    // 0x800890F8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800890FC: addu        $t2, $t2, $s2
    ctx->r10 = ADD32(ctx->r10, ctx->r18);
    // 0x80089100: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80089104: subu        $t2, $t2, $s2
    ctx->r10 = SUB32(ctx->r10, ctx->r18);
    // 0x80089108: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x8008910C: addiu       $t4, $t4, 0x5770
    ctx->r12 = ADD32(ctx->r12, 0X5770);
    // 0x80089110: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80089114: addu        $s0, $t2, $t4
    ctx->r16 = ADD32(ctx->r10, ctx->r12);
L_80089118:
    // 0x80089118: jal         0x8009800C
    // 0x8008911C: nop

    krand2(rdram, ctx);
        goto after_27;
    // 0x8008911C: nop

    after_27:
    // 0x80089120: lui         $t5, 0x802B
    ctx->r13 = S32(0X802B << 16);
    // 0x80089124: lw          $t5, -0x5380($t5)
    ctx->r13 = S32(MEM_W(ctx->r13, -0X5380));
    // 0x80089128: lw          $s1, 0xB0($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x8008912C: div         $zero, $v0, $t5
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r13)));
    // 0x80089130: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80089134: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80089138: mfhi        $t6
    ctx->r14 = hi;
    // 0x8008913C: sw          $t6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r14;
    // 0x80089140: bne         $t5, $zero, L_8008914C
    if (ctx->r13 != 0) {
        // 0x80089144: nop
    
            goto L_8008914C;
    }
    // 0x80089144: nop

    // 0x80089148: break       7
    do_break(2148045128);
L_8008914C:
    // 0x8008914C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80089150: bne         $t5, $at, L_80089164
    if (ctx->r13 != ctx->r1) {
        // 0x80089154: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80089164;
    }
    // 0x80089154: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80089158: bne         $v0, $at, L_80089164
    if (ctx->r2 != ctx->r1) {
        // 0x8008915C: nop
    
            goto L_80089164;
    }
    // 0x8008915C: nop

    // 0x80089160: break       6
    do_break(2148045152);
L_80089164:
    // 0x80089164: jal         0x8009800C
    // 0x80089168: nop

    krand2(rdram, ctx);
        goto after_28;
    // 0x80089168: nop

    after_28:
    // 0x8008916C: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x80089170: lw          $t9, -0x537C($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, -0X537C));
    // 0x80089174: lw          $s1, 0xB0($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x80089178: div         $zero, $v0, $t9
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r25)));
    // 0x8008917C: bne         $t9, $zero, L_80089188
    if (ctx->r25 != 0) {
        // 0x80089180: nop
    
            goto L_80089188;
    }
    // 0x80089180: nop

    // 0x80089184: break       7
    do_break(2148045188);
L_80089188:
    // 0x80089188: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008918C: bne         $t9, $at, L_800891A0
    if (ctx->r25 != ctx->r1) {
        // 0x80089190: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800891A0;
    }
    // 0x80089190: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80089194: bne         $v0, $at, L_800891A0
    if (ctx->r2 != ctx->r1) {
        // 0x80089198: nop
    
            goto L_800891A0;
    }
    // 0x80089198: nop

    // 0x8008919C: break       6
    do_break(2148045212);
L_800891A0:
    // 0x800891A0: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x800891A4: addu        $t4, $s0, $t2
    ctx->r12 = ADD32(ctx->r16, ctx->r10);
    // 0x800891A8: mfhi        $t3
    ctx->r11 = hi;
    // 0x800891AC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800891B0: slt         $at, $s1, $s4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800891B4: sw          $t3, 0x10C($t4)
    MEM_W(0X10C, ctx->r12) = ctx->r11;
    // 0x800891B8: bne         $at, $zero, L_80089118
    if (ctx->r1 != 0) {
        // 0x800891BC: sw          $s1, 0xB0($sp)
        MEM_W(0XB0, ctx->r29) = ctx->r17;
            goto L_80089118;
    }
    // 0x800891BC: sw          $s1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r17;
    // 0x800891C0: b           L_80089384
    // 0x800891C4: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
        goto L_80089384;
    // 0x800891C4: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
L_800891C8:
    // 0x800891C8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800891CC: bne         $s0, $at, L_800892F8
    if (ctx->r16 != ctx->r1) {
        // 0x800891D0: andi        $t5, $s4, 0x1FFF
        ctx->r13 = ctx->r20 & 0X1FFF;
            goto L_800892F8;
    }
    // 0x800891D0: andi        $t5, $s4, 0x1FFF
    ctx->r13 = ctx->r20 & 0X1FFF;
    // 0x800891D4: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
    // 0x800891D8: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800891DC: sra         $t6, $t7, 16
    ctx->r14 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800891E0: addiu       $at, $zero, 0xA2D
    ctx->r1 = ADD32(0, 0XA2D);
    // 0x800891E4: beq         $v1, $at, L_800892A0
    if (ctx->r3 == ctx->r1) {
        // 0x800891E8: or          $s4, $t6, $zero
        ctx->r20 = ctx->r14 | 0;
            goto L_800892A0;
    }
    // 0x800891E8: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x800891EC: addiu       $at, $zero, 0xF01
    ctx->r1 = ADD32(0, 0XF01);
    // 0x800891F0: beq         $v1, $at, L_800892A0
    if (ctx->r3 == ctx->r1) {
        // 0x800891F4: addiu       $at, $zero, 0x664
        ctx->r1 = ADD32(0, 0X664);
            goto L_800892A0;
    }
    // 0x800891F4: addiu       $at, $zero, 0x664
    ctx->r1 = ADD32(0, 0X664);
    // 0x800891F8: beq         $v1, $at, L_800892A0
    if (ctx->r3 == ctx->r1) {
        // 0x800891FC: sll         $t8, $t6, 3
        ctx->r24 = S32(ctx->r14 << 3);
            goto L_800892A0;
    }
    // 0x800891FC: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x80089200: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80089204: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x80089208: addiu       $t9, $t9, 0x61A8
    ctx->r25 = ADD32(ctx->r25, 0X61A8);
    // 0x8008920C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80089210: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80089214: lh          $t2, 0x12($v0)
    ctx->r10 = S32(MEM_H(ctx->r2, 0X12));
    // 0x80089218: addiu       $at, $zero, 0x230
    ctx->r1 = ADD32(0, 0X230);
    // 0x8008921C: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80089220: beql        $t2, $at, L_8008923C
    if (ctx->r10 == ctx->r1) {
        // 0x80089224: lh          $t4, 0x8($v0)
        ctx->r12 = S32(MEM_H(ctx->r2, 0X8));
            goto L_8008923C;
    }
    goto skip_19;
    // 0x80089224: lh          $t4, 0x8($v0)
    ctx->r12 = S32(MEM_H(ctx->r2, 0X8));
    skip_19:
    // 0x80089228: lh          $t3, 0x10($v0)
    ctx->r11 = S32(MEM_H(ctx->r2, 0X10));
    // 0x8008922C: addiu       $at, $zero, 0x230
    ctx->r1 = ADD32(0, 0X230);
    // 0x80089230: bnel        $t3, $at, L_800892A4
    if (ctx->r11 != ctx->r1) {
        // 0x80089234: sll         $a0, $s5, 16
        ctx->r4 = S32(ctx->r21 << 16);
            goto L_800892A4;
    }
    goto skip_20;
    // 0x80089234: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    skip_20:
    // 0x80089238: lh          $t4, 0x8($v0)
    ctx->r12 = S32(MEM_H(ctx->r2, 0X8));
L_8008923C:
    // 0x8008923C: addiu       $t7, $t7, 0x61A8
    ctx->r15 = ADD32(ctx->r15, 0X61A8);
    // 0x80089240: lw          $t8, 0x0($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80089244: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80089248: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8008924C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80089250: addu        $v1, $t5, $t7
    ctx->r3 = ADD32(ctx->r13, ctx->r15);
    // 0x80089254: lw          $t6, 0x0($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80089258: lw          $t9, 0x4($v1)
    ctx->r25 = S32(MEM_W(ctx->r3, 0X4));
    // 0x8008925C: lw          $t2, 0x4($v0)
    ctx->r10 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80089260: subu        $a0, $t6, $t8
    ctx->r4 = SUB32(ctx->r14, ctx->r24);
    // 0x80089264: jal         0x80092024
    // 0x80089268: subu        $a1, $t9, $t2
    ctx->r5 = SUB32(ctx->r25, ctx->r10);
    getangle(rdram, ctx);
        goto after_29;
    // 0x80089268: subu        $a1, $t9, $t2
    ctx->r5 = SUB32(ctx->r25, ctx->r10);
    after_29:
    // 0x8008926C: lh          $t7, 0x14($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X14));
    // 0x80089270: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x80089274: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80089278: subu        $t6, $t5, $t7
    ctx->r14 = SUB32(ctx->r13, ctx->r15);
    // 0x8008927C: andi        $t8, $t6, 0x7FF
    ctx->r24 = ctx->r14 & 0X7FF;
    // 0x80089280: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80089284: sh          $t8, 0x14($s3)
    MEM_H(0X14, ctx->r19) = ctx->r24;
    // 0x80089288: sh          $s5, 0x16($s3)
    MEM_H(0X16, ctx->r19) = ctx->r21;
    // 0x8008928C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80089290: jal         0x8009D240
    // 0x80089294: addiu       $a1, $zero, 0x65E
    ctx->r5 = ADD32(0, 0X65E);
    spawn(rdram, ctx);
        goto after_30;
    // 0x80089294: addiu       $a1, $zero, 0x65E
    ctx->r5 = ADD32(0, 0X65E);
    after_30:
    // 0x80089298: b           L_800897A8
    // 0x8008929C: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
        goto L_800897A8;
    // 0x8008929C: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
L_800892A0:
    // 0x800892A0: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
L_800892A4:
    // 0x800892A4: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800892A8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800892AC: lw          $a1, 0xBC($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800892B0: lw          $a2, 0xB8($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800892B4: jal         0x8009219C
    // 0x800892B8: lw          $a3, 0xB4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XB4));
    setsprite(rdram, ctx);
        goto after_31;
    // 0x800892B8: lw          $a3, 0xB4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XB4));
    after_31:
    // 0x800892BC: lw          $t5, 0x8($s3)
    ctx->r13 = S32(MEM_W(ctx->r19, 0X8));
    // 0x800892C0: lw          $a2, 0x0($s3)
    ctx->r6 = S32(MEM_W(ctx->r19, 0X0));
    // 0x800892C4: lw          $a3, 0x4($s3)
    ctx->r7 = S32(MEM_W(ctx->r19, 0X4));
    // 0x800892C8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800892CC: lh          $t7, 0xE($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0XE));
    // 0x800892D0: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x800892D4: sll         $a1, $s4, 16
    ctx->r5 = S32(ctx->r20 << 16);
    // 0x800892D8: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800892DC: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800892E0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800892E4: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800892E8: jal         0x800B06B8
    // 0x800892EC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    checkhitwall(rdram, ctx);
        goto after_32;
    // 0x800892EC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_32:
    // 0x800892F0: b           L_80089384
    // 0x800892F4: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
        goto L_80089384;
    // 0x800892F4: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
L_800892F8:
    // 0x800892F8: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x800892FC: bne         $s0, $at, L_80089380
    if (ctx->r16 != ctx->r1) {
        // 0x80089300: sll         $a0, $s5, 16
        ctx->r4 = S32(ctx->r21 << 16);
            goto L_80089380;
    }
    // 0x80089300: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80089304: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80089308: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8008930C: lw          $a1, 0xBC($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x80089310: lw          $a2, 0xB8($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x80089314: jal         0x8009219C
    // 0x80089318: lw          $a3, 0xB4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XB4));
    setsprite(rdram, ctx);
        goto after_33;
    // 0x80089318: lw          $a3, 0xB4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XB4));
    after_33:
    // 0x8008931C: lh          $t8, 0x1C($s3)
    ctx->r24 = S32(MEM_H(ctx->r19, 0X1C));
    // 0x80089320: bgezl       $t8, L_80089384
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80089324: lh          $v1, 0xE($s3)
        ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
            goto L_80089384;
    }
    goto skip_21;
    // 0x80089324: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
    skip_21:
    // 0x80089328: lh          $a0, 0x10($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
    // 0x8008932C: lui         $t2, 0x8022
    ctx->r10 = S32(0X8022 << 16);
    // 0x80089330: addiu       $t2, $t2, -0x1988
    ctx->r10 = ADD32(ctx->r10, -0X1988);
    // 0x80089334: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80089338: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8008933C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80089340: addu        $v0, $t9, $t2
    ctx->r2 = ADD32(ctx->r25, ctx->r10);
    // 0x80089344: lh          $t3, 0xC($v0)
    ctx->r11 = S32(MEM_H(ctx->r2, 0XC));
    // 0x80089348: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8008934C: beq         $t4, $zero, L_80089378
    if (ctx->r12 == 0) {
        // 0x80089350: nop
    
            goto L_80089378;
    }
    // 0x80089350: nop

    // 0x80089354: lbu         $t5, 0x23($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X23);
    // 0x80089358: bne         $t5, $zero, L_80089378
    if (ctx->r13 != 0) {
        // 0x8008935C: nop
    
            goto L_80089378;
    }
    // 0x8008935C: nop

    // 0x80089360: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80089364: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80089368: jal         0x80092728
    // 0x8008936C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    deletesprite(rdram, ctx);
        goto after_34;
    // 0x8008936C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_34:
    // 0x80089370: b           L_800897A8
    // 0x80089374: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
        goto L_800897A8;
    // 0x80089374: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
L_80089378:
    // 0x80089378: jal         0x800B147C
    // 0x8008937C: nop

    checkhitceiling(rdram, ctx);
        goto after_35;
    // 0x8008937C: nop

    after_35:
L_80089380:
    // 0x80089380: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
L_80089384:
    // 0x80089384: addiu       $at, $zero, 0xA2D
    ctx->r1 = ADD32(0, 0XA2D);
    // 0x80089388: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x8008938C: bne         $v1, $at, L_80089438
    if (ctx->r3 != ctx->r1) {
        // 0x80089390: sra         $t6, $a0, 16
        ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
            goto L_80089438;
    }
    // 0x80089390: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80089394: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80089398: addiu       $a1, $zero, 0x762
    ctx->r5 = ADD32(0, 0X762);
    // 0x8008939C: jal         0x8009D240
    // 0x800893A0: andi        $s0, $s4, 0xC000
    ctx->r16 = ctx->r20 & 0XC000;
    spawn(rdram, ctx);
        goto after_36;
    // 0x800893A0: andi        $s0, $s4, 0xC000
    ctx->r16 = ctx->r20 & 0XC000;
    after_36:
    // 0x800893A4: multu       $v0, $fp
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800893A8: lw          $t9, 0xBC($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800893AC: lw          $t2, 0xB8($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800893B0: lw          $t3, 0xB4($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x800893B4: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x800893B8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800893BC: sll         $a1, $s5, 16
    ctx->r5 = S32(ctx->r21 << 16);
    // 0x800893C0: mflo        $t8
    ctx->r24 = lo;
    // 0x800893C4: addu        $v1, $s7, $t8
    ctx->r3 = ADD32(ctx->r23, ctx->r24);
    // 0x800893C8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800893CC: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800893D0: bne         $s0, $at, L_800893F8
    if (ctx->r16 != ctx->r1) {
        // 0x800893D4: sw          $t3, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r11;
            goto L_800893F8;
    }
    // 0x800893D4: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x800893D8: lh          $t4, 0x1C($s3)
    ctx->r12 = S32(MEM_H(ctx->r19, 0X1C));
    // 0x800893DC: bgtzl       $t4, L_800893FC
    if (SIGNED(ctx->r12) > 0) {
        // 0x800893E0: sra         $t9, $a1, 16
        ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
            goto L_800893FC;
    }
    goto skip_22;
    // 0x800893E0: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    skip_22:
    // 0x800893E4: lh          $t5, 0xC($v1)
    ctx->r13 = S32(MEM_H(ctx->r3, 0XC));
    // 0x800893E8: addiu       $t8, $t3, 0x3000
    ctx->r24 = ADD32(ctx->r11, 0X3000);
    // 0x800893EC: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x800893F0: ori         $t7, $t5, 0x8
    ctx->r15 = ctx->r13 | 0X8;
    // 0x800893F4: sh          $t7, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r15;
L_800893F8:
    // 0x800893F8: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
L_800893FC:
    // 0x800893FC: jal         0x80059034
    // 0x80089400: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    spritesound(rdram, ctx);
        goto after_37;
    // 0x80089400: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_37:
    // 0x80089404: lh          $t2, 0x22($s3)
    ctx->r10 = S32(MEM_H(ctx->r19, 0X22));
    // 0x80089408: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x8008940C: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80089410: sra         $a2, $t2, 2
    ctx->r6 = S32(SIGNED(ctx->r10) >> 2);
    // 0x80089414: subu        $t5, $t2, $a2
    ctx->r13 = SUB32(ctx->r10, ctx->r6);
    // 0x80089418: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008941C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80089420: addiu       $a1, $zero, 0x6F4
    ctx->r5 = ADD32(0, 0X6F4);
    // 0x80089424: sw          $t2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r10;
    // 0x80089428: sra         $a3, $t2, 1
    ctx->r7 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8008942C: jal         0x80087994
    // 0x80089430: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    hitradius(rdram, ctx);
        goto after_38;
    // 0x80089430: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_38:
    // 0x80089434: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
L_80089438:
    // 0x80089438: addiu       $at, $zero, 0x66E
    ctx->r1 = ADD32(0, 0X66E);
    // 0x8008943C: bne         $v1, $at, L_80089490
    if (ctx->r3 != ctx->r1) {
        // 0x80089440: sll         $a0, $s5, 16
        ctx->r4 = S32(ctx->r21 << 16);
            goto L_80089490;
    }
    // 0x80089440: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80089444: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80089448: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8008944C: jal         0x8009D240
    // 0x80089450: addiu       $a1, $zero, 0x678
    ctx->r5 = ADD32(0, 0X678);
    spawn(rdram, ctx);
        goto after_39;
    // 0x80089450: addiu       $a1, $zero, 0x678
    ctx->r5 = ADD32(0, 0X678);
    after_39:
    // 0x80089454: sll         $a1, $s5, 16
    ctx->r5 = S32(ctx->r21 << 16);
    // 0x80089458: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8008945C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80089460: jal         0x80059034
    // 0x80089464: addiu       $a0, $zero, 0xC5
    ctx->r4 = ADD32(0, 0XC5);
    spritesound(rdram, ctx);
        goto after_40;
    // 0x80089464: addiu       $a0, $zero, 0xC5
    ctx->r4 = ADD32(0, 0XC5);
    after_40:
    // 0x80089468: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x8008946C: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80089470: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80089474: addiu       $a1, $zero, 0x2A8
    ctx->r5 = ADD32(0, 0X2A8);
    // 0x80089478: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008947C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80089480: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80089484: jal         0x80087994
    // 0x80089488: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    hitradius(rdram, ctx);
        goto after_41;
    // 0x80089488: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_41:
    // 0x8008948C: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
L_80089490:
    // 0x80089490: addiu       $at, $zero, 0xF01
    ctx->r1 = ADD32(0, 0XF01);
    // 0x80089494: bne         $v1, $at, L_800896B4
    if (ctx->r3 != ctx->r1) {
        // 0x80089498: addiu       $t9, $zero, 0x687
        ctx->r25 = ADD32(0, 0X687);
            goto L_800896B4;
    }
    // 0x80089498: addiu       $t9, $zero, 0x687
    ctx->r25 = ADD32(0, 0X687);
    // 0x8008949C: lh          $a0, 0x10($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
    // 0x800894A0: lw          $a1, 0x0($s3)
    ctx->r5 = S32(MEM_W(ctx->r19, 0X0));
    // 0x800894A4: lw          $a2, 0x4($s3)
    ctx->r6 = S32(MEM_W(ctx->r19, 0X4));
    // 0x800894A8: lw          $a3, 0x8($s3)
    ctx->r7 = S32(MEM_W(ctx->r19, 0X8));
    // 0x800894AC: addiu       $t2, $zero, -0x7F
    ctx->r10 = ADD32(0, -0X7F);
    // 0x800894B0: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x800894B4: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x800894B8: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800894BC: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x800894C0: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800894C4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800894C8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800894CC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800894D0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800894D4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800894D8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800894DC: jal         0x8009B028
    // 0x800894E0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    EGS(rdram, ctx);
        goto after_42;
    // 0x800894E0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_42:
    // 0x800894E4: multu       $v0, $fp
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800894E8: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x800894EC: sll         $a1, $s5, 16
    ctx->r5 = S32(ctx->r21 << 16);
    // 0x800894F0: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800894F4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800894F8: mflo        $t6
    ctx->r14 = lo;
    // 0x800894FC: addu        $t8, $s7, $t6
    ctx->r24 = ADD32(ctx->r23, ctx->r14);
    // 0x80089500: sh          $t7, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r15;
    // 0x80089504: lh          $t9, 0x1A($s3)
    ctx->r25 = S32(MEM_H(ctx->r19, 0X1A));
    // 0x80089508: slti        $at, $t9, 0x59
    ctx->r1 = SIGNED(ctx->r25) < 0X59 ? 1 : 0;
    // 0x8008950C: bne         $at, $zero, L_80089630
    if (ctx->r1 != 0) {
        // 0x80089510: nop
    
            goto L_80089630;
    }
    // 0x80089510: nop

    // 0x80089514: sll         $a1, $s5, 16
    ctx->r5 = S32(ctx->r21 << 16);
    // 0x80089518: sra         $t2, $a1, 16
    ctx->r10 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8008951C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80089520: jal         0x80059034
    // 0x80089524: addiu       $a0, $zero, 0x10F
    ctx->r4 = ADD32(0, 0X10F);
    spritesound(rdram, ctx);
        goto after_43;
    // 0x80089524: addiu       $a0, $zero, 0x10F
    ctx->r4 = ADD32(0, 0X10F);
    after_43:
    // 0x80089528: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x8008952C: lh          $t3, -0x9DC($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, -0X9DC));
    // 0x80089530: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80089534: blez        $t3, L_800895E4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80089538: sll         $t5, $s2, 3
        ctx->r13 = S32(ctx->r18 << 3);
            goto L_800895E4;
    }
    // 0x80089538: sll         $t5, $s2, 3
    ctx->r13 = S32(ctx->r18 << 3);
L_8008953C:
    // 0x8008953C: subu        $t5, $t5, $s2
    ctx->r13 = SUB32(ctx->r13, ctx->r18);
    // 0x80089540: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80089544: addu        $t5, $t5, $s2
    ctx->r13 = ADD32(ctx->r13, ctx->r18);
    // 0x80089548: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008954C: subu        $t5, $t5, $s2
    ctx->r13 = SUB32(ctx->r13, ctx->r18);
    // 0x80089550: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x80089554: addiu       $t4, $t4, 0x5770
    ctx->r12 = ADD32(ctx->r12, 0X5770);
    // 0x80089558: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008955C: addu        $s0, $t5, $t4
    ctx->r16 = ADD32(ctx->r13, ctx->r12);
    // 0x80089560: lh          $t6, 0x28C($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28C));
    // 0x80089564: blez        $t6, L_800895C4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80089568: nop
    
            goto L_800895C4;
    }
    // 0x80089568: nop

    // 0x8008956C: lw          $a0, 0x0($s3)
    ctx->r4 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80089570: lw          $a1, 0x4($s3)
    ctx->r5 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80089574: lw          $a2, 0x8($s3)
    ctx->r6 = S32(MEM_W(ctx->r19, 0X8));
    // 0x80089578: lh          $a3, 0x10($s3)
    ctx->r7 = S32(MEM_H(ctx->r19, 0X10));
    // 0x8008957C: lw          $t7, 0x214($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X214));
    // 0x80089580: lw          $t8, 0x218($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X218));
    // 0x80089584: lw          $t9, 0x21C($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X21C));
    // 0x80089588: lh          $t2, 0x288($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X288));
    // 0x8008958C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80089590: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80089594: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80089598: jal         0x80092E68
    // 0x8008959C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    cansee(rdram, ctx);
        goto after_44;
    // 0x8008959C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    after_44:
    // 0x800895A0: beq         $v0, $zero, L_800895C4
    if (ctx->r2 == 0) {
        // 0x800895A4: addiu       $t3, $zero, 0x40
        ctx->r11 = ADD32(0, 0X40);
            goto L_800895C4;
    }
    // 0x800895A4: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x800895A8: addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // 0x800895AC: sb          $t3, 0x367($s0)
    MEM_B(0X367, ctx->r16) = ctx->r11;
    // 0x800895B0: sb          $v0, 0x368($s0)
    MEM_B(0X368, ctx->r16) = ctx->r2;
    // 0x800895B4: sb          $v0, 0x369($s0)
    MEM_B(0X369, ctx->r16) = ctx->r2;
    // 0x800895B8: lh          $t5, 0x1A($s3)
    ctx->r13 = S32(MEM_H(ctx->r19, 0X1A));
    // 0x800895BC: addiu       $t4, $t5, -0x20
    ctx->r12 = ADD32(ctx->r13, -0X20);
    // 0x800895C0: sw          $t4, 0x274($s0)
    MEM_W(0X274, ctx->r16) = ctx->r12;
L_800895C4:
    // 0x800895C4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800895C8: lh          $t8, -0x9DC($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X9DC));
    // 0x800895CC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800895D0: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800895D4: sra         $s2, $t6, 16
    ctx->r18 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800895D8: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800895DC: bnel        $at, $zero, L_8008953C
    if (ctx->r1 != 0) {
        // 0x800895E0: sll         $t5, $s2, 3
        ctx->r13 = S32(ctx->r18 << 3);
            goto L_8008953C;
    }
    goto skip_23;
    // 0x800895E0: sll         $t5, $s2, 3
    ctx->r13 = S32(ctx->r18 << 3);
    skip_23:
L_800895E4:
    // 0x800895E4: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x800895E8: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800895EC: sb          $t9, -0x559D($at)
    MEM_B(-0X559D, ctx->r1) = ctx->r25;
    // 0x800895F0: lw          $a2, 0x8($s3)
    ctx->r6 = S32(MEM_W(ctx->r19, 0X8));
    // 0x800895F4: lw          $a1, 0x4($s3)
    ctx->r5 = S32(MEM_W(ctx->r19, 0X4));
    // 0x800895F8: lw          $a0, 0x0($s3)
    ctx->r4 = S32(MEM_W(ctx->r19, 0X0));
    // 0x800895FC: sra         $t8, $a2, 5
    ctx->r24 = S32(SIGNED(ctx->r6) >> 5);
    // 0x80089600: sra         $t4, $a1, 1
    ctx->r12 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80089604: sra         $t2, $a0, 1
    ctx->r10 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80089608: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8008960C: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x80089610: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80089614: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80089618: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8008961C: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80089620: jal         0x80064960
    // 0x80089624: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    addexplosionmodel(rdram, ctx);
        goto after_45;
    // 0x80089624: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_45:
    // 0x80089628: b           L_80089674
    // 0x8008962C: lh          $t4, 0x22($s3)
    ctx->r12 = S32(MEM_H(ctx->r19, 0X22));
        goto L_80089674;
    // 0x8008962C: lh          $t4, 0x22($s3)
    ctx->r12 = S32(MEM_H(ctx->r19, 0X22));
L_80089630:
    // 0x80089630: jal         0x80059034
    // 0x80089634: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    spritesound(rdram, ctx);
        goto after_46;
    // 0x80089634: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_46:
    // 0x80089638: lw          $a0, 0x0($s3)
    ctx->r4 = S32(MEM_W(ctx->r19, 0X0));
    // 0x8008963C: lw          $a1, 0x4($s3)
    ctx->r5 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80089640: lw          $a2, 0x8($s3)
    ctx->r6 = S32(MEM_W(ctx->r19, 0X8));
    // 0x80089644: sra         $t5, $a0, 1
    ctx->r13 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80089648: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8008964C: sra         $t2, $a2, 5
    ctx->r10 = S32(SIGNED(ctx->r6) >> 5);
    // 0x80089650: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80089654: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80089658: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x8008965C: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80089660: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80089664: sra         $a2, $t3, 16
    ctx->r6 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80089668: jal         0x80064960
    // 0x8008966C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    addexplosionmodel(rdram, ctx);
        goto after_47;
    // 0x8008966C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_47:
    // 0x80089670: lh          $t4, 0x22($s3)
    ctx->r12 = S32(MEM_H(ctx->r19, 0X22));
L_80089674:
    // 0x80089674: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80089678: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8008967C: sw          $t4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r12;
    // 0x80089680: lh          $a1, 0x1A($s3)
    ctx->r5 = S32(MEM_H(ctx->r19, 0X1A));
    // 0x80089684: sra         $a2, $t4, 2
    ctx->r6 = S32(SIGNED(ctx->r12) >> 2);
    // 0x80089688: subu        $t9, $t4, $a2
    ctx->r25 = SUB32(ctx->r12, ctx->r6);
    // 0x8008968C: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x80089690: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x80089694: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80089698: addiu       $a1, $t7, 0x6F4
    ctx->r5 = ADD32(ctx->r15, 0X6F4);
    // 0x8008969C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800896A0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800896A4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800896A8: jal         0x80087994
    // 0x800896AC: sra         $a3, $t4, 1
    ctx->r7 = S32(SIGNED(ctx->r12) >> 1);
    hitradius(rdram, ctx);
        goto after_48;
    // 0x800896AC: sra         $a3, $t4, 1
    ctx->r7 = S32(SIGNED(ctx->r12) >> 1);
    after_48:
    // 0x800896B0: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
L_800896B4:
    // 0x800896B4: addiu       $at, $zero, 0x550
    ctx->r1 = ADD32(0, 0X550);
    // 0x800896B8: beq         $v1, $at, L_800896D4
    if (ctx->r3 == ctx->r1) {
        // 0x800896BC: sll         $a0, $s5, 16
        ctx->r4 = S32(ctx->r21 << 16);
            goto L_800896D4;
    }
    // 0x800896BC: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x800896C0: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800896C4: jal         0x80092728
    // 0x800896C8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    deletesprite(rdram, ctx);
        goto after_49;
    // 0x800896C8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_49:
    // 0x800896CC: b           L_800897A8
    // 0x800896D0: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
        goto L_800897A8;
    // 0x800896D0: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
L_800896D4:
    // 0x800896D4: addiu       $at, $zero, 0x550
    ctx->r1 = ADD32(0, 0X550);
    // 0x800896D8: bnel        $v1, $at, L_80089718
    if (ctx->r3 != ctx->r1) {
        // 0x800896DC: addiu       $at, $zero, 0xA2D
        ctx->r1 = ADD32(0, 0XA2D);
            goto L_80089718;
    }
    goto skip_24;
    // 0x800896DC: addiu       $at, $zero, 0xA2D
    ctx->r1 = ADD32(0, 0XA2D);
    skip_24:
    // 0x800896E0: lb          $t3, 0x24($s3)
    ctx->r11 = S32(MEM_B(ctx->r19, 0X24));
    // 0x800896E4: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x800896E8: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800896EC: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x800896F0: sb          $t5, 0x24($s3)
    MEM_B(0X24, ctx->r19) = ctx->r13;
    // 0x800896F4: lb          $t4, 0x24($s3)
    ctx->r12 = S32(MEM_B(ctx->r19, 0X24));
    // 0x800896F8: slti        $at, $t4, 0x28
    ctx->r1 = SIGNED(ctx->r12) < 0X28 ? 1 : 0;
    // 0x800896FC: bnel        $at, $zero, L_800897A8
    if (ctx->r1 != 0) {
        // 0x80089700: lh          $s5, 0xC8($sp)
        ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
            goto L_800897A8;
    }
    goto skip_25;
    // 0x80089700: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
    skip_25:
    // 0x80089704: jal         0x80092728
    // 0x80089708: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    deletesprite(rdram, ctx);
        goto after_50;
    // 0x80089708: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_50:
    // 0x8008970C: b           L_800897A8
    // 0x80089710: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
        goto L_800897A8;
    // 0x80089710: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
    // 0x80089714: addiu       $at, $zero, 0xA2D
    ctx->r1 = ADD32(0, 0XA2D);
L_80089718:
    // 0x80089718: bnel        $v1, $at, L_800897A8
    if (ctx->r3 != ctx->r1) {
        // 0x8008971C: lh          $s5, 0xC8($sp)
        ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
            goto L_800897A8;
    }
    goto skip_26;
    // 0x8008971C: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
    skip_26:
    // 0x80089720: lh          $t7, 0x10($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X10));
    // 0x80089724: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x80089728: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008972C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80089730: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x80089734: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80089738: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8008973C: lh          $t8, -0x1970($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X1970));
    // 0x80089740: bnel        $t8, $at, L_800897A8
    if (ctx->r24 != ctx->r1) {
        // 0x80089744: lh          $s5, 0xC8($sp)
        ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
            goto L_800897A8;
    }
    goto skip_27;
    // 0x80089744: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
    skip_27:
    // 0x80089748: jal         0x8009800C
    // 0x8008974C: nop

    krand2(rdram, ctx);
        goto after_51;
    // 0x8008974C: nop

    after_51:
    // 0x80089750: sra         $t2, $v0, 8
    ctx->r10 = S32(SIGNED(ctx->r2) >> 8);
    // 0x80089754: slti        $at, $t2, 0x73
    ctx->r1 = SIGNED(ctx->r10) < 0X73 ? 1 : 0;
    // 0x80089758: bne         $at, $zero, L_800897A4
    if (ctx->r1 != 0) {
        // 0x8008975C: sll         $a0, $s5, 16
        ctx->r4 = S32(ctx->r21 << 16);
            goto L_800897A4;
    }
    // 0x8008975C: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80089760: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80089764: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80089768: jal         0x8009D240
    // 0x8008976C: addiu       $a1, $zero, 0x295
    ctx->r5 = ADD32(0, 0X295);
    spawn(rdram, ctx);
        goto after_52;
    // 0x8008976C: addiu       $a1, $zero, 0x295
    ctx->r5 = ADD32(0, 0X295);
    after_52:
    // 0x80089770: b           L_800897A8
    // 0x80089774: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
        goto L_800897A8;
    // 0x80089774: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
L_80089778:
    // 0x80089778: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008977C: jal         0x800ACF18
    // 0x80089780: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    findplayer(rdram, ctx);
        goto after_53;
    // 0x80089780: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    after_53:
    // 0x80089784: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80089788: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8008978C: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80089790: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80089794: lw          $a2, 0xB0($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x80089798: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8008979C: jal         0x8008F488
    // 0x800897A0: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    execute(rdram, ctx);
        goto after_54;
    // 0x800897A0: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_54:
L_800897A4:
    // 0x800897A4: lh          $s5, 0xC8($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0XC8));
L_800897A8:
    // 0x800897A8: bgez        $s5, L_80088490
    if (SIGNED(ctx->r21) >= 0) {
        // 0x800897AC: nop
    
            goto L_80088490;
    }
    // 0x800897AC: nop

L_800897B0:
    // 0x800897B0: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800897B4: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800897B8: lw          $s1, 0x44($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800897BC: lw          $s2, 0x48($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800897C0: lw          $s3, 0x4C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800897C4: lw          $s4, 0x50($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800897C8: lw          $s5, 0x54($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X54));
    // 0x800897CC: lw          $s6, 0x58($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X58));
    // 0x800897D0: lw          $s7, 0x5C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800897D4: lw          $fp, 0x60($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800897D8: jr          $ra
    // 0x800897DC: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x800897DC: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_800617AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800617AC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800617B0: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x800617B4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800617B8: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800617BC: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800617C0: blez        $a0, L_800618F4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800617C4: sw          $s0, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r16;
            goto L_800618F4;
    }
    // 0x800617C4: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800617C8: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x800617CC: lui         $t3, 0x8026
    ctx->r11 = S32(0X8026 << 16);
    // 0x800617D0: lui         $t2, 0x4F0
    ctx->r10 = S32(0X4F0 << 16);
    // 0x800617D4: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x800617D8: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x800617DC: addiu       $t0, $t0, -0x2354
    ctx->r8 = ADD32(ctx->r8, -0X2354);
    // 0x800617E0: addiu       $t1, $t1, 0x4418
    ctx->r9 = ADD32(ctx->r9, 0X4418);
    // 0x800617E4: ori         $t2, $t2, 0x100
    ctx->r10 = ctx->r10 | 0X100;
    // 0x800617E8: addiu       $t3, $t3, -0x3C7C
    ctx->r11 = ADD32(ctx->r11, -0X3C7C);
    // 0x800617EC: addiu       $t5, $t5, -0x2350
    ctx->r13 = ADD32(ctx->r13, -0X2350);
    // 0x800617F0: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x800617F4: lui         $s0, 0xBF00
    ctx->r16 = S32(0XBF00 << 16);
    // 0x800617F8: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
L_800617FC:
    // 0x800617FC: lh          $t8, 0x0($t0)
    ctx->r24 = S32(MEM_H(ctx->r8, 0X0));
    // 0x80061800: bnel        $t8, $zero, L_8006182C
    if (ctx->r24 != 0) {
        // 0x80061804: lw          $v1, 0x0($t1)
        ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
            goto L_8006182C;
    }
    goto skip_0;
    // 0x80061804: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    skip_0:
    // 0x80061808: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8006180C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80061810: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80061814: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80061818: lw          $t6, 0x0($t3)
    ctx->r14 = S32(MEM_W(ctx->r11, 0X0));
    // 0x8006181C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80061820: sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
    // 0x80061824: sh          $zero, 0x0($t5)
    MEM_H(0X0, ctx->r13) = 0;
    // 0x80061828: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
L_8006182C:
    // 0x8006182C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80061830: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80061834: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80061838: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x8006183C: lh          $t8, 0x0($t5)
    ctx->r24 = S32(MEM_H(ctx->r13, 0X0));
    // 0x80061840: multu       $t8, $s1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061844: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80061848: mflo        $a2
    ctx->r6 = lo;
    // 0x8006184C: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x80061850: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80061854: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80061858: addiu       $t6, $a2, 0xA
    ctx->r14 = ADD32(ctx->r6, 0XA);
    // 0x8006185C: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x80061860: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x80061864: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80061868: addiu       $t9, $a2, 0x14
    ctx->r25 = ADD32(ctx->r6, 0X14);
    // 0x8006186C: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x80061870: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80061874: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80061878: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8006187C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80061880: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80061884: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x80061888: lh          $t6, 0x0($t5)
    ctx->r14 = S32(MEM_H(ctx->r13, 0X0));
    // 0x8006188C: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061890: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x80061894: mflo        $a2
    ctx->r6 = lo;
    // 0x80061898: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x8006189C: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800618A0: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800618A4: addiu       $t7, $a2, 0x14
    ctx->r15 = ADD32(ctx->r6, 0X14);
    // 0x800618A8: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800618AC: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x800618B0: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800618B4: addiu       $t8, $a2, 0x1E
    ctx->r24 = ADD32(ctx->r6, 0X1E);
    // 0x800618B8: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x800618BC: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x800618C0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800618C4: lh          $t8, 0x0($t5)
    ctx->r24 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800618C8: lh          $t6, 0x0($t0)
    ctx->r14 = S32(MEM_H(ctx->r8, 0X0));
    // 0x800618CC: addiu       $t7, $t8, 0x4
    ctx->r15 = ADD32(ctx->r24, 0X4);
    // 0x800618D0: lw          $t8, 0x0($t3)
    ctx->r24 = S32(MEM_W(ctx->r11, 0X0));
    // 0x800618D4: addiu       $t9, $t6, -0x4
    ctx->r25 = ADD32(ctx->r14, -0X4);
    // 0x800618D8: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800618DC: sh          $t7, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r15;
    // 0x800618E0: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800618E4: addiu       $t7, $t8, 0x40
    ctx->r15 = ADD32(ctx->r24, 0X40);
    // 0x800618E8: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x800618EC: bgtz        $a0, L_800617FC
    if (SIGNED(ctx->r4) > 0) {
        // 0x800618F0: sw          $t7, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r15;
            goto L_800617FC;
    }
    // 0x800618F0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
L_800618F4:
    // 0x800618F4: lw          $s0, 0x8($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X8));
    // 0x800618F8: lw          $s1, 0xC($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0XC));
    // 0x800618FC: jr          $ra
    // 0x80061900: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80061900: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void gametext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F68: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80063F6C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80063F70: sll         $s2, $a0, 16
    ctx->r18 = S32(ctx->r4 << 16);
    // 0x80063F74: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80063F78: sra         $s1, $s2, 16
    ctx->r17 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80063F7C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80063F80: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80063F84: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80063F88: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80063F8C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80063F90: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80063F94: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80063F98: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80063F9C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80063FA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80063FA4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80063FA8: bne         $s1, $at, L_80064074
    if (ctx->r17 != ctx->r1) {
        // 0x80063FAC: sw          $a1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r5;
            goto L_80064074;
    }
    // 0x80063FAC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80063FB0: lbu         $s0, 0x0($a2)
    ctx->r16 = MEM_BU(ctx->r6, 0X0);
    // 0x80063FB4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80063FB8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80063FBC: beq         $s0, $zero, L_80064044
    if (ctx->r16 == 0) {
        // 0x80063FC0: addiu       $s7, $zero, 0xA
        ctx->r23 = ADD32(0, 0XA);
            goto L_80064044;
    }
    // 0x80063FC0: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x80063FC4: beq         $s7, $s0, L_80064044
    if (ctx->r23 == ctx->r16) {
        // 0x80063FC8: addiu       $fp, $zero, 0xD
        ctx->r30 = ADD32(0, 0XD);
            goto L_80064044;
    }
    // 0x80063FC8: addiu       $fp, $zero, 0xD
    ctx->r30 = ADD32(0, 0XD);
    // 0x80063FCC: beq         $fp, $s0, L_80064044
    if (ctx->r30 == ctx->r16) {
        // 0x80063FD0: addiu       $s6, $zero, 0x1C
        ctx->r22 = ADD32(0, 0X1C);
            goto L_80064044;
    }
    // 0x80063FD0: addiu       $s6, $zero, 0x1C
    ctx->r22 = ADD32(0, 0X1C);
    // 0x80063FD4: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x80063FD8: addiu       $s5, $s5, -0x5010
    ctx->r21 = ADD32(ctx->r21, -0X5010);
    // 0x80063FDC: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80063FE0: addiu       $s4, $zero, 0x20
    ctx->r20 = ADD32(0, 0X20);
L_80063FE4:
    // 0x80063FE4: bne         $s4, $v0, L_80063FFC
    if (ctx->r20 != ctx->r2) {
        // 0x80063FE8: addiu       $a0, $v0, 0xAE5
        ctx->r4 = ADD32(ctx->r2, 0XAE5);
            goto L_80063FFC;
    }
    // 0x80063FE8: addiu       $a0, $v0, 0xAE5
    ctx->r4 = ADD32(ctx->r2, 0XAE5);
    // 0x80063FEC: addiu       $s2, $s2, 0x7
    ctx->r18 = ADD32(ctx->r18, 0X7);
    // 0x80063FF0: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x80063FF4: b           L_80064024
    // 0x80063FF8: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
        goto L_80064024;
    // 0x80063FF8: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
L_80063FFC:
    // 0x80063FFC: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x80064000: jal         0x8006370C
    // 0x80064004: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    gettileid(rdram, ctx);
        goto after_0;
    // 0x80064004: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x80064008: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006400C: mflo        $t0
    ctx->r8 = lo;
    // 0x80064010: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x80064014: lh          $t2, 0xC($t1)
    ctx->r10 = S32(MEM_H(ctx->r9, 0XC));
    // 0x80064018: addu        $s2, $s2, $t2
    ctx->r18 = ADD32(ctx->r18, ctx->r10);
    // 0x8006401C: sll         $t3, $s2, 16
    ctx->r11 = S32(ctx->r18 << 16);
    // 0x80064020: sra         $s2, $t3, 16
    ctx->r18 = S32(SIGNED(ctx->r11) >> 16);
L_80064024:
    // 0x80064024: lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1);
    // 0x80064028: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006402C: beq         $v0, $zero, L_80064044
    if (ctx->r2 == 0) {
        // 0x80064030: nop
    
            goto L_80064044;
    }
    // 0x80064030: nop

    // 0x80064034: beq         $s7, $v0, L_80064044
    if (ctx->r23 == ctx->r2) {
        // 0x80064038: nop
    
            goto L_80064044;
    }
    // 0x80064038: nop

    // 0x8006403C: bne         $fp, $v0, L_80063FE4
    if (ctx->r30 != ctx->r2) {
        // 0x80064040: nop
    
            goto L_80063FE4;
    }
    // 0x80064040: nop

L_80064044:
    // 0x80064044: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x80064048: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x8006404C: addiu       $s5, $s5, -0x5010
    ctx->r21 = ADD32(ctx->r21, -0X5010);
    // 0x80064050: addiu       $s4, $zero, 0x20
    ctx->r20 = ADD32(0, 0X20);
    // 0x80064054: addiu       $s6, $zero, 0x1C
    ctx->r22 = ADD32(0, 0X1C);
    // 0x80064058: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x8006405C: addiu       $fp, $zero, 0xD
    ctx->r30 = ADD32(0, 0XD);
    // 0x80064060: bgez        $s2, L_80064070
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80064064: sra         $t5, $s2, 1
        ctx->r13 = S32(SIGNED(ctx->r18) >> 1);
            goto L_80064070;
    }
    // 0x80064064: sra         $t5, $s2, 1
    ctx->r13 = S32(SIGNED(ctx->r18) >> 1);
    // 0x80064068: addiu       $at, $s2, 0x1
    ctx->r1 = ADD32(ctx->r18, 0X1);
    // 0x8006406C: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_80064070:
    // 0x80064070: subu        $s1, $t6, $t5
    ctx->r17 = SUB32(ctx->r14, ctx->r13);
L_80064074:
    // 0x80064074: lbu         $s0, 0x0($s3)
    ctx->r16 = MEM_BU(ctx->r19, 0X0);
    // 0x80064078: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x8006407C: addiu       $s5, $s5, -0x5010
    ctx->r21 = ADD32(ctx->r21, -0X5010);
    // 0x80064080: addiu       $s4, $zero, 0x20
    ctx->r20 = ADD32(0, 0X20);
    // 0x80064084: addiu       $s6, $zero, 0x1C
    ctx->r22 = ADD32(0, 0X1C);
    // 0x80064088: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x8006408C: beq         $s0, $zero, L_8006410C
    if (ctx->r16 == 0) {
        // 0x80064090: addiu       $fp, $zero, 0xD
        ctx->r30 = ADD32(0, 0XD);
            goto L_8006410C;
    }
    // 0x80064090: addiu       $fp, $zero, 0xD
    ctx->r30 = ADD32(0, 0XD);
    // 0x80064094: beql        $s7, $s0, L_80064110
    if (ctx->r23 == ctx->r16) {
        // 0x80064098: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_80064110;
    }
    goto skip_0;
    // 0x80064098: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_0:
    // 0x8006409C: beq         $fp, $s0, L_8006410C
    if (ctx->r30 == ctx->r16) {
        // 0x800640A0: addiu       $a2, $s0, 0xAE5
        ctx->r6 = ADD32(ctx->r16, 0XAE5);
            goto L_8006410C;
    }
    // 0x800640A0: addiu       $a2, $s0, 0xAE5
    ctx->r6 = ADD32(ctx->r16, 0XAE5);
L_800640A4:
    // 0x800640A4: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x800640A8: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800640AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800640B0: jal         0x80065A64
    // 0x800640B4: lh          $a1, 0x46($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X46));
    rotatesprite_simple(rdram, ctx);
        goto after_1;
    // 0x800640B4: lh          $a1, 0x46($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X46));
    after_1:
    // 0x800640B8: lbu         $s0, 0x0($s3)
    ctx->r16 = MEM_BU(ctx->r19, 0X0);
    // 0x800640BC: bne         $s4, $s0, L_800640CC
    if (ctx->r20 != ctx->r16) {
        // 0x800640C0: addiu       $a0, $s0, 0xAE5
        ctx->r4 = ADD32(ctx->r16, 0XAE5);
            goto L_800640CC;
    }
    // 0x800640C0: addiu       $a0, $s0, 0xAE5
    ctx->r4 = ADD32(ctx->r16, 0XAE5);
    // 0x800640C4: b           L_800640EC
    // 0x800640C8: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
        goto L_800640EC;
    // 0x800640C8: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
L_800640CC:
    // 0x800640CC: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x800640D0: jal         0x8006370C
    // 0x800640D4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    gettileid(rdram, ctx);
        goto after_2;
    // 0x800640D4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_2:
    // 0x800640D8: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800640DC: mflo        $t9
    ctx->r25 = lo;
    // 0x800640E0: addu        $t0, $s5, $t9
    ctx->r8 = ADD32(ctx->r21, ctx->r25);
    // 0x800640E4: lh          $t1, 0xC($t0)
    ctx->r9 = S32(MEM_H(ctx->r8, 0XC));
    // 0x800640E8: addu        $s1, $s1, $t1
    ctx->r17 = ADD32(ctx->r17, ctx->r9);
L_800640EC:
    // 0x800640EC: lbu         $s0, 0x1($s3)
    ctx->r16 = MEM_BU(ctx->r19, 0X1);
    // 0x800640F0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800640F4: beql        $s0, $zero, L_80064110
    if (ctx->r16 == 0) {
        // 0x800640F8: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_80064110;
    }
    goto skip_1;
    // 0x800640F8: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_1:
    // 0x800640FC: beql        $s7, $s0, L_80064110
    if (ctx->r23 == ctx->r16) {
        // 0x80064100: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_80064110;
    }
    goto skip_2;
    // 0x80064100: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_2:
    // 0x80064104: bnel        $fp, $s0, L_800640A4
    if (ctx->r30 != ctx->r16) {
        // 0x80064108: addiu       $a2, $s0, 0xAE5
        ctx->r6 = ADD32(ctx->r16, 0XAE5);
            goto L_800640A4;
    }
    goto skip_3;
    // 0x80064108: addiu       $a2, $s0, 0xAE5
    ctx->r6 = ADD32(ctx->r16, 0XAE5);
    skip_3:
L_8006410C:
    // 0x8006410C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_80064110:
    // 0x80064110: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80064114: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80064118: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8006411C: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80064120: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80064124: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80064128: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8006412C: lw          $s7, 0x34($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80064130: lw          $fp, 0x38($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80064134: jr          $ra
    // 0x80064138: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80064138: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800705C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800705C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800705CC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800705D0: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    // 0x800705D4: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800705D8: beq         $t6, $zero, L_8007060C
    if (ctx->r14 == 0) {
        // 0x800705DC: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_8007060C;
    }
    // 0x800705DC: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800705E0: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
L_800705E4:
    // 0x800705E4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800705E8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800705EC: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x800705F0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800705F4: sh          $v1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r3;
    // 0x800705F8: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800705FC: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x80070600: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80070604: bne         $v0, $zero, L_800705E4
    if (ctx->r2 != 0) {
        // 0x80070608: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800705E4;
    }
    // 0x80070608: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_8007060C:
    // 0x8007060C: jr          $ra
    // 0x80070610: nop

    return;
    // 0x80070610: nop

;}
RECOMP_FUNC void findotherplayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD108: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800AD10C: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x800AD110: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800AD114: lui         $a2, 0x802B
    ctx->r6 = S32(0X802B << 16);
    // 0x800AD118: lw          $a2, -0x540C($a2)
    ctx->r6 = S32(MEM_W(ctx->r6, -0X540C));
    // 0x800AD11C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800AD120: sll         $a3, $a0, 16
    ctx->r7 = S32(ctx->r4 << 16);
    // 0x800AD124: lui         $v1, 0x7FFF
    ctx->r3 = S32(0X7FFF << 16);
    // 0x800AD128: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800AD12C: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x800AD130: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x800AD134: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800AD138: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x800AD13C: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x800AD140: blez        $a2, L_800AD230
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800AD144: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800AD230;
    }
    // 0x800AD144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AD148: lui         $s0, 0x802A
    ctx->r16 = S32(0X802A << 16);
    // 0x800AD14C: lui         $t5, 0x8024
    ctx->r13 = S32(0X8024 << 16);
    // 0x800AD150: addiu       $t5, $t5, 0x6BA8
    ctx->r13 = ADD32(ctx->r13, 0X6BA8);
    // 0x800AD154: addiu       $s0, $s0, 0x5770
    ctx->r16 = ADD32(ctx->r16, 0X5770);
    // 0x800AD158: addiu       $s2, $zero, 0x2C
    ctx->r18 = ADD32(0, 0X2C);
    // 0x800AD15C: addiu       $s1, $zero, 0x38C
    ctx->r17 = ADD32(0, 0X38C);
L_800AD160:
    // 0x800AD160: beql        $a0, $v0, L_800AD21C
    if (ctx->r4 == ctx->r2) {
        // 0x800AD164: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800AD21C;
    }
    goto skip_0;
    // 0x800AD164: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800AD168: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AD16C: mflo        $t9
    ctx->r25 = lo;
    // 0x800AD170: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x800AD174: lh          $t6, 0x2E0($t0)
    ctx->r14 = S32(MEM_H(ctx->r8, 0X2E0));
    // 0x800AD178: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AD17C: mflo        $t7
    ctx->r15 = lo;
    // 0x800AD180: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800AD184: lh          $t9, 0x22($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X22));
    // 0x800AD188: blezl       $t9, L_800AD21C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800AD18C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800AD21C;
    }
    goto skip_1;
    // 0x800AD18C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x800AD190: multu       $a0, $s1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AD194: lw          $t7, 0x23C($t0)
    ctx->r15 = S32(MEM_W(ctx->r8, 0X23C));
    // 0x800AD198: mflo        $t6
    ctx->r14 = lo;
    // 0x800AD19C: addu        $t1, $s0, $t6
    ctx->r9 = ADD32(ctx->r16, ctx->r14);
    // 0x800AD1A0: lw          $t8, 0x218($t1)
    ctx->r24 = S32(MEM_W(ctx->r9, 0X218));
    // 0x800AD1A4: lw          $t3, 0x214($t1)
    ctx->r11 = S32(MEM_W(ctx->r9, 0X214));
    // 0x800AD1A8: lw          $t4, 0x21C($t1)
    ctx->r12 = S32(MEM_W(ctx->r9, 0X21C));
    // 0x800AD1AC: subu        $t2, $t7, $t8
    ctx->r10 = SUB32(ctx->r15, ctx->r24);
    // 0x800AD1B0: blez        $t2, L_800AD1C0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800AD1B4: negu        $t1, $t2
        ctx->r9 = SUB32(0, ctx->r10);
            goto L_800AD1C0;
    }
    // 0x800AD1B4: negu        $t1, $t2
    ctx->r9 = SUB32(0, ctx->r10);
    // 0x800AD1B8: b           L_800AD1C0
    // 0x800AD1BC: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_800AD1C0;
    // 0x800AD1BC: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
L_800AD1C0:
    // 0x800AD1C0: lw          $t9, 0x238($t0)
    ctx->r25 = S32(MEM_W(ctx->r8, 0X238));
    // 0x800AD1C4: subu        $t2, $t9, $t3
    ctx->r10 = SUB32(ctx->r25, ctx->r11);
    // 0x800AD1C8: blez        $t2, L_800AD1D8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800AD1CC: negu        $t3, $t2
        ctx->r11 = SUB32(0, ctx->r10);
            goto L_800AD1D8;
    }
    // 0x800AD1CC: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x800AD1D0: b           L_800AD1D8
    // 0x800AD1D4: or          $t3, $t2, $zero
    ctx->r11 = ctx->r10 | 0;
        goto L_800AD1D8;
    // 0x800AD1D4: or          $t3, $t2, $zero
    ctx->r11 = ctx->r10 | 0;
L_800AD1D8:
    // 0x800AD1D8: lw          $t6, 0x240($t0)
    ctx->r14 = S32(MEM_W(ctx->r8, 0X240));
    // 0x800AD1DC: subu        $t2, $t6, $t4
    ctx->r10 = SUB32(ctx->r14, ctx->r12);
    // 0x800AD1E0: blez        $t2, L_800AD1F0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800AD1E4: negu        $t0, $t2
        ctx->r8 = SUB32(0, ctx->r10);
            goto L_800AD1F0;
    }
    // 0x800AD1E4: negu        $t0, $t2
    ctx->r8 = SUB32(0, ctx->r10);
    // 0x800AD1E8: b           L_800AD1F0
    // 0x800AD1EC: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
        goto L_800AD1F0;
    // 0x800AD1EC: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
L_800AD1F0:
    // 0x800AD1F0: sra         $t7, $t0, 4
    ctx->r15 = S32(SIGNED(ctx->r8) >> 4);
    // 0x800AD1F4: addu        $t8, $t7, $t3
    ctx->r24 = ADD32(ctx->r15, ctx->r11);
    // 0x800AD1F8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800AD1FC: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AD200: beql        $at, $zero, L_800AD21C
    if (ctx->r1 == 0) {
        // 0x800AD204: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800AD21C;
    }
    goto skip_2;
    // 0x800AD204: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x800AD208: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x800AD20C: sra         $t9, $a3, 16
    ctx->r25 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800AD210: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800AD214: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x800AD218: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800AD21C:
    // 0x800AD21C: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800AD220: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800AD224: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800AD228: bne         $at, $zero, L_800AD160
    if (ctx->r1 != 0) {
        // 0x800AD22C: nop
    
            goto L_800AD160;
    }
    // 0x800AD22C: nop

L_800AD230:
    // 0x800AD230: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x800AD234: lw          $s2, 0xC($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0XC));
    // 0x800AD238: lw          $s1, 0x8($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X8));
    // 0x800AD23C: lw          $s0, 0x4($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X4));
    // 0x800AD240: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800AD244: jr          $ra
    // 0x800AD248: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800AD248: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
;}
RECOMP_FUNC void computergetinput(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5724: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x800B5728: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800B572C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800B5730: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800B5734: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800B5738: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800B573C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800B5740: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800B5744: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800B5748: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800B574C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800B5750: sw          $a0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r4;
    // 0x800B5754: sw          $a1, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r5;
    // 0x800B5758: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x800B575C: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x800B5760: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x800B5764: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x800B5768: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800B576C: lw          $t7, 0x138($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X138));
    // 0x800B5770: lui         $fp, 0x802A
    ctx->r30 = S32(0X802A << 16);
    // 0x800B5774: addiu       $fp, $fp, 0x5770
    ctx->r30 = ADD32(ctx->r30, 0X5770);
    // 0x800B5778: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800B577C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B5780: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800B5784: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B5788: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B578C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B5790: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B5794: addu        $t9, $fp, $t8
    ctx->r25 = ADD32(ctx->r30, ctx->r24);
    // 0x800B5798: sw          $t9, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r25;
    // 0x800B579C: lh          $t7, 0x2C6($t9)
    ctx->r15 = S32(MEM_H(ctx->r25, 0X2C6));
    // 0x800B57A0: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x800B57A4: beql        $at, $zero, L_800B57BC
    if (ctx->r1 == 0) {
        // 0x800B57A8: lw          $t5, 0xA8($sp)
        ctx->r13 = S32(MEM_W(ctx->r29, 0XA8));
            goto L_800B57BC;
    }
    goto skip_0;
    // 0x800B57A8: lw          $t5, 0xA8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XA8));
    skip_0:
    // 0x800B57AC: lw          $t8, 0x8($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X8));
    // 0x800B57B0: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x800B57B4: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // 0x800B57B8: lw          $t5, 0xA8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XA8));
L_800B57BC:
    // 0x800B57BC: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x800B57C0: addiu       $t9, $t9, 0x6BA8
    ctx->r25 = ADD32(ctx->r25, 0X6BA8);
    // 0x800B57C4: lh          $t7, 0x2E0($t5)
    ctx->r15 = S32(MEM_H(ctx->r13, 0X2E0));
    // 0x800B57C8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B57CC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B57D0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B57D4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B57D8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B57DC: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800B57E0: lw          $t5, 0x4($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X4));
    // 0x800B57E4: lh          $t8, 0x14($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X14));
    // 0x800B57E8: lw          $t7, 0x8($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X8));
    // 0x800B57EC: sw          $t5, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r13;
    // 0x800B57F0: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800B57F4: lw          $t5, 0x138($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X138));
    // 0x800B57F8: sw          $t8, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r24;
    // 0x800B57FC: lui         $t8, 0x8028
    ctx->r24 = S32(0X8028 << 16);
    // 0x800B5800: sw          $t7, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r15;
    // 0x800B5804: addiu       $t8, $t8, -0x6830
    ctx->r24 = ADD32(ctx->r24, -0X6830);
    // 0x800B5808: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x800B580C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800B5810: lh          $t6, 0x10($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X10));
    // 0x800B5814: addu        $s6, $t7, $t8
    ctx->r22 = ADD32(ctx->r15, ctx->r24);
    // 0x800B5818: lw          $a0, 0x0($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X0));
    // 0x800B581C: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x800B5820: sw          $t7, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r15;
    // 0x800B5824: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800B5828: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800B582C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800B5830: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800B5834: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B5838: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800B583C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B5840: addu        $t7, $fp, $t6
    ctx->r15 = ADD32(ctx->r30, ctx->r14);
    // 0x800B5844: lh          $s4, 0x2E0($t7)
    ctx->r20 = S32(MEM_H(ctx->r15, 0X2E0));
    // 0x800B5848: lw          $a2, 0x11C($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X11C));
    // 0x800B584C: lw          $a1, 0x120($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X120));
    // 0x800B5850: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x800B5854: subu        $t8, $t8, $s4
    ctx->r24 = SUB32(ctx->r24, ctx->r20);
    // 0x800B5858: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B585C: subu        $t8, $t8, $s4
    ctx->r24 = SUB32(ctx->r24, ctx->r20);
    // 0x800B5860: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B5864: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800B5868: lw          $t1, 0x0($t0)
    ctx->r9 = S32(MEM_W(ctx->r8, 0X0));
    // 0x800B586C: lw          $t2, 0x4($t0)
    ctx->r10 = S32(MEM_W(ctx->r8, 0X4));
    // 0x800B5870: beq         $t5, $a0, L_800B58AC
    if (ctx->r13 == ctx->r4) {
        // 0x800B5874: lw          $v1, 0x8($t0)
        ctx->r3 = S32(MEM_W(ctx->r8, 0X8));
            goto L_800B58AC;
    }
    // 0x800B5874: lw          $v1, 0x8($t0)
    ctx->r3 = S32(MEM_W(ctx->r8, 0X8));
    // 0x800B5878: lh          $t7, 0x10($t0)
    ctx->r15 = S32(MEM_H(ctx->r8, 0X10));
    // 0x800B587C: addiu       $t6, $v1, -0x3000
    ctx->r14 = ADD32(ctx->r3, -0X3000);
    // 0x800B5880: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800B5884: lw          $a0, 0x124($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X124));
    // 0x800B5888: addiu       $a2, $a2, -0x3000
    ctx->r6 = ADD32(ctx->r6, -0X3000);
    // 0x800B588C: lh          $a3, 0xE6($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XE6));
    // 0x800B5890: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800B5894: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800B5898: jal         0x80092E68
    // 0x800B589C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    cansee(rdram, ctx);
        goto after_0;
    // 0x800B589C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x800B58A0: bne         $v0, $zero, L_800B58AC
    if (ctx->r2 != 0) {
        // 0x800B58A4: lw          $t8, 0x138($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0X138));
            goto L_800B58AC;
    }
    // 0x800B58A4: lw          $t8, 0x138($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X138));
    // 0x800B58A8: sw          $t8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r24;
L_800B58AC:
    // 0x800B58AC: lw          $a0, 0x0($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X0));
    // 0x800B58B0: lw          $t9, 0x138($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X138));
    // 0x800B58B4: addiu       $a1, $sp, 0x130
    ctx->r5 = ADD32(ctx->r29, 0X130);
    // 0x800B58B8: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x800B58BC: beq         $t9, $a0, L_800B58E8
    if (ctx->r25 == ctx->r4) {
        // 0x800B58C0: subu        $t5, $t5, $a0
        ctx->r13 = SUB32(ctx->r13, ctx->r4);
            goto L_800B58E8;
    }
    // 0x800B58C0: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800B58C4: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800B58C8: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x800B58CC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B58D0: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800B58D4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B58D8: addu        $v1, $fp, $t5
    ctx->r3 = ADD32(ctx->r30, ctx->r13);
    // 0x800B58DC: lh          $t6, 0x31A($v1)
    ctx->r14 = S32(MEM_H(ctx->r3, 0X31A));
    // 0x800B58E0: beql        $t6, $zero, L_800B5918
    if (ctx->r14 == 0) {
        // 0x800B58E4: lh          $t9, 0x2E0($v1)
        ctx->r25 = S32(MEM_H(ctx->r3, 0X2E0));
            goto L_800B5918;
    }
    goto skip_1;
    // 0x800B58E4: lh          $t9, 0x2E0($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0X2E0));
    skip_1:
L_800B58E8:
    // 0x800B58E8: jal         0x800AD108
    // 0x800B58EC: lh          $a0, 0x13A($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X13A));
    findotherplayer(rdram, ctx);
        goto after_1;
    // 0x800B58EC: lh          $a0, 0x13A($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X13A));
    after_1:
    // 0x800B58F0: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x800B58F4: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800B58F8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800B58FC: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800B5900: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B5904: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800B5908: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B590C: addu        $v1, $fp, $t8
    ctx->r3 = ADD32(ctx->r30, ctx->r24);
    // 0x800B5910: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // 0x800B5914: lh          $t9, 0x2E0($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0X2E0));
L_800B5918:
    // 0x800B5918: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x800B591C: addiu       $t6, $t6, 0x6BA8
    ctx->r14 = ADD32(ctx->r14, 0X6BA8);
    // 0x800B5920: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800B5924: subu        $t5, $t5, $t9
    ctx->r13 = SUB32(ctx->r13, ctx->r25);
    // 0x800B5928: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B592C: subu        $t5, $t5, $t9
    ctx->r13 = SUB32(ctx->r13, ctx->r25);
    // 0x800B5930: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B5934: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x800B5938: lw          $t7, 0x0($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800B593C: lw          $t8, 0x4($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X4));
    // 0x800B5940: lw          $t9, 0xA8($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800B5944: sw          $t7, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r15;
    // 0x800B5948: sw          $t8, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r24;
    // 0x800B594C: lh          $t5, 0x31A($t9)
    ctx->r13 = S32(MEM_H(ctx->r25, 0X31A));
    // 0x800B5950: lw          $s4, 0x8($v0)
    ctx->r20 = S32(MEM_W(ctx->r2, 0X8));
    // 0x800B5954: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800B5958: beql        $t5, $zero, L_800B599C
    if (ctx->r13 == 0) {
        // 0x800B595C: lw          $t9, 0xA8($sp)
        ctx->r25 = S32(MEM_W(ctx->r29, 0XA8));
            goto L_800B599C;
    }
    goto skip_2;
    // 0x800B595C: lw          $t9, 0xA8($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XA8));
    skip_2:
    // 0x800B5960: lbu         $t6, 0x378C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X378C);
    // 0x800B5964: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x800B5968: beql        $s6, $t6, L_800B7668
    if (ctx->r22 == ctx->r14) {
        // 0x800B596C: lw          $ra, 0x64($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
            goto L_800B7668;
    }
    goto skip_3;
    // 0x800B596C: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
    skip_3:
    // 0x800B5970: lh          $t7, 0x2CE($t9)
    ctx->r15 = S32(MEM_H(ctx->r25, 0X2CE));
    // 0x800B5974: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800B5978: lw          $t8, 0x13C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800B597C: bnel        $t7, $at, L_800B7668
    if (ctx->r15 != ctx->r1) {
        // 0x800B5980: lw          $ra, 0x64($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
            goto L_800B7668;
    }
    goto skip_4;
    // 0x800B5980: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
    skip_4:
    // 0x800B5984: lw          $t5, 0x8($t8)
    ctx->r13 = S32(MEM_W(ctx->r24, 0X8));
    // 0x800B5988: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x800B598C: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800B5990: b           L_800B7664
    // 0x800B5994: sw          $t6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r14;
        goto L_800B7664;
    // 0x800B5994: sw          $t6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r14;
    // 0x800B5998: lw          $t9, 0xA8($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XA8));
L_800B599C:
    // 0x800B599C: lh          $t7, 0x2DA($t9)
    ctx->r15 = S32(MEM_H(ctx->r25, 0X2DA));
    // 0x800B59A0: blezl       $t7, L_800B59F8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800B59A4: lw          $t7, 0x0($s6)
        ctx->r15 = S32(MEM_W(ctx->r22, 0X0));
            goto L_800B59F8;
    }
    goto skip_5;
    // 0x800B59A4: lw          $t7, 0x0($s6)
    ctx->r15 = S32(MEM_W(ctx->r22, 0X0));
    skip_5:
    // 0x800B59A8: lh          $t5, 0x28C($t9)
    ctx->r13 = S32(MEM_H(ctx->r25, 0X28C));
    // 0x800B59AC: lui         $t6, 0x802B
    ctx->r14 = S32(0X802B << 16);
    // 0x800B59B0: slti        $at, $t5, 0x64
    ctx->r1 = SIGNED(ctx->r13) < 0X64 ? 1 : 0;
    // 0x800B59B4: beql        $at, $zero, L_800B59F8
    if (ctx->r1 == 0) {
        // 0x800B59B8: lw          $t7, 0x0($s6)
        ctx->r15 = S32(MEM_W(ctx->r22, 0X0));
            goto L_800B59F8;
    }
    goto skip_6;
    // 0x800B59B8: lw          $t7, 0x0($s6)
    ctx->r15 = S32(MEM_W(ctx->r22, 0X0));
    skip_6:
    // 0x800B59BC: lw          $t6, -0x5408($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, -0X5408));
    // 0x800B59C0: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x800B59C4: sllv        $s0, $t8, $t6
    ctx->r16 = S32(ctx->r24 << (ctx->r14 & 31));
    // 0x800B59C8: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x800B59CC: jal         0x8009800C
    // 0x800B59D0: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    krand2(rdram, ctx);
        goto after_2;
    // 0x800B59D0: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    after_2:
    // 0x800B59D4: andi        $t5, $v0, 0xFF
    ctx->r13 = ctx->r2 & 0XFF;
    // 0x800B59D8: slt         $at, $t5, $s0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800B59DC: beq         $at, $zero, L_800B59F4
    if (ctx->r1 == 0) {
        // 0x800B59E0: lw          $v0, 0x13C($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0X13C));
            goto L_800B59F4;
    }
    // 0x800B59E0: lw          $v0, 0x13C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800B59E4: lw          $t8, 0x8($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X8));
    // 0x800B59E8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B59EC: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800B59F0: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
L_800B59F4:
    // 0x800B59F4: lw          $t7, 0x0($s6)
    ctx->r15 = S32(MEM_W(ctx->r22, 0X0));
L_800B59F8:
    // 0x800B59F8: lw          $a2, 0x11C($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X11C));
    // 0x800B59FC: lw          $a0, 0x124($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X124));
    // 0x800B5A00: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x800B5A04: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800B5A08: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800B5A0C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800B5A10: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B5A14: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800B5A18: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B5A1C: addu        $v1, $fp, $t9
    ctx->r3 = ADD32(ctx->r30, ctx->r25);
    // 0x800B5A20: lh          $t5, 0x31A($v1)
    ctx->r13 = S32(MEM_H(ctx->r3, 0X31A));
    // 0x800B5A24: lw          $a1, 0x120($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X120));
    // 0x800B5A28: lh          $s1, 0xE6($sp)
    ctx->r17 = S32(MEM_H(ctx->r29, 0XE6));
    // 0x800B5A2C: bne         $t5, $zero, L_800B6218
    if (ctx->r13 != 0) {
        // 0x800B5A30: addiu       $a2, $a2, -0x3000
        ctx->r6 = ADD32(ctx->r6, -0X3000);
            goto L_800B6218;
    }
    // 0x800B5A30: addiu       $a2, $a2, -0x3000
    ctx->r6 = ADD32(ctx->r6, -0X3000);
    // 0x800B5A34: lh          $t5, 0x2E0($v1)
    ctx->r13 = S32(MEM_H(ctx->r3, 0X2E0));
    // 0x800B5A38: sll         $a3, $s1, 16
    ctx->r7 = S32(ctx->r17 << 16);
    // 0x800B5A3C: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800B5A40: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x800B5A44: lw          $t6, 0x118($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X118));
    // 0x800B5A48: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x800B5A4C: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x800B5A50: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B5A54: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x800B5A58: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800B5A5C: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x800B5A60: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B5A64: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x800B5A68: lh          $t6, 0x6BB8($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, 0X6BB8));
    // 0x800B5A6C: lw          $t7, 0x114($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X114));
    // 0x800B5A70: addiu       $t9, $s4, -0x3000
    ctx->r25 = ADD32(ctx->r20, -0X3000);
    // 0x800B5A74: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800B5A78: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800B5A7C: jal         0x80092E68
    // 0x800B5A80: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    cansee(rdram, ctx);
        goto after_3;
    // 0x800B5A80: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_3:
    // 0x800B5A84: beq         $v0, $zero, L_800B6218
    if (ctx->r2 == 0) {
        // 0x800B5A88: lui         $t7, 0x802B
        ctx->r15 = S32(0X802B << 16);
            goto L_800B6218;
    }
    // 0x800B5A88: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x800B5A8C: lw          $t7, -0x5408($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X5408));
    // 0x800B5A90: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x800B5A94: sllv        $s0, $t9, $t7
    ctx->r16 = S32(ctx->r25 << (ctx->r15 & 31));
    // 0x800B5A98: sll         $t5, $s0, 16
    ctx->r13 = S32(ctx->r16 << 16);
    // 0x800B5A9C: jal         0x8009800C
    // 0x800B5AA0: sra         $s0, $t5, 16
    ctx->r16 = S32(SIGNED(ctx->r13) >> 16);
    krand2(rdram, ctx);
        goto after_4;
    // 0x800B5AA0: sra         $s0, $t5, 16
    ctx->r16 = S32(SIGNED(ctx->r13) >> 16);
    after_4:
    // 0x800B5AA4: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x800B5AA8: slt         $at, $t6, $s0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800B5AAC: beql        $at, $zero, L_800B5AC8
    if (ctx->r1 == 0) {
        // 0x800B5AB0: lw          $t0, 0xA8($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0XA8));
            goto L_800B5AC8;
    }
    goto skip_7;
    // 0x800B5AB0: lw          $t0, 0xA8($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA8));
    skip_7:
    // 0x800B5AB4: lw          $t9, 0x13C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800B5AB8: lw          $t7, 0x8($t9)
    ctx->r15 = S32(MEM_W(ctx->r25, 0X8));
    // 0x800B5ABC: ori         $t5, $t7, 0x4
    ctx->r13 = ctx->r15 | 0X4;
    // 0x800B5AC0: sw          $t5, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r13;
    // 0x800B5AC4: lw          $t0, 0xA8($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA8));
L_800B5AC8:
    // 0x800B5AC8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800B5ACC: lh          $t8, 0x2B2($t0)
    ctx->r24 = S32(MEM_H(ctx->r8, 0X2B2));
    // 0x800B5AD0: bnel        $t8, $at, L_800B5B00
    if (ctx->r24 != ctx->r1) {
        // 0x800B5AD4: lw          $t0, 0xA8($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0XA8));
            goto L_800B5B00;
    }
    goto skip_8;
    // 0x800B5AD4: lw          $t0, 0xA8($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA8));
    skip_8:
    // 0x800B5AD8: jal         0x8009800C
    // 0x800B5ADC: nop

    krand2(rdram, ctx);
        goto after_5;
    // 0x800B5ADC: nop

    after_5:
    // 0x800B5AE0: andi        $t6, $v0, 0x7
    ctx->r14 = ctx->r2 & 0X7;
    // 0x800B5AE4: bne         $t6, $zero, L_800B5AFC
    if (ctx->r14 != 0) {
        // 0x800B5AE8: lw          $v0, 0x13C($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0X13C));
            goto L_800B5AFC;
    }
    // 0x800B5AE8: lw          $v0, 0x13C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800B5AEC: lw          $t7, 0x8($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X8));
    // 0x800B5AF0: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800B5AF4: and         $t5, $t7, $at
    ctx->r13 = ctx->r15 & ctx->r1;
    // 0x800B5AF8: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
L_800B5AFC:
    // 0x800B5AFC: lw          $t0, 0xA8($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA8));
L_800B5B00:
    // 0x800B5B00: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800B5B04: lh          $v0, 0x2B2($t0)
    ctx->r2 = S32(MEM_H(ctx->r8, 0X2B2));
    // 0x800B5B08: bnel        $v0, $at, L_800B5B28
    if (ctx->r2 != ctx->r1) {
        // 0x800B5B0C: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800B5B28;
    }
    goto skip_9;
    // 0x800B5B0C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_9:
    // 0x800B5B10: lw          $t9, 0x13C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800B5B14: lw          $t8, 0x8($t9)
    ctx->r24 = S32(MEM_W(ctx->r25, 0X8));
    // 0x800B5B18: ori         $t6, $t8, 0xC00
    ctx->r14 = ctx->r24 | 0XC00;
    // 0x800B5B1C: sw          $t6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r14;
    // 0x800B5B20: lh          $v0, 0x2B2($t0)
    ctx->r2 = S32(MEM_H(ctx->r8, 0X2B2));
    // 0x800B5B24: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_800B5B28:
    // 0x800B5B28: bnel        $v0, $at, L_800B5C3C
    if (ctx->r2 != ctx->r1) {
        // 0x800B5B2C: lw          $t0, 0xA8($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0XA8));
            goto L_800B5C3C;
    }
    goto skip_10;
    // 0x800B5B2C: lw          $t0, 0xA8($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA8));
    skip_10:
    // 0x800B5B30: lw          $t5, 0xE8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XE8));
    // 0x800B5B34: sll         $a3, $s1, 16
    ctx->r7 = S32(ctx->r17 << 16);
    // 0x800B5B38: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x800B5B3C: addiu       $t8, $t5, 0x200
    ctx->r24 = ADD32(ctx->r13, 0X200);
    // 0x800B5B40: andi        $t6, $t8, 0x7FF
    ctx->r14 = ctx->r24 & 0X7FF;
    // 0x800B5B44: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800B5B48: addiu       $v0, $v0, -0x9A0
    ctx->r2 = ADD32(ctx->r2, -0X9A0);
    // 0x800B5B4C: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800B5B50: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800B5B54: addu        $t7, $v0, $t9
    ctx->r15 = ADD32(ctx->r2, ctx->r25);
    // 0x800B5B58: lh          $t8, 0x0($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800B5B5C: andi        $t6, $t5, 0x7FF
    ctx->r14 = ctx->r13 & 0X7FF;
    // 0x800B5B60: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800B5B64: addu        $t7, $v0, $t9
    ctx->r15 = ADD32(ctx->r2, ctx->r25);
    // 0x800B5B68: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800B5B6C: lh          $t8, 0x0($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800B5B70: lw          $a2, 0x11C($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X11C));
    // 0x800B5B74: addiu       $s0, $sp, 0xCA
    ctx->r16 = ADD32(ctx->r29, 0XCA);
    // 0x800B5B78: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800B5B7C: lh          $t9, 0x2B8($t0)
    ctx->r25 = S32(MEM_H(ctx->r8, 0X2B8));
    // 0x800B5B80: lw          $t5, 0x220($t0)
    ctx->r13 = S32(MEM_W(ctx->r8, 0X220));
    // 0x800B5B84: addiu       $s2, $sp, 0x10C
    ctx->r18 = ADD32(ctx->r29, 0X10C);
    // 0x800B5B88: addiu       $s3, $sp, 0x108
    ctx->r19 = ADD32(ctx->r29, 0X108);
    // 0x800B5B8C: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x800B5B90: subu        $t7, $t6, $t9
    ctx->r15 = SUB32(ctx->r14, ctx->r25);
    // 0x800B5B94: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x800B5B98: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x800B5B9C: addiu       $s5, $sp, 0x104
    ctx->r21 = ADD32(ctx->r29, 0X104);
    // 0x800B5BA0: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x800B5BA4: addiu       $t5, $t8, 0xC80
    ctx->r13 = ADD32(ctx->r24, 0XC80);
    // 0x800B5BA8: addiu       $t9, $sp, 0xC6
    ctx->r25 = ADD32(ctx->r29, 0XC6);
    // 0x800B5BAC: addiu       $t6, $sp, 0xC8
    ctx->r14 = ADD32(ctx->r29, 0XC8);
    // 0x800B5BB0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800B5BB4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800B5BB8: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800B5BBC: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800B5BC0: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800B5BC4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800B5BC8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800B5BCC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B5BD0: lw          $a0, 0x124($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X124));
    // 0x800B5BD4: lw          $a1, 0x120($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X120));
    // 0x800B5BD8: jal         0x8009324C
    // 0x800B5BDC: addiu       $a2, $a2, -0x2600
    ctx->r6 = ADD32(ctx->r6, -0X2600);
    hitscan(rdram, ctx);
        goto after_6;
    // 0x800B5BDC: addiu       $a2, $a2, -0x2600
    ctx->r6 = ADD32(ctx->r6, -0X2600);
    after_6:
    // 0x800B5BE0: lw          $t1, 0x10C($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X10C));
    // 0x800B5BE4: lw          $t8, 0x124($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X124));
    // 0x800B5BE8: lw          $t2, 0x108($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X108));
    // 0x800B5BEC: lw          $t5, 0x120($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X120));
    // 0x800B5BF0: subu        $a0, $t1, $t8
    ctx->r4 = SUB32(ctx->r9, ctx->r24);
    // 0x800B5BF4: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B5BF8: subu        $a2, $t2, $t5
    ctx->r6 = SUB32(ctx->r10, ctx->r13);
    // 0x800B5BFC: lui         $at, 0x64
    ctx->r1 = S32(0X64 << 16);
    // 0x800B5C00: mflo        $t6
    ctx->r14 = lo;
    // 0x800B5C04: nop

    // 0x800B5C08: nop

    // 0x800B5C0C: multu       $a2, $a2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B5C10: mflo        $t9
    ctx->r25 = lo;
    // 0x800B5C14: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x800B5C18: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800B5C1C: beql        $at, $zero, L_800B5C3C
    if (ctx->r1 == 0) {
        // 0x800B5C20: lw          $t0, 0xA8($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0XA8));
            goto L_800B5C3C;
    }
    goto skip_11;
    // 0x800B5C20: lw          $t0, 0xA8($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA8));
    skip_11:
    // 0x800B5C24: lw          $v0, 0x13C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800B5C28: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800B5C2C: lw          $t8, 0x8($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X8));
    // 0x800B5C30: and         $t5, $t8, $at
    ctx->r13 = ctx->r24 & ctx->r1;
    // 0x800B5C34: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x800B5C38: lw          $t0, 0xA8($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA8));
L_800B5C3C:
    // 0x800B5C3C: lhu         $v1, 0x2B2($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X2B2);
    // 0x800B5C40: addiu       $t6, $v1, -0x4
    ctx->r14 = ADD32(ctx->r3, -0X4);
    // 0x800B5C44: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x800B5C48: beq         $at, $zero, L_800B5C88
    if (ctx->r1 == 0) {
        // 0x800B5C4C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800B5C88;
    }
    // 0x800B5C4C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B5C50: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800B5C54: addu        $at, $at, $t6
    gpr jr_addend_800B5C5C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B5C58: lw          $t6, -0x6D4C($at)
    ctx->r14 = ADD32(ctx->r1, -0X6D4C);
    // 0x800B5C5C: jr          $t6
    // 0x800B5C60: nop

    switch (jr_addend_800B5C5C >> 2) {
        case 0: goto L_800B5C64; break;
        case 1: goto L_800B5C88; break;
        case 2: goto L_800B5C88; break;
        case 3: goto L_800B5C84; break;
        case 4: goto L_800B5C88; break;
        case 5: goto L_800B5C6C; break;
        case 6: goto L_800B5C74; break;
        case 7: goto L_800B5C7C; break;
        default: switch_error(__func__, 0x800B5C5C, 0x801092B4);
    }
    // 0x800B5C60: nop

L_800B5C64:
    // 0x800B5C64: b           L_800B5C88
    // 0x800B5C68: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
        goto L_800B5C88;
    // 0x800B5C68: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
L_800B5C6C:
    // 0x800B5C6C: b           L_800B5C88
    // 0x800B5C70: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
        goto L_800B5C88;
    // 0x800B5C70: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_800B5C74:
    // 0x800B5C74: b           L_800B5C88
    // 0x800B5C78: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
        goto L_800B5C88;
    // 0x800B5C78: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_800B5C7C:
    // 0x800B5C7C: b           L_800B5C88
    // 0x800B5C80: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
        goto L_800B5C88;
    // 0x800B5C80: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_800B5C84:
    // 0x800B5C84: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
L_800B5C88:
    // 0x800B5C88: lw          $t9, 0x0($s6)
    ctx->r25 = S32(MEM_W(ctx->r22, 0X0));
    // 0x800B5C8C: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x800B5C90: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x800B5C94: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800B5C98: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x800B5C9C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B5CA0: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x800B5CA4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B5CA8: addu        $t8, $fp, $t7
    ctx->r24 = ADD32(ctx->r30, ctx->r15);
    // 0x800B5CAC: lhu         $v0, 0x2B2($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X2B2);
    // 0x800B5CB0: addiu       $t5, $v0, -0x4
    ctx->r13 = ADD32(ctx->r2, -0X4);
    // 0x800B5CB4: sltiu       $at, $t5, 0x8
    ctx->r1 = ctx->r13 < 0X8 ? 1 : 0;
    // 0x800B5CB8: beq         $at, $zero, L_800B5CF8
    if (ctx->r1 == 0) {
        // 0x800B5CBC: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_800B5CF8;
    }
    // 0x800B5CBC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B5CC0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800B5CC4: addu        $at, $at, $t5
    gpr jr_addend_800B5CCC = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800B5CC8: lw          $t5, -0x6D2C($at)
    ctx->r13 = ADD32(ctx->r1, -0X6D2C);
    // 0x800B5CCC: jr          $t5
    // 0x800B5CD0: nop

    switch (jr_addend_800B5CCC >> 2) {
        case 0: goto L_800B5CD4; break;
        case 1: goto L_800B5CF8; break;
        case 2: goto L_800B5CF8; break;
        case 3: goto L_800B5CF4; break;
        case 4: goto L_800B5CF8; break;
        case 5: goto L_800B5CDC; break;
        case 6: goto L_800B5CE4; break;
        case 7: goto L_800B5CEC; break;
        default: switch_error(__func__, 0x800B5CCC, 0x801092D4);
    }
    // 0x800B5CD0: nop

L_800B5CD4:
    // 0x800B5CD4: b           L_800B5CF8
    // 0x800B5CD8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_800B5CF8;
    // 0x800B5CD8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800B5CDC:
    // 0x800B5CDC: b           L_800B5CF8
    // 0x800B5CE0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_800B5CF8;
    // 0x800B5CE0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800B5CE4:
    // 0x800B5CE4: b           L_800B5CF8
    // 0x800B5CE8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_800B5CF8;
    // 0x800B5CE8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_800B5CEC:
    // 0x800B5CEC: b           L_800B5CF8
    // 0x800B5CF0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_800B5CF8;
    // 0x800B5CF0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800B5CF4:
    // 0x800B5CF4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_800B5CF8:
    // 0x800B5CF8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800B5CFC: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x800B5D00: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800B5D04: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800B5D08: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x800B5D0C: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x800B5D10: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x800B5D14: lw          $s0, 0x1060($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X1060));
    // 0x800B5D18: lw          $t8, 0x118($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X118));
    // 0x800B5D1C: lw          $t5, 0x124($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X124));
    // 0x800B5D20: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x800B5D24: beq         $at, $zero, L_800B5D30
    if (ctx->r1 == 0) {
        // 0x800B5D28: subu        $s1, $t8, $t5
        ctx->r17 = SUB32(ctx->r24, ctx->r13);
            goto L_800B5D30;
    }
    // 0x800B5D28: subu        $s1, $t8, $t5
    ctx->r17 = SUB32(ctx->r24, ctx->r13);
    // 0x800B5D2C: addiu       $s0, $zero, 0x80
    ctx->r16 = ADD32(0, 0X80);
L_800B5D30:
    // 0x800B5D30: multu       $s1, $s1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B5D34: lw          $t6, 0x114($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X114));
    // 0x800B5D38: lw          $t9, 0x120($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X120));
    // 0x800B5D3C: subu        $s2, $t6, $t9
    ctx->r18 = SUB32(ctx->r14, ctx->r25);
    // 0x800B5D40: mflo        $t7
    ctx->r15 = lo;
    // 0x800B5D44: nop

    // 0x800B5D48: nop

    // 0x800B5D4C: multu       $s2, $s2
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B5D50: mflo        $t8
    ctx->r24 = lo;
    // 0x800B5D54: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800B5D58: jal         0x80092164
    // 0x800B5D5C: nop

    ksqrt(rdram, ctx);
        goto after_7;
    // 0x800B5D5C: nop

    after_7:
    // 0x800B5D60: bne         $v0, $zero, L_800B5D6C
    if (ctx->r2 != 0) {
        // 0x800B5D64: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800B5D6C;
    }
    // 0x800B5D64: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800B5D68: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_800B5D6C:
    // 0x800B5D6C: lw          $t5, 0x0($s6)
    ctx->r13 = S32(MEM_W(ctx->r22, 0X0));
    // 0x800B5D70: lw          $t8, 0x118($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X118));
    // 0x800B5D74: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800B5D78: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800B5D7C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800B5D80: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800B5D84: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B5D88: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800B5D8C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B5D90: addu        $v1, $fp, $t6
    ctx->r3 = ADD32(ctx->r30, ctx->r14);
    // 0x800B5D94: lw          $t9, 0x24C($v1)
    ctx->r25 = S32(MEM_W(ctx->r3, 0X24C));
    // 0x800B5D98: lw          $t6, 0x124($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X124));
    // 0x800B5D9C: sra         $t7, $t9, 14
    ctx->r15 = S32(SIGNED(ctx->r25) >> 14);
    // 0x800B5DA0: lw          $t9, 0x250($v1)
    ctx->r25 = S32(MEM_W(ctx->r3, 0X250));
    // 0x800B5DA4: addu        $t5, $t7, $t8
    ctx->r13 = ADD32(ctx->r15, ctx->r24);
    // 0x800B5DA8: lw          $t8, 0x114($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X114));
    // 0x800B5DAC: subu        $a0, $t5, $t6
    ctx->r4 = SUB32(ctx->r13, ctx->r14);
    // 0x800B5DB0: lw          $t6, 0x120($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X120));
    // 0x800B5DB4: sra         $t7, $t9, 14
    ctx->r15 = S32(SIGNED(ctx->r25) >> 14);
    // 0x800B5DB8: addu        $t5, $t7, $t8
    ctx->r13 = ADD32(ctx->r15, ctx->r24);
    // 0x800B5DBC: jal         0x80092024
    // 0x800B5DC0: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
    getangle(rdram, ctx);
        goto after_8;
    // 0x800B5DC0: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
    after_8:
    // 0x800B5DC4: lw          $t9, 0x11C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X11C));
    // 0x800B5DC8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800B5DCC: subu        $s7, $s4, $t9
    ctx->r23 = SUB32(ctx->r20, ctx->r25);
    // 0x800B5DD0: jal         0x80091A38
    // 0x800B5DD4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    klabs(rdram, ctx);
        goto after_9;
    // 0x800B5DD4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_9:
    // 0x800B5DD8: sra         $t7, $v0, 4
    ctx->r15 = S32(SIGNED(ctx->r2) >> 4);
    // 0x800B5DDC: slt         $at, $t7, $s0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800B5DE0: bnel        $at, $zero, L_800B5DF8
    if (ctx->r1 != 0) {
        // 0x800B5DE4: lw          $t8, 0x0($s6)
        ctx->r24 = S32(MEM_W(ctx->r22, 0X0));
            goto L_800B5DF8;
    }
    goto skip_12;
    // 0x800B5DE4: lw          $t8, 0x0($s6)
    ctx->r24 = S32(MEM_W(ctx->r22, 0X0));
    skip_12:
    // 0x800B5DE8: jal         0x80091A38
    // 0x800B5DEC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    klabs(rdram, ctx);
        goto after_10;
    // 0x800B5DEC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_10:
    // 0x800B5DF0: sra         $s0, $v0, 4
    ctx->r16 = S32(SIGNED(ctx->r2) >> 4);
    // 0x800B5DF4: lw          $t8, 0x0($s6)
    ctx->r24 = S32(MEM_W(ctx->r22, 0X0));
L_800B5DF8:
    // 0x800B5DF8: addiu       $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
    // 0x800B5DFC: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x800B5E00: sll         $t5, $t8, 3
    ctx->r13 = S32(ctx->r24 << 3);
    // 0x800B5E04: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x800B5E08: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800B5E0C: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x800B5E10: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B5E14: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x800B5E18: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B5E1C: addu        $t6, $fp, $t5
    ctx->r14 = ADD32(ctx->r30, ctx->r13);
    // 0x800B5E20: lh          $t9, 0x2E0($t6)
    ctx->r25 = S32(MEM_H(ctx->r14, 0X2E0));
    // 0x800B5E24: addiu       $a3, $a3, 0x6BA8
    ctx->r7 = ADD32(ctx->r7, 0X6BA8);
    // 0x800B5E28: lw          $a2, 0x13C($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800B5E2C: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B5E30: mflo        $t7
    ctx->r15 = lo;
    // 0x800B5E34: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x800B5E38: lbu         $t5, 0x28($t8)
    ctx->r13 = MEM_BU(ctx->r24, 0X28);
    // 0x800B5E3C: slti        $at, $t5, 0x20
    ctx->r1 = SIGNED(ctx->r13) < 0X20 ? 1 : 0;
    // 0x800B5E40: beql        $at, $zero, L_800B5E60
    if (ctx->r1 == 0) {
        // 0x800B5E44: lw          $v0, 0x124($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0X124));
            goto L_800B5E60;
    }
    goto skip_13;
    // 0x800B5E44: lw          $v0, 0x124($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X124));
    skip_13:
    // 0x800B5E48: lw          $t6, 0x8($a2)
    ctx->r14 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800B5E4C: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800B5E50: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800B5E54: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x800B5E58: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x800B5E5C: lw          $v0, 0x124($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X124));
L_800B5E60:
    // 0x800B5E60: lw          $t7, 0x118($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X118));
    // 0x800B5E64: lw          $a1, 0x120($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X120));
    // 0x800B5E68: lw          $t9, 0x114($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X114));
    // 0x800B5E6C: subu        $v1, $v0, $t7
    ctx->r3 = SUB32(ctx->r2, ctx->r15);
    // 0x800B5E70: multu       $v1, $s0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B5E74: subu        $a0, $a1, $t9
    ctx->r4 = SUB32(ctx->r5, ctx->r25);
    // 0x800B5E78: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x800B5E7C: lw          $a2, 0x13C($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800B5E80: mflo        $t8
    ctx->r24 = lo;
    // 0x800B5E84: nop

    // 0x800B5E88: nop

    // 0x800B5E8C: div         $zero, $t8, $s5
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r21)));
    // 0x800B5E90: mflo        $t5
    ctx->r13 = lo;
    // 0x800B5E94: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x800B5E98: bne         $s5, $zero, L_800B5EA4
    if (ctx->r21 != 0) {
        // 0x800B5E9C: nop
    
            goto L_800B5EA4;
    }
    // 0x800B5E9C: nop

    // 0x800B5EA0: break       7
    do_break(2148228768);
L_800B5EA4:
    // 0x800B5EA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B5EA8: bne         $s5, $at, L_800B5EBC
    if (ctx->r21 != ctx->r1) {
        // 0x800B5EAC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B5EBC;
    }
    // 0x800B5EAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B5EB0: bne         $t8, $at, L_800B5EBC
    if (ctx->r24 != ctx->r1) {
        // 0x800B5EB4: nop
    
            goto L_800B5EBC;
    }
    // 0x800B5EB4: nop

    // 0x800B5EB8: break       6
    do_break(2148228792);
L_800B5EBC:
    // 0x800B5EBC: multu       $a0, $s0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B5EC0: sw          $t6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r14;
    // 0x800B5EC4: mflo        $t8
    ctx->r24 = lo;
    // 0x800B5EC8: nop

    // 0x800B5ECC: nop

    // 0x800B5ED0: div         $zero, $t8, $s5
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r21)));
    // 0x800B5ED4: mflo        $t5
    ctx->r13 = lo;
    // 0x800B5ED8: addu        $t7, $t5, $t9
    ctx->r15 = ADD32(ctx->r13, ctx->r25);
    // 0x800B5EDC: bne         $s5, $zero, L_800B5EE8
    if (ctx->r21 != 0) {
        // 0x800B5EE0: nop
    
            goto L_800B5EE8;
    }
    // 0x800B5EE0: nop

    // 0x800B5EE4: break       7
    do_break(2148228836);
L_800B5EE8:
    // 0x800B5EE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B5EEC: bne         $s5, $at, L_800B5F00
    if (ctx->r21 != ctx->r1) {
        // 0x800B5EF0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B5F00;
    }
    // 0x800B5EF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B5EF4: bne         $t8, $at, L_800B5F00
    if (ctx->r24 != ctx->r1) {
        // 0x800B5EF8: nop
    
            goto L_800B5F00;
    }
    // 0x800B5EF8: nop

    // 0x800B5EFC: break       6
    do_break(2148228860);
L_800B5F00:
    // 0x800B5F00: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x800B5F04: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B5F08: sw          $t7, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r15;
    // 0x800B5F0C: lh          $t7, 0x2($a2)
    ctx->r15 = S32(MEM_H(ctx->r6, 0X2));
    // 0x800B5F10: lh          $t8, 0x4($a2)
    ctx->r24 = S32(MEM_H(ctx->r6, 0X4));
    // 0x800B5F14: mflo        $t5
    ctx->r13 = lo;
    // 0x800B5F18: nop

    // 0x800B5F1C: nop

    // 0x800B5F20: div         $zero, $t5, $s5
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r21)));
    // 0x800B5F24: mflo        $t9
    ctx->r25 = lo;
    // 0x800B5F28: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800B5F2C: bne         $s5, $zero, L_800B5F38
    if (ctx->r21 != 0) {
        // 0x800B5F30: nop
    
            goto L_800B5F38;
    }
    // 0x800B5F30: nop

    // 0x800B5F34: break       7
    do_break(2148228916);
L_800B5F38:
    // 0x800B5F38: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B5F3C: bne         $s5, $at, L_800B5F50
    if (ctx->r21 != ctx->r1) {
        // 0x800B5F40: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B5F50;
    }
    // 0x800B5F40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B5F44: bne         $t5, $at, L_800B5F50
    if (ctx->r13 != ctx->r1) {
        // 0x800B5F48: nop
    
            goto L_800B5F50;
    }
    // 0x800B5F48: nop

    // 0x800B5F4C: break       6
    do_break(2148228940);
L_800B5F50:
    // 0x800B5F50: sh          $t6, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r14;
    // 0x800B5F54: lw          $t5, 0x108($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X108));
    // 0x800B5F58: subu        $t7, $t5, $a1
    ctx->r15 = SUB32(ctx->r13, ctx->r5);
    // 0x800B5F5C: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B5F60: mflo        $t9
    ctx->r25 = lo;
    // 0x800B5F64: nop

    // 0x800B5F68: nop

    // 0x800B5F6C: div         $zero, $t9, $s5
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r21)));
    // 0x800B5F70: mflo        $t6
    ctx->r14 = lo;
    // 0x800B5F74: addu        $t5, $t8, $t6
    ctx->r13 = ADD32(ctx->r24, ctx->r14);
    // 0x800B5F78: bne         $s5, $zero, L_800B5F84
    if (ctx->r21 != 0) {
        // 0x800B5F7C: nop
    
            goto L_800B5F84;
    }
    // 0x800B5F7C: nop

    // 0x800B5F80: break       7
    do_break(2148228992);
L_800B5F84:
    // 0x800B5F84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B5F88: bne         $s5, $at, L_800B5F9C
    if (ctx->r21 != ctx->r1) {
        // 0x800B5F8C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B5F9C;
    }
    // 0x800B5F8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B5F90: bne         $t9, $at, L_800B5F9C
    if (ctx->r25 != ctx->r1) {
        // 0x800B5F94: nop
    
            goto L_800B5F9C;
    }
    // 0x800B5F94: nop

    // 0x800B5F98: break       6
    do_break(2148229016);
L_800B5F9C:
    // 0x800B5F9C: sh          $t5, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r13;
    // 0x800B5FA0: beq         $s0, $zero, L_800B611C
    if (ctx->r16 == 0) {
        // 0x800B5FA4: lw          $t7, 0x138($sp)
        ctx->r15 = S32(MEM_W(ctx->r29, 0X138));
            goto L_800B611C;
    }
    // 0x800B5FA4: lw          $t7, 0x138($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X138));
    // 0x800B5FA8: addiu       $at, $zero, 0x349C
    ctx->r1 = ADD32(0, 0X349C);
    // 0x800B5FAC: multu       $t7, $at
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B5FB0: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x800B5FB4: lw          $t8, -0x5370($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X5370));
    // 0x800B5FB8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800B5FBC: addiu       $a1, $a1, -0x9A0
    ctx->r5 = ADD32(ctx->r5, -0X9A0);
    // 0x800B5FC0: mflo        $t9
    ctx->r25 = lo;
    // 0x800B5FC4: addu        $t1, $t9, $t8
    ctx->r9 = ADD32(ctx->r25, ctx->r24);
    // 0x800B5FC8: sll         $t6, $t1, 6
    ctx->r14 = S32(ctx->r9 << 6);
    // 0x800B5FCC: andi        $t5, $t6, 0x7FF
    ctx->r13 = ctx->r14 & 0X7FF;
    // 0x800B5FD0: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x800B5FD4: addiu       $t8, $t1, 0x1095
    ctx->r24 = ADD32(ctx->r9, 0X1095);
    // 0x800B5FD8: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x800B5FDC: sll         $t6, $t8, 5
    ctx->r14 = S32(ctx->r24 << 5);
    // 0x800B5FE0: andi        $t5, $t6, 0x7FF
    ctx->r13 = ctx->r14 & 0X7FF;
    // 0x800B5FE4: lh          $s4, 0x0($t9)
    ctx->r20 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800B5FE8: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x800B5FEC: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x800B5FF0: addiu       $t6, $t1, 0x1A59
    ctx->r14 = ADD32(ctx->r9, 0X1A59);
    // 0x800B5FF4: lh          $t8, 0x0($t9)
    ctx->r24 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800B5FF8: sll         $t5, $t6, 4
    ctx->r13 = S32(ctx->r14 << 4);
    // 0x800B5FFC: andi        $t7, $t5, 0x7FF
    ctx->r15 = ctx->r13 & 0X7FF;
    // 0x800B6000: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800B6004: addiu       $t5, $t1, 0x3D45
    ctx->r13 = ADD32(ctx->r9, 0X3D45);
    // 0x800B6008: addu        $s4, $s4, $t8
    ctx->r20 = ADD32(ctx->r20, ctx->r24);
    // 0x800B600C: addu        $t8, $a1, $t9
    ctx->r24 = ADD32(ctx->r5, ctx->r25);
    // 0x800B6010: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x800B6014: andi        $t9, $t7, 0x7FF
    ctx->r25 = ctx->r15 & 0X7FF;
    // 0x800B6018: lw          $t7, 0x0($s6)
    ctx->r15 = S32(MEM_W(ctx->r22, 0X0));
    // 0x800B601C: lh          $t6, 0x0($t8)
    ctx->r14 = S32(MEM_H(ctx->r24, 0X0));
    // 0x800B6020: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800B6024: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x800B6028: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800B602C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800B6030: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800B6034: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B6038: addu        $s4, $s4, $t6
    ctx->r20 = ADD32(ctx->r20, ctx->r14);
    // 0x800B603C: addu        $t6, $a1, $t8
    ctx->r14 = ADD32(ctx->r5, ctx->r24);
    // 0x800B6040: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800B6044: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B6048: lh          $t5, 0x0($t6)
    ctx->r13 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800B604C: addu        $t8, $fp, $t9
    ctx->r24 = ADD32(ctx->r30, ctx->r25);
    // 0x800B6050: lh          $t6, 0x2E0($t8)
    ctx->r14 = S32(MEM_H(ctx->r24, 0X2E0));
    // 0x800B6054: addu        $s4, $s4, $t5
    ctx->r20 = ADD32(ctx->r20, ctx->r13);
    // 0x800B6058: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B605C: mflo        $t5
    ctx->r13 = lo;
    // 0x800B6060: addu        $t7, $a3, $t5
    ctx->r15 = ADD32(ctx->r7, ctx->r13);
    // 0x800B6064: lh          $v0, 0x14($t7)
    ctx->r2 = S32(MEM_H(ctx->r15, 0X14));
    // 0x800B6068: addiu       $t9, $v0, 0x200
    ctx->r25 = ADD32(ctx->r2, 0X200);
    // 0x800B606C: andi        $t8, $t9, 0x7FF
    ctx->r24 = ctx->r25 & 0X7FF;
    // 0x800B6070: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x800B6074: addu        $t5, $a1, $t6
    ctx->r13 = ADD32(ctx->r5, ctx->r14);
    // 0x800B6078: lh          $s1, 0x0($t5)
    ctx->r17 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800B607C: andi        $t7, $v0, 0x7FF
    ctx->r15 = ctx->r2 & 0X7FF;
    // 0x800B6080: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800B6084: multu       $a0, $s1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B6088: addu        $t8, $a1, $t9
    ctx->r24 = ADD32(ctx->r5, ctx->r25);
    // 0x800B608C: lh          $s2, 0x0($t8)
    ctx->r18 = S32(MEM_H(ctx->r24, 0X0));
    // 0x800B6090: addiu       $t9, $s3, 0x400
    ctx->r25 = ADD32(ctx->r19, 0X400);
    // 0x800B6094: andi        $t8, $t9, 0x7FF
    ctx->r24 = ctx->r25 & 0X7FF;
    // 0x800B6098: sw          $t1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r9;
    // 0x800B609C: mflo        $t6
    ctx->r14 = lo;
    // 0x800B60A0: nop

    // 0x800B60A4: nop

    // 0x800B60A8: multu       $v1, $s2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B60AC: mflo        $t5
    ctx->r13 = lo;
    // 0x800B60B0: slt         $at, $t6, $t5
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B60B4: beq         $at, $zero, L_800B60C4
    if (ctx->r1 == 0) {
        // 0x800B60B8: sll         $t6, $t8, 1
        ctx->r14 = S32(ctx->r24 << 1);
            goto L_800B60C4;
    }
    // 0x800B60B8: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x800B60BC: b           L_800B60C8
    // 0x800B60C0: addiu       $s4, $s4, 0x2000
    ctx->r20 = ADD32(ctx->r20, 0X2000);
        goto L_800B60C8;
    // 0x800B60C0: addiu       $s4, $s4, 0x2000
    ctx->r20 = ADD32(ctx->r20, 0X2000);
L_800B60C4:
    // 0x800B60C4: addiu       $s4, $s4, -0x2000
    ctx->r20 = ADD32(ctx->r20, -0X2000);
L_800B60C8:
    // 0x800B60C8: addu        $t5, $a1, $t6
    ctx->r13 = ADD32(ctx->r5, ctx->r14);
    // 0x800B60CC: lh          $t9, 0x0($t5)
    ctx->r25 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800B60D0: lw          $v0, 0x13C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800B60D4: multu       $t9, $s4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B60D8: lh          $t7, 0x2($v0)
    ctx->r15 = S32(MEM_H(ctx->r2, 0X2));
    // 0x800B60DC: lh          $t9, 0x4($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X4));
    // 0x800B60E0: mflo        $t8
    ctx->r24 = lo;
    // 0x800B60E4: sra         $t6, $t8, 17
    ctx->r14 = S32(SIGNED(ctx->r24) >> 17);
    // 0x800B60E8: addu        $t5, $t7, $t6
    ctx->r13 = ADD32(ctx->r15, ctx->r14);
    // 0x800B60EC: addiu       $t8, $s3, 0x200
    ctx->r24 = ADD32(ctx->r19, 0X200);
    // 0x800B60F0: andi        $t7, $t8, 0x7FF
    ctx->r15 = ctx->r24 & 0X7FF;
    // 0x800B60F4: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x800B60F8: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // 0x800B60FC: addu        $t5, $a1, $t6
    ctx->r13 = ADD32(ctx->r5, ctx->r14);
    // 0x800B6100: lh          $t8, 0x0($t5)
    ctx->r24 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800B6104: multu       $t8, $s4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B6108: mflo        $t7
    ctx->r15 = lo;
    // 0x800B610C: sra         $t6, $t7, 17
    ctx->r14 = S32(SIGNED(ctx->r15) >> 17);
    // 0x800B6110: addu        $t5, $t9, $t6
    ctx->r13 = ADD32(ctx->r25, ctx->r14);
    // 0x800B6114: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    // 0x800B6118: lw          $a2, 0x13C($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X13C));
L_800B611C:
    // 0x800B611C: lw          $t8, 0xE8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XE8));
    // 0x800B6120: sll         $t5, $s7, 3
    ctx->r13 = S32(ctx->r23 << 3);
    // 0x800B6124: subu        $v0, $s3, $t8
    ctx->r2 = SUB32(ctx->r19, ctx->r24);
    // 0x800B6128: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // 0x800B612C: andi        $t7, $v0, 0x7FF
    ctx->r15 = ctx->r2 & 0X7FF;
    // 0x800B6130: addiu       $v0, $t7, -0x400
    ctx->r2 = ADD32(ctx->r15, -0X400);
    // 0x800B6134: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800B6138: slti        $at, $t9, -0x7E
    ctx->r1 = SIGNED(ctx->r25) < -0X7E ? 1 : 0;
    // 0x800B613C: bne         $at, $zero, L_800B614C
    if (ctx->r1 != 0) {
        // 0x800B6140: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_800B614C;
    }
    // 0x800B6140: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800B6144: b           L_800B6150
    // 0x800B6148: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
        goto L_800B6150;
    // 0x800B6148: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_800B614C:
    // 0x800B614C: addiu       $s3, $zero, -0x7F
    ctx->r19 = ADD32(0, -0X7F);
L_800B6150:
    // 0x800B6150: slti        $at, $s3, 0x7F
    ctx->r1 = SIGNED(ctx->r19) < 0X7F ? 1 : 0;
    // 0x800B6154: beq         $at, $zero, L_800B6178
    if (ctx->r1 == 0) {
        // 0x800B6158: addiu       $s3, $zero, -0x7F
        ctx->r19 = ADD32(0, -0X7F);
            goto L_800B6178;
    }
    // 0x800B6158: addiu       $s3, $zero, -0x7F
    ctx->r19 = ADD32(0, -0X7F);
    // 0x800B615C: slti        $at, $v0, -0x7E
    ctx->r1 = SIGNED(ctx->r2) < -0X7E ? 1 : 0;
    // 0x800B6160: bne         $at, $zero, L_800B6170
    if (ctx->r1 != 0) {
        // 0x800B6164: addiu       $v1, $zero, -0x7F
        ctx->r3 = ADD32(0, -0X7F);
            goto L_800B6170;
    }
    // 0x800B6164: addiu       $v1, $zero, -0x7F
    ctx->r3 = ADD32(0, -0X7F);
    // 0x800B6168: b           L_800B6170
    // 0x800B616C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800B6170;
    // 0x800B616C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800B6170:
    // 0x800B6170: b           L_800B6180
    // 0x800B6174: sb          $v1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r3;
        goto L_800B6180;
    // 0x800B6174: sb          $v1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r3;
L_800B6178:
    // 0x800B6178: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x800B617C: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
L_800B6180:
    // 0x800B6180: div         $zero, $t5, $s5
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r21)));
    // 0x800B6184: lw          $t9, 0xA8($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800B6188: mflo        $t8
    ctx->r24 = lo;
    // 0x800B618C: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x800B6190: lw          $t6, 0x220($t9)
    ctx->r14 = S32(MEM_W(ctx->r25, 0X220));
    // 0x800B6194: bne         $s5, $zero, L_800B61A0
    if (ctx->r21 != 0) {
        // 0x800B6198: nop
    
            goto L_800B61A0;
    }
    // 0x800B6198: nop

    // 0x800B619C: break       7
    do_break(2148229532);
L_800B61A0:
    // 0x800B61A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B61A4: bne         $s5, $at, L_800B61B8
    if (ctx->r21 != ctx->r1) {
        // 0x800B61A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B61B8;
    }
    // 0x800B61A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B61AC: bne         $t5, $at, L_800B61B8
    if (ctx->r13 != ctx->r1) {
        // 0x800B61B0: nop
    
            goto L_800B61B8;
    }
    // 0x800B61B0: nop

    // 0x800B61B4: break       6
    do_break(2148229556);
L_800B61B8:
    // 0x800B61B8: subu        $v0, $t7, $t6
    ctx->r2 = SUB32(ctx->r15, ctx->r14);
    // 0x800B61BC: addiu       $v0, $v0, 0x64
    ctx->r2 = ADD32(ctx->r2, 0X64);
    // 0x800B61C0: sra         $t5, $v0, 1
    ctx->r13 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800B61C4: slti        $at, $t5, -0x7E
    ctx->r1 = SIGNED(ctx->r13) < -0X7E ? 1 : 0;
    // 0x800B61C8: bne         $at, $zero, L_800B61D8
    if (ctx->r1 != 0) {
        // 0x800B61CC: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_800B61D8;
    }
    // 0x800B61CC: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800B61D0: b           L_800B61D8
    // 0x800B61D4: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
        goto L_800B61D8;
    // 0x800B61D4: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
L_800B61D8:
    // 0x800B61D8: slti        $at, $s3, 0x7F
    ctx->r1 = SIGNED(ctx->r19) < 0X7F ? 1 : 0;
    // 0x800B61DC: beq         $at, $zero, L_800B6200
    if (ctx->r1 == 0) {
        // 0x800B61E0: addiu       $t8, $zero, 0x7F
        ctx->r24 = ADD32(0, 0X7F);
            goto L_800B6200;
    }
    // 0x800B61E0: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x800B61E4: slti        $at, $v0, -0x7E
    ctx->r1 = SIGNED(ctx->r2) < -0X7E ? 1 : 0;
    // 0x800B61E8: bne         $at, $zero, L_800B61F8
    if (ctx->r1 != 0) {
        // 0x800B61EC: addiu       $v1, $zero, -0x7F
        ctx->r3 = ADD32(0, -0X7F);
            goto L_800B61F8;
    }
    // 0x800B61EC: addiu       $v1, $zero, -0x7F
    ctx->r3 = ADD32(0, -0X7F);
    // 0x800B61F0: b           L_800B61F8
    // 0x800B61F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800B61F8;
    // 0x800B61F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800B61F8:
    // 0x800B61F8: b           L_800B6204
    // 0x800B61FC: sb          $v1, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r3;
        goto L_800B6204;
    // 0x800B61FC: sb          $v1, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r3;
L_800B6200:
    // 0x800B6200: sb          $t8, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r24;
L_800B6204:
    // 0x800B6204: lw          $t9, 0x8($a2)
    ctx->r25 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800B6208: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x800B620C: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x800B6210: b           L_800B7664
    // 0x800B6214: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
        goto L_800B7664;
    // 0x800B6214: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
L_800B6218:
    // 0x800B6218: lw          $t8, 0x0($s6)
    ctx->r24 = S32(MEM_W(ctx->r22, 0X0));
    // 0x800B621C: lw          $t6, 0xA4($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800B6220: lui         $t5, 0x8028
    ctx->r13 = S32(0X8028 << 16);
    // 0x800B6224: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800B6228: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800B622C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800B6230: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800B6234: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B6238: addiu       $t5, $t5, -0x6860
    ctx->r13 = ADD32(ctx->r13, -0X6860);
    // 0x800B623C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800B6240: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800B6244: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B6248: lui         $t7, 0x802A
    ctx->r15 = S32(0X802A << 16);
    // 0x800B624C: addu        $a3, $t6, $t5
    ctx->r7 = ADD32(ctx->r14, ctx->r13);
    // 0x800B6250: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x800B6254: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x800B6258: lh          $t7, 0x5A50($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X5A50));
    // 0x800B625C: lw          $t8, 0xA4($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800B6260: lui         $t9, 0x8028
    ctx->r25 = S32(0X8028 << 16);
    // 0x800B6264: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800B6268: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x800B626C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B6270: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x800B6274: lw          $t7, 0xA8($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800B6278: lui         $t5, 0x8024
    ctx->r13 = S32(0X8024 << 16);
    // 0x800B627C: addiu       $t9, $t9, -0x6850
    ctx->r25 = ADD32(ctx->r25, -0X6850);
    // 0x800B6280: addiu       $t5, $t5, 0x6BA8
    ctx->r13 = ADD32(ctx->r13, 0X6BA8);
    // 0x800B6284: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B6288: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800B628C: addu        $v0, $t6, $t5
    ctx->r2 = ADD32(ctx->r14, ctx->r13);
    // 0x800B6290: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800B6294: lh          $t6, 0x2E0($t7)
    ctx->r14 = S32(MEM_H(ctx->r15, 0X2E0));
    // 0x800B6298: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x800B629C: lh          $t9, 0x10($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X10));
    // 0x800B62A0: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x800B62A4: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x800B62A8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B62AC: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x800B62B0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B62B4: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x800B62B8: lh          $t8, 0x6BB8($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, 0X6BB8));
    // 0x800B62BC: lui         $a0, 0x8028
    ctx->r4 = S32(0X8028 << 16);
    // 0x800B62C0: addiu       $a0, $a0, -0x5DC0
    ctx->r4 = ADD32(ctx->r4, -0X5DC0);
    // 0x800B62C4: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x800B62C8: sw          $a3, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r7;
    // 0x800B62CC: sw          $v1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r3;
    // 0x800B62D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B62D4: addiu       $a2, $zero, 0x53
    ctx->r6 = ADD32(0, 0X53);
    // 0x800B62D8: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x800B62DC: jal         0x8005A548
    // 0x800B62E0: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    clearbufbyte(rdram, ctx);
        goto after_11;
    // 0x800B62E0: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    after_11:
    // 0x800B62E4: lw          $t5, 0xE0($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XE0));
    // 0x800B62E8: lw          $t7, 0xE0($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XE0));
    // 0x800B62EC: lui         $t9, 0x8028
    ctx->r25 = S32(0X8028 << 16);
    // 0x800B62F0: lui         $fp, 0x8028
    ctx->r30 = S32(0X8028 << 16);
    // 0x800B62F4: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800B62F8: addiu       $t9, $t9, -0x5DC0
    ctx->r25 = ADD32(ctx->r25, -0X5DC0);
    // 0x800B62FC: sra         $t8, $t5, 3
    ctx->r24 = S32(SIGNED(ctx->r13) >> 3);
    // 0x800B6300: addiu       $fp, $fp, -0x62E8
    ctx->r30 = ADD32(ctx->r30, -0X62E8);
    // 0x800B6304: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800B6308: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800B630C: sh          $t7, -0x6810($at)
    MEM_H(-0X6810, ctx->r1) = ctx->r15;
    // 0x800B6310: sh          $t6, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r14;
    // 0x800B6314: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800B6318: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B631C: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x800B6320: sllv        $t9, $t8, $t6
    ctx->r25 = S32(ctx->r24 << (ctx->r14 & 31));
    // 0x800B6324: lui         $t8, 0x8028
    ctx->r24 = S32(0X8028 << 16);
    // 0x800B6328: addiu       $t8, $t8, -0x6810
    ctx->r24 = ADD32(ctx->r24, -0X6810);
    // 0x800B632C: or          $t5, $t7, $t9
    ctx->r13 = ctx->r15 | ctx->r25;
    // 0x800B6330: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x800B6334: sw          $t8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r24;
    // 0x800B6338: sw          $zero, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = 0;
    // 0x800B633C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_800B6340:
    // 0x800B6340: lw          $t6, 0x8C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x800B6344: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800B6348: addiu       $t9, $t9, -0x1988
    ctx->r25 = ADD32(ctx->r25, -0X1988);
    // 0x800B634C: lh          $a0, 0x0($t6)
    ctx->r4 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800B6350: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x800B6354: addiu       $t6, $t6, 0x61A8
    ctx->r14 = ADD32(ctx->r14, 0X61A8);
    // 0x800B6358: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800B635C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800B6360: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800B6364: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x800B6368: lh          $s4, 0x8($v0)
    ctx->r20 = S32(MEM_H(ctx->r2, 0X8));
    // 0x800B636C: lh          $t5, 0xA($v0)
    ctx->r13 = S32(MEM_H(ctx->r2, 0XA));
    // 0x800B6370: sll         $t8, $s4, 3
    ctx->r24 = S32(ctx->r20 << 3);
    // 0x800B6374: addu        $t8, $t8, $s4
    ctx->r24 = ADD32(ctx->r24, ctx->r20);
    // 0x800B6378: addu        $s5, $t5, $s4
    ctx->r21 = ADD32(ctx->r13, ctx->r20);
    // 0x800B637C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B6380: slt         $at, $s4, $s5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x800B6384: beq         $at, $zero, L_800B6928
    if (ctx->r1 == 0) {
        // 0x800B6388: addu        $s0, $t8, $t6
        ctx->r16 = ADD32(ctx->r24, ctx->r14);
            goto L_800B6928;
    }
    // 0x800B6388: addu        $s0, $t8, $t6
    ctx->r16 = ADD32(ctx->r24, ctx->r14);
L_800B638C:
    // 0x800B638C: lh          $t7, 0xC($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0XC));
    // 0x800B6390: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x800B6394: addiu       $t6, $t6, 0x61A8
    ctx->r14 = ADD32(ctx->r14, 0X61A8);
    // 0x800B6398: bltz        $t7, L_800B6910
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B639C: sw          $t7, 0x130($sp)
        MEM_W(0X130, ctx->r29) = ctx->r15;
            goto L_800B6910;
    }
    // 0x800B639C: sw          $t7, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r15;
    // 0x800B63A0: lh          $t5, 0x8($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X8));
    // 0x800B63A4: lw          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800B63A8: lh          $a0, 0x132($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X132));
    // 0x800B63AC: sll         $t8, $t5, 3
    ctx->r24 = S32(ctx->r13 << 3);
    // 0x800B63B0: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x800B63B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B63B8: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x800B63BC: lw          $t7, 0x0($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800B63C0: lw          $t8, 0x4($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X4));
    // 0x800B63C4: lw          $t6, 0x4($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800B63C8: addu        $s1, $t7, $t9
    ctx->r17 = ADD32(ctx->r15, ctx->r25);
    // 0x800B63CC: sra         $a1, $s1, 1
    ctx->r5 = S32(SIGNED(ctx->r17) >> 1);
    // 0x800B63D0: addu        $s2, $t8, $t6
    ctx->r18 = ADD32(ctx->r24, ctx->r14);
    // 0x800B63D4: sra         $a2, $s2, 1
    ctx->r6 = S32(SIGNED(ctx->r18) >> 1);
    // 0x800B63D8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800B63DC: jal         0x80098E64
    // 0x800B63E0: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    getceilzofslope(rdram, ctx);
        goto after_12;
    // 0x800B63E0: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    after_12:
    // 0x800B63E4: lw          $t1, 0x130($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
    // 0x800B63E8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800B63EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B63F0: sll         $a0, $t1, 16
    ctx->r4 = S32(ctx->r9 << 16);
    // 0x800B63F4: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B63F8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800B63FC: jal         0x80098FB4
    // 0x800B6400: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    getflorzofslope(rdram, ctx);
        goto after_13;
    // 0x800B6400: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_13:
    // 0x800B6404: addiu       $t5, $v0, -0x1C00
    ctx->r13 = ADD32(ctx->r2, -0X1C00);
    // 0x800B6408: slt         $at, $t5, $s3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800B640C: beq         $at, $zero, L_800B6440
    if (ctx->r1 == 0) {
        // 0x800B6410: lw          $t1, 0x130($sp)
        ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
            goto L_800B6440;
    }
    // 0x800B6410: lw          $t1, 0x130($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
    // 0x800B6414: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x800B6418: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x800B641C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800B6420: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x800B6424: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x800B6428: lh          $v0, -0x1970($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X1970));
    // 0x800B642C: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x800B6430: bne         $at, $zero, L_800B6910
    if (ctx->r1 != 0) {
        // 0x800B6434: slti        $at, $v0, 0x17
        ctx->r1 = SIGNED(ctx->r2) < 0X17 ? 1 : 0;
            goto L_800B6910;
    }
    // 0x800B6434: slti        $at, $v0, 0x17
    ctx->r1 = SIGNED(ctx->r2) < 0X17 ? 1 : 0;
    // 0x800B6438: beq         $at, $zero, L_800B6910
    if (ctx->r1 == 0) {
        // 0x800B643C: sw          $t1, 0x130($sp)
        MEM_W(0X130, ctx->r29) = ctx->r9;
            goto L_800B6910;
    }
    // 0x800B643C: sw          $t1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r9;
L_800B6440:
    // 0x800B6440: lw          $t1, 0x130($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
    // 0x800B6444: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B6448: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800B644C: sll         $a0, $t1, 16
    ctx->r4 = S32(ctx->r9 << 16);
    // 0x800B6450: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B6454: jal         0x80098FB4
    // 0x800B6458: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    getflorzofslope(rdram, ctx);
        goto after_14;
    // 0x800B6458: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_14:
    // 0x800B645C: lw          $t7, 0x8C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x800B6460: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800B6464: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B6468: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800B646C: jal         0x80098FB4
    // 0x800B6470: lh          $a0, 0x0($t7)
    ctx->r4 = S32(MEM_H(ctx->r15, 0X0));
    getflorzofslope(rdram, ctx);
        goto after_15;
    // 0x800B6470: lh          $a0, 0x0($t7)
    ctx->r4 = S32(MEM_H(ctx->r15, 0X0));
    after_15:
    // 0x800B6474: addiu       $t9, $v0, -0x4800
    ctx->r25 = ADD32(ctx->r2, -0X4800);
    // 0x800B6478: slt         $at, $s3, $t9
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B647C: bne         $at, $zero, L_800B6910
    if (ctx->r1 != 0) {
        // 0x800B6480: lw          $t1, 0x130($sp)
        ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
            goto L_800B6910;
    }
    // 0x800B6480: lw          $t1, 0x130($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
    // 0x800B6484: lui         $t8, 0x8028
    ctx->r24 = S32(0X8028 << 16);
    // 0x800B6488: addiu       $t8, $t8, -0x5DC0
    ctx->r24 = ADD32(ctx->r24, -0X5DC0);
    // 0x800B648C: sra         $t5, $t1, 3
    ctx->r13 = S32(SIGNED(ctx->r9) >> 3);
    // 0x800B6490: addu        $v0, $t5, $t8
    ctx->r2 = ADD32(ctx->r13, ctx->r24);
    // 0x800B6494: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800B6498: andi        $t6, $t1, 0x7
    ctx->r14 = ctx->r9 & 0X7;
    // 0x800B649C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B64A0: sllv        $a0, $t7, $t6
    ctx->r4 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x800B64A4: and         $t9, $v1, $a0
    ctx->r25 = ctx->r3 & ctx->r4;
    // 0x800B64A8: bne         $t9, $zero, L_800B6910
    if (ctx->r25 != 0) {
        // 0x800B64AC: or          $t5, $v1, $a0
        ctx->r13 = ctx->r3 | ctx->r4;
            goto L_800B6910;
    }
    // 0x800B64AC: or          $t5, $v1, $a0
    ctx->r13 = ctx->r3 | ctx->r4;
    // 0x800B64B0: lw          $t8, 0xD8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XD8));
    // 0x800B64B4: sll         $a1, $s7, 1
    ctx->r5 = S32(ctx->r23 << 1);
    // 0x800B64B8: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800B64BC: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x800B64C0: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x800B64C4: sh          $t1, -0x6810($at)
    MEM_H(-0X6810, ctx->r1) = ctx->r9;
    // 0x800B64C8: addu        $t7, $fp, $a1
    ctx->r15 = ADD32(ctx->r30, ctx->r5);
    // 0x800B64CC: sh          $t8, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r24;
    // 0x800B64D0: lw          $t6, 0xDC($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XDC));
    // 0x800B64D4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B64D8: sw          $t1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r9;
    // 0x800B64DC: bne         $t1, $t6, L_800B6910
    if (ctx->r9 != ctx->r14) {
        // 0x800B64E0: lw          $a0, 0x90($sp)
        ctx->r4 = S32(MEM_W(ctx->r29, 0X90));
            goto L_800B6910;
    }
    // 0x800B64E0: lw          $a0, 0x90($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X90));
    // 0x800B64E4: lw          $t9, 0xE0($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XE0));
    // 0x800B64E8: lw          $t7, 0xA4($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800B64EC: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800B64F0: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800B64F4: lui         $t6, 0x8028
    ctx->r14 = S32(0X8028 << 16);
    // 0x800B64F8: subu        $t5, $t5, $t9
    ctx->r13 = SUB32(ctx->r13, ctx->r25);
    // 0x800B64FC: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800B6500: addiu       $t6, $t6, -0x6890
    ctx->r14 = ADD32(ctx->r14, -0X6890);
    // 0x800B6504: addiu       $t8, $t8, -0x1988
    ctx->r24 = ADD32(ctx->r24, -0X1988);
    // 0x800B6508: addu        $s1, $t5, $t8
    ctx->r17 = ADD32(ctx->r13, ctx->r24);
    // 0x800B650C: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x800B6510: lui         $t6, 0x8028
    ctx->r14 = S32(0X8028 << 16);
    // 0x800B6514: lui         $t5, 0x8028
    ctx->r13 = S32(0X8028 << 16);
    // 0x800B6518: addiu       $t5, $t5, -0x6880
    ctx->r13 = ADD32(ctx->r13, -0X6880);
    // 0x800B651C: addiu       $t6, $t6, -0x6870
    ctx->r14 = ADD32(ctx->r14, -0X6870);
    // 0x800B6520: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x800B6524: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x800B6528: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x800B652C: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x800B6530: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x800B6534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B6538: addiu       $a2, $zero, 0x53
    ctx->r6 = ADD32(0, 0X53);
    // 0x800B653C: jal         0x8005A548
    // 0x800B6540: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    clearbufbyte(rdram, ctx);
        goto after_16;
    // 0x800B6540: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    after_16:
    // 0x800B6544: addiu       $a1, $s7, -0x1
    ctx->r5 = ADD32(ctx->r23, -0X1);
    // 0x800B6548: bltz        $a1, L_800B659C
    if (SIGNED(ctx->r5) < 0) {
        // 0x800B654C: or          $s3, $a1, $zero
        ctx->r19 = ctx->r5 | 0;
            goto L_800B659C;
    }
    // 0x800B654C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800B6550: sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19 << 1);
L_800B6554:
    // 0x800B6554: lui         $v0, 0x8028
    ctx->r2 = S32(0X8028 << 16);
    // 0x800B6558: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B655C: lh          $v0, -0x6810($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X6810));
    // 0x800B6560: lui         $t8, 0x8028
    ctx->r24 = S32(0X8028 << 16);
    // 0x800B6564: addiu       $t8, $t8, -0x5DC0
    ctx->r24 = ADD32(ctx->r24, -0X5DC0);
    // 0x800B6568: sra         $t5, $v0, 3
    ctx->r13 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800B656C: addu        $a0, $t5, $t8
    ctx->r4 = ADD32(ctx->r13, ctx->r24);
    // 0x800B6570: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B6574: andi        $t6, $v0, 0x7
    ctx->r14 = ctx->r2 & 0X7;
    // 0x800B6578: sllv        $t5, $t9, $t6
    ctx->r13 = S32(ctx->r25 << (ctx->r14 & 31));
    // 0x800B657C: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x800B6580: addu        $t9, $fp, $v1
    ctx->r25 = ADD32(ctx->r30, ctx->r3);
    // 0x800B6584: lh          $s3, 0x0($t9)
    ctx->r19 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800B6588: or          $t8, $t7, $t5
    ctx->r24 = ctx->r15 | ctx->r13;
    // 0x800B658C: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x800B6590: bgezl       $s3, L_800B6554
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800B6594: sll         $v1, $s3, 1
        ctx->r3 = S32(ctx->r19 << 1);
            goto L_800B6554;
    }
    goto skip_14;
    // 0x800B6594: sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19 << 1);
    skip_14:
    // 0x800B6598: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
L_800B659C:
    // 0x800B659C: bltz        $a1, L_800B65C0
    if (SIGNED(ctx->r5) < 0) {
        // 0x800B65A0: lw          $t8, 0x98($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0X98));
            goto L_800B65C0;
    }
    // 0x800B65A0: lw          $t8, 0x98($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X98));
L_800B65A4:
    // 0x800B65A4: sll         $t6, $s3, 1
    ctx->r14 = S32(ctx->r19 << 1);
    // 0x800B65A8: addu        $t7, $fp, $t6
    ctx->r15 = ADD32(ctx->r30, ctx->r14);
    // 0x800B65AC: lh          $v0, 0x0($t7)
    ctx->r2 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800B65B0: beql        $v0, $zero, L_800B65C4
    if (ctx->r2 == 0) {
        // 0x800B65B4: sll         $t5, $s3, 1
        ctx->r13 = S32(ctx->r19 << 1);
            goto L_800B65C4;
    }
    goto skip_15;
    // 0x800B65B4: sll         $t5, $s3, 1
    ctx->r13 = S32(ctx->r19 << 1);
    skip_15:
    // 0x800B65B8: bgez        $v0, L_800B65A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B65BC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800B65A4;
    }
    // 0x800B65BC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_800B65C0:
    // 0x800B65C0: sll         $t5, $s3, 1
    ctx->r13 = S32(ctx->r19 << 1);
L_800B65C4:
    // 0x800B65C4: lui         $v0, 0x8028
    ctx->r2 = S32(0X8028 << 16);
    // 0x800B65C8: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x800B65CC: lh          $v0, -0x6810($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X6810));
    // 0x800B65D0: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x800B65D4: addiu       $t6, $t6, -0x1988
    ctx->r14 = ADD32(ctx->r14, -0X1988);
    // 0x800B65D8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800B65DC: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x800B65E0: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800B65E4: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x800B65E8: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x800B65EC: lh          $v1, 0x8($a0)
    ctx->r3 = S32(MEM_H(ctx->r4, 0X8));
    // 0x800B65F0: lh          $t7, 0xA($a0)
    ctx->r15 = S32(MEM_H(ctx->r4, 0XA));
    // 0x800B65F4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800B65F8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800B65FC: addu        $s5, $t7, $v1
    ctx->r21 = ADD32(ctx->r15, ctx->r3);
    // 0x800B6600: slt         $at, $v1, $s5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x800B6604: beq         $at, $zero, L_800B6650
    if (ctx->r1 == 0) {
        // 0x800B6608: or          $s4, $v1, $zero
        ctx->r20 = ctx->r3 | 0;
            goto L_800B6650;
    }
    // 0x800B6608: or          $s4, $v1, $zero
    ctx->r20 = ctx->r3 | 0;
    // 0x800B660C: sll         $t5, $s4, 3
    ctx->r13 = S32(ctx->r20 << 3);
    // 0x800B6610: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800B6614: sll         $t9, $s5, 3
    ctx->r25 = S32(ctx->r21 << 3);
    // 0x800B6618: addu        $t9, $t9, $s5
    ctx->r25 = ADD32(ctx->r25, ctx->r21);
    // 0x800B661C: addiu       $t8, $t8, 0x61A8
    ctx->r24 = ADD32(ctx->r24, 0X61A8);
    // 0x800B6620: addu        $t5, $t5, $s4
    ctx->r13 = ADD32(ctx->r13, ctx->r20);
    // 0x800B6624: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B6628: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B662C: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x800B6630: addu        $s0, $t5, $t8
    ctx->r16 = ADD32(ctx->r13, ctx->r24);
L_800B6634:
    // 0x800B6634: lw          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800B6638: lw          $t7, 0x4($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800B663C: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    // 0x800B6640: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800B6644: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x800B6648: bne         $at, $zero, L_800B6634
    if (ctx->r1 != 0) {
        // 0x800B664C: addu        $t2, $t2, $t7
        ctx->r10 = ADD32(ctx->r10, ctx->r15);
            goto L_800B6634;
    }
    // 0x800B664C: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
L_800B6650:
    // 0x800B6650: subu        $v0, $s5, $v1
    ctx->r2 = SUB32(ctx->r21, ctx->r3);
    // 0x800B6654: div         $zero, $t1, $v0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r2)));
    // 0x800B6658: bne         $v0, $zero, L_800B6664
    if (ctx->r2 != 0) {
        // 0x800B665C: nop
    
            goto L_800B6664;
    }
    // 0x800B665C: nop

    // 0x800B6660: break       7
    do_break(2148230752);
L_800B6664:
    // 0x800B6664: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B6668: bne         $v0, $at, L_800B667C
    if (ctx->r2 != ctx->r1) {
        // 0x800B666C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B667C;
    }
    // 0x800B666C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B6670: bne         $t1, $at, L_800B667C
    if (ctx->r9 != ctx->r1) {
        // 0x800B6674: nop
    
            goto L_800B667C;
    }
    // 0x800B6674: nop

    // 0x800B6678: break       6
    do_break(2148230776);
L_800B667C:
    // 0x800B667C: mflo        $t1
    ctx->r9 = lo;
    // 0x800B6680: lh          $v1, 0x8($s1)
    ctx->r3 = S32(MEM_H(ctx->r17, 0X8));
    // 0x800B6684: lh          $t5, 0xA($s1)
    ctx->r13 = S32(MEM_H(ctx->r17, 0XA));
    // 0x800B6688: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x800B668C: bne         $v0, $zero, L_800B6698
    if (ctx->r2 != 0) {
        // 0x800B6690: nop
    
            goto L_800B6698;
    }
    // 0x800B6690: nop

    // 0x800B6694: break       7
    do_break(2148230804);
L_800B6698:
    // 0x800B6698: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B669C: bne         $v0, $at, L_800B66B0
    if (ctx->r2 != ctx->r1) {
        // 0x800B66A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B66B0;
    }
    // 0x800B66A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B66A4: bne         $t2, $at, L_800B66B0
    if (ctx->r10 != ctx->r1) {
        // 0x800B66A8: nop
    
            goto L_800B66B0;
    }
    // 0x800B66A8: nop

    // 0x800B66AC: break       6
    do_break(2148230828);
L_800B66B0:
    // 0x800B66B0: addu        $s5, $t5, $v1
    ctx->r21 = ADD32(ctx->r13, ctx->r3);
    // 0x800B66B4: mflo        $t2
    ctx->r10 = lo;
    // 0x800B66B8: slt         $at, $v1, $s5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x800B66BC: sw          $t2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r10;
    // 0x800B66C0: sw          $t1, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r9;
    // 0x800B66C4: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x800B66C8: beq         $at, $zero, L_800B67FC
    if (ctx->r1 == 0) {
        // 0x800B66CC: or          $s4, $v1, $zero
        ctx->r20 = ctx->r3 | 0;
            goto L_800B67FC;
    }
    // 0x800B66CC: or          $s4, $v1, $zero
    ctx->r20 = ctx->r3 | 0;
    // 0x800B66D0: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x800B66D4: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x800B66D8: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800B66DC: addiu       $t8, $t8, 0x61A8
    ctx->r24 = ADD32(ctx->r24, 0X61A8);
    // 0x800B66E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B66E4: addu        $s0, $t9, $t8
    ctx->r16 = ADD32(ctx->r25, ctx->r24);
L_800B66E8:
    // 0x800B66E8: lw          $t7, 0x98($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X98));
    // 0x800B66EC: lh          $t6, 0xC($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0XC));
    // 0x800B66F0: lw          $t9, 0x124($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X124));
    // 0x800B66F4: lw          $t5, 0x0($t7)
    ctx->r13 = S32(MEM_W(ctx->r15, 0X0));
    // 0x800B66F8: lw          $t8, 0x120($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X120));
    // 0x800B66FC: beql        $t6, $t5, L_800B6714
    if (ctx->r14 == ctx->r13) {
        // 0x800B6700: lh          $t7, 0x8($s0)
        ctx->r15 = S32(MEM_H(ctx->r16, 0X8));
            goto L_800B6714;
    }
    goto skip_16;
    // 0x800B6700: lh          $t7, 0x8($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X8));
    skip_16:
    // 0x800B6704: sw          $t1, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r9;
    // 0x800B6708: b           L_800B67E4
    // 0x800B670C: sw          $t2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r10;
        goto L_800B67E4;
    // 0x800B670C: sw          $t2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r10;
    // 0x800B6710: lh          $t7, 0x8($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X8));
L_800B6714:
    // 0x800B6714: lw          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800B6718: subu        $a2, $t2, $t8
    ctx->r6 = SUB32(ctx->r10, ctx->r24);
    // 0x800B671C: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800B6720: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x800B6724: subu        $t7, $v0, $t9
    ctx->r15 = SUB32(ctx->r2, ctx->r25);
    // 0x800B6728: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B672C: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x800B6730: addiu       $t5, $t5, 0x61A8
    ctx->r13 = ADD32(ctx->r13, 0X61A8);
    // 0x800B6734: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B6738: lw          $v1, 0x4($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800B673C: addu        $a1, $t6, $t5
    ctx->r5 = ADD32(ctx->r14, ctx->r13);
    // 0x800B6740: subu        $a0, $t1, $t9
    ctx->r4 = SUB32(ctx->r9, ctx->r25);
    // 0x800B6744: subu        $t5, $v1, $t8
    ctx->r13 = SUB32(ctx->r3, ctx->r24);
    // 0x800B6748: lw          $t0, 0x4($a1)
    ctx->r8 = S32(MEM_W(ctx->r5, 0X4));
    // 0x800B674C: lw          $a3, 0x0($a1)
    ctx->r7 = S32(MEM_W(ctx->r5, 0X0));
    // 0x800B6750: mflo        $t6
    ctx->r14 = lo;
    // 0x800B6754: sw          $t1, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r9;
    // 0x800B6758: sw          $t2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r10;
    // 0x800B675C: multu       $a0, $t5
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B6760: subu        $s2, $t0, $v1
    ctx->r18 = SUB32(ctx->r8, ctx->r3);
    // 0x800B6764: subu        $t5, $t0, $t8
    ctx->r13 = SUB32(ctx->r8, ctx->r24);
    // 0x800B6768: subu        $s1, $a3, $v0
    ctx->r17 = SUB32(ctx->r7, ctx->r2);
    // 0x800B676C: mflo        $t7
    ctx->r15 = lo;
    // 0x800B6770: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B6774: bne         $at, $zero, L_800B67AC
    if (ctx->r1 != 0) {
        // 0x800B6778: nop
    
            goto L_800B67AC;
    }
    // 0x800B6778: nop

    // 0x800B677C: multu       $a0, $t5
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B6780: subu        $t7, $a3, $t9
    ctx->r15 = SUB32(ctx->r7, ctx->r25);
    // 0x800B6784: mflo        $t6
    ctx->r14 = lo;
    // 0x800B6788: nop

    // 0x800B678C: nop

    // 0x800B6790: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B6794: mflo        $t8
    ctx->r24 = lo;
    // 0x800B6798: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B679C: bne         $at, $zero, L_800B67AC
    if (ctx->r1 != 0) {
        // 0x800B67A0: nop
    
            goto L_800B67AC;
    }
    // 0x800B67A0: nop

    // 0x800B67A4: b           L_800B67FC
    // 0x800B67A8: or          $s3, $s4, $zero
    ctx->r19 = ctx->r20 | 0;
        goto L_800B67FC;
    // 0x800B67A8: or          $s3, $s4, $zero
    ctx->r19 = ctx->r20 | 0;
L_800B67AC:
    // 0x800B67AC: multu       $s1, $s1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B67B0: mflo        $t5
    ctx->r13 = lo;
    // 0x800B67B4: nop

    // 0x800B67B8: nop

    // 0x800B67BC: multu       $s2, $s2
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B67C0: mflo        $t9
    ctx->r25 = lo;
    // 0x800B67C4: addu        $a0, $t5, $t9
    ctx->r4 = ADD32(ctx->r13, ctx->r25);
    // 0x800B67C8: jal         0x80092164
    // 0x800B67CC: nop

    ksqrt(rdram, ctx);
        goto after_17;
    // 0x800B67CC: nop

    after_17:
    // 0x800B67D0: slt         $at, $s6, $v0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B67D4: beql        $at, $zero, L_800B67E8
    if (ctx->r1 == 0) {
        // 0x800B67D8: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_800B67E8;
    }
    goto skip_17;
    // 0x800B67D8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_17:
    // 0x800B67DC: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800B67E0: or          $s3, $s4, $zero
    ctx->r19 = ctx->r20 | 0;
L_800B67E4:
    // 0x800B67E4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_800B67E8:
    // 0x800B67E8: slt         $at, $s4, $s5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x800B67EC: lw          $t1, 0x10C($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X10C));
    // 0x800B67F0: lw          $t2, 0x108($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X108));
    // 0x800B67F4: bne         $at, $zero, L_800B66E8
    if (ctx->r1 != 0) {
        // 0x800B67F8: addiu       $s0, $s0, 0x24
        ctx->r16 = ADD32(ctx->r16, 0X24);
            goto L_800B66E8;
    }
    // 0x800B67F8: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
L_800B67FC:
    // 0x800B67FC: lw          $t7, 0x94($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X94));
    // 0x800B6800: sll         $t6, $s3, 3
    ctx->r14 = S32(ctx->r19 << 3);
    // 0x800B6804: addu        $t6, $t6, $s3
    ctx->r14 = ADD32(ctx->r14, ctx->r19);
    // 0x800B6808: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800B680C: addiu       $t8, $t8, 0x61A8
    ctx->r24 = ADD32(ctx->r24, 0X61A8);
    // 0x800B6810: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B6814: addu        $s0, $t6, $t8
    ctx->r16 = ADD32(ctx->r14, ctx->r24);
    // 0x800B6818: sw          $s3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r19;
    // 0x800B681C: lh          $t5, 0x8($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X8));
    // 0x800B6820: lw          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800B6824: sll         $t9, $t5, 3
    ctx->r25 = S32(ctx->r13 << 3);
    // 0x800B6828: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x800B682C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B6830: addu        $s1, $t9, $t8
    ctx->r17 = ADD32(ctx->r25, ctx->r24);
    // 0x800B6834: lw          $t7, 0x0($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800B6838: lw          $t5, 0x4($s1)
    ctx->r13 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800B683C: lw          $t9, 0x4($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800B6840: subu        $a0, $t7, $t6
    ctx->r4 = SUB32(ctx->r15, ctx->r14);
    // 0x800B6844: jal         0x80092024
    // 0x800B6848: subu        $a1, $t5, $t9
    ctx->r5 = SUB32(ctx->r13, ctx->r25);
    getangle(rdram, ctx);
        goto after_18;
    // 0x800B6848: subu        $a1, $t5, $t9
    ctx->r5 = SUB32(ctx->r13, ctx->r25);
    after_18:
    // 0x800B684C: lh          $t7, 0x8($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X8));
    // 0x800B6850: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x800B6854: addiu       $t5, $t5, 0x61A8
    ctx->r13 = ADD32(ctx->r13, 0X61A8);
    // 0x800B6858: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800B685C: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x800B6860: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B6864: addu        $s1, $t6, $t5
    ctx->r17 = ADD32(ctx->r14, ctx->r13);
    // 0x800B6868: lw          $t8, 0x0($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800B686C: lw          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800B6870: addiu       $v1, $v0, 0x600
    ctx->r3 = ADD32(ctx->r2, 0X600);
    // 0x800B6874: addiu       $t5, $v1, 0x200
    ctx->r13 = ADD32(ctx->r3, 0X200);
    // 0x800B6878: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x800B687C: sra         $t6, $t7, 1
    ctx->r14 = S32(SIGNED(ctx->r15) >> 1);
    // 0x800B6880: andi        $t9, $t5, 0x7FF
    ctx->r25 = ctx->r13 & 0X7FF;
    // 0x800B6884: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800B6888: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800B688C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800B6890: lh          $t7, -0x9A0($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, -0X9A0));
    // 0x800B6894: lw          $t8, 0x7C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X7C));
    // 0x800B6898: sra         $t5, $t7, 8
    ctx->r13 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800B689C: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x800B68A0: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x800B68A4: lw          $t5, 0x4($s1)
    ctx->r13 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800B68A8: lw          $t7, 0x4($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800B68AC: andi        $t8, $v1, 0x7FF
    ctx->r24 = ctx->r3 & 0X7FF;
    // 0x800B68B0: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x800B68B4: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x800B68B8: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800B68BC: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x800B68C0: lh          $t5, -0x9A0($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, -0X9A0));
    // 0x800B68C4: lw          $t7, 0x78($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800B68C8: sra         $t9, $t6, 1
    ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800B68CC: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800B68D0: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800B68D4: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800B68D8: lw          $t5, 0x98($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X98));
    // 0x800B68DC: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800B68E0: lw          $t6, 0x0($t5)
    ctx->r14 = S32(MEM_W(ctx->r13, 0X0));
    // 0x800B68E4: lw          $t5, 0x74($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X74));
    // 0x800B68E8: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800B68EC: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x800B68F0: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800B68F4: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800B68F8: lw          $t8, -0x1984($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X1984));
    // 0x800B68FC: addiu       $t7, $t8, -0x2000
    ctx->r15 = ADD32(ctx->r24, -0X2000);
    // 0x800B6900: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800B6904: lw          $t6, 0x8C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x800B6908: b           L_800B6928
    // 0x800B690C: lh          $a0, 0x0($t6)
    ctx->r4 = S32(MEM_H(ctx->r14, 0X0));
        goto L_800B6928;
    // 0x800B690C: lh          $a0, 0x0($t6)
    ctx->r4 = S32(MEM_H(ctx->r14, 0X0));
L_800B6910:
    // 0x800B6910: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800B6914: slt         $at, $s4, $s5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x800B6918: bne         $at, $zero, L_800B638C
    if (ctx->r1 != 0) {
        // 0x800B691C: addiu       $s0, $s0, 0x24
        ctx->r16 = ADD32(ctx->r16, 0X24);
            goto L_800B638C;
    }
    // 0x800B691C: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    // 0x800B6920: lw          $t9, 0x8C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x800B6924: lh          $a0, 0x0($t9)
    ctx->r4 = S32(MEM_H(ctx->r25, 0X0));
L_800B6928:
    // 0x800B6928: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800B692C: lui         $s4, 0x8027
    ctx->r20 = S32(0X8027 << 16);
    // 0x800B6930: addu        $s4, $s4, $t8
    ctx->r20 = ADD32(ctx->r20, ctx->r24);
    // 0x800B6934: lh          $s4, 0x2330($s4)
    ctx->r20 = S32(MEM_H(ctx->r20, 0X2330));
    // 0x800B6938: bltz        $s4, L_800B6CD8
    if (SIGNED(ctx->r20) < 0) {
        // 0x800B693C: sll         $t7, $s4, 2
        ctx->r15 = S32(ctx->r20 << 2);
            goto L_800B6CD8;
    }
    // 0x800B693C: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
L_800B6940:
    // 0x800B6940: subu        $t7, $t7, $s4
    ctx->r15 = SUB32(ctx->r15, ctx->r20);
    // 0x800B6944: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B6948: subu        $t7, $t7, $s4
    ctx->r15 = SUB32(ctx->r15, ctx->r20);
    // 0x800B694C: lui         $t5, 0x8024
    ctx->r13 = S32(0X8024 << 16);
    // 0x800B6950: addiu       $t5, $t5, 0x6BA8
    ctx->r13 = ADD32(ctx->r13, 0X6BA8);
    // 0x800B6954: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B6958: addu        $t0, $t7, $t5
    ctx->r8 = ADD32(ctx->r15, ctx->r13);
    // 0x800B695C: lh          $t6, 0xE($t0)
    ctx->r14 = S32(MEM_H(ctx->r8, 0XE));
    // 0x800B6960: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B6964: bnel        $t6, $at, L_800B6CC4
    if (ctx->r14 != ctx->r1) {
        // 0x800B6968: sll         $t8, $s4, 1
        ctx->r24 = S32(ctx->r20 << 1);
            goto L_800B6CC4;
    }
    goto skip_18;
    // 0x800B6968: sll         $t8, $s4, 1
    ctx->r24 = S32(ctx->r20 << 1);
    skip_18:
    // 0x800B696C: lh          $t9, 0x1E($t0)
    ctx->r25 = S32(MEM_H(ctx->r8, 0X1E));
    // 0x800B6970: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800B6974: bnel        $t9, $at, L_800B6CC4
    if (ctx->r25 != ctx->r1) {
        // 0x800B6978: sll         $t8, $s4, 1
        ctx->r24 = S32(ctx->r20 << 1);
            goto L_800B6CC4;
    }
    goto skip_19;
    // 0x800B6978: sll         $t8, $s4, 1
    ctx->r24 = S32(ctx->r20 << 1);
    skip_19:
    // 0x800B697C: lh          $t8, 0x16($t0)
    ctx->r24 = S32(MEM_H(ctx->r8, 0X16));
    // 0x800B6980: sll         $a1, $s7, 1
    ctx->r5 = S32(ctx->r23 << 1);
    // 0x800B6984: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800B6988: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800B698C: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x800B6990: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B6994: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x800B6998: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B699C: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x800B69A0: lh          $t1, 0x10($t6)
    ctx->r9 = S32(MEM_H(ctx->r14, 0X10));
    // 0x800B69A4: lui         $t8, 0x8028
    ctx->r24 = S32(0X8028 << 16);
    // 0x800B69A8: addiu       $t8, $t8, -0x5DC0
    ctx->r24 = ADD32(ctx->r24, -0X5DC0);
    // 0x800B69AC: sra         $t9, $t1, 3
    ctx->r25 = S32(SIGNED(ctx->r9) >> 3);
    // 0x800B69B0: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x800B69B4: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800B69B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800B69BC: andi        $t7, $t1, 0x7
    ctx->r15 = ctx->r9 & 0X7;
    // 0x800B69C0: sllv        $a0, $t5, $t7
    ctx->r4 = S32(ctx->r13 << (ctx->r15 & 31));
    // 0x800B69C4: and         $t6, $v1, $a0
    ctx->r14 = ctx->r3 & ctx->r4;
    // 0x800B69C8: bne         $t6, $zero, L_800B6CC0
    if (ctx->r14 != 0) {
        // 0x800B69CC: sw          $t1, 0x130($sp)
        MEM_W(0X130, ctx->r29) = ctx->r9;
            goto L_800B6CC0;
    }
    // 0x800B69CC: sw          $t1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r9;
    // 0x800B69D0: lw          $t8, 0xD8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XD8));
    // 0x800B69D4: or          $t9, $v1, $a0
    ctx->r25 = ctx->r3 | ctx->r4;
    // 0x800B69D8: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800B69DC: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x800B69E0: sh          $t1, -0x6810($at)
    MEM_H(-0X6810, ctx->r1) = ctx->r9;
    // 0x800B69E4: addu        $t5, $fp, $a1
    ctx->r13 = ADD32(ctx->r30, ctx->r5);
    // 0x800B69E8: sh          $t8, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r24;
    // 0x800B69EC: lw          $t7, 0xDC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XDC));
    // 0x800B69F0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B69F4: lw          $v0, 0xA4($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800B69F8: bne         $t1, $t7, L_800B6CC0
    if (ctx->r9 != ctx->r15) {
        // 0x800B69FC: sw          $t1, 0x130($sp)
        MEM_W(0X130, ctx->r29) = ctx->r9;
            goto L_800B6CC0;
    }
    // 0x800B69FC: sw          $t1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r9;
    // 0x800B6A00: lw          $t6, 0xE0($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XE0));
    // 0x800B6A04: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800B6A08: addiu       $t8, $t8, -0x1988
    ctx->r24 = ADD32(ctx->r24, -0X1988);
    // 0x800B6A0C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800B6A10: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x800B6A14: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800B6A18: addu        $s1, $t9, $t8
    ctx->r17 = ADD32(ctx->r25, ctx->r24);
    // 0x800B6A1C: lui         $t5, 0x8028
    ctx->r13 = S32(0X8028 << 16);
    // 0x800B6A20: addiu       $t5, $t5, -0x6890
    ctx->r13 = ADD32(ctx->r13, -0X6890);
    // 0x800B6A24: lui         $t8, 0x8028
    ctx->r24 = S32(0X8028 << 16);
    // 0x800B6A28: lui         $t6, 0x8028
    ctx->r14 = S32(0X8028 << 16);
    // 0x800B6A2C: addiu       $t6, $t6, -0x6880
    ctx->r14 = ADD32(ctx->r14, -0X6880);
    // 0x800B6A30: addiu       $t8, $t8, -0x6870
    ctx->r24 = ADD32(ctx->r24, -0X6870);
    // 0x800B6A34: addu        $t7, $v0, $t5
    ctx->r15 = ADD32(ctx->r2, ctx->r13);
    // 0x800B6A38: addu        $t5, $v0, $t8
    ctx->r13 = ADD32(ctx->r2, ctx->r24);
    // 0x800B6A3C: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x800B6A40: sw          $t9, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r25;
    // 0x800B6A44: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x800B6A48: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x800B6A4C: lw          $a0, 0x90($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X90));
    // 0x800B6A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B6A54: addiu       $a2, $zero, 0x53
    ctx->r6 = ADD32(0, 0X53);
    // 0x800B6A58: jal         0x8005A548
    // 0x800B6A5C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    clearbufbyte(rdram, ctx);
        goto after_19;
    // 0x800B6A5C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    after_19:
    // 0x800B6A60: addiu       $a1, $s7, -0x1
    ctx->r5 = ADD32(ctx->r23, -0X1);
    // 0x800B6A64: bltz        $a1, L_800B6ABC
    if (SIGNED(ctx->r5) < 0) {
        // 0x800B6A68: or          $s3, $a1, $zero
        ctx->r19 = ctx->r5 | 0;
            goto L_800B6ABC;
    }
    // 0x800B6A68: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800B6A6C: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800B6A70: lui         $a2, 0x8028
    ctx->r6 = S32(0X8028 << 16);
    // 0x800B6A74: addiu       $a2, $a2, -0x6810
    ctx->r6 = ADD32(ctx->r6, -0X6810);
    // 0x800B6A78: addiu       $a3, $a3, -0x5DC0
    ctx->r7 = ADD32(ctx->r7, -0X5DC0);
    // 0x800B6A7C: sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19 << 1);
L_800B6A80:
    // 0x800B6A80: addu        $t7, $a2, $v1
    ctx->r15 = ADD32(ctx->r6, ctx->r3);
    // 0x800B6A84: lh          $v0, 0x0($t7)
    ctx->r2 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800B6A88: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800B6A8C: sra         $t6, $v0, 3
    ctx->r14 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800B6A90: andi        $t8, $v0, 0x7
    ctx->r24 = ctx->r2 & 0X7;
    // 0x800B6A94: sllv        $t7, $t5, $t8
    ctx->r15 = S32(ctx->r13 << (ctx->r24 & 31));
    // 0x800B6A98: addu        $a0, $a3, $t6
    ctx->r4 = ADD32(ctx->r7, ctx->r14);
    // 0x800B6A9C: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x800B6AA0: addu        $t5, $fp, $v1
    ctx->r13 = ADD32(ctx->r30, ctx->r3);
    // 0x800B6AA4: lh          $s3, 0x0($t5)
    ctx->r19 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800B6AA8: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x800B6AAC: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x800B6AB0: bgezl       $s3, L_800B6A80
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800B6AB4: sll         $v1, $s3, 1
        ctx->r3 = S32(ctx->r19 << 1);
            goto L_800B6A80;
    }
    goto skip_20;
    // 0x800B6AB4: sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19 << 1);
    skip_20:
    // 0x800B6AB8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
L_800B6ABC:
    // 0x800B6ABC: bltz        $a1, L_800B6AE0
    if (SIGNED(ctx->r5) < 0) {
        // 0x800B6AC0: lui         $t6, 0x8028
        ctx->r14 = S32(0X8028 << 16);
            goto L_800B6AE0;
    }
    // 0x800B6AC0: lui         $t6, 0x8028
    ctx->r14 = S32(0X8028 << 16);
L_800B6AC4:
    // 0x800B6AC4: sll         $t8, $s3, 1
    ctx->r24 = S32(ctx->r19 << 1);
    // 0x800B6AC8: addu        $t9, $fp, $t8
    ctx->r25 = ADD32(ctx->r30, ctx->r24);
    // 0x800B6ACC: lh          $v0, 0x0($t9)
    ctx->r2 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800B6AD0: beql        $v0, $zero, L_800B6AE4
    if (ctx->r2 == 0) {
        // 0x800B6AD4: sll         $t7, $s3, 1
        ctx->r15 = S32(ctx->r19 << 1);
            goto L_800B6AE4;
    }
    goto skip_21;
    // 0x800B6AD4: sll         $t7, $s3, 1
    ctx->r15 = S32(ctx->r19 << 1);
    skip_21:
    // 0x800B6AD8: bgez        $v0, L_800B6AC4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B6ADC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800B6AC4;
    }
    // 0x800B6ADC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_800B6AE0:
    // 0x800B6AE0: sll         $t7, $s3, 1
    ctx->r15 = S32(ctx->r19 << 1);
L_800B6AE4:
    // 0x800B6AE4: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x800B6AE8: lh          $t6, -0x6810($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X6810));
    // 0x800B6AEC: lw          $t5, 0x98($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X98));
    // 0x800B6AF0: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800B6AF4: addiu       $t7, $t7, 0x61A8
    ctx->r15 = ADD32(ctx->r15, 0X61A8);
    // 0x800B6AF8: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x800B6AFC: lh          $v1, 0x8($s1)
    ctx->r3 = S32(MEM_H(ctx->r17, 0X8));
    // 0x800B6B00: lh          $t8, 0xA($s1)
    ctx->r24 = S32(MEM_H(ctx->r17, 0XA));
    // 0x800B6B04: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x800B6B08: addu        $s5, $t8, $v1
    ctx->r21 = ADD32(ctx->r24, ctx->r3);
    // 0x800B6B0C: slt         $at, $v1, $s5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x800B6B10: beq         $at, $zero, L_800B6BB8
    if (ctx->r1 == 0) {
        // 0x800B6B14: or          $s4, $v1, $zero
        ctx->r20 = ctx->r3 | 0;
            goto L_800B6BB8;
    }
    // 0x800B6B14: or          $s4, $v1, $zero
    ctx->r20 = ctx->r3 | 0;
    // 0x800B6B18: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x800B6B1C: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x800B6B20: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B6B24: addu        $s0, $t9, $t7
    ctx->r16 = ADD32(ctx->r25, ctx->r15);
L_800B6B28:
    // 0x800B6B28: lh          $t6, 0x8($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X8));
    // 0x800B6B2C: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800B6B30: addiu       $t8, $t8, 0x61A8
    ctx->r24 = ADD32(ctx->r24, 0X61A8);
    // 0x800B6B34: sll         $t5, $t6, 3
    ctx->r13 = S32(ctx->r14 << 3);
    // 0x800B6B38: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x800B6B3C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B6B40: addu        $a1, $t5, $t8
    ctx->r5 = ADD32(ctx->r13, ctx->r24);
    // 0x800B6B44: lw          $t9, 0x0($a1)
    ctx->r25 = S32(MEM_W(ctx->r5, 0X0));
    // 0x800B6B48: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800B6B4C: lw          $t6, 0x4($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X4));
    // 0x800B6B50: lw          $t5, 0x4($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800B6B54: subu        $s1, $t9, $t7
    ctx->r17 = SUB32(ctx->r25, ctx->r15);
    // 0x800B6B58: multu       $s1, $s1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B6B5C: subu        $s2, $t6, $t5
    ctx->r18 = SUB32(ctx->r14, ctx->r13);
    // 0x800B6B60: mflo        $t8
    ctx->r24 = lo;
    // 0x800B6B64: nop

    // 0x800B6B68: nop

    // 0x800B6B6C: multu       $s2, $s2
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B6B70: mflo        $t9
    ctx->r25 = lo;
    // 0x800B6B74: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x800B6B78: jal         0x80092164
    // 0x800B6B7C: nop

    ksqrt(rdram, ctx);
        goto after_20;
    // 0x800B6B7C: nop

    after_20:
    // 0x800B6B80: lw          $t6, 0x98($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X98));
    // 0x800B6B84: lh          $t7, 0xC($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0XC));
    // 0x800B6B88: slt         $at, $s6, $v0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B6B8C: lw          $t5, 0x0($t6)
    ctx->r13 = S32(MEM_W(ctx->r14, 0X0));
    // 0x800B6B90: bnel        $t7, $t5, L_800B6BAC
    if (ctx->r15 != ctx->r13) {
        // 0x800B6B94: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_800B6BAC;
    }
    goto skip_22;
    // 0x800B6B94: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_22:
    // 0x800B6B98: beql        $at, $zero, L_800B6BAC
    if (ctx->r1 == 0) {
        // 0x800B6B9C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_800B6BAC;
    }
    goto skip_23;
    // 0x800B6B9C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_23:
    // 0x800B6BA0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800B6BA4: or          $s3, $s4, $zero
    ctx->r19 = ctx->r20 | 0;
    // 0x800B6BA8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_800B6BAC:
    // 0x800B6BAC: slt         $at, $s4, $s5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x800B6BB0: bne         $at, $zero, L_800B6B28
    if (ctx->r1 != 0) {
        // 0x800B6BB4: addiu       $s0, $s0, 0x24
        ctx->r16 = ADD32(ctx->r16, 0X24);
            goto L_800B6B28;
    }
    // 0x800B6BB4: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
L_800B6BB8:
    // 0x800B6BB8: addiu       $v1, $zero, 0x24
    ctx->r3 = ADD32(0, 0X24);
    // 0x800B6BBC: multu       $s3, $v1
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B6BC0: lw          $t8, 0x94($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X94));
    // 0x800B6BC4: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x800B6BC8: addiu       $v0, $v0, 0x61A8
    ctx->r2 = ADD32(ctx->r2, 0X61A8);
    // 0x800B6BCC: sw          $s3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r19;
    // 0x800B6BD0: mflo        $t9
    ctx->r25 = lo;
    // 0x800B6BD4: addu        $s0, $v0, $t9
    ctx->r16 = ADD32(ctx->r2, ctx->r25);
    // 0x800B6BD8: lh          $t6, 0x8($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X8));
    // 0x800B6BDC: lw          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800B6BE0: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B6BE4: lw          $t6, 0x4($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800B6BE8: mflo        $t7
    ctx->r15 = lo;
    // 0x800B6BEC: addu        $s1, $v0, $t7
    ctx->r17 = ADD32(ctx->r2, ctx->r15);
    // 0x800B6BF0: lw          $t5, 0x0($s1)
    ctx->r13 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800B6BF4: lw          $t9, 0x4($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800B6BF8: subu        $a0, $t5, $t8
    ctx->r4 = SUB32(ctx->r13, ctx->r24);
    // 0x800B6BFC: jal         0x80092024
    // 0x800B6C00: subu        $a1, $t9, $t6
    ctx->r5 = SUB32(ctx->r25, ctx->r14);
    getangle(rdram, ctx);
        goto after_21;
    // 0x800B6C00: subu        $a1, $t9, $t6
    ctx->r5 = SUB32(ctx->r25, ctx->r14);
    after_21:
    // 0x800B6C04: lh          $t5, 0x8($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X8));
    // 0x800B6C08: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800B6C0C: addiu       $t9, $t9, 0x61A8
    ctx->r25 = ADD32(ctx->r25, 0X61A8);
    // 0x800B6C10: sll         $t8, $t5, 3
    ctx->r24 = S32(ctx->r13 << 3);
    // 0x800B6C14: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x800B6C18: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B6C1C: addu        $s1, $t8, $t9
    ctx->r17 = ADD32(ctx->r24, ctx->r25);
    // 0x800B6C20: lw          $t7, 0x0($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800B6C24: lw          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800B6C28: addiu       $v1, $v0, 0x600
    ctx->r3 = ADD32(ctx->r2, 0X600);
    // 0x800B6C2C: addiu       $t9, $v1, 0x200
    ctx->r25 = ADD32(ctx->r3, 0X200);
    // 0x800B6C30: addu        $t5, $t6, $t7
    ctx->r13 = ADD32(ctx->r14, ctx->r15);
    // 0x800B6C34: sra         $t8, $t5, 1
    ctx->r24 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800B6C38: andi        $t6, $t9, 0x7FF
    ctx->r14 = ctx->r25 & 0X7FF;
    // 0x800B6C3C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800B6C40: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x800B6C44: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x800B6C48: lh          $t5, -0x9A0($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, -0X9A0));
    // 0x800B6C4C: lw          $t7, 0x7C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X7C));
    // 0x800B6C50: sra         $t9, $t5, 8
    ctx->r25 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800B6C54: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x800B6C58: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800B6C5C: lw          $t9, 0x4($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800B6C60: lw          $t5, 0x4($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800B6C64: andi        $t7, $v1, 0x7FF
    ctx->r15 = ctx->r3 & 0X7FF;
    // 0x800B6C68: addu        $t8, $t5, $t9
    ctx->r24 = ADD32(ctx->r13, ctx->r25);
    // 0x800B6C6C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x800B6C70: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x800B6C74: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x800B6C78: lh          $t9, -0x9A0($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X9A0));
    // 0x800B6C7C: lw          $t5, 0x78($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800B6C80: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800B6C84: sra         $t8, $t9, 8
    ctx->r24 = S32(SIGNED(ctx->r25) >> 8);
    // 0x800B6C88: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800B6C8C: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800B6C90: lw          $t9, 0x98($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X98));
    // 0x800B6C94: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800B6C98: lw          $t8, 0x0($t9)
    ctx->r24 = S32(MEM_W(ctx->r25, 0X0));
    // 0x800B6C9C: lw          $t9, 0x74($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X74));
    // 0x800B6CA0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800B6CA4: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x800B6CA8: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800B6CAC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800B6CB0: lw          $t7, -0x1984($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X1984));
    // 0x800B6CB4: addiu       $t5, $t7, -0x2000
    ctx->r13 = ADD32(ctx->r15, -0X2000);
    // 0x800B6CB8: b           L_800B6CD8
    // 0x800B6CBC: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
        goto L_800B6CD8;
    // 0x800B6CBC: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
L_800B6CC0:
    // 0x800B6CC0: sll         $t8, $s4, 1
    ctx->r24 = S32(ctx->r20 << 1);
L_800B6CC4:
    // 0x800B6CC4: lui         $s4, 0x8027
    ctx->r20 = S32(0X8027 << 16);
    // 0x800B6CC8: addu        $s4, $s4, $t8
    ctx->r20 = ADD32(ctx->r20, ctx->r24);
    // 0x800B6CCC: lh          $s4, 0x4FA0($s4)
    ctx->r20 = S32(MEM_H(ctx->r20, 0X4FA0));
    // 0x800B6CD0: bgezl       $s4, L_800B6940
    if (SIGNED(ctx->r20) >= 0) {
        // 0x800B6CD4: sll         $t7, $s4, 2
        ctx->r15 = S32(ctx->r20 << 2);
            goto L_800B6940;
    }
    goto skip_24;
    // 0x800B6CD4: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    skip_24:
L_800B6CD8:
    // 0x800B6CD8: lw          $t6, 0x94($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X94));
    // 0x800B6CDC: lw          $t5, 0xD8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XD8));
    // 0x800B6CE0: lw          $t7, 0x98($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X98));
    // 0x800B6CE4: lw          $v1, 0x0($t6)
    ctx->r3 = S32(MEM_W(ctx->r14, 0X0));
    // 0x800B6CE8: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x800B6CEC: bltzl       $v1, L_800B6D00
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B6CF0: lw          $t8, 0x8C($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0X8C));
            goto L_800B6D00;
    }
    goto skip_25;
    // 0x800B6CF0: lw          $t8, 0x8C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X8C));
    skip_25:
    // 0x800B6CF4: b           L_800B6D1C
    // 0x800B6CF8: lw          $v0, 0x0($t7)
    ctx->r2 = S32(MEM_W(ctx->r15, 0X0));
        goto L_800B6D1C;
    // 0x800B6CF8: lw          $v0, 0x0($t7)
    ctx->r2 = S32(MEM_W(ctx->r15, 0X0));
    // 0x800B6CFC: lw          $t8, 0x8C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X8C));
L_800B6D00:
    // 0x800B6D00: slt         $at, $t9, $s7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x800B6D04: sw          $t9, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r25;
    // 0x800B6D08: addiu       $t6, $t8, 0x2
    ctx->r14 = ADD32(ctx->r24, 0X2);
    // 0x800B6D0C: bne         $at, $zero, L_800B6340
    if (ctx->r1 != 0) {
        // 0x800B6D10: sw          $t6, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r14;
            goto L_800B6340;
    }
    // 0x800B6D10: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    // 0x800B6D14: lw          $t7, 0x98($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X98));
    // 0x800B6D18: lw          $v0, 0x0($t7)
    ctx->r2 = S32(MEM_W(ctx->r15, 0X0));
L_800B6D1C:
    // 0x800B6D1C: bltz        $v0, L_800B6D2C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B6D20: lw          $t5, 0xA4($sp)
        ctx->r13 = S32(MEM_W(ctx->r29, 0XA4));
            goto L_800B6D2C;
    }
    // 0x800B6D20: lw          $t5, 0xA4($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800B6D24: bgez        $v1, L_800B7068
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800B6D28: lw          $t9, 0xA4($sp)
        ctx->r25 = S32(MEM_W(ctx->r29, 0XA4));
            goto L_800B7068;
    }
    // 0x800B6D28: lw          $t9, 0xA4($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XA4));
L_800B6D2C:
    // 0x800B6D2C: lui         $t8, 0x8028
    ctx->r24 = S32(0X8028 << 16);
    // 0x800B6D30: lui         $t6, 0x8028
    ctx->r14 = S32(0X8028 << 16);
    // 0x800B6D34: addiu       $t6, $t6, -0x6890
    ctx->r14 = ADD32(ctx->r14, -0X6890);
    // 0x800B6D38: addiu       $t8, $t8, -0x6840
    ctx->r24 = ADD32(ctx->r24, -0X6840);
    // 0x800B6D3C: addu        $s7, $t5, $t8
    ctx->r23 = ADD32(ctx->r13, ctx->r24);
    // 0x800B6D40: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x800B6D44: lw          $t6, 0x0($s7)
    ctx->r14 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800B6D48: lui         $t7, 0x8028
    ctx->r15 = S32(0X8028 << 16);
    // 0x800B6D4C: addiu       $t7, $t7, -0x6880
    ctx->r15 = ADD32(ctx->r15, -0X6880);
    // 0x800B6D50: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800B6D54: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x800B6D58: bgez        $t6, L_800B6F0C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B6D5C: sw          $t9, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r25;
            goto L_800B6F0C;
    }
    // 0x800B6D5C: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x800B6D60: lui         $s1, 0x802B
    ctx->r17 = S32(0X802B << 16);
    // 0x800B6D64: addiu       $s1, $s1, -0x5378
    ctx->r17 = ADD32(ctx->r17, -0X5378);
    // 0x800B6D68: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B6D6C: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x800B6D70: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_800B6D74:
    // 0x800B6D74: bne         $s3, $s0, L_800B6D84
    if (ctx->r19 != ctx->r16) {
        // 0x800B6D78: lw          $t9, 0xA8($sp)
        ctx->r25 = S32(MEM_W(ctx->r29, 0XA8));
            goto L_800B6D84;
    }
    // 0x800B6D78: lw          $t9, 0xA8($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800B6D7C: b           L_800B6DBC
    // 0x800B6D80: lh          $s4, 0x288($t9)
    ctx->r20 = S32(MEM_H(ctx->r25, 0X288));
        goto L_800B6DBC;
    // 0x800B6D80: lh          $s4, 0x288($t9)
    ctx->r20 = S32(MEM_H(ctx->r25, 0X288));
L_800B6D84:
    // 0x800B6D84: jal         0x8009800C
    // 0x800B6D88: nop

    krand2(rdram, ctx);
        goto after_22;
    // 0x800B6D88: nop

    after_22:
    // 0x800B6D8C: lh          $t5, 0x0($s1)
    ctx->r13 = S32(MEM_H(ctx->r17, 0X0));
    // 0x800B6D90: div         $zero, $v0, $t5
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r13)));
    // 0x800B6D94: mfhi        $s4
    ctx->r20 = hi;
    // 0x800B6D98: bne         $t5, $zero, L_800B6DA4
    if (ctx->r13 != 0) {
        // 0x800B6D9C: nop
    
            goto L_800B6DA4;
    }
    // 0x800B6D9C: nop

    // 0x800B6DA0: break       7
    do_break(2148232608);
L_800B6DA4:
    // 0x800B6DA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B6DA8: bne         $t5, $at, L_800B6DBC
    if (ctx->r13 != ctx->r1) {
        // 0x800B6DAC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B6DBC;
    }
    // 0x800B6DAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B6DB0: bne         $v0, $at, L_800B6DBC
    if (ctx->r2 != ctx->r1) {
        // 0x800B6DB4: nop
    
            goto L_800B6DBC;
    }
    // 0x800B6DB4: nop

    // 0x800B6DB8: break       6
    do_break(2148232632);
L_800B6DBC:
    // 0x800B6DBC: sll         $t7, $s4, 1
    ctx->r15 = S32(ctx->r20 << 1);
    // 0x800B6DC0: lui         $t1, 0x8027
    ctx->r9 = S32(0X8027 << 16);
    // 0x800B6DC4: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x800B6DC8: lh          $t1, 0x2330($t1)
    ctx->r9 = S32(MEM_H(ctx->r9, 0X2330));
    // 0x800B6DCC: bltz        $t1, L_800B6F00
    if (SIGNED(ctx->r9) < 0) {
        // 0x800B6DD0: sw          $t1, 0x130($sp)
        MEM_W(0X130, ctx->r29) = ctx->r9;
            goto L_800B6F00;
    }
    // 0x800B6DD0: sw          $t1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r9;
    // 0x800B6DD4: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
L_800B6DD8:
    // 0x800B6DD8: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x800B6DDC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B6DE0: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x800B6DE4: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x800B6DE8: addiu       $t6, $t6, 0x6BA8
    ctx->r14 = ADD32(ctx->r14, 0X6BA8);
    // 0x800B6DEC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B6DF0: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x800B6DF4: lbu         $t9, 0x27($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X27);
    // 0x800B6DF8: blezl       $t9, L_800B6EE8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800B6DFC: sll         $t5, $t1, 1
        ctx->r13 = S32(ctx->r9 << 1);
            goto L_800B6EE8;
    }
    goto skip_26;
    // 0x800B6DFC: sll         $t5, $t1, 1
    ctx->r13 = S32(ctx->r9 << 1);
    skip_26:
    // 0x800B6E00: lbu         $t5, 0x28($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X28);
    // 0x800B6E04: blezl       $t5, L_800B6EE8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800B6E08: sll         $t5, $t1, 1
        ctx->r13 = S32(ctx->r9 << 1);
            goto L_800B6EE8;
    }
    goto skip_27;
    // 0x800B6E08: sll         $t5, $t1, 1
    ctx->r13 = S32(ctx->r9 << 1);
    skip_27:
    // 0x800B6E0C: sw          $t1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r9;
    // 0x800B6E10: lw          $a0, 0x138($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X138));
    // 0x800B6E14: jal         0x800B4FEC
    // 0x800B6E18: lh          $a1, 0xE($v0)
    ctx->r5 = S32(MEM_H(ctx->r2, 0XE));
    getspritescore(rdram, ctx);
        goto after_23;
    // 0x800B6E18: lh          $a1, 0xE($v0)
    ctx->r5 = S32(MEM_H(ctx->r2, 0XE));
    after_23:
    // 0x800B6E1C: bgtz        $v0, L_800B6E2C
    if (SIGNED(ctx->r2) > 0) {
        // 0x800B6E20: lw          $t1, 0x130($sp)
        ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
            goto L_800B6E2C;
    }
    // 0x800B6E20: lw          $t1, 0x130($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
    // 0x800B6E24: b           L_800B6EE4
    // 0x800B6E28: lw          $t1, 0x130($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
        goto L_800B6EE4;
    // 0x800B6E28: lw          $t1, 0x130($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
L_800B6E2C:
    // 0x800B6E2C: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x800B6E30: subu        $t7, $t7, $t1
    ctx->r15 = SUB32(ctx->r15, ctx->r9);
    // 0x800B6E34: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B6E38: subu        $t7, $t7, $t1
    ctx->r15 = SUB32(ctx->r15, ctx->r9);
    // 0x800B6E3C: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x800B6E40: addiu       $t8, $t8, 0x6BA8
    ctx->r24 = ADD32(ctx->r24, 0X6BA8);
    // 0x800B6E44: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B6E48: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800B6E4C: lw          $t5, 0x8($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X8));
    // 0x800B6E50: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800B6E54: lw          $t9, 0x4($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X4));
    // 0x800B6E58: lw          $a2, 0x11C($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X11C));
    // 0x800B6E5C: addiu       $t7, $t5, -0x400
    ctx->r15 = ADD32(ctx->r13, -0X400);
    // 0x800B6E60: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800B6E64: lw          $a0, 0x124($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X124));
    // 0x800B6E68: lw          $a1, 0x120($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X120));
    // 0x800B6E6C: lh          $a3, 0xE6($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XE6));
    // 0x800B6E70: sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    // 0x800B6E74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800B6E78: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800B6E7C: jal         0x80092E68
    // 0x800B6E80: addiu       $a2, $a2, -0x2000
    ctx->r6 = ADD32(ctx->r6, -0X2000);
    cansee(rdram, ctx);
        goto after_24;
    // 0x800B6E80: addiu       $a2, $a2, -0x2000
    ctx->r6 = ADD32(ctx->r6, -0X2000);
    after_24:
    // 0x800B6E84: beq         $v0, $zero, L_800B6EE0
    if (ctx->r2 == 0) {
        // 0x800B6E88: lw          $t1, 0x130($sp)
        ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
            goto L_800B6EE0;
    }
    // 0x800B6E88: lw          $t1, 0x130($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
    // 0x800B6E8C: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x800B6E90: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x800B6E94: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B6E98: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x800B6E9C: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x800B6EA0: addiu       $t6, $t6, 0x6BA8
    ctx->r14 = ADD32(ctx->r14, 0X6BA8);
    // 0x800B6EA4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B6EA8: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x800B6EAC: lw          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800B6EB0: lw          $t5, 0x7C($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X7C));
    // 0x800B6EB4: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800B6EB8: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800B6EBC: lw          $t8, 0x78($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800B6EC0: lw          $t7, 0x4($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X4));
    // 0x800B6EC4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800B6EC8: lw          $t9, 0xA4($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800B6ECC: lw          $t6, 0x8($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X8));
    // 0x800B6ED0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800B6ED4: sw          $t6, -0x6870($at)
    MEM_W(-0X6870, ctx->r1) = ctx->r14;
    // 0x800B6ED8: b           L_800B6F10
    // 0x800B6EDC: sw          $t1, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r9;
        goto L_800B6F10;
    // 0x800B6EDC: sw          $t1, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r9;
L_800B6EE0:
    // 0x800B6EE0: lw          $t1, 0x130($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
L_800B6EE4:
    // 0x800B6EE4: sll         $t5, $t1, 1
    ctx->r13 = S32(ctx->r9 << 1);
L_800B6EE8:
    // 0x800B6EE8: lui         $t1, 0x8027
    ctx->r9 = S32(0X8027 << 16);
    // 0x800B6EEC: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x800B6EF0: lh          $t1, 0x4FA0($t1)
    ctx->r9 = S32(MEM_H(ctx->r9, 0X4FA0));
    // 0x800B6EF4: bgezl       $t1, L_800B6DD8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800B6EF8: sll         $t8, $t1, 2
        ctx->r24 = S32(ctx->r9 << 2);
            goto L_800B6DD8;
    }
    goto skip_28;
    // 0x800B6EF8: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    skip_28:
    // 0x800B6EFC: sw          $t1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r9;
L_800B6F00:
    // 0x800B6F00: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800B6F04: bne         $s3, $s6, L_800B6D74
    if (ctx->r19 != ctx->r22) {
        // 0x800B6F08: nop
    
            goto L_800B6D74;
    }
    // 0x800B6F08: nop

L_800B6F0C:
    // 0x800B6F0C: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
L_800B6F10:
    // 0x800B6F10: lw          $t7, 0x7C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X7C));
    // 0x800B6F14: lw          $t6, 0x124($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X124));
    // 0x800B6F18: lw          $t8, 0x78($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800B6F1C: lw          $v0, 0x0($t7)
    ctx->r2 = S32(MEM_W(ctx->r15, 0X0));
    // 0x800B6F20: lw          $t9, 0x120($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X120));
    // 0x800B6F24: lw          $v1, 0x0($t8)
    ctx->r3 = S32(MEM_W(ctx->r24, 0X0));
    // 0x800B6F28: subu        $s1, $v0, $t6
    ctx->r17 = SUB32(ctx->r2, ctx->r14);
    // 0x800B6F2C: multu       $s1, $s1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B6F30: subu        $s2, $v1, $t9
    ctx->r18 = SUB32(ctx->r3, ctx->r25);
    // 0x800B6F34: sw          $v0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r2;
    // 0x800B6F38: sw          $v1, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r3;
    // 0x800B6F3C: mflo        $t5
    ctx->r13 = lo;
    // 0x800B6F40: nop

    // 0x800B6F44: nop

    // 0x800B6F48: multu       $s2, $s2
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B6F4C: mflo        $t7
    ctx->r15 = lo;
    // 0x800B6F50: addu        $a0, $t5, $t7
    ctx->r4 = ADD32(ctx->r13, ctx->r15);
    // 0x800B6F54: jal         0x80092164
    // 0x800B6F58: nop

    ksqrt(rdram, ctx);
        goto after_25;
    // 0x800B6F58: nop

    after_25:
    // 0x800B6F5C: beq         $v0, $zero, L_800B7664
    if (ctx->r2 == 0) {
        // 0x800B6F60: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800B7664;
    }
    // 0x800B6F60: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800B6F64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B6F68: jal         0x80092024
    // 0x800B6F6C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    getangle(rdram, ctx);
        goto after_26;
    // 0x800B6F6C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_26:
    // 0x800B6F70: addiu       $fp, $zero, 0x7FF
    ctx->r30 = ADD32(0, 0X7FF);
    // 0x800B6F74: multu       $s1, $fp
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B6F78: lw          $t0, 0x13C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800B6F7C: addiu       $s3, $zero, -0x7F
    ctx->r19 = ADD32(0, -0X7F);
    // 0x800B6F80: lh          $t8, 0x2($t0)
    ctx->r24 = S32(MEM_H(ctx->r8, 0X2));
    // 0x800B6F84: lh          $t7, 0x4($t0)
    ctx->r15 = S32(MEM_H(ctx->r8, 0X4));
    // 0x800B6F88: mflo        $t6
    ctx->r14 = lo;
    // 0x800B6F8C: nop

    // 0x800B6F90: nop

    // 0x800B6F94: div         $zero, $t6, $s5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r21)));
    // 0x800B6F98: mflo        $t9
    ctx->r25 = lo;
    // 0x800B6F9C: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x800B6FA0: bne         $s5, $zero, L_800B6FAC
    if (ctx->r21 != 0) {
        // 0x800B6FA4: nop
    
            goto L_800B6FAC;
    }
    // 0x800B6FA4: nop

    // 0x800B6FA8: break       7
    do_break(2148233128);
L_800B6FAC:
    // 0x800B6FAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B6FB0: bne         $s5, $at, L_800B6FC4
    if (ctx->r21 != ctx->r1) {
        // 0x800B6FB4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B6FC4;
    }
    // 0x800B6FB4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B6FB8: bne         $t6, $at, L_800B6FC4
    if (ctx->r14 != ctx->r1) {
        // 0x800B6FBC: nop
    
            goto L_800B6FC4;
    }
    // 0x800B6FBC: nop

    // 0x800B6FC0: break       6
    do_break(2148233152);
L_800B6FC4:
    // 0x800B6FC4: multu       $s2, $fp
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B6FC8: sh          $t5, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r13;
    // 0x800B6FCC: mflo        $t6
    ctx->r14 = lo;
    // 0x800B6FD0: nop

    // 0x800B6FD4: nop

    // 0x800B6FD8: div         $zero, $t6, $s5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r21)));
    // 0x800B6FDC: mflo        $t8
    ctx->r24 = lo;
    // 0x800B6FE0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B6FE4: sh          $t9, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r25;
    // 0x800B6FE8: lw          $t5, 0xE8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XE8));
    // 0x800B6FEC: bne         $s5, $zero, L_800B6FF8
    if (ctx->r21 != 0) {
        // 0x800B6FF0: nop
    
            goto L_800B6FF8;
    }
    // 0x800B6FF0: nop

    // 0x800B6FF4: break       7
    do_break(2148233204);
L_800B6FF8:
    // 0x800B6FF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B6FFC: bne         $s5, $at, L_800B7010
    if (ctx->r21 != ctx->r1) {
        // 0x800B7000: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B7010;
    }
    // 0x800B7000: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B7004: bne         $t6, $at, L_800B7010
    if (ctx->r14 != ctx->r1) {
        // 0x800B7008: nop
    
            goto L_800B7010;
    }
    // 0x800B7008: nop

    // 0x800B700C: break       6
    do_break(2148233228);
L_800B7010:
    // 0x800B7010: subu        $a0, $v0, $t5
    ctx->r4 = SUB32(ctx->r2, ctx->r13);
    // 0x800B7014: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    // 0x800B7018: andi        $t6, $a0, 0x7FF
    ctx->r14 = ctx->r4 & 0X7FF;
    // 0x800B701C: addiu       $a0, $t6, -0x400
    ctx->r4 = ADD32(ctx->r14, -0X400);
    // 0x800B7020: sra         $t7, $a0, 3
    ctx->r15 = S32(SIGNED(ctx->r4) >> 3);
    // 0x800B7024: slti        $at, $t7, -0x7E
    ctx->r1 = SIGNED(ctx->r15) < -0X7E ? 1 : 0;
    // 0x800B7028: bne         $at, $zero, L_800B7038
    if (ctx->r1 != 0) {
        // 0x800B702C: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800B7038;
    }
    // 0x800B702C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800B7030: b           L_800B7038
    // 0x800B7034: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
        goto L_800B7038;
    // 0x800B7034: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
L_800B7038:
    // 0x800B7038: slti        $at, $s3, 0x7F
    ctx->r1 = SIGNED(ctx->r19) < 0X7F ? 1 : 0;
    // 0x800B703C: beq         $at, $zero, L_800B7060
    if (ctx->r1 == 0) {
        // 0x800B7040: addiu       $t8, $zero, 0x7F
        ctx->r24 = ADD32(0, 0X7F);
            goto L_800B7060;
    }
    // 0x800B7040: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x800B7044: slti        $at, $a0, -0x7E
    ctx->r1 = SIGNED(ctx->r4) < -0X7E ? 1 : 0;
    // 0x800B7048: bne         $at, $zero, L_800B7058
    if (ctx->r1 != 0) {
        // 0x800B704C: addiu       $v1, $zero, -0x7F
        ctx->r3 = ADD32(0, -0X7F);
            goto L_800B7058;
    }
    // 0x800B704C: addiu       $v1, $zero, -0x7F
    ctx->r3 = ADD32(0, -0X7F);
    // 0x800B7050: b           L_800B7058
    // 0x800B7054: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_800B7058;
    // 0x800B7054: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800B7058:
    // 0x800B7058: b           L_800B7084
    // 0x800B705C: sb          $v1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r3;
        goto L_800B7084;
    // 0x800B705C: sb          $v1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r3;
L_800B7060:
    // 0x800B7060: b           L_800B7084
    // 0x800B7064: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
        goto L_800B7084;
    // 0x800B7064: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
L_800B7068:
    // 0x800B7068: lui         $t5, 0x8028
    ctx->r13 = S32(0X8028 << 16);
    // 0x800B706C: addiu       $t5, $t5, -0x6840
    ctx->r13 = ADD32(ctx->r13, -0X6840);
    // 0x800B7070: addu        $s7, $t9, $t5
    ctx->r23 = ADD32(ctx->r25, ctx->r13);
    // 0x800B7074: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800B7078: sw          $t6, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r14;
    // 0x800B707C: addiu       $fp, $zero, 0x7FF
    ctx->r30 = ADD32(0, 0X7FF);
    // 0x800B7080: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
L_800B7084:
    // 0x800B7084: lw          $t7, 0xA8($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800B7088: lui         $s1, 0x1
    ctx->r17 = S32(0X1 << 16);
    // 0x800B708C: ori         $s1, $s1, 0x1
    ctx->r17 = ctx->r17 | 0X1;
    // 0x800B7090: lw          $t8, 0x214($t7)
    ctx->r24 = S32(MEM_W(ctx->r15, 0X214));
    // 0x800B7094: addiu       $s0, $sp, 0xCA
    ctx->r16 = ADD32(ctx->r29, 0XCA);
    // 0x800B7098: addiu       $s2, $sp, 0x10C
    ctx->r18 = ADD32(ctx->r29, 0X10C);
    // 0x800B709C: sw          $t8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r24;
    // 0x800B70A0: lw          $t9, 0x218($t7)
    ctx->r25 = S32(MEM_W(ctx->r15, 0X218));
    // 0x800B70A4: addiu       $s3, $sp, 0x108
    ctx->r19 = ADD32(ctx->r29, 0X108);
    // 0x800B70A8: addiu       $s5, $sp, 0x104
    ctx->r21 = ADD32(ctx->r29, 0X104);
    // 0x800B70AC: sw          $t9, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r25;
    // 0x800B70B0: lw          $t5, 0x21C($t7)
    ctx->r13 = S32(MEM_W(ctx->r15, 0X21C));
    // 0x800B70B4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800B70B8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800B70BC: sw          $t5, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r13;
    // 0x800B70C0: lh          $t6, 0x288($t7)
    ctx->r14 = S32(MEM_H(ctx->r15, 0X288));
    // 0x800B70C4: addiu       $t5, $zero, 0xA4
    ctx->r13 = ADD32(0, 0XA4);
    // 0x800B70C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B70CC: sh          $t6, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r14;
    // 0x800B70D0: lw          $t8, 0x24C($t7)
    ctx->r24 = S32(MEM_W(ctx->r15, 0X24C));
    // 0x800B70D4: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x800B70D8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800B70DC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800B70E0: lw          $t9, 0x250($t7)
    ctx->r25 = S32(MEM_W(ctx->r15, 0X250));
    // 0x800B70E4: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x800B70E8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800B70EC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800B70F0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800B70F4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800B70F8: jal         0x800958C8
    // 0x800B70FC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    clipmove(rdram, ctx);
        goto after_27;
    // 0x800B70FC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_27:
    // 0x800B7100: bne         $v0, $zero, L_800B7174
    if (ctx->r2 != 0) {
        // 0x800B7104: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_800B7174;
    }
    // 0x800B7104: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800B7108: lw          $t7, 0xA8($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800B710C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B7110: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800B7114: lw          $t9, 0x214($t7)
    ctx->r25 = S32(MEM_W(ctx->r15, 0X214));
    // 0x800B7118: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800B711C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800B7120: sw          $t9, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r25;
    // 0x800B7124: lw          $t5, 0x218($t7)
    ctx->r13 = S32(MEM_W(ctx->r15, 0X218));
    // 0x800B7128: sw          $t5, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r13;
    // 0x800B712C: lw          $t6, 0x21C($t7)
    ctx->r14 = S32(MEM_W(ctx->r15, 0X21C));
    // 0x800B7130: addiu       $t8, $t6, 0x1800
    ctx->r24 = ADD32(ctx->r14, 0X1800);
    // 0x800B7134: sw          $t8, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r24;
    // 0x800B7138: lh          $t9, 0x288($t7)
    ctx->r25 = S32(MEM_H(ctx->r15, 0X288));
    // 0x800B713C: addiu       $t8, $zero, 0xA4
    ctx->r24 = ADD32(0, 0XA4);
    // 0x800B7140: sh          $t9, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r25;
    // 0x800B7144: lw          $t5, 0x24C($t7)
    ctx->r13 = S32(MEM_W(ctx->r15, 0X24C));
    // 0x800B7148: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x800B714C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800B7150: lw          $t6, 0x250($t7)
    ctx->r14 = S32(MEM_W(ctx->r15, 0X250));
    // 0x800B7154: addiu       $t5, $zero, 0x400
    ctx->r13 = ADD32(0, 0X400);
    // 0x800B7158: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800B715C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800B7160: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800B7164: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800B7168: jal         0x800958C8
    // 0x800B716C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    clipmove(rdram, ctx);
        goto after_28;
    // 0x800B716C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_28:
    // 0x800B7170: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_800B7174:
    // 0x800B7174: beq         $v0, $zero, L_800B746C
    if (ctx->r2 == 0) {
        // 0x800B7178: ori         $s5, $zero, 0x8000
        ctx->r21 = 0 | 0X8000;
            goto L_800B746C;
    }
    // 0x800B7178: ori         $s5, $zero, 0x8000
    ctx->r21 = 0 | 0X8000;
    // 0x800B717C: lw          $t7, 0xA4($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800B7180: lui         $t6, 0x8028
    ctx->r14 = S32(0X8028 << 16);
    // 0x800B7184: addiu       $t6, $t6, -0x6820
    ctx->r14 = ADD32(ctx->r14, -0X6820);
    // 0x800B7188: addu        $s3, $t7, $t6
    ctx->r19 = ADD32(ctx->r15, ctx->r14);
    // 0x800B718C: lw          $t8, 0x0($s3)
    ctx->r24 = S32(MEM_W(ctx->r19, 0X0));
    // 0x800B7190: lw          $t6, 0x114($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X114));
    // 0x800B7194: lw          $t7, 0x124($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X124));
    // 0x800B7198: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B719C: lw          $t8, 0x120($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X120));
    // 0x800B71A0: lw          $t5, 0x118($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X118));
    // 0x800B71A4: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x800B71A8: andi        $t9, $v0, 0xC000
    ctx->r25 = ctx->r2 & 0XC000;
    // 0x800B71AC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800B71B0: sw          $zero, 0x130($sp)
    MEM_W(0X130, ctx->r29) = 0;
    // 0x800B71B4: subu        $s2, $t6, $t8
    ctx->r18 = SUB32(ctx->r14, ctx->r24);
    // 0x800B71B8: bne         $s5, $t9, L_800B726C
    if (ctx->r21 != ctx->r25) {
        // 0x800B71BC: subu        $s1, $t5, $t7
        ctx->r17 = SUB32(ctx->r13, ctx->r15);
            goto L_800B726C;
    }
    // 0x800B71BC: subu        $s1, $t5, $t7
    ctx->r17 = SUB32(ctx->r13, ctx->r15);
    // 0x800B71C0: andi        $t5, $v0, 0xE7F
    ctx->r13 = ctx->r2 & 0XE7F;
    // 0x800B71C4: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x800B71C8: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800B71CC: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x800B71D0: addiu       $t6, $t6, 0x61A8
    ctx->r14 = ADD32(ctx->r14, 0X61A8);
    // 0x800B71D4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B71D8: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800B71DC: sw          $t1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r9;
    // 0x800B71E0: lh          $t9, 0xC($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0XC));
    // 0x800B71E4: andi        $t5, $s4, 0xE7F
    ctx->r13 = ctx->r20 & 0XE7F;
    // 0x800B71E8: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x800B71EC: bltz        $t9, L_800B726C
    if (SIGNED(ctx->r25) < 0) {
        // 0x800B71F0: addu        $t7, $t7, $t5
        ctx->r15 = ADD32(ctx->r15, ctx->r13);
            goto L_800B726C;
    }
    // 0x800B71F0: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800B71F4: lw          $t8, 0xA8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800B71F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B71FC: addu        $s0, $t7, $t6
    ctx->r16 = ADD32(ctx->r15, ctx->r14);
    // 0x800B7200: lh          $a0, 0xC($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0XC));
    // 0x800B7204: lw          $a1, 0x214($t8)
    ctx->r5 = S32(MEM_W(ctx->r24, 0X214));
    // 0x800B7208: jal         0x80098FB4
    // 0x800B720C: lw          $a2, 0x218($t8)
    ctx->r6 = S32(MEM_W(ctx->r24, 0X218));
    getflorzofslope(rdram, ctx);
        goto after_29;
    // 0x800B720C: lw          $a2, 0x218($t8)
    ctx->r6 = S32(MEM_W(ctx->r24, 0X218));
    after_29:
    // 0x800B7210: lw          $t9, 0xA8($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800B7214: lw          $t1, 0x130($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
    // 0x800B7218: lw          $t5, 0x21C($t9)
    ctx->r13 = S32(MEM_W(ctx->r25, 0X21C));
    // 0x800B721C: ori         $t6, $t1, 0x1
    ctx->r14 = ctx->r9 | 0X1;
    // 0x800B7220: addiu       $t7, $t5, 0x1800
    ctx->r15 = ADD32(ctx->r13, 0X1800);
    // 0x800B7224: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B7228: bnel        $at, $zero, L_800B7238
    if (ctx->r1 != 0) {
        // 0x800B722C: lw          $t8, 0xA8($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0XA8));
            goto L_800B7238;
    }
    goto skip_29;
    // 0x800B722C: lw          $t8, 0xA8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XA8));
    skip_29:
    // 0x800B7230: sw          $t6, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r14;
    // 0x800B7234: lw          $t8, 0xA8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XA8));
L_800B7238:
    // 0x800B7238: lh          $a0, 0xC($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0XC));
    // 0x800B723C: lw          $a1, 0x214($t8)
    ctx->r5 = S32(MEM_W(ctx->r24, 0X214));
    // 0x800B7240: jal         0x80098E64
    // 0x800B7244: lw          $a2, 0x218($t8)
    ctx->r6 = S32(MEM_W(ctx->r24, 0X218));
    getceilzofslope(rdram, ctx);
        goto after_30;
    // 0x800B7244: lw          $a2, 0x218($t8)
    ctx->r6 = S32(MEM_W(ctx->r24, 0X218));
    after_30:
    // 0x800B7248: lw          $t9, 0xA8($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800B724C: lw          $t1, 0x130($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
    // 0x800B7250: lw          $t5, 0x21C($t9)
    ctx->r13 = S32(MEM_W(ctx->r25, 0X21C));
    // 0x800B7254: ori         $t6, $t1, 0x2
    ctx->r14 = ctx->r9 | 0X2;
    // 0x800B7258: addiu       $t7, $t5, -0x1800
    ctx->r15 = ADD32(ctx->r13, -0X1800);
    // 0x800B725C: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B7260: bnel        $at, $zero, L_800B7270
    if (ctx->r1 != 0) {
        // 0x800B7264: andi        $s0, $s4, 0xC000
        ctx->r16 = ctx->r20 & 0XC000;
            goto L_800B7270;
    }
    goto skip_30;
    // 0x800B7264: andi        $s0, $s4, 0xC000
    ctx->r16 = ctx->r20 & 0XC000;
    skip_30:
    // 0x800B7268: sw          $t6, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r14;
L_800B726C:
    // 0x800B726C: andi        $s0, $s4, 0xC000
    ctx->r16 = ctx->r20 & 0XC000;
L_800B7270:
    // 0x800B7270: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x800B7274: bne         $s0, $at, L_800B7280
    if (ctx->r16 != ctx->r1) {
        // 0x800B7278: lw          $t1, 0x130($sp)
        ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
            goto L_800B7280;
    }
    // 0x800B7278: lw          $t1, 0x130($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
    // 0x800B727C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800B7280:
    // 0x800B7280: andi        $t8, $t1, 0x1
    ctx->r24 = ctx->r9 & 0X1;
    // 0x800B7284: beq         $t8, $zero, L_800B72AC
    if (ctx->r24 == 0) {
        // 0x800B7288: sw          $t1, 0x130($sp)
        MEM_W(0X130, ctx->r29) = ctx->r9;
            goto L_800B72AC;
    }
    // 0x800B7288: sw          $t1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r9;
    // 0x800B728C: lw          $t9, 0x0($s3)
    ctx->r25 = S32(MEM_W(ctx->r19, 0X0));
    // 0x800B7290: sw          $t1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r9;
    // 0x800B7294: lw          $v0, 0x13C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800B7298: bnel        $s6, $t9, L_800B72B0
    if (ctx->r22 != ctx->r25) {
        // 0x800B729C: lw          $t1, 0x130($sp)
        ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
            goto L_800B72B0;
    }
    goto skip_31;
    // 0x800B729C: lw          $t1, 0x130($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
    skip_31:
    // 0x800B72A0: lw          $t5, 0x8($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X8));
    // 0x800B72A4: ori         $t7, $t5, 0x1
    ctx->r15 = ctx->r13 | 0X1;
    // 0x800B72A8: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
L_800B72AC:
    // 0x800B72AC: lw          $t1, 0x130($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X130));
L_800B72B0:
    // 0x800B72B0: lw          $v0, 0x13C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800B72B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B72B8: andi        $t6, $t1, 0x2
    ctx->r14 = ctx->r9 & 0X2;
    // 0x800B72BC: beq         $t6, $zero, L_800B72D0
    if (ctx->r14 == 0) {
        // 0x800B72C0: nop
    
            goto L_800B72D0;
    }
    // 0x800B72C0: nop

    // 0x800B72C4: lw          $t8, 0x8($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X8));
    // 0x800B72C8: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x800B72CC: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
L_800B72D0:
    // 0x800B72D0: jal         0x80092024
    // 0x800B72D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    getangle(rdram, ctx);
        goto after_31;
    // 0x800B72D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_31:
    // 0x800B72D8: bne         $s5, $s0, L_800B7324
    if (ctx->r21 != ctx->r16) {
        // 0x800B72DC: addiu       $a2, $zero, 0x24
        ctx->r6 = ADD32(0, 0X24);
            goto L_800B7324;
    }
    // 0x800B72DC: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // 0x800B72E0: andi        $t5, $s4, 0xE7F
    ctx->r13 = ctx->r20 & 0XE7F;
    // 0x800B72E4: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B72E8: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x800B72EC: addiu       $v1, $v1, 0x61A8
    ctx->r3 = ADD32(ctx->r3, 0X61A8);
    // 0x800B72F0: mflo        $t7
    ctx->r15 = lo;
    // 0x800B72F4: addu        $s0, $v1, $t7
    ctx->r16 = ADD32(ctx->r3, ctx->r15);
    // 0x800B72F8: lh          $t6, 0x8($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X8));
    // 0x800B72FC: lw          $t5, 0x0($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800B7300: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B7304: lw          $t6, 0x4($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800B7308: mflo        $t8
    ctx->r24 = lo;
    // 0x800B730C: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x800B7310: lw          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800B7314: lw          $t7, 0x4($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X4));
    // 0x800B7318: subu        $a0, $t9, $t5
    ctx->r4 = SUB32(ctx->r25, ctx->r13);
    // 0x800B731C: jal         0x80092024
    // 0x800B7320: subu        $a1, $t7, $t6
    ctx->r5 = SUB32(ctx->r15, ctx->r14);
    getangle(rdram, ctx);
        goto after_32;
    // 0x800B7320: subu        $a1, $t7, $t6
    ctx->r5 = SUB32(ctx->r15, ctx->r14);
    after_32:
L_800B7324:
    // 0x800B7324: lw          $t8, 0x138($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X138));
    // 0x800B7328: addiu       $at, $zero, 0x349C
    ctx->r1 = ADD32(0, 0X349C);
    // 0x800B732C: lui         $t5, 0x802B
    ctx->r13 = S32(0X802B << 16);
    // 0x800B7330: multu       $t8, $at
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B7334: lw          $t5, -0x5370($t5)
    ctx->r13 = S32(MEM_W(ctx->r13, -0X5370));
    // 0x800B7338: lw          $a1, 0x13C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800B733C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B7340: mflo        $t9
    ctx->r25 = lo;
    // 0x800B7344: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x800B7348: sll         $t6, $t7, 6
    ctx->r14 = S32(ctx->r15 << 6);
    // 0x800B734C: andi        $t8, $t6, 0x7FF
    ctx->r24 = ctx->r14 & 0X7FF;
    // 0x800B7350: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x800B7354: addiu       $t5, $t5, -0x9A0
    ctx->r13 = ADD32(ctx->r13, -0X9A0);
    // 0x800B7358: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B735C: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800B7360: sw          $t7, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r15;
    // 0x800B7364: addiu       $t8, $t7, 0x1095
    ctx->r24 = ADD32(ctx->r15, 0X1095);
    // 0x800B7368: lh          $s4, 0x0($t6)
    ctx->r20 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800B736C: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x800B7370: andi        $t6, $t9, 0x7FF
    ctx->r14 = ctx->r25 & 0X7FF;
    // 0x800B7374: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x800B7378: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x800B737C: lh          $t6, 0x0($t9)
    ctx->r14 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800B7380: addiu       $t8, $t7, 0x1A59
    ctx->r24 = ADD32(ctx->r15, 0X1A59);
    // 0x800B7384: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800B7388: addu        $s4, $s4, $t6
    ctx->r20 = ADD32(ctx->r20, ctx->r14);
    // 0x800B738C: andi        $t6, $t9, 0x7FF
    ctx->r14 = ctx->r25 & 0X7FF;
    // 0x800B7390: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x800B7394: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x800B7398: lh          $t6, 0x0($t9)
    ctx->r14 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800B739C: addiu       $t8, $t7, 0x3D45
    ctx->r24 = ADD32(ctx->r15, 0X3D45);
    // 0x800B73A0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800B73A4: addu        $s4, $s4, $t6
    ctx->r20 = ADD32(ctx->r20, ctx->r14);
    // 0x800B73A8: andi        $t6, $t9, 0x7FF
    ctx->r14 = ctx->r25 & 0X7FF;
    // 0x800B73AC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800B73B0: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x800B73B4: lh          $t9, 0x0($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X0));
    // 0x800B73B8: addiu       $t7, $v0, 0x400
    ctx->r15 = ADD32(ctx->r2, 0X400);
    // 0x800B73BC: andi        $t8, $t7, 0x7FF
    ctx->r24 = ctx->r15 & 0X7FF;
    // 0x800B73C0: addu        $s4, $s4, $t9
    ctx->r20 = ADD32(ctx->r20, ctx->r25);
    // 0x800B73C4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B73C8: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x800B73CC: lh          $t8, 0x0($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800B73D0: lh          $t6, 0x2($a1)
    ctx->r14 = S32(MEM_H(ctx->r5, 0X2));
    // 0x800B73D4: multu       $t8, $s4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B73D8: lh          $t8, 0x4($a1)
    ctx->r24 = S32(MEM_H(ctx->r5, 0X4));
    // 0x800B73DC: mflo        $t9
    ctx->r25 = lo;
    // 0x800B73E0: sra         $t5, $t9, 17
    ctx->r13 = S32(SIGNED(ctx->r25) >> 17);
    // 0x800B73E4: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x800B73E8: addiu       $t9, $v0, 0x200
    ctx->r25 = ADD32(ctx->r2, 0X200);
    // 0x800B73EC: andi        $t6, $t9, 0x7FF
    ctx->r14 = ctx->r25 & 0X7FF;
    // 0x800B73F0: sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
    // 0x800B73F4: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800B73F8: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x800B73FC: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800B7400: lh          $t7, -0x9A0($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, -0X9A0));
    // 0x800B7404: multu       $t7, $s4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B7408: mflo        $t9
    ctx->r25 = lo;
    // 0x800B740C: sra         $t6, $t9, 17
    ctx->r14 = S32(SIGNED(ctx->r25) >> 17);
    // 0x800B7410: addu        $t5, $t8, $t6
    ctx->r13 = ADD32(ctx->r24, ctx->r14);
    // 0x800B7414: sh          $t5, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r13;
    // 0x800B7418: lw          $v1, 0x0($s3)
    ctx->r3 = S32(MEM_W(ctx->r19, 0X0));
    // 0x800B741C: andi        $t7, $v1, 0x1F
    ctx->r15 = ctx->r3 & 0X1F;
    // 0x800B7420: bnel        $t7, $at, L_800B7440
    if (ctx->r15 != ctx->r1) {
        // 0x800B7424: slti        $at, $v1, 0x21
        ctx->r1 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
            goto L_800B7440;
    }
    goto skip_32;
    // 0x800B7424: slti        $at, $v1, 0x21
    ctx->r1 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
    skip_32:
    // 0x800B7428: lw          $t9, 0x8($a1)
    ctx->r25 = S32(MEM_W(ctx->r5, 0X8));
    // 0x800B742C: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x800B7430: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x800B7434: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x800B7438: lw          $v1, 0x0($s3)
    ctx->r3 = S32(MEM_W(ctx->r19, 0X0));
    // 0x800B743C: slti        $at, $v1, 0x21
    ctx->r1 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
L_800B7440:
    // 0x800B7440: bne         $at, $zero, L_800B7464
    if (ctx->r1 != 0) {
        // 0x800B7444: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_800B7464;
    }
    // 0x800B7444: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B7448: lw          $t5, 0x98($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X98));
    // 0x800B744C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800B7450: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800B7454: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x800B7458: lw          $t9, 0x94($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X94));
    // 0x800B745C: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800B7460: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_800B7464:
    // 0x800B7464: b           L_800B747C
    // 0x800B7468: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
        goto L_800B747C;
    // 0x800B7468: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
L_800B746C:
    // 0x800B746C: lw          $t6, 0xA4($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800B7470: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800B7474: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B7478: sw          $zero, -0x6820($at)
    MEM_W(-0X6820, ctx->r1) = 0;
L_800B747C:
    // 0x800B747C: lw          $t5, 0x98($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X98));
    // 0x800B7480: lw          $t9, 0x94($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X94));
    // 0x800B7484: lw          $t7, 0x0($t5)
    ctx->r15 = S32(MEM_W(ctx->r13, 0X0));
    // 0x800B7488: bltzl       $t7, L_800B7668
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B748C: lw          $ra, 0x64($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
            goto L_800B7668;
    }
    goto skip_33;
    // 0x800B748C: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
    skip_33:
    // 0x800B7490: lw          $t8, 0x0($t9)
    ctx->r24 = S32(MEM_W(ctx->r25, 0X0));
    // 0x800B7494: lw          $t6, 0xA4($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800B7498: lui         $v0, 0x8028
    ctx->r2 = S32(0X8028 << 16);
    // 0x800B749C: bltz        $t8, L_800B7664
    if (SIGNED(ctx->r24) < 0) {
        // 0x800B74A0: addu        $v0, $v0, $t6
        ctx->r2 = ADD32(ctx->r2, ctx->r14);
            goto L_800B7664;
    }
    // 0x800B74A0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800B74A4: lw          $v0, -0x6890($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, -0X6890));
    // 0x800B74A8: lw          $t5, 0x124($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X124));
    // 0x800B74AC: lui         $v1, 0x8028
    ctx->r3 = S32(0X8028 << 16);
    // 0x800B74B0: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x800B74B4: subu        $s1, $v0, $t5
    ctx->r17 = SUB32(ctx->r2, ctx->r13);
    // 0x800B74B8: multu       $s1, $s1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B74BC: lw          $v1, -0x6880($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, -0X6880));
    // 0x800B74C0: lw          $t7, 0x120($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X120));
    // 0x800B74C4: subu        $s2, $v1, $t7
    ctx->r18 = SUB32(ctx->r3, ctx->r15);
    // 0x800B74C8: mflo        $t9
    ctx->r25 = lo;
    // 0x800B74CC: nop

    // 0x800B74D0: nop

    // 0x800B74D4: multu       $s2, $s2
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B74D8: mflo        $t8
    ctx->r24 = lo;
    // 0x800B74DC: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    // 0x800B74E0: jal         0x80092164
    // 0x800B74E4: nop

    ksqrt(rdram, ctx);
        goto after_33;
    // 0x800B74E4: nop

    after_33:
    // 0x800B74E8: beq         $v0, $zero, L_800B7664
    if (ctx->r2 == 0) {
        // 0x800B74EC: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800B7664;
    }
    // 0x800B74EC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800B74F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B74F4: jal         0x80092024
    // 0x800B74F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    getangle(rdram, ctx);
        goto after_34;
    // 0x800B74F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_34:
    // 0x800B74FC: lw          $t6, 0x94($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X94));
    // 0x800B7500: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800B7504: lw          $v1, 0x0($t6)
    ctx->r3 = S32(MEM_W(ctx->r14, 0X0));
    // 0x800B7508: bltz        $v1, L_800B756C
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B750C: nop
    
            goto L_800B756C;
    }
    // 0x800B750C: nop

    // 0x800B7510: slti        $at, $s5, 0x1000
    ctx->r1 = SIGNED(ctx->r21) < 0X1000 ? 1 : 0;
    // 0x800B7514: beq         $at, $zero, L_800B756C
    if (ctx->r1 == 0) {
        // 0x800B7518: nop
    
            goto L_800B756C;
    }
    // 0x800B7518: nop

    // 0x800B751C: addiu       $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
    // 0x800B7520: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B7524: lui         $a3, 0x8022
    ctx->r7 = S32(0X8022 << 16);
    // 0x800B7528: addiu       $a3, $a3, 0x61A8
    ctx->r7 = ADD32(ctx->r7, 0X61A8);
    // 0x800B752C: mflo        $t5
    ctx->r13 = lo;
    // 0x800B7530: addu        $v0, $a3, $t5
    ctx->r2 = ADD32(ctx->r7, ctx->r13);
    // 0x800B7534: lh          $t7, 0x8($v0)
    ctx->r15 = S32(MEM_H(ctx->r2, 0X8));
    // 0x800B7538: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800B753C: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B7540: lw          $t7, 0x4($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X4));
    // 0x800B7544: mflo        $t9
    ctx->r25 = lo;
    // 0x800B7548: addu        $a2, $a3, $t9
    ctx->r6 = ADD32(ctx->r7, ctx->r25);
    // 0x800B754C: lw          $t8, 0x0($a2)
    ctx->r24 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800B7550: lw          $t5, 0x4($a2)
    ctx->r13 = S32(MEM_W(ctx->r6, 0X4));
    // 0x800B7554: subu        $a0, $t8, $t6
    ctx->r4 = SUB32(ctx->r24, ctx->r14);
    // 0x800B7558: jal         0x80092024
    // 0x800B755C: subu        $a1, $t5, $t7
    ctx->r5 = SUB32(ctx->r13, ctx->r15);
    getangle(rdram, ctx);
        goto after_35;
    // 0x800B755C: subu        $a1, $t5, $t7
    ctx->r5 = SUB32(ctx->r13, ctx->r15);
    after_35:
    // 0x800B7560: addiu       $s3, $v0, 0x600
    ctx->r19 = ADD32(ctx->r2, 0X600);
    // 0x800B7564: andi        $t9, $s3, 0x7FF
    ctx->r25 = ctx->r19 & 0X7FF;
    // 0x800B7568: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
L_800B756C:
    // 0x800B756C: multu       $s1, $fp
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B7570: lw          $t8, 0x13C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800B7574: lh          $t6, 0x2($t8)
    ctx->r14 = S32(MEM_H(ctx->r24, 0X2));
    // 0x800B7578: mflo        $t5
    ctx->r13 = lo;
    // 0x800B757C: nop

    // 0x800B7580: nop

    // 0x800B7584: div         $zero, $t5, $s5
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r21)));
    // 0x800B7588: mflo        $t7
    ctx->r15 = lo;
    // 0x800B758C: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800B7590: bne         $s5, $zero, L_800B759C
    if (ctx->r21 != 0) {
        // 0x800B7594: nop
    
            goto L_800B759C;
    }
    // 0x800B7594: nop

    // 0x800B7598: break       7
    do_break(2148234648);
L_800B759C:
    // 0x800B759C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B75A0: bne         $s5, $at, L_800B75B4
    if (ctx->r21 != ctx->r1) {
        // 0x800B75A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B75B4;
    }
    // 0x800B75A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B75A8: bne         $t5, $at, L_800B75B4
    if (ctx->r13 != ctx->r1) {
        // 0x800B75AC: nop
    
            goto L_800B75B4;
    }
    // 0x800B75AC: nop

    // 0x800B75B0: break       6
    do_break(2148234672);
L_800B75B4:
    // 0x800B75B4: multu       $s2, $fp
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B75B8: lh          $t5, 0x4($t8)
    ctx->r13 = S32(MEM_H(ctx->r24, 0X4));
    // 0x800B75BC: sh          $t9, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r25;
    // 0x800B75C0: mflo        $t6
    ctx->r14 = lo;
    // 0x800B75C4: nop

    // 0x800B75C8: nop

    // 0x800B75CC: div         $zero, $t6, $s5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r21)));
    // 0x800B75D0: mflo        $t7
    ctx->r15 = lo;
    // 0x800B75D4: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x800B75D8: bne         $s5, $zero, L_800B75E4
    if (ctx->r21 != 0) {
        // 0x800B75DC: nop
    
            goto L_800B75E4;
    }
    // 0x800B75DC: nop

    // 0x800B75E0: break       7
    do_break(2148234720);
L_800B75E4:
    // 0x800B75E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B75E8: bne         $s5, $at, L_800B75FC
    if (ctx->r21 != ctx->r1) {
        // 0x800B75EC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B75FC;
    }
    // 0x800B75EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B75F0: bne         $t6, $at, L_800B75FC
    if (ctx->r14 != ctx->r1) {
        // 0x800B75F4: nop
    
            goto L_800B75FC;
    }
    // 0x800B75F4: nop

    // 0x800B75F8: break       6
    do_break(2148234744);
L_800B75FC:
    // 0x800B75FC: sh          $t9, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r25;
    // 0x800B7600: lw          $t6, 0xE8($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XE8));
    // 0x800B7604: lw          $t9, 0x13C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800B7608: subu        $v0, $s3, $t6
    ctx->r2 = SUB32(ctx->r19, ctx->r14);
    // 0x800B760C: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // 0x800B7610: andi        $t5, $v0, 0x7FF
    ctx->r13 = ctx->r2 & 0X7FF;
    // 0x800B7614: addiu       $v0, $t5, -0x400
    ctx->r2 = ADD32(ctx->r13, -0X400);
    // 0x800B7618: sra         $t7, $v0, 3
    ctx->r15 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800B761C: slti        $at, $t7, -0x7E
    ctx->r1 = SIGNED(ctx->r15) < -0X7E ? 1 : 0;
    // 0x800B7620: bne         $at, $zero, L_800B7630
    if (ctx->r1 != 0) {
        // 0x800B7624: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800B7630;
    }
    // 0x800B7624: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800B7628: b           L_800B7634
    // 0x800B762C: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
        goto L_800B7634;
    // 0x800B762C: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
L_800B7630:
    // 0x800B7630: addiu       $s3, $zero, -0x7F
    ctx->r19 = ADD32(0, -0X7F);
L_800B7634:
    // 0x800B7634: slti        $at, $s3, 0x7F
    ctx->r1 = SIGNED(ctx->r19) < 0X7F ? 1 : 0;
    // 0x800B7638: beq         $at, $zero, L_800B765C
    if (ctx->r1 == 0) {
        // 0x800B763C: lw          $t6, 0x13C($sp)
        ctx->r14 = S32(MEM_W(ctx->r29, 0X13C));
            goto L_800B765C;
    }
    // 0x800B763C: lw          $t6, 0x13C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800B7640: slti        $at, $v0, -0x7E
    ctx->r1 = SIGNED(ctx->r2) < -0X7E ? 1 : 0;
    // 0x800B7644: bne         $at, $zero, L_800B7654
    if (ctx->r1 != 0) {
        // 0x800B7648: addiu       $v1, $zero, -0x7F
        ctx->r3 = ADD32(0, -0X7F);
            goto L_800B7654;
    }
    // 0x800B7648: addiu       $v1, $zero, -0x7F
    ctx->r3 = ADD32(0, -0X7F);
    // 0x800B764C: b           L_800B7654
    // 0x800B7650: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800B7654;
    // 0x800B7650: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800B7654:
    // 0x800B7654: b           L_800B7664
    // 0x800B7658: sb          $v1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r3;
        goto L_800B7664;
    // 0x800B7658: sb          $v1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r3;
L_800B765C:
    // 0x800B765C: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x800B7660: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
L_800B7664:
    // 0x800B7664: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
L_800B7668:
    // 0x800B7668: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800B766C: lw          $s1, 0x44($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800B7670: lw          $s2, 0x48($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800B7674: lw          $s3, 0x4C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800B7678: lw          $s4, 0x50($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800B767C: lw          $s5, 0x54($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X54));
    // 0x800B7680: lw          $s6, 0x58($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X58));
    // 0x800B7684: lw          $s7, 0x5C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800B7688: lw          $fp, 0x60($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800B768C: jr          $ra
    // 0x800B7690: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    return;
    // 0x800B7690: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    // 0x800B7694: nop

    // 0x800B7698: nop

    // 0x800B769C: nop

;}
RECOMP_FUNC void _collectPVoices(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C24F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C24FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C2500: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C2504: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C2508: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C250C: lw          $s0, 0x14($a0)
    ctx->r16 = S32(MEM_W(ctx->r4, 0X14));
    // 0x800C2510: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800C2514: addiu       $s2, $a0, 0x4
    ctx->r18 = ADD32(ctx->r4, 0X4);
    // 0x800C2518: beql        $s0, $zero, L_800C2544
    if (ctx->r16 == 0) {
        // 0x800C251C: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800C2544;
    }
    goto skip_0;
    // 0x800C251C: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_0:
L_800C2520:
    // 0x800C2520: jal         0x800BF770
    // 0x800C2524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800C2524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800C2528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C252C: jal         0x800BF7A0
    // 0x800C2530: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_1;
    // 0x800C2530: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800C2534: lw          $s0, 0x14($s1)
    ctx->r16 = S32(MEM_W(ctx->r17, 0X14));
    // 0x800C2538: bne         $s0, $zero, L_800C2520
    if (ctx->r16 != 0) {
        // 0x800C253C: nop
    
            goto L_800C2520;
    }
    // 0x800C253C: nop

    // 0x800C2540: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_800C2544:
    // 0x800C2544: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800C2548: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800C254C: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800C2550: jr          $ra
    // 0x800C2554: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C2554: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006768C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006768C: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80067690: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x80067694: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80067698: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x8006769C: addiu       $t0, $t0, 0x61A8
    ctx->r8 = ADD32(ctx->r8, 0X61A8);
    // 0x800676A0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800676A4: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x800676A8: lbu         $t1, 0x1E($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X1E);
    // 0x800676AC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800676B0: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800676B4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800676B8: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x800676BC: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x800676C0: lui         $a3, 0x8027
    ctx->r7 = S32(0X8027 << 16);
    // 0x800676C4: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x800676C8: addiu       $a3, $a3, -0x1418
    ctx->r7 = ADD32(ctx->r7, -0X1418);
    // 0x800676CC: addiu       $a2, $a2, -0x1414
    ctx->r6 = ADD32(ctx->r6, -0X1414);
    // 0x800676D0: addiu       $v1, $v1, -0x141C
    ctx->r3 = ADD32(ctx->r3, -0X141C);
    // 0x800676D4: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800676D8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800676DC: lwc1        $f0, -0x145C($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X145C));
    // 0x800676E0: bgez        $t1, L_800676F8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800676E4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800676F8;
    }
    // 0x800676E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800676E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800676EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800676F0: nop

    // 0x800676F4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800676F8:
    // 0x800676F8: div.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800676FC: lbu         $t2, 0x20($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X20);
    // 0x80067700: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067704: andi        $t9, $a1, 0x4
    ctx->r25 = ctx->r5 & 0X4;
    // 0x80067708: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8006770C: nop

    // 0x80067710: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80067714: bgez        $t2, L_80067728
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80067718: swc1        $f10, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
            goto L_80067728;
    }
    // 0x80067718: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x8006771C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067720: nop

    // 0x80067724: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80067728:
    // 0x80067728: div.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8006772C: lbu         $t3, 0x1F($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1F);
    // 0x80067730: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067734: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80067738: nop

    // 0x8006773C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80067740: bgez        $t3, L_80067754
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80067744: swc1        $f8, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
            goto L_80067754;
    }
    // 0x80067744: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x80067748: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8006774C: nop

    // 0x80067750: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80067754:
    // 0x80067754: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80067758: lwc1        $f4, -0x1458($at)
    ctx->f4.u32l = S32(MEM_W(ctx->r1, -0X1458));
    // 0x8006775C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80067760: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80067764: div.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80067768: andi        $t4, $a1, 0x100
    ctx->r12 = ctx->r5 & 0X100;
    // 0x8006776C: div.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80067770: beq         $t4, $zero, L_800677BC
    if (ctx->r12 == 0) {
        // 0x80067774: swc1        $f6, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
            goto L_800677BC;
    }
    // 0x80067774: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x80067778: lbu         $t5, 0x21($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X21);
    // 0x8006777C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80067780: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x80067784: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x80067788: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8006778C: addiu       $a0, $a0, -0x1410
    ctx->r4 = ADD32(ctx->r4, -0X1410);
    // 0x80067790: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80067794: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80067798: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x8006779C: lwc1        $f0, -0x1448($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X1448));
    // 0x800677A0: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800677A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800677A8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = S32(MEM_W(ctx->r4, 0X0));
    // 0x800677AC: div.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800677B0: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800677B4: b           L_80067814
    // 0x800677B8: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
        goto L_80067814;
    // 0x800677B8: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
L_800677BC:
    // 0x800677BC: lbu         $t8, 0x21($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X21);
    // 0x800677C0: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x800677C4: addiu       $a0, $a0, -0x1410
    ctx->r4 = ADD32(ctx->r4, -0X1410);
    // 0x800677C8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800677CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800677D0: bgez        $t8, L_800677E4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800677D4: cvt.s.w     $f10, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800677E4;
    }
    // 0x800677D4: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800677D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800677DC: nop

    // 0x800677E0: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800677E4:
    // 0x800677E4: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x800677E8: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x800677EC: lwc1        $f0, -0x1448($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X1448));
    // 0x800677F0: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800677F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800677F8: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = S32(MEM_W(ctx->r4, 0X0));
    // 0x800677FC: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = S32(MEM_W(ctx->r7, 0X0));
    // 0x80067800: div.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80067804: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x80067808: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x8006780C: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80067810: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
L_80067814:
    // 0x80067814: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = S32(MEM_W(ctx->r4, 0X0));
    // 0x80067818: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x8006781C: addiu       $v0, $v0, -0x1420
    ctx->r2 = ADD32(ctx->r2, -0X1420);
    // 0x80067820: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80067824: bne         $t9, $at, L_80067850
    if (ctx->r25 != ctx->r1) {
        // 0x80067828: swc1        $f2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
            goto L_80067850;
    }
    // 0x80067828: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8006782C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80067830: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80067834: nop

    // 0x80067838: mul.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8006783C: nop

    // 0x80067840: mul.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80067844: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80067848: b           L_80067864
    // 0x8006784C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_80067864;
    // 0x8006784C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_80067850:
    // 0x80067850: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80067854: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80067858: nop

    // 0x8006785C: mul.s       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80067860: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_80067864:
    // 0x80067864: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = S32(MEM_W(ctx->r6, 0X0));
    // 0x80067868: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006786C: mul.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80067870: swc1        $f0, -0x1444($at)
    MEM_W(-0X1444, ctx->r1) = ctx->f0.u32l;
    // 0x80067874: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80067878: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006787C: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = S32(MEM_W(ctx->r3, 0X0));
    // 0x80067880: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80067884: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80067888: nop

    // 0x8006788C: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80067890: add.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80067894: jr          $ra
    // 0x80067898: swc1        $f16, -0x1440($at)
    MEM_W(-0X1440, ctx->r1) = ctx->f16.u32l;
    return;
    // 0x80067898: swc1        $f16, -0x1440($at)
    MEM_W(-0X1440, ctx->r1) = ctx->f16.u32l;
;}
RECOMP_FUNC void controllervibstopall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800519E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800519E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800519E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800519EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800519F0:
    // 0x800519F0: jal         0x800519C4
    // 0x800519F4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800519C4(rdram, ctx);
        goto after_0;
    // 0x800519F4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x800519F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800519FC: andi        $t6, $s0, 0xFFFF
    ctx->r14 = ctx->r16 & 0XFFFF;
    // 0x80051A00: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80051A04: bne         $at, $zero, L_800519F0
    if (ctx->r1 != 0) {
        // 0x80051A08: or          $s0, $t6, $zero
        ctx->r16 = ctx->r14 | 0;
            goto L_800519F0;
    }
    // 0x80051A08: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80051A0C: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80051A10: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80051A14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80051A18: jr          $ra
    // 0x80051A1C: nop

    return;
    // 0x80051A1C: nop

;}
RECOMP_FUNC void alSynAllocFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC750: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CC754: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x800CC758: sra         $t6, $t0, 16
    ctx->r14 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800CC75C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CC760: sll         $s1, $t6, 2
    ctx->r17 = S32(ctx->r14 << 2);
    // 0x800CC764: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CC768: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CC76C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800CC770: addu        $s1, $s1, $t6
    ctx->r17 = ADD32(ctx->r17, ctx->r14);
    // 0x800CC774: lw          $t7, 0x34($a0)
    ctx->r15 = S32(MEM_W(ctx->r4, 0X34));
    // 0x800CC778: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x800CC77C: subu        $s1, $s1, $t6
    ctx->r17 = SUB32(ctx->r17, ctx->r14);
    // 0x800CC780: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CC784: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x800CC788: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800CC78C: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    // 0x800CC790: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800CC794: jal         0x800CC310
    // 0x800CC798: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    alFxNew(rdram, ctx);
        goto after_0;
    // 0x800CC798: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x800CC79C: lw          $t8, 0x34($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X34));
    // 0x800CC7A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800CC7A4: addu        $a2, $t8, $s1
    ctx->r6 = ADD32(ctx->r24, ctx->r17);
    // 0x800CC7A8: jal         0x800D0ED4
    // 0x800CC7AC: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    alFxParam(rdram, ctx);
        goto after_1;
    // 0x800CC7AC: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    after_1:
    // 0x800CC7B0: lw          $t9, 0x34($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X34));
    // 0x800CC7B4: lw          $a0, 0x30($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X30));
    // 0x800CC7B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800CC7BC: addu        $a2, $t9, $s1
    ctx->r6 = ADD32(ctx->r25, ctx->r17);
    // 0x800CC7C0: jal         0x800CC7F0
    // 0x800CC7C4: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    alMainBusParam(rdram, ctx);
        goto after_2;
    // 0x800CC7C4: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    after_2:
    // 0x800CC7C8: lw          $t2, 0x34($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X34));
    // 0x800CC7CC: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800CC7D0: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800CC7D4: addu        $v0, $t2, $s1
    ctx->r2 = ADD32(ctx->r10, ctx->r17);
    // 0x800CC7D8: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800CC7DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CC7E0: jr          $ra
    // 0x800CC7E4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    return;
    // 0x800CC7E4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
;}
RECOMP_FUNC void ksgn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091A50: bgez        $a0, L_80091A60
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80091A54: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80091A60;
    }
    // 0x80091A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80091A58: jr          $ra
    // 0x80091A5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80091A5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80091A60:
    // 0x80091A60: jr          $ra
    // 0x80091A64: nop

    return;
    // 0x80091A64: nop

;}
RECOMP_FUNC void divscale30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800918CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800918D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800918D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800918D8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800918DC: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x800918E0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800918E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800918E8: jal         0x800BB834
    // 0x800918EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x800918EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800918F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800918F4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800918F8: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800918FC: jal         0x800BB89C
    // 0x80091900: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80091900: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x80091904: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80091908: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009190C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80091910: jr          $ra
    // 0x80091914: nop

    return;
    // 0x80091914: nop

;}
RECOMP_FUNC void func_8004F96C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F96C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8004F970: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004F974: beq         $t7, $zero, L_8004F998
    if (ctx->r15 == 0) {
        // 0x8004F978: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_8004F998;
    }
    // 0x8004F978: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8004F97C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004F980: addiu       $v0, $v0, 0x3778
    ctx->r2 = ADD32(ctx->r2, 0X3778);
    // 0x8004F984: lh          $t8, 0x0($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X0));
    // 0x8004F988: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F98C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8004F990: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8004F994: sh          $zero, 0x3774($at)
    MEM_H(0X3774, ctx->r1) = 0;
L_8004F998:
    // 0x8004F998: jr          $ra
    // 0x8004F99C: nop

    return;
    // 0x8004F99C: nop

;}
RECOMP_FUNC void stopsong(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800585D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800585D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800585DC: jal         0x80058348
    // 0x800585E0: nop

    func_80058348(rdram, ctx);
        goto after_0;
    // 0x800585E0: nop

    after_0:
    // 0x800585E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800585E8: beq         $v0, $at, L_8005861C
    if (ctx->r2 == ctx->r1) {
        // 0x800585EC: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8005861C;
    }
    // 0x800585EC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800585F0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800585F4: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800585F8: addiu       $t7, $t7, -0x5F08
    ctx->r15 = ADD32(ctx->r15, -0X5F08);
    // 0x800585FC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80058600: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80058604: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80058608: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x8005860C: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    // 0x80058610: addiu       $a0, $a0, -0x5FA0
    ctx->r4 = ADD32(ctx->r4, -0X5FA0);
    // 0x80058614: jal         0x800BB610
    // 0x80058618: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80058618: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_8005861C:
    // 0x8005861C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80058620: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80058624: jr          $ra
    // 0x80058628: nop

    return;
    // 0x80058628: nop

;}
RECOMP_FUNC void controllervibdisable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051910: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80051914: addiu       $a0, $a0, -0x4708
    ctx->r4 = ADD32(ctx->r4, -0X4708);
    // 0x80051918: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005191C:
    // 0x8005191C: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80051920: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051924: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x80051928: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x8005192C: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80051930: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80051934: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80051938: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x8005193C: bne         $at, $zero, L_8005191C
    if (ctx->r1 != 0) {
        // 0x80051940: sh          $zero, 0x2($v1)
        MEM_H(0X2, ctx->r3) = 0;
            goto L_8005191C;
    }
    // 0x80051940: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x80051944: jr          $ra
    // 0x80051948: nop

    return;
    // 0x80051948: nop

;}
RECOMP_FUNC void dmulscale1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800901E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800901E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800901EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800901F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800901F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800901F8: jal         0x800BB8F8
    // 0x800901FC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x800901FC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090200: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090204: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090208: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8009020C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090210: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090214: jal         0x800BB8F8
    // 0x80090218: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090218: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x8009021C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090220: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090224: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090228: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x8009022C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090230: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090234: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090238: jal         0x800BBA24
    // 0x8009023C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x8009023C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80090240: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090244: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090248: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009024C: jr          $ra
    // 0x80090250: nop

    return;
    // 0x80090250: nop

;}
RECOMP_FUNC void nsqrtasm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091A00: bgezl       $a0, L_80091A14
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80091A04: mtc1        $a0, $f4
        ctx->f4.u32l = ctx->r4;
            goto L_80091A14;
    }
    goto skip_0;
    // 0x80091A04: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    skip_0:
    // 0x80091A08: jr          $ra
    // 0x80091A0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80091A0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80091A10: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
L_80091A14:
    // 0x80091A14: nop

    // 0x80091A18: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80091A1C: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x80091A20: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80091A24: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80091A28: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80091A2C: nop

    // 0x80091A30: jr          $ra
    // 0x80091A34: nop

    return;
    // 0x80091A34: nop

;}
RECOMP_FUNC void displayweapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007351C: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x80073520: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x80073524: lh          $t6, 0xD2($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0XD2));
    // 0x80073528: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x8007352C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80073530: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80073534: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80073538: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007353C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80073540: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80073544: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80073548: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007354C: addiu       $t8, $t8, 0x5770
    ctx->r24 = ADD32(ctx->r24, 0X5770);
    // 0x80073550: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80073554: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x80073558: jal         0x80091A38
    // 0x8007355C: lh          $a0, 0x28A($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X28A));
    klabs(rdram, ctx);
        goto after_0;
    // 0x8007355C: lh          $a0, 0x28A($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X28A));
    after_0:
    // 0x80073560: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80073564: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80073568: lh          $t9, 0x2E0($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x8007356C: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x80073570: addiu       $t7, $t7, 0x6BA8
    ctx->r15 = ADD32(ctx->r15, 0X6BA8);
    // 0x80073574: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80073578: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x8007357C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80073580: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80073584: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80073588: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8007358C: lb          $a0, 0x24($v1)
    ctx->r4 = S32(MEM_B(ctx->r3, 0X24));
    // 0x80073590: mflo        $t4
    ctx->r12 = lo;
    // 0x80073594: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x80073598: slti        $at, $a0, 0x19
    ctx->r1 = SIGNED(ctx->r4) < 0X19 ? 1 : 0;
    // 0x8007359C: bnel        $at, $zero, L_800735AC
    if (ctx->r1 != 0) {
        // 0x800735A0: lh          $t8, 0x2BE($s0)
        ctx->r24 = S32(MEM_H(ctx->r16, 0X2BE));
            goto L_800735AC;
    }
    goto skip_0;
    // 0x800735A0: lh          $t8, 0x2BE($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2BE));
    skip_0:
    // 0x800735A4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800735A8: lh          $t8, 0x2BE($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2BE));
L_800735AC:
    // 0x800735AC: bgezl       $t8, L_80074C18
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800735B0: lw          $ra, 0x2C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
            goto L_80074C18;
    }
    goto skip_1;
    // 0x800735B0: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    skip_1:
    // 0x800735B4: lh          $t9, -0x54AC($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X54AC));
    // 0x800735B8: bgezl       $t9, L_80074C18
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800735BC: lw          $ra, 0x2C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
            goto L_80074C18;
    }
    goto skip_2;
    // 0x800735BC: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    skip_2:
    // 0x800735C0: lh          $t6, 0x2E2($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X2E2));
    // 0x800735C4: bgtzl       $t6, L_80074C18
    if (SIGNED(ctx->r14) > 0) {
        // 0x800735C8: lw          $ra, 0x2C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
            goto L_80074C18;
    }
    goto skip_3;
    // 0x800735C8: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    skip_3:
    // 0x800735CC: lbu         $t7, 0x25($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X25);
    // 0x800735D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800735D4: lh          $a1, 0xD2($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XD2));
    // 0x800735D8: beql        $t7, $at, L_800735F0
    if (ctx->r15 == ctx->r1) {
        // 0x800735DC: sb          $a0, 0xA9($sp)
        MEM_B(0XA9, ctx->r29) = ctx->r4;
            goto L_800735F0;
    }
    goto skip_4;
    // 0x800735DC: sb          $a0, 0xA9($sp)
    MEM_B(0XA9, ctx->r29) = ctx->r4;
    skip_4:
    // 0x800735E0: lh          $t8, 0x22($v1)
    ctx->r24 = S32(MEM_H(ctx->r3, 0X22));
    // 0x800735E4: blezl       $t8, L_80074C18
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800735E8: lw          $ra, 0x2C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
            goto L_80074C18;
    }
    goto skip_5;
    // 0x800735E8: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    skip_5:
    // 0x800735EC: sb          $a0, 0xA9($sp)
    MEM_B(0XA9, ctx->r29) = ctx->r4;
L_800735F0:
    // 0x800735F0: jal         0x80072A70
    // 0x800735F4: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    animatefist(rdram, ctx);
        goto after_1;
    // 0x800735F4: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    after_1:
    // 0x800735F8: bne         $v0, $zero, L_80074C14
    if (ctx->r2 != 0) {
        // 0x800735FC: lw          $t4, 0xC8($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
            goto L_80074C14;
    }
    // 0x800735FC: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80073600: lb          $a0, 0xA9($sp)
    ctx->r4 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073604: lh          $a1, 0xD2($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XD2));
    // 0x80073608: jal         0x80072DCC
    // 0x8007360C: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    animateknuckles(rdram, ctx);
        goto after_2;
    // 0x8007360C: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    after_2:
    // 0x80073610: bne         $v0, $zero, L_80074C14
    if (ctx->r2 != 0) {
        // 0x80073614: lw          $t4, 0xC8($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
            goto L_80074C14;
    }
    // 0x80073614: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80073618: lb          $a0, 0xA9($sp)
    ctx->r4 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x8007361C: lh          $a1, 0xD2($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XD2));
    // 0x80073620: jal         0x80073048
    // 0x80073624: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    animatetip(rdram, ctx);
        goto after_3;
    // 0x80073624: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    after_3:
    // 0x80073628: bne         $v0, $zero, L_80074C14
    if (ctx->r2 != 0) {
        // 0x8007362C: lw          $t4, 0xC8($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
            goto L_80074C14;
    }
    // 0x8007362C: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80073630: lb          $a0, 0xA9($sp)
    ctx->r4 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073634: lh          $a1, 0xD2($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XD2));
    // 0x80073638: jal         0x800731DC
    // 0x8007363C: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    animateaccess(rdram, ctx);
        goto after_4;
    // 0x8007363C: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    after_4:
    // 0x80073640: bne         $v0, $zero, L_80074C14
    if (ctx->r2 != 0) {
        // 0x80073644: lw          $t4, 0xC8($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
            goto L_80074C14;
    }
    // 0x80073644: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80073648: lb          $a0, 0xA9($sp)
    ctx->r4 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x8007364C: lh          $a1, 0xD2($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XD2));
    // 0x80073650: jal         0x80072C14
    // 0x80073654: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    animateknee(rdram, ctx);
        goto after_5;
    // 0x80073654: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    after_5:
    // 0x80073658: lh          $v1, 0x328($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X328));
    // 0x8007365C: lw          $a1, 0x270($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X270));
    // 0x80073660: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x80073664: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80073668: sra         $a2, $a1, 1
    ctx->r6 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8007366C: addiu       $t7, $a2, 0x200
    ctx->r15 = ADD32(ctx->r6, 0X200);
    // 0x80073670: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x80073674: andi        $t8, $t7, 0x7FF
    ctx->r24 = ctx->r15 & 0X7FF;
    // 0x80073678: addiu       $a3, $a3, -0x9A0
    ctx->r7 = ADD32(ctx->r7, -0X9A0);
    // 0x8007367C: addiu       $at, $zero, 0x600
    ctx->r1 = ADD32(0, 0X600);
    // 0x80073680: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80073684: mflo        $t9
    ctx->r25 = lo;
    // 0x80073688: subu        $t0, $t6, $t9
    ctx->r8 = SUB32(ctx->r14, ctx->r25);
    // 0x8007368C: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x80073690: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x80073694: lh          $t7, 0x0($t9)
    ctx->r15 = S32(MEM_H(ctx->r25, 0X0));
    // 0x80073698: addiu       $t6, $zero, 0x46
    ctx->r14 = ADD32(0, 0X46);
    // 0x8007369C: lh          $t9, 0x2D8($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2D8));
    // 0x800736A0: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x800736A4: lh          $t7, 0x2E0($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800736A8: mflo        $t8
    ctx->r24 = lo;
    // 0x800736AC: subu        $t1, $t6, $t8
    ctx->r9 = SUB32(ctx->r14, ctx->r24);
    // 0x800736B0: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800736B4: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x800736B8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800736BC: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x800736C0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800736C4: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x800736C8: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x800736CC: lbu         $t8, 0x6BCF($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X6BCF);
    // 0x800736D0: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x800736D4: addiu       $t0, $t0, -0x14
    ctx->r8 = ADD32(ctx->r8, -0X14);
    // 0x800736D8: slti        $at, $t8, 0x20
    ctx->r1 = SIGNED(ctx->r24) < 0X20 ? 1 : 0;
    // 0x800736DC: beq         $at, $zero, L_80073724
    if (ctx->r1 == 0) {
        // 0x800736E0: addiu       $t1, $t1, -0x3A
        ctx->r9 = ADD32(ctx->r9, -0X3A);
            goto L_80073724;
    }
    // 0x800736E0: addiu       $t1, $t1, -0x3A
    ctx->r9 = ADD32(ctx->r9, -0X3A);
    // 0x800736E4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800736E8: andi        $t7, $t9, 0x7FF
    ctx->r15 = ctx->r25 & 0X7FF;
    // 0x800736EC: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x800736F0: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x800736F4: lh          $a0, 0x0($t8)
    ctx->r4 = S32(MEM_H(ctx->r24, 0X0));
    // 0x800736F8: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    // 0x800736FC: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80073700: sra         $t9, $a0, 9
    ctx->r25 = S32(SIGNED(ctx->r4) >> 9);
    // 0x80073704: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80073708: jal         0x80091A38
    // 0x8007370C: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    klabs(rdram, ctx);
        goto after_6;
    // 0x8007370C: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    after_6:
    // 0x80073710: lw          $t0, 0xCC($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80073714: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80073718: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x8007371C: b           L_8007375C
    // 0x80073720: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
        goto L_8007375C;
    // 0x80073720: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
L_80073724:
    // 0x80073724: andi        $t7, $a2, 0x7FF
    ctx->r15 = ctx->r6 & 0X7FF;
    // 0x80073728: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8007372C: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x80073730: lh          $a0, 0x0($t8)
    ctx->r4 = S32(MEM_H(ctx->r24, 0X0));
    // 0x80073734: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    // 0x80073738: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x8007373C: sra         $t9, $a0, 11
    ctx->r25 = S32(SIGNED(ctx->r4) >> 11);
    // 0x80073740: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80073744: jal         0x80091A38
    // 0x80073748: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    klabs(rdram, ctx);
        goto after_7;
    // 0x80073748: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    after_7:
    // 0x8007374C: lw          $t0, 0xCC($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80073750: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80073754: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80073758: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
L_8007375C:
    // 0x8007375C: lbu         $t7, 0x364($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X364);
    // 0x80073760: lh          $v0, 0x2B4($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X2B4));
    // 0x80073764: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80073768: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x8007376C: bltz        $v0, L_8007377C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80073770: subu        $t0, $t0, $t6
        ctx->r8 = SUB32(ctx->r8, ctx->r14);
            goto L_8007377C;
    }
    // 0x80073770: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x80073774: b           L_80073780
    // 0x80073778: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
        goto L_80073780;
    // 0x80073778: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
L_8007377C:
    // 0x8007377C: lh          $t2, 0x2B2($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X2B2));
L_80073780:
    // 0x80073780: beql        $t2, $at, L_800737AC
    if (ctx->r10 == ctx->r1) {
        // 0x80073784: lh          $t7, 0x288($s0)
        ctx->r15 = S32(MEM_H(ctx->r16, 0X288));
            goto L_800737AC;
    }
    goto skip_6;
    // 0x80073784: lh          $t7, 0x288($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X288));
    skip_6:
    // 0x80073788: lh          $v1, 0x328($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X328));
    // 0x8007378C: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80073790: mflo        $t8
    ctx->r24 = lo;
    // 0x80073794: bgez        $t8, L_800737A4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80073798: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_800737A4;
    }
    // 0x80073798: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8007379C: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x800737A0: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_800737A4:
    // 0x800737A4: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800737A8: lh          $t7, 0x288($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X288));
L_800737AC:
    // 0x800737AC: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800737B0: addiu       $t8, $t8, -0x1988
    ctx->r24 = ADD32(ctx->r24, -0X1988);
    // 0x800737B4: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800737B8: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x800737BC: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800737C0: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x800737C4: lh          $t9, 0x18($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X18));
    // 0x800737C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800737CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800737D0: bnel        $t9, $at, L_800737E4
    if (ctx->r25 != ctx->r1) {
        // 0x800737D4: lbu         $t6, 0x27($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0X27);
            goto L_800737E4;
    }
    goto skip_7;
    // 0x800737D4: lbu         $t6, 0x27($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X27);
    skip_7:
    // 0x800737D8: b           L_800737E8
    // 0x800737DC: sb          $t7, 0xAA($sp)
    MEM_B(0XAA, ctx->r29) = ctx->r15;
        goto L_800737E8;
    // 0x800737DC: sb          $t7, 0xAA($sp)
    MEM_B(0XAA, ctx->r29) = ctx->r15;
    // 0x800737E0: lbu         $t6, 0x27($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X27);
L_800737E4:
    // 0x800737E4: sb          $t6, 0xAA($sp)
    MEM_B(0XAA, ctx->r29) = ctx->r14;
L_800737E8:
    // 0x800737E8: lh          $t8, 0x2EA($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2EA));
    // 0x800737EC: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
    // 0x800737F0: subu        $v0, $v1, $t8
    ctx->r2 = SUB32(ctx->r3, ctx->r24);
    // 0x800737F4: beq         $v0, $v1, L_800738B4
    if (ctx->r2 == ctx->r3) {
        // 0x800737F8: slti        $at, $v0, 0x5
        ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
            goto L_800738B4;
    }
    // 0x800737F8: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800737FC: bne         $at, $zero, L_80073810
    if (ctx->r1 != 0) {
        // 0x80073800: subu        $a1, $t4, $t0
        ctx->r5 = SUB32(ctx->r12, ctx->r8);
            goto L_80073810;
    }
    // 0x80073800: subu        $a1, $t4, $t0
    ctx->r5 = SUB32(ctx->r12, ctx->r8);
    // 0x80073804: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80073808: bne         $at, $zero, L_80073864
    if (ctx->r1 != 0) {
        // 0x8007380C: addiu       $a2, $zero, 0x9DA
        ctx->r6 = ADD32(0, 0X9DA);
            goto L_80073864;
    }
    // 0x8007380C: addiu       $a2, $zero, 0x9DA
    ctx->r6 = ADD32(0, 0X9DA);
L_80073810:
    // 0x80073810: lh          $t9, 0x28A($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80073814: lbu         $t8, 0xAA($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073818: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8007381C: sra         $t7, $t9, 1
    ctx->r15 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80073820: subu        $a0, $t1, $t7
    ctx->r4 = SUB32(ctx->r9, ctx->r15);
    // 0x80073824: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x80073828: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8007382C: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    // 0x80073830: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
    // 0x80073834: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80073838: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x8007383C: addiu       $a1, $a1, 0xFA
    ctx->r5 = ADD32(ctx->r5, 0XFA);
    // 0x80073840: addiu       $a2, $zero, 0x9D9
    ctx->r6 = ADD32(0, 0X9D9);
    // 0x80073844: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073848: jal         0x800724B0
    // 0x8007384C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    myospal(rdram, ctx);
        goto after_8;
    // 0x8007384C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_8:
    // 0x80073850: lw          $t0, 0xCC($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80073854: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80073858: lw          $t2, 0xC4($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0XC4));
    // 0x8007385C: b           L_800738B4
    // 0x80073860: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
        goto L_800738B4;
    // 0x80073860: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
L_80073864:
    // 0x80073864: lh          $t9, 0x28A($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80073868: lbu         $t8, 0xAA($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XAA);
    // 0x8007386C: subu        $a1, $t4, $t0
    ctx->r5 = SUB32(ctx->r12, ctx->r8);
    // 0x80073870: sra         $t7, $t9, 1
    ctx->r15 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80073874: subu        $a0, $t1, $t7
    ctx->r4 = SUB32(ctx->r9, ctx->r15);
    // 0x80073878: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8007387C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80073880: addiu       $a0, $a0, 0x90
    ctx->r4 = ADD32(ctx->r4, 0X90);
    // 0x80073884: addiu       $a1, $a1, 0xD6
    ctx->r5 = ADD32(ctx->r5, 0XD6);
    // 0x80073888: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    // 0x8007388C: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
    // 0x80073890: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80073894: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x80073898: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x8007389C: jal         0x800724B0
    // 0x800738A0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    myospal(rdram, ctx);
        goto after_9;
    // 0x800738A0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_9:
    // 0x800738A4: lw          $t0, 0xCC($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x800738A8: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800738AC: lw          $t2, 0xC4($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0XC4));
    // 0x800738B0: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
L_800738B4:
    // 0x800738B4: lh          $t9, 0x2E0($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800738B8: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x800738BC: addiu       $t6, $t6, 0x6BA8
    ctx->r14 = ADD32(ctx->r14, 0X6BA8);
    // 0x800738C0: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800738C4: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x800738C8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800738CC: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x800738D0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800738D4: addu        $v1, $t7, $t6
    ctx->r3 = ADD32(ctx->r15, ctx->r14);
    // 0x800738D8: lbu         $t8, 0x27($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X27);
    // 0x800738DC: slti        $at, $t8, 0x28
    ctx->r1 = SIGNED(ctx->r24) < 0X28 ? 1 : 0;
    // 0x800738E0: beql        $at, $zero, L_80073A0C
    if (ctx->r1 == 0) {
        // 0x800738E4: sltiu       $at, $t2, 0xF
        ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
            goto L_80073A0C;
    }
    goto skip_8;
    // 0x800738E4: sltiu       $at, $t2, 0xF
    ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
    skip_8:
    // 0x800738E8: lbu         $t9, 0x341($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X341);
    // 0x800738EC: lui         $a1, 0x8028
    ctx->r5 = S32(0X8028 << 16);
    // 0x800738F0: bne         $t9, $zero, L_80073918
    if (ctx->r25 != 0) {
        // 0x800738F4: nop
    
            goto L_80073918;
    }
    // 0x800738F4: nop

    // 0x800738F8: lh          $t0, 0x18($v1)
    ctx->r8 = S32(MEM_H(ctx->r3, 0X18));
    // 0x800738FC: addiu       $a1, $a1, -0x68A0
    ctx->r5 = ADD32(ctx->r5, -0X68A0);
    // 0x80073900: lh          $t7, 0x0($a1)
    ctx->r15 = S32(MEM_H(ctx->r5, 0X0));
    // 0x80073904: sra         $v0, $t0, 1
    ctx->r2 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80073908: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x8007390C: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x80073910: addiu       $t4, $t4, 0x20
    ctx->r12 = ADD32(ctx->r12, 0X20);
    // 0x80073914: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
L_80073918:
    // 0x80073918: lui         $a1, 0x8028
    ctx->r5 = S32(0X8028 << 16);
    // 0x8007391C: addiu       $a1, $a1, -0x68A0
    ctx->r5 = ADD32(ctx->r5, -0X68A0);
    // 0x80073920: lh          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_H(ctx->r5, 0X0));
    // 0x80073924: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80073928: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x8007392C: andi        $t9, $t8, 0x7FF
    ctx->r25 = ctx->r24 & 0X7FF;
    // 0x80073930: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x80073934: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80073938: lh          $v0, -0x9A0($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X9A0));
    // 0x8007393C: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
    // 0x80073940: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    // 0x80073944: sra         $t6, $v0, 10
    ctx->r14 = S32(SIGNED(ctx->r2) >> 10);
    // 0x80073948: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x8007394C: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80073950: jal         0x80091A38
    // 0x80073954: sra         $a0, $v0, 8
    ctx->r4 = S32(SIGNED(ctx->r2) >> 8);
    klabs(rdram, ctx);
        goto after_10;
    // 0x80073954: sra         $a0, $v0, 8
    ctx->r4 = S32(SIGNED(ctx->r2) >> 8);
    after_10:
    // 0x80073958: lh          $t8, 0x28A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x8007395C: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80073960: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80073964: lbu         $t7, 0xAA($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073968: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8007396C: subu        $a0, $t1, $t9
    ctx->r4 = SUB32(ctx->r9, ctx->r25);
    // 0x80073970: subu        $a1, $t4, $v0
    ctx->r5 = SUB32(ctx->r12, ctx->r2);
    // 0x80073974: addiu       $a1, $a1, 0x102
    ctx->r5 = ADD32(ctx->r5, 0X102);
    // 0x80073978: addiu       $a0, $a0, 0xFA
    ctx->r4 = ADD32(ctx->r4, 0XFA);
    // 0x8007397C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80073980: addiu       $a2, $zero, 0x668
    ctx->r6 = ADD32(0, 0X668);
    // 0x80073984: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073988: jal         0x800724B0
    // 0x8007398C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    myospal(rdram, ctx);
        goto after_11;
    // 0x8007398C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_11:
    // 0x80073990: lui         $t6, 0x8028
    ctx->r14 = S32(0X8028 << 16);
    // 0x80073994: lh          $t6, -0x68A0($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X68A0));
    // 0x80073998: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8007399C: lw          $t2, 0xC4($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0XC4));
    // 0x800739A0: andi        $t8, $t6, 0x7FF
    ctx->r24 = ctx->r14 & 0X7FF;
    // 0x800739A4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800739A8: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800739AC: lh          $v0, -0x9A0($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X9A0));
    // 0x800739B0: sra         $t7, $v0, 10
    ctx->r15 = S32(SIGNED(ctx->r2) >> 10);
    // 0x800739B4: subu        $t1, $t2, $t7
    ctx->r9 = SUB32(ctx->r10, ctx->r15);
    // 0x800739B8: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x800739BC: jal         0x80091A38
    // 0x800739C0: sra         $a0, $v0, 8
    ctx->r4 = S32(SIGNED(ctx->r2) >> 8);
    klabs(rdram, ctx);
        goto after_12;
    // 0x800739C0: sra         $a0, $v0, 8
    ctx->r4 = S32(SIGNED(ctx->r2) >> 8);
    after_12:
    // 0x800739C4: lh          $t6, 0x28A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x800739C8: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800739CC: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x800739D0: lbu         $t7, 0xAA($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XAA);
    // 0x800739D4: sra         $t8, $t6, 1
    ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800739D8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800739DC: subu        $a0, $t1, $t8
    ctx->r4 = SUB32(ctx->r9, ctx->r24);
    // 0x800739E0: addu        $a1, $v0, $t4
    ctx->r5 = ADD32(ctx->r2, ctx->r12);
    // 0x800739E4: addiu       $a1, $a1, 0xC8
    ctx->r5 = ADD32(ctx->r5, 0XC8);
    // 0x800739E8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x800739EC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800739F0: addiu       $a2, $zero, 0x668
    ctx->r6 = ADD32(0, 0X668);
    // 0x800739F4: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x800739F8: jal         0x800724B0
    // 0x800739FC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    myospal(rdram, ctx);
        goto after_13;
    // 0x800739FC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_13:
    // 0x80073A00: b           L_80074C0C
    // 0x80073A04: nop

        goto L_80074C0C;
    // 0x80073A04: nop

    // 0x80073A08: sltiu       $at, $t2, 0xF
    ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
L_80073A0C:
    // 0x80073A0C: beq         $at, $zero, L_80074C0C
    if (ctx->r1 == 0) {
        // 0x80073A10: sw          $t2, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r10;
            goto L_80074C0C;
    }
    // 0x80073A10: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80073A14: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x80073A18: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80073A1C: addu        $at, $at, $t6
    gpr jr_addend_80073A24 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80073A20: lw          $t6, 0x5228($at)
    ctx->r14 = ADD32(ctx->r1, 0X5228);
    // 0x80073A24: jr          $t6
    // 0x80073A28: nop

    switch (jr_addend_80073A24 >> 2) {
        case 0: goto L_80073A2C; break;
        case 1: goto L_80074170; break;
        case 2: goto L_80073D6C; break;
        case 3: goto L_80073EC8; break;
        case 4: goto L_80074774; break;
        case 5: goto L_800745A4; break;
        case 6: goto L_80074A0C; break;
        case 7: goto L_80074A0C; break;
        case 8: goto L_80073BB8; break;
        case 9: goto L_80073AB0; break;
        case 10: goto L_80074848; break;
        case 11: goto L_800746CC; break;
        case 12: goto L_80074170; break;
        case 13: goto L_80073D6C; break;
        case 14: goto L_80073BB8; break;
        default: switch_error(__func__, 0x80073A24, 0x80105228);
    }
    // 0x80073A28: nop

L_80073A2C:
    // 0x80073A2C: lh          $v0, 0x2D4($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X2D4));
    // 0x80073A30: blez        $v0, L_80074C0C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80073A34: slti        $at, $v0, 0x5
        ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
            goto L_80074C0C;
    }
    // 0x80073A34: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80073A38: bne         $at, $zero, L_80073A4C
    if (ctx->r1 != 0) {
        // 0x80073A3C: subu        $v1, $t4, $t0
        ctx->r3 = SUB32(ctx->r12, ctx->r8);
            goto L_80073A4C;
    }
    // 0x80073A3C: subu        $v1, $t4, $t0
    ctx->r3 = SUB32(ctx->r12, ctx->r8);
    // 0x80073A40: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80073A44: bne         $at, $zero, L_80073A80
    if (ctx->r1 != 0) {
        // 0x80073A48: addiu       $a1, $v1, 0x11D
        ctx->r5 = ADD32(ctx->r3, 0X11D);
            goto L_80073A80;
    }
    // 0x80073A48: addiu       $a1, $v1, 0x11D
    ctx->r5 = ADD32(ctx->r3, 0X11D);
L_80073A4C:
    // 0x80073A4C: lh          $t8, 0x28A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80073A50: lbu         $t7, 0xAA($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073A54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80073A58: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80073A5C: subu        $a0, $t1, $t9
    ctx->r4 = SUB32(ctx->r9, ctx->r25);
    // 0x80073A60: addiu       $a0, $a0, 0x104
    ctx->r4 = ADD32(ctx->r4, 0X104);
    // 0x80073A64: addiu       $a1, $v1, 0x141
    ctx->r5 = ADD32(ctx->r3, 0X141);
    // 0x80073A68: addiu       $a2, $zero, 0x9D9
    ctx->r6 = ADD32(0, 0X9D9);
    // 0x80073A6C: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073A70: jal         0x800724B0
    // 0x80073A74: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    myospal(rdram, ctx);
        goto after_14;
    // 0x80073A74: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_14:
    // 0x80073A78: b           L_80074C0C
    // 0x80073A7C: nop

        goto L_80074C0C;
    // 0x80073A7C: nop

L_80073A80:
    // 0x80073A80: lh          $t6, 0x28A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80073A84: lbu         $t9, 0xAA($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073A88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80073A8C: sra         $t8, $t6, 1
    ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80073A90: subu        $a0, $t1, $t8
    ctx->r4 = SUB32(ctx->r9, ctx->r24);
    // 0x80073A94: addiu       $a0, $a0, 0xC8
    ctx->r4 = ADD32(ctx->r4, 0XC8);
    // 0x80073A98: addiu       $a2, $zero, 0x9DA
    ctx->r6 = ADD32(0, 0X9DA);
    // 0x80073A9C: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073AA0: jal         0x800724B0
    // 0x80073AA4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    myospal(rdram, ctx);
        goto after_15;
    // 0x80073AA4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_15:
    // 0x80073AA8: b           L_80074C0C
    // 0x80073AAC: nop

        goto L_80074C0C;
    // 0x80073AAC: nop

L_80073AB0:
    // 0x80073AB0: addiu       $t2, $s0, 0x2D4
    ctx->r10 = ADD32(ctx->r16, 0X2D4);
    // 0x80073AB4: lh          $v0, 0x0($t2)
    ctx->r2 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80073AB8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80073ABC: addiu       $t0, $t0, -0xA
    ctx->r8 = ADD32(ctx->r8, -0XA);
    // 0x80073AC0: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80073AC4: bne         $at, $zero, L_80073AD0
    if (ctx->r1 != 0) {
        // 0x80073AC8: sll         $t7, $v0, 3
        ctx->r15 = S32(ctx->r2 << 3);
            goto L_80073AD0;
    }
    // 0x80073AC8: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80073ACC: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
L_80073AD0:
    // 0x80073AD0: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80073AD4: beq         $at, $zero, L_80073B24
    if (ctx->r1 == 0) {
        // 0x80073AD8: subu        $v1, $t4, $t0
        ctx->r3 = SUB32(ctx->r12, ctx->r8);
            goto L_80073B24;
    }
    // 0x80073AD8: subu        $v1, $t4, $t0
    ctx->r3 = SUB32(ctx->r12, ctx->r8);
    // 0x80073ADC: lh          $t6, 0x28A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80073AE0: lbu         $t9, 0xAA($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073AE4: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80073AE8: sra         $t8, $t6, 1
    ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80073AEC: subu        $a0, $t1, $t8
    ctx->r4 = SUB32(ctx->r9, ctx->r24);
    // 0x80073AF0: addiu       $a0, $a0, 0x8E
    ctx->r4 = ADD32(ctx->r4, 0X8E);
    // 0x80073AF4: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80073AF8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80073AFC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80073B00: addiu       $a1, $v1, 0xED
    ctx->r5 = ADD32(ctx->r3, 0XED);
    // 0x80073B04: addiu       $a2, $zero, 0xA06
    ctx->r6 = ADD32(0, 0XA06);
    // 0x80073B08: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073B0C: jal         0x800724B0
    // 0x80073B10: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    myospal(rdram, ctx);
        goto after_16;
    // 0x80073B10: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_16:
    // 0x80073B14: lw          $t2, 0x48($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80073B18: lw          $v1, 0x44($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80073B1C: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80073B20: lh          $v0, 0x0($t2)
    ctx->r2 = S32(MEM_H(ctx->r10, 0X0));
L_80073B24:
    // 0x80073B24: lh          $t7, 0x28A($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80073B28: sra         $a2, $v0, 2
    ctx->r6 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80073B2C: addiu       $a2, $a2, 0xA03
    ctx->r6 = ADD32(ctx->r6, 0XA03);
    // 0x80073B30: sra         $t6, $t7, 1
    ctx->r14 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80073B34: lbu         $t7, 0xAA($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073B38: subu        $a0, $t1, $t6
    ctx->r4 = SUB32(ctx->r9, ctx->r14);
    // 0x80073B3C: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80073B40: addiu       $a1, $v1, 0xF9
    ctx->r5 = ADD32(ctx->r3, 0XF9);
    // 0x80073B44: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x80073B48: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80073B4C: addiu       $a0, $a0, 0x82
    ctx->r4 = ADD32(ctx->r4, 0X82);
    // 0x80073B50: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80073B54: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80073B58: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80073B5C: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073B60: jal         0x800724B0
    // 0x80073B64: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    myospal(rdram, ctx);
        goto after_17;
    // 0x80073B64: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_17:
    // 0x80073B68: lw          $t2, 0x48($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80073B6C: lh          $t6, 0x28A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80073B70: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80073B74: lh          $a2, 0x0($t2)
    ctx->r6 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80073B78: sra         $t8, $t6, 1
    ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80073B7C: subu        $a0, $t1, $t8
    ctx->r4 = SUB32(ctx->r9, ctx->r24);
    // 0x80073B80: sra         $t9, $a2, 2
    ctx->r25 = S32(SIGNED(ctx->r6) >> 2);
    // 0x80073B84: addiu       $a2, $t9, 0xA03
    ctx->r6 = ADD32(ctx->r25, 0XA03);
    // 0x80073B88: lbu         $t9, 0xAA($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073B8C: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x80073B90: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80073B94: lw          $a1, 0x40($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X40));
    // 0x80073B98: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80073B9C: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80073BA0: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    // 0x80073BA4: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073BA8: jal         0x800724B0
    // 0x80073BAC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    myospal(rdram, ctx);
        goto after_18;
    // 0x80073BAC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_18:
    // 0x80073BB0: b           L_80074C0C
    // 0x80073BB4: nop

        goto L_80074C0C;
    // 0x80073BB4: nop

L_80073BB8:
    // 0x80073BB8: addiu       $t2, $s0, 0x2D4
    ctx->r10 = ADD32(ctx->r16, 0X2D4);
    // 0x80073BBC: lh          $v0, 0x0($t2)
    ctx->r2 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80073BC0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80073BC4: addiu       $a2, $zero, 0x9F1
    ctx->r6 = ADD32(0, 0X9F1);
    // 0x80073BC8: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80073BCC: beq         $at, $zero, L_80073C00
    if (ctx->r1 == 0) {
        // 0x80073BD0: lb          $a3, 0xA9($sp)
        ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
            goto L_80073C00;
    }
    // 0x80073BD0: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073BD4: sll         $t7, $v0, 7
    ctx->r15 = S32(ctx->r2 << 7);
    // 0x80073BD8: addiu       $t6, $t7, 0x400
    ctx->r14 = ADD32(ctx->r15, 0X400);
    // 0x80073BDC: andi        $t8, $t6, 0x7FF
    ctx->r24 = ctx->r14 & 0X7FF;
    // 0x80073BE0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80073BE4: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80073BE8: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x80073BEC: lh          $v1, -0x9A0($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, -0X9A0));
    // 0x80073BF0: sra         $t7, $v1, 10
    ctx->r15 = S32(SIGNED(ctx->r3) >> 10);
    // 0x80073BF4: sra         $t6, $v1, 11
    ctx->r14 = S32(SIGNED(ctx->r3) >> 11);
    // 0x80073BF8: subu        $t1, $t1, $t7
    ctx->r9 = SUB32(ctx->r9, ctx->r15);
    // 0x80073BFC: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
L_80073C00:
    // 0x80073C00: lbu         $t8, 0xAA($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073C04: addiu       $a0, $t1, 0xF9
    ctx->r4 = ADD32(ctx->r9, 0XF9);
    // 0x80073C08: subu        $s0, $t5, $t0
    ctx->r16 = SUB32(ctx->r13, ctx->r8);
    // 0x80073C0C: addiu       $a1, $s0, 0xBE
    ctx->r5 = ADD32(ctx->r16, 0XBE);
    // 0x80073C10: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x80073C14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80073C18: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x80073C1C: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80073C20: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80073C24: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x80073C28: jal         0x800724B0
    // 0x80073C2C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    myospal(rdram, ctx);
        goto after_19;
    // 0x80073C2C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_19:
    // 0x80073C30: lw          $t2, 0x48($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80073C34: lw          $t0, 0xCC($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80073C38: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80073C3C: lh          $v0, 0x0($t2)
    ctx->r2 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80073C40: lw          $t5, 0x44($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80073C44: lw          $t9, 0x3C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80073C48: blez        $v0, L_80073CD4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80073C4C: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80073CD4;
    }
    // 0x80073C4C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80073C50: bne         $t9, $at, L_80073C60
    if (ctx->r25 != ctx->r1) {
        // 0x80073C54: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_80073C60;
    }
    // 0x80073C54: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80073C58: b           L_80073C64
    // 0x80073C5C: addiu       $a2, $zero, 0xED0
    ctx->r6 = ADD32(0, 0XED0);
        goto L_80073C64;
    // 0x80073C5C: addiu       $a2, $zero, 0xED0
    ctx->r6 = ADD32(0, 0XED0);
L_80073C60:
    // 0x80073C60: addiu       $a2, $zero, 0xECD
    ctx->r6 = ADD32(0, 0XECD);
L_80073C64:
    // 0x80073C64: addiu       $t6, $zero, 0x4F
    ctx->r14 = ADD32(0, 0X4F);
    // 0x80073C68: subu        $t3, $t6, $t7
    ctx->r11 = SUB32(ctx->r14, ctx->r15);
    // 0x80073C6C: sll         $t8, $t3, 16
    ctx->r24 = S32(ctx->r11 << 16);
    // 0x80073C70: sra         $t3, $t8, 16
    ctx->r11 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80073C74: slti        $at, $t3, 0x2F
    ctx->r1 = SIGNED(ctx->r11) < 0X2F ? 1 : 0;
    // 0x80073C78: beq         $at, $zero, L_80073C84
    if (ctx->r1 == 0) {
        // 0x80073C7C: sll         $v1, $v0, 2
        ctx->r3 = S32(ctx->r2 << 2);
            goto L_80073C84;
    }
    // 0x80073C7C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80073C80: addiu       $t3, $zero, 0x2F
    ctx->r11 = ADD32(0, 0X2F);
L_80073C84:
    // 0x80073C84: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80073C88: addiu       $v1, $v1, -0x3C
    ctx->r3 = ADD32(ctx->r3, -0X3C);
    // 0x80073C8C: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x80073C90: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80073C94: bgez        $v1, L_80073CA0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80073C98: addu        $a0, $t3, $t1
        ctx->r4 = ADD32(ctx->r11, ctx->r9);
            goto L_80073CA0;
    }
    // 0x80073C98: addu        $a0, $t3, $t1
    ctx->r4 = ADD32(ctx->r11, ctx->r9);
    // 0x80073C9C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80073CA0:
    // 0x80073CA0: lbu         $t9, 0xAA($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073CA4: addu        $t8, $t5, $v1
    ctx->r24 = ADD32(ctx->r13, ctx->r3);
    // 0x80073CA8: subu        $a1, $t8, $t0
    ctx->r5 = SUB32(ctx->r24, ctx->r8);
    // 0x80073CAC: addiu       $a1, $a1, 0xBD
    ctx->r5 = ADD32(ctx->r5, 0XBD);
    // 0x80073CB0: addiu       $a0, $a0, 0xF9
    ctx->r4 = ADD32(ctx->r4, 0XF9);
    // 0x80073CB4: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073CB8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80073CBC: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80073CC0: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80073CC4: jal         0x800724B0
    // 0x80073CC8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    myospal(rdram, ctx);
        goto after_20;
    // 0x80073CC8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_20:
    // 0x80073CCC: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80073CD0: lw          $t2, 0x48($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
L_80073CD4:
    // 0x80073CD4: lbu         $t6, 0xAA($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073CD8: lw          $a0, 0x4C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80073CDC: addiu       $a1, $s0, 0xBD
    ctx->r5 = ADD32(ctx->r16, 0XBD);
    // 0x80073CE0: addiu       $a2, $zero, 0x9F0
    ctx->r6 = ADD32(0, 0X9F0);
    // 0x80073CE4: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073CE8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80073CEC: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80073CF0: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80073CF4: jal         0x800724B0
    // 0x80073CF8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    myospal(rdram, ctx);
        goto after_21;
    // 0x80073CF8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_21:
    // 0x80073CFC: lw          $t2, 0x48($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80073D00: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80073D04: lw          $t8, 0x3C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80073D08: lh          $t7, 0x0($t2)
    ctx->r15 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80073D0C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80073D10: bne         $t7, $zero, L_80074C0C
    if (ctx->r15 != 0) {
        // 0x80073D14: nop
    
            goto L_80074C0C;
    }
    // 0x80073D14: nop

    // 0x80073D18: bne         $t8, $at, L_80073D48
    if (ctx->r24 != ctx->r1) {
        // 0x80073D1C: addiu       $a0, $t1, 0xFF
        ctx->r4 = ADD32(ctx->r9, 0XFF);
            goto L_80073D48;
    }
    // 0x80073D1C: addiu       $a0, $t1, 0xFF
    ctx->r4 = ADD32(ctx->r9, 0XFF);
    // 0x80073D20: lbu         $t9, 0xAA($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073D24: addiu       $a0, $t1, 0xF6
    ctx->r4 = ADD32(ctx->r9, 0XF6);
    // 0x80073D28: addiu       $a1, $s0, 0xE2
    ctx->r5 = ADD32(ctx->r16, 0XE2);
    // 0x80073D2C: addiu       $a2, $zero, 0xECE
    ctx->r6 = ADD32(0, 0XECE);
    // 0x80073D30: addiu       $a3, $zero, -0x20
    ctx->r7 = ADD32(0, -0X20);
    // 0x80073D34: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80073D38: jal         0x800724B0
    // 0x80073D3C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    myospal(rdram, ctx);
        goto after_22;
    // 0x80073D3C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_22:
    // 0x80073D40: b           L_80074C0C
    // 0x80073D44: nop

        goto L_80074C0C;
    // 0x80073D44: nop

L_80073D48:
    // 0x80073D48: lbu         $t6, 0xAA($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073D4C: addiu       $a1, $s0, 0xE6
    ctx->r5 = ADD32(ctx->r16, 0XE6);
    // 0x80073D50: addiu       $a2, $zero, 0xECF
    ctx->r6 = ADD32(0, 0XECF);
    // 0x80073D54: addiu       $a3, $zero, -0x20
    ctx->r7 = ADD32(0, -0X20);
    // 0x80073D58: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80073D5C: jal         0x800724B0
    // 0x80073D60: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    myospal(rdram, ctx);
        goto after_23;
    // 0x80073D60: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_23:
    // 0x80073D64: b           L_80074C0C
    // 0x80073D68: nop

        goto L_80074C0C;
    // 0x80073D68: nop

L_80073D6C:
    // 0x80073D6C: lh          $v0, 0x2D4($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X2D4));
    // 0x80073D70: addiu       $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
    // 0x80073D74: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80073D78: bne         $at, $zero, L_80073D94
    if (ctx->r1 != 0) {
        // 0x80073D7C: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80073D94;
    }
    // 0x80073D7C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80073D80: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80073D84: beql        $at, $zero, L_80073D98
    if (ctx->r1 == 0) {
        // 0x80073D88: sltiu       $at, $v0, 0x1F
        ctx->r1 = ctx->r2 < 0X1F ? 1 : 0;
            goto L_80073D98;
    }
    goto skip_9;
    // 0x80073D88: sltiu       $at, $v0, 0x1F
    ctx->r1 = ctx->r2 < 0X1F ? 1 : 0;
    skip_9:
    // 0x80073D8C: addiu       $t0, $t0, -0xF
    ctx->r8 = ADD32(ctx->r8, -0XF);
    // 0x80073D90: addiu       $t1, $t1, 0xF
    ctx->r9 = ADD32(ctx->r9, 0XF);
L_80073D94:
    // 0x80073D94: sltiu       $at, $v0, 0x1F
    ctx->r1 = ctx->r2 < 0X1F ? 1 : 0;
L_80073D98:
    // 0x80073D98: beq         $at, $zero, L_80074C0C
    if (ctx->r1 == 0) {
        // 0x80073D9C: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_80074C0C;
    }
    // 0x80073D9C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80073DA0: addu        $at, $at, $t7
    gpr jr_addend_80073DA8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80073DA4: lw          $t7, 0x5264($at)
    ctx->r15 = ADD32(ctx->r1, 0X5264);
    // 0x80073DA8: jr          $t7
    // 0x80073DAC: nop

    switch (jr_addend_80073DA8 >> 2) {
        case 0: goto L_80073DB0; break;
        case 1: goto L_80073DB0; break;
        case 2: goto L_80073DB0; break;
        case 3: goto L_80073DB0; break;
        case 4: goto L_80073DB0; break;
        case 5: goto L_80073DB0; break;
        case 6: goto L_80073DB0; break;
        case 7: goto L_80073DB0; break;
        case 8: goto L_80073DB0; break;
        case 9: goto L_80073DE8; break;
        case 10: goto L_80073DE8; break;
        case 11: goto L_80073DE8; break;
        case 12: goto L_80073DE8; break;
        case 13: goto L_80073E20; break;
        case 14: goto L_80073E20; break;
        case 15: goto L_80073E20; break;
        case 16: goto L_80073E58; break;
        case 17: goto L_80073E58; break;
        case 18: goto L_80073E58; break;
        case 19: goto L_80073E90; break;
        case 20: goto L_80073E90; break;
        case 21: goto L_80073E90; break;
        case 22: goto L_80073E90; break;
        case 23: goto L_80073E90; break;
        case 24: goto L_80073E90; break;
        case 25: goto L_80073E58; break;
        case 26: goto L_80073E58; break;
        case 27: goto L_80073E58; break;
        case 28: goto L_80073E20; break;
        case 29: goto L_80073E20; break;
        case 30: goto L_80073E20; break;
        default: switch_error(__func__, 0x80073DA8, 0x80105264);
    }
    // 0x80073DAC: nop

L_80073DB0:
    // 0x80073DB0: lh          $t8, 0x28A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80073DB4: lbu         $t6, 0xAA($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073DB8: subu        $a1, $t4, $t0
    ctx->r5 = SUB32(ctx->r12, ctx->r8);
    // 0x80073DBC: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80073DC0: subu        $a0, $t1, $t9
    ctx->r4 = SUB32(ctx->r9, ctx->r25);
    // 0x80073DC4: addiu       $a0, $a0, 0x131
    ctx->r4 = ADD32(ctx->r4, 0X131);
    // 0x80073DC8: addiu       $a1, $a1, 0x11D
    ctx->r5 = ADD32(ctx->r5, 0X11D);
    // 0x80073DCC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80073DD0: addiu       $a2, $zero, 0xA35
    ctx->r6 = ADD32(0, 0XA35);
    // 0x80073DD4: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073DD8: jal         0x800724B0
    // 0x80073DDC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    myospal(rdram, ctx);
        goto after_24;
    // 0x80073DDC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_24:
    // 0x80073DE0: b           L_80074C0C
    // 0x80073DE4: nop

        goto L_80074C0C;
    // 0x80073DE4: nop

L_80073DE8:
    // 0x80073DE8: lh          $t7, 0x28A($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80073DEC: lbu         $t9, 0xAA($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073DF0: subu        $a1, $t4, $t0
    ctx->r5 = SUB32(ctx->r12, ctx->r8);
    // 0x80073DF4: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80073DF8: subu        $a0, $t1, $t8
    ctx->r4 = SUB32(ctx->r9, ctx->r24);
    // 0x80073DFC: addiu       $a0, $a0, 0x131
    ctx->r4 = ADD32(ctx->r4, 0X131);
    // 0x80073E00: addiu       $a1, $a1, 0x11D
    ctx->r5 = ADD32(ctx->r5, 0X11D);
    // 0x80073E04: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80073E08: addiu       $a2, $zero, 0xA38
    ctx->r6 = ADD32(0, 0XA38);
    // 0x80073E0C: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073E10: jal         0x800724B0
    // 0x80073E14: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    myospal(rdram, ctx);
        goto after_25;
    // 0x80073E14: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_25:
    // 0x80073E18: b           L_80074C0C
    // 0x80073E1C: nop

        goto L_80074C0C;
    // 0x80073E1C: nop

L_80073E20:
    // 0x80073E20: lh          $t6, 0x28A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80073E24: lbu         $t8, 0xAA($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073E28: subu        $a1, $t4, $t0
    ctx->r5 = SUB32(ctx->r12, ctx->r8);
    // 0x80073E2C: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80073E30: subu        $a0, $t1, $t7
    ctx->r4 = SUB32(ctx->r9, ctx->r15);
    // 0x80073E34: addiu       $a0, $a0, 0x131
    ctx->r4 = ADD32(ctx->r4, 0X131);
    // 0x80073E38: addiu       $a1, $a1, 0x128
    ctx->r5 = ADD32(ctx->r5, 0X128);
    // 0x80073E3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80073E40: addiu       $a2, $zero, 0xA39
    ctx->r6 = ADD32(0, 0XA39);
    // 0x80073E44: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073E48: jal         0x800724B0
    // 0x80073E4C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    myospal(rdram, ctx);
        goto after_26;
    // 0x80073E4C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_26:
    // 0x80073E50: b           L_80074C0C
    // 0x80073E54: nop

        goto L_80074C0C;
    // 0x80073E54: nop

L_80073E58:
    // 0x80073E58: lh          $t9, 0x28A($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80073E5C: lbu         $t7, 0xAA($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073E60: subu        $a1, $t4, $t0
    ctx->r5 = SUB32(ctx->r12, ctx->r8);
    // 0x80073E64: sra         $t6, $t9, 1
    ctx->r14 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80073E68: subu        $a0, $t1, $t6
    ctx->r4 = SUB32(ctx->r9, ctx->r14);
    // 0x80073E6C: addiu       $a0, $a0, 0x131
    ctx->r4 = ADD32(ctx->r4, 0X131);
    // 0x80073E70: addiu       $a1, $a1, 0x11D
    ctx->r5 = ADD32(ctx->r5, 0X11D);
    // 0x80073E74: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80073E78: addiu       $a2, $zero, 0xA3A
    ctx->r6 = ADD32(0, 0XA3A);
    // 0x80073E7C: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073E80: jal         0x800724B0
    // 0x80073E84: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    myospal(rdram, ctx);
        goto after_27;
    // 0x80073E84: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_27:
    // 0x80073E88: b           L_80074C0C
    // 0x80073E8C: nop

        goto L_80074C0C;
    // 0x80073E8C: nop

L_80073E90:
    // 0x80073E90: lh          $t8, 0x28A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80073E94: lbu         $t6, 0xAA($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073E98: subu        $a1, $t4, $t0
    ctx->r5 = SUB32(ctx->r12, ctx->r8);
    // 0x80073E9C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80073EA0: subu        $a0, $t1, $t9
    ctx->r4 = SUB32(ctx->r9, ctx->r25);
    // 0x80073EA4: addiu       $a0, $a0, 0x131
    ctx->r4 = ADD32(ctx->r4, 0X131);
    // 0x80073EA8: addiu       $a1, $a1, 0x11D
    ctx->r5 = ADD32(ctx->r5, 0X11D);
    // 0x80073EAC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80073EB0: addiu       $a2, $zero, 0xA3B
    ctx->r6 = ADD32(0, 0XA3B);
    // 0x80073EB4: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80073EB8: jal         0x800724B0
    // 0x80073EBC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    myospal(rdram, ctx);
        goto after_28;
    // 0x80073EBC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_28:
    // 0x80073EC0: b           L_80074C0C
    // 0x80073EC4: nop

        goto L_80074C0C;
    // 0x80073EC4: nop

L_80073EC8:
    // 0x80073EC8: sh          $t0, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r8;
    // 0x80073ECC: sh          $t1, 0x92($sp)
    MEM_H(0X92, ctx->r29) = ctx->r9;
    // 0x80073ED0: addiu       $t2, $s0, 0x2D4
    ctx->r10 = ADD32(ctx->r16, 0X2D4);
    // 0x80073ED4: lh          $t7, 0x0($t2)
    ctx->r15 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80073ED8: blezl       $t7, L_80073FE4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80073EDC: lh          $t6, 0x28A($s0)
        ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
            goto L_80073FE4;
    }
    goto skip_10;
    // 0x80073EDC: lh          $t6, 0x28A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
    skip_10:
    // 0x80073EE0: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x80073EE4: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80073EE8: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80073EEC: jal         0x80071FC0
    // 0x80073EF0: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    fakekrand(rdram, ctx);
        goto after_29;
    // 0x80073EF0: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    after_29:
    // 0x80073EF4: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x80073EF8: slti        $at, $t8, 0x7F
    ctx->r1 = SIGNED(ctx->r24) < 0X7F ? 1 : 0;
    // 0x80073EFC: lw          $t0, 0xCC($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80073F00: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80073F04: lw          $t2, 0x48($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80073F08: beq         $at, $zero, L_80073FE0
    if (ctx->r1 == 0) {
        // 0x80073F0C: lw          $t4, 0xC8($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
            goto L_80073FE0;
    }
    // 0x80073F0C: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80073F10: lh          $t6, 0x0($t2)
    ctx->r14 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80073F14: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80073F18: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    // 0x80073F1C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80073F20: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80073F24: lh          $a0, -0x9A0($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, -0X9A0));
    // 0x80073F28: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80073F2C: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80073F30: sra         $t8, $a0, 12
    ctx->r24 = S32(SIGNED(ctx->r4) >> 12);
    // 0x80073F34: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80073F38: jal         0x80091A38
    // 0x80073F3C: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    klabs(rdram, ctx);
        goto after_30;
    // 0x80073F3C: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    after_30:
    // 0x80073F40: lw          $t0, 0xCC($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80073F44: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x80073F48: jal         0x80071FC0
    // 0x80073F4C: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    fakekrand(rdram, ctx);
        goto after_31;
    // 0x80073F4C: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    after_31:
    // 0x80073F50: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80073F54: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x80073F58: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x80073F5C: jal         0x80071FC0
    // 0x80073F60: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    fakekrand(rdram, ctx);
        goto after_32;
    // 0x80073F60: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    after_32:
    // 0x80073F64: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x80073F68: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80073F6C: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x80073F70: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80073F74: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80073F78: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80073F7C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80073F80: ldc1        $f16, 0x52E0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X52E0);
    // 0x80073F84: lh          $t6, 0x28A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80073F88: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80073F8C: lw          $t0, 0xCC($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80073F90: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80073F94: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80073F98: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80073F9C: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80073FA0: subu        $a0, $t1, $t7
    ctx->r4 = SUB32(ctx->r9, ctx->r15);
    // 0x80073FA4: subu        $a1, $t4, $t0
    ctx->r5 = SUB32(ctx->r12, ctx->r8);
    // 0x80073FA8: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80073FAC: addiu       $a1, $a1, 0xCD
    ctx->r5 = ADD32(ctx->r5, 0XCD);
    // 0x80073FB0: addiu       $a0, $a0, 0xD7
    ctx->r4 = ADD32(ctx->r4, 0XD7);
    // 0x80073FB4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80073FB8: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
    // 0x80073FBC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80073FC0: addiu       $a2, $zero, 0xF4F
    ctx->r6 = ADD32(0, 0XF4F);
    // 0x80073FC4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80073FC8: jal         0x800726B0
    // 0x80073FCC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    displayflash(rdram, ctx);
        goto after_33;
    // 0x80073FCC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_33:
    // 0x80073FD0: lw          $t0, 0xCC($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80073FD4: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80073FD8: lw          $t2, 0x48($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80073FDC: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
L_80073FE0:
    // 0x80073FE0: lh          $t6, 0x28A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
L_80073FE4:
    // 0x80073FE4: lbu         $t8, 0xAA($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XAA);
    // 0x80073FE8: subu        $a1, $t4, $t0
    ctx->r5 = SUB32(ctx->r12, ctx->r8);
    // 0x80073FEC: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80073FF0: subu        $a0, $t1, $t7
    ctx->r4 = SUB32(ctx->r9, ctx->r15);
    // 0x80073FF4: addiu       $a0, $a0, 0xEB
    ctx->r4 = ADD32(ctx->r4, 0XEB);
    // 0x80073FF8: addiu       $a1, $a1, 0x109
    ctx->r5 = ADD32(ctx->r5, 0X109);
    // 0x80073FFC: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    // 0x80074000: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80074004: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074008: addiu       $a2, $zero, 0x9E8
    ctx->r6 = ADD32(0, 0X9E8);
    // 0x8007400C: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80074010: jal         0x800724B0
    // 0x80074014: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    myospal(rdram, ctx);
        goto after_34;
    // 0x80074014: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_34:
    // 0x80074018: lw          $t2, 0x48($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
    // 0x8007401C: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80074020: lh          $t0, 0x94($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X94));
    // 0x80074024: lh          $t9, 0x0($t2)
    ctx->r25 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80074028: lh          $t1, 0x92($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X92));
    // 0x8007402C: blezl       $t9, L_80074138
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80074030: lh          $t9, 0x28A($s0)
        ctx->r25 = S32(MEM_H(ctx->r16, 0X28A));
            goto L_80074138;
    }
    goto skip_11;
    // 0x80074030: lh          $t9, 0x28A($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X28A));
    skip_11:
    // 0x80074034: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x80074038: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x8007403C: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80074040: jal         0x80071FC0
    // 0x80074044: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    fakekrand(rdram, ctx);
        goto after_35;
    // 0x80074044: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    after_35:
    // 0x80074048: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x8007404C: slti        $at, $t6, 0x7F
    ctx->r1 = SIGNED(ctx->r14) < 0X7F ? 1 : 0;
    // 0x80074050: lw          $t0, 0xCC($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80074054: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80074058: lw          $t2, 0x48($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
    // 0x8007405C: beq         $at, $zero, L_80074134
    if (ctx->r1 == 0) {
        // 0x80074060: lw          $t4, 0xC8($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
            goto L_80074134;
    }
    // 0x80074060: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80074064: lh          $t7, 0x0($t2)
    ctx->r15 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80074068: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8007406C: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    // 0x80074070: sll         $t8, $t7, 7
    ctx->r24 = S32(ctx->r15 << 7);
    // 0x80074074: addiu       $t9, $t8, 0x200
    ctx->r25 = ADD32(ctx->r24, 0X200);
    // 0x80074078: andi        $t6, $t9, 0x7FF
    ctx->r14 = ctx->r25 & 0X7FF;
    // 0x8007407C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80074080: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80074084: lh          $a0, -0x9A0($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, -0X9A0));
    // 0x80074088: sra         $t8, $a0, 12
    ctx->r24 = S32(SIGNED(ctx->r4) >> 12);
    // 0x8007408C: jal         0x80091A38
    // 0x80074090: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    klabs(rdram, ctx);
        goto after_36;
    // 0x80074090: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_36:
    // 0x80074094: lh          $t9, 0x94($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X94));
    // 0x80074098: subu        $t0, $t9, $v0
    ctx->r8 = SUB32(ctx->r25, ctx->r2);
    // 0x8007409C: jal         0x80071FC0
    // 0x800740A0: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    fakekrand(rdram, ctx);
        goto after_37;
    // 0x800740A0: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    after_37:
    // 0x800740A4: lh          $t6, 0x92($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X92));
    // 0x800740A8: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x800740AC: subu        $t1, $t6, $t7
    ctx->r9 = SUB32(ctx->r14, ctx->r15);
    // 0x800740B0: jal         0x80071FC0
    // 0x800740B4: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    fakekrand(rdram, ctx);
        goto after_38;
    // 0x800740B4: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    after_38:
    // 0x800740B8: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x800740BC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800740C0: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x800740C4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800740C8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800740CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800740D0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800740D4: ldc1        $f16, 0x52E8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X52E8);
    // 0x800740D8: lh          $t8, 0x28A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x800740DC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800740E0: lw          $t0, 0xCC($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x800740E4: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800740E8: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x800740EC: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800740F0: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800740F4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800740F8: subu        $a0, $t9, $t1
    ctx->r4 = SUB32(ctx->r25, ctx->r9);
    // 0x800740FC: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80074100: subu        $a1, $t4, $t0
    ctx->r5 = SUB32(ctx->r12, ctx->r8);
    // 0x80074104: addiu       $a1, $a1, 0xCD
    ctx->r5 = ADD32(ctx->r5, 0XCD);
    // 0x80074108: addiu       $a0, $a0, 0x69
    ctx->r4 = ADD32(ctx->r4, 0X69);
    // 0x8007410C: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
    // 0x80074110: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80074114: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80074118: addiu       $a2, $zero, 0xF4F
    ctx->r6 = ADD32(0, 0XF4F);
    // 0x8007411C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80074120: jal         0x800726B0
    // 0x80074124: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    displayflash(rdram, ctx);
        goto after_39;
    // 0x80074124: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_39:
    // 0x80074128: lw          $t0, 0xCC($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x8007412C: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80074130: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
L_80074134:
    // 0x80074134: lh          $t9, 0x28A($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X28A));
L_80074138:
    // 0x80074138: lbu         $t8, 0xAA($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XAA);
    // 0x8007413C: subu        $a1, $t4, $t0
    ctx->r5 = SUB32(ctx->r12, ctx->r8);
    // 0x80074140: sra         $t6, $t9, 1
    ctx->r14 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80074144: subu        $a0, $t6, $t1
    ctx->r4 = SUB32(ctx->r14, ctx->r9);
    // 0x80074148: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8007414C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80074150: addiu       $a0, $a0, 0x55
    ctx->r4 = ADD32(ctx->r4, 0X55);
    // 0x80074154: addiu       $a1, $a1, 0x109
    ctx->r5 = ADD32(ctx->r5, 0X109);
    // 0x80074158: addiu       $a2, $zero, 0x9E8
    ctx->r6 = ADD32(0, 0X9E8);
    // 0x8007415C: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80074160: jal         0x800724B0
    // 0x80074164: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    myospal(rdram, ctx);
        goto after_40;
    // 0x80074164: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_40:
    // 0x80074168: b           L_80074C0C
    // 0x8007416C: nop

        goto L_80074C0C;
    // 0x8007416C: nop

L_80074170:
    // 0x80074170: addiu       $t2, $s0, 0x2D4
    ctx->r10 = ADD32(ctx->r16, 0X2D4);
    // 0x80074174: lh          $v0, 0x0($t2)
    ctx->r2 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80074178: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x8007417C: addiu       $t9, $t9, -0x1778
    ctx->r25 = ADD32(ctx->r25, -0X1778);
    // 0x80074180: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80074184: beql        $at, $zero, L_800742BC
    if (ctx->r1 == 0) {
        // 0x80074188: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_800742BC;
    }
    goto skip_12;
    // 0x80074188: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    skip_12:
    // 0x8007418C: lw          $at, 0x0($t9)
    ctx->r1 = S32(MEM_W(ctx->r25, 0X0));
    // 0x80074190: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x80074194: addiu       $a0, $t1, 0xA5
    ctx->r4 = ADD32(ctx->r9, 0XA5);
    // 0x80074198: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x8007419C: lw          $t7, 0x4($t9)
    ctx->r15 = S32(MEM_W(ctx->r25, 0X4));
    // 0x800741A0: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x800741A4: sra         $t8, $t3, 16
    ctx->r24 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800741A8: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800741AC: lhu         $at, 0x8($t9)
    ctx->r1 = MEM_HU(ctx->r25, 0X8);
    // 0x800741B0: or          $t3, $t8, $zero
    ctx->r11 = ctx->r24 | 0;
    // 0x800741B4: subu        $v1, $t4, $t0
    ctx->r3 = SUB32(ctx->r12, ctx->r8);
    // 0x800741B8: sh          $at, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r1;
    // 0x800741BC: lh          $v0, 0x0($t2)
    ctx->r2 = S32(MEM_H(ctx->r10, 0X0));
    // 0x800741C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800741C4: bne         $v0, $at, L_800741D8
    if (ctx->r2 != ctx->r1) {
        // 0x800741C8: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_800741D8;
    }
    // 0x800741C8: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800741CC: addiu       $t3, $a0, 0x6
    ctx->r11 = ADD32(ctx->r4, 0X6);
    // 0x800741D0: sll         $t9, $t3, 16
    ctx->r25 = S32(ctx->r11 << 16);
    // 0x800741D4: sra         $t3, $t9, 16
    ctx->r11 = S32(SIGNED(ctx->r25) >> 16);
L_800741D8:
    // 0x800741D8: addu        $t6, $a1, $t8
    ctx->r14 = ADD32(ctx->r5, ctx->r24);
    // 0x800741DC: lh          $t0, 0x0($t6)
    ctx->r8 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800741E0: beql        $t0, $zero, L_80074280
    if (ctx->r8 == 0) {
        // 0x800741E4: lh          $t8, 0x28A($s0)
        ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
            goto L_80074280;
    }
    goto skip_13;
    // 0x800741E4: lh          $t8, 0x28A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
    skip_13:
    // 0x800741E8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x800741EC: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x800741F0: jal         0x80071FC0
    // 0x800741F4: sh          $t3, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r11;
    fakekrand(rdram, ctx);
        goto after_41;
    // 0x800741F4: sh          $t3, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r11;
    after_41:
    // 0x800741F8: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x800741FC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80074200: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x80074204: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80074208: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8007420C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80074210: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x80074214: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80074218: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007421C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80074220: lh          $t9, 0x28A($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80074224: lh          $t3, 0x86($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X86));
    // 0x80074228: lw          $v1, 0x44($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8007422C: sra         $t7, $t9, 1
    ctx->r15 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80074230: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80074234: subu        $a0, $t3, $t7
    ctx->r4 = SUB32(ctx->r11, ctx->r15);
    // 0x80074238: addiu       $a0, $a0, 0x1E
    ctx->r4 = ADD32(ctx->r4, 0X1E);
    // 0x8007423C: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80074240: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80074244: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80074248: addiu       $a2, $zero, 0xF4F
    ctx->r6 = ADD32(0, 0XF4F);
    // 0x8007424C: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
    // 0x80074250: addiu       $a1, $v1, 0xCD
    ctx->r5 = ADD32(ctx->r3, 0XCD);
    // 0x80074254: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80074258: jal         0x800726B0
    // 0x8007425C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    displayflash(rdram, ctx);
        goto after_42;
    // 0x8007425C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_42:
    // 0x80074260: lw          $t2, 0x48($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80074264: lw          $v1, 0x44($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80074268: lh          $t3, 0x86($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X86));
    // 0x8007426C: lh          $t9, 0x0($t2)
    ctx->r25 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80074270: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x80074274: addu        $t0, $sp, $t7
    ctx->r8 = ADD32(ctx->r29, ctx->r15);
    // 0x80074278: lh          $t0, 0x88($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, 0X88));
    // 0x8007427C: lh          $t8, 0x28A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
L_80074280:
    // 0x80074280: addiu       $a2, $t0, 0x9DC
    ctx->r6 = ADD32(ctx->r8, 0X9DC);
    // 0x80074284: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x80074288: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8007428C: lbu         $t8, 0xAA($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XAA);
    // 0x80074290: subu        $a0, $t3, $t6
    ctx->r4 = SUB32(ctx->r11, ctx->r14);
    // 0x80074294: addiu       $a0, $a0, 0x73
    ctx->r4 = ADD32(ctx->r4, 0X73);
    // 0x80074298: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8007429C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800742A0: addiu       $a1, $v1, 0x11D
    ctx->r5 = ADD32(ctx->r3, 0X11D);
    // 0x800742A4: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x800742A8: jal         0x800724B0
    // 0x800742AC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    myospal(rdram, ctx);
        goto after_43;
    // 0x800742AC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_43:
    // 0x800742B0: b           L_80074C0C
    // 0x800742B4: nop

        goto L_80074C0C;
    // 0x800742B4: nop

    // 0x800742B8: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
L_800742BC:
    // 0x800742BC: beq         $at, $zero, L_800742F8
    if (ctx->r1 == 0) {
        // 0x800742C0: addiu       $t7, $zero, 0x135
        ctx->r15 = ADD32(0, 0X135);
            goto L_800742F8;
    }
    // 0x800742C0: addiu       $t7, $zero, 0x135
    ctx->r15 = ADD32(0, 0X135);
    // 0x800742C4: lh          $t6, 0x28A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x800742C8: lbu         $t8, 0xAA($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XAA);
    // 0x800742CC: subu        $a1, $t4, $t0
    ctx->r5 = SUB32(ctx->r12, ctx->r8);
    // 0x800742D0: sra         $t9, $t6, 1
    ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800742D4: subu        $a0, $t7, $t9
    ctx->r4 = SUB32(ctx->r15, ctx->r25);
    // 0x800742D8: addiu       $a1, $a1, 0x123
    ctx->r5 = ADD32(ctx->r5, 0X123);
    // 0x800742DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800742E0: addiu       $a2, $zero, 0x9E0
    ctx->r6 = ADD32(0, 0X9E0);
    // 0x800742E4: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x800742E8: jal         0x800724B0
    // 0x800742EC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    myospal(rdram, ctx);
        goto after_44;
    // 0x800742EC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_44:
    // 0x800742F0: b           L_80074C0C
    // 0x800742F4: nop

        goto L_80074C0C;
    // 0x800742F4: nop

L_800742F8:
    // 0x800742F8: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x800742FC: beq         $at, $zero, L_80074380
    if (ctx->r1 == 0) {
        // 0x80074300: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_80074380;
    }
    // 0x80074300: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80074304: lh          $t9, 0x28A($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80074308: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8007430C: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80074310: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80074314: subu        $a0, $t7, $t8
    ctx->r4 = SUB32(ctx->r15, ctx->r24);
    // 0x80074318: lbu         $t7, 0xAA($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XAA);
    // 0x8007431C: addu        $t9, $t6, $t4
    ctx->r25 = ADD32(ctx->r14, ctx->r12);
    // 0x80074320: subu        $a1, $t9, $t0
    ctx->r5 = SUB32(ctx->r25, ctx->r8);
    // 0x80074324: subu        $v1, $t4, $t0
    ctx->r3 = SUB32(ctx->r12, ctx->r8);
    // 0x80074328: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8007432C: addiu       $a1, $a1, 0x64
    ctx->r5 = ADD32(ctx->r5, 0X64);
    // 0x80074330: addiu       $a0, $a0, 0x11C
    ctx->r4 = ADD32(ctx->r4, 0X11C);
    // 0x80074334: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074338: addiu       $a2, $zero, 0x9E2
    ctx->r6 = ADD32(0, 0X9E2);
    // 0x8007433C: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80074340: jal         0x800724B0
    // 0x80074344: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    myospal(rdram, ctx);
        goto after_45;
    // 0x80074344: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_45:
    // 0x80074348: lh          $t8, 0x28A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x8007434C: lw          $v1, 0x44($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80074350: lbu         $t7, 0xAA($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XAA);
    // 0x80074354: addiu       $t9, $zero, 0x12A
    ctx->r25 = ADD32(0, 0X12A);
    // 0x80074358: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8007435C: subu        $a0, $t9, $t6
    ctx->r4 = SUB32(ctx->r25, ctx->r14);
    // 0x80074360: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074364: addiu       $a2, $zero, 0x9E1
    ctx->r6 = ADD32(0, 0X9E1);
    // 0x80074368: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x8007436C: addiu       $a1, $v1, 0x11C
    ctx->r5 = ADD32(ctx->r3, 0X11C);
    // 0x80074370: jal         0x800724B0
    // 0x80074374: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    myospal(rdram, ctx);
        goto after_46;
    // 0x80074374: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_46:
    // 0x80074378: b           L_80074C0C
    // 0x8007437C: nop

        goto L_80074C0C;
    // 0x8007437C: nop

L_80074380:
    // 0x80074380: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80074384: beq         $at, $zero, L_80074448
    if (ctx->r1 == 0) {
        // 0x80074388: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_80074448;
    }
    // 0x80074388: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8007438C: lh          $t9, 0x28A($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80074390: subu        $v1, $t4, $t0
    ctx->r3 = SUB32(ctx->r12, ctx->r8);
    // 0x80074394: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80074398: sra         $t6, $t9, 1
    ctx->r14 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8007439C: lbu         $t9, 0xAA($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XAA);
    // 0x800743A0: subu        $a0, $t8, $t6
    ctx->r4 = SUB32(ctx->r24, ctx->r14);
    // 0x800743A4: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x800743A8: addiu       $a1, $a1, 0x1A4
    ctx->r5 = ADD32(ctx->r5, 0X1A4);
    // 0x800743AC: addiu       $a0, $a0, 0x9A
    ctx->r4 = ADD32(ctx->r4, 0X9A);
    // 0x800743B0: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x800743B4: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x800743B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800743BC: addiu       $a2, $zero, 0x9E4
    ctx->r6 = ADD32(0, 0X9E4);
    // 0x800743C0: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x800743C4: jal         0x800724B0
    // 0x800743C8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    myospal(rdram, ctx);
        goto after_47;
    // 0x800743C8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_47:
    // 0x800743CC: lw          $t2, 0x48($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800743D0: lh          $t6, 0x28A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x800743D4: lw          $v1, 0x44($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800743D8: lh          $v0, 0x0($t2)
    ctx->r2 = S32(MEM_H(ctx->r10, 0X0));
    // 0x800743DC: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800743E0: lbu         $t6, 0xAA($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XAA);
    // 0x800743E4: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800743E8: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800743EC: subu        $a0, $t8, $t7
    ctx->r4 = SUB32(ctx->r24, ctx->r15);
    // 0x800743F0: subu        $a1, $v1, $t9
    ctx->r5 = SUB32(ctx->r3, ctx->r25);
    // 0x800743F4: addiu       $a1, $a1, 0x190
    ctx->r5 = ADD32(ctx->r5, 0X190);
    // 0x800743F8: addiu       $a0, $a0, 0xAE
    ctx->r4 = ADD32(ctx->r4, 0XAE);
    // 0x800743FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074400: addiu       $a2, $zero, 0x9E2
    ctx->r6 = ADD32(0, 0X9E2);
    // 0x80074404: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80074408: jal         0x800724B0
    // 0x8007440C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    myospal(rdram, ctx);
        goto after_48;
    // 0x8007440C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_48:
    // 0x80074410: lh          $t8, 0x28A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80074414: lw          $v1, 0x44($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80074418: lbu         $t6, 0xAA($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XAA);
    // 0x8007441C: addiu       $t9, $zero, 0x12A
    ctx->r25 = ADD32(0, 0X12A);
    // 0x80074420: sra         $t7, $t8, 1
    ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80074424: subu        $a0, $t9, $t7
    ctx->r4 = SUB32(ctx->r25, ctx->r15);
    // 0x80074428: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007442C: addiu       $a2, $zero, 0x9E1
    ctx->r6 = ADD32(0, 0X9E1);
    // 0x80074430: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80074434: addiu       $a1, $v1, 0x11C
    ctx->r5 = ADD32(ctx->r3, 0X11C);
    // 0x80074438: jal         0x800724B0
    // 0x8007443C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    myospal(rdram, ctx);
        goto after_49;
    // 0x8007443C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_49:
    // 0x80074440: b           L_80074C0C
    // 0x80074444: nop

        goto L_80074C0C;
    // 0x80074444: nop

L_80074448:
    // 0x80074448: slti        $at, $v0, 0x17
    ctx->r1 = SIGNED(ctx->r2) < 0X17 ? 1 : 0;
    // 0x8007444C: beq         $at, $zero, L_800744BC
    if (ctx->r1 == 0) {
        // 0x80074450: addiu       $t7, $zero, 0xB8
        ctx->r15 = ADD32(0, 0XB8);
            goto L_800744BC;
    }
    // 0x80074450: addiu       $t7, $zero, 0xB8
    ctx->r15 = ADD32(0, 0XB8);
    // 0x80074454: lh          $t8, 0x28A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80074458: lbu         $t6, 0xAA($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XAA);
    // 0x8007445C: subu        $v1, $t4, $t0
    ctx->r3 = SUB32(ctx->r12, ctx->r8);
    // 0x80074460: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80074464: subu        $a0, $t7, $t9
    ctx->r4 = SUB32(ctx->r15, ctx->r25);
    // 0x80074468: addiu       $a1, $v1, 0xF5
    ctx->r5 = ADD32(ctx->r3, 0XF5);
    // 0x8007446C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80074470: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074474: addiu       $a2, $zero, 0x9E4
    ctx->r6 = ADD32(0, 0X9E4);
    // 0x80074478: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x8007447C: jal         0x800724B0
    // 0x80074480: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    myospal(rdram, ctx);
        goto after_50;
    // 0x80074480: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_50:
    // 0x80074484: lh          $t8, 0x28A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80074488: lw          $v1, 0x44($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8007448C: lbu         $t6, 0xAA($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XAA);
    // 0x80074490: addiu       $t9, $zero, 0x12A
    ctx->r25 = ADD32(0, 0X12A);
    // 0x80074494: sra         $t7, $t8, 1
    ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80074498: subu        $a0, $t9, $t7
    ctx->r4 = SUB32(ctx->r25, ctx->r15);
    // 0x8007449C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800744A0: addiu       $a2, $zero, 0x9E1
    ctx->r6 = ADD32(0, 0X9E1);
    // 0x800744A4: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x800744A8: addiu       $a1, $v1, 0x11C
    ctx->r5 = ADD32(ctx->r3, 0X11C);
    // 0x800744AC: jal         0x800724B0
    // 0x800744B0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    myospal(rdram, ctx);
        goto after_51;
    // 0x800744B0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_51:
    // 0x800744B4: b           L_80074C0C
    // 0x800744B8: nop

        goto L_80074C0C;
    // 0x800744B8: nop

L_800744BC:
    // 0x800744BC: slti        $at, $v0, 0x19
    ctx->r1 = SIGNED(ctx->r2) < 0X19 ? 1 : 0;
    // 0x800744C0: beq         $at, $zero, L_80074530
    if (ctx->r1 == 0) {
        // 0x800744C4: addiu       $t7, $zero, 0xCC
        ctx->r15 = ADD32(0, 0XCC);
            goto L_80074530;
    }
    // 0x800744C4: addiu       $t7, $zero, 0xCC
    ctx->r15 = ADD32(0, 0XCC);
    // 0x800744C8: lh          $t8, 0x28A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x800744CC: lbu         $t6, 0xAA($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XAA);
    // 0x800744D0: subu        $v1, $t4, $t0
    ctx->r3 = SUB32(ctx->r12, ctx->r8);
    // 0x800744D4: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800744D8: subu        $a0, $t7, $t9
    ctx->r4 = SUB32(ctx->r15, ctx->r25);
    // 0x800744DC: addiu       $a1, $v1, 0xF5
    ctx->r5 = ADD32(ctx->r3, 0XF5);
    // 0x800744E0: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x800744E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800744E8: addiu       $a2, $zero, 0x9E4
    ctx->r6 = ADD32(0, 0X9E4);
    // 0x800744EC: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x800744F0: jal         0x800724B0
    // 0x800744F4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    myospal(rdram, ctx);
        goto after_52;
    // 0x800744F4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_52:
    // 0x800744F8: lh          $t8, 0x28A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x800744FC: lw          $v1, 0x44($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80074500: lbu         $t6, 0xAA($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XAA);
    // 0x80074504: addiu       $t9, $zero, 0x12A
    ctx->r25 = ADD32(0, 0X12A);
    // 0x80074508: sra         $t7, $t8, 1
    ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8007450C: subu        $a0, $t9, $t7
    ctx->r4 = SUB32(ctx->r25, ctx->r15);
    // 0x80074510: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074514: addiu       $a2, $zero, 0x9E1
    ctx->r6 = ADD32(0, 0X9E1);
    // 0x80074518: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x8007451C: addiu       $a1, $v1, 0x11C
    ctx->r5 = ADD32(ctx->r3, 0X11C);
    // 0x80074520: jal         0x800724B0
    // 0x80074524: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    myospal(rdram, ctx);
        goto after_53;
    // 0x80074524: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_53:
    // 0x80074528: b           L_80074C0C
    // 0x8007452C: nop

        goto L_80074C0C;
    // 0x8007452C: nop

L_80074530:
    // 0x80074530: slti        $at, $v0, 0x1B
    ctx->r1 = SIGNED(ctx->r2) < 0X1B ? 1 : 0;
    // 0x80074534: beq         $at, $zero, L_80074C0C
    if (ctx->r1 == 0) {
        // 0x80074538: addiu       $t7, $zero, 0xCC
        ctx->r15 = ADD32(0, 0XCC);
            goto L_80074C0C;
    }
    // 0x80074538: addiu       $t7, $zero, 0xCC
    ctx->r15 = ADD32(0, 0XCC);
    // 0x8007453C: lh          $t8, 0x28A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80074540: lbu         $t6, 0xAA($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XAA);
    // 0x80074544: subu        $v1, $t4, $t0
    ctx->r3 = SUB32(ctx->r12, ctx->r8);
    // 0x80074548: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8007454C: subu        $a0, $t7, $t9
    ctx->r4 = SUB32(ctx->r15, ctx->r25);
    // 0x80074550: addiu       $a1, $v1, 0x109
    ctx->r5 = ADD32(ctx->r3, 0X109);
    // 0x80074554: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80074558: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007455C: addiu       $a2, $zero, 0x9E4
    ctx->r6 = ADD32(0, 0X9E4);
    // 0x80074560: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80074564: jal         0x800724B0
    // 0x80074568: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    myospal(rdram, ctx);
        goto after_54;
    // 0x80074568: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_54:
    // 0x8007456C: lh          $t8, 0x28A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80074570: lw          $v1, 0x44($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80074574: lbu         $t6, 0xAA($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XAA);
    // 0x80074578: addiu       $t9, $zero, 0x134
    ctx->r25 = ADD32(0, 0X134);
    // 0x8007457C: sra         $t7, $t8, 1
    ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80074580: subu        $a0, $t9, $t7
    ctx->r4 = SUB32(ctx->r25, ctx->r15);
    // 0x80074584: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074588: addiu       $a2, $zero, 0x9E1
    ctx->r6 = ADD32(0, 0X9E1);
    // 0x8007458C: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80074590: addiu       $a1, $v1, 0x12B
    ctx->r5 = ADD32(ctx->r3, 0X12B);
    // 0x80074594: jal         0x800724B0
    // 0x80074598: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    myospal(rdram, ctx);
        goto after_55;
    // 0x80074598: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_55:
    // 0x8007459C: b           L_80074C0C
    // 0x800745A0: nop

        goto L_80074C0C;
    // 0x800745A0: nop

L_800745A4:
    // 0x800745A4: addiu       $t2, $s0, 0x2D4
    ctx->r10 = ADD32(ctx->r16, 0X2D4);
    // 0x800745A8: lh          $t8, 0x0($t2)
    ctx->r24 = S32(MEM_H(ctx->r10, 0X0));
    // 0x800745AC: subu        $a1, $t4, $t0
    ctx->r5 = SUB32(ctx->r12, ctx->r8);
    // 0x800745B0: addiu       $a1, $a1, 0xF0
    ctx->r5 = ADD32(ctx->r5, 0XF0);
    // 0x800745B4: beq         $t8, $zero, L_800746A0
    if (ctx->r24 == 0) {
        // 0x800745B8: addiu       $a2, $zero, 0xA0D
        ctx->r6 = ADD32(0, 0XA0D);
            goto L_800746A0;
    }
    // 0x800745B8: addiu       $a2, $zero, 0xA0D
    ctx->r6 = ADD32(0, 0XA0D);
    // 0x800745BC: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800745C0: addiu       $t9, $t9, -0x176C
    ctx->r25 = ADD32(ctx->r25, -0X176C);
    // 0x800745C4: lw          $at, 0x0($t9)
    ctx->r1 = S32(MEM_W(ctx->r25, 0X0));
    // 0x800745C8: addiu       $v1, $sp, 0x70
    ctx->r3 = ADD32(ctx->r29, 0X70);
    // 0x800745CC: sw          $at, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r1;
    // 0x800745D0: lw          $t8, 0x4($t9)
    ctx->r24 = S32(MEM_W(ctx->r25, 0X4));
    // 0x800745D4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800745D8: lw          $at, 0x8($t9)
    ctx->r1 = S32(MEM_W(ctx->r25, 0X8));
    // 0x800745DC: sw          $at, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r1;
    // 0x800745E0: lw          $t8, 0xC($t9)
    ctx->r24 = S32(MEM_W(ctx->r25, 0XC));
    // 0x800745E4: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x800745E8: lw          $at, 0x10($t9)
    ctx->r1 = S32(MEM_W(ctx->r25, 0X10));
    // 0x800745EC: sw          $at, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r1;
    // 0x800745F0: lbu         $at, 0x14($t9)
    ctx->r1 = MEM_BU(ctx->r25, 0X14);
    // 0x800745F4: sb          $at, 0x14($v1)
    MEM_B(0X14, ctx->r3) = ctx->r1;
    // 0x800745F8: lh          $v0, 0x0($t2)
    ctx->r2 = S32(MEM_H(ctx->r10, 0X0));
    // 0x800745FC: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80074600: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80074604: beq         $at, $zero, L_80074620
    if (ctx->r1 == 0) {
        // 0x80074608: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_80074620;
    }
    // 0x80074608: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8007460C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80074610: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80074614: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80074618: b           L_80074658
    // 0x8007461C: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
        goto L_80074658;
    // 0x8007461C: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
L_80074620:
    // 0x80074620: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x80074624: beq         $at, $zero, L_80074640
    if (ctx->r1 == 0) {
        // 0x80074628: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80074640;
    }
    // 0x80074628: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8007462C: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x80074630: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80074634: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x80074638: b           L_80074658
    // 0x8007463C: addiu       $t0, $t0, -0xC8
    ctx->r8 = ADD32(ctx->r8, -0XC8);
        goto L_80074658;
    // 0x8007463C: addiu       $t0, $t0, -0xC8
    ctx->r8 = ADD32(ctx->r8, -0XC8);
L_80074640:
    // 0x80074640: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80074644: beq         $at, $zero, L_80074658
    if (ctx->r1 == 0) {
        // 0x80074648: sll         $t9, $v0, 3
        ctx->r25 = S32(ctx->r2 << 3);
            goto L_80074658;
    }
    // 0x80074648: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x8007464C: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x80074650: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80074654: addiu       $t0, $t0, 0x7E
    ctx->r8 = ADD32(ctx->r8, 0X7E);
L_80074658:
    // 0x80074658: lh          $t6, 0x28A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x8007465C: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
    // 0x80074660: lbu         $a2, 0x0($t9)
    ctx->r6 = MEM_BU(ctx->r25, 0X0);
    // 0x80074664: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80074668: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x8007466C: subu        $a0, $t1, $t7
    ctx->r4 = SUB32(ctx->r9, ctx->r15);
    // 0x80074670: lbu         $t7, 0xAA($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XAA);
    // 0x80074674: addiu       $a2, $a2, 0xA0D
    ctx->r6 = ADD32(ctx->r6, 0XA0D);
    // 0x80074678: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8007467C: subu        $a1, $t4, $t0
    ctx->r5 = SUB32(ctx->r12, ctx->r8);
    // 0x80074680: addiu       $a1, $a1, 0xFA
    ctx->r5 = ADD32(ctx->r5, 0XFA);
    // 0x80074684: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80074688: addiu       $a0, $a0, 0xBE
    ctx->r4 = ADD32(ctx->r4, 0XBE);
    // 0x8007468C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074690: jal         0x800724B0
    // 0x80074694: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    myospal(rdram, ctx);
        goto after_56;
    // 0x80074694: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_56:
    // 0x80074698: b           L_80074C0C
    // 0x8007469C: nop

        goto L_80074C0C;
    // 0x8007469C: nop

L_800746A0:
    // 0x800746A0: lh          $t9, 0x28A($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x800746A4: lbu         $t6, 0xAA($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XAA);
    // 0x800746A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800746AC: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800746B0: subu        $a0, $t1, $t8
    ctx->r4 = SUB32(ctx->r9, ctx->r24);
    // 0x800746B4: addiu       $a0, $a0, 0xBE
    ctx->r4 = ADD32(ctx->r4, 0XBE);
    // 0x800746B8: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x800746BC: jal         0x800724B0
    // 0x800746C0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    myospal(rdram, ctx);
        goto after_57;
    // 0x800746C0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_57:
    // 0x800746C4: b           L_80074C0C
    // 0x800746C8: nop

        goto L_80074C0C;
    // 0x800746C8: nop

L_800746CC:
    // 0x800746CC: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800746D0: addiu       $t7, $t7, -0x1754
    ctx->r15 = ADD32(ctx->r15, -0X1754);
    // 0x800746D4: lw          $at, 0x0($t7)
    ctx->r1 = S32(MEM_W(ctx->r15, 0X0));
    // 0x800746D8: addiu       $t1, $sp, 0x64
    ctx->r9 = ADD32(ctx->r29, 0X64);
    // 0x800746DC: subu        $v1, $t4, $t0
    ctx->r3 = SUB32(ctx->r12, ctx->r8);
    // 0x800746E0: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x800746E4: lw          $t8, 0x4($t7)
    ctx->r24 = S32(MEM_W(ctx->r15, 0X4));
    // 0x800746E8: addiu       $a1, $v1, 0x102
    ctx->r5 = ADD32(ctx->r3, 0X102);
    // 0x800746EC: addiu       $a2, $zero, 0xA0A
    ctx->r6 = ADD32(0, 0XA0A);
    // 0x800746F0: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x800746F4: lwr         $at, 0xA($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0XA);
    // 0x800746F8: addiu       $t7, $zero, 0x66
    ctx->r15 = ADD32(0, 0X66);
    // 0x800746FC: swr         $at, 0xA($t1)
    do_swr(rdram, 0XA, ctx->r9, ctx->r1);
    // 0x80074700: lh          $v0, 0x2D4($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X2D4));
    // 0x80074704: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80074708: beq         $v0, $zero, L_80074750
    if (ctx->r2 == 0) {
        // 0x8007470C: addu        $t8, $t1, $v0
        ctx->r24 = ADD32(ctx->r9, ctx->r2);
            goto L_80074750;
    }
    // 0x8007470C: addu        $t8, $t1, $v0
    ctx->r24 = ADD32(ctx->r9, ctx->r2);
    // 0x80074710: lh          $t6, 0x28A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80074714: lb          $a2, 0x0($t8)
    ctx->r6 = S32(MEM_B(ctx->r24, 0X0));
    // 0x80074718: addiu       $t7, $zero, 0x66
    ctx->r15 = ADD32(0, 0X66);
    // 0x8007471C: sra         $t9, $t6, 1
    ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80074720: subu        $a0, $t7, $t9
    ctx->r4 = SUB32(ctx->r15, ctx->r25);
    // 0x80074724: lbu         $t9, 0xAA($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XAA);
    // 0x80074728: addiu       $a2, $a2, 0xA0A
    ctx->r6 = ADD32(ctx->r6, 0XA0A);
    // 0x8007472C: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80074730: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80074734: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074738: addiu       $a1, $v1, 0x102
    ctx->r5 = ADD32(ctx->r3, 0X102);
    // 0x8007473C: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80074740: jal         0x800724B0
    // 0x80074744: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    myospal(rdram, ctx);
        goto after_58;
    // 0x80074744: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_58:
    // 0x80074748: b           L_80074C0C
    // 0x8007474C: nop

        goto L_80074C0C;
    // 0x8007474C: nop

L_80074750:
    // 0x80074750: lh          $t8, 0x28A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80074754: lbu         $t9, 0xAA($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XAA);
    // 0x80074758: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007475C: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80074760: subu        $a0, $t7, $t6
    ctx->r4 = SUB32(ctx->r15, ctx->r14);
    // 0x80074764: jal         0x800724B0
    // 0x80074768: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    myospal(rdram, ctx);
        goto after_59;
    // 0x80074768: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_59:
    // 0x8007476C: b           L_80074C0C
    // 0x80074770: nop

        goto L_80074C0C;
    // 0x80074770: nop

L_80074774:
    // 0x80074774: lh          $v0, 0x2D4($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X2D4));
    // 0x80074778: addiu       $a2, $zero, 0xE36
    ctx->r6 = ADD32(0, 0XE36);
    // 0x8007477C: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80074780: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80074784: bne         $at, $zero, L_800747B8
    if (ctx->r1 != 0) {
        // 0x80074788: slti        $at, $v0, 0x8
        ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
            goto L_800747B8;
    }
    // 0x80074788: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8007478C: beq         $at, $zero, L_800747B8
    if (ctx->r1 == 0) {
        // 0x80074790: sll         $t8, $v0, 7
        ctx->r24 = S32(ctx->r2 << 7);
            goto L_800747B8;
    }
    // 0x80074790: sll         $t8, $v0, 7
    ctx->r24 = S32(ctx->r2 << 7);
    // 0x80074794: addiu       $t7, $t8, 0x400
    ctx->r15 = ADD32(ctx->r24, 0X400);
    // 0x80074798: andi        $t6, $t7, 0x7FF
    ctx->r14 = ctx->r15 & 0X7FF;
    // 0x8007479C: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800747A0: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x800747A4: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x800747A8: lh          $v1, -0x9A0($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, -0X9A0));
    // 0x800747AC: sra         $t8, $v1, 10
    ctx->r24 = S32(SIGNED(ctx->r3) >> 10);
    // 0x800747B0: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x800747B4: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
L_800747B8:
    // 0x800747B8: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800747BC: bne         $at, $zero, L_8007481C
    if (ctx->r1 != 0) {
        // 0x800747C0: subu        $v1, $t4, $t0
        ctx->r3 = SUB32(ctx->r12, ctx->r8);
            goto L_8007481C;
    }
    // 0x800747C0: subu        $v1, $t4, $t0
    ctx->r3 = SUB32(ctx->r12, ctx->r8);
    // 0x800747C4: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x800747C8: beq         $at, $zero, L_8007481C
    if (ctx->r1 == 0) {
        // 0x800747CC: addiu       $t0, $v0, -0x2
        ctx->r8 = ADD32(ctx->r2, -0X2);
            goto L_8007481C;
    }
    // 0x800747CC: addiu       $t0, $v0, -0x2
    ctx->r8 = ADD32(ctx->r2, -0X2);
    // 0x800747D0: lh          $t6, 0x28A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x800747D4: bgez        $t0, L_800747E4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800747D8: sra         $t7, $t0, 1
        ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
            goto L_800747E4;
    }
    // 0x800747D8: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x800747DC: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x800747E0: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_800747E4:
    // 0x800747E4: sra         $t9, $t6, 1
    ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800747E8: lbu         $t6, 0xAA($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XAA);
    // 0x800747EC: addiu       $a2, $t7, 0xE36
    ctx->r6 = ADD32(ctx->r15, 0XE36);
    // 0x800747F0: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800747F4: subu        $a0, $t1, $t9
    ctx->r4 = SUB32(ctx->r9, ctx->r25);
    // 0x800747F8: addiu       $a0, $a0, 0x136
    ctx->r4 = ADD32(ctx->r4, 0X136);
    // 0x800747FC: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80074800: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074804: addiu       $a1, $v1, 0x116
    ctx->r5 = ADD32(ctx->r3, 0X116);
    // 0x80074808: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x8007480C: jal         0x800724B0
    // 0x80074810: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    myospal(rdram, ctx);
        goto after_60;
    // 0x80074810: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_60:
    // 0x80074814: b           L_80074C0C
    // 0x80074818: nop

        goto L_80074C0C;
    // 0x80074818: nop

L_8007481C:
    // 0x8007481C: lh          $t9, 0x28A($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80074820: lbu         $t7, 0xAA($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XAA);
    // 0x80074824: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074828: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8007482C: subu        $a0, $t1, $t8
    ctx->r4 = SUB32(ctx->r9, ctx->r24);
    // 0x80074830: addiu       $a0, $a0, 0x136
    ctx->r4 = ADD32(ctx->r4, 0X136);
    // 0x80074834: addiu       $a1, $v1, 0x111
    ctx->r5 = ADD32(ctx->r3, 0X111);
    // 0x80074838: jal         0x800724B0
    // 0x8007483C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    myospal(rdram, ctx);
        goto after_61;
    // 0x8007483C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_61:
    // 0x80074840: b           L_80074C0C
    // 0x80074844: nop

        goto L_80074C0C;
    // 0x80074844: nop

L_80074848:
    // 0x80074848: lh          $t6, 0x2D4($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X2D4));
    // 0x8007484C: subu        $a1, $t4, $t0
    ctx->r5 = SUB32(ctx->r12, ctx->r8);
    // 0x80074850: addiu       $a1, $a1, 0x122
    ctx->r5 = ADD32(ctx->r5, 0X122);
    // 0x80074854: beq         $t6, $zero, L_800749E0
    if (ctx->r14 == 0) {
        // 0x80074858: addiu       $a2, $zero, 0x9F4
        ctx->r6 = ADD32(0, 0X9F4);
            goto L_800749E0;
    }
    // 0x80074858: addiu       $a2, $zero, 0x9F4
    ctx->r6 = ADD32(0, 0X9F4);
    // 0x8007485C: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x80074860: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80074864: jal         0x80071FC0
    // 0x80074868: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    fakekrand(rdram, ctx);
        goto after_62;
    // 0x80074868: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    after_62:
    // 0x8007486C: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80074870: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x80074874: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x80074878: jal         0x80071FC0
    // 0x8007487C: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    fakekrand(rdram, ctx);
        goto after_63;
    // 0x8007487C: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    after_63:
    // 0x80074880: lh          $t7, 0x2C2($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X2C2));
    // 0x80074884: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80074888: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8007488C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80074890: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80074894: ldc1        $f8, 0x52F0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X52F0);
    // 0x80074898: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8007489C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800748A0: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x800748A4: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x800748A8: lw          $t0, 0xCC($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x800748AC: div.d       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f0.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x800748B0: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800748B4: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x800748B8: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x800748BC: nop

    // 0x800748C0: bc1fl       L_800748D8
    if (!c1cs) {
        // 0x800748C4: cvt.s.d     $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f16.fl = CVT_S_D(ctx->f0.d);
            goto L_800748D8;
    }
    goto skip_14;
    // 0x800748C4: cvt.s.d     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f16.fl = CVT_S_D(ctx->f0.d);
    skip_14:
    // 0x800748C8: cvt.s.d     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f10.fl = CVT_S_D(ctx->f2.d);
    // 0x800748CC: b           L_800748DC
    // 0x800748D0: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
        goto L_800748DC;
    // 0x800748D0: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x800748D4: cvt.s.d     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f16.fl = CVT_S_D(ctx->f0.d);
L_800748D8:
    // 0x800748D8: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
L_800748DC:
    // 0x800748DC: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x800748E0: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x800748E4: jal         0x80071FC0
    // 0x800748E8: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    fakekrand(rdram, ctx);
        goto after_64;
    // 0x800748E8: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    after_64:
    // 0x800748EC: jal         0x80071FC0
    // 0x800748F0: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    fakekrand(rdram, ctx);
        goto after_65;
    // 0x800748F0: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    after_65:
    // 0x800748F4: jal         0x80071FC0
    // 0x800748F8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    fakekrand(rdram, ctx);
        goto after_66;
    // 0x800748F8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_66:
    // 0x800748FC: lw          $t8, 0x50($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X50));
    // 0x80074900: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80074904: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80074908: andi        $t7, $t8, 0xFF
    ctx->r15 = ctx->r24 & 0XFF;
    // 0x8007490C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80074910: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x80074914: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80074918: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8007491C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80074920: lh          $t6, 0x28A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80074924: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80074928: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8007492C: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x80074930: sra         $t9, $t6, 1
    ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80074934: lw          $t6, 0x54($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X54));
    // 0x80074938: subu        $a0, $t1, $t9
    ctx->r4 = SUB32(ctx->r9, ctx->r25);
    // 0x8007493C: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = S32(MEM_W(ctx->r29, 0X60));
    // 0x80074940: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x80074944: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80074948: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x8007494C: add.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f8.d + ctx->f2.d;
    // 0x80074950: lw          $t0, 0xCC($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80074954: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80074958: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8007495C: mul.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80074960: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80074964: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x80074968: subu        $v1, $t4, $t0
    ctx->r3 = SUB32(ctx->r12, ctx->r8);
    // 0x8007496C: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x80074970: addiu       $a1, $v1, 0xD7
    ctx->r5 = ADD32(ctx->r3, 0XD7);
    // 0x80074974: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80074978: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8007497C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80074980: addiu       $a0, $a0, 0xAF
    ctx->r4 = ADD32(ctx->r4, 0XAF);
    // 0x80074984: addiu       $a2, $zero, 0xF01
    ctx->r6 = ADD32(0, 0XF01);
    // 0x80074988: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8007498C: add.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f8.d + ctx->f2.d;
    // 0x80074990: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80074994: mul.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80074998: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8007499C: jal         0x800726B0
    // 0x800749A0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    displayflash(rdram, ctx);
        goto after_67;
    // 0x800749A0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_67:
    // 0x800749A4: lh          $t6, 0x28A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x800749A8: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800749AC: lw          $v1, 0x44($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800749B0: lbu         $t8, 0xAA($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XAA);
    // 0x800749B4: sra         $t9, $t6, 1
    ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800749B8: subu        $a0, $t1, $t9
    ctx->r4 = SUB32(ctx->r9, ctx->r25);
    // 0x800749BC: addiu       $a0, $a0, 0x9B
    ctx->r4 = ADD32(ctx->r4, 0X9B);
    // 0x800749C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800749C4: addiu       $a2, $zero, 0x9F4
    ctx->r6 = ADD32(0, 0X9F4);
    // 0x800749C8: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x800749CC: addiu       $a1, $v1, 0x122
    ctx->r5 = ADD32(ctx->r3, 0X122);
    // 0x800749D0: jal         0x800724B0
    // 0x800749D4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    myospal(rdram, ctx);
        goto after_68;
    // 0x800749D4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_68:
    // 0x800749D8: b           L_80074C0C
    // 0x800749DC: nop

        goto L_80074C0C;
    // 0x800749DC: nop

L_800749E0:
    // 0x800749E0: lh          $t7, 0x28A($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x800749E4: lbu         $t9, 0xAA($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XAA);
    // 0x800749E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800749EC: sra         $t6, $t7, 1
    ctx->r14 = S32(SIGNED(ctx->r15) >> 1);
    // 0x800749F0: subu        $a0, $t1, $t6
    ctx->r4 = SUB32(ctx->r9, ctx->r14);
    // 0x800749F4: addiu       $a0, $a0, 0x9B
    ctx->r4 = ADD32(ctx->r4, 0X9B);
    // 0x800749F8: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x800749FC: jal         0x800724B0
    // 0x80074A00: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    myospal(rdram, ctx);
        goto after_69;
    // 0x80074A00: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_69:
    // 0x80074A04: b           L_80074C0C
    // 0x80074A08: nop

        goto L_80074C0C;
    // 0x80074A08: nop

L_80074A0C:
    // 0x80074A0C: addiu       $t2, $s0, 0x2D4
    ctx->r10 = ADD32(ctx->r16, 0X2D4);
    // 0x80074A10: lh          $t8, 0x0($t2)
    ctx->r24 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80074A14: addiu       $t1, $t1, 0x1C
    ctx->r9 = ADD32(ctx->r9, 0X1C);
    // 0x80074A18: addiu       $t4, $t4, 0x12
    ctx->r12 = ADD32(ctx->r12, 0X12);
    // 0x80074A1C: blezl       $t8, L_80074A68
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80074A20: lh          $t9, 0x28A($s0)
        ctx->r25 = S32(MEM_H(ctx->r16, 0X28A));
            goto L_80074A68;
    }
    goto skip_15;
    // 0x80074A20: lh          $t9, 0x28A($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X28A));
    skip_15:
    // 0x80074A24: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x80074A28: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80074A2C: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80074A30: jal         0x80071FC0
    // 0x80074A34: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    fakekrand(rdram, ctx);
        goto after_70;
    // 0x80074A34: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    after_70:
    // 0x80074A38: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80074A3C: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x80074A40: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x80074A44: jal         0x80071FC0
    // 0x80074A48: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    fakekrand(rdram, ctx);
        goto after_71;
    // 0x80074A48: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    after_71:
    // 0x80074A4C: lw          $t0, 0xCC($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80074A50: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x80074A54: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80074A58: lw          $t2, 0x48($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80074A5C: lw          $t4, 0xC8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80074A60: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x80074A64: lh          $t9, 0x28A($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X28A));
L_80074A68:
    // 0x80074A68: lbu         $t7, 0xAA($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XAA);
    // 0x80074A6C: subu        $v1, $t4, $t0
    ctx->r3 = SUB32(ctx->r12, ctx->r8);
    // 0x80074A70: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80074A74: subu        $a0, $t1, $t8
    ctx->r4 = SUB32(ctx->r9, ctx->r24);
    // 0x80074A78: addiu       $t6, $v1, 0xD6
    ctx->r14 = ADD32(ctx->r3, 0XD6);
    // 0x80074A7C: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80074A80: addiu       $a0, $a0, 0xCE
    ctx->r4 = ADD32(ctx->r4, 0XCE);
    // 0x80074A84: addiu       $a1, $v1, 0xE3
    ctx->r5 = ADD32(ctx->r3, 0XE3);
    // 0x80074A88: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80074A8C: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80074A90: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80074A94: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074A98: addiu       $a2, $zero, 0x9FC
    ctx->r6 = ADD32(0, 0X9FC);
    // 0x80074A9C: lb          $a3, 0xA9($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80074AA0: jal         0x800724B0
    // 0x80074AA4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    myospal(rdram, ctx);
        goto after_72;
    // 0x80074AA4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_72:
    // 0x80074AA8: lh          $t9, 0x29C($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X29C));
    // 0x80074AAC: lw          $v1, 0x44($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80074AB0: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80074AB4: blez        $t9, L_80074AC4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80074AB8: lw          $t2, 0x48($sp)
        ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
            goto L_80074AC4;
    }
    // 0x80074AB8: lw          $t2, 0x48($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80074ABC: b           L_80074AD4
    // 0x80074AC0: addiu       $v0, $zero, -0x20
    ctx->r2 = ADD32(0, -0X20);
        goto L_80074AD4;
    // 0x80074AC0: addiu       $v0, $zero, -0x20
    ctx->r2 = ADD32(0, -0X20);
L_80074AC4:
    // 0x80074AC4: lb          $v0, 0xA9($sp)
    ctx->r2 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80074AC8: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80074ACC: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80074AD0: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
L_80074AD4:
    // 0x80074AD4: lh          $t6, 0x28A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80074AD8: sll         $a3, $v0, 24
    ctx->r7 = S32(ctx->r2 << 24);
    // 0x80074ADC: sra         $t8, $a3, 24
    ctx->r24 = S32(SIGNED(ctx->r7) >> 24);
    // 0x80074AE0: sra         $t9, $t6, 1
    ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80074AE4: subu        $a0, $t1, $t9
    ctx->r4 = SUB32(ctx->r9, ctx->r25);
    // 0x80074AE8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80074AEC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80074AF0: addiu       $a0, $a0, 0x95
    ctx->r4 = ADD32(ctx->r4, 0X95);
    // 0x80074AF4: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80074AF8: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80074AFC: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80074B00: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80074B04: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074B08: lw          $a1, 0x40($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X40));
    // 0x80074B0C: jal         0x800724B0
    // 0x80074B10: addiu       $a2, $zero, 0xF2C
    ctx->r6 = ADD32(0, 0XF2C);
    myospal(rdram, ctx);
        goto after_73;
    // 0x80074B10: addiu       $a2, $zero, 0xF2C
    ctx->r6 = ADD32(0, 0XF2C);
    after_73:
    // 0x80074B14: lh          $t6, 0x29A($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X29A));
    // 0x80074B18: lw          $v1, 0x44($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80074B1C: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80074B20: blez        $t6, L_80074B30
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80074B24: lw          $t2, 0x48($sp)
        ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
            goto L_80074B30;
    }
    // 0x80074B24: lw          $t2, 0x48($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80074B28: b           L_80074B40
    // 0x80074B2C: addiu       $v0, $zero, -0x20
    ctx->r2 = ADD32(0, -0X20);
        goto L_80074B40;
    // 0x80074B2C: addiu       $v0, $zero, -0x20
    ctx->r2 = ADD32(0, -0X20);
L_80074B30:
    // 0x80074B30: lb          $v0, 0xA9($sp)
    ctx->r2 = S32(MEM_B(ctx->r29, 0XA9));
    // 0x80074B34: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80074B38: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80074B3C: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
L_80074B40:
    // 0x80074B40: lh          $t7, 0x28A($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80074B44: sll         $a3, $v0, 24
    ctx->r7 = S32(ctx->r2 << 24);
    // 0x80074B48: sra         $t9, $a3, 24
    ctx->r25 = S32(SIGNED(ctx->r7) >> 24);
    // 0x80074B4C: sra         $t6, $t7, 1
    ctx->r14 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80074B50: subu        $a0, $t1, $t6
    ctx->r4 = SUB32(ctx->r9, ctx->r14);
    // 0x80074B54: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80074B58: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80074B5C: addiu       $a0, $a0, 0x9B
    ctx->r4 = ADD32(ctx->r4, 0X9B);
    // 0x80074B60: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80074B64: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80074B68: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80074B6C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80074B70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074B74: addiu       $a1, $v1, 0xDD
    ctx->r5 = ADD32(ctx->r3, 0XDD);
    // 0x80074B78: jal         0x800724B0
    // 0x80074B7C: addiu       $a2, $zero, 0xF2E
    ctx->r6 = ADD32(0, 0XF2E);
    myospal(rdram, ctx);
        goto after_74;
    // 0x80074B7C: addiu       $a2, $zero, 0xF2E
    ctx->r6 = ADD32(0, 0XF2E);
    after_74:
    // 0x80074B80: lh          $t7, 0x2E4($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X2E4));
    // 0x80074B84: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80074B88: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80074B8C: andi        $t6, $t7, 0x7FF
    ctx->r14 = ctx->r15 & 0X7FF;
    // 0x80074B90: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x80074B94: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80074B98: lh          $v0, -0x9A0($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X9A0));
    // 0x80074B9C: lw          $t9, 0x3C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80074BA0: lw          $v1, 0x44($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80074BA4: sra         $t8, $v0, 10
    ctx->r24 = S32(SIGNED(ctx->r2) >> 10);
    // 0x80074BA8: negu        $v0, $t8
    ctx->r2 = SUB32(0, ctx->r24);
    // 0x80074BAC: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x80074BB0: lw          $t1, 0xC0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x80074BB4: lw          $t2, 0x48($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80074BB8: bne         $t9, $at, L_80074BC8
    if (ctx->r25 != ctx->r1) {
        // 0x80074BBC: sra         $v0, $t7, 16
        ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
            goto L_80074BC8;
    }
    // 0x80074BBC: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80074BC0: b           L_80074BCC
    // 0x80074BC4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
        goto L_80074BCC;
    // 0x80074BC4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_80074BC8:
    // 0x80074BC8: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
L_80074BCC:
    // 0x80074BCC: lh          $t8, 0x0($t2)
    ctx->r24 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80074BD0: addiu       $a1, $v1, 0xCB
    ctx->r5 = ADD32(ctx->r3, 0XCB);
    // 0x80074BD4: addiu       $a2, $zero, 0xF2D
    ctx->r6 = ADD32(0, 0XF2D);
    // 0x80074BD8: blezl       $t8, L_80074BE8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80074BDC: lh          $t7, 0x28A($s0)
        ctx->r15 = S32(MEM_H(ctx->r16, 0X28A));
            goto L_80074BE8;
    }
    goto skip_16;
    // 0x80074BDC: lh          $t7, 0x28A($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X28A));
    skip_16:
    // 0x80074BE0: addiu       $v0, $zero, -0x20
    ctx->r2 = ADD32(0, -0X20);
    // 0x80074BE4: lh          $t7, 0x28A($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X28A));
L_80074BE8:
    // 0x80074BE8: sll         $a3, $v0, 24
    ctx->r7 = S32(ctx->r2 << 24);
    // 0x80074BEC: sra         $t9, $a3, 24
    ctx->r25 = S32(SIGNED(ctx->r7) >> 24);
    // 0x80074BF0: sra         $t6, $t7, 1
    ctx->r14 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80074BF4: subu        $a0, $t1, $t6
    ctx->r4 = SUB32(ctx->r9, ctx->r14);
    // 0x80074BF8: addiu       $a0, $a0, 0xAB
    ctx->r4 = ADD32(ctx->r4, 0XAB);
    // 0x80074BFC: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80074C00: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80074C04: jal         0x800724B0
    // 0x80074C08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    myospal(rdram, ctx);
        goto after_75;
    // 0x80074C08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_75:
L_80074C0C:
    // 0x80074C0C: jal         0x800728D8
    // 0x80074C10: lh          $a0, 0xD2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XD2));
    displayloogie(rdram, ctx);
        goto after_76;
    // 0x80074C10: lh          $a0, 0xD2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XD2));
    after_76:
L_80074C14:
    // 0x80074C14: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
L_80074C18:
    // 0x80074C18: lw          $s0, 0x28($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80074C1C: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    // 0x80074C20: jr          $ra
    // 0x80074C24: nop

    return;
    // 0x80074C24: nop

;}
RECOMP_FUNC void func_80062AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062AD0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80062AD4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80062AD8: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80062ADC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80062AE0: addiu       $t7, $t7, -0x1988
    ctx->r15 = ADD32(ctx->r15, -0X1988);
    // 0x80062AE4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80062AE8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80062AEC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80062AF0: lhu         $s1, 0x20($v0)
    ctx->r17 = MEM_HU(ctx->r2, 0X20);
    // 0x80062AF4: lui         $at, 0x802C
    ctx->r1 = S32(0X802C << 16);
    // 0x80062AF8: lbu         $t9, 0x23($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X23);
    // 0x80062AFC: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80062B00: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80062B04: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80062B08: ori         $at, $at, 0x5000
    ctx->r1 = ctx->r1 | 0X5000;
    // 0x80062B0C: addu        $s1, $t8, $at
    ctx->r17 = ADD32(ctx->r24, ctx->r1);
    // 0x80062B10: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80062B14: sb          $t9, -0x298C($at)
    MEM_B(-0X298C, ctx->r1) = ctx->r25;
    // 0x80062B18: lb          $t0, 0x22($v0)
    ctx->r8 = S32(MEM_B(ctx->r2, 0X22));
    // 0x80062B1C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80062B20: lui         $s7, 0x8022
    ctx->r23 = S32(0X8022 << 16);
    // 0x80062B24: addiu       $s7, $s7, -0x234C
    ctx->r23 = ADD32(ctx->r23, -0X234C);
    // 0x80062B28: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x80062B2C: sw          $t0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r8;
    // 0x80062B30: sw          $zero, -0x3C70($at)
    MEM_W(-0X3C70, ctx->r1) = 0;
    // 0x80062B34: lbu         $t1, 0x2C($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2C);
    // 0x80062B38: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80062B3C: lui         $fp, 0x8026
    ctx->r30 = S32(0X8026 << 16);
    // 0x80062B40: addiu       $fp, $fp, -0x3C76
    ctx->r30 = ADD32(ctx->r30, -0X3C76);
    // 0x80062B44: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80062B48: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80062B4C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80062B50: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80062B54: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80062B58: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80062B5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80062B60: sh          $zero, 0x0($fp)
    MEM_H(0X0, ctx->r30) = 0;
    // 0x80062B64: blez        $t1, L_80062D5C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80062B68: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_80062D5C;
    }
    // 0x80062B68: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80062B6C: lui         $s4, 0x8022
    ctx->r20 = S32(0X8022 << 16);
    // 0x80062B70: lui         $s3, 0x8022
    ctx->r19 = S32(0X8022 << 16);
    // 0x80062B74: lui         $s2, 0x8022
    ctx->r18 = S32(0X8022 << 16);
    // 0x80062B78: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80062B7C: addiu       $s0, $s0, -0x537C
    ctx->r16 = ADD32(ctx->r16, -0X537C);
    // 0x80062B80: addiu       $s2, $s2, -0x2980
    ctx->r18 = ADD32(ctx->r18, -0X2980);
    // 0x80062B84: addiu       $s3, $s3, -0x2958
    ctx->r19 = ADD32(ctx->r19, -0X2958);
    // 0x80062B88: addiu       $s4, $s4, -0x2930
    ctx->r20 = ADD32(ctx->r20, -0X2930);
    // 0x80062B8C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80062B90: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // 0x80062B94: lh          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_H(ctx->r17, 0X0));
L_80062B98:
    // 0x80062B98: lh          $a1, 0x2($s1)
    ctx->r5 = S32(MEM_H(ctx->r17, 0X2));
    // 0x80062B9C: lh          $a2, 0x4($s1)
    ctx->r6 = S32(MEM_H(ctx->r17, 0X4));
    // 0x80062BA0: jal         0x80062D98
    // 0x80062BA4: lh          $a3, 0x2($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X2));
    func_80062D98(rdram, ctx);
        goto after_0;
    // 0x80062BA4: lh          $a3, 0x2($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X2));
    after_0:
    // 0x80062BA8: lh          $t2, 0x0($s1)
    ctx->r10 = S32(MEM_H(ctx->r17, 0X0));
    // 0x80062BAC: lw          $t3, 0x0($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062BB0: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80062BB4: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x80062BB8: lw          $t5, 0x0($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062BBC: lh          $t4, -0x8($s1)
    ctx->r12 = S32(MEM_H(ctx->r17, -0X8));
    // 0x80062BC0: sh          $t4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r12;
    // 0x80062BC4: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062BC8: lh          $t6, -0x6($s1)
    ctx->r14 = S32(MEM_H(ctx->r17, -0X6));
    // 0x80062BCC: sh          $t6, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r14;
    // 0x80062BD0: lw          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062BD4: lh          $t8, -0x4($s1)
    ctx->r24 = S32(MEM_H(ctx->r17, -0X4));
    // 0x80062BD8: sh          $t8, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r24;
    // 0x80062BDC: lw          $t1, 0x0($s0)
    ctx->r9 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062BE0: lh          $t0, -0x2($s1)
    ctx->r8 = S32(MEM_H(ctx->r17, -0X2));
    // 0x80062BE4: sh          $t0, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r8;
    // 0x80062BE8: lw          $t3, 0x0($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062BEC: lw          $t2, 0x0($s2)
    ctx->r10 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80062BF0: sb          $t2, 0xC($t3)
    MEM_B(0XC, ctx->r11) = ctx->r10;
    // 0x80062BF4: lw          $t5, 0x0($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062BF8: lw          $t4, 0x0($s3)
    ctx->r12 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80062BFC: sb          $t4, 0xD($t5)
    MEM_B(0XD, ctx->r13) = ctx->r12;
    // 0x80062C00: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062C04: lw          $t6, 0x0($s4)
    ctx->r14 = S32(MEM_W(ctx->r20, 0X0));
    // 0x80062C08: sb          $t6, 0xE($t7)
    MEM_B(0XE, ctx->r15) = ctx->r14;
    // 0x80062C0C: lw          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062C10: sb          $s5, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r21;
    // 0x80062C14: lw          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062C18: lh          $a3, 0x2($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X2));
    // 0x80062C1C: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x80062C20: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80062C24: lh          $a2, 0x4($s1)
    ctx->r6 = S32(MEM_H(ctx->r17, 0X4));
    // 0x80062C28: lh          $a1, 0x2($s1)
    ctx->r5 = S32(MEM_H(ctx->r17, 0X2));
    // 0x80062C2C: jal         0x80062D98
    // 0x80062C30: lh          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_H(ctx->r17, 0X0));
    func_80062D98(rdram, ctx);
        goto after_1;
    // 0x80062C30: lh          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_H(ctx->r17, 0X0));
    after_1:
    // 0x80062C34: lh          $t1, 0x0($s1)
    ctx->r9 = S32(MEM_H(ctx->r17, 0X0));
    // 0x80062C38: lw          $t2, 0x0($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062C3C: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80062C40: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x80062C44: lw          $t4, 0x0($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062C48: lh          $t3, -0x8($s1)
    ctx->r11 = S32(MEM_H(ctx->r17, -0X8));
    // 0x80062C4C: sh          $t3, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r11;
    // 0x80062C50: lw          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062C54: lh          $t5, -0x6($s1)
    ctx->r13 = S32(MEM_H(ctx->r17, -0X6));
    // 0x80062C58: sh          $t5, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r13;
    // 0x80062C5C: lw          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062C60: lh          $t7, -0x4($s1)
    ctx->r15 = S32(MEM_H(ctx->r17, -0X4));
    // 0x80062C64: sh          $t7, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r15;
    // 0x80062C68: lw          $t0, 0x0($s0)
    ctx->r8 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062C6C: lh          $t9, -0x2($s1)
    ctx->r25 = S32(MEM_H(ctx->r17, -0X2));
    // 0x80062C70: sh          $t9, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r25;
    // 0x80062C74: lw          $t2, 0x0($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062C78: lw          $t1, 0x0($s2)
    ctx->r9 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80062C7C: sb          $t1, 0xC($t2)
    MEM_B(0XC, ctx->r10) = ctx->r9;
    // 0x80062C80: lw          $t4, 0x0($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062C84: lw          $t3, 0x0($s3)
    ctx->r11 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80062C88: sb          $t3, 0xD($t4)
    MEM_B(0XD, ctx->r12) = ctx->r11;
    // 0x80062C8C: lw          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062C90: lw          $t5, 0x0($s4)
    ctx->r13 = S32(MEM_W(ctx->r20, 0X0));
    // 0x80062C94: sb          $t5, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r13;
    // 0x80062C98: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062C9C: sb          $s5, 0xF($t7)
    MEM_B(0XF, ctx->r15) = ctx->r21;
    // 0x80062CA0: lw          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062CA4: lh          $a3, 0x2($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X2));
    // 0x80062CA8: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x80062CAC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80062CB0: lh          $a2, 0x4($s1)
    ctx->r6 = S32(MEM_H(ctx->r17, 0X4));
    // 0x80062CB4: lh          $a1, 0x2($s1)
    ctx->r5 = S32(MEM_H(ctx->r17, 0X2));
    // 0x80062CB8: jal         0x80062D98
    // 0x80062CBC: lh          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_H(ctx->r17, 0X0));
    func_80062D98(rdram, ctx);
        goto after_2;
    // 0x80062CBC: lh          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_H(ctx->r17, 0X0));
    after_2:
    // 0x80062CC0: lh          $t0, 0x0($s1)
    ctx->r8 = S32(MEM_H(ctx->r17, 0X0));
    // 0x80062CC4: lw          $t1, 0x0($s0)
    ctx->r9 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062CC8: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80062CCC: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80062CD0: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x80062CD4: lw          $t3, 0x0($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062CD8: lh          $t2, -0x8($s1)
    ctx->r10 = S32(MEM_H(ctx->r17, -0X8));
    // 0x80062CDC: sh          $t2, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r10;
    // 0x80062CE0: lw          $t5, 0x0($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062CE4: lh          $t4, -0x6($s1)
    ctx->r12 = S32(MEM_H(ctx->r17, -0X6));
    // 0x80062CE8: sh          $t4, 0x4($t5)
    MEM_H(0X4, ctx->r13) = ctx->r12;
    // 0x80062CEC: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062CF0: lh          $t6, -0x4($s1)
    ctx->r14 = S32(MEM_H(ctx->r17, -0X4));
    // 0x80062CF4: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x80062CF8: lw          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062CFC: lh          $t8, -0x2($s1)
    ctx->r24 = S32(MEM_H(ctx->r17, -0X2));
    // 0x80062D00: sh          $t8, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r24;
    // 0x80062D04: lw          $t1, 0x0($s0)
    ctx->r9 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062D08: lw          $t0, 0x0($s2)
    ctx->r8 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80062D0C: sb          $t0, 0xC($t1)
    MEM_B(0XC, ctx->r9) = ctx->r8;
    // 0x80062D10: lw          $t3, 0x0($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062D14: lw          $t2, 0x0($s3)
    ctx->r10 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80062D18: sb          $t2, 0xD($t3)
    MEM_B(0XD, ctx->r11) = ctx->r10;
    // 0x80062D1C: lw          $t5, 0x0($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062D20: lw          $t4, 0x0($s4)
    ctx->r12 = S32(MEM_W(ctx->r20, 0X0));
    // 0x80062D24: sb          $t4, 0xE($t5)
    MEM_B(0XE, ctx->r13) = ctx->r12;
    // 0x80062D28: lw          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062D2C: sb          $s5, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r21;
    // 0x80062D30: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062D34: lh          $t9, 0x0($fp)
    ctx->r25 = S32(MEM_H(ctx->r30, 0X0));
    // 0x80062D38: lw          $t1, 0x44($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80062D3C: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x80062D40: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80062D44: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80062D48: sh          $t0, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r8;
    // 0x80062D4C: lbu         $t2, 0x2C($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2C);
    // 0x80062D50: slt         $at, $s6, $t2
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80062D54: bnel        $at, $zero, L_80062B98
    if (ctx->r1 != 0) {
        // 0x80062D58: lh          $a0, 0x0($s1)
        ctx->r4 = S32(MEM_H(ctx->r17, 0X0));
            goto L_80062B98;
    }
    goto skip_0;
    // 0x80062D58: lh          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_H(ctx->r17, 0X0));
    skip_0:
L_80062D5C:
    // 0x80062D5C: lh          $t3, 0x0($fp)
    ctx->r11 = S32(MEM_H(ctx->r30, 0X0));
    // 0x80062D60: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80062D64: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x80062D68: lw          $fp, 0x38($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80062D6C: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80062D70: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80062D74: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80062D78: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80062D7C: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80062D80: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80062D84: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80062D88: lw          $s7, 0x34($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80062D8C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80062D90: jr          $ra
    // 0x80062D94: sw          $t3, -0x3C70($at)
    MEM_W(-0X3C70, ctx->r1) = ctx->r11;
    return;
    // 0x80062D94: sw          $t3, -0x3C70($at)
    MEM_W(-0X3C70, ctx->r1) = ctx->r11;
;}
RECOMP_FUNC void adjustfloorpanning(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B1CC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005B1D0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005B1D4: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8005B1D8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8005B1DC: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8005B1E0: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8005B1E4: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x8005B1E8: addiu       $t8, $t8, -0x1988
    ctx->r24 = ADD32(ctx->r24, -0X1988);
    // 0x8005B1EC: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8005B1F0: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8005B1F4: lhu         $a3, 0x1E($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X1E);
    // 0x8005B1F8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8005B1FC: or          $t9, $a2, $zero
    ctx->r25 = ctx->r6 | 0;
    // 0x8005B200: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8005B204: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x8005B208: lui         $at, 0x802C
    ctx->r1 = S32(0X802C << 16);
    // 0x8005B20C: addu        $t9, $t9, $a3
    ctx->r25 = ADD32(ctx->r25, ctx->r7);
    // 0x8005B210: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8005B214: ori         $at, $at, 0x5000
    ctx->r1 = ctx->r1 | 0X5000;
    // 0x8005B218: lbu         $t1, 0x2B($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X2B);
    // 0x8005B21C: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8005B220: addu        $a3, $t9, $at
    ctx->r7 = ADD32(ctx->r25, ctx->r1);
    // 0x8005B224: sll         $t7, $t6, 19
    ctx->r15 = S32(ctx->r14 << 19);
    // 0x8005B228: or          $t9, $a2, $zero
    ctx->r25 = ctx->r6 | 0;
    // 0x8005B22C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8005B230: sll         $t6, $t9, 19
    ctx->r14 = S32(ctx->r25 << 19);
    // 0x8005B234: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8005B238: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8005B23C: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8005B240: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8005B244: blez        $t1, L_8005B464
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8005B248: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8005B464;
    }
    // 0x8005B248: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005B24C: addiu       $s1, $sp, 0x1C
    ctx->r17 = ADD32(ctx->r29, 0X1C);
    // 0x8005B250: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
L_8005B254:
    // 0x8005B254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005B258:
    // 0x8005B258: lh          $t8, 0x6($a3)
    ctx->r24 = S32(MEM_H(ctx->r7, 0X6));
    // 0x8005B25C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8005B260: addu        $t6, $s0, $v1
    ctx->r14 = ADD32(ctx->r16, ctx->r3);
    // 0x8005B264: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x8005B268: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8005B26C: lh          $t7, 0x8($a3)
    ctx->r15 = S32(MEM_H(ctx->r7, 0X8));
    // 0x8005B270: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005B274: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x8005B278: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8005B27C: addu        $t9, $s1, $v1
    ctx->r25 = ADD32(ctx->r17, ctx->r3);
    // 0x8005B280: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x8005B284: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8005B288: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8005B28C: bne         $at, $zero, L_8005B258
    if (ctx->r1 != 0) {
        // 0x8005B290: addiu       $a3, $a3, 0xA
        ctx->r7 = ADD32(ctx->r7, 0XA);
            goto L_8005B258;
    }
    // 0x8005B290: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    // 0x8005B294: lw          $v1, 0x28($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8005B298: lw          $a0, 0x2C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8005B29C: lw          $t2, 0x30($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8005B2A0: slti        $at, $v1, 0x7FF8
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF8 ? 1 : 0;
    // 0x8005B2A4: lw          $t3, 0x1C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8005B2A8: lw          $t4, 0x20($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8005B2AC: bne         $at, $zero, L_8005B2C8
    if (ctx->r1 != 0) {
        // 0x8005B2B0: lw          $t5, 0x24($sp)
        ctx->r13 = S32(MEM_W(ctx->r29, 0X24));
            goto L_8005B2C8;
    }
    // 0x8005B2B0: lw          $t5, 0x24($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8005B2B4: slti        $at, $a0, 0x7FF8
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF8 ? 1 : 0;
    // 0x8005B2B8: bne         $at, $zero, L_8005B2C8
    if (ctx->r1 != 0) {
        // 0x8005B2BC: slti        $at, $t2, 0x7FF8
        ctx->r1 = SIGNED(ctx->r10) < 0X7FF8 ? 1 : 0;
            goto L_8005B2C8;
    }
    // 0x8005B2BC: slti        $at, $t2, 0x7FF8
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF8 ? 1 : 0;
    // 0x8005B2C0: beql        $at, $zero, L_8005B2F8
    if (ctx->r1 == 0) {
        // 0x8005B2C4: slti        $at, $v1, 0x7FF9
        ctx->r1 = SIGNED(ctx->r3) < 0X7FF9 ? 1 : 0;
            goto L_8005B2F8;
    }
    goto skip_0;
    // 0x8005B2C4: slti        $at, $v1, 0x7FF9
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF9 ? 1 : 0;
    skip_0:
L_8005B2C8:
    // 0x8005B2C8: addiu       $v1, $v1, 0x1000
    ctx->r3 = ADD32(ctx->r3, 0X1000);
L_8005B2CC:
    // 0x8005B2CC: slti        $at, $v1, 0x7FF8
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF8 ? 1 : 0;
    // 0x8005B2D0: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x8005B2D4: bne         $at, $zero, L_8005B2C8
    if (ctx->r1 != 0) {
        // 0x8005B2D8: addiu       $t2, $t2, 0x1000
        ctx->r10 = ADD32(ctx->r10, 0X1000);
            goto L_8005B2C8;
    }
    // 0x8005B2D8: addiu       $t2, $t2, 0x1000
    ctx->r10 = ADD32(ctx->r10, 0X1000);
    // 0x8005B2DC: slti        $at, $a0, 0x7FF8
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF8 ? 1 : 0;
    // 0x8005B2E0: bnel        $at, $zero, L_8005B2CC
    if (ctx->r1 != 0) {
        // 0x8005B2E4: addiu       $v1, $v1, 0x1000
        ctx->r3 = ADD32(ctx->r3, 0X1000);
            goto L_8005B2CC;
    }
    goto skip_1;
    // 0x8005B2E4: addiu       $v1, $v1, 0x1000
    ctx->r3 = ADD32(ctx->r3, 0X1000);
    skip_1:
    // 0x8005B2E8: slti        $at, $t2, 0x7FF8
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF8 ? 1 : 0;
    // 0x8005B2EC: bnel        $at, $zero, L_8005B2CC
    if (ctx->r1 != 0) {
        // 0x8005B2F0: addiu       $v1, $v1, 0x1000
        ctx->r3 = ADD32(ctx->r3, 0X1000);
            goto L_8005B2CC;
    }
    goto skip_2;
    // 0x8005B2F0: addiu       $v1, $v1, 0x1000
    ctx->r3 = ADD32(ctx->r3, 0X1000);
    skip_2:
    // 0x8005B2F4: slti        $at, $v1, 0x7FF9
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF9 ? 1 : 0;
L_8005B2F8:
    // 0x8005B2F8: beq         $at, $zero, L_8005B314
    if (ctx->r1 == 0) {
        // 0x8005B2FC: addiu       $a3, $a3, -0x1E
        ctx->r7 = ADD32(ctx->r7, -0X1E);
            goto L_8005B314;
    }
    // 0x8005B2FC: addiu       $a3, $a3, -0x1E
    ctx->r7 = ADD32(ctx->r7, -0X1E);
    // 0x8005B300: slti        $at, $a0, 0x7FF9
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF9 ? 1 : 0;
    // 0x8005B304: beq         $at, $zero, L_8005B314
    if (ctx->r1 == 0) {
        // 0x8005B308: slti        $at, $t2, 0x7FF9
        ctx->r1 = SIGNED(ctx->r10) < 0X7FF9 ? 1 : 0;
            goto L_8005B314;
    }
    // 0x8005B308: slti        $at, $t2, 0x7FF9
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF9 ? 1 : 0;
    // 0x8005B30C: bnel        $at, $zero, L_8005B344
    if (ctx->r1 != 0) {
        // 0x8005B310: slti        $at, $t3, 0x7FF8
        ctx->r1 = SIGNED(ctx->r11) < 0X7FF8 ? 1 : 0;
            goto L_8005B344;
    }
    goto skip_3;
    // 0x8005B310: slti        $at, $t3, 0x7FF8
    ctx->r1 = SIGNED(ctx->r11) < 0X7FF8 ? 1 : 0;
    skip_3:
L_8005B314:
    // 0x8005B314: addiu       $v1, $v1, -0x1000
    ctx->r3 = ADD32(ctx->r3, -0X1000);
L_8005B318:
    // 0x8005B318: slti        $at, $v1, 0x7FF9
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF9 ? 1 : 0;
    // 0x8005B31C: addiu       $a0, $a0, -0x1000
    ctx->r4 = ADD32(ctx->r4, -0X1000);
    // 0x8005B320: beq         $at, $zero, L_8005B314
    if (ctx->r1 == 0) {
        // 0x8005B324: addiu       $t2, $t2, -0x1000
        ctx->r10 = ADD32(ctx->r10, -0X1000);
            goto L_8005B314;
    }
    // 0x8005B324: addiu       $t2, $t2, -0x1000
    ctx->r10 = ADD32(ctx->r10, -0X1000);
    // 0x8005B328: slti        $at, $a0, 0x7FF9
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF9 ? 1 : 0;
    // 0x8005B32C: beql        $at, $zero, L_8005B318
    if (ctx->r1 == 0) {
        // 0x8005B330: addiu       $v1, $v1, -0x1000
        ctx->r3 = ADD32(ctx->r3, -0X1000);
            goto L_8005B318;
    }
    goto skip_4;
    // 0x8005B330: addiu       $v1, $v1, -0x1000
    ctx->r3 = ADD32(ctx->r3, -0X1000);
    skip_4:
    // 0x8005B334: slti        $at, $t2, 0x7FF9
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF9 ? 1 : 0;
    // 0x8005B338: beql        $at, $zero, L_8005B318
    if (ctx->r1 == 0) {
        // 0x8005B33C: addiu       $v1, $v1, -0x1000
        ctx->r3 = ADD32(ctx->r3, -0X1000);
            goto L_8005B318;
    }
    goto skip_5;
    // 0x8005B33C: addiu       $v1, $v1, -0x1000
    ctx->r3 = ADD32(ctx->r3, -0X1000);
    skip_5:
    // 0x8005B340: slti        $at, $t3, 0x7FF8
    ctx->r1 = SIGNED(ctx->r11) < 0X7FF8 ? 1 : 0;
L_8005B344:
    // 0x8005B344: bne         $at, $zero, L_8005B360
    if (ctx->r1 != 0) {
        // 0x8005B348: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005B360;
    }
    // 0x8005B348: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005B34C: slti        $at, $t4, 0x7FF8
    ctx->r1 = SIGNED(ctx->r12) < 0X7FF8 ? 1 : 0;
    // 0x8005B350: bne         $at, $zero, L_8005B360
    if (ctx->r1 != 0) {
        // 0x8005B354: slti        $at, $t5, 0x7FF8
        ctx->r1 = SIGNED(ctx->r13) < 0X7FF8 ? 1 : 0;
            goto L_8005B360;
    }
    // 0x8005B354: slti        $at, $t5, 0x7FF8
    ctx->r1 = SIGNED(ctx->r13) < 0X7FF8 ? 1 : 0;
    // 0x8005B358: beql        $at, $zero, L_8005B390
    if (ctx->r1 == 0) {
        // 0x8005B35C: slti        $at, $t3, 0x7FF9
        ctx->r1 = SIGNED(ctx->r11) < 0X7FF9 ? 1 : 0;
            goto L_8005B390;
    }
    goto skip_6;
    // 0x8005B35C: slti        $at, $t3, 0x7FF9
    ctx->r1 = SIGNED(ctx->r11) < 0X7FF9 ? 1 : 0;
    skip_6:
L_8005B360:
    // 0x8005B360: addiu       $t3, $t3, 0x1000
    ctx->r11 = ADD32(ctx->r11, 0X1000);
L_8005B364:
    // 0x8005B364: slti        $at, $t3, 0x7FF8
    ctx->r1 = SIGNED(ctx->r11) < 0X7FF8 ? 1 : 0;
    // 0x8005B368: addiu       $t4, $t4, 0x1000
    ctx->r12 = ADD32(ctx->r12, 0X1000);
    // 0x8005B36C: bne         $at, $zero, L_8005B360
    if (ctx->r1 != 0) {
        // 0x8005B370: addiu       $t5, $t5, 0x1000
        ctx->r13 = ADD32(ctx->r13, 0X1000);
            goto L_8005B360;
    }
    // 0x8005B370: addiu       $t5, $t5, 0x1000
    ctx->r13 = ADD32(ctx->r13, 0X1000);
    // 0x8005B374: slti        $at, $t4, 0x7FF8
    ctx->r1 = SIGNED(ctx->r12) < 0X7FF8 ? 1 : 0;
    // 0x8005B378: bnel        $at, $zero, L_8005B364
    if (ctx->r1 != 0) {
        // 0x8005B37C: addiu       $t3, $t3, 0x1000
        ctx->r11 = ADD32(ctx->r11, 0X1000);
            goto L_8005B364;
    }
    goto skip_7;
    // 0x8005B37C: addiu       $t3, $t3, 0x1000
    ctx->r11 = ADD32(ctx->r11, 0X1000);
    skip_7:
    // 0x8005B380: slti        $at, $t5, 0x7FF8
    ctx->r1 = SIGNED(ctx->r13) < 0X7FF8 ? 1 : 0;
    // 0x8005B384: bnel        $at, $zero, L_8005B364
    if (ctx->r1 != 0) {
        // 0x8005B388: addiu       $t3, $t3, 0x1000
        ctx->r11 = ADD32(ctx->r11, 0X1000);
            goto L_8005B364;
    }
    goto skip_8;
    // 0x8005B388: addiu       $t3, $t3, 0x1000
    ctx->r11 = ADD32(ctx->r11, 0X1000);
    skip_8:
    // 0x8005B38C: slti        $at, $t3, 0x7FF9
    ctx->r1 = SIGNED(ctx->r11) < 0X7FF9 ? 1 : 0;
L_8005B390:
    // 0x8005B390: beq         $at, $zero, L_8005B3AC
    if (ctx->r1 == 0) {
        // 0x8005B394: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8005B3AC;
    }
    // 0x8005B394: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8005B398: slti        $at, $t4, 0x7FF9
    ctx->r1 = SIGNED(ctx->r12) < 0X7FF9 ? 1 : 0;
    // 0x8005B39C: beq         $at, $zero, L_8005B3AC
    if (ctx->r1 == 0) {
        // 0x8005B3A0: slti        $at, $t5, 0x7FF9
        ctx->r1 = SIGNED(ctx->r13) < 0X7FF9 ? 1 : 0;
            goto L_8005B3AC;
    }
    // 0x8005B3A0: slti        $at, $t5, 0x7FF9
    ctx->r1 = SIGNED(ctx->r13) < 0X7FF9 ? 1 : 0;
    // 0x8005B3A4: bnel        $at, $zero, L_8005B3DC
    if (ctx->r1 != 0) {
        // 0x8005B3A8: sw          $v1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r3;
            goto L_8005B3DC;
    }
    goto skip_9;
    // 0x8005B3A8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    skip_9:
L_8005B3AC:
    // 0x8005B3AC: addiu       $t3, $t3, -0x1000
    ctx->r11 = ADD32(ctx->r11, -0X1000);
L_8005B3B0:
    // 0x8005B3B0: slti        $at, $t3, 0x7FF9
    ctx->r1 = SIGNED(ctx->r11) < 0X7FF9 ? 1 : 0;
    // 0x8005B3B4: addiu       $t4, $t4, -0x1000
    ctx->r12 = ADD32(ctx->r12, -0X1000);
    // 0x8005B3B8: beq         $at, $zero, L_8005B3AC
    if (ctx->r1 == 0) {
        // 0x8005B3BC: addiu       $t5, $t5, -0x1000
        ctx->r13 = ADD32(ctx->r13, -0X1000);
            goto L_8005B3AC;
    }
    // 0x8005B3BC: addiu       $t5, $t5, -0x1000
    ctx->r13 = ADD32(ctx->r13, -0X1000);
    // 0x8005B3C0: slti        $at, $t4, 0x7FF9
    ctx->r1 = SIGNED(ctx->r12) < 0X7FF9 ? 1 : 0;
    // 0x8005B3C4: beql        $at, $zero, L_8005B3B0
    if (ctx->r1 == 0) {
        // 0x8005B3C8: addiu       $t3, $t3, -0x1000
        ctx->r11 = ADD32(ctx->r11, -0X1000);
            goto L_8005B3B0;
    }
    goto skip_10;
    // 0x8005B3C8: addiu       $t3, $t3, -0x1000
    ctx->r11 = ADD32(ctx->r11, -0X1000);
    skip_10:
    // 0x8005B3CC: slti        $at, $t5, 0x7FF9
    ctx->r1 = SIGNED(ctx->r13) < 0X7FF9 ? 1 : 0;
    // 0x8005B3D0: beql        $at, $zero, L_8005B3B0
    if (ctx->r1 == 0) {
        // 0x8005B3D4: addiu       $t3, $t3, -0x1000
        ctx->r11 = ADD32(ctx->r11, -0X1000);
            goto L_8005B3B0;
    }
    goto skip_11;
    // 0x8005B3D4: addiu       $t3, $t3, -0x1000
    ctx->r11 = ADD32(ctx->r11, -0X1000);
    skip_11:
    // 0x8005B3D8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
L_8005B3DC:
    // 0x8005B3DC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8005B3E0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8005B3E4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8005B3E8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8005B3EC: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_8005B3F0:
    // 0x8005B3F0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8005B3F4: addu        $t7, $s0, $v1
    ctx->r15 = ADD32(ctx->r16, ctx->r3);
    // 0x8005B3F8: lw          $t8, 0x0($t7)
    ctx->r24 = S32(MEM_W(ctx->r15, 0X0));
    // 0x8005B3FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005B400: addu        $t9, $s1, $v1
    ctx->r25 = ADD32(ctx->r17, ctx->r3);
    // 0x8005B404: sh          $t8, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r24;
    // 0x8005B408: lw          $t6, 0x0($t9)
    ctx->r14 = S32(MEM_W(ctx->r25, 0X0));
    // 0x8005B40C: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x8005B410: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8005B414: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8005B418: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    // 0x8005B41C: bne         $at, $zero, L_8005B3F0
    if (ctx->r1 != 0) {
        // 0x8005B420: sh          $t6, -0x2($a3)
        MEM_H(-0X2, ctx->r7) = ctx->r14;
            goto L_8005B3F0;
    }
    // 0x8005B420: sh          $t6, -0x2($a3)
    MEM_H(-0X2, ctx->r7) = ctx->r14;
    // 0x8005B424: lw          $v1, 0x28($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8005B428: lw          $a0, 0x2C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8005B42C: lw          $t2, 0x30($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8005B430: lw          $t3, 0x1C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8005B434: lw          $t4, 0x20($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8005B438: lw          $t5, 0x24($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8005B43C: andi        $t8, $t0, 0xFFFF
    ctx->r24 = ctx->r8 & 0XFFFF;
    // 0x8005B440: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005B444: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8005B448: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8005B44C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8005B450: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8005B454: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8005B458: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8005B45C: bne         $at, $zero, L_8005B254
    if (ctx->r1 != 0) {
        // 0x8005B460: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_8005B254;
    }
    // 0x8005B460: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_8005B464:
    // 0x8005B464: lw          $s0, 0x8($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X8));
    // 0x8005B468: lw          $s1, 0xC($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0XC));
    // 0x8005B46C: jr          $ra
    // 0x8005B470: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005B470: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800636B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800636B8: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x800636BC: lw          $a1, -0x524C($a1)
    ctx->r5 = S32(MEM_W(ctx->r5, -0X524C));
    // 0x800636C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800636C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800636C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800636CC: jal         0x800632BC
    // 0x800636D0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_800632BC(rdram, ctx);
        goto after_0;
    // 0x800636D0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_0:
    // 0x800636D4: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x800636D8: lw          $a1, -0x5244($a1)
    ctx->r5 = S32(MEM_W(ctx->r5, -0X5244));
    // 0x800636DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800636E0: jal         0x80063470
    // 0x800636E4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_80063470(rdram, ctx);
        goto after_1;
    // 0x800636E4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_1:
    // 0x800636E8: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x800636EC: lw          $a1, -0x5248($a1)
    ctx->r5 = S32(MEM_W(ctx->r5, -0X5248));
    // 0x800636F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800636F4: jal         0x80063594
    // 0x800636F8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_80063594(rdram, ctx);
        goto after_2;
    // 0x800636F8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_2:
    // 0x800636FC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80063700: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063704: jr          $ra
    // 0x80063708: nop

    return;
    // 0x80063708: nop

;}
RECOMP_FUNC void dmulscale4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090334: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009033C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090340: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090344: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090348: jal         0x800BB8F8
    // 0x8009034C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8009034C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090350: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090354: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090358: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8009035C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090360: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090364: jal         0x800BB8F8
    // 0x80090368: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090368: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x8009036C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090370: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090374: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090378: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x8009037C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090380: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090384: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090388: jal         0x800BBA24
    // 0x8009038C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x8009038C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x80090390: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090394: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090398: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009039C: jr          $ra
    // 0x800903A0: nop

    return;
    // 0x800903A0: nop

;}
RECOMP_FUNC void dmulscale5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800903A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800903A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800903AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800903B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800903B4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800903B8: jal         0x800BB8F8
    // 0x800903BC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x800903BC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800903C0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800903C4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800903C8: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800903CC: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800903D0: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800903D4: jal         0x800BB8F8
    // 0x800903D8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x800903D8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x800903DC: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800903E0: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800903E4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800903E8: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x800903EC: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800903F0: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x800903F4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800903F8: jal         0x800BBA24
    // 0x800903FC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x800903FC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_2:
    // 0x80090400: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090404: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090408: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009040C: jr          $ra
    // 0x80090410: nop

    return;
    // 0x80090410: nop

;}
RECOMP_FUNC void alLink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF7A0: lw          $t6, 0x0($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X0));
    // 0x800BF7A4: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x800BF7A8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BF7AC: lw          $v0, 0x0($a1)
    ctx->r2 = S32(MEM_W(ctx->r5, 0X0));
    // 0x800BF7B0: beq         $v0, $zero, L_800BF7BC
    if (ctx->r2 == 0) {
        // 0x800BF7B4: nop
    
            goto L_800BF7BC;
    }
    // 0x800BF7B4: nop

    // 0x800BF7B8: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
L_800BF7BC:
    // 0x800BF7BC: jr          $ra
    // 0x800BF7C0: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    return;
    // 0x800BF7C0: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
;}
RECOMP_FUNC void func_80050754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050754: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80050758: lh          $a0, -0x9DC($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, -0X9DC));
    // 0x8005075C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80050760: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80050764: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80050768: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005076C: blez        $a0, L_800507A8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80050770: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800507A8;
    }
    // 0x80050770: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80050774: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80050778: addiu       $v1, $v1, -0x6C48
    ctx->r3 = ADD32(ctx->r3, -0X6C48);
L_8005077C:
    // 0x8005077C: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x80050780: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80050784: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80050788: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005078C: sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16 << 16);
    // 0x80050790: sra         $s0, $t2, 16
    ctx->r16 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80050794: or          $v0, $v0, $t8
    ctx->r2 = ctx->r2 | ctx->r24;
    // 0x80050798: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8005079C: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x800507A0: bne         $at, $zero, L_8005077C
    if (ctx->r1 != 0) {
        // 0x800507A4: sra         $v0, $t9, 16
        ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
            goto L_8005077C;
    }
    // 0x800507A4: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
L_800507A8:
    // 0x800507A8: andi        $t4, $v0, 0x1000
    ctx->r12 = ctx->r2 & 0X1000;
    // 0x800507AC: beq         $t4, $zero, L_800507E8
    if (ctx->r12 == 0) {
        // 0x800507B0: lui         $v1, 0x800D
        ctx->r3 = S32(0X800D << 16);
            goto L_800507E8;
    }
    // 0x800507B0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800507B4: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800507B8: lh          $t5, 0x3778($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, 0X3778));
    // 0x800507BC: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800507C0: addiu       $t0, $t0, 0x3774
    ctx->r8 = ADD32(ctx->r8, 0X3774);
    // 0x800507C4: slti        $at, $t5, 0x6
    ctx->r1 = SIGNED(ctx->r13) < 0X6 ? 1 : 0;
    // 0x800507C8: beq         $at, $zero, L_800507E8
    if (ctx->r1 == 0) {
        // 0x800507CC: addiu       $t6, $zero, 0x6
        ctx->r14 = ADD32(0, 0X6);
            goto L_800507E8;
    }
    // 0x800507CC: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800507D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800507D4: sh          $t6, 0x3778($at)
    MEM_H(0X3778, ctx->r1) = ctx->r14;
    // 0x800507D8: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    // 0x800507DC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800507E0: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x800507E4: sh          $t7, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r15;
L_800507E8:
    // 0x800507E8: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800507EC: lh          $t8, 0x3750($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, 0X3750));
    // 0x800507F0: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800507F4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800507F8: addiu       $t0, $t0, 0x3774
    ctx->r8 = ADD32(ctx->r8, 0X3774);
    // 0x800507FC: bne         $t8, $at, L_80050810
    if (ctx->r24 != ctx->r1) {
        // 0x80050800: lh          $v1, 0x3778($v1)
        ctx->r3 = S32(MEM_H(ctx->r3, 0X3778));
            goto L_80050810;
    }
    // 0x80050800: lh          $v1, 0x3778($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X3778));
    // 0x80050804: addiu       $v0, $zero, 0xE6B
    ctx->r2 = ADD32(0, 0XE6B);
    // 0x80050808: b           L_80050818
    // 0x8005080C: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
        goto L_80050818;
    // 0x8005080C: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
L_80050810:
    // 0x80050810: addiu       $v0, $zero, 0xE6C
    ctx->r2 = ADD32(0, 0XE6C);
    // 0x80050814: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
L_80050818:
    // 0x80050818: sltiu       $at, $v1, 0x7
    ctx->r1 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x8005081C: beq         $at, $zero, L_800509EC
    if (ctx->r1 == 0) {
        // 0x80050820: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800509EC;
    }
    // 0x80050820: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80050824: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80050828: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8005082C: addu        $at, $at, $t9
    gpr jr_addend_80050834 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80050830: lw          $t9, 0x3830($at)
    ctx->r25 = ADD32(ctx->r1, 0X3830);
    // 0x80050834: jr          $t9
    // 0x80050838: nop

    switch (jr_addend_80050834 >> 2) {
        case 0: goto L_8005083C; break;
        case 1: goto L_800508C8; break;
        case 2: goto L_800508C8; break;
        case 3: goto L_800508C8; break;
        case 4: goto L_800508C8; break;
        case 5: goto L_800508C8; break;
        case 6: goto L_80050958; break;
        default: switch_error(__func__, 0x80050834, 0x80103830);
    }
    // 0x80050838: nop

L_8005083C:
    // 0x8005083C: lh          $t1, 0x0($t0)
    ctx->r9 = S32(MEM_H(ctx->r8, 0X0));
    // 0x80050840: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x80050844: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x80050848: sll         $t2, $t1, 20
    ctx->r10 = S32(ctx->r9 << 20);
    // 0x8005084C: sra         $s0, $t2, 16
    ctx->r16 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80050850: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80050854: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x80050858: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x8005085C: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80050860: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80050864: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80050868: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8005086C: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x80050870: jal         0x8006E994
    // 0x80050874: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    setrotatespriteflags(rdram, ctx);
        goto after_0;
    // 0x80050874: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_0:
    // 0x80050878: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8005087C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80050880: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80050884: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80050888: lh          $v0, 0x2E($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0X2E));
    // 0x8005088C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80050890: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80050894: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050898: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005089C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800508A0: jal         0x8005D13C
    // 0x800508A4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    rotatesprite(rdram, ctx);
        goto after_1;
    // 0x800508A4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x800508A8: xori        $a0, $s0, 0x100
    ctx->r4 = ctx->r16 ^ 0X100;
    // 0x800508AC: sltiu       $a0, $a0, 0x1
    ctx->r4 = ctx->r4 < 0X1 ? 1 : 0;
    // 0x800508B0: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x800508B4: jal         0x8004F96C
    // 0x800508B8: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_2;
    // 0x800508B8: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_2:
    // 0x800508BC: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800508C0: b           L_800509F4
    // 0x800508C4: addiu       $t0, $t0, 0x3774
    ctx->r8 = ADD32(ctx->r8, 0X3774);
        goto L_800509F4;
    // 0x800508C4: addiu       $t0, $t0, 0x3774
    ctx->r8 = ADD32(ctx->r8, 0X3774);
L_800508C8:
    // 0x800508C8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800508CC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800508D0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800508D4: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x800508D8: jal         0x8006E994
    // 0x800508DC: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    setrotatespriteflags(rdram, ctx);
        goto after_3;
    // 0x800508DC: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    after_3:
    // 0x800508E0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800508E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800508E8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800508EC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800508F0: lh          $v0, 0x2E($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0X2E));
    // 0x800508F4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800508F8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800508FC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050900: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80050904: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80050908: jal         0x8005D13C
    // 0x8005090C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    rotatesprite(rdram, ctx);
        goto after_4;
    // 0x8005090C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
    // 0x80050910: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80050914: lh          $t9, 0x3778($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, 0X3778));
    // 0x80050918: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x8005091C: addu        $a0, $s0, $t9
    ctx->r4 = ADD32(ctx->r16, ctx->r25);
    // 0x80050920: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80050924: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x80050928: jal         0x8004F9A0
    // 0x8005092C: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    func_8004F9A0(rdram, ctx);
        goto after_5;
    // 0x8005092C: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    after_5:
    // 0x80050930: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80050934: lh          $a0, 0x3774($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3774));
    // 0x80050938: xori        $t3, $a0, 0x96
    ctx->r11 = ctx->r4 ^ 0X96;
    // 0x8005093C: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80050940: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80050944: jal         0x8004F96C
    // 0x80050948: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_6;
    // 0x80050948: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_6:
    // 0x8005094C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80050950: b           L_800509F4
    // 0x80050954: addiu       $t0, $t0, 0x3774
    ctx->r8 = ADD32(ctx->r8, 0X3774);
        goto L_800509F4;
    // 0x80050954: addiu       $t0, $t0, 0x3774
    ctx->r8 = ADD32(ctx->r8, 0X3774);
L_80050958:
    // 0x80050958: lh          $t6, 0x0($t0)
    ctx->r14 = S32(MEM_H(ctx->r8, 0X0));
    // 0x8005095C: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x80050960: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x80050964: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80050968: subu        $s0, $t8, $t7
    ctx->r16 = SUB32(ctx->r24, ctx->r15);
    // 0x8005096C: sll         $t9, $s0, 16
    ctx->r25 = S32(ctx->r16 << 16);
    // 0x80050970: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80050974: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80050978: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x8005097C: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x80050980: sra         $t4, $a2, 16
    ctx->r12 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80050984: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80050988: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8005098C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80050990: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80050994: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80050998: jal         0x8006E994
    // 0x8005099C: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    setrotatespriteflags(rdram, ctx);
        goto after_7;
    // 0x8005099C: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    after_7:
    // 0x800509A0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800509A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800509A8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800509AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800509B0: lh          $v0, 0x2E($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0X2E));
    // 0x800509B4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800509B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800509BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800509C0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800509C4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800509C8: jal         0x8005D13C
    // 0x800509CC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    rotatesprite(rdram, ctx);
        goto after_8;
    // 0x800509CC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // 0x800509D0: sltiu       $a0, $s0, 0x1
    ctx->r4 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x800509D4: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800509D8: jal         0x8004F96C
    // 0x800509DC: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_9;
    // 0x800509DC: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_9:
    // 0x800509E0: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800509E4: b           L_800509F4
    // 0x800509E8: addiu       $t0, $t0, 0x3774
    ctx->r8 = ADD32(ctx->r8, 0X3774);
        goto L_800509F4;
    // 0x800509E8: addiu       $t0, $t0, 0x3774
    ctx->r8 = ADD32(ctx->r8, 0X3774);
L_800509EC:
    // 0x800509EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800509F0: sb          $t8, 0x375C($at)
    MEM_B(0X375C, ctx->r1) = ctx->r24;
L_800509F4:
    // 0x800509F4: lh          $t7, 0x0($t0)
    ctx->r15 = S32(MEM_H(ctx->r8, 0X0));
    // 0x800509F8: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800509FC: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80050A00: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80050A04: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x80050A08: jr          $ra
    // 0x80050A0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80050A0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void alSynDelete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9B40: jr          $ra
    // 0x800C9B44: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x800C9B44: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80058FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058FEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80058FF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80058FF4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80058FF8: jal         0x80058A30
    // 0x80058FFC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80058A30(rdram, ctx);
        goto after_0;
    // 0x80058FFC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80059000: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80059004: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80059008: lh          $a0, 0x2A($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X2A));
    // 0x8005900C: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x80059010: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80059014: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x80059018: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005901C: jal         0x80058428
    // 0x80059020: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_80058428(rdram, ctx);
        goto after_1;
    // 0x80059020: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x80059024: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80059028: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005902C: jr          $ra
    // 0x80059030: nop

    return;
    // 0x80059030: nop

;}
RECOMP_FUNC void alSavePull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE534: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CE538: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CE53C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CE540: lw          $a0, 0x0($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X0));
    // 0x800CE544: lw          $t7, 0x30($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800CE548: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800CE54C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CE550: lw          $t9, 0x4($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X4));
    // 0x800CE554: jalr        $t9
    // 0x800CE558: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CE558: nop

    after_0:
    // 0x800CE55C: lw          $a2, 0x28($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800CE560: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x800CE564: lui         $t2, 0x440
    ctx->r10 = S32(0X440 << 16);
    // 0x800CE568: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800CE56C: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x800CE570: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x800CE574: ori         $t2, $t2, 0x580
    ctx->r10 = ctx->r10 | 0X580;
    // 0x800CE578: lui         $t1, 0xD00
    ctx->r9 = S32(0XD00 << 16);
    // 0x800CE57C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800CE580: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800CE584: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800CE588: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800CE58C: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x800CE590: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800CE594: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x800CE598: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x800CE59C: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    // 0x800CE5A0: lw          $t6, 0x20($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800CE5A4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800CE5A8: lw          $t7, 0x14($t6)
    ctx->r15 = S32(MEM_W(ctx->r14, 0X14));
    // 0x800CE5AC: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x800CE5B0: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800CE5B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CE5B8: jr          $ra
    // 0x800CE5BC: nop

    return;
    // 0x800CE5BC: nop

;}
RECOMP_FUNC void divscale32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091964: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009196C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80091970: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80091974: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80091978: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009197C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80091980: jal         0x800BB834
    // 0x80091984: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x80091984: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80091988: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009198C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80091990: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80091994: jal         0x800BB89C
    // 0x80091998: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80091998: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x8009199C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800919A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800919A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800919A8: jr          $ra
    // 0x800919AC: nop

    return;
    // 0x800919AC: nop

;}
