.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242FE0
/* 1718C0 80242FE0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 1718C4 80242FE4 AFB60028 */  sw        $s6, 0x28($sp)
/* 1718C8 80242FE8 3C16800E */  lui       $s6, %hi(gBattleStatus)
/* 1718CC 80242FEC 26D6C070 */  addiu     $s6, $s6, %lo(gBattleStatus)
/* 1718D0 80242FF0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 1718D4 80242FF4 AFB50024 */  sw        $s5, 0x24($sp)
/* 1718D8 80242FF8 AFB40020 */  sw        $s4, 0x20($sp)
/* 1718DC 80242FFC AFB3001C */  sw        $s3, 0x1c($sp)
/* 1718E0 80243000 AFB20018 */  sw        $s2, 0x18($sp)
/* 1718E4 80243004 AFB10014 */  sw        $s1, 0x14($sp)
/* 1718E8 80243008 AFB00010 */  sw        $s0, 0x10($sp)
/* 1718EC 8024300C F7B80040 */  sdc1      $f24, 0x40($sp)
/* 1718F0 80243010 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 1718F4 80243014 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 1718F8 80243018 8ED500D8 */  lw        $s5, 0xd8($s6)
/* 1718FC 8024301C 3C02800E */  lui       $v0, %hi(gBattleState2)
/* 171900 80243020 8C42C4DC */  lw        $v0, %lo(gBattleState2)($v0)
/* 171904 80243024 1440002D */  bnez      $v0, .L802430DC
/* 171908 80243028 8ED200DC */   lw       $s2, 0xdc($s6)
/* 17190C 8024302C 8EC30004 */  lw        $v1, 4($s6)
/* 171910 80243030 30620002 */  andi      $v0, $v1, 2
/* 171914 80243034 10400227 */  beqz      $v0, .L802438D4
/* 171918 80243038 2404000A */   addiu    $a0, $zero, 0xa
/* 17191C 8024303C 1240000A */  beqz      $s2, .L80243068
/* 171920 80243040 30620004 */   andi     $v0, $v1, 4
/* 171924 80243044 14400009 */  bnez      $v0, .L8024306C
/* 171928 80243048 3C03F7FF */   lui      $v1, 0xf7ff
/* 17192C 8024304C 8E420000 */  lw        $v0, ($s2)
/* 171930 80243050 3C030020 */  lui       $v1, 0x20
/* 171934 80243054 00431024 */  and       $v0, $v0, $v1
/* 171938 80243058 14400004 */  bnez      $v0, .L8024306C
/* 17193C 8024305C 3C03F7FF */   lui      $v1, 0xf7ff
/* 171940 80243060 08090E35 */  j         .L802438D4
/* 171944 80243064 2404000B */   addiu    $a0, $zero, 0xb
.L80243068:
/* 171948 80243068 3C03F7FF */  lui       $v1, 0xf7ff
.L8024306C:
/* 17194C 8024306C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 171950 80243070 8EA20000 */  lw        $v0, ($s5)
/* 171954 80243074 3C040400 */  lui       $a0, 0x400
/* 171958 80243078 00431024 */  and       $v0, $v0, $v1
/* 17195C 8024307C 00441025 */  or        $v0, $v0, $a0
/* 171960 80243080 12400005 */  beqz      $s2, .L80243098
/* 171964 80243084 AEA20000 */   sw       $v0, ($s5)
/* 171968 80243088 8E420000 */  lw        $v0, ($s2)
/* 17196C 8024308C 00431024 */  and       $v0, $v0, $v1
/* 171970 80243090 00441025 */  or        $v0, $v0, $a0
/* 171974 80243094 AE420000 */  sw        $v0, ($s2)
.L80243098:
/* 171978 80243098 24020001 */  addiu     $v0, $zero, 1
/* 17197C 8024309C 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 171980 802430A0 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 171984 802430A4 3C01800E */  lui       $at, %hi(gBattleState2)
/* 171988 802430A8 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
/* 17198C 802430AC 8C820004 */  lw        $v0, 4($a0)
/* 171990 802430B0 2403FFFD */  addiu     $v1, $zero, -3
/* 171994 802430B4 3C01802A */  lui       $at, %hi(D_8029F258)
/* 171998 802430B8 AC20F258 */  sw        $zero, %lo(D_8029F258)($at)
/* 17199C 802430BC 00431024 */  and       $v0, $v0, $v1
/* 1719A0 802430C0 2403FFFB */  addiu     $v1, $zero, -5
/* 1719A4 802430C4 00431024 */  and       $v0, $v0, $v1
/* 1719A8 802430C8 2403FFF7 */  addiu     $v1, $zero, -9
/* 1719AC 802430CC 00431024 */  and       $v0, $v0, $v1
/* 1719B0 802430D0 2403FFEF */  addiu     $v1, $zero, -0x11
/* 1719B4 802430D4 00431024 */  and       $v0, $v0, $v1
/* 1719B8 802430D8 AC820004 */  sw        $v0, 4($a0)
.L802430DC:
/* 1719BC 802430DC 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 1719C0 802430E0 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 1719C4 802430E4 24020001 */  addiu     $v0, $zero, 1
/* 1719C8 802430E8 14620091 */  bne       $v1, $v0, .L80243330
/* 1719CC 802430EC 24020002 */   addiu    $v0, $zero, 2
/* 1719D0 802430F0 0000A02D */  daddu     $s4, $zero, $zero
/* 1719D4 802430F4 0280882D */  daddu     $s1, $s4, $zero
/* 1719D8 802430F8 02C0982D */  daddu     $s3, $s6, $zero
.L802430FC:
/* 1719DC 802430FC 8E7000E0 */  lw        $s0, 0xe0($s3)
/* 1719E0 80243100 5200000B */  beql      $s0, $zero, .L80243130
/* 1719E4 80243104 26310001 */   addiu    $s1, $s1, 1
/* 1719E8 80243108 8E0201D8 */  lw        $v0, 0x1d8($s0)
/* 1719EC 8024310C 50400008 */  beql      $v0, $zero, .L80243130
/* 1719F0 80243110 26310001 */   addiu    $s1, $s1, 1
/* 1719F4 80243114 8E0401E8 */  lw        $a0, 0x1e8($s0)
/* 1719F8 80243118 0C0B1059 */  jal       does_script_exist
/* 1719FC 8024311C 00000000 */   nop
/* 171A00 80243120 50400002 */  beql      $v0, $zero, .L8024312C
/* 171A04 80243124 AE0001D8 */   sw       $zero, 0x1d8($s0)
/* 171A08 80243128 24140001 */  addiu     $s4, $zero, 1
.L8024312C:
/* 171A0C 8024312C 26310001 */  addiu     $s1, $s1, 1
.L80243130:
/* 171A10 80243130 2A220018 */  slti      $v0, $s1, 0x18
/* 171A14 80243134 1440FFF1 */  bnez      $v0, .L802430FC
/* 171A18 80243138 26730004 */   addiu    $s3, $s3, 4
/* 171A1C 8024313C 16800079 */  bnez      $s4, .L80243324
/* 171A20 80243140 00000000 */   nop
/* 171A24 80243144 0C098F18 */  jal       reset_actor_turn_info
/* 171A28 80243148 0000882D */   daddu    $s1, $zero, $zero
/* 171A2C 8024314C 24130014 */  addiu     $s3, $zero, 0x14
/* 171A30 80243150 3C14800E */  lui       $s4, %hi(gBattleStatus)
/* 171A34 80243154 2694C070 */  addiu     $s4, $s4, %lo(gBattleStatus)
/* 171A38 80243158 00111080 */  sll       $v0, $s1, 2
.L8024315C:
/* 171A3C 8024315C 02C21021 */  addu      $v0, $s6, $v0
/* 171A40 80243160 8C5000E0 */  lw        $s0, 0xe0($v0)
/* 171A44 80243164 52000069 */  beql      $s0, $zero, .L8024330C
/* 171A48 80243168 26310001 */   addiu    $s1, $s1, 1
/* 171A4C 8024316C 3C04FFFE */  lui       $a0, 0xfffe
/* 171A50 80243170 3484FFFF */  ori       $a0, $a0, 0xffff
/* 171A54 80243174 8E020000 */  lw        $v0, ($s0)
/* 171A58 80243178 3C030C00 */  lui       $v1, 0xc00
/* 171A5C 8024317C 00431025 */  or        $v0, $v0, $v1
/* 171A60 80243180 00442024 */  and       $a0, $v0, $a0
/* 171A64 80243184 82020210 */  lb        $v0, 0x210($s0)
/* 171A68 80243188 92030210 */  lbu       $v1, 0x210($s0)
/* 171A6C 8024318C 10400015 */  beqz      $v0, .L802431E4
/* 171A70 80243190 AE040000 */   sw       $a0, ($s0)
/* 171A74 80243194 2462FFFD */  addiu     $v0, $v1, -3
/* 171A78 80243198 2C420006 */  sltiu     $v0, $v0, 6
/* 171A7C 8024319C 10400003 */  beqz      $v0, .L802431AC
/* 171A80 802431A0 3C020001 */   lui      $v0, 1
/* 171A84 802431A4 00821025 */  or        $v0, $a0, $v0
/* 171A88 802431A8 AE020000 */  sw        $v0, ($s0)
.L802431AC:
/* 171A8C 802431AC 92020211 */  lbu       $v0, 0x211($s0)
/* 171A90 802431B0 2442FFFF */  addiu     $v0, $v0, -1
/* 171A94 802431B4 A2020211 */  sb        $v0, 0x211($s0)
/* 171A98 802431B8 00021600 */  sll       $v0, $v0, 0x18
/* 171A9C 802431BC 1C400009 */  bgtz      $v0, .L802431E4
/* 171AA0 802431C0 00000000 */   nop
/* 171AA4 802431C4 86040436 */  lh        $a0, 0x436($s0)
/* 171AA8 802431C8 0C011E26 */  jal       remove_status_debuff
/* 171AAC 802431CC A2000210 */   sb       $zero, 0x210($s0)
/* 171AB0 802431D0 0200202D */  daddu     $a0, $s0, $zero
/* 171AB4 802431D4 0C09DC58 */  jal       dispatch_event_actor
/* 171AB8 802431D8 24050031 */   addiu    $a1, $zero, 0x31
/* 171ABC 802431DC 3C01802A */  lui       $at, %hi(D_8029F258)
/* 171AC0 802431E0 AC33F258 */  sw        $s3, %lo(D_8029F258)($at)
.L802431E4:
/* 171AC4 802431E4 82020212 */  lb        $v0, 0x212($s0)
/* 171AC8 802431E8 1040000C */  beqz      $v0, .L8024321C
/* 171ACC 802431EC 00000000 */   nop
/* 171AD0 802431F0 92020213 */  lbu       $v0, 0x213($s0)
/* 171AD4 802431F4 2442FFFF */  addiu     $v0, $v0, -1
/* 171AD8 802431F8 A2020213 */  sb        $v0, 0x213($s0)
/* 171ADC 802431FC 00021600 */  sll       $v0, $v0, 0x18
/* 171AE0 80243200 1C400006 */  bgtz      $v0, .L8024321C
/* 171AE4 80243204 00000000 */   nop
/* 171AE8 80243208 86040436 */  lh        $a0, 0x436($s0)
/* 171AEC 8024320C 0C011E68 */  jal       remove_status_static
/* 171AF0 80243210 A2000212 */   sb       $zero, 0x212($s0)
/* 171AF4 80243214 3C01802A */  lui       $at, %hi(D_8029F258)
/* 171AF8 80243218 AC33F258 */  sw        $s3, %lo(D_8029F258)($at)
.L8024321C:
/* 171AFC 8024321C 82020218 */  lb        $v0, 0x218($s0)
/* 171B00 80243220 1040000C */  beqz      $v0, .L80243254
/* 171B04 80243224 00000000 */   nop
/* 171B08 80243228 92020219 */  lbu       $v0, 0x219($s0)
/* 171B0C 8024322C 2442FFFF */  addiu     $v0, $v0, -1
/* 171B10 80243230 A2020219 */  sb        $v0, 0x219($s0)
/* 171B14 80243234 00021600 */  sll       $v0, $v0, 0x18
/* 171B18 80243238 1C400006 */  bgtz      $v0, .L80243254
/* 171B1C 8024323C 00000000 */   nop
/* 171B20 80243240 86040436 */  lh        $a0, 0x436($s0)
/* 171B24 80243244 0C011EAA */  jal       remove_status_transparent
/* 171B28 80243248 A2000218 */   sb       $zero, 0x218($s0)
/* 171B2C 8024324C 3C01802A */  lui       $at, %hi(D_8029F258)
/* 171B30 80243250 AC33F258 */  sw        $s3, %lo(D_8029F258)($at)
.L80243254:
/* 171B34 80243254 82020214 */  lb        $v0, 0x214($s0)
/* 171B38 80243258 1040000A */  beqz      $v0, .L80243284
/* 171B3C 8024325C 00000000 */   nop
/* 171B40 80243260 92020215 */  lbu       $v0, 0x215($s0)
/* 171B44 80243264 2442FFFF */  addiu     $v0, $v0, -1
/* 171B48 80243268 A2020215 */  sb        $v0, 0x215($s0)
/* 171B4C 8024326C 00021600 */  sll       $v0, $v0, 0x18
/* 171B50 80243270 1C400004 */  bgtz      $v0, .L80243284
/* 171B54 80243274 00000000 */   nop
/* 171B58 80243278 A2000214 */  sb        $zero, 0x214($s0)
/* 171B5C 8024327C 3C01802A */  lui       $at, %hi(D_8029F258)
/* 171B60 80243280 AC33F258 */  sw        $s3, %lo(D_8029F258)($at)
.L80243284:
/* 171B64 80243284 92020211 */  lbu       $v0, 0x211($s0)
/* 171B68 80243288 82030217 */  lb        $v1, 0x217($s0)
/* 171B6C 8024328C A2020217 */  sb        $v0, 0x217($s0)
/* 171B70 80243290 00021600 */  sll       $v0, $v0, 0x18
/* 171B74 80243294 00021603 */  sra       $v0, $v0, 0x18
/* 171B78 80243298 18400008 */  blez      $v0, .L802432BC
/* 171B7C 8024329C 00000000 */   nop
/* 171B80 802432A0 8E030440 */  lw        $v1, 0x440($s0)
/* 171B84 802432A4 2402000D */  addiu     $v0, $zero, 0xd
/* 171B88 802432A8 A2020216 */  sb        $v0, 0x216($s0)
/* 171B8C 802432AC 82020217 */  lb        $v0, 0x217($s0)
/* 171B90 802432B0 8C63000C */  lw        $v1, 0xc($v1)
/* 171B94 802432B4 08090CB5 */  j         .L802432D4
/* 171B98 802432B8 AC62003C */   sw       $v0, 0x3c($v1)
.L802432BC:
/* 171B9C 802432BC 10620005 */  beq       $v1, $v0, .L802432D4
/* 171BA0 802432C0 00000000 */   nop
/* 171BA4 802432C4 8E020440 */  lw        $v0, 0x440($s0)
/* 171BA8 802432C8 A2000216 */  sb        $zero, 0x216($s0)
/* 171BAC 802432CC 8C42000C */  lw        $v0, 0xc($v0)
/* 171BB0 802432D0 AC40003C */  sw        $zero, 0x3c($v0)
.L802432D4:
/* 171BB4 802432D4 82030210 */  lb        $v1, 0x210($s0)
/* 171BB8 802432D8 24020009 */  addiu     $v0, $zero, 9
/* 171BBC 802432DC 5462000B */  bnel      $v1, $v0, .L8024330C
/* 171BC0 802432E0 26310001 */   addiu    $s1, $s1, 1
/* 171BC4 802432E4 0200202D */  daddu     $a0, $s0, $zero
/* 171BC8 802432E8 24050001 */  addiu     $a1, $zero, 1
/* 171BCC 802432EC 8E820000 */  lw        $v0, ($s4)
/* 171BD0 802432F0 2406000A */  addiu     $a2, $zero, 0xa
/* 171BD4 802432F4 34420020 */  ori       $v0, $v0, 0x20
/* 171BD8 802432F8 0C09E23E */  jal       dispatch_damage_event_actor_0
/* 171BDC 802432FC AE820000 */   sw       $v0, ($s4)
/* 171BE0 80243300 3C01802A */  lui       $at, %hi(D_8029F258)
/* 171BE4 80243304 AC33F258 */  sw        $s3, %lo(D_8029F258)($at)
/* 171BE8 80243308 26310001 */  addiu     $s1, $s1, 1
.L8024330C:
/* 171BEC 8024330C 2A220018 */  slti      $v0, $s1, 0x18
/* 171BF0 80243310 1440FF92 */  bnez      $v0, .L8024315C
/* 171BF4 80243314 00111080 */   sll      $v0, $s1, 2
/* 171BF8 80243318 24020002 */  addiu     $v0, $zero, 2
/* 171BFC 8024331C 3C01800E */  lui       $at, %hi(gBattleState2)
/* 171C00 80243320 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
.L80243324:
/* 171C04 80243324 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 171C08 80243328 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 171C0C 8024332C 24020002 */  addiu     $v0, $zero, 2
.L80243330:
/* 171C10 80243330 14620070 */  bne       $v1, $v0, .L802434F4
/* 171C14 80243334 00000000 */   nop
/* 171C18 80243338 8EA201D8 */  lw        $v0, 0x1d8($s5)
/* 171C1C 8024333C 10400005 */  beqz      $v0, .L80243354
/* 171C20 80243340 00000000 */   nop
/* 171C24 80243344 0C0B1059 */  jal       does_script_exist
/* 171C28 80243348 8EA401E8 */   lw       $a0, 0x1e8($s5)
/* 171C2C 8024334C 14400069 */  bnez      $v0, .L802434F4
/* 171C30 80243350 00000000 */   nop
.L80243354:
/* 171C34 80243354 1240000A */  beqz      $s2, .L80243380
/* 171C38 80243358 AEA001D8 */   sw       $zero, 0x1d8($s5)
/* 171C3C 8024335C 8E4201D8 */  lw        $v0, 0x1d8($s2)
/* 171C40 80243360 50400007 */  beql      $v0, $zero, .L80243380
/* 171C44 80243364 AE4001D8 */   sw       $zero, 0x1d8($s2)
/* 171C48 80243368 8E4401E8 */  lw        $a0, 0x1e8($s2)
/* 171C4C 8024336C 0C0B1059 */  jal       does_script_exist
/* 171C50 80243370 00000000 */   nop
/* 171C54 80243374 1440005F */  bnez      $v0, .L802434F4
/* 171C58 80243378 00000000 */   nop
/* 171C5C 8024337C AE4001D8 */  sw        $zero, 0x1d8($s2)
.L80243380:
/* 171C60 80243380 0000A02D */  daddu     $s4, $zero, $zero
/* 171C64 80243384 0280882D */  daddu     $s1, $s4, $zero
/* 171C68 80243388 02C0982D */  daddu     $s3, $s6, $zero
.L8024338C:
/* 171C6C 8024338C 8E7000E0 */  lw        $s0, 0xe0($s3)
/* 171C70 80243390 5200000B */  beql      $s0, $zero, .L802433C0
/* 171C74 80243394 26310001 */   addiu    $s1, $s1, 1
/* 171C78 80243398 8E0201D8 */  lw        $v0, 0x1d8($s0)
/* 171C7C 8024339C 50400008 */  beql      $v0, $zero, .L802433C0
/* 171C80 802433A0 26310001 */   addiu    $s1, $s1, 1
/* 171C84 802433A4 8E0401E8 */  lw        $a0, 0x1e8($s0)
/* 171C88 802433A8 0C0B1059 */  jal       does_script_exist
/* 171C8C 802433AC 00000000 */   nop
/* 171C90 802433B0 50400002 */  beql      $v0, $zero, .L802433BC
/* 171C94 802433B4 AE0001D8 */   sw       $zero, 0x1d8($s0)
/* 171C98 802433B8 24140001 */  addiu     $s4, $zero, 1
.L802433BC:
/* 171C9C 802433BC 26310001 */  addiu     $s1, $s1, 1
.L802433C0:
/* 171CA0 802433C0 2A220018 */  slti      $v0, $s1, 0x18
/* 171CA4 802433C4 1440FFF1 */  bnez      $v0, .L8024338C
/* 171CA8 802433C8 26730004 */   addiu    $s3, $s3, 4
/* 171CAC 802433CC 16800049 */  bnez      $s4, .L802434F4
/* 171CB0 802433D0 00000000 */   nop
/* 171CB4 802433D4 0C098D19 */  jal       btl_check_player_defeated
/* 171CB8 802433D8 00000000 */   nop
/* 171CBC 802433DC 1440013F */  bnez      $v0, .L802438DC
/* 171CC0 802433E0 00000000 */   nop
/* 171CC4 802433E4 0C098D0D */  jal       btl_check_enemies_defeated
/* 171CC8 802433E8 00000000 */   nop
/* 171CCC 802433EC 1440013B */  bnez      $v0, .L802438DC
/* 171CD0 802433F0 00000000 */   nop
/* 171CD4 802433F4 0C093903 */  jal       btl_cam_use_preset
/* 171CD8 802433F8 24040002 */   addiu    $a0, $zero, 2
/* 171CDC 802433FC 12400007 */  beqz      $s2, .L8024341C
/* 171CE0 80243400 3C030010 */   lui      $v1, 0x10
/* 171CE4 80243404 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 171CE8 80243408 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 171CEC 8024340C 8C820000 */  lw        $v0, ($a0)
/* 171CF0 80243410 00431024 */  and       $v0, $v0, $v1
/* 171CF4 80243414 14400003 */  bnez      $v0, .L80243424
/* 171CF8 80243418 00000000 */   nop
.L8024341C:
/* 171CFC 8024341C 08090D3B */  j         .L802434EC
/* 171D00 80243420 24020004 */   addiu    $v0, $zero, 4
.L80243424:
/* 171D04 80243424 8C820004 */  lw        $v0, 4($a0)
/* 171D08 80243428 30420040 */  andi      $v0, $v0, 0x40
/* 171D0C 8024342C 1440002F */  bnez      $v0, .L802434EC
/* 171D10 80243430 24020004 */   addiu    $v0, $zero, 4
/* 171D14 80243434 3C03F7FF */  lui       $v1, 0xf7ff
/* 171D18 80243438 8EA20000 */  lw        $v0, ($s5)
/* 171D1C 8024343C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 171D20 80243440 00431024 */  and       $v0, $v0, $v1
/* 171D24 80243444 AEA20000 */  sw        $v0, ($s5)
/* 171D28 80243448 8E420000 */  lw        $v0, ($s2)
/* 171D2C 8024344C 00431024 */  and       $v0, $v0, $v1
/* 171D30 80243450 AE420000 */  sw        $v0, ($s2)
/* 171D34 80243454 8EA20000 */  lw        $v0, ($s5)
/* 171D38 80243458 3C030400 */  lui       $v1, 0x400
/* 171D3C 8024345C 00431025 */  or        $v0, $v0, $v1
/* 171D40 80243460 AEA20000 */  sw        $v0, ($s5)
/* 171D44 80243464 8E420000 */  lw        $v0, ($s2)
/* 171D48 80243468 00431025 */  or        $v0, $v0, $v1
/* 171D4C 8024346C AE420000 */  sw        $v0, ($s2)
/* 171D50 80243470 82C2009A */  lb        $v0, 0x9a($s6)
/* 171D54 80243474 1440000A */  bnez      $v0, .L802434A0
/* 171D58 80243478 2643000C */   addiu    $v1, $s2, 0xc
/* 171D5C 8024347C C6400138 */  lwc1      $f0, 0x138($s2)
/* 171D60 80243480 C6420140 */  lwc1      $f2, 0x140($s2)
/* 171D64 80243484 E640000C */  swc1      $f0, 0xc($s2)
/* 171D68 80243488 E6420014 */  swc1      $f2, 0x14($s2)
/* 171D6C 8024348C C6A00138 */  lwc1      $f0, 0x138($s5)
/* 171D70 80243490 E6400018 */  swc1      $f0, 0x18($s2)
/* 171D74 80243494 C6A00140 */  lwc1      $f0, 0x140($s5)
/* 171D78 80243498 08090D37 */  j         .L802434DC
/* 171D7C 8024349C E6400020 */   swc1     $f0, 0x20($s2)
.L802434A0:
/* 171D80 802434A0 C6400138 */  lwc1      $f0, 0x138($s2)
/* 171D84 802434A4 C6460140 */  lwc1      $f6, 0x140($s2)
/* 171D88 802434A8 3C0140A0 */  lui       $at, 0x40a0
/* 171D8C 802434AC 44811000 */  mtc1      $at, $f2
/* 171D90 802434B0 C6440138 */  lwc1      $f4, 0x138($s2)
/* 171D94 802434B4 E640000C */  swc1      $f0, 0xc($s2)
/* 171D98 802434B8 46003006 */  mov.s     $f0, $f6
/* 171D9C 802434BC 46020000 */  add.s     $f0, $f0, $f2
/* 171DA0 802434C0 E6460014 */  swc1      $f6, 0x14($s2)
/* 171DA4 802434C4 E6440018 */  swc1      $f4, 0x18($s2)
/* 171DA8 802434C8 E6400020 */  swc1      $f0, 0x20($s2)
/* 171DAC 802434CC C6A00138 */  lwc1      $f0, 0x138($s5)
/* 171DB0 802434D0 E6400138 */  swc1      $f0, 0x138($s2)
/* 171DB4 802434D4 C6A00140 */  lwc1      $f0, 0x140($s5)
/* 171DB8 802434D8 E6400140 */  swc1      $f0, 0x140($s2)
.L802434DC:
/* 171DBC 802434DC 24020004 */  addiu     $v0, $zero, 4
/* 171DC0 802434E0 A4620064 */  sh        $v0, 0x64($v1)
/* 171DC4 802434E4 24020003 */  addiu     $v0, $zero, 3
/* 171DC8 802434E8 AC600048 */  sw        $zero, 0x48($v1)
.L802434EC:
/* 171DCC 802434EC 3C01800E */  lui       $at, %hi(gBattleState2)
/* 171DD0 802434F0 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
.L802434F4:
/* 171DD4 802434F4 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 171DD8 802434F8 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 171DDC 802434FC 24020003 */  addiu     $v0, $zero, 3
/* 171DE0 80243500 1462006F */  bne       $v1, $v0, .L802436C0
/* 171DE4 80243504 00000000 */   nop
/* 171DE8 80243508 86420070 */  lh        $v0, 0x70($s2)
/* 171DEC 8024350C 10400022 */  beqz      $v0, .L80243598
/* 171DF0 80243510 00000000 */   nop
/* 171DF4 80243514 C6400018 */  lwc1      $f0, 0x18($s2)
/* 171DF8 80243518 C6480144 */  lwc1      $f8, 0x144($s2)
/* 171DFC 8024351C C6420020 */  lwc1      $f2, 0x20($s2)
/* 171E00 80243520 46080001 */  sub.s     $f0, $f0, $f8
/* 171E04 80243524 C644014C */  lwc1      $f4, 0x14c($s2)
/* 171E08 80243528 46041081 */  sub.s     $f2, $f2, $f4
/* 171E0C 8024352C 44823000 */  mtc1      $v0, $f6
/* 171E10 80243530 00000000 */  nop
/* 171E14 80243534 468031A0 */  cvt.s.w   $f6, $f6
/* 171E18 80243538 46060003 */  div.s     $f0, $f0, $f6
/* 171E1C 8024353C 46004200 */  add.s     $f8, $f8, $f0
/* 171E20 80243540 46003006 */  mov.s     $f0, $f6
/* 171E24 80243544 46061083 */  div.s     $f2, $f2, $f6
/* 171E28 80243548 C640000C */  lwc1      $f0, 0xc($s2)
/* 171E2C 8024354C 46022100 */  add.s     $f4, $f4, $f2
/* 171E30 80243550 E6480144 */  swc1      $f8, 0x144($s2)
/* 171E34 80243554 E644014C */  swc1      $f4, 0x14c($s2)
/* 171E38 80243558 C6A40144 */  lwc1      $f4, 0x144($s5)
/* 171E3C 8024355C 46040001 */  sub.s     $f0, $f0, $f4
/* 171E40 80243560 46003086 */  mov.s     $f2, $f6
/* 171E44 80243564 46060003 */  div.s     $f0, $f0, $f6
/* 171E48 80243568 46002100 */  add.s     $f4, $f4, $f0
/* 171E4C 8024356C E6A40144 */  swc1      $f4, 0x144($s5)
/* 171E50 80243570 C6400014 */  lwc1      $f0, 0x14($s2)
/* 171E54 80243574 C6A4014C */  lwc1      $f4, 0x14c($s5)
/* 171E58 80243578 86420070 */  lh        $v0, 0x70($s2)
/* 171E5C 8024357C 46040001 */  sub.s     $f0, $f0, $f4
/* 171E60 80243580 44821000 */  mtc1      $v0, $f2
/* 171E64 80243584 00000000 */  nop
/* 171E68 80243588 468010A0 */  cvt.s.w   $f2, $f2
/* 171E6C 8024358C 46020003 */  div.s     $f0, $f0, $f2
/* 171E70 80243590 46002100 */  add.s     $f4, $f4, $f0
/* 171E74 80243594 E6A4014C */  swc1      $f4, 0x14c($s5)
.L80243598:
/* 171E78 80243598 C64C0054 */  lwc1      $f12, 0x54($s2)
/* 171E7C 8024359C 3C0140C9 */  lui       $at, 0x40c9
/* 171E80 802435A0 34210FD0 */  ori       $at, $at, 0xfd0
/* 171E84 802435A4 4481B000 */  mtc1      $at, $f22
/* 171E88 802435A8 00000000 */  nop
/* 171E8C 802435AC 46166302 */  mul.s     $f12, $f12, $f22
/* 171E90 802435B0 00000000 */  nop
/* 171E94 802435B4 3C0143B4 */  lui       $at, 0x43b4
/* 171E98 802435B8 4481C000 */  mtc1      $at, $f24
/* 171E9C 802435BC 3C014180 */  lui       $at, 0x4180
/* 171EA0 802435C0 4481A000 */  mtc1      $at, $f20
/* 171EA4 802435C4 0C00A85B */  jal       sin_rad
/* 171EA8 802435C8 46186303 */   div.s    $f12, $f12, $f24
/* 171EAC 802435CC 46140002 */  mul.s     $f0, $f0, $f20
/* 171EB0 802435D0 00000000 */  nop
/* 171EB4 802435D4 C642014C */  lwc1      $f2, 0x14c($s2)
/* 171EB8 802435D8 46001081 */  sub.s     $f2, $f2, $f0
/* 171EBC 802435DC C64C0054 */  lwc1      $f12, 0x54($s2)
/* 171EC0 802435E0 0C00A6C9 */  jal       clamp_angle
/* 171EC4 802435E4 E642014C */   swc1     $f2, 0x14c($s2)
/* 171EC8 802435E8 C64C0054 */  lwc1      $f12, 0x54($s2)
/* 171ECC 802435EC 46166302 */  mul.s     $f12, $f12, $f22
/* 171ED0 802435F0 00000000 */  nop
/* 171ED4 802435F4 E640018C */  swc1      $f0, 0x18c($s2)
/* 171ED8 802435F8 0C00A85B */  jal       sin_rad
/* 171EDC 802435FC 46186303 */   div.s    $f12, $f12, $f24
/* 171EE0 80243600 46140002 */  mul.s     $f0, $f0, $f20
/* 171EE4 80243604 00000000 */  nop
/* 171EE8 80243608 C6A2014C */  lwc1      $f2, 0x14c($s5)
/* 171EEC 8024360C 46001080 */  add.s     $f2, $f2, $f0
/* 171EF0 80243610 E6A2014C */  swc1      $f2, 0x14c($s5)
/* 171EF4 80243614 0C00A6C9 */  jal       clamp_angle
/* 171EF8 80243618 C64C0054 */   lwc1     $f12, 0x54($s2)
/* 171EFC 8024361C E6A0018C */  swc1      $f0, 0x18c($s5)
/* 171F00 80243620 C6400054 */  lwc1      $f0, 0x54($s2)
/* 171F04 80243624 3C0142B4 */  lui       $at, 0x42b4
/* 171F08 80243628 44811000 */  mtc1      $at, $f2
/* 171F0C 8024362C 86420070 */  lh        $v0, 0x70($s2)
/* 171F10 80243630 46020000 */  add.s     $f0, $f0, $f2
/* 171F14 80243634 96430070 */  lhu       $v1, 0x70($s2)
/* 171F18 80243638 10400004 */  beqz      $v0, .L8024364C
/* 171F1C 8024363C E6400054 */   swc1     $f0, 0x54($s2)
/* 171F20 80243640 2462FFFF */  addiu     $v0, $v1, -1
/* 171F24 80243644 08090DB0 */  j         .L802436C0
/* 171F28 80243648 A6420070 */   sh       $v0, 0x70($s2)
.L8024364C:
/* 171F2C 8024364C C6400018 */  lwc1      $f0, 0x18($s2)
/* 171F30 80243650 C6420020 */  lwc1      $f2, 0x20($s2)
/* 171F34 80243654 C644000C */  lwc1      $f4, 0xc($s2)
/* 171F38 80243658 E6400144 */  swc1      $f0, 0x144($s2)
/* 171F3C 8024365C E642014C */  swc1      $f2, 0x14c($s2)
/* 171F40 80243660 E6A40144 */  swc1      $f4, 0x144($s5)
/* 171F44 80243664 C6400014 */  lwc1      $f0, 0x14($s2)
/* 171F48 80243668 E6A0014C */  swc1      $f0, 0x14c($s5)
/* 171F4C 8024366C 82C2009A */  lb        $v0, 0x9a($s6)
/* 171F50 80243670 14400005 */  bnez      $v0, .L80243688
/* 171F54 80243674 00000000 */   nop
/* 171F58 80243678 C6400144 */  lwc1      $f0, 0x144($s2)
/* 171F5C 8024367C C642014C */  lwc1      $f2, 0x14c($s2)
/* 171F60 80243680 E6400138 */  swc1      $f0, 0x138($s2)
/* 171F64 80243684 E6420140 */  swc1      $f2, 0x140($s2)
.L80243688:
/* 171F68 80243688 C6A00144 */  lwc1      $f0, 0x144($s5)
/* 171F6C 8024368C C6A2014C */  lwc1      $f2, 0x14c($s5)
/* 171F70 80243690 E6A00138 */  swc1      $f0, 0x138($s5)
/* 171F74 80243694 E6A20140 */  swc1      $f2, 0x140($s5)
/* 171F78 80243698 3C05FFEF */  lui       $a1, 0xffef
/* 171F7C 8024369C 34A5FFFF */  ori       $a1, $a1, 0xffff
/* 171F80 802436A0 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 171F84 802436A4 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 171F88 802436A8 8C820000 */  lw        $v0, ($a0)
/* 171F8C 802436AC 24030004 */  addiu     $v1, $zero, 4
/* 171F90 802436B0 3C01800E */  lui       $at, %hi(gBattleState2)
/* 171F94 802436B4 AC23C4DC */  sw        $v1, %lo(gBattleState2)($at)
/* 171F98 802436B8 00451024 */  and       $v0, $v0, $a1
/* 171F9C 802436BC AC820000 */  sw        $v0, ($a0)
.L802436C0:
/* 171FA0 802436C0 3C10800E */  lui       $s0, %hi(gBattleState2)
/* 171FA4 802436C4 2610C4DC */  addiu     $s0, $s0, %lo(gBattleState2)
/* 171FA8 802436C8 8E030000 */  lw        $v1, ($s0)
/* 171FAC 802436CC 24020004 */  addiu     $v0, $zero, 4
/* 171FB0 802436D0 14620038 */  bne       $v1, $v0, .L802437B4
/* 171FB4 802436D4 00000000 */   nop
/* 171FB8 802436D8 3C03802A */  lui       $v1, %hi(D_8029F258)
/* 171FBC 802436DC 2463F258 */  addiu     $v1, $v1, %lo(D_8029F258)
/* 171FC0 802436E0 8C620000 */  lw        $v0, ($v1)
/* 171FC4 802436E4 10400003 */  beqz      $v0, .L802436F4
/* 171FC8 802436E8 2442FFFF */   addiu    $v0, $v0, -1
/* 171FCC 802436EC 08090DED */  j         .L802437B4
/* 171FD0 802436F0 AC620000 */   sw       $v0, ($v1)
.L802436F4:
/* 171FD4 802436F4 82C3008A */  lb        $v1, 0x8a($s6)
/* 171FD8 802436F8 24020002 */  addiu     $v0, $zero, 2
/* 171FDC 802436FC 14620011 */  bne       $v1, $v0, .L80243744
/* 171FE0 80243700 3C04F7FF */   lui      $a0, 0xf7ff
/* 171FE4 80243704 3C048028 */  lui       $a0, %hi(PlayerScriptDispatcher)
/* 171FE8 80243708 24844EBC */  addiu     $a0, $a0, %lo(PlayerScriptDispatcher)
/* 171FEC 8024370C 2405000A */  addiu     $a1, $zero, 0xa
/* 171FF0 80243710 0000302D */  daddu     $a2, $zero, $zero
/* 171FF4 80243714 24020003 */  addiu     $v0, $zero, 3
/* 171FF8 80243718 A2C200AD */  sb        $v0, 0xad($s6)
/* 171FFC 8024371C 24020015 */  addiu     $v0, $zero, 0x15
/* 172000 80243720 A2C0008A */  sb        $zero, 0x8a($s6)
/* 172004 80243724 0C0B0CF8 */  jal       start_script
/* 172008 80243728 A2C201A7 */   sb       $v0, 0x1a7($s6)
/* 17200C 8024372C 0040182D */  daddu     $v1, $v0, $zero
/* 172010 80243730 AEA301D4 */  sw        $v1, 0x1d4($s5)
/* 172014 80243734 8C620144 */  lw        $v0, 0x144($v1)
/* 172018 80243738 AEA201E4 */  sw        $v0, 0x1e4($s5)
/* 17201C 8024373C AC600148 */  sw        $zero, 0x148($v1)
/* 172020 80243740 3C04F7FF */  lui       $a0, 0xf7ff
.L80243744:
/* 172024 80243744 3C05800E */  lui       $a1, %hi(gBattleStatus)
/* 172028 80243748 24A5C070 */  addiu     $a1, $a1, %lo(gBattleStatus)
/* 17202C 8024374C 2406FFFD */  addiu     $a2, $zero, -3
/* 172030 80243750 8CA20000 */  lw        $v0, ($a1)
/* 172034 80243754 3484FFFF */  ori       $a0, $a0, 0xffff
/* 172038 80243758 00461024 */  and       $v0, $v0, $a2
/* 17203C 8024375C ACA20000 */  sw        $v0, ($a1)
/* 172040 80243760 8EA20000 */  lw        $v0, ($s5)
/* 172044 80243764 3C030400 */  lui       $v1, 0x400
/* 172048 80243768 00441024 */  and       $v0, $v0, $a0
/* 17204C 8024376C 00431025 */  or        $v0, $v0, $v1
/* 172050 80243770 12400005 */  beqz      $s2, .L80243788
/* 172054 80243774 AEA20000 */   sw       $v0, ($s5)
/* 172058 80243778 8E420000 */  lw        $v0, ($s2)
/* 17205C 8024377C 00441024 */  and       $v0, $v0, $a0
/* 172060 80243780 00431025 */  or        $v0, $v0, $v1
/* 172064 80243784 AE420000 */  sw        $v0, ($s2)
.L80243788:
/* 172068 80243788 8CA20004 */  lw        $v0, 4($a1)
/* 17206C 8024378C 24030005 */  addiu     $v1, $zero, 5
/* 172070 80243790 AE030000 */  sw        $v1, ($s0)
/* 172074 80243794 2403FFFB */  addiu     $v1, $zero, -5
/* 172078 80243798 00461024 */  and       $v0, $v0, $a2
/* 17207C 8024379C 00431024 */  and       $v0, $v0, $v1
/* 172080 802437A0 2403FFF7 */  addiu     $v1, $zero, -9
/* 172084 802437A4 00431024 */  and       $v0, $v0, $v1
/* 172088 802437A8 2403FFEF */  addiu     $v1, $zero, -0x11
/* 17208C 802437AC 00431024 */  and       $v0, $v0, $v1
/* 172090 802437B0 ACA20004 */  sw        $v0, 4($a1)
.L802437B4:
/* 172094 802437B4 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 172098 802437B8 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 17209C 802437BC 24020005 */  addiu     $v0, $zero, 5
/* 1720A0 802437C0 14620028 */  bne       $v1, $v0, .L80243864
/* 1720A4 802437C4 24020006 */   addiu    $v0, $zero, 6
/* 1720A8 802437C8 8EA201D4 */  lw        $v0, 0x1d4($s5)
/* 1720AC 802437CC 50400007 */  beql      $v0, $zero, .L802437EC
/* 1720B0 802437D0 AEA001D4 */   sw       $zero, 0x1d4($s5)
/* 1720B4 802437D4 8EA401E4 */  lw        $a0, 0x1e4($s5)
/* 1720B8 802437D8 0C0B1059 */  jal       does_script_exist
/* 1720BC 802437DC 00000000 */   nop
/* 1720C0 802437E0 1440001D */  bnez      $v0, .L80243858
/* 1720C4 802437E4 00000000 */   nop
/* 1720C8 802437E8 AEA001D4 */  sw        $zero, 0x1d4($s5)
.L802437EC:
/* 1720CC 802437EC 0000882D */  daddu     $s1, $zero, $zero
/* 1720D0 802437F0 2413000D */  addiu     $s3, $zero, 0xd
/* 1720D4 802437F4 02C0902D */  daddu     $s2, $s6, $zero
.L802437F8:
/* 1720D8 802437F8 8E5000E0 */  lw        $s0, 0xe0($s2)
/* 1720DC 802437FC 52000010 */  beql      $s0, $zero, .L80243840
/* 1720E0 80243800 26310001 */   addiu    $s1, $s1, 1
/* 1720E4 80243804 8E0201CC */  lw        $v0, 0x1cc($s0)
/* 1720E8 80243808 5040000D */  beql      $v0, $zero, .L80243840
/* 1720EC 8024380C 26310001 */   addiu    $s1, $s1, 1
/* 1720F0 80243810 2405000A */  addiu     $a1, $zero, 0xa
/* 1720F4 80243814 A2D301A7 */  sb        $s3, 0x1a7($s6)
/* 1720F8 80243818 8E0401CC */  lw        $a0, 0x1cc($s0)
/* 1720FC 8024381C 0C0B0CF8 */  jal       start_script
/* 172100 80243820 0000302D */   daddu    $a2, $zero, $zero
/* 172104 80243824 0040182D */  daddu     $v1, $v0, $zero
/* 172108 80243828 AE0301DC */  sw        $v1, 0x1dc($s0)
/* 17210C 8024382C 8C620144 */  lw        $v0, 0x144($v1)
/* 172110 80243830 AE0201EC */  sw        $v0, 0x1ec($s0)
/* 172114 80243834 36220200 */  ori       $v0, $s1, 0x200
/* 172118 80243838 AC620148 */  sw        $v0, 0x148($v1)
/* 17211C 8024383C 26310001 */  addiu     $s1, $s1, 1
.L80243840:
/* 172120 80243840 2A220018 */  slti      $v0, $s1, 0x18
/* 172124 80243844 1440FFEC */  bnez      $v0, .L802437F8
/* 172128 80243848 26520004 */   addiu    $s2, $s2, 4
/* 17212C 8024384C 24020006 */  addiu     $v0, $zero, 6
/* 172130 80243850 3C01800E */  lui       $at, %hi(gBattleState2)
/* 172134 80243854 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
.L80243858:
/* 172138 80243858 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 17213C 8024385C 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 172140 80243860 24020006 */  addiu     $v0, $zero, 6
.L80243864:
/* 172144 80243864 14620016 */  bne       $v1, $v0, .L802438C0
/* 172148 80243868 0000A02D */   daddu    $s4, $zero, $zero
/* 17214C 8024386C 0280882D */  daddu     $s1, $s4, $zero
/* 172150 80243870 02C0902D */  daddu     $s2, $s6, $zero
.L80243874:
/* 172154 80243874 8E5000E0 */  lw        $s0, 0xe0($s2)
/* 172158 80243878 5200000A */  beql      $s0, $zero, .L802438A4
/* 17215C 8024387C 26310001 */   addiu    $s1, $s1, 1
/* 172160 80243880 8E0201CC */  lw        $v0, 0x1cc($s0)
/* 172164 80243884 50400007 */  beql      $v0, $zero, .L802438A4
/* 172168 80243888 26310001 */   addiu    $s1, $s1, 1
/* 17216C 8024388C 8E0401EC */  lw        $a0, 0x1ec($s0)
/* 172170 80243890 0C0B1059 */  jal       does_script_exist
/* 172174 80243894 00000000 */   nop
/* 172178 80243898 54400001 */  bnel      $v0, $zero, .L802438A0
/* 17217C 8024389C 24140001 */   addiu    $s4, $zero, 1
.L802438A0:
/* 172180 802438A0 26310001 */  addiu     $s1, $s1, 1
.L802438A4:
/* 172184 802438A4 2A220018 */  slti      $v0, $s1, 0x18
/* 172188 802438A8 1440FFF2 */  bnez      $v0, .L80243874
/* 17218C 802438AC 26520004 */   addiu    $s2, $s2, 4
/* 172190 802438B0 16800003 */  bnez      $s4, .L802438C0
/* 172194 802438B4 24020007 */   addiu    $v0, $zero, 7
/* 172198 802438B8 3C01800E */  lui       $at, %hi(gBattleState2)
/* 17219C 802438BC AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
.L802438C0:
/* 1721A0 802438C0 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 1721A4 802438C4 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 1721A8 802438C8 24020007 */  addiu     $v0, $zero, 7
/* 1721AC 802438CC 14620003 */  bne       $v1, $v0, .L802438DC
/* 1721B0 802438D0 24040014 */   addiu    $a0, $zero, 0x14
.L802438D4:
/* 1721B4 802438D4 0C090464 */  jal       btl_set_state
/* 1721B8 802438D8 00000000 */   nop
.L802438DC:
/* 1721BC 802438DC 8FBF002C */  lw        $ra, 0x2c($sp)
/* 1721C0 802438E0 8FB60028 */  lw        $s6, 0x28($sp)
/* 1721C4 802438E4 8FB50024 */  lw        $s5, 0x24($sp)
/* 1721C8 802438E8 8FB40020 */  lw        $s4, 0x20($sp)
/* 1721CC 802438EC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1721D0 802438F0 8FB20018 */  lw        $s2, 0x18($sp)
/* 1721D4 802438F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 1721D8 802438F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 1721DC 802438FC D7B80040 */  ldc1      $f24, 0x40($sp)
/* 1721E0 80243900 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 1721E4 80243904 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 1721E8 80243908 03E00008 */  jr        $ra
/* 1721EC 8024390C 27BD0048 */   addiu    $sp, $sp, 0x48
