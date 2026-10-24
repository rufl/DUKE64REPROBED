nonmatching demoinput, 0x16C

glabel demoinput
    /* 11080 8005B480 3C028010 */  lui        $v0, %hi(D_80101364)
    /* 11084 8005B484 90421364 */  lbu        $v0, %lo(D_80101364)($v0)
    /* 11088 8005B488 3C048022 */  lui        $a0, %hi(boardtimer)
    /* 1108C 8005B48C 2484D654 */  addiu      $a0, $a0, %lo(boardtimer)
    /* 11090 8005B490 10400009 */  beqz       $v0, .L8005B4B8
    /* 11094 8005B494 24010001 */   addiu     $at, $zero, 0x1
    /* 11098 8005B498 10410019 */  beq        $v0, $at, .L8005B500
    /* 1109C 8005B49C 24010002 */   addiu     $at, $zero, 0x2
    /* 110A0 8005B4A0 1041002B */  beq        $v0, $at, .L8005B550
    /* 110A4 8005B4A4 3C048022 */   lui       $a0, %hi(boardtimer)
    /* 110A8 8005B4A8 3C038022 */  lui        $v1, %hi(demo_button)
    /* 110AC 8005B4AC 2463D652 */  addiu      $v1, $v1, %lo(demo_button)
    /* 110B0 8005B4B0 1000003A */  b          .L8005B59C
    /* 110B4 8005B4B4 2484D654 */   addiu     $a0, $a0, %lo(boardtimer)
  .L8005B4B8:
    /* 110B8 8005B4B8 8C8E0000 */  lw         $t6, 0x0($a0)
    /* 110BC 8005B4BC 3C18800D */  lui        $t8, %hi(D_800D4DA4)
    /* 110C0 8005B4C0 27184DA4 */  addiu      $t8, $t8, %lo(D_800D4DA4)
    /* 110C4 8005B4C4 000E7880 */  sll        $t7, $t6, 2
    /* 110C8 8005B4C8 01EE7823 */  subu       $t7, $t7, $t6
    /* 110CC 8005B4CC 000F7840 */  sll        $t7, $t7, 1
    /* 110D0 8005B4D0 01F81021 */  addu       $v0, $t7, $t8
    /* 110D4 8005B4D4 84590000 */  lh         $t9, 0x0($v0)
    /* 110D8 8005B4D8 3C018022 */  lui        $at, %hi(demo_stickx)
    /* 110DC 8005B4DC 3C038022 */  lui        $v1, %hi(demo_button)
    /* 110E0 8005B4E0 A439D64E */  sh         $t9, %lo(demo_stickx)($at)
    /* 110E4 8005B4E4 84480002 */  lh         $t0, 0x2($v0)
    /* 110E8 8005B4E8 3C018022 */  lui        $at, %hi(demo_sticky)
    /* 110EC 8005B4EC 2463D652 */  addiu      $v1, $v1, %lo(demo_button)
    /* 110F0 8005B4F0 A428D650 */  sh         $t0, %lo(demo_sticky)($at)
    /* 110F4 8005B4F4 94490004 */  lhu        $t1, 0x4($v0)
    /* 110F8 8005B4F8 10000028 */  b          .L8005B59C
    /* 110FC 8005B4FC A4690000 */   sh        $t1, 0x0($v1)
  .L8005B500:
    /* 11100 8005B500 3C048022 */  lui        $a0, %hi(boardtimer)
    /* 11104 8005B504 2484D654 */  addiu      $a0, $a0, %lo(boardtimer)
    /* 11108 8005B508 8C8A0000 */  lw         $t2, 0x0($a0)
    /* 1110C 8005B50C 3C0C800D */  lui        $t4, %hi(D_800D5D70)
    /* 11110 8005B510 258C5D70 */  addiu      $t4, $t4, %lo(D_800D5D70)
    /* 11114 8005B514 000A5880 */  sll        $t3, $t2, 2
    /* 11118 8005B518 016A5823 */  subu       $t3, $t3, $t2
    /* 1111C 8005B51C 000B5840 */  sll        $t3, $t3, 1
    /* 11120 8005B520 016C1021 */  addu       $v0, $t3, $t4
    /* 11124 8005B524 844D0000 */  lh         $t5, 0x0($v0)
    /* 11128 8005B528 3C018022 */  lui        $at, %hi(demo_stickx)
    /* 1112C 8005B52C 3C038022 */  lui        $v1, %hi(demo_button)
    /* 11130 8005B530 A42DD64E */  sh         $t5, %lo(demo_stickx)($at)
    /* 11134 8005B534 844E0002 */  lh         $t6, 0x2($v0)
    /* 11138 8005B538 3C018022 */  lui        $at, %hi(demo_sticky)
    /* 1113C 8005B53C 2463D652 */  addiu      $v1, $v1, %lo(demo_button)
    /* 11140 8005B540 A42ED650 */  sh         $t6, %lo(demo_sticky)($at)
    /* 11144 8005B544 944F0004 */  lhu        $t7, 0x4($v0)
    /* 11148 8005B548 10000014 */  b          .L8005B59C
    /* 1114C 8005B54C A46F0000 */   sh        $t7, 0x0($v1)
  .L8005B550:
    /* 11150 8005B550 3C048022 */  lui        $a0, %hi(boardtimer)
    /* 11154 8005B554 2484D654 */  addiu      $a0, $a0, %lo(boardtimer)
    /* 11158 8005B558 8C980000 */  lw         $t8, 0x0($a0)
    /* 1115C 8005B55C 3C08800D */  lui        $t0, %hi(D_800D7948)
    /* 11160 8005B560 25087948 */  addiu      $t0, $t0, %lo(D_800D7948)
    /* 11164 8005B564 0018C880 */  sll        $t9, $t8, 2
    /* 11168 8005B568 0338C823 */  subu       $t9, $t9, $t8
    /* 1116C 8005B56C 0019C840 */  sll        $t9, $t9, 1
    /* 11170 8005B570 03281021 */  addu       $v0, $t9, $t0
    /* 11174 8005B574 84490000 */  lh         $t1, 0x0($v0)
    /* 11178 8005B578 3C018022 */  lui        $at, %hi(demo_stickx)
    /* 1117C 8005B57C 3C038022 */  lui        $v1, %hi(demo_button)
    /* 11180 8005B580 A429D64E */  sh         $t1, %lo(demo_stickx)($at)
    /* 11184 8005B584 844A0002 */  lh         $t2, 0x2($v0)
    /* 11188 8005B588 3C018022 */  lui        $at, %hi(demo_sticky)
    /* 1118C 8005B58C 2463D652 */  addiu      $v1, $v1, %lo(demo_button)
    /* 11190 8005B590 A42AD650 */  sh         $t2, %lo(demo_sticky)($at)
    /* 11194 8005B594 944B0004 */  lhu        $t3, 0x4($v0)
    /* 11198 8005B598 A46B0000 */  sh         $t3, 0x0($v1)
  .L8005B59C:
    /* 1119C 8005B59C 946C0000 */  lhu        $t4, 0x0($v1)
    /* 111A0 8005B5A0 3401FFFF */  ori        $at, $zero, 0xFFFF
    /* 111A4 8005B5A4 3C0D802A */  lui        $t5, %hi(ps + 0x28C)
    /* 111A8 8005B5A8 11810003 */  beq        $t4, $at, .L8005B5B8
    /* 111AC 8005B5AC 240E000D */   addiu     $t6, $zero, 0xD
    /* 111B0 8005B5B0 85AD59FC */  lh         $t5, %lo(ps + 0x28C)($t5)
    /* 111B4 8005B5B4 1DA00008 */  bgtz       $t5, .L8005B5D8
  .L8005B5B8:
    /* 111B8 8005B5B8 3C01800D */   lui       $at, %hi(gamestate)
    /* 111BC 8005B5BC A02E36C8 */  sb         $t6, %lo(gamestate)($at)
    /* 111C0 8005B5C0 3C018022 */  lui        $at, %hi(demo_stickx)
    /* 111C4 8005B5C4 A420D64E */  sh         $zero, %lo(demo_stickx)($at)
    /* 111C8 8005B5C8 3C018022 */  lui        $at, %hi(demo_sticky)
    /* 111CC 8005B5CC A420D650 */  sh         $zero, %lo(demo_sticky)($at)
    /* 111D0 8005B5D0 03E00008 */  jr         $ra
    /* 111D4 8005B5D4 A4600000 */   sh        $zero, 0x0($v1)
  .L8005B5D8:
    /* 111D8 8005B5D8 8C8F0000 */  lw         $t7, 0x0($a0)
    /* 111DC 8005B5DC 25F80001 */  addiu      $t8, $t7, 0x1
    /* 111E0 8005B5E0 AC980000 */  sw         $t8, 0x0($a0)
    /* 111E4 8005B5E4 03E00008 */  jr         $ra
    /* 111E8 8005B5E8 00000000 */   nop
endlabel demoinput
    /* 111EC 8005B5EC 00000000 */  nop
