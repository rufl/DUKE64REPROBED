nonmatching func_800594A8, 0x40

glabel func_800594A8
    /* F0A8 800594A8 308E0007 */  andi       $t6, $a0, 0x7
    /* F0AC 800594AC 3C0F800D */  lui        $t7, %hi(D_800D4D90)
    /* F0B0 800594B0 0004C0C3 */  sra        $t8, $a0, 3
    /* F0B4 800594B4 3C198022 */  lui        $t9, %hi(D_8021ACA0)
    /* F0B8 800594B8 0338C821 */  addu       $t9, $t9, $t8
    /* F0BC 800594BC 01EE7821 */  addu       $t7, $t7, $t6
    /* F0C0 800594C0 91EF4D90 */  lbu        $t7, %lo(D_800D4D90)($t7)
    /* F0C4 800594C4 9339ACA0 */  lbu        $t9, %lo(D_8021ACA0)($t9)
    /* F0C8 800594C8 00001025 */  or         $v0, $zero, $zero
    /* F0CC 800594CC 01F94024 */  and        $t0, $t7, $t9
    /* F0D0 800594D0 11000003 */  beqz       $t0, .L800594E0
    /* F0D4 800594D4 00000000 */   nop
    /* F0D8 800594D8 03E00008 */  jr         $ra
    /* F0DC 800594DC 24020001 */   addiu     $v0, $zero, 0x1
  .L800594E0:
    /* F0E0 800594E0 03E00008 */  jr         $ra
    /* F0E4 800594E4 00000000 */   nop
endlabel func_800594A8
