.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel star_outline_update
/* 413494 E0126134 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 413498 E0126138 AFBF001C */  sw        $ra, 0x1c($sp)
/* 41349C E012613C AFB20018 */  sw        $s2, 0x18($sp)
/* 4134A0 E0126140 AFB10014 */  sw        $s1, 0x14($sp)
/* 4134A4 E0126144 AFB00010 */  sw        $s0, 0x10($sp)
/* 4134A8 E0126148 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 4134AC E012614C F7B60028 */  sdc1      $f22, 0x28($sp)
/* 4134B0 E0126150 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 4134B4 E0126154 8C830000 */  lw        $v1, ($a0)
/* 4134B8 E0126158 8C90000C */  lw        $s0, 0xc($a0)
/* 4134BC E012615C 30620010 */  andi      $v0, $v1, 0x10
/* 4134C0 E0126160 86060002 */  lh        $a2, 2($s0)
/* 4134C4 E0126164 10400005 */  beqz      $v0, .LE012617C
/* 4134C8 E0126168 2402FFEF */   addiu    $v0, $zero, -0x11
/* 4134CC E012616C 00621024 */  and       $v0, $v1, $v0
/* 4134D0 E0126170 AC820000 */  sw        $v0, ($a0)
/* 4134D4 E0126174 24020010 */  addiu     $v0, $zero, 0x10
/* 4134D8 E0126178 AE020010 */  sw        $v0, 0x10($s0)
.LE012617C:
/* 4134DC E012617C 8E030010 */  lw        $v1, 0x10($s0)
/* 4134E0 E0126180 286203E8 */  slti      $v0, $v1, 0x3e8
/* 4134E4 E0126184 10400002 */  beqz      $v0, .LE0126190
/* 4134E8 E0126188 2462FFFF */   addiu    $v0, $v1, -1
/* 4134EC E012618C AE020010 */  sw        $v0, 0x10($s0)
.LE0126190:
/* 4134F0 E0126190 8E020014 */  lw        $v0, 0x14($s0)
/* 4134F4 E0126194 8E050010 */  lw        $a1, 0x10($s0)
/* 4134F8 E0126198 24420001 */  addiu     $v0, $v0, 1
/* 4134FC E012619C 04A10005 */  bgez      $a1, .LE01261B4
/* 413500 E01261A0 AE020014 */   sw       $v0, 0x14($s0)
/* 413504 E01261A4 0C080128 */  jal       shim_remove_effect
/* 413508 E01261A8 00000000 */   nop
/* 41350C E01261AC 08049920 */  j         .LE0126480
/* 413510 E01261B0 00000000 */   nop
.LE01261B4:
/* 413514 E01261B4 0040882D */  daddu     $s1, $v0, $zero
/* 413518 E01261B8 28A20010 */  slti      $v0, $a1, 0x10
/* 41351C E01261BC 1040000B */  beqz      $v0, .LE01261EC
/* 413520 E01261C0 2A220010 */   slti     $v0, $s1, 0x10
/* 413524 E01261C4 8E020024 */  lw        $v0, 0x24($s0)
/* 413528 E01261C8 00051900 */  sll       $v1, $a1, 4
/* 41352C E01261CC 0062102A */  slt       $v0, $v1, $v0
/* 413530 E01261D0 54400001 */  bnel      $v0, $zero, .LE01261D8
/* 413534 E01261D4 AE030024 */   sw       $v1, 0x24($s0)
.LE01261D8:
/* 413538 E01261D8 8E020034 */  lw        $v0, 0x34($s0)
/* 41353C E01261DC 0062102A */  slt       $v0, $v1, $v0
/* 413540 E01261E0 54400001 */  bnel      $v0, $zero, .LE01261E8
/* 413544 E01261E4 AE030034 */   sw       $v1, 0x34($s0)
.LE01261E8:
/* 413548 E01261E8 2A220010 */  slti      $v0, $s1, 0x10
.LE01261EC:
/* 41354C E01261EC 1040000B */  beqz      $v0, .LE012621C
/* 413550 E01261F0 00000000 */   nop
/* 413554 E01261F4 00111900 */  sll       $v1, $s1, 4
/* 413558 E01261F8 8E020024 */  lw        $v0, 0x24($s0)
/* 41355C E01261FC 2463000F */  addiu     $v1, $v1, 0xf
/* 413560 E0126200 0043102A */  slt       $v0, $v0, $v1
/* 413564 E0126204 54400001 */  bnel      $v0, $zero, .LE012620C
/* 413568 E0126208 AE030024 */   sw       $v1, 0x24($s0)
.LE012620C:
/* 41356C E012620C 8E020034 */  lw        $v0, 0x34($s0)
/* 413570 E0126210 0043102A */  slt       $v0, $v0, $v1
/* 413574 E0126214 54400001 */  bnel      $v0, $zero, .LE012621C
/* 413578 E0126218 AE030034 */   sw       $v1, 0x34($s0)
.LE012621C:
/* 41357C E012621C C600003C */  lwc1      $f0, 0x3c($s0)
/* 413580 E0126220 C6020040 */  lwc1      $f2, 0x40($s0)
/* 413584 E0126224 C6040044 */  lwc1      $f4, 0x44($s0)
/* 413588 E0126228 C6060038 */  lwc1      $f6, 0x38($s0)
/* 41358C E012622C 24120001 */  addiu     $s2, $zero, 1
/* 413590 E0126230 E6000048 */  swc1      $f0, 0x48($s0)
/* 413594 E0126234 E602004C */  swc1      $f2, 0x4c($s0)
/* 413598 E0126238 E6040050 */  swc1      $f4, 0x50($s0)
/* 41359C E012623C 14D20086 */  bne       $a2, $s2, .LE0126458
/* 4135A0 E0126240 E6060054 */   swc1     $f6, 0x54($s0)
/* 4135A4 E0126244 3C014080 */  lui       $at, 0x4080
/* 4135A8 E0126248 44810000 */  mtc1      $at, $f0
/* 4135AC E012624C 4491A000 */  mtc1      $s1, $f20
/* 4135B0 E0126250 00000000 */  nop
/* 4135B4 E0126254 4680A520 */  cvt.s.w   $f20, $f20
/* 4135B8 E0126258 4600A002 */  mul.s     $f0, $f20, $f0
/* 4135BC E012625C 00000000 */  nop
/* 4135C0 E0126260 3C01E012 */  lui       $at, %hi(D_E0126BD0)
/* 4135C4 E0126264 D42C6BD0 */  ldc1      $f12, %lo(D_E0126BD0)($at)
/* 4135C8 E0126268 4600A521 */  cvt.d.s   $f20, $f20
/* 4135CC E012626C 462CA302 */  mul.d     $f12, $f20, $f12
/* 4135D0 E0126270 00000000 */  nop
/* 4135D4 E0126274 3C01E012 */  lui       $at, %hi(D_E0126BD8)
/* 4135D8 E0126278 D4246BD8 */  ldc1      $f4, %lo(D_E0126BD8)($at)
/* 4135DC E012627C 46000021 */  cvt.d.s   $f0, $f0
/* 4135E0 E0126280 46240102 */  mul.d     $f4, $f0, $f4
/* 4135E4 E0126284 00000000 */  nop
/* 4135E8 E0126288 3C01E012 */  lui       $at, %hi(D_E0126BE0)
/* 4135EC E012628C D4226BE0 */  ldc1      $f2, %lo(D_E0126BE0)($at)
/* 4135F0 E0126290 46220002 */  mul.d     $f0, $f0, $f2
/* 4135F4 E0126294 00000000 */  nop
/* 4135F8 E0126298 00111080 */  sll       $v0, $s1, 2
/* 4135FC E012629C 44821000 */  mtc1      $v0, $f2
/* 413600 E01262A0 00000000 */  nop
/* 413604 E01262A4 468010A0 */  cvt.s.w   $f2, $f2
/* 413608 E01262A8 240200FF */  addiu     $v0, $zero, 0xff
/* 41360C E01262AC E602003C */  swc1      $f2, 0x3c($s0)
/* 413610 E01262B0 AE020024 */  sw        $v0, 0x24($s0)
/* 413614 E01262B4 46206320 */  cvt.s.d   $f12, $f12
/* 413618 E01262B8 46202120 */  cvt.s.d   $f4, $f4
/* 41361C E01262BC 46200020 */  cvt.s.d   $f0, $f0
/* 413620 E01262C0 E6040040 */  swc1      $f4, 0x40($s0)
/* 413624 E01262C4 0C080140 */  jal       shim_sin_deg
/* 413628 E01262C8 E6000044 */   swc1     $f0, 0x44($s0)
/* 41362C E01262CC 3C01E012 */  lui       $at, %hi(D_E0126BE8)
/* 413630 E01262D0 D42C6BE8 */  ldc1      $f12, %lo(D_E0126BE8)($at)
/* 413634 E01262D4 462CA302 */  mul.d     $f12, $f20, $f12
/* 413638 E01262D8 00000000 */  nop
/* 41363C E01262DC 3C0142FE */  lui       $at, 0x42fe
/* 413640 E01262E0 4481C000 */  mtc1      $at, $f24
/* 413644 E01262E4 00000000 */  nop
/* 413648 E01262E8 46180002 */  mul.s     $f0, $f0, $f24
/* 41364C E01262EC 00000000 */  nop
/* 413650 E01262F0 3C014300 */  lui       $at, 0x4300
/* 413654 E01262F4 44811000 */  mtc1      $at, $f2
/* 413658 E01262F8 00000000 */  nop
/* 41365C E01262FC 46020000 */  add.s     $f0, $f0, $f2
/* 413660 E0126300 4600020D */  trunc.w.s $f8, $f0
/* 413664 E0126304 E6080034 */  swc1      $f8, 0x34($s0)
/* 413668 E0126308 0C080140 */  jal       shim_sin_deg
/* 41366C E012630C 46206320 */   cvt.s.d  $f12, $f12
/* 413670 E0126310 3C01E012 */  lui       $at, %hi(D_E0126BF0)
/* 413674 E0126314 D42C6BF0 */  ldc1      $f12, %lo(D_E0126BF0)($at)
/* 413678 E0126318 462CA302 */  mul.d     $f12, $f20, $f12
/* 41367C E012631C 00000000 */  nop
/* 413680 E0126320 46180002 */  mul.s     $f0, $f0, $f24
/* 413684 E0126324 00000000 */  nop
/* 413688 E0126328 3C014357 */  lui       $at, 0x4357
/* 41368C E012632C 4481B000 */  mtc1      $at, $f22
/* 413690 E0126330 00000000 */  nop
/* 413694 E0126334 46160000 */  add.s     $f0, $f0, $f22
/* 413698 E0126338 4600020D */  trunc.w.s $f8, $f0
/* 41369C E012633C E6080018 */  swc1      $f8, 0x18($s0)
/* 4136A0 E0126340 0C080140 */  jal       shim_sin_deg
/* 4136A4 E0126344 46206320 */   cvt.s.d  $f12, $f12
/* 4136A8 E0126348 3C01E012 */  lui       $at, %hi(D_E0126BF8)
/* 4136AC E012634C D42C6BF8 */  ldc1      $f12, %lo(D_E0126BF8)($at)
/* 4136B0 E0126350 462CA302 */  mul.d     $f12, $f20, $f12
/* 4136B4 E0126354 00000000 */  nop
/* 4136B8 E0126358 46180002 */  mul.s     $f0, $f0, $f24
/* 4136BC E012635C 00000000 */  nop
/* 4136C0 E0126360 46160000 */  add.s     $f0, $f0, $f22
/* 4136C4 E0126364 4600020D */  trunc.w.s $f8, $f0
/* 4136C8 E0126368 E608001C */  swc1      $f8, 0x1c($s0)
/* 4136CC E012636C 0C080140 */  jal       shim_sin_deg
/* 4136D0 E0126370 46206320 */   cvt.s.d  $f12, $f12
/* 4136D4 E0126374 3C01E012 */  lui       $at, %hi(D_E0126C00)
/* 4136D8 E0126378 D42C6C00 */  ldc1      $f12, %lo(D_E0126C00)($at)
/* 4136DC E012637C 462CA302 */  mul.d     $f12, $f20, $f12
/* 4136E0 E0126380 00000000 */  nop
/* 4136E4 E0126384 46180002 */  mul.s     $f0, $f0, $f24
/* 4136E8 E0126388 00000000 */  nop
/* 4136EC E012638C 46160000 */  add.s     $f0, $f0, $f22
/* 4136F0 E0126390 4600020D */  trunc.w.s $f8, $f0
/* 4136F4 E0126394 E6080020 */  swc1      $f8, 0x20($s0)
/* 4136F8 E0126398 0C080140 */  jal       shim_sin_deg
/* 4136FC E012639C 46206320 */   cvt.s.d  $f12, $f12
/* 413700 E01263A0 3C01E012 */  lui       $at, %hi(D_E0126C08)
/* 413704 E01263A4 D42C6C08 */  ldc1      $f12, %lo(D_E0126C08)($at)
/* 413708 E01263A8 462CA302 */  mul.d     $f12, $f20, $f12
/* 41370C E01263AC 00000000 */  nop
/* 413710 E01263B0 46180002 */  mul.s     $f0, $f0, $f24
/* 413714 E01263B4 00000000 */  nop
/* 413718 E01263B8 3C01433C */  lui       $at, 0x433c
/* 41371C E01263BC 4481B000 */  mtc1      $at, $f22
/* 413720 E01263C0 00000000 */  nop
/* 413724 E01263C4 46160000 */  add.s     $f0, $f0, $f22
/* 413728 E01263C8 4600020D */  trunc.w.s $f8, $f0
/* 41372C E01263CC E6080028 */  swc1      $f8, 0x28($s0)
/* 413730 E01263D0 0C080140 */  jal       shim_sin_deg
/* 413734 E01263D4 46206320 */   cvt.s.d  $f12, $f12
/* 413738 E01263D8 3C01E012 */  lui       $at, %hi(D_E0126C10)
/* 41373C E01263DC D42C6C10 */  ldc1      $f12, %lo(D_E0126C10)($at)
/* 413740 E01263E0 462CA302 */  mul.d     $f12, $f20, $f12
/* 413744 E01263E4 00000000 */  nop
/* 413748 E01263E8 46180002 */  mul.s     $f0, $f0, $f24
/* 41374C E01263EC 00000000 */  nop
/* 413750 E01263F0 46160000 */  add.s     $f0, $f0, $f22
/* 413754 E01263F4 4600020D */  trunc.w.s $f8, $f0
/* 413758 E01263F8 E608002C */  swc1      $f8, 0x2c($s0)
/* 41375C E01263FC 0C080140 */  jal       shim_sin_deg
/* 413760 E0126400 46206320 */   cvt.s.d  $f12, $f12
/* 413764 E0126404 3C01E012 */  lui       $at, %hi(D_E0126C18)
/* 413768 E0126408 D4226C18 */  ldc1      $f2, %lo(D_E0126C18)($at)
/* 41376C E012640C 4622A502 */  mul.d     $f20, $f20, $f2
/* 413770 E0126410 00000000 */  nop
/* 413774 E0126414 46180002 */  mul.s     $f0, $f0, $f24
/* 413778 E0126418 00000000 */  nop
/* 41377C E012641C 46160000 */  add.s     $f0, $f0, $f22
/* 413780 E0126420 4600020D */  trunc.w.s $f8, $f0
/* 413784 E0126424 E6080030 */  swc1      $f8, 0x30($s0)
/* 413788 E0126428 0C080140 */  jal       shim_sin_deg
/* 41378C E012642C 4620A320 */   cvt.s.d  $f12, $f20
/* 413790 E0126430 3C01E012 */  lui       $at, %hi(D_E0126C20)
/* 413794 E0126434 D4226C20 */  ldc1      $f2, %lo(D_E0126C20)($at)
/* 413798 E0126438 46000021 */  cvt.d.s   $f0, $f0
/* 41379C E012643C 46220002 */  mul.d     $f0, $f0, $f2
/* 4137A0 E0126440 00000000 */  nop
/* 4137A4 E0126444 3C01E012 */  lui       $at, %hi(D_E0126C28)
/* 4137A8 E0126448 D4226C28 */  ldc1      $f2, %lo(D_E0126C28)($at)
/* 4137AC E012644C 46220000 */  add.d     $f0, $f0, $f2
/* 4137B0 E0126450 46200020 */  cvt.s.d   $f0, $f0
/* 4137B4 E0126454 E6000038 */  swc1      $f0, 0x38($s0)
.LE0126458:
/* 4137B8 E0126458 16320009 */  bne       $s1, $s2, .LE0126480
/* 4137BC E012645C 00000000 */   nop
/* 4137C0 E0126460 C600003C */  lwc1      $f0, 0x3c($s0)
/* 4137C4 E0126464 C6020040 */  lwc1      $f2, 0x40($s0)
/* 4137C8 E0126468 C6040044 */  lwc1      $f4, 0x44($s0)
/* 4137CC E012646C C6060038 */  lwc1      $f6, 0x38($s0)
/* 4137D0 E0126470 E6000048 */  swc1      $f0, 0x48($s0)
/* 4137D4 E0126474 E602004C */  swc1      $f2, 0x4c($s0)
/* 4137D8 E0126478 E6040050 */  swc1      $f4, 0x50($s0)
/* 4137DC E012647C E6060054 */  swc1      $f6, 0x54($s0)
.LE0126480:
/* 4137E0 E0126480 8FBF001C */  lw        $ra, 0x1c($sp)
/* 4137E4 E0126484 8FB20018 */  lw        $s2, 0x18($sp)
/* 4137E8 E0126488 8FB10014 */  lw        $s1, 0x14($sp)
/* 4137EC E012648C 8FB00010 */  lw        $s0, 0x10($sp)
/* 4137F0 E0126490 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 4137F4 E0126494 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 4137F8 E0126498 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 4137FC E012649C 03E00008 */  jr        $ra
/* 413800 E01264A0 27BD0038 */   addiu    $sp, $sp, 0x38
