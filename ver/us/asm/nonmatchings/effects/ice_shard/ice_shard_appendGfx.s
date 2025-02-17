.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ice_shard_appendGfx
/* 3F87DC E01103EC 27BDFF38 */  addiu     $sp, $sp, -0xc8
/* 3F87E0 E01103F0 0080402D */  daddu     $t0, $a0, $zero
/* 3F87E4 E01103F4 3C09DB06 */  lui       $t1, 0xdb06
/* 3F87E8 E01103F8 35290024 */  ori       $t1, $t1, 0x24
/* 3F87EC E01103FC AFB500B4 */  sw        $s5, 0xb4($sp)
/* 3F87F0 E0110400 3C15800A */  lui       $s5, %hi(gMasterGfxPos)
/* 3F87F4 E0110404 26B5A66C */  addiu     $s5, $s5, %lo(gMasterGfxPos)
/* 3F87F8 E0110408 3C02E700 */  lui       $v0, 0xe700
/* 3F87FC E011040C AFBF00BC */  sw        $ra, 0xbc($sp)
/* 3F8800 E0110410 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 3F8804 E0110414 AFB400B0 */  sw        $s4, 0xb0($sp)
/* 3F8808 E0110418 AFB300AC */  sw        $s3, 0xac($sp)
/* 3F880C E011041C AFB200A8 */  sw        $s2, 0xa8($sp)
/* 3F8810 E0110420 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 3F8814 E0110424 AFB000A0 */  sw        $s0, 0xa0($sp)
/* 3F8818 E0110428 F7B400C0 */  sdc1      $f20, 0xc0($sp)
/* 3F881C E011042C 8EA60000 */  lw        $a2, ($s5)
/* 3F8820 E0110430 4480A000 */  mtc1      $zero, $f20
/* 3F8824 E0110434 8D14000C */  lw        $s4, 0xc($t0)
/* 3F8828 E0110438 00C0182D */  daddu     $v1, $a2, $zero
/* 3F882C E011043C 8E960024 */  lw        $s6, 0x24($s4)
/* 3F8830 E0110440 8E930000 */  lw        $s3, ($s4)
/* 3F8834 E0110444 24C60008 */  addiu     $a2, $a2, 8
/* 3F8838 E0110448 AC620000 */  sw        $v0, ($v1)
/* 3F883C E011044C AC600004 */  sw        $zero, 4($v1)
/* 3F8840 E0110450 ACC90000 */  sw        $t1, ($a2)
/* 3F8844 E0110454 8D020010 */  lw        $v0, 0x10($t0)
/* 3F8848 E0110458 3C088000 */  lui       $t0, 0x8000
/* 3F884C E011045C 4405A000 */  mfc1      $a1, $f20
/* 3F8850 E0110460 4407A000 */  mfc1      $a3, $f20
/* 3F8854 E0110464 8C42001C */  lw        $v0, 0x1c($v0)
/* 3F8858 E0110468 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3F885C E011046C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3F8860 E0110470 00481021 */  addu      $v0, $v0, $t0
/* 3F8864 E0110474 ACC20004 */  sw        $v0, 4($a2)
/* 3F8868 E0110478 00031080 */  sll       $v0, $v1, 2
/* 3F886C E011047C 00431021 */  addu      $v0, $v0, $v1
/* 3F8870 E0110480 00021080 */  sll       $v0, $v0, 2
/* 3F8874 E0110484 00431023 */  subu      $v0, $v0, $v1
/* 3F8878 E0110488 000218C0 */  sll       $v1, $v0, 3
/* 3F887C E011048C 00431021 */  addu      $v0, $v0, $v1
/* 3F8880 E0110490 000210C0 */  sll       $v0, $v0, 3
/* 3F8884 E0110494 C6800038 */  lwc1      $f0, 0x38($s4)
/* 3F8888 E0110498 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 3F888C E011049C 00220821 */  addu      $at, $at, $v0
/* 3F8890 E01104A0 C4221DEC */  lwc1      $f2, %lo(gCameras+0x6C)($at)
/* 3F8894 E01104A4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3F8898 E01104A8 C6800004 */  lwc1      $f0, 4($s4)
/* 3F889C E01104AC 27A40020 */  addiu     $a0, $sp, 0x20
/* 3F88A0 E01104B0 AEA60000 */  sw        $a2, ($s5)
/* 3F88A4 E01104B4 24C60008 */  addiu     $a2, $a2, 8
/* 3F88A8 E01104B8 E7A00014 */  swc1      $f0, 0x14($sp)
/* 3F88AC E01104BC C6800008 */  lwc1      $f0, 8($s4)
/* 3F88B0 E01104C0 46001087 */  neg.s     $f2, $f2
/* 3F88B4 E01104C4 AEA60000 */  sw        $a2, ($s5)
/* 3F88B8 E01104C8 44061000 */  mfc1      $a2, $f2
/* 3F88BC E01104CC 3C120001 */  lui       $s2, 1
/* 3F88C0 E01104D0 E7A00018 */  swc1      $f0, 0x18($sp)
/* 3F88C4 E01104D4 C680000C */  lwc1      $f0, 0xc($s4)
/* 3F88C8 E01104D8 36521630 */  ori       $s2, $s2, 0x1630
/* 3F88CC E01104DC 0C080180 */  jal       shim_guPositionF
/* 3F88D0 E01104E0 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 3F88D4 E01104E4 27A40020 */  addiu     $a0, $sp, 0x20
/* 3F88D8 E01104E8 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3F88DC E01104EC 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3F88E0 E01104F0 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 3F88E4 E01104F4 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 3F88E8 E01104F8 96050000 */  lhu       $a1, ($s0)
/* 3F88EC E01104FC 8E220000 */  lw        $v0, ($s1)
/* 3F88F0 E0110500 00052980 */  sll       $a1, $a1, 6
/* 3F88F4 E0110504 00B22821 */  addu      $a1, $a1, $s2
/* 3F88F8 E0110508 0C080118 */  jal       shim_guMtxF2L
/* 3F88FC E011050C 00452821 */   addu     $a1, $v0, $a1
/* 3F8900 E0110510 3C02DA38 */  lui       $v0, 0xda38
/* 3F8904 E0110514 34420002 */  ori       $v0, $v0, 2
/* 3F8908 E0110518 27A40020 */  addiu     $a0, $sp, 0x20
/* 3F890C E011051C 8EA90000 */  lw        $t1, ($s5)
/* 3F8910 E0110520 4406A000 */  mfc1      $a2, $f20
/* 3F8914 E0110524 96080000 */  lhu       $t0, ($s0)
/* 3F8918 E0110528 3C013F80 */  lui       $at, 0x3f80
/* 3F891C E011052C 44810000 */  mtc1      $at, $f0
/* 3F8920 E0110530 00C0382D */  daddu     $a3, $a2, $zero
/* 3F8924 E0110534 0120282D */  daddu     $a1, $t1, $zero
/* 3F8928 E0110538 3103FFFF */  andi      $v1, $t0, 0xffff
/* 3F892C E011053C 00031980 */  sll       $v1, $v1, 6
/* 3F8930 E0110540 00721821 */  addu      $v1, $v1, $s2
/* 3F8934 E0110544 ACA20000 */  sw        $v0, ($a1)
/* 3F8938 E0110548 8E220000 */  lw        $v0, ($s1)
/* 3F893C E011054C 25290008 */  addiu     $t1, $t1, 8
/* 3F8940 E0110550 00431021 */  addu      $v0, $v0, $v1
/* 3F8944 E0110554 ACA20004 */  sw        $v0, 4($a1)
/* 3F8948 E0110558 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3F894C E011055C 8E85003C */  lw        $a1, 0x3c($s4)
/* 3F8950 E0110560 25080001 */  addiu     $t0, $t0, 1
/* 3F8954 E0110564 AEA90000 */  sw        $t1, ($s5)
/* 3F8958 E0110568 0C080104 */  jal       shim_guRotateF
/* 3F895C E011056C A6080000 */   sh       $t0, ($s0)
/* 3F8960 E0110570 27A40020 */  addiu     $a0, $sp, 0x20
/* 3F8964 E0110574 96050000 */  lhu       $a1, ($s0)
/* 3F8968 E0110578 8E220000 */  lw        $v0, ($s1)
/* 3F896C E011057C 00052980 */  sll       $a1, $a1, 6
/* 3F8970 E0110580 00B22821 */  addu      $a1, $a1, $s2
/* 3F8974 E0110584 0C080118 */  jal       shim_guMtxF2L
/* 3F8978 E0110588 00452821 */   addu     $a1, $v0, $a1
/* 3F897C E011058C 3C07D838 */  lui       $a3, 0xd838
/* 3F8980 E0110590 3C03DA38 */  lui       $v1, 0xda38
/* 3F8984 E0110594 3C0BDE00 */  lui       $t3, 0xde00
/* 3F8988 E0110598 3C0CFA00 */  lui       $t4, 0xfa00
/* 3F898C E011059C 8EA90000 */  lw        $t1, ($s5)
/* 3F8990 E01105A0 3C014080 */  lui       $at, 0x4080
/* 3F8994 E01105A4 44812000 */  mtc1      $at, $f4
/* 3F8998 E01105A8 0120202D */  daddu     $a0, $t1, $zero
/* 3F899C E01105AC 25290008 */  addiu     $t1, $t1, 8
/* 3F89A0 E01105B0 AEA90000 */  sw        $t1, ($s5)
/* 3F89A4 E01105B4 96020000 */  lhu       $v0, ($s0)
/* 3F89A8 E01105B8 3C06F200 */  lui       $a2, 0xf200
/* 3F89AC E01105BC AC830000 */  sw        $v1, ($a0)
/* 3F89B0 E01105C0 24430001 */  addiu     $v1, $v0, 1
/* 3F89B4 E01105C4 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3F89B8 E01105C8 00021180 */  sll       $v0, $v0, 6
/* 3F89BC E01105CC A6030000 */  sh        $v1, ($s0)
/* 3F89C0 E01105D0 8E230000 */  lw        $v1, ($s1)
/* 3F89C4 E01105D4 00521021 */  addu      $v0, $v0, $s2
/* 3F89C8 E01105D8 00621821 */  addu      $v1, $v1, $v0
/* 3F89CC E01105DC 25220008 */  addiu     $v0, $t1, 8
/* 3F89D0 E01105E0 AC830004 */  sw        $v1, 4($a0)
/* 3F89D4 E01105E4 AEA20000 */  sw        $v0, ($s5)
/* 3F89D8 E01105E8 25220010 */  addiu     $v0, $t1, 0x10
/* 3F89DC E01105EC AD2B0000 */  sw        $t3, ($t1)
/* 3F89E0 E01105F0 AEA20000 */  sw        $v0, ($s5)
/* 3F89E4 E01105F4 25220018 */  addiu     $v0, $t1, 0x18
/* 3F89E8 E01105F8 AEA20000 */  sw        $v0, ($s5)
/* 3F89EC E01105FC 3C03E011 */  lui       $v1, %hi(D_E01108B4)
/* 3F89F0 E0110600 8C6308B4 */  lw        $v1, %lo(D_E01108B4)($v1)
/* 3F89F4 E0110604 25220020 */  addiu     $v0, $t1, 0x20
/* 3F89F8 E0110608 AEA20000 */  sw        $v0, ($s5)
/* 3F89FC E011060C 001317C2 */  srl       $v0, $s3, 0x1f
/* 3F8A00 E0110610 02621021 */  addu      $v0, $s3, $v0
/* 3F8A04 E0110614 00021043 */  sra       $v0, $v0, 1
/* 3F8A08 E0110618 00021040 */  sll       $v0, $v0, 1
/* 3F8A0C E011061C 02629823 */  subu      $s3, $s3, $v0
/* 3F8A10 E0110620 001329C0 */  sll       $a1, $s3, 7
/* 3F8A14 E0110624 30A50FFF */  andi      $a1, $a1, 0xfff
/* 3F8A18 E0110628 00052B00 */  sll       $a1, $a1, 0xc
/* 3F8A1C E011062C AD230004 */  sw        $v1, 4($t1)
/* 3F8A20 E0110630 C6800044 */  lwc1      $f0, 0x44($s4)
/* 3F8A24 E0110634 001319C0 */  sll       $v1, $s3, 7
/* 3F8A28 E0110638 46040082 */  mul.s     $f2, $f0, $f4
/* 3F8A2C E011063C 00000000 */  nop
/* 3F8A30 E0110640 3463007C */  ori       $v1, $v1, 0x7c
/* 3F8A34 E0110644 30630FFF */  andi      $v1, $v1, 0xfff
/* 3F8A38 E0110648 00031B00 */  sll       $v1, $v1, 0xc
/* 3F8A3C E011064C AD2C0018 */  sw        $t4, 0x18($t1)
/* 3F8A40 E0110650 4600118D */  trunc.w.s $f6, $f2
/* 3F8A44 E0110654 44043000 */  mfc1      $a0, $f6
/* 3F8A48 E0110658 00000000 */  nop
/* 3F8A4C E011065C 000411C0 */  sll       $v0, $a0, 7
/* 3F8A50 E0110660 30420FFF */  andi      $v0, $v0, 0xfff
/* 3F8A54 E0110664 00461025 */  or        $v0, $v0, $a2
/* 3F8A58 E0110668 00A21025 */  or        $v0, $a1, $v0
/* 3F8A5C E011066C 00042140 */  sll       $a0, $a0, 5
/* 3F8A60 E0110670 AD220008 */  sw        $v0, 8($t1)
/* 3F8A64 E0110674 2482001F */  addiu     $v0, $a0, 0x1f
/* 3F8A68 E0110678 00021080 */  sll       $v0, $v0, 2
/* 3F8A6C E011067C 30420FFF */  andi      $v0, $v0, 0xfff
/* 3F8A70 E0110680 00621025 */  or        $v0, $v1, $v0
/* 3F8A74 E0110684 AD22000C */  sw        $v0, 0xc($t1)
/* 3F8A78 E0110688 24820020 */  addiu     $v0, $a0, 0x20
/* 3F8A7C E011068C 00021080 */  sll       $v0, $v0, 2
/* 3F8A80 E0110690 30420FFF */  andi      $v0, $v0, 0xfff
/* 3F8A84 E0110694 00461025 */  or        $v0, $v0, $a2
/* 3F8A88 E0110698 00A22825 */  or        $a1, $a1, $v0
/* 3F8A8C E011069C 2484003F */  addiu     $a0, $a0, 0x3f
/* 3F8A90 E01106A0 00042080 */  sll       $a0, $a0, 2
/* 3F8A94 E01106A4 30840FFF */  andi      $a0, $a0, 0xfff
/* 3F8A98 E01106A8 3C020100 */  lui       $v0, 0x100
/* 3F8A9C E01106AC 00822025 */  or        $a0, $a0, $v0
/* 3F8AA0 E01106B0 00641825 */  or        $v1, $v1, $a0
/* 3F8AA4 E01106B4 AD250010 */  sw        $a1, 0x10($t1)
/* 3F8AA8 E01106B8 AD230014 */  sw        $v1, 0x14($t1)
/* 3F8AAC E01106BC 9283001B */  lbu       $v1, 0x1b($s4)
/* 3F8AB0 E01106C0 9284001F */  lbu       $a0, 0x1f($s4)
/* 3F8AB4 E01106C4 92850023 */  lbu       $a1, 0x23($s4)
/* 3F8AB8 E01106C8 25220028 */  addiu     $v0, $t1, 0x28
/* 3F8ABC E01106CC AEA20000 */  sw        $v0, ($s5)
/* 3F8AC0 E01106D0 3C02FB00 */  lui       $v0, 0xfb00
/* 3F8AC4 E01106D4 AD220020 */  sw        $v0, 0x20($t1)
/* 3F8AC8 E01106D8 4600018D */  trunc.w.s $f6, $f0
/* 3F8ACC E01106DC 44023000 */  mfc1      $v0, $f6
/* 3F8AD0 E01106E0 00000000 */  nop
/* 3F8AD4 E01106E4 00021080 */  sll       $v0, $v0, 2
/* 3F8AD8 E01106E8 44820000 */  mtc1      $v0, $f0
/* 3F8ADC E01106EC 00000000 */  nop
/* 3F8AE0 E01106F0 46800020 */  cvt.s.w   $f0, $f0
/* 3F8AE4 E01106F4 32C200FF */  andi      $v0, $s6, 0xff
/* 3F8AE8 E01106F8 46001081 */  sub.s     $f2, $f2, $f0
/* 3F8AEC E01106FC 3C014380 */  lui       $at, 0x4380
/* 3F8AF0 E0110700 44810000 */  mtc1      $at, $f0
/* 3F8AF4 E0110704 00031E00 */  sll       $v1, $v1, 0x18
/* 3F8AF8 E0110708 00042400 */  sll       $a0, $a0, 0x10
/* 3F8AFC E011070C 00641825 */  or        $v1, $v1, $a0
/* 3F8B00 E0110710 00052A00 */  sll       $a1, $a1, 8
/* 3F8B04 E0110714 00651825 */  or        $v1, $v1, $a1
/* 3F8B08 E0110718 00621825 */  or        $v1, $v1, $v0
/* 3F8B0C E011071C AD23001C */  sw        $v1, 0x1c($t1)
/* 3F8B10 E0110720 9282002B */  lbu       $v0, 0x2b($s4)
/* 3F8B14 E0110724 9283002F */  lbu       $v1, 0x2f($s4)
/* 3F8B18 E0110728 92840033 */  lbu       $a0, 0x33($s4)
/* 3F8B1C E011072C 34E70002 */  ori       $a3, $a3, 2
/* 3F8B20 E0110730 AD2B0028 */  sw        $t3, 0x28($t1)
/* 3F8B24 E0110734 00021600 */  sll       $v0, $v0, 0x18
/* 3F8B28 E0110738 46001082 */  mul.s     $f2, $f2, $f0
/* 3F8B2C E011073C 00000000 */  nop
/* 3F8B30 E0110740 00031C00 */  sll       $v1, $v1, 0x10
/* 3F8B34 E0110744 00431025 */  or        $v0, $v0, $v1
/* 3F8B38 E0110748 00042200 */  sll       $a0, $a0, 8
/* 3F8B3C E011074C 00441025 */  or        $v0, $v0, $a0
/* 3F8B40 E0110750 4600118D */  trunc.w.s $f6, $f2
/* 3F8B44 E0110754 440A3000 */  mfc1      $t2, $f6
/* 3F8B48 E0110758 00000000 */  nop
/* 3F8B4C E011075C 314300FF */  andi      $v1, $t2, 0xff
/* 3F8B50 E0110760 00431025 */  or        $v0, $v0, $v1
/* 3F8B54 E0110764 AD220024 */  sw        $v0, 0x24($t1)
/* 3F8B58 E0110768 3C03E011 */  lui       $v1, %hi(D_E01108B0)
/* 3F8B5C E011076C 8C6308B0 */  lw        $v1, %lo(D_E01108B0)($v1)
/* 3F8B60 E0110770 25220030 */  addiu     $v0, $t1, 0x30
/* 3F8B64 E0110774 AEA20000 */  sw        $v0, ($s5)
/* 3F8B68 E0110778 25220038 */  addiu     $v0, $t1, 0x38
/* 3F8B6C E011077C AD23002C */  sw        $v1, 0x2c($t1)
/* 3F8B70 E0110780 AEA20000 */  sw        $v0, ($s5)
/* 3F8B74 E0110784 24020040 */  addiu     $v0, $zero, 0x40
/* 3F8B78 E0110788 AD220034 */  sw        $v0, 0x34($t1)
/* 3F8B7C E011078C 24020001 */  addiu     $v0, $zero, 1
/* 3F8B80 E0110790 16620030 */  bne       $s3, $v0, .LE0110854
/* 3F8B84 E0110794 AD270030 */   sw       $a3, 0x30($t1)
/* 3F8B88 E0110798 C6800044 */  lwc1      $f0, 0x44($s4)
/* 3F8B8C E011079C 46040002 */  mul.s     $f0, $f0, $f4
/* 3F8B90 E01107A0 00000000 */  nop
/* 3F8B94 E01107A4 24020003 */  addiu     $v0, $zero, 3
/* 3F8B98 E01107A8 4600018D */  trunc.w.s $f6, $f0
/* 3F8B9C E01107AC 44033000 */  mfc1      $v1, $f6
/* 3F8BA0 E01107B0 00000000 */  nop
/* 3F8BA4 E01107B4 14620028 */  bne       $v1, $v0, .LE0110858
/* 3F8BA8 E01107B8 3C05D838 */   lui      $a1, 0xd838
/* 3F8BAC E01107BC 3C088080 */  lui       $t0, 0x8080
/* 3F8BB0 E01107C0 35088081 */  ori       $t0, $t0, 0x8081
/* 3F8BB4 E01107C4 3C07FCFF */  lui       $a3, 0xfcff
/* 3F8BB8 E01107C8 34E7C7FF */  ori       $a3, $a3, 0xc7ff
/* 3F8BBC E01107CC 3C04FF8D */  lui       $a0, 0xff8d
/* 3F8BC0 E01107D0 3484FEFF */  ori       $a0, $a0, 0xfeff
/* 3F8BC4 E01107D4 25220040 */  addiu     $v0, $t1, 0x40
/* 3F8BC8 E01107D8 AEA20000 */  sw        $v0, ($s5)
/* 3F8BCC E01107DC AD2C0038 */  sw        $t4, 0x38($t1)
/* 3F8BD0 E01107E0 9283001B */  lbu       $v1, 0x1b($s4)
/* 3F8BD4 E01107E4 9285001F */  lbu       $a1, 0x1f($s4)
/* 3F8BD8 E01107E8 92860023 */  lbu       $a2, 0x23($s4)
/* 3F8BDC E01107EC 25220048 */  addiu     $v0, $t1, 0x48
/* 3F8BE0 E01107F0 AEA20000 */  sw        $v0, ($s5)
/* 3F8BE4 E01107F4 25220050 */  addiu     $v0, $t1, 0x50
/* 3F8BE8 E01107F8 02CA0018 */  mult      $s6, $t2
/* 3F8BEC E01107FC AD270040 */  sw        $a3, 0x40($t1)
/* 3F8BF0 E0110800 AD240044 */  sw        $a0, 0x44($t1)
/* 3F8BF4 E0110804 AEA20000 */  sw        $v0, ($s5)
/* 3F8BF8 E0110808 3C020900 */  lui       $v0, 0x900
/* 3F8BFC E011080C 24421168 */  addiu     $v0, $v0, 0x1168
/* 3F8C00 E0110810 AD2B0048 */  sw        $t3, 0x48($t1)
/* 3F8C04 E0110814 00002012 */  mflo      $a0
/* 3F8C08 E0110818 AD22004C */  sw        $v0, 0x4c($t1)
/* 3F8C0C E011081C 00031E00 */  sll       $v1, $v1, 0x18
/* 3F8C10 E0110820 00880018 */  mult      $a0, $t0
/* 3F8C14 E0110824 00052C00 */  sll       $a1, $a1, 0x10
/* 3F8C18 E0110828 00651825 */  or        $v1, $v1, $a1
/* 3F8C1C E011082C 00063200 */  sll       $a2, $a2, 8
/* 3F8C20 E0110830 00661825 */  or        $v1, $v1, $a2
/* 3F8C24 E0110834 00001010 */  mfhi      $v0
/* 3F8C28 E0110838 00441021 */  addu      $v0, $v0, $a0
/* 3F8C2C E011083C 000211C3 */  sra       $v0, $v0, 7
/* 3F8C30 E0110840 000427C3 */  sra       $a0, $a0, 0x1f
/* 3F8C34 E0110844 00441023 */  subu      $v0, $v0, $a0
/* 3F8C38 E0110848 304200FF */  andi      $v0, $v0, 0xff
/* 3F8C3C E011084C 00621825 */  or        $v1, $v1, $v0
/* 3F8C40 E0110850 AD23003C */  sw        $v1, 0x3c($t1)
.LE0110854:
/* 3F8C44 E0110854 3C05D838 */  lui       $a1, 0xd838
.LE0110858:
/* 3F8C48 E0110858 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 3F8C4C E011085C 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 3F8C50 E0110860 8C620000 */  lw        $v0, ($v1)
/* 3F8C54 E0110864 34A50002 */  ori       $a1, $a1, 2
/* 3F8C58 E0110868 0040202D */  daddu     $a0, $v0, $zero
/* 3F8C5C E011086C 24420008 */  addiu     $v0, $v0, 8
/* 3F8C60 E0110870 AC620000 */  sw        $v0, ($v1)
/* 3F8C64 E0110874 24020040 */  addiu     $v0, $zero, 0x40
/* 3F8C68 E0110878 AC850000 */  sw        $a1, ($a0)
/* 3F8C6C E011087C AC820004 */  sw        $v0, 4($a0)
/* 3F8C70 E0110880 8FBF00BC */  lw        $ra, 0xbc($sp)
/* 3F8C74 E0110884 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 3F8C78 E0110888 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 3F8C7C E011088C 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 3F8C80 E0110890 8FB300AC */  lw        $s3, 0xac($sp)
/* 3F8C84 E0110894 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 3F8C88 E0110898 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 3F8C8C E011089C 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 3F8C90 E01108A0 D7B400C0 */  ldc1      $f20, 0xc0($sp)
/* 3F8C94 E01108A4 03E00008 */  jr        $ra
/* 3F8C98 E01108A8 27BD00C8 */   addiu    $sp, $sp, 0xc8
/* 3F8C9C E01108AC 00000000 */  nop
