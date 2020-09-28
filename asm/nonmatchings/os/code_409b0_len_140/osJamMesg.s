.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osJamMesg
/* 409B0 800655B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 409B4 800655B4 AFB00010 */  sw        $s0, 0x10($sp)
/* 409B8 800655B8 00808021 */  addu      $s0, $a0, $zero
/* 409BC 800655BC AFB50024 */  sw        $s5, 0x24($sp)
/* 409C0 800655C0 00A0A821 */  addu      $s5, $a1, $zero
/* 409C4 800655C4 AFB20018 */  sw        $s2, 0x18($sp)
/* 409C8 800655C8 00C09021 */  addu      $s2, $a2, $zero
/* 409CC 800655CC AFBF0028 */  sw        $ra, 0x28($sp)
/* 409D0 800655D0 AFB40020 */  sw        $s4, 0x20($sp)
/* 409D4 800655D4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 409D8 800655D8 0C01ACD8 */  jal       __osDisableInt
/* 409DC 800655DC AFB10014 */   sw       $s1, 0x14($sp)
/* 409E0 800655E0 8E030008 */  lw        $v1, 8($s0)
/* 409E4 800655E4 8E040010 */  lw        $a0, 0x10($s0)
/* 409E8 800655E8 0064182A */  slt       $v1, $v1, $a0
/* 409EC 800655EC 14600012 */  bnez      $v1, .L80065638
/* 409F0 800655F0 00408821 */   addu     $s1, $v0, $zero
/* 409F4 800655F4 24140001 */  addiu     $s4, $zero, 1
/* 409F8 800655F8 24130008 */  addiu     $s3, $zero, 8
.L800655FC:
/* 409FC 800655FC 12540005 */  beq       $s2, $s4, .L80065614
/* 40A00 80065600 26040004 */   addiu    $a0, $s0, 4
/* 40A04 80065604 0C01ACF4 */  jal       __osRestoreInt
/* 40A08 80065608 02202021 */   addu     $a0, $s1, $zero
/* 40A0C 8006560C 080195B0 */  j         .L800656C0
/* 40A10 80065610 2402FFFF */   addiu    $v0, $zero, -1
.L80065614:
/* 40A14 80065614 3C028009 */  lui       $v0, 0x8009
/* 40A18 80065618 8C424660 */  lw        $v0, 0x4660($v0)
/* 40A1C 8006561C 0C01AC1B */  jal       osEnqueueAndYield
/* 40A20 80065620 A4530010 */   sh       $s3, 0x10($v0)
/* 40A24 80065624 8E020008 */  lw        $v0, 8($s0)
/* 40A28 80065628 8E030010 */  lw        $v1, 0x10($s0)
/* 40A2C 8006562C 0043102A */  slt       $v0, $v0, $v1
/* 40A30 80065630 1040FFF2 */  beqz      $v0, .L800655FC
/* 40A34 80065634 00000000 */   nop      
.L80065638:
/* 40A38 80065638 8E02000C */  lw        $v0, 0xc($s0)
/* 40A3C 8006563C 8E030010 */  lw        $v1, 0x10($s0)
/* 40A40 80065640 00431021 */  addu      $v0, $v0, $v1
/* 40A44 80065644 2442FFFF */  addiu     $v0, $v0, -1
/* 40A48 80065648 0043001A */  div       $zero, $v0, $v1
/* 40A4C 8006564C 14600002 */  bnez      $v1, .L80065658
/* 40A50 80065650 00000000 */   nop      
/* 40A54 80065654 0007000D */  break     7
.L80065658:
/* 40A58 80065658 2401FFFF */   addiu    $at, $zero, -1
/* 40A5C 8006565C 14610004 */  bne       $v1, $at, .L80065670
/* 40A60 80065660 3C018000 */   lui      $at, 0x8000
/* 40A64 80065664 14410002 */  bne       $v0, $at, .L80065670
/* 40A68 80065668 00000000 */   nop      
/* 40A6C 8006566C 0006000D */  break     6
.L80065670:
/* 40A70 80065670 00001810 */   mfhi     $v1
/* 40A74 80065674 8E020014 */  lw        $v0, 0x14($s0)
/* 40A78 80065678 AE03000C */  sw        $v1, 0xc($s0)
/* 40A7C 8006567C 00031880 */  sll       $v1, $v1, 2
/* 40A80 80065680 00621821 */  addu      $v1, $v1, $v0
/* 40A84 80065684 AC750000 */  sw        $s5, ($v1)
/* 40A88 80065688 8E020008 */  lw        $v0, 8($s0)
/* 40A8C 8006568C 8E030000 */  lw        $v1, ($s0)
/* 40A90 80065690 24420001 */  addiu     $v0, $v0, 1
/* 40A94 80065694 AE020008 */  sw        $v0, 8($s0)
/* 40A98 80065698 8C620000 */  lw        $v0, ($v1)
/* 40A9C 8006569C 10400005 */  beqz      $v0, .L800656B4
/* 40AA0 800656A0 00000000 */   nop      
/* 40AA4 800656A4 0C01AC6F */  jal       osPopThread
/* 40AA8 800656A8 02002021 */   addu     $a0, $s0, $zero
/* 40AAC 800656AC 0C019808 */  jal       osStartThread
/* 40AB0 800656B0 00402021 */   addu     $a0, $v0, $zero
.L800656B4:
/* 40AB4 800656B4 0C01ACF4 */  jal       __osRestoreInt
/* 40AB8 800656B8 02202021 */   addu     $a0, $s1, $zero
/* 40ABC 800656BC 00001021 */  addu      $v0, $zero, $zero
.L800656C0:
/* 40AC0 800656C0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 40AC4 800656C4 8FB50024 */  lw        $s5, 0x24($sp)
/* 40AC8 800656C8 8FB40020 */  lw        $s4, 0x20($sp)
/* 40ACC 800656CC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 40AD0 800656D0 8FB20018 */  lw        $s2, 0x18($sp)
/* 40AD4 800656D4 8FB10014 */  lw        $s1, 0x14($sp)
/* 40AD8 800656D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 40ADC 800656DC 03E00008 */  jr        $ra
/* 40AE0 800656E0 27BD0030 */   addiu    $sp, $sp, 0x30
/* 40AE4 800656E4 00000000 */  nop       
/* 40AE8 800656E8 00000000 */  nop       
/* 40AEC 800656EC 00000000 */  nop       
