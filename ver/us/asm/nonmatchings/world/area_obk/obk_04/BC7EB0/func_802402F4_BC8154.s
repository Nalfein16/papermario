.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F4_BC8154
/* BC8154 802402F4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BC8158 802402F8 AFB10014 */  sw        $s1, 0x14($sp)
/* BC815C 802402FC 0080882D */  daddu     $s1, $a0, $zero
/* BC8160 80240300 AFBF0024 */  sw        $ra, 0x24($sp)
/* BC8164 80240304 AFB40020 */  sw        $s4, 0x20($sp)
/* BC8168 80240308 AFB3001C */  sw        $s3, 0x1c($sp)
/* BC816C 8024030C AFB20018 */  sw        $s2, 0x18($sp)
/* BC8170 80240310 AFB00010 */  sw        $s0, 0x10($sp)
/* BC8174 80240314 8E24014C */  lw        $a0, 0x14c($s1)
/* BC8178 80240318 0C00EABB */  jal       get_npc_unsafe
/* BC817C 8024031C 2414000C */   addiu    $s4, $zero, 0xc
/* BC8180 80240320 0040802D */  daddu     $s0, $v0, $zero
/* BC8184 80240324 8E230074 */  lw        $v1, 0x74($s1)
/* BC8188 80240328 8E130020 */  lw        $s3, 0x20($s0)
/* BC818C 8024032C 10740057 */  beq       $v1, $s4, .L8024048C
/* BC8190 80240330 2862000D */   slti     $v0, $v1, 0xd
/* BC8194 80240334 1040000F */  beqz      $v0, .L80240374
/* BC8198 80240338 24120001 */   addiu    $s2, $zero, 1
/* BC819C 8024033C 10720094 */  beq       $v1, $s2, .L80240590
/* BC81A0 80240340 28620002 */   slti     $v0, $v1, 2
/* BC81A4 80240344 10400005 */  beqz      $v0, .L8024035C
/* BC81A8 80240348 2402000A */   addiu    $v0, $zero, 0xa
/* BC81AC 8024034C 10600015 */  beqz      $v1, .L802403A4
/* BC81B0 80240350 0220202D */   daddu    $a0, $s1, $zero
/* BC81B4 80240354 08090164 */  j         .L80240590
/* BC81B8 80240358 00000000 */   nop
.L8024035C:
/* BC81BC 8024035C 10620019 */  beq       $v1, $v0, .L802403C4
/* BC81C0 80240360 2402000B */   addiu    $v0, $zero, 0xb
/* BC81C4 80240364 10620025 */  beq       $v1, $v0, .L802403FC
/* BC81C8 80240368 00000000 */   nop
/* BC81CC 8024036C 08090164 */  j         .L80240590
/* BC81D0 80240370 00000000 */   nop
.L80240374:
/* BC81D4 80240374 2402000E */  addiu     $v0, $zero, 0xe
/* BC81D8 80240378 1062005B */  beq       $v1, $v0, .L802404E8
/* BC81DC 8024037C 0062102A */   slt      $v0, $v1, $v0
/* BC81E0 80240380 1440004E */  bnez      $v0, .L802404BC
/* BC81E4 80240384 0220202D */   daddu    $a0, $s1, $zero
/* BC81E8 80240388 2402000F */  addiu     $v0, $zero, 0xf
/* BC81EC 8024038C 10620069 */  beq       $v1, $v0, .L80240534
/* BC81F0 80240390 24020064 */   addiu    $v0, $zero, 0x64
/* BC81F4 80240394 10620079 */  beq       $v1, $v0, .L8024057C
/* BC81F8 80240398 3C05FD05 */   lui      $a1, 0xfd05
/* BC81FC 8024039C 08090164 */  j         .L80240590
/* BC8200 802403A0 00000000 */   nop
.L802403A4:
/* BC8204 802403A4 3C05FD05 */  lui       $a1, 0xfd05
/* BC8208 802403A8 0C0B1EAF */  jal       evt_get_variable
/* BC820C 802403AC 34A50F81 */   ori      $a1, $a1, 0xf81
/* BC8210 802403B0 14520077 */  bne       $v0, $s2, .L80240590
/* BC8214 802403B4 00000000 */   nop
/* BC8218 802403B8 AE620000 */  sw        $v0, ($s3)
/* BC821C 802403BC 08090163 */  j         .L8024058C
/* BC8220 802403C0 2402000A */   addiu    $v0, $zero, 0xa
.L802403C4:
/* BC8224 802403C4 C600000C */  lwc1      $f0, 0xc($s0)
/* BC8228 802403C8 3C014000 */  lui       $at, 0x4000
/* BC822C 802403CC 44816000 */  mtc1      $at, $f12
/* BC8230 802403D0 0C00A6C9 */  jal       clamp_angle
/* BC8234 802403D4 460C0300 */   add.s    $f12, $f0, $f12
/* BC8238 802403D8 9602008E */  lhu       $v0, 0x8e($s0)
/* BC823C 802403DC E600000C */  swc1      $f0, 0xc($s0)
/* BC8240 802403E0 2442FFFF */  addiu     $v0, $v0, -1
/* BC8244 802403E4 A602008E */  sh        $v0, 0x8e($s0)
/* BC8248 802403E8 00021400 */  sll       $v0, $v0, 0x10
/* BC824C 802403EC 14400068 */  bnez      $v0, .L80240590
/* BC8250 802403F0 2402000B */   addiu    $v0, $zero, 0xb
/* BC8254 802403F4 08090164 */  j         .L80240590
/* BC8258 802403F8 AE220074 */   sw       $v0, 0x74($s1)
.L802403FC:
/* BC825C 802403FC C602003C */  lwc1      $f2, 0x3c($s0)
/* BC8260 80240400 3C01C466 */  lui       $at, 0xc466
/* BC8264 80240404 44810000 */  mtc1      $at, $f0
/* BC8268 80240408 00000000 */  nop
/* BC826C 8024040C 4600103E */  c.le.s    $f2, $f0
/* BC8270 80240410 00000000 */  nop
/* BC8274 80240414 45000003 */  bc1f      .L80240424
/* BC8278 80240418 00000000 */   nop
/* BC827C 8024041C 0C090066 */  jal       func_80240198_BC7FF8
/* BC8280 80240420 00000000 */   nop
.L80240424:
/* BC8284 80240424 C600000C */  lwc1      $f0, 0xc($s0)
/* BC8288 80240428 3C014000 */  lui       $at, 0x4000
/* BC828C 8024042C 44816000 */  mtc1      $at, $f12
/* BC8290 80240430 0C00A6C9 */  jal       clamp_angle
/* BC8294 80240434 460C0300 */   add.s    $f12, $f0, $f12
/* BC8298 80240438 C604003C */  lwc1      $f4, 0x3c($s0)
/* BC829C 8024043C 3C013F00 */  lui       $at, 0x3f00
/* BC82A0 80240440 44811000 */  mtc1      $at, $f2
/* BC82A4 80240444 00000000 */  nop
/* BC82A8 80240448 46022101 */  sub.s     $f4, $f4, $f2
/* BC82AC 8024044C 3C01C477 */  lui       $at, 0xc477
/* BC82B0 80240450 44811000 */  mtc1      $at, $f2
/* BC82B4 80240454 E600000C */  swc1      $f0, 0xc($s0)
/* BC82B8 80240458 4602203E */  c.le.s    $f4, $f2
/* BC82BC 8024045C 00000000 */  nop
/* BC82C0 80240460 4500004B */  bc1f      .L80240590
/* BC82C4 80240464 E604003C */   swc1     $f4, 0x3c($s0)
/* BC82C8 80240468 0220202D */  daddu     $a0, $s1, $zero
/* BC82CC 8024046C 3C05FD05 */  lui       $a1, 0xfd05
/* BC82D0 80240470 34A50F82 */  ori       $a1, $a1, 0xf82
/* BC82D4 80240474 0C0B2026 */  jal       evt_set_variable
/* BC82D8 80240478 24060001 */   addiu    $a2, $zero, 1
/* BC82DC 8024047C 0C09008B */  jal       func_8024022C_BC808C
/* BC82E0 80240480 00000000 */   nop
/* BC82E4 80240484 08090164 */  j         .L80240590
/* BC82E8 80240488 AE340074 */   sw       $s4, 0x74($s1)
.L8024048C:
/* BC82EC 8024048C 0220202D */  daddu     $a0, $s1, $zero
/* BC82F0 80240490 3C05FD05 */  lui       $a1, 0xfd05
/* BC82F4 80240494 0C0B1EAF */  jal       evt_get_variable
/* BC82F8 80240498 34A50F83 */   ori      $a1, $a1, 0xf83
/* BC82FC 8024049C 0C0900A8 */  jal       func_802402A0_BC8100
/* BC8300 802404A0 0040202D */   daddu    $a0, $v0, $zero
/* BC8304 802404A4 AE220074 */  sw        $v0, 0x74($s1)
/* BC8308 802404A8 C600000C */  lwc1      $f0, 0xc($s0)
/* BC830C 802404AC 3C014000 */  lui       $at, 0x4000
/* BC8310 802404B0 44816000 */  mtc1      $at, $f12
/* BC8314 802404B4 0809015B */  j         .L8024056C
/* BC8318 802404B8 460C0300 */   add.s    $f12, $f0, $f12
.L802404BC:
/* BC831C 802404BC 3C05FD05 */  lui       $a1, 0xfd05
/* BC8320 802404C0 0C0B1EAF */  jal       evt_get_variable
/* BC8324 802404C4 34A50F83 */   ori      $a1, $a1, 0xf83
/* BC8328 802404C8 0C0900A8 */  jal       func_802402A0_BC8100
/* BC832C 802404CC 0040202D */   daddu    $a0, $v0, $zero
/* BC8330 802404D0 AE220074 */  sw        $v0, 0x74($s1)
/* BC8334 802404D4 C600000C */  lwc1      $f0, 0xc($s0)
/* BC8338 802404D8 3C014000 */  lui       $at, 0x4000
/* BC833C 802404DC 44816000 */  mtc1      $at, $f12
/* BC8340 802404E0 0809015B */  j         .L8024056C
/* BC8344 802404E4 460C0301 */   sub.s    $f12, $f0, $f12
.L802404E8:
/* BC8348 802404E8 0220202D */  daddu     $a0, $s1, $zero
/* BC834C 802404EC 3C05FD05 */  lui       $a1, 0xfd05
/* BC8350 802404F0 34A50F83 */  ori       $a1, $a1, 0xf83
/* BC8354 802404F4 0C0B2026 */  jal       evt_set_variable
/* BC8358 802404F8 0000302D */   daddu    $a2, $zero, $zero
/* BC835C 802404FC 9602008E */  lhu       $v0, 0x8e($s0)
/* BC8360 80240500 24030032 */  addiu     $v1, $zero, 0x32
/* BC8364 80240504 24420001 */  addiu     $v0, $v0, 1
/* BC8368 80240508 A602008E */  sh        $v0, 0x8e($s0)
/* BC836C 8024050C 00021400 */  sll       $v0, $v0, 0x10
/* BC8370 80240510 00021403 */  sra       $v0, $v0, 0x10
/* BC8374 80240514 14430002 */  bne       $v0, $v1, .L80240520
/* BC8378 80240518 2402000F */   addiu    $v0, $zero, 0xf
/* BC837C 8024051C AE220074 */  sw        $v0, 0x74($s1)
.L80240520:
/* BC8380 80240520 C6000010 */  lwc1      $f0, 0x10($s0)
/* BC8384 80240524 3C014000 */  lui       $at, 0x4000
/* BC8388 80240528 44811000 */  mtc1      $at, $f2
/* BC838C 8024052C 08090158 */  j         .L80240560
/* BC8390 80240530 46020001 */   sub.s    $f0, $f0, $f2
.L80240534:
/* BC8394 80240534 9602008E */  lhu       $v0, 0x8e($s0)
/* BC8398 80240538 2442FFFF */  addiu     $v0, $v0, -1
/* BC839C 8024053C A602008E */  sh        $v0, 0x8e($s0)
/* BC83A0 80240540 00021400 */  sll       $v0, $v0, 0x10
/* BC83A4 80240544 50400001 */  beql      $v0, $zero, .L8024054C
/* BC83A8 80240548 AE340074 */   sw       $s4, 0x74($s1)
.L8024054C:
/* BC83AC 8024054C C6000010 */  lwc1      $f0, 0x10($s0)
/* BC83B0 80240550 3C014000 */  lui       $at, 0x4000
/* BC83B4 80240554 44811000 */  mtc1      $at, $f2
/* BC83B8 80240558 00000000 */  nop
/* BC83BC 8024055C 46020000 */  add.s     $f0, $f0, $f2
.L80240560:
/* BC83C0 80240560 C60C000C */  lwc1      $f12, 0xc($s0)
/* BC83C4 80240564 46026300 */  add.s     $f12, $f12, $f2
/* BC83C8 80240568 E6000010 */  swc1      $f0, 0x10($s0)
.L8024056C:
/* BC83CC 8024056C 0C00A6C9 */  jal       clamp_angle
/* BC83D0 80240570 00000000 */   nop
/* BC83D4 80240574 08090164 */  j         .L80240590
/* BC83D8 80240578 E600000C */   swc1     $f0, 0xc($s0)
.L8024057C:
/* BC83DC 8024057C 0C0B1EAF */  jal       evt_get_variable
/* BC83E0 80240580 34A50F83 */   ori      $a1, $a1, 0xf83
/* BC83E4 80240584 0C0900A8 */  jal       func_802402A0_BC8100
/* BC83E8 80240588 0040202D */   daddu    $a0, $v0, $zero
.L8024058C:
/* BC83EC 8024058C AE220074 */  sw        $v0, 0x74($s1)
.L80240590:
/* BC83F0 80240590 8FBF0024 */  lw        $ra, 0x24($sp)
/* BC83F4 80240594 8FB40020 */  lw        $s4, 0x20($sp)
/* BC83F8 80240598 8FB3001C */  lw        $s3, 0x1c($sp)
/* BC83FC 8024059C 8FB20018 */  lw        $s2, 0x18($sp)
/* BC8400 802405A0 8FB10014 */  lw        $s1, 0x14($sp)
/* BC8404 802405A4 8FB00010 */  lw        $s0, 0x10($sp)
/* BC8408 802405A8 24020002 */  addiu     $v0, $zero, 2
/* BC840C 802405AC 03E00008 */  jr        $ra
/* BC8410 802405B0 27BD0028 */   addiu    $sp, $sp, 0x28
