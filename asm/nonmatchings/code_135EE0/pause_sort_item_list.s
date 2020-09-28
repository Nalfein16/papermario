.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_sort_item_list
/* 137D8C 80244A4C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 137D90 80244A50 AFB60028 */  sw        $s6, 0x28($sp)
/* 137D94 80244A54 0080B02D */  daddu     $s6, $a0, $zero
/* 137D98 80244A58 AFB7002C */  sw        $s7, 0x2c($sp)
/* 137D9C 80244A5C 00C0B82D */  daddu     $s7, $a2, $zero
/* 137DA0 80244A60 28A20002 */  slti      $v0, $a1, 2
/* 137DA4 80244A64 AFBF0030 */  sw        $ra, 0x30($sp)
/* 137DA8 80244A68 AFB50024 */  sw        $s5, 0x24($sp)
/* 137DAC 80244A6C AFB40020 */  sw        $s4, 0x20($sp)
/* 137DB0 80244A70 AFB3001C */  sw        $s3, 0x1c($sp)
/* 137DB4 80244A74 AFB20018 */  sw        $s2, 0x18($sp)
/* 137DB8 80244A78 AFB10014 */  sw        $s1, 0x14($sp)
/* 137DBC 80244A7C 14400038 */  bnez      $v0, .L80244B60
/* 137DC0 80244A80 AFB00010 */   sw       $s0, 0x10($sp)
/* 137DC4 80244A84 24020002 */  addiu     $v0, $zero, 2
/* 137DC8 80244A88 14A2000A */  bne       $a1, $v0, .L80244AB4
/* 137DCC 80244A8C 24140001 */   addiu    $s4, $zero, 1
/* 137DD0 80244A90 02E0F809 */  jalr      $s7
/* 137DD4 80244A94 02C22821 */   addu     $a1, $s6, $v0
/* 137DD8 80244A98 18400031 */  blez      $v0, .L80244B60
/* 137DDC 80244A9C 00000000 */   nop      
/* 137DE0 80244AA0 96C20002 */  lhu       $v0, 2($s6)
/* 137DE4 80244AA4 96C30000 */  lhu       $v1, ($s6)
/* 137DE8 80244AA8 A6C20000 */  sh        $v0, ($s6)
/* 137DEC 80244AAC 080912D8 */  j         .L80244B60
/* 137DF0 80244AB0 A6C30002 */   sh       $v1, 2($s6)
.L80244AB4:
/* 137DF4 80244AB4 0285102B */  sltu      $v0, $s4, $a1
/* 137DF8 80244AB8 50400007 */  beql      $v0, $zero, .L80244AD8
/* 137DFC 80244ABC 0014A042 */   srl      $s4, $s4, 1
/* 137E00 80244AC0 00141040 */  sll       $v0, $s4, 1
.L80244AC4:
/* 137E04 80244AC4 24540001 */  addiu     $s4, $v0, 1
/* 137E08 80244AC8 0285102B */  sltu      $v0, $s4, $a1
/* 137E0C 80244ACC 1440FFFD */  bnez      $v0, .L80244AC4
/* 137E10 80244AD0 00141040 */   sll      $v0, $s4, 1
/* 137E14 80244AD4 0014A042 */  srl       $s4, $s4, 1
.L80244AD8:
/* 137E18 80244AD8 00051040 */  sll       $v0, $a1, 1
/* 137E1C 80244ADC 12800020 */  beqz      $s4, .L80244B60
/* 137E20 80244AE0 02C2A821 */   addu     $s5, $s6, $v0
.L80244AE4:
/* 137E24 80244AE4 00141840 */  sll       $v1, $s4, 1
/* 137E28 80244AE8 02C39021 */  addu      $s2, $s6, $v1
/* 137E2C 80244AEC 0255102B */  sltu      $v0, $s2, $s5
/* 137E30 80244AF0 10400019 */  beqz      $v0, .L80244B58
/* 137E34 80244AF4 00141042 */   srl      $v0, $s4, 1
/* 137E38 80244AF8 0060982D */  daddu     $s3, $v1, $zero
/* 137E3C 80244AFC 02538023 */  subu      $s0, $s2, $s3
.L80244B00:
/* 137E40 80244B00 080912CD */  j         .L80244B34
/* 137E44 80244B04 0216102B */   sltu     $v0, $s0, $s6
.L80244B08:
/* 137E48 80244B08 02138821 */  addu      $s1, $s0, $s3
/* 137E4C 80244B0C 02E0F809 */  jalr      $s7
/* 137E50 80244B10 0220282D */   daddu    $a1, $s1, $zero
/* 137E54 80244B14 5840000C */  blezl     $v0, .L80244B48
/* 137E58 80244B18 26520002 */   addiu    $s2, $s2, 2
/* 137E5C 80244B1C 96220000 */  lhu       $v0, ($s1)
/* 137E60 80244B20 96030000 */  lhu       $v1, ($s0)
/* 137E64 80244B24 A6020000 */  sh        $v0, ($s0)
/* 137E68 80244B28 02138023 */  subu      $s0, $s0, $s3
/* 137E6C 80244B2C 0216102B */  sltu      $v0, $s0, $s6
/* 137E70 80244B30 A6230000 */  sh        $v1, ($s1)
.L80244B34:
/* 137E74 80244B34 14400003 */  bnez      $v0, .L80244B44
/* 137E78 80244B38 0215102B */   sltu     $v0, $s0, $s5
/* 137E7C 80244B3C 1440FFF2 */  bnez      $v0, .L80244B08
/* 137E80 80244B40 0200202D */   daddu    $a0, $s0, $zero
.L80244B44:
/* 137E84 80244B44 26520002 */  addiu     $s2, $s2, 2
.L80244B48:
/* 137E88 80244B48 0255102B */  sltu      $v0, $s2, $s5
/* 137E8C 80244B4C 5440FFEC */  bnel      $v0, $zero, .L80244B00
/* 137E90 80244B50 02538023 */   subu     $s0, $s2, $s3
/* 137E94 80244B54 00141042 */  srl       $v0, $s4, 1
.L80244B58:
/* 137E98 80244B58 1440FFE2 */  bnez      $v0, .L80244AE4
/* 137E9C 80244B5C 0040A02D */   daddu    $s4, $v0, $zero
.L80244B60:
/* 137EA0 80244B60 8FBF0030 */  lw        $ra, 0x30($sp)
/* 137EA4 80244B64 8FB7002C */  lw        $s7, 0x2c($sp)
/* 137EA8 80244B68 8FB60028 */  lw        $s6, 0x28($sp)
/* 137EAC 80244B6C 8FB50024 */  lw        $s5, 0x24($sp)
/* 137EB0 80244B70 8FB40020 */  lw        $s4, 0x20($sp)
/* 137EB4 80244B74 8FB3001C */  lw        $s3, 0x1c($sp)
/* 137EB8 80244B78 8FB20018 */  lw        $s2, 0x18($sp)
/* 137EBC 80244B7C 8FB10014 */  lw        $s1, 0x14($sp)
/* 137EC0 80244B80 8FB00010 */  lw        $s0, 0x10($sp)
/* 137EC4 80244B84 03E00008 */  jr        $ra
/* 137EC8 80244B88 27BD0038 */   addiu    $sp, $sp, 0x38
/* 137ECC 80244B8C 00000000 */  nop       
