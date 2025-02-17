.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_80247AB8_B27FF8
.word .L802413D4_B21914, .L802413C0_B21900, .L802413D4_B21914, .L802413D4_B21914, .L802413D4_B21914, .L802413D4_B21914, .L802413D4_B21914, .L802413D4_B21914, .L802413D4_B21914, .L802413C0_B21900, .L802413D4_B21914, .L802413D4_B21914, .L802413D4_B21914, 0

.section .text

glabel jan_00_unkVtxFunc001
/* B21878 80241338 27BDFF98 */  addiu     $sp, $sp, -0x68
/* B2187C 8024133C AFB20018 */  sw        $s2, 0x18($sp)
/* B21880 80241340 0080902D */  daddu     $s2, $a0, $zero
/* B21884 80241344 AFB10014 */  sw        $s1, 0x14($sp)
/* B21888 80241348 00A0882D */  daddu     $s1, $a1, $zero
/* B2188C 8024134C AFB7002C */  sw        $s7, 0x2c($sp)
/* B21890 80241350 00C0B82D */  daddu     $s7, $a2, $zero
/* B21894 80241354 AFB00010 */  sw        $s0, 0x10($sp)
/* B21898 80241358 00E0802D */  daddu     $s0, $a3, $zero
/* B2189C 8024135C AFBF0030 */  sw        $ra, 0x30($sp)
/* B218A0 80241360 AFB60028 */  sw        $s6, 0x28($sp)
/* B218A4 80241364 AFB50024 */  sw        $s5, 0x24($sp)
/* B218A8 80241368 AFB40020 */  sw        $s4, 0x20($sp)
/* B218AC 8024136C AFB3001C */  sw        $s3, 0x1c($sp)
/* B218B0 80241370 F7BE0060 */  sdc1      $f30, 0x60($sp)
/* B218B4 80241374 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* B218B8 80241378 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* B218BC 8024137C F7B80048 */  sdc1      $f24, 0x48($sp)
/* B218C0 80241380 F7B60040 */  sdc1      $f22, 0x40($sp)
/* B218C4 80241384 F7B40038 */  sdc1      $f20, 0x38($sp)
/* B218C8 80241388 8E160000 */  lw        $s6, ($s0)
/* B218CC 8024138C 0C00EAD2 */  jal       get_npc_safe
/* B218D0 80241390 0000202D */   daddu    $a0, $zero, $zero
/* B218D4 80241394 8C420028 */  lw        $v0, 0x28($v0)
/* B218D8 80241398 3C03FF4A */  lui       $v1, 0xff4a
/* B218DC 8024139C 00431821 */  addu      $v1, $v0, $v1
/* B218E0 802413A0 2C62000D */  sltiu     $v0, $v1, 0xd
/* B218E4 802413A4 1040000B */  beqz      $v0, .L802413D4_B21914
/* B218E8 802413A8 00031080 */   sll      $v0, $v1, 2
/* B218EC 802413AC 3C018024 */  lui       $at, %hi(jtbl_80247AB8_B27FF8)
/* B218F0 802413B0 00220821 */  addu      $at, $at, $v0
/* B218F4 802413B4 8C227AB8 */  lw        $v0, %lo(jtbl_80247AB8_B27FF8)($at)
/* B218F8 802413B8 00400008 */  jr        $v0
/* B218FC 802413BC 00000000 */   nop
.L802413C0_B21900:
/* B21900 802413C0 8E020000 */  lw        $v0, ($s0)
/* B21904 802413C4 04410003 */  bgez      $v0, .L802413D4_B21914
/* B21908 802413C8 00000000 */   nop
/* B2190C 802413CC 0000B02D */  daddu     $s6, $zero, $zero
/* B21910 802413D0 AE000000 */  sw        $zero, ($s0)
.L802413D4_B21914:
/* B21914 802413D4 1AE00065 */  blez      $s7, .L8024156C
/* B21918 802413D8 0000A02D */   daddu    $s4, $zero, $zero
/* B2191C 802413DC 0220982D */  daddu     $s3, $s1, $zero
/* B21920 802413E0 3C014220 */  lui       $at, 0x4220
/* B21924 802413E4 4481F000 */  mtc1      $at, $f30
/* B21928 802413E8 3C014120 */  lui       $at, 0x4120
/* B2192C 802413EC 4481E000 */  mtc1      $at, $f28
.L802413F0:
/* B21930 802413F0 86440000 */  lh        $a0, ($s2)
/* B21934 802413F4 2882001F */  slti      $v0, $a0, 0x1f
/* B21938 802413F8 54400058 */  bnel      $v0, $zero, .L8024155C
/* B2193C 802413FC 26730010 */   addiu    $s3, $s3, 0x10
/* B21940 80241400 3C026666 */  lui       $v0, 0x6666
/* B21944 80241404 34426667 */  ori       $v0, $v0, 0x6667
/* B21948 80241408 2483FFE2 */  addiu     $v1, $a0, -0x1e
/* B2194C 8024140C 00620018 */  mult      $v1, $v0
/* B21950 80241410 4480C000 */  mtc1      $zero, $f24
/* B21954 80241414 0000802D */  daddu     $s0, $zero, $zero
/* B21958 80241418 00031FC3 */  sra       $v1, $v1, 0x1f
/* B2195C 8024141C 4600C686 */  mov.s     $f26, $f24
/* B21960 80241420 00004010 */  mfhi      $t0
/* B21964 80241424 00081083 */  sra       $v0, $t0, 2
/* B21968 80241428 00438823 */  subu      $s1, $v0, $v1
/* B2196C 8024142C 00111080 */  sll       $v0, $s1, 2
/* B21970 80241430 00511021 */  addu      $v0, $v0, $s1
/* B21974 80241434 00021040 */  sll       $v0, $v0, 1
/* B21978 80241438 2442001E */  addiu     $v0, $v0, 0x1e
/* B2197C 8024143C 1A20001D */  blez      $s1, .L802414B4
/* B21980 80241440 0082A823 */   subu     $s5, $a0, $v0
.L80241444:
/* B21984 80241444 44966000 */  mtc1      $s6, $f12
/* B21988 80241448 00000000 */  nop
/* B2198C 8024144C 0C00A8BB */  jal       sin_deg
/* B21990 80241450 46806320 */   cvt.s.w  $f12, $f12
/* B21994 80241454 44902000 */  mtc1      $s0, $f4
/* B21998 80241458 00000000 */  nop
/* B2199C 8024145C 46802120 */  cvt.s.w   $f4, $f4
/* B219A0 80241460 461E2083 */  div.s     $f2, $f4, $f30
/* B219A4 80241464 46001082 */  mul.s     $f2, $f2, $f0
/* B219A8 80241468 00000000 */  nop
/* B219AC 8024146C 3C014170 */  lui       $at, 0x4170
/* B219B0 80241470 44813000 */  mtc1      $at, $f6
/* B219B4 80241474 00000000 */  nop
/* B219B8 80241478 46062103 */  div.s     $f4, $f4, $f6
/* B219BC 8024147C 46022580 */  add.s     $f22, $f4, $f2
/* B219C0 80241480 0C00A874 */  jal       cos_rad
/* B219C4 80241484 4600B306 */   mov.s    $f12, $f22
/* B219C8 80241488 461C0002 */  mul.s     $f0, $f0, $f28
/* B219CC 8024148C 00000000 */  nop
/* B219D0 80241490 4600D680 */  add.s     $f26, $f26, $f0
/* B219D4 80241494 0C00A85B */  jal       sin_rad
/* B219D8 80241498 4600B306 */   mov.s    $f12, $f22
/* B219DC 8024149C 461C0002 */  mul.s     $f0, $f0, $f28
/* B219E0 802414A0 00000000 */  nop
/* B219E4 802414A4 26100001 */  addiu     $s0, $s0, 1
/* B219E8 802414A8 0211102A */  slt       $v0, $s0, $s1
/* B219EC 802414AC 1440FFE5 */  bnez      $v0, .L80241444
/* B219F0 802414B0 4600C600 */   add.s    $f24, $f24, $f0
.L802414B4:
/* B219F4 802414B4 44966000 */  mtc1      $s6, $f12
/* B219F8 802414B8 00000000 */  nop
/* B219FC 802414BC 0C00A8BB */  jal       sin_deg
/* B21A00 802414C0 46806320 */   cvt.s.w  $f12, $f12
/* B21A04 802414C4 44902000 */  mtc1      $s0, $f4
/* B21A08 802414C8 00000000 */  nop
/* B21A0C 802414CC 46802120 */  cvt.s.w   $f4, $f4
/* B21A10 802414D0 461E2083 */  div.s     $f2, $f4, $f30
/* B21A14 802414D4 46001082 */  mul.s     $f2, $f2, $f0
/* B21A18 802414D8 00000000 */  nop
/* B21A1C 802414DC 3C014170 */  lui       $at, 0x4170
/* B21A20 802414E0 44813000 */  mtc1      $at, $f6
/* B21A24 802414E4 00000000 */  nop
/* B21A28 802414E8 46062103 */  div.s     $f4, $f4, $f6
/* B21A2C 802414EC 46022580 */  add.s     $f22, $f4, $f2
/* B21A30 802414F0 0C00A874 */  jal       cos_rad
/* B21A34 802414F4 4600B306 */   mov.s    $f12, $f22
/* B21A38 802414F8 4495A000 */  mtc1      $s5, $f20
/* B21A3C 802414FC 00000000 */  nop
/* B21A40 80241500 4680A520 */  cvt.s.w   $f20, $f20
/* B21A44 80241504 4600A002 */  mul.s     $f0, $f20, $f0
/* B21A48 80241508 00000000 */  nop
/* B21A4C 8024150C 4600D680 */  add.s     $f26, $f26, $f0
/* B21A50 80241510 0C00A85B */  jal       sin_rad
/* B21A54 80241514 4600B306 */   mov.s    $f12, $f22
/* B21A58 80241518 4600A502 */  mul.s     $f20, $f20, $f0
/* B21A5C 8024151C 00000000 */  nop
/* B21A60 80241520 4600D18D */  trunc.w.s $f6, $f26
/* B21A64 80241524 44023000 */  mfc1      $v0, $f6
/* B21A68 80241528 00000000 */  nop
/* B21A6C 8024152C A6620000 */  sh        $v0, ($s3)
/* B21A70 80241530 86420002 */  lh        $v0, 2($s2)
/* B21A74 80241534 4614C600 */  add.s     $f24, $f24, $f20
/* B21A78 80241538 44820000 */  mtc1      $v0, $f0
/* B21A7C 8024153C 00000000 */  nop
/* B21A80 80241540 46800020 */  cvt.s.w   $f0, $f0
/* B21A84 80241544 46180000 */  add.s     $f0, $f0, $f24
/* B21A88 80241548 4600018D */  trunc.w.s $f6, $f0
/* B21A8C 8024154C 44023000 */  mfc1      $v0, $f6
/* B21A90 80241550 00000000 */  nop
/* B21A94 80241554 A6620002 */  sh        $v0, 2($s3)
/* B21A98 80241558 26730010 */  addiu     $s3, $s3, 0x10
.L8024155C:
/* B21A9C 8024155C 26940001 */  addiu     $s4, $s4, 1
/* B21AA0 80241560 0297102A */  slt       $v0, $s4, $s7
/* B21AA4 80241564 1440FFA2 */  bnez      $v0, .L802413F0
/* B21AA8 80241568 26520010 */   addiu    $s2, $s2, 0x10
.L8024156C:
/* B21AAC 8024156C 8FBF0030 */  lw        $ra, 0x30($sp)
/* B21AB0 80241570 8FB7002C */  lw        $s7, 0x2c($sp)
/* B21AB4 80241574 8FB60028 */  lw        $s6, 0x28($sp)
/* B21AB8 80241578 8FB50024 */  lw        $s5, 0x24($sp)
/* B21ABC 8024157C 8FB40020 */  lw        $s4, 0x20($sp)
/* B21AC0 80241580 8FB3001C */  lw        $s3, 0x1c($sp)
/* B21AC4 80241584 8FB20018 */  lw        $s2, 0x18($sp)
/* B21AC8 80241588 8FB10014 */  lw        $s1, 0x14($sp)
/* B21ACC 8024158C 8FB00010 */  lw        $s0, 0x10($sp)
/* B21AD0 80241590 D7BE0060 */  ldc1      $f30, 0x60($sp)
/* B21AD4 80241594 D7BC0058 */  ldc1      $f28, 0x58($sp)
/* B21AD8 80241598 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* B21ADC 8024159C D7B80048 */  ldc1      $f24, 0x48($sp)
/* B21AE0 802415A0 D7B60040 */  ldc1      $f22, 0x40($sp)
/* B21AE4 802415A4 D7B40038 */  ldc1      $f20, 0x38($sp)
/* B21AE8 802415A8 03E00008 */  jr        $ra
/* B21AEC 802415AC 27BD0068 */   addiu    $sp, $sp, 0x68
