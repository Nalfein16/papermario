.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel __osContRamWrite
/* 457C0 8006A3C0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 457C4 8006A3C4 8FA20058 */  lw        $v0, 0x58($sp)
/* 457C8 8006A3C8 AFB40030 */  sw        $s4, 0x30($sp)
/* 457CC 8006A3CC 0080A021 */  addu      $s4, $a0, $zero
/* 457D0 8006A3D0 AFB3002C */  sw        $s3, 0x2c($sp)
/* 457D4 8006A3D4 00A09821 */  addu      $s3, $a1, $zero
/* 457D8 8006A3D8 AFB50034 */  sw        $s5, 0x34($sp)
/* 457DC 8006A3DC 24150002 */  addiu     $s5, $zero, 2
/* 457E0 8006A3E0 AFB7003C */  sw        $s7, 0x3c($sp)
/* 457E4 8006A3E4 00E0B821 */  addu      $s7, $a3, $zero
/* 457E8 8006A3E8 AFB00020 */  sw        $s0, 0x20($sp)
/* 457EC 8006A3EC 00C08021 */  addu      $s0, $a2, $zero
/* 457F0 8006A3F0 3204FFFF */  andi      $a0, $s0, 0xffff
/* 457F4 8006A3F4 2C830007 */  sltiu     $v1, $a0, 7
/* 457F8 8006A3F8 AFBF0044 */  sw        $ra, 0x44($sp)
/* 457FC 8006A3FC AFBE0040 */  sw        $fp, 0x40($sp)
/* 45800 8006A400 AFB60038 */  sw        $s6, 0x38($sp)
/* 45804 8006A404 AFB20028 */  sw        $s2, 0x28($sp)
/* 45808 8006A408 38420001 */  xori      $v0, $v0, 1
/* 4580C 8006A40C 0002102B */  sltu      $v0, $zero, $v0
/* 45810 8006A410 00431024 */  and       $v0, $v0, $v1
/* 45814 8006A414 10400003 */  beqz      $v0, .L8006A424
/* 45818 8006A418 AFB10024 */   sw       $s1, 0x24($sp)
/* 4581C 8006A41C 1480005D */  bnez      $a0, .L8006A594
/* 45820 8006A420 00001021 */   addu     $v0, $zero, $zero
.L8006A424:
/* 45824 8006A424 0C019771 */  jal       __osSiGetAccess
/* 45828 8006A428 241E0003 */   addiu    $fp, $zero, 3
/* 4582C 8006A42C 3216FFFF */  andi      $s6, $s0, 0xffff
/* 45830 8006A430 00108140 */  sll       $s0, $s0, 5
/* 45834 8006A434 AFB00014 */  sw        $s0, 0x14($sp)
.L8006A438:
/* 45838 8006A438 3C02800A */  lui       $v0, %hi(__osContLastCmd)
/* 4583C 8006A43C 9042A61C */  lbu       $v0, %lo(__osContLastCmd)($v0)
/* 45840 8006A440 3C10800E */  lui       $s0, %hi(__osPfsPifRam)
/* 45844 8006A444 145E0005 */  bne       $v0, $fp, .L8006A45C
/* 45848 8006A448 2610A000 */   addiu    $s0, $s0, %lo(__osPfsPifRam)
/* 4584C 8006A44C 3C028009 */  lui       $v0, %hi(__osPfsLastChannel)
/* 45850 8006A450 8C4258E0 */  lw        $v0, %lo(__osPfsLastChannel)($v0)
/* 45854 8006A454 5053001A */  beql      $v0, $s3, .L8006A4C0
/* 45858 8006A458 02708021 */   addu     $s0, $s3, $s0
.L8006A45C:
/* 4585C 8006A45C 3C01800A */  lui       $at, %hi(__osContLastCmd)
/* 45860 8006A460 A03EA61C */  sb        $fp, %lo(__osContLastCmd)($at)
/* 45864 8006A464 3C018009 */  lui       $at, %hi(__osPfsLastChannel)
/* 45868 8006A468 AC3358E0 */  sw        $s3, %lo(__osPfsLastChannel)($at)
/* 4586C 8006A46C 1A600006 */  blez      $s3, .L8006A488
/* 45870 8006A470 00001821 */   addu     $v1, $zero, $zero
.L8006A474:
/* 45874 8006A474 A2000000 */  sb        $zero, ($s0)
/* 45878 8006A478 24630001 */  addiu     $v1, $v1, 1
/* 4587C 8006A47C 0073102A */  slt       $v0, $v1, $s3
/* 45880 8006A480 1440FFFC */  bnez      $v0, .L8006A474
/* 45884 8006A484 26100001 */   addiu    $s0, $s0, 1
.L8006A488:
/* 45888 8006A488 24080001 */  addiu     $t0, $zero, 1
/* 4588C 8006A48C 3C01800E */  lui       $at, %hi(D_800DA03C)
/* 45890 8006A490 AC28A03C */  sw        $t0, %lo(D_800DA03C)($at)
/* 45894 8006A494 240800FF */  addiu     $t0, $zero, 0xff
/* 45898 8006A498 24020023 */  addiu     $v0, $zero, 0x23
/* 4589C 8006A49C A2080000 */  sb        $t0, ($s0)
/* 458A0 8006A4A0 24080001 */  addiu     $t0, $zero, 1
/* 458A4 8006A4A4 A2080002 */  sb        $t0, 2($s0)
/* 458A8 8006A4A8 240800FF */  addiu     $t0, $zero, 0xff
/* 458AC 8006A4AC A2020001 */  sb        $v0, 1($s0)
/* 458B0 8006A4B0 240200FE */  addiu     $v0, $zero, 0xfe
/* 458B4 8006A4B4 A21E0003 */  sb        $fp, 3($s0)
/* 458B8 8006A4B8 A2080026 */  sb        $t0, 0x26($s0)
/* 458BC 8006A4BC A2020027 */  sb        $v0, 0x27($s0)
.L8006A4C0:
/* 458C0 8006A4C0 02C02021 */  addu      $a0, $s6, $zero
/* 458C4 8006A4C4 001610C2 */  srl       $v0, $s6, 3
/* 458C8 8006A4C8 0C01B218 */  jal       __osContAddressCrc
/* 458CC 8006A4CC A2020004 */   sb       $v0, 4($s0)
/* 458D0 8006A4D0 02E02021 */  addu      $a0, $s7, $zero
/* 458D4 8006A4D4 8FA80014 */  lw        $t0, 0x14($sp)
/* 458D8 8006A4D8 26050006 */  addiu     $a1, $s0, 6
/* 458DC 8006A4DC 24060020 */  addiu     $a2, $zero, 0x20
/* 458E0 8006A4E0 00481025 */  or        $v0, $v0, $t0
/* 458E4 8006A4E4 0C019194 */  jal       bcopy
/* 458E8 8006A4E8 A2020005 */   sb       $v0, 5($s0)
/* 458EC 8006A4EC 3C05800E */  lui       $a1, %hi(__osPfsPifRam)
/* 458F0 8006A4F0 24A5A000 */  addiu     $a1, $a1, %lo(__osPfsPifRam)
/* 458F4 8006A4F4 0C019730 */  jal       __osSiRawStartDma
/* 458F8 8006A4F8 24040001 */   addiu    $a0, $zero, 1
/* 458FC 8006A4FC 0C01B233 */  jal       __osContDataCrc
/* 45900 8006A500 02E02021 */   addu     $a0, $s7, $zero
/* 45904 8006A504 02802021 */  addu      $a0, $s4, $zero
/* 45908 8006A508 00002821 */  addu      $a1, $zero, $zero
/* 4590C 8006A50C 24060001 */  addiu     $a2, $zero, 1
/* 45910 8006A510 0C0195BC */  jal       osRecvMesg
/* 45914 8006A514 00409021 */   addu     $s2, $v0, $zero
/* 45918 8006A518 3C05800E */  lui       $a1, %hi(__osPfsPifRam)
/* 4591C 8006A51C 24A5A000 */  addiu     $a1, $a1, %lo(__osPfsPifRam)
/* 45920 8006A520 0C019730 */  jal       __osSiRawStartDma
/* 45924 8006A524 00002021 */   addu     $a0, $zero, $zero
/* 45928 8006A528 02802021 */  addu      $a0, $s4, $zero
/* 4592C 8006A52C 00002821 */  addu      $a1, $zero, $zero
/* 45930 8006A530 0C0195BC */  jal       osRecvMesg
/* 45934 8006A534 24060001 */   addiu    $a2, $zero, 1
/* 45938 8006A538 92020002 */  lbu       $v0, 2($s0)
/* 4593C 8006A53C 304200C0 */  andi      $v0, $v0, 0xc0
/* 45940 8006A540 00028902 */  srl       $s1, $v0, 4
/* 45944 8006A544 5620000B */  bnel      $s1, $zero, .L8006A574
/* 45948 8006A548 24110001 */   addiu    $s1, $zero, 1
/* 4594C 8006A54C 92030026 */  lbu       $v1, 0x26($s0)
/* 45950 8006A550 324200FF */  andi      $v0, $s2, 0xff
/* 45954 8006A554 10430007 */  beq       $v0, $v1, .L8006A574
/* 45958 8006A558 02802021 */   addu     $a0, $s4, $zero
/* 4595C 8006A55C 0C01A530 */  jal       __osPfsGetStatus
/* 45960 8006A560 02602821 */   addu     $a1, $s3, $zero
/* 45964 8006A564 00408821 */  addu      $s1, $v0, $zero
/* 45968 8006A568 16200007 */  bnez      $s1, .L8006A588
/* 4596C 8006A56C 00000000 */   nop
/* 45970 8006A570 24110004 */  addiu     $s1, $zero, 4
.L8006A574:
/* 45974 8006A574 24020004 */  addiu     $v0, $zero, 4
/* 45978 8006A578 16220003 */  bne       $s1, $v0, .L8006A588
/* 4597C 8006A57C 02A01021 */   addu     $v0, $s5, $zero
/* 45980 8006A580 0441FFAD */  bgez      $v0, .L8006A438
/* 45984 8006A584 26B5FFFF */   addiu    $s5, $s5, -1
.L8006A588:
/* 45988 8006A588 0C01978C */  jal       __osSiRelAccess
/* 4598C 8006A58C 00000000 */   nop
/* 45990 8006A590 02201021 */  addu      $v0, $s1, $zero
.L8006A594:
/* 45994 8006A594 8FBF0044 */  lw        $ra, 0x44($sp)
/* 45998 8006A598 8FBE0040 */  lw        $fp, 0x40($sp)
/* 4599C 8006A59C 8FB7003C */  lw        $s7, 0x3c($sp)
/* 459A0 8006A5A0 8FB60038 */  lw        $s6, 0x38($sp)
/* 459A4 8006A5A4 8FB50034 */  lw        $s5, 0x34($sp)
/* 459A8 8006A5A8 8FB40030 */  lw        $s4, 0x30($sp)
/* 459AC 8006A5AC 8FB3002C */  lw        $s3, 0x2c($sp)
/* 459B0 8006A5B0 8FB20028 */  lw        $s2, 0x28($sp)
/* 459B4 8006A5B4 8FB10024 */  lw        $s1, 0x24($sp)
/* 459B8 8006A5B8 8FB00020 */  lw        $s0, 0x20($sp)
/* 459BC 8006A5BC 03E00008 */  jr        $ra
/* 459C0 8006A5C0 27BD0048 */   addiu    $sp, $sp, 0x48
/* 459C4 8006A5C4 00000000 */  nop
/* 459C8 8006A5C8 00000000 */  nop
/* 459CC 8006A5CC 00000000 */  nop
/* 459D0 8006A5D0 00000000 */  nop
/* 459D4 8006A5D4 00000000 */  nop
/* 459D8 8006A5D8 00000000 */  nop
/* 459DC 8006A5DC 00000000 */  nop
/* 459E0 8006A5E0 00000000 */  nop
/* 459E4 8006A5E4 00000000 */  nop
/* 459E8 8006A5E8 00000000 */  nop
/* 459EC 8006A5EC 00000000 */  nop
/* 459F0 8006A5F0 00000000 */  nop
/* 459F4 8006A5F4 00000000 */  nop
/* 459F8 8006A5F8 00000000 */  nop
/* 459FC 8006A5FC 00000000 */  nop
/* 45A00 8006A600 00000000 */  nop
/* 45A04 8006A604 00000000 */  nop
/* 45A08 8006A608 00000000 */  nop
/* 45A0C 8006A60C 00000000 */  nop
/* 45A10 8006A610 00000000 */  nop
/* 45A14 8006A614 00000000 */  nop
/* 45A18 8006A618 00000000 */  nop
/* 45A1C 8006A61C 00000000 */  nop
/* 45A20 8006A620 00000000 */  nop
/* 45A24 8006A624 00000000 */  nop
/* 45A28 8006A628 00000000 */  nop
/* 45A2C 8006A62C 00000000 */  nop
