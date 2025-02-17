.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel rising_bubble_main
/* 355EE0 E0046000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 355EE4 E0046004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 355EE8 E0046008 4485A000 */  mtc1      $a1, $f20
/* 355EEC E004600C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 355EF0 E0046010 4486C000 */  mtc1      $a2, $f24
/* 355EF4 E0046014 AFB1002C */  sw        $s1, 0x2c($sp)
/* 355EF8 E0046018 0080882D */  daddu     $s1, $a0, $zero
/* 355EFC E004601C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 355F00 E0046020 4487B000 */  mtc1      $a3, $f22
/* 355F04 E0046024 27A40010 */  addiu     $a0, $sp, 0x10
/* 355F08 E0046028 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 355F0C E004602C C7BA0068 */  lwc1      $f26, 0x68($sp)
/* 355F10 E0046030 3C02E004 */  lui       $v0, %hi(rising_bubble_init)
/* 355F14 E0046034 24426158 */  addiu     $v0, $v0, %lo(rising_bubble_init)
/* 355F18 E0046038 AFA20018 */  sw        $v0, 0x18($sp)
/* 355F1C E004603C 3C02E004 */  lui       $v0, %hi(rising_bubble_update)
/* 355F20 E0046040 24426160 */  addiu     $v0, $v0, %lo(rising_bubble_update)
/* 355F24 E0046044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 355F28 E0046048 3C02E004 */  lui       $v0, %hi(rising_bubble_render)
/* 355F2C E004604C 2442627C */  addiu     $v0, $v0, %lo(rising_bubble_render)
/* 355F30 E0046050 AFA20020 */  sw        $v0, 0x20($sp)
/* 355F34 E0046054 24020023 */  addiu     $v0, $zero, 0x23
/* 355F38 E0046058 AFBF0030 */  sw        $ra, 0x30($sp)
/* 355F3C E004605C AFB00028 */  sw        $s0, 0x28($sp)
/* 355F40 E0046060 AFA00010 */  sw        $zero, 0x10($sp)
/* 355F44 E0046064 AFA00024 */  sw        $zero, 0x24($sp)
/* 355F48 E0046068 0C080124 */  jal       shim_create_effect_instance
/* 355F4C E004606C AFA20014 */   sw       $v0, 0x14($sp)
/* 355F50 E0046070 24040028 */  addiu     $a0, $zero, 0x28
/* 355F54 E0046074 24030001 */  addiu     $v1, $zero, 1
/* 355F58 E0046078 0040802D */  daddu     $s0, $v0, $zero
/* 355F5C E004607C 0C08012C */  jal       shim_general_heap_malloc
/* 355F60 E0046080 AE030008 */   sw       $v1, 8($s0)
/* 355F64 E0046084 AE02000C */  sw        $v0, 0xc($s0)
/* 355F68 E0046088 0040802D */  daddu     $s0, $v0, $zero
/* 355F6C E004608C 56000003 */  bnel      $s0, $zero, .LE004609C
/* 355F70 E0046090 AE110000 */   sw       $s1, ($s0)
.LE0046094:
/* 355F74 E0046094 08011825 */  j         .LE0046094
/* 355F78 E0046098 00000000 */   nop
.LE004609C:
/* 355F7C E004609C 44800000 */  mtc1      $zero, $f0
/* 355F80 E00460A0 E6140004 */  swc1      $f20, 4($s0)
/* 355F84 E00460A4 E6180008 */  swc1      $f24, 8($s0)
/* 355F88 E00460A8 E616000C */  swc1      $f22, 0xc($s0)
/* 355F8C E00460AC AE000014 */  sw        $zero, 0x14($s0)
/* 355F90 E00460B0 4600D032 */  c.eq.s    $f26, $f0
/* 355F94 E00460B4 00000000 */  nop
/* 355F98 E00460B8 45010013 */  bc1t      .LE0046108
/* 355F9C E00460BC AE00001C */   sw       $zero, 0x1c($s0)
/* 355FA0 E00460C0 0C080138 */  jal       shim_rand_int
/* 355FA4 E00460C4 24040003 */   addiu    $a0, $zero, 3
/* 355FA8 E00460C8 3C01E004 */  lui       $at, %hi(D_E0046620)
/* 355FAC E00460CC D4226620 */  ldc1      $f2, %lo(D_E0046620)($at)
/* 355FB0 E00460D0 44820000 */  mtc1      $v0, $f0
/* 355FB4 E00460D4 00000000 */  nop
/* 355FB8 E00460D8 46800021 */  cvt.d.w   $f0, $f0
/* 355FBC E00460DC 46220002 */  mul.d     $f0, $f0, $f2
/* 355FC0 E00460E0 00000000 */  nop
/* 355FC4 E00460E4 3C01E004 */  lui       $at, %hi(D_E0046628)
/* 355FC8 E00460E8 D4226628 */  ldc1      $f2, %lo(D_E0046628)($at)
/* 355FCC E00460EC 46220000 */  add.d     $f0, $f0, $f2
/* 355FD0 E00460F0 3C01E004 */  lui       $at, %hi(D_E0046630)
/* 355FD4 E00460F4 D4226630 */  ldc1      $f2, %lo(D_E0046630)($at)
/* 355FD8 E00460F8 46220002 */  mul.d     $f0, $f0, $f2
/* 355FDC E00460FC 00000000 */  nop
/* 355FE0 E0046100 08011845 */  j         .LE0046114
/* 355FE4 E0046104 46200020 */   cvt.s.d  $f0, $f0
.LE0046108:
/* 355FE8 E0046108 3C013F80 */  lui       $at, 0x3f80
/* 355FEC E004610C 44810000 */  mtc1      $at, $f0
/* 355FF0 E0046110 00000000 */  nop
.LE0046114:
/* 355FF4 E0046114 E6000010 */  swc1      $f0, 0x10($s0)
/* 355FF8 E0046118 2404001F */  addiu     $a0, $zero, 0x1f
/* 355FFC E004611C 24020020 */  addiu     $v0, $zero, 0x20
/* 356000 E0046120 0C080138 */  jal       shim_rand_int
/* 356004 E0046124 AE020018 */   sw       $v0, 0x18($s0)
/* 356008 E0046128 461AC000 */  add.s     $f0, $f24, $f26
/* 35600C E004612C AE020020 */  sw        $v0, 0x20($s0)
/* 356010 E0046130 E6000024 */  swc1      $f0, 0x24($s0)
/* 356014 E0046134 8FBF0030 */  lw        $ra, 0x30($sp)
/* 356018 E0046138 8FB1002C */  lw        $s1, 0x2c($sp)
/* 35601C E004613C 8FB00028 */  lw        $s0, 0x28($sp)
/* 356020 E0046140 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 356024 E0046144 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 356028 E0046148 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 35602C E004614C D7B40038 */  ldc1      $f20, 0x38($sp)
/* 356030 E0046150 03E00008 */  jr        $ra
/* 356034 E0046154 27BD0058 */   addiu    $sp, $sp, 0x58
