.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel viMgrMain
/* 42010 80066C10 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 42014 80066C14 AFB00018 */  sw        $s0, 0x18($sp)
/* 42018 80066C18 00808021 */  addu      $s0, $a0, $zero
/* 4201C 80066C1C AFBF002C */  sw        $ra, 0x2c($sp)
/* 42020 80066C20 AFB40028 */  sw        $s4, 0x28($sp)
/* 42024 80066C24 AFB30024 */  sw        $s3, 0x24($sp)
/* 42028 80066C28 AFB20020 */  sw        $s2, 0x20($sp)
/* 4202C 80066C2C AFB1001C */  sw        $s1, 0x1c($sp)
/* 42030 80066C30 0C01B2E8 */  jal       __osViGetCurrentContext
/* 42034 80066C34 AFA00010 */   sw       $zero, 0x10($sp)
/* 42038 80066C38 94420002 */  lhu       $v0, 2($v0)
/* 4203C 80066C3C 3C01800B */  lui       $at, %hi(D_800AF910)
/* 42040 80066C40 A422F910 */  sh        $v0, %lo(D_800AF910)($at)
/* 42044 80066C44 14400004 */  bnez      $v0, .L80066C58
/* 42048 80066C48 00008821 */   addu     $s1, $zero, $zero
/* 4204C 80066C4C 24020001 */  addiu     $v0, $zero, 1
/* 42050 80066C50 3C01800B */  lui       $at, %hi(D_800AF910)
/* 42054 80066C54 A422F910 */  sh        $v0, %lo(D_800AF910)($at)
.L80066C58:
/* 42058 80066C58 02009021 */  addu      $s2, $s0, $zero
/* 4205C 80066C5C 2414000D */  addiu     $s4, $zero, 0xd
/* 42060 80066C60 2413000E */  addiu     $s3, $zero, 0xe
.L80066C64:
/* 42064 80066C64 8E44000C */  lw        $a0, 0xc($s2)
/* 42068 80066C68 27A50010 */  addiu     $a1, $sp, 0x10
/* 4206C 80066C6C 0C0195BC */  jal       osRecvMesg
/* 42070 80066C70 24060001 */   addiu    $a2, $zero, 1
/* 42074 80066C74 8FA20010 */  lw        $v0, 0x10($sp)
/* 42078 80066C78 94420000 */  lhu       $v0, ($v0)
/* 4207C 80066C7C 10540005 */  beq       $v0, $s4, .L80066C94
/* 42080 80066C80 00000000 */   nop
/* 42084 80066C84 1053003C */  beq       $v0, $s3, .L80066D78
/* 42088 80066C88 00000000 */   nop
/* 4208C 80066C8C 08019B19 */  j         .L80066C64
/* 42090 80066C90 00000000 */   nop
.L80066C94:
/* 42094 80066C94 0C019C1C */  jal       __osViSwapContext
/* 42098 80066C98 00000000 */   nop
/* 4209C 80066C9C 3C02800B */  lui       $v0, %hi(D_800AF910)
/* 420A0 80066CA0 9442F910 */  lhu       $v0, %lo(D_800AF910)($v0)
/* 420A4 80066CA4 2442FFFF */  addiu     $v0, $v0, -1
/* 420A8 80066CA8 3C01800B */  lui       $at, %hi(D_800AF910)
/* 420AC 80066CAC A422F910 */  sh        $v0, %lo(D_800AF910)($at)
/* 420B0 80066CB0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 420B4 80066CB4 1440000C */  bnez      $v0, .L80066CE8
/* 420B8 80066CB8 00000000 */   nop
/* 420BC 80066CBC 0C01B2E8 */  jal       __osViGetCurrentContext
/* 420C0 80066CC0 00000000 */   nop
/* 420C4 80066CC4 8C440010 */  lw        $a0, 0x10($v0)
/* 420C8 80066CC8 10800004 */  beqz      $a0, .L80066CDC
/* 420CC 80066CCC 00408021 */   addu     $s0, $v0, $zero
/* 420D0 80066CD0 8E050014 */  lw        $a1, 0x14($s0)
/* 420D4 80066CD4 0C019608 */  jal       osSendMesg
/* 420D8 80066CD8 00003021 */   addu     $a2, $zero, $zero
.L80066CDC:
/* 420DC 80066CDC 96020002 */  lhu       $v0, 2($s0)
/* 420E0 80066CE0 3C01800B */  lui       $at, %hi(D_800AF910)
/* 420E4 80066CE4 A422F910 */  sh        $v0, %lo(D_800AF910)($at)
.L80066CE8:
/* 420E8 80066CE8 3C02800A */  lui       $v0, %hi(__osViIntrCount)
/* 420EC 80066CEC 8C42A5E4 */  lw        $v0, %lo(__osViIntrCount)($v0)
/* 420F0 80066CF0 24420001 */  addiu     $v0, $v0, 1
/* 420F4 80066CF4 3C01800A */  lui       $at, %hi(__osViIntrCount)
/* 420F8 80066CF8 1220000A */  beqz      $s1, .L80066D24
/* 420FC 80066CFC AC22A5E4 */   sw       $v0, %lo(__osViIntrCount)($at)
/* 42100 80066D00 0C019680 */  jal       osGetCount
/* 42104 80066D04 00008821 */   addu     $s1, $zero, $zero
/* 42108 80066D08 00408021 */  addu      $s0, $v0, $zero
/* 4210C 80066D0C 02001821 */  addu      $v1, $s0, $zero
/* 42110 80066D10 00001021 */  addu      $v0, $zero, $zero
/* 42114 80066D14 3C01800A */  lui       $at, %hi(__osCurrentTime)
/* 42118 80066D18 AC22A608 */  sw        $v0, %lo(__osCurrentTime)($at)
/* 4211C 80066D1C 3C01800A */  lui       $at, %hi(D_8009A60C)
/* 42120 80066D20 AC23A60C */  sw        $v1, %lo(D_8009A60C)($at)
.L80066D24:
/* 42124 80066D24 3C10800A */  lui       $s0, %hi(__osBaseCounter)
/* 42128 80066D28 0C019680 */  jal       osGetCount
/* 4212C 80066D2C 8E10A5C8 */   lw       $s0, %lo(__osBaseCounter)($s0)
/* 42130 80066D30 3C01800A */  lui       $at, %hi(__osBaseCounter)
/* 42134 80066D34 AC22A5C8 */  sw        $v0, %lo(__osBaseCounter)($at)
/* 42138 80066D38 00508023 */  subu      $s0, $v0, $s0
/* 4213C 80066D3C 3C02800A */  lui       $v0, %hi(__osCurrentTime)
/* 42140 80066D40 8C42A608 */  lw        $v0, %lo(__osCurrentTime)($v0)
/* 42144 80066D44 3C03800A */  lui       $v1, %hi(D_8009A60C)
/* 42148 80066D48 8C63A60C */  lw        $v1, %lo(D_8009A60C)($v1)
/* 4214C 80066D4C 02002821 */  addu      $a1, $s0, $zero
/* 42150 80066D50 00002021 */  addu      $a0, $zero, $zero
/* 42154 80066D54 00651821 */  addu      $v1, $v1, $a1
/* 42158 80066D58 0065302B */  sltu      $a2, $v1, $a1
/* 4215C 80066D5C 00441021 */  addu      $v0, $v0, $a0
/* 42160 80066D60 00461021 */  addu      $v0, $v0, $a2
/* 42164 80066D64 3C01800A */  lui       $at, %hi(__osCurrentTime)
/* 42168 80066D68 AC22A608 */  sw        $v0, %lo(__osCurrentTime)($at)
/* 4216C 80066D6C 3C01800A */  lui       $at, %hi(D_8009A60C)
/* 42170 80066D70 08019B19 */  j         .L80066C64
/* 42174 80066D74 AC23A60C */   sw       $v1, %lo(D_8009A60C)($at)
.L80066D78:
/* 42178 80066D78 0C019935 */  jal       __osTimerInterrupt
/* 4217C 80066D7C 00000000 */   nop
/* 42180 80066D80 08019B19 */  j         .L80066C64
/* 42184 80066D84 00000000 */   nop
/* 42188 80066D88 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4218C 80066D8C 8FB40028 */  lw        $s4, 0x28($sp)
/* 42190 80066D90 8FB30024 */  lw        $s3, 0x24($sp)
/* 42194 80066D94 8FB20020 */  lw        $s2, 0x20($sp)
/* 42198 80066D98 8FB1001C */  lw        $s1, 0x1c($sp)
/* 4219C 80066D9C 8FB00018 */  lw        $s0, 0x18($sp)
/* 421A0 80066DA0 03E00008 */  jr        $ra
/* 421A4 80066DA4 27BD0030 */   addiu    $sp, $sp, 0x30
/* 421A8 80066DA8 00000000 */  nop
/* 421AC 80066DAC 00000000 */  nop
