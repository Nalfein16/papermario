.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024266C_8547DC
/* 8547DC 8024266C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8547E0 80242670 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8547E4 80242674 8C82000C */  lw        $v0, 0xc($a0)
/* 8547E8 80242678 0C0B1EAF */  jal       evt_get_variable
/* 8547EC 8024267C 8C450000 */   lw       $a1, ($v0)
/* 8547F0 80242680 0040182D */  daddu     $v1, $v0, $zero
/* 8547F4 80242684 10600012 */  beqz      $v1, .L802426D0
/* 8547F8 80242688 0000202D */   daddu    $a0, $zero, $zero
/* 8547FC 8024268C 8C620000 */  lw        $v0, ($v1)
/* 854800 80242690 5040000A */  beql      $v0, $zero, .L802426BC
/* 854804 80242694 00041080 */   sll      $v0, $a0, 2
/* 854808 80242698 3C058025 */  lui       $a1, %hi(D_80252A00)
/* 85480C 8024269C 24A52A00 */  addiu     $a1, $a1, %lo(D_80252A00)
.L802426A0:
/* 854810 802426A0 24630004 */  addiu     $v1, $v1, 4
/* 854814 802426A4 24840001 */  addiu     $a0, $a0, 1
/* 854818 802426A8 ACA20000 */  sw        $v0, ($a1)
/* 85481C 802426AC 8C620000 */  lw        $v0, ($v1)
/* 854820 802426B0 1440FFFB */  bnez      $v0, .L802426A0
/* 854824 802426B4 24A50004 */   addiu    $a1, $a1, 4
/* 854828 802426B8 00041080 */  sll       $v0, $a0, 2
.L802426BC:
/* 85482C 802426BC 3C018025 */  lui       $at, %hi(D_80252A00)
/* 854830 802426C0 00220821 */  addu      $at, $at, $v0
/* 854834 802426C4 AC202A00 */  sw        $zero, %lo(D_80252A00)($at)
/* 854838 802426C8 080909BE */  j         .L802426F8
/* 85483C 802426CC 00000000 */   nop
.L802426D0:
/* 854840 802426D0 3C038025 */  lui       $v1, %hi(D_80252A00)
/* 854844 802426D4 24632A00 */  addiu     $v1, $v1, %lo(D_80252A00)
/* 854848 802426D8 0060282D */  daddu     $a1, $v1, $zero
.L802426DC:
/* 85484C 802426DC 24820010 */  addiu     $v0, $a0, 0x10
/* 854850 802426E0 AC620000 */  sw        $v0, ($v1)
/* 854854 802426E4 24630004 */  addiu     $v1, $v1, 4
/* 854858 802426E8 24840001 */  addiu     $a0, $a0, 1
/* 85485C 802426EC 28820070 */  slti      $v0, $a0, 0x70
/* 854860 802426F0 1440FFFA */  bnez      $v0, .L802426DC
/* 854864 802426F4 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L802426F8:
/* 854868 802426F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 85486C 802426FC 24020002 */  addiu     $v0, $zero, 2
/* 854870 80242700 03E00008 */  jr        $ra
/* 854874 80242704 27BD0018 */   addiu    $sp, $sp, 0x18
