nonmatching mainproc, 0x470

glabel mainproc
    /* 1988 8004BD88 27BDFFA0 */  addiu      $sp, $sp, -0x60
    /* 198C 8004BD8C AFB00020 */  sw         $s0, 0x20($sp)
    /* 1990 8004BD90 00808025 */  or         $s0, $a0, $zero
    /* 1994 8004BD94 AFBF003C */  sw         $ra, 0x3C($sp)
    /* 1998 8004BD98 3C048012 */  lui        $a0, %hi(D_80123620)
    /* 199C 8004BD9C 3C058012 */  lui        $a1, %hi(D_801236B0)
    /* 19A0 8004BDA0 AFB60038 */  sw         $s6, 0x38($sp)
    /* 19A4 8004BDA4 AFB50034 */  sw         $s5, 0x34($sp)
    /* 19A8 8004BDA8 AFB40030 */  sw         $s4, 0x30($sp)
    /* 19AC 8004BDAC AFB3002C */  sw         $s3, 0x2C($sp)
    /* 19B0 8004BDB0 AFB20028 */  sw         $s2, 0x28($sp)
    /* 19B4 8004BDB4 AFB10024 */  sw         $s1, 0x24($sp)
    /* 19B8 8004BDB8 24A536B0 */  addiu      $a1, $a1, %lo(D_801236B0)
    /* 19BC 8004BDBC 24843620 */  addiu      $a0, $a0, %lo(D_80123620)
    /* 19C0 8004BDC0 0C02EDD8 */  jal        osCreateMesgQueue
    /* 19C4 8004BDC4 24060008 */   addiu     $a2, $zero, 0x8
    /* 19C8 8004BDC8 3C07802B */  lui        $a3, %hi(D_802AE7B0)
    /* 19CC 8004BDCC 3C02000C */  lui        $v0, %hi(D_000C2270)
    /* 19D0 8004BDD0 24E7E7B0 */  addiu      $a3, $a3, %lo(D_802AE7B0)
    /* 19D4 8004BDD4 24422270 */  addiu      $v0, $v0, %lo(D_000C2270)
    /* 19D8 8004BDD8 3C05000C */  lui        $a1, %hi(D_000C0880)
    /* 19DC 8004BDDC 24A50880 */  addiu      $a1, $a1, %lo(D_000C0880)
    /* 19E0 8004BDE0 00E27821 */  addu       $t7, $a3, $v0
    /* 19E4 8004BDE4 3C01802C */  lui        $at, (0x802C5001 >> 16)
    /* 19E8 8004BDE8 3C03801C */  lui        $v1, %hi(paletteoffset)
    /* 19EC 8004BDEC 34215001 */  ori        $at, $at, (0x802C5001 & 0xFFFF)
    /* 19F0 8004BDF0 01E5C023 */  subu       $t8, $t7, $a1
    /* 19F4 8004BDF4 24634414 */  addiu      $v1, $v1, %lo(paletteoffset)
    /* 19F8 8004BDF8 0301082B */  sltu       $at, $t8, $at
    /* 19FC 8004BDFC 14200003 */  bnez       $at, .L8004BE0C
    /* 1A00 8004BE00 AC670000 */   sw        $a3, 0x0($v1)
  .L8004BE04:
    /* 1A04 8004BE04 1000FFFF */  b          .L8004BE04
    /* 1A08 8004BE08 00000000 */   nop
  .L8004BE0C:
    /* 1A0C 8004BE0C 00E02025 */  or         $a0, $a3, $zero
    /* 1A10 8004BE10 0C012D58 */  jal        copyfromrom
    /* 1A14 8004BE14 00453023 */   subu      $a2, $v0, $a1
    /* 1A18 8004BE18 3C118012 */  lui        $s1, %hi(scheduler)
    /* 1A1C 8004BE1C 2631F348 */  addiu      $s1, $s1, %lo(scheduler)
    /* 1A20 8004BE20 3C058012 */  lui        $a1, %hi(D_801235D0)
    /* 1A24 8004BE24 24A535D0 */  addiu      $a1, $a1, %lo(D_801235D0)
    /* 1A28 8004BE28 02202025 */  or         $a0, $s1, $zero
    /* 1A2C 8004BE2C 24060040 */  addiu      $a2, $zero, 0x40
    /* 1A30 8004BE30 0C013104 */  jal        osCreateScheduler2
    /* 1A34 8004BE34 24070001 */   addiu     $a3, $zero, 0x1
    /* 1A38 8004BE38 3C128011 */  lui        $s2, %hi(contThread)
    /* 1A3C 8004BE3C 3C198012 */  lui        $t9, %hi(audioThread)
    /* 1A40 8004BE40 26526FE8 */  addiu      $s2, $s2, %lo(contThread)
    /* 1A44 8004BE44 2739B198 */  addiu      $t9, $t9, %lo(audioThread)
    /* 1A48 8004BE48 3C068005 */  lui        $a2, %hi(controllerThread)
    /* 1A4C 8004BE4C 24080014 */  addiu      $t0, $zero, 0x14
    /* 1A50 8004BE50 AFA80014 */  sw         $t0, 0x14($sp)
    /* 1A54 8004BE54 24C6C1F8 */  addiu      $a2, $a2, %lo(controllerThread)
    /* 1A58 8004BE58 AFB90010 */  sw         $t9, 0x10($sp)
    /* 1A5C 8004BE5C 02402025 */  or         $a0, $s2, $zero
    /* 1A60 8004BE60 24050005 */  addiu      $a1, $zero, 0x5
    /* 1A64 8004BE64 0C02EB78 */  jal        osCreateThread
    /* 1A68 8004BE68 02003825 */   or        $a3, $s0, $zero
    /* 1A6C 8004BE6C 3C138012 */  lui        $s3, %hi(audioThread)
    /* 1A70 8004BE70 3C098012 */  lui        $t1, %hi(scheduler)
    /* 1A74 8004BE74 2673B198 */  addiu      $s3, $s3, %lo(audioThread)
    /* 1A78 8004BE78 2529F348 */  addiu      $t1, $t1, %lo(scheduler)
    /* 1A7C 8004BE7C 3C068005 */  lui        $a2, %hi(__amMain)
    /* 1A80 8004BE80 240A001E */  addiu      $t2, $zero, 0x1E
    /* 1A84 8004BE84 AFAA0014 */  sw         $t2, 0x14($sp)
    /* 1A88 8004BE88 24C6C344 */  addiu      $a2, $a2, %lo(__amMain)
    /* 1A8C 8004BE8C AFA90010 */  sw         $t1, 0x10($sp)
    /* 1A90 8004BE90 02602025 */  or         $a0, $s3, $zero
    /* 1A94 8004BE94 24050006 */  addiu      $a1, $zero, 0x6
    /* 1A98 8004BE98 0C02EB78 */  jal        osCreateThread
    /* 1A9C 8004BE9C 02003825 */   or        $a3, $s0, $zero
    /* 1AA0 8004BEA0 0C0160BC */  jal        soundSetupMsgQueue
    /* 1AA4 8004BEA4 00000000 */   nop
    /* 1AA8 8004BEA8 0C015DF7 */  jal        soundInit
    /* 1AAC 8004BEAC 00000000 */   nop
    /* 1AB0 8004BEB0 0C014644 */  jal        controllervibdisable
    /* 1AB4 8004BEB4 00000000 */   nop
    /* 1AB8 8004BEB8 0C0133E2 */  jal        initControllers
    /* 1ABC 8004BEBC 00000000 */   nop
    /* 1AC0 8004BEC0 3C048012 */  lui        $a0, %hi(controllerthreadsync)
    /* 1AC4 8004BEC4 3C058012 */  lui        $a1, %hi(D_801236D0)
    /* 1AC8 8004BEC8 24A536D0 */  addiu      $a1, $a1, %lo(D_801236D0)
    /* 1ACC 8004BECC 24843638 */  addiu      $a0, $a0, %lo(controllerthreadsync)
    /* 1AD0 8004BED0 0C02EDD8 */  jal        osCreateMesgQueue
    /* 1AD4 8004BED4 24060001 */   addiu     $a2, $zero, 0x1
    /* 1AD8 8004BED8 3C148012 */  lui        $s4, %hi(retraceMessageQ)
    /* 1ADC 8004BEDC 26943650 */  addiu      $s4, $s4, %lo(retraceMessageQ)
    /* 1AE0 8004BEE0 3C058012 */  lui        $a1, %hi(D_801236D8)
    /* 1AE4 8004BEE4 24A536D8 */  addiu      $a1, $a1, %lo(D_801236D8)
    /* 1AE8 8004BEE8 02802025 */  or         $a0, $s4, $zero
    /* 1AEC 8004BEEC 0C02EDD8 */  jal        osCreateMesgQueue
    /* 1AF0 8004BEF0 24060008 */   addiu     $a2, $zero, 0x8
    /* 1AF4 8004BEF4 3C058012 */  lui        $a1, %hi(D_801235D0)
    /* 1AF8 8004BEF8 24A535D0 */  addiu      $a1, $a1, %lo(D_801235D0)
    /* 1AFC 8004BEFC 02202025 */  or         $a0, $s1, $zero
    /* 1B00 8004BF00 0C01315F */  jal        osScAddClient
    /* 1B04 8004BF04 02803025 */   or        $a2, $s4, $zero
    /* 1B08 8004BF08 0C02EBCC */  jal        osStartThread
    /* 1B0C 8004BF0C 02402025 */   or        $a0, $s2, $zero
    /* 1B10 8004BF10 0C02EBCC */  jal        osStartThread
    /* 1B14 8004BF14 02602025 */   or        $a0, $s3, $zero
    /* 1B18 8004BF18 0C012D94 */  jal        determineclockfreq
    /* 1B1C 8004BF1C 00000000 */   nop
    /* 1B20 8004BF20 0C013601 */  jal        setdefaultcontrollermode
    /* 1B24 8004BF24 00000000 */   nop
    /* 1B28 8004BF28 0C02D34D */  jal        loadefs
    /* 1B2C 8004BF2C 00000000 */   nop
    /* 1B30 8004BF30 0C019212 */  jal        cacheandtileinit
    /* 1B34 8004BF34 00000000 */   nop
    /* 1B38 8004BF38 0C02ED60 */  jal        osGetTime
    /* 1B3C 8004BF3C 00000000 */   nop
    /* 1B40 8004BF40 3C12801C */  lui        $s2, %hi(nowtime2)
    /* 1B44 8004BF44 26524428 */  addiu      $s2, $s2, %lo(nowtime2)
    /* 1B48 8004BF48 3C16800D */  lui        $s6, %hi(framecounter)
    /* 1B4C 8004BF4C 3C15801C */  lui        $s5, %hi(nowtime)
    /* 1B50 8004BF50 3C13800D */  lui        $s3, %hi(gfxtaskcreated)
    /* 1B54 8004BF54 3C11800D */  lui        $s1, %hi(prevtime)
    /* 1B58 8004BF58 3C10801C */  lui        $s0, %hi(clockfreq)
    /* 1B5C 8004BF5C AE420000 */  sw         $v0, 0x0($s2)
    /* 1B60 8004BF60 AE430004 */  sw         $v1, 0x4($s2)
    /* 1B64 8004BF64 26104408 */  addiu      $s0, $s0, %lo(clockfreq)
    /* 1B68 8004BF68 263136F8 */  addiu      $s1, $s1, %lo(prevtime)
    /* 1B6C 8004BF6C 267336CC */  addiu      $s3, $s3, %lo(gfxtaskcreated)
    /* 1B70 8004BF70 26B54420 */  addiu      $s5, $s5, %lo(nowtime)
    /* 1B74 8004BF74 26D636F0 */  addiu      $s6, $s6, %lo(framecounter)
  .L8004BF78:
    /* 1B78 8004BF78 0C02ED60 */  jal        osGetTime
    /* 1B7C 8004BF7C 00000000 */   nop
    /* 1B80 8004BF80 8EAF0004 */  lw         $t7, 0x4($s5)
    /* 1B84 8004BF84 8EAE0000 */  lw         $t6, 0x0($s5)
    /* 1B88 8004BF88 8E290004 */  lw         $t1, 0x4($s1)
    /* 1B8C 8004BF8C 8E280000 */  lw         $t0, 0x0($s1)
    /* 1B90 8004BF90 006F082B */  sltu       $at, $v1, $t7
    /* 1B94 8004BF94 006FC823 */  subu       $t9, $v1, $t7
    /* 1B98 8004BF98 004EC023 */  subu       $t8, $v0, $t6
    /* 1B9C 8004BF9C 0301C023 */  subu       $t8, $t8, $at
    /* 1BA0 8004BFA0 01395821 */  addu       $t3, $t1, $t9
    /* 1BA4 8004BFA4 0179082B */  sltu       $at, $t3, $t9
    /* 1BA8 8004BFA8 00285021 */  addu       $t2, $at, $t0
    /* 1BAC 8004BFAC 01585021 */  addu       $t2, $t2, $t8
    /* 1BB0 8004BFB0 AE420000 */  sw         $v0, 0x0($s2)
    /* 1BB4 8004BFB4 AE430004 */  sw         $v1, 0x4($s2)
    /* 1BB8 8004BFB8 AE2A0000 */  sw         $t2, 0x0($s1)
    /* 1BBC 8004BFBC AE2B0004 */  sw         $t3, 0x4($s1)
    /* 1BC0 8004BFC0 8E040000 */  lw         $a0, 0x0($s0)
    /* 1BC4 8004BFC4 8E050004 */  lw         $a1, 0x4($s0)
    /* 1BC8 8004BFC8 24060000 */  addiu      $a2, $zero, 0x0
    /* 1BCC 8004BFCC 0C02EE3E */  jal        __ll_mul
    /* 1BD0 8004BFD0 24070006 */   addiu     $a3, $zero, 0x6
    /* 1BD4 8004BFD4 8E2C0000 */  lw         $t4, 0x0($s1)
    /* 1BD8 8004BFD8 8E2D0004 */  lw         $t5, 0x4($s1)
    /* 1BDC 8004BFDC 0182082A */  slt        $at, $t4, $v0
    /* 1BE0 8004BFE0 1420000C */  bnez       $at, .L8004C014
    /* 1BE4 8004BFE4 004C082A */   slt       $at, $v0, $t4
    /* 1BE8 8004BFE8 14200004 */  bnez       $at, .L8004BFFC
    /* 1BEC 8004BFEC 24060000 */   addiu     $a2, $zero, 0x0
    /* 1BF0 8004BFF0 006D082B */  sltu       $at, $v1, $t5
    /* 1BF4 8004BFF4 50200008 */  beql       $at, $zero, .L8004C018
    /* 1BF8 8004BFF8 8E4E0000 */   lw        $t6, 0x0($s2)
  .L8004BFFC:
    /* 1BFC 8004BFFC 8E040000 */  lw         $a0, 0x0($s0)
    /* 1C00 8004C000 8E050004 */  lw         $a1, 0x4($s0)
    /* 1C04 8004C004 0C02EE3E */  jal        __ll_mul
    /* 1C08 8004C008 24070006 */   addiu     $a3, $zero, 0x6
    /* 1C0C 8004C00C AE220000 */  sw         $v0, 0x0($s1)
    /* 1C10 8004C010 AE230004 */  sw         $v1, 0x4($s1)
  .L8004C014:
    /* 1C14 8004C014 8E4E0000 */  lw         $t6, 0x0($s2)
  .L8004C018:
    /* 1C18 8004C018 8E4F0004 */  lw         $t7, 0x4($s2)
    /* 1C1C 8004C01C 8E040000 */  lw         $a0, 0x0($s0)
    /* 1C20 8004C020 8E050004 */  lw         $a1, 0x4($s0)
    /* 1C24 8004C024 24060000 */  addiu      $a2, $zero, 0x0
    /* 1C28 8004C028 24070002 */  addiu      $a3, $zero, 0x2
    /* 1C2C 8004C02C AEAE0000 */  sw         $t6, 0x0($s5)
    /* 1C30 8004C030 0C02EE3E */  jal        __ll_mul
    /* 1C34 8004C034 AEAF0004 */   sw        $t7, 0x4($s5)
    /* 1C38 8004C038 8E280000 */  lw         $t0, 0x0($s1)
    /* 1C3C 8004C03C 8E290004 */  lw         $t1, 0x4($s1)
    /* 1C40 8004C040 0102082A */  slt        $at, $t0, $v0
    /* 1C44 8004C044 AFA80040 */  sw         $t0, 0x40($sp)
    /* 1C48 8004C048 14200028 */  bnez       $at, .L8004C0EC
    /* 1C4C 8004C04C AFA90044 */   sw        $t1, 0x44($sp)
    /* 1C50 8004C050 0048082A */  slt        $at, $v0, $t0
    /* 1C54 8004C054 14200003 */  bnez       $at, .L8004C064
    /* 1C58 8004C058 0069082B */   sltu      $at, $v1, $t1
    /* 1C5C 8004C05C 50200024 */  beql       $at, $zero, .L8004C0F0
    /* 1C60 8004C060 8FB80040 */   lw        $t8, 0x40($sp)
  .L8004C064:
    /* 1C64 8004C064 0C012E79 */  jal        timerupdate
    /* 1C68 8004C068 00000000 */   nop
    /* 1C6C 8004C06C 8E040000 */  lw         $a0, 0x0($s0)
    /* 1C70 8004C070 8E050004 */  lw         $a1, 0x4($s0)
    /* 1C74 8004C074 24060000 */  addiu      $a2, $zero, 0x0
    /* 1C78 8004C078 0C02EE3E */  jal        __ll_mul
    /* 1C7C 8004C07C 24070002 */   addiu     $a3, $zero, 0x2
    /* 1C80 8004C080 3C0A800D */  lui        $t2, %hi(prevtime)
    /* 1C84 8004C084 3C0B800D */  lui        $t3, %hi(prevtime + 0x4)
    /* 1C88 8004C088 8D6B36FC */  lw         $t3, %lo(prevtime + 0x4)($t3)
    /* 1C8C 8004C08C 8D4A36F8 */  lw         $t2, %lo(prevtime)($t2)
    /* 1C90 8004C090 24060000 */  addiu      $a2, $zero, 0x0
    /* 1C94 8004C094 0163082B */  sltu       $at, $t3, $v1
    /* 1C98 8004C098 01426023 */  subu       $t4, $t2, $v0
    /* 1C9C 8004C09C 01816023 */  subu       $t4, $t4, $at
    /* 1CA0 8004C0A0 3C01800D */  lui        $at, %hi(prevtime + 0x4)
    /* 1CA4 8004C0A4 01636823 */  subu       $t5, $t3, $v1
    /* 1CA8 8004C0A8 AC2D36FC */  sw         $t5, %lo(prevtime + 0x4)($at)
    /* 1CAC 8004C0AC AC2C36F8 */  sw         $t4, %lo(prevtime)($at)
    /* 1CB0 8004C0B0 8E050004 */  lw         $a1, 0x4($s0)
    /* 1CB4 8004C0B4 8E040000 */  lw         $a0, 0x0($s0)
    /* 1CB8 8004C0B8 0C02EE3E */  jal        __ll_mul
    /* 1CBC 8004C0BC 24070002 */   addiu     $a3, $zero, 0x2
    /* 1CC0 8004C0C0 8E2E0000 */  lw         $t6, 0x0($s1)
    /* 1CC4 8004C0C4 8E2F0004 */  lw         $t7, 0x4($s1)
    /* 1CC8 8004C0C8 004E082A */  slt        $at, $v0, $t6
    /* 1CCC 8004C0CC AFAE0040 */  sw         $t6, 0x40($sp)
    /* 1CD0 8004C0D0 1420FFE4 */  bnez       $at, .L8004C064
    /* 1CD4 8004C0D4 AFAF0044 */   sw        $t7, 0x44($sp)
    /* 1CD8 8004C0D8 01C2082A */  slt        $at, $t6, $v0
    /* 1CDC 8004C0DC 14200003 */  bnez       $at, .L8004C0EC
    /* 1CE0 8004C0E0 006F082B */   sltu      $at, $v1, $t7
    /* 1CE4 8004C0E4 1420FFDF */  bnez       $at, .L8004C064
    /* 1CE8 8004C0E8 00000000 */   nop
  .L8004C0EC:
    /* 1CEC 8004C0EC 8FB80040 */  lw         $t8, 0x40($sp)
  .L8004C0F0:
    /* 1CF0 8004C0F0 0700FFA1 */  bltz       $t8, .L8004BF78
    /* 1CF4 8004C0F4 00000000 */   nop
    /* 1CF8 8004C0F8 1F000001 */  bgtz       $t8, .L8004C100
    /* 1CFC 8004C0FC 00000000 */   nop
  .L8004C100:
    /* 1D00 8004C100 0C012E79 */  jal        timerupdate
    /* 1D04 8004C104 00000000 */   nop
    /* 1D08 8004C108 0C012EE1 */  jal        setupgfx
    /* 1D0C 8004C10C 00000000 */   nop
    /* 1D10 8004C110 0C012E24 */  jal        display
    /* 1D14 8004C114 00000000 */   nop
    /* 1D18 8004C118 8E040000 */  lw         $a0, 0x0($s0)
    /* 1D1C 8004C11C 8E050004 */  lw         $a1, 0x4($s0)
    /* 1D20 8004C120 24060000 */  addiu      $a2, $zero, 0x0
    /* 1D24 8004C124 0C02EE3E */  jal        __ll_mul
    /* 1D28 8004C128 24070002 */   addiu     $a3, $zero, 0x2
    /* 1D2C 8004C12C 3C0A800D */  lui        $t2, %hi(prevtime)
    /* 1D30 8004C130 3C0B800D */  lui        $t3, %hi(prevtime + 0x4)
    /* 1D34 8004C134 8D6B36FC */  lw         $t3, %lo(prevtime + 0x4)($t3)
    /* 1D38 8004C138 8D4A36F8 */  lw         $t2, %lo(prevtime)($t2)
    /* 1D3C 8004C13C 3C048012 */  lui        $a0, %hi(controllerthreadsync)
    /* 1D40 8004C140 0163082B */  sltu       $at, $t3, $v1
    /* 1D44 8004C144 01426023 */  subu       $t4, $t2, $v0
    /* 1D48 8004C148 01816023 */  subu       $t4, $t4, $at
    /* 1D4C 8004C14C 3C01800D */  lui        $at, %hi(prevtime + 0x4)
    /* 1D50 8004C150 01636823 */  subu       $t5, $t3, $v1
    /* 1D54 8004C154 AC2D36FC */  sw         $t5, %lo(prevtime + 0x4)($at)
    /* 1D58 8004C158 AC2C36F8 */  sw         $t4, %lo(prevtime)($at)
    /* 1D5C 8004C15C 8E6E0000 */  lw         $t6, 0x0($s3)
    /* 1D60 8004C160 24843638 */  addiu      $a0, $a0, %lo(controllerthreadsync)
    /* 1D64 8004C164 00002825 */  or         $a1, $zero, $zero
    /* 1D68 8004C168 11C00010 */  beqz       $t6, .L8004C1AC
    /* 1D6C 8004C16C 00000000 */   nop
    /* 1D70 8004C170 0C02ED10 */  jal        osRecvMesg
    /* 1D74 8004C174 24060001 */   addiu     $a2, $zero, 0x1
    /* 1D78 8004C178 8E8F0008 */  lw         $t7, 0x8($s4)
    /* 1D7C 8004C17C 8E880010 */  lw         $t0, 0x10($s4)
    /* 1D80 8004C180 AE600000 */  sw         $zero, 0x0($s3)
    /* 1D84 8004C184 02802025 */  or         $a0, $s4, $zero
    /* 1D88 8004C188 01E8082A */  slt        $at, $t7, $t0
    /* 1D8C 8004C18C 14200003 */  bnez       $at, .L8004C19C
    /* 1D90 8004C190 00002825 */   or        $a1, $zero, $zero
    /* 1D94 8004C194 0C02ED10 */  jal        osRecvMesg
    /* 1D98 8004C198 24060001 */   addiu     $a2, $zero, 0x1
  .L8004C19C:
    /* 1D9C 8004C19C 02802025 */  or         $a0, $s4, $zero
    /* 1DA0 8004C1A0 00002825 */  or         $a1, $zero, $zero
    /* 1DA4 8004C1A4 0C02ED10 */  jal        osRecvMesg
    /* 1DA8 8004C1A8 24060001 */   addiu     $a2, $zero, 0x1
  .L8004C1AC:
    /* 1DAC 8004C1AC 0C012EED */  jal        creategfxtask
    /* 1DB0 8004C1B0 00000000 */   nop
    /* 1DB4 8004C1B4 8ED80000 */  lw         $t8, 0x0($s6)
    /* 1DB8 8004C1B8 24090001 */  addiu      $t1, $zero, 0x1
    /* 1DBC 8004C1BC AE690000 */  sw         $t1, 0x0($s3)
    /* 1DC0 8004C1C0 3B190001 */  xori       $t9, $t8, 0x1
    /* 1DC4 8004C1C4 1000FF6C */  b          .L8004BF78
    /* 1DC8 8004C1C8 AED90000 */   sw        $t9, 0x0($s6)
    /* 1DCC 8004C1CC 00000000 */  nop
    /* 1DD0 8004C1D0 8FBF003C */  lw         $ra, 0x3C($sp)
    /* 1DD4 8004C1D4 8FB00020 */  lw         $s0, 0x20($sp)
    /* 1DD8 8004C1D8 8FB10024 */  lw         $s1, 0x24($sp)
    /* 1DDC 8004C1DC 8FB20028 */  lw         $s2, 0x28($sp)
    /* 1DE0 8004C1E0 8FB3002C */  lw         $s3, 0x2C($sp)
    /* 1DE4 8004C1E4 8FB40030 */  lw         $s4, 0x30($sp)
    /* 1DE8 8004C1E8 8FB50034 */  lw         $s5, 0x34($sp)
    /* 1DEC 8004C1EC 8FB60038 */  lw         $s6, 0x38($sp)
    /* 1DF0 8004C1F0 03E00008 */  jr         $ra
    /* 1DF4 8004C1F4 27BD0060 */   addiu     $sp, $sp, 0x60
endlabel mainproc
