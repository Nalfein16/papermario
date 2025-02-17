.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021C14C_6A334C
/* 6A334C 8021C14C 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 6A3350 8021C150 AFB1001C */  sw        $s1, 0x1c($sp)
/* 6A3354 8021C154 0080882D */  daddu     $s1, $a0, $zero
/* 6A3358 8021C158 AFB20020 */  sw        $s2, 0x20($sp)
/* 6A335C 8021C15C AFBF002C */  sw        $ra, 0x2c($sp)
/* 6A3360 8021C160 AFB40028 */  sw        $s4, 0x28($sp)
/* 6A3364 8021C164 AFB30024 */  sw        $s3, 0x24($sp)
/* 6A3368 8021C168 AFB00018 */  sw        $s0, 0x18($sp)
/* 6A336C 8021C16C F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 6A3370 8021C170 F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 6A3374 8021C174 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 6A3378 8021C178 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 6A337C 8021C17C F7B40030 */  sdc1      $f20, 0x30($sp)
/* 6A3380 8021C180 8E240148 */  lw        $a0, 0x148($s1)
/* 6A3384 8021C184 8E30000C */  lw        $s0, 0xc($s1)
/* 6A3388 8021C188 0C09A75B */  jal       get_actor
/* 6A338C 8021C18C 00A0902D */   daddu    $s2, $a1, $zero
/* 6A3390 8021C190 0040982D */  daddu     $s3, $v0, $zero
/* 6A3394 8021C194 126000D5 */  beqz      $s3, .L8021C4EC
/* 6A3398 8021C198 24020002 */   addiu    $v0, $zero, 2
/* 6A339C 8021C19C 1240003C */  beqz      $s2, .L8021C290
/* 6A33A0 8021C1A0 0220202D */   daddu    $a0, $s1, $zero
/* 6A33A4 8021C1A4 8E050000 */  lw        $a1, ($s0)
/* 6A33A8 8021C1A8 26100004 */  addiu     $s0, $s0, 4
/* 6A33AC 8021C1AC 0C0B1EAF */  jal       evt_get_variable
/* 6A33B0 8021C1B0 0000902D */   daddu    $s2, $zero, $zero
/* 6A33B4 8021C1B4 8E050000 */  lw        $a1, ($s0)
/* 6A33B8 8021C1B8 26100004 */  addiu     $s0, $s0, 4
/* 6A33BC 8021C1BC 4482E000 */  mtc1      $v0, $f28
/* 6A33C0 8021C1C0 00000000 */  nop
/* 6A33C4 8021C1C4 4680E720 */  cvt.s.w   $f28, $f28
/* 6A33C8 8021C1C8 0C0B1EAF */  jal       evt_get_variable
/* 6A33CC 8021C1CC 0220202D */   daddu    $a0, $s1, $zero
/* 6A33D0 8021C1D0 8E050000 */  lw        $a1, ($s0)
/* 6A33D4 8021C1D4 26100004 */  addiu     $s0, $s0, 4
/* 6A33D8 8021C1D8 4482D000 */  mtc1      $v0, $f26
/* 6A33DC 8021C1DC 00000000 */  nop
/* 6A33E0 8021C1E0 4680D6A0 */  cvt.s.w   $f26, $f26
/* 6A33E4 8021C1E4 0C0B1EAF */  jal       evt_get_variable
/* 6A33E8 8021C1E8 0220202D */   daddu    $a0, $s1, $zero
/* 6A33EC 8021C1EC 8E050000 */  lw        $a1, ($s0)
/* 6A33F0 8021C1F0 26100004 */  addiu     $s0, $s0, 4
/* 6A33F4 8021C1F4 4482C000 */  mtc1      $v0, $f24
/* 6A33F8 8021C1F8 00000000 */  nop
/* 6A33FC 8021C1FC 4680C620 */  cvt.s.w   $f24, $f24
/* 6A3400 8021C200 0C0B210B */  jal       evt_get_float_variable
/* 6A3404 8021C204 0220202D */   daddu    $a0, $s1, $zero
/* 6A3408 8021C208 0220202D */  daddu     $a0, $s1, $zero
/* 6A340C 8021C20C 8E050000 */  lw        $a1, ($s0)
/* 6A3410 8021C210 0C0B210B */  jal       evt_get_float_variable
/* 6A3414 8021C214 46000506 */   mov.s    $f20, $f0
/* 6A3418 8021C218 240400B4 */  addiu     $a0, $zero, 0xb4
/* 6A341C 8021C21C 0C00AB39 */  jal       heap_malloc
/* 6A3420 8021C220 46000586 */   mov.s    $f22, $f0
/* 6A3424 8021C224 0040882D */  daddu     $s1, $v0, $zero
/* 6A3428 8021C228 24060028 */  addiu     $a2, $zero, 0x28
/* 6A342C 8021C22C 240500FF */  addiu     $a1, $zero, 0xff
/* 6A3430 8021C230 24040001 */  addiu     $a0, $zero, 1
/* 6A3434 8021C234 26230038 */  addiu     $v1, $s1, 0x38
/* 6A3438 8021C238 AE710078 */  sw        $s1, 0x78($s3)
.L8021C23C:
/* 6A343C 8021C23C E47CFFCC */  swc1      $f28, -0x34($v1)
/* 6A3440 8021C240 E47AFFD0 */  swc1      $f26, -0x30($v1)
/* 6A3444 8021C244 E478FFD4 */  swc1      $f24, -0x2c($v1)
/* 6A3448 8021C248 E474FFE0 */  swc1      $f20, -0x20($v1)
/* 6A344C 8021C24C E474FFD8 */  swc1      $f20, -0x28($v1)
/* 6A3450 8021C250 E476FFDC */  swc1      $f22, -0x24($v1)
/* 6A3454 8021C254 AC64FFE4 */  sw        $a0, -0x1c($v1)
/* 6A3458 8021C258 AC66FFE8 */  sw        $a2, -0x18($v1)
/* 6A345C 8021C25C AC65FFEC */  sw        $a1, -0x14($v1)
/* 6A3460 8021C260 AC65FFF0 */  sw        $a1, -0x10($v1)
/* 6A3464 8021C264 AC60FFF4 */  sw        $zero, -0xc($v1)
/* 6A3468 8021C268 AC60FFF8 */  sw        $zero, -8($v1)
/* 6A346C 8021C26C AC60FFFC */  sw        $zero, -4($v1)
/* 6A3470 8021C270 AC600000 */  sw        $zero, ($v1)
/* 6A3474 8021C274 2463003C */  addiu     $v1, $v1, 0x3c
/* 6A3478 8021C278 26520001 */  addiu     $s2, $s2, 1
/* 6A347C 8021C27C 2A420003 */  slti      $v0, $s2, 3
/* 6A3480 8021C280 1440FFEE */  bnez      $v0, .L8021C23C
/* 6A3484 8021C284 2484000A */   addiu    $a0, $a0, 0xa
/* 6A3488 8021C288 0808713B */  j         .L8021C4EC
/* 6A348C 8021C28C 0000102D */   daddu    $v0, $zero, $zero
.L8021C290:
/* 6A3490 8021C290 0000A02D */  daddu     $s4, $zero, $zero
/* 6A3494 8021C294 0280902D */  daddu     $s2, $s4, $zero
/* 6A3498 8021C298 8E710078 */  lw        $s1, 0x78($s3)
/* 6A349C 8021C29C 3C013DCC */  lui       $at, 0x3dcc
/* 6A34A0 8021C2A0 3421CCCD */  ori       $at, $at, 0xcccd
/* 6A34A4 8021C2A4 4481C000 */  mtc1      $at, $f24
/* 6A34A8 8021C2A8 3C013F00 */  lui       $at, 0x3f00
/* 6A34AC 8021C2AC 4481B000 */  mtc1      $at, $f22
/* 6A34B0 8021C2B0 3C01437F */  lui       $at, 0x437f
/* 6A34B4 8021C2B4 4481A000 */  mtc1      $at, $f20
/* 6A34B8 8021C2B8 26300028 */  addiu     $s0, $s1, 0x28
.L8021C2BC:
/* 6A34BC 8021C2BC 8E02FFF4 */  lw        $v0, -0xc($s0)
/* 6A34C0 8021C2C0 1840001C */  blez      $v0, .L8021C334
/* 6A34C4 8021C2C4 2442FFFF */   addiu    $v0, $v0, -1
/* 6A34C8 8021C2C8 1C40007D */  bgtz      $v0, .L8021C4C0
/* 6A34CC 8021C2CC AE02FFF4 */   sw       $v0, -0xc($s0)
/* 6A34D0 8021C2D0 C600FFF0 */  lwc1      $f0, -0x10($s0)
/* 6A34D4 8021C2D4 2402FFFF */  addiu     $v0, $zero, -1
/* 6A34D8 8021C2D8 AFA20014 */  sw        $v0, 0x14($sp)
/* 6A34DC 8021C2DC E7A00010 */  swc1      $f0, 0x10($sp)
/* 6A34E0 8021C2E0 8E05FFDC */  lw        $a1, -0x24($s0)
/* 6A34E4 8021C2E4 8E06FFE0 */  lw        $a2, -0x20($s0)
/* 6A34E8 8021C2E8 8E07FFE4 */  lw        $a3, -0x1c($s0)
/* 6A34EC 8021C2EC 0C01CA9C */  jal       fx_star_outline
/* 6A34F0 8021C2F0 0000202D */   daddu    $a0, $zero, $zero
/* 6A34F4 8021C2F4 AE220000 */  sw        $v0, ($s1)
/* 6A34F8 8021C2F8 8C42000C */  lw        $v0, 0xc($v0)
/* 6A34FC 8021C2FC C6000004 */  lwc1      $f0, 4($s0)
/* 6A3500 8021C300 E440003C */  swc1      $f0, 0x3c($v0)
/* 6A3504 8021C304 8E220000 */  lw        $v0, ($s1)
/* 6A3508 8021C308 C6000008 */  lwc1      $f0, 8($s0)
/* 6A350C 8021C30C 8C42000C */  lw        $v0, 0xc($v0)
/* 6A3510 8021C310 E4400040 */  swc1      $f0, 0x40($v0)
/* 6A3514 8021C314 8E220000 */  lw        $v0, ($s1)
/* 6A3518 8021C318 C600000C */  lwc1      $f0, 0xc($s0)
/* 6A351C 8021C31C 8C42000C */  lw        $v0, 0xc($v0)
/* 6A3520 8021C320 E4400044 */  swc1      $f0, 0x44($v0)
/* 6A3524 8021C324 8E220000 */  lw        $v0, ($s1)
/* 6A3528 8021C328 8C42000C */  lw        $v0, 0xc($v0)
/* 6A352C 8021C32C 08087130 */  j         .L8021C4C0
/* 6A3530 8021C330 A4400000 */   sh       $zero, ($v0)
.L8021C334:
/* 6A3534 8021C334 8E020010 */  lw        $v0, 0x10($s0)
/* 6A3538 8021C338 10400003 */  beqz      $v0, .L8021C348
/* 6A353C 8021C33C 00000000 */   nop
/* 6A3540 8021C340 08087130 */  j         .L8021C4C0
/* 6A3544 8021C344 26940001 */   addiu    $s4, $s4, 1
.L8021C348:
/* 6A3548 8021C348 C600FFE8 */  lwc1      $f0, -0x18($s0)
/* 6A354C 8021C34C C608FFEC */  lwc1      $f8, -0x14($s0)
/* 6A3550 8021C350 46080001 */  sub.s     $f0, $f0, $f8
/* 6A3554 8021C354 C602FFF8 */  lwc1      $f2, -8($s0)
/* 6A3558 8021C358 468010A0 */  cvt.s.w   $f2, $f2
/* 6A355C 8021C35C 46000005 */  abs.s     $f0, $f0
/* 6A3560 8021C360 46020002 */  mul.s     $f0, $f0, $f2
/* 6A3564 8021C364 00000000 */  nop
/* 6A3568 8021C368 C606000C */  lwc1      $f6, 0xc($s0)
/* 6A356C 8021C36C 3C014110 */  lui       $at, 0x4110
/* 6A3570 8021C370 44811000 */  mtc1      $at, $f2
/* 6A3574 8021C374 3C014220 */  lui       $at, 0x4220
/* 6A3578 8021C378 44812000 */  mtc1      $at, $f4
/* 6A357C 8021C37C 46023180 */  add.s     $f6, $f6, $f2
/* 6A3580 8021C380 8E03FFF8 */  lw        $v1, -8($s0)
/* 6A3584 8021C384 46040003 */  div.s     $f0, $f0, $f4
/* 6A3588 8021C388 46080000 */  add.s     $f0, $f0, $f8
/* 6A358C 8021C38C 2862000B */  slti      $v0, $v1, 0xb
/* 6A3590 8021C390 E606000C */  swc1      $f6, 0xc($s0)
/* 6A3594 8021C394 1040001C */  beqz      $v0, .L8021C408
/* 6A3598 8021C398 E600FFF0 */   swc1     $f0, -0x10($s0)
/* 6A359C 8021C39C 000317C2 */  srl       $v0, $v1, 0x1f
/* 6A35A0 8021C3A0 00621021 */  addu      $v0, $v1, $v0
/* 6A35A4 8021C3A4 00021043 */  sra       $v0, $v0, 1
/* 6A35A8 8021C3A8 44821000 */  mtc1      $v0, $f2
/* 6A35AC 8021C3AC 00000000 */  nop
/* 6A35B0 8021C3B0 468010A0 */  cvt.s.w   $f2, $f2
/* 6A35B4 8021C3B4 0060102D */  daddu     $v0, $v1, $zero
/* 6A35B8 8021C3B8 46181082 */  mul.s     $f2, $f2, $f24
/* 6A35BC 8021C3BC 00000000 */  nop
/* 6A35C0 8021C3C0 00021FC2 */  srl       $v1, $v0, 0x1f
/* 6A35C4 8021C3C4 00431021 */  addu      $v0, $v0, $v1
/* 6A35C8 8021C3C8 00021043 */  sra       $v0, $v0, 1
/* 6A35CC 8021C3CC 44820000 */  mtc1      $v0, $f0
/* 6A35D0 8021C3D0 00000000 */  nop
/* 6A35D4 8021C3D4 46800020 */  cvt.s.w   $f0, $f0
/* 6A35D8 8021C3D8 46180002 */  mul.s     $f0, $f0, $f24
/* 6A35DC 8021C3DC 00000000 */  nop
/* 6A35E0 8021C3E0 46161080 */  add.s     $f2, $f2, $f22
/* 6A35E4 8021C3E4 46141082 */  mul.s     $f2, $f2, $f20
/* 6A35E8 8021C3E8 00000000 */  nop
/* 6A35EC 8021C3EC 46160000 */  add.s     $f0, $f0, $f22
/* 6A35F0 8021C3F0 46140002 */  mul.s     $f0, $f0, $f20
/* 6A35F4 8021C3F4 00000000 */  nop
/* 6A35F8 8021C3F8 4600128D */  trunc.w.s $f10, $f2
/* 6A35FC 8021C3FC E60AFFFC */  swc1      $f10, -4($s0)
/* 6A3600 8021C400 4600028D */  trunc.w.s $f10, $f0
/* 6A3604 8021C404 E60A0000 */  swc1      $f10, ($s0)
.L8021C408:
/* 6A3608 8021C408 8E02FFF8 */  lw        $v0, -8($s0)
/* 6A360C 8021C40C 2442FFFF */  addiu     $v0, $v0, -1
/* 6A3610 8021C410 1C400007 */  bgtz      $v0, .L8021C430
/* 6A3614 8021C414 AE02FFF8 */   sw       $v0, -8($s0)
/* 6A3618 8021C418 8E240000 */  lw        $a0, ($s1)
/* 6A361C 8021C41C 0C016914 */  jal       remove_effect
/* 6A3620 8021C420 00000000 */   nop
/* 6A3624 8021C424 24020001 */  addiu     $v0, $zero, 1
/* 6A3628 8021C428 08087130 */  j         .L8021C4C0
/* 6A362C 8021C42C AE020010 */   sw       $v0, 0x10($s0)
.L8021C430:
/* 6A3630 8021C430 8E220000 */  lw        $v0, ($s1)
/* 6A3634 8021C434 C600FFDC */  lwc1      $f0, -0x24($s0)
/* 6A3638 8021C438 8C42000C */  lw        $v0, 0xc($v0)
/* 6A363C 8021C43C E4400004 */  swc1      $f0, 4($v0)
/* 6A3640 8021C440 8E220000 */  lw        $v0, ($s1)
/* 6A3644 8021C444 C600FFE0 */  lwc1      $f0, -0x20($s0)
/* 6A3648 8021C448 8C42000C */  lw        $v0, 0xc($v0)
/* 6A364C 8021C44C E4400008 */  swc1      $f0, 8($v0)
/* 6A3650 8021C450 8E220000 */  lw        $v0, ($s1)
/* 6A3654 8021C454 C600FFE4 */  lwc1      $f0, -0x1c($s0)
/* 6A3658 8021C458 8C42000C */  lw        $v0, 0xc($v0)
/* 6A365C 8021C45C E440000C */  swc1      $f0, 0xc($v0)
/* 6A3660 8021C460 8E220000 */  lw        $v0, ($s1)
/* 6A3664 8021C464 C6000004 */  lwc1      $f0, 4($s0)
/* 6A3668 8021C468 8C42000C */  lw        $v0, 0xc($v0)
/* 6A366C 8021C46C E440003C */  swc1      $f0, 0x3c($v0)
/* 6A3670 8021C470 8E220000 */  lw        $v0, ($s1)
/* 6A3674 8021C474 C6000008 */  lwc1      $f0, 8($s0)
/* 6A3678 8021C478 8C42000C */  lw        $v0, 0xc($v0)
/* 6A367C 8021C47C E4400040 */  swc1      $f0, 0x40($v0)
/* 6A3680 8021C480 8E220000 */  lw        $v0, ($s1)
/* 6A3684 8021C484 C600000C */  lwc1      $f0, 0xc($s0)
/* 6A3688 8021C488 8C42000C */  lw        $v0, 0xc($v0)
/* 6A368C 8021C48C E4400044 */  swc1      $f0, 0x44($v0)
/* 6A3690 8021C490 8E220000 */  lw        $v0, ($s1)
/* 6A3694 8021C494 C600FFF0 */  lwc1      $f0, -0x10($s0)
/* 6A3698 8021C498 8C42000C */  lw        $v0, 0xc($v0)
/* 6A369C 8021C49C E4400038 */  swc1      $f0, 0x38($v0)
/* 6A36A0 8021C4A0 8E220000 */  lw        $v0, ($s1)
/* 6A36A4 8021C4A4 8C43000C */  lw        $v1, 0xc($v0)
/* 6A36A8 8021C4A8 8E02FFFC */  lw        $v0, -4($s0)
/* 6A36AC 8021C4AC AC620024 */  sw        $v0, 0x24($v1)
/* 6A36B0 8021C4B0 8E220000 */  lw        $v0, ($s1)
/* 6A36B4 8021C4B4 8C43000C */  lw        $v1, 0xc($v0)
/* 6A36B8 8021C4B8 8E020000 */  lw        $v0, ($s0)
/* 6A36BC 8021C4BC AC620034 */  sw        $v0, 0x34($v1)
.L8021C4C0:
/* 6A36C0 8021C4C0 2610003C */  addiu     $s0, $s0, 0x3c
/* 6A36C4 8021C4C4 26520001 */  addiu     $s2, $s2, 1
/* 6A36C8 8021C4C8 2A420003 */  slti      $v0, $s2, 3
/* 6A36CC 8021C4CC 1440FF7B */  bnez      $v0, .L8021C2BC
/* 6A36D0 8021C4D0 2631003C */   addiu    $s1, $s1, 0x3c
/* 6A36D4 8021C4D4 2A820003 */  slti      $v0, $s4, 3
/* 6A36D8 8021C4D8 14400004 */  bnez      $v0, .L8021C4EC
/* 6A36DC 8021C4DC 0000102D */   daddu    $v0, $zero, $zero
/* 6A36E0 8021C4E0 0C00AB4B */  jal       heap_free
/* 6A36E4 8021C4E4 0220202D */   daddu    $a0, $s1, $zero
/* 6A36E8 8021C4E8 24020002 */  addiu     $v0, $zero, 2
.L8021C4EC:
/* 6A36EC 8021C4EC 8FBF002C */  lw        $ra, 0x2c($sp)
/* 6A36F0 8021C4F0 8FB40028 */  lw        $s4, 0x28($sp)
/* 6A36F4 8021C4F4 8FB30024 */  lw        $s3, 0x24($sp)
/* 6A36F8 8021C4F8 8FB20020 */  lw        $s2, 0x20($sp)
/* 6A36FC 8021C4FC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 6A3700 8021C500 8FB00018 */  lw        $s0, 0x18($sp)
/* 6A3704 8021C504 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 6A3708 8021C508 D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 6A370C 8021C50C D7B80040 */  ldc1      $f24, 0x40($sp)
/* 6A3710 8021C510 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 6A3714 8021C514 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 6A3718 8021C518 03E00008 */  jr        $ra
/* 6A371C 8021C51C 27BD0058 */   addiu    $sp, $sp, 0x58
