.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata
dlabel D_8023CD50_6F5E30
.double 47.0

dlabel D_8023CD58_6F5E38
.double 1.12

dlabel D_8023CD60_6F5E40
.double 0.53

dlabel D_8023CD68_6F5E48
.double 47.0

dlabel D_8023CD70_6F5E50
.double 0.8

dlabel D_8023CD78_6F5E58
.double 0.53

dlabel D_8023CD80_6F5E60
.double 0.8

dlabel D_8023CD88_6F5E68
.double 16.5

dlabel D_8023CD90_6F5E70
.double 33.0, 0.0

.section .text

glabel func_8023817C_6F125C
/* 6F125C 8023817C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 6F1260 80238180 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6F1264 80238184 0080982D */  daddu     $s3, $a0, $zero
/* 6F1268 80238188 AFB40020 */  sw        $s4, 0x20($sp)
/* 6F126C 8023818C 3C14800E */  lui       $s4, %hi(gBattleStatus)
/* 6F1270 80238190 2694C070 */  addiu     $s4, $s4, %lo(gBattleStatus)
/* 6F1274 80238194 AFBF0024 */  sw        $ra, 0x24($sp)
/* 6F1278 80238198 AFB20018 */  sw        $s2, 0x18($sp)
/* 6F127C 8023819C AFB10014 */  sw        $s1, 0x14($sp)
/* 6F1280 802381A0 AFB00010 */  sw        $s0, 0x10($sp)
/* 6F1284 802381A4 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 6F1288 802381A8 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 6F128C 802381AC F7B60030 */  sdc1      $f22, 0x30($sp)
/* 6F1290 802381B0 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 6F1294 802381B4 8E9200DC */  lw        $s2, 0xdc($s4)
/* 6F1298 802381B8 8E71000C */  lw        $s1, 0xc($s3)
/* 6F129C 802381BC 10A00010 */  beqz      $a1, .L80238200
/* 6F12A0 802381C0 2650000C */   addiu    $s0, $s2, 0xc
/* 6F12A4 802381C4 8E250000 */  lw        $a1, ($s1)
/* 6F12A8 802381C8 0C0B1EAF */  jal       evt_get_variable
/* 6F12AC 802381CC 26310004 */   addiu    $s1, $s1, 4
/* 6F12B0 802381D0 A6420070 */  sh        $v0, 0x70($s2)
/* 6F12B4 802381D4 8E250000 */  lw        $a1, ($s1)
/* 6F12B8 802381D8 0C0B1EAF */  jal       evt_get_variable
/* 6F12BC 802381DC 0260202D */   daddu    $a0, $s3, $zero
/* 6F12C0 802381E0 A6420072 */  sh        $v0, 0x72($s2)
/* 6F12C4 802381E4 AE600074 */  sw        $zero, 0x74($s3)
/* 6F12C8 802381E8 AE600070 */  sw        $zero, 0x70($s3)
/* 6F12CC 802381EC 86430072 */  lh        $v1, 0x72($s2)
/* 6F12D0 802381F0 24020001 */  addiu     $v0, $zero, 1
/* 6F12D4 802381F4 14620002 */  bne       $v1, $v0, .L80238200
/* 6F12D8 802381F8 24020002 */   addiu    $v0, $zero, 2
/* 6F12DC 802381FC AE620070 */  sw        $v0, 0x70($s3)
.L80238200:
/* 6F12E0 80238200 8E620070 */  lw        $v0, 0x70($s3)
/* 6F12E4 80238204 144000F5 */  bnez      $v0, .L802385DC
/* 6F12E8 80238208 00000000 */   nop
/* 6F12EC 8023820C C6400144 */  lwc1      $f0, 0x144($s2)
/* 6F12F0 80238210 C618000C */  lwc1      $f24, 0xc($s0)
/* 6F12F4 80238214 C61A0014 */  lwc1      $f26, 0x14($s0)
/* 6F12F8 80238218 E6000000 */  swc1      $f0, ($s0)
/* 6F12FC 8023821C C6400148 */  lwc1      $f0, 0x148($s2)
/* 6F1300 80238220 4406C000 */  mfc1      $a2, $f24
/* 6F1304 80238224 4407D000 */  mfc1      $a3, $f26
/* 6F1308 80238228 C6160000 */  lwc1      $f22, ($s0)
/* 6F130C 8023822C E6000004 */  swc1      $f0, 4($s0)
/* 6F1310 80238230 C654014C */  lwc1      $f20, 0x14c($s2)
/* 6F1314 80238234 4600B306 */  mov.s     $f12, $f22
/* 6F1318 80238238 4600A386 */  mov.s     $f14, $f20
/* 6F131C 8023823C 0C00A720 */  jal       atan2
/* 6F1320 80238240 E6140008 */   swc1     $f20, 8($s0)
/* 6F1324 80238244 4600B306 */  mov.s     $f12, $f22
/* 6F1328 80238248 4406C000 */  mfc1      $a2, $f24
/* 6F132C 8023824C 4407D000 */  mfc1      $a3, $f26
/* 6F1330 80238250 4600A386 */  mov.s     $f14, $f20
/* 6F1334 80238254 0C00A7B5 */  jal       dist2D
/* 6F1338 80238258 E6000048 */   swc1     $f0, 0x48($s0)
/* 6F133C 8023825C 86020064 */  lh        $v0, 0x64($s0)
/* 6F1340 80238260 46000106 */  mov.s     $f4, $f0
/* 6F1344 80238264 14400012 */  bnez      $v0, .L802382B0
/* 6F1348 80238268 E604004C */   swc1     $f4, 0x4c($s0)
/* 6F134C 8023826C C6000040 */  lwc1      $f0, 0x40($s0)
/* 6F1350 80238270 C6020040 */  lwc1      $f2, 0x40($s0)
/* 6F1354 80238274 46002003 */  div.s     $f0, $f4, $f0
/* 6F1358 80238278 4600028D */  trunc.w.s $f10, $f0
/* 6F135C 8023827C 44035000 */  mfc1      $v1, $f10
/* 6F1360 80238280 00000000 */  nop
/* 6F1364 80238284 00031400 */  sll       $v0, $v1, 0x10
/* 6F1368 80238288 00021403 */  sra       $v0, $v0, 0x10
/* 6F136C 8023828C 44820000 */  mtc1      $v0, $f0
/* 6F1370 80238290 00000000 */  nop
/* 6F1374 80238294 46800020 */  cvt.s.w   $f0, $f0
/* 6F1378 80238298 46020002 */  mul.s     $f0, $f0, $f2
/* 6F137C 8023829C 00000000 */  nop
/* 6F1380 802382A0 46002086 */  mov.s     $f2, $f4
/* 6F1384 802382A4 A6030064 */  sh        $v1, 0x64($s0)
/* 6F1388 802382A8 0808E0B9 */  j         .L802382E4
/* 6F138C 802382AC 46001201 */   sub.s    $f8, $f2, $f0
.L802382B0:
/* 6F1390 802382B0 44821000 */  mtc1      $v0, $f2
/* 6F1394 802382B4 00000000 */  nop
/* 6F1398 802382B8 468010A0 */  cvt.s.w   $f2, $f2
/* 6F139C 802382BC 86020064 */  lh        $v0, 0x64($s0)
/* 6F13A0 802382C0 46022083 */  div.s     $f2, $f4, $f2
/* 6F13A4 802382C4 44820000 */  mtc1      $v0, $f0
/* 6F13A8 802382C8 00000000 */  nop
/* 6F13AC 802382CC 46800020 */  cvt.s.w   $f0, $f0
/* 6F13B0 802382D0 46020002 */  mul.s     $f0, $f0, $f2
/* 6F13B4 802382D4 00000000 */  nop
/* 6F13B8 802382D8 C604004C */  lwc1      $f4, 0x4c($s0)
/* 6F13BC 802382DC E6020040 */  swc1      $f2, 0x40($s0)
/* 6F13C0 802382E0 46002201 */  sub.s     $f8, $f4, $f0
.L802382E4:
/* 6F13C4 802382E4 86030064 */  lh        $v1, 0x64($s0)
/* 6F13C8 802382E8 106001C1 */  beqz      $v1, .L802389F0
/* 6F13CC 802382EC 24020002 */   addiu    $v0, $zero, 2
/* 6F13D0 802382F0 86020064 */  lh        $v0, 0x64($s0)
/* 6F13D4 802382F4 C602000C */  lwc1      $f2, 0xc($s0)
/* 6F13D8 802382F8 3C014049 */  lui       $at, 0x4049
/* 6F13DC 802382FC 34210FD0 */  ori       $at, $at, 0xfd0
/* 6F13E0 80238300 44810000 */  mtc1      $at, $f0
/* 6F13E4 80238304 C6040000 */  lwc1      $f4, ($s0)
/* 6F13E8 80238308 44823000 */  mtc1      $v0, $f6
/* 6F13EC 8023830C 00000000 */  nop
/* 6F13F0 80238310 468031A0 */  cvt.s.w   $f6, $f6
/* 6F13F4 80238314 46060003 */  div.s     $f0, $f0, $f6
/* 6F13F8 80238318 46041081 */  sub.s     $f2, $f2, $f4
/* 6F13FC 8023831C E600003C */  swc1      $f0, 0x3c($s0)
/* 6F1400 80238320 44830000 */  mtc1      $v1, $f0
/* 6F1404 80238324 00000000 */  nop
/* 6F1408 80238328 46800020 */  cvt.s.w   $f0, $f0
/* 6F140C 8023832C 46001083 */  div.s     $f2, $f2, $f0
/* 6F1410 80238330 C6000010 */  lwc1      $f0, 0x10($s0)
/* 6F1414 80238334 E6020030 */  swc1      $f2, 0x30($s0)
/* 6F1418 80238338 C6020004 */  lwc1      $f2, 4($s0)
/* 6F141C 8023833C AE000044 */  sw        $zero, 0x44($s0)
/* 6F1420 80238340 46020001 */  sub.s     $f0, $f0, $f2
/* 6F1424 80238344 C6040014 */  lwc1      $f4, 0x14($s0)
/* 6F1428 80238348 46003086 */  mov.s     $f2, $f6
/* 6F142C 8023834C 46020003 */  div.s     $f0, $f0, $f2
/* 6F1430 80238350 E6000034 */  swc1      $f0, 0x34($s0)
/* 6F1434 80238354 46003006 */  mov.s     $f0, $f6
/* 6F1438 80238358 46004003 */  div.s     $f0, $f8, $f0
/* 6F143C 8023835C C6020008 */  lwc1      $f2, 8($s0)
/* 6F1440 80238360 86020066 */  lh        $v0, 0x66($s0)
/* 6F1444 80238364 46022101 */  sub.s     $f4, $f4, $f2
/* 6F1448 80238368 C6020040 */  lwc1      $f2, 0x40($s0)
/* 6F144C 8023836C 28420003 */  slti      $v0, $v0, 3
/* 6F1450 80238370 46001080 */  add.s     $f2, $f2, $f0
/* 6F1454 80238374 46062103 */  div.s     $f4, $f4, $f6
/* 6F1458 80238378 E6040038 */  swc1      $f4, 0x38($s0)
/* 6F145C 8023837C 10400045 */  beqz      $v0, .L80238494
/* 6F1460 80238380 E6020040 */   swc1     $f2, 0x40($s0)
/* 6F1464 80238384 86020064 */  lh        $v0, 0x64($s0)
/* 6F1468 80238388 24030168 */  addiu     $v1, $zero, 0x168
/* 6F146C 8023838C 14400002 */  bnez      $v0, .L80238398
/* 6F1470 80238390 0062001A */   div      $zero, $v1, $v0
/* 6F1474 80238394 0007000D */  break     7
.L80238398:
/* 6F1478 80238398 2401FFFF */   addiu    $at, $zero, -1
/* 6F147C 8023839C 14410004 */  bne       $v0, $at, .L802383B0
/* 6F1480 802383A0 3C018000 */   lui      $at, 0x8000
/* 6F1484 802383A4 14610002 */  bne       $v1, $at, .L802383B0
/* 6F1488 802383A8 00000000 */   nop
/* 6F148C 802383AC 0006000D */  break     6
.L802383B0:
/* 6F1490 802383B0 00001812 */   mflo     $v1
/* 6F1494 802383B4 C608004C */  lwc1      $f8, 0x4c($s0)
/* 6F1498 802383B8 3C014034 */  lui       $at, 0x4034
/* 6F149C 802383BC 44811800 */  mtc1      $at, $f3
/* 6F14A0 802383C0 44801000 */  mtc1      $zero, $f2
/* 6F14A4 802383C4 46004021 */  cvt.d.s   $f0, $f8
/* 6F14A8 802383C8 46220001 */  sub.d     $f0, $f0, $f2
/* 6F14AC 802383CC 3C014018 */  lui       $at, 0x4018
/* 6F14B0 802383D0 44811800 */  mtc1      $at, $f3
/* 6F14B4 802383D4 44801000 */  mtc1      $zero, $f2
/* 6F14B8 802383D8 46200220 */  cvt.s.d   $f8, $f0
/* 6F14BC 802383DC 46004021 */  cvt.d.s   $f0, $f8
/* 6F14C0 802383E0 46220003 */  div.d     $f0, $f0, $f2
/* 6F14C4 802383E4 46200220 */  cvt.s.d   $f8, $f0
/* 6F14C8 802383E8 3C018024 */  lui       $at, %hi(D_8023CD50_6F5E30)
/* 6F14CC 802383EC D422CD50 */  ldc1      $f2, %lo(D_8023CD50_6F5E30)($at)
/* 6F14D0 802383F0 46004021 */  cvt.d.s   $f0, $f8
/* 6F14D4 802383F4 46220000 */  add.d     $f0, $f0, $f2
/* 6F14D8 802383F8 3C0142B4 */  lui       $at, 0x42b4
/* 6F14DC 802383FC 44811000 */  mtc1      $at, $f2
/* 6F14E0 80238400 46200220 */  cvt.s.d   $f8, $f0
/* 6F14E4 80238404 44830000 */  mtc1      $v1, $f0
/* 6F14E8 80238408 00000000 */  nop
/* 6F14EC 8023840C 46800020 */  cvt.s.w   $f0, $f0
/* 6F14F0 80238410 86030066 */  lh        $v1, 0x66($s0)
/* 6F14F4 80238414 24020002 */  addiu     $v0, $zero, 2
/* 6F14F8 80238418 E6020024 */  swc1      $f2, 0x24($s0)
/* 6F14FC 8023841C E6080050 */  swc1      $f8, 0x50($s0)
/* 6F1500 80238420 14620008 */  bne       $v1, $v0, .L80238444
/* 6F1504 80238424 E6000028 */   swc1     $f0, 0x28($s0)
/* 6F1508 80238428 3C018024 */  lui       $at, %hi(D_8023CD58_6F5E38)
/* 6F150C 8023842C D422CD58 */  ldc1      $f2, %lo(D_8023CD58_6F5E38)($at)
/* 6F1510 80238430 46004021 */  cvt.d.s   $f0, $f8
/* 6F1514 80238434 46220002 */  mul.d     $f0, $f0, $f2
/* 6F1518 80238438 00000000 */  nop
/* 6F151C 8023843C 46200020 */  cvt.s.d   $f0, $f0
/* 6F1520 80238440 E6000050 */  swc1      $f0, 0x50($s0)
.L80238444:
/* 6F1524 80238444 C60C0024 */  lwc1      $f12, 0x24($s0)
/* 6F1528 80238448 3C0140C9 */  lui       $at, 0x40c9
/* 6F152C 8023844C 34210FD0 */  ori       $at, $at, 0xfd0
/* 6F1530 80238450 44810000 */  mtc1      $at, $f0
/* 6F1534 80238454 C6140044 */  lwc1      $f20, 0x44($s0)
/* 6F1538 80238458 C616003C */  lwc1      $f22, 0x3c($s0)
/* 6F153C 8023845C AE000018 */  sw        $zero, 0x18($s0)
/* 6F1540 80238460 46006302 */  mul.s     $f12, $f12, $f0
/* 6F1544 80238464 00000000 */  nop
/* 6F1548 80238468 AE00001C */  sw        $zero, 0x1c($s0)
/* 6F154C 8023846C 4600A521 */  cvt.d.s   $f20, $f20
/* 6F1550 80238470 3C0143B4 */  lui       $at, 0x43b4
/* 6F1554 80238474 44810000 */  mtc1      $at, $f0
/* 6F1558 80238478 4600B5A1 */  cvt.d.s   $f22, $f22
/* 6F155C 8023847C 0C00A85B */  jal       sin_rad
/* 6F1560 80238480 46006303 */   div.s    $f12, $f12, $f0
/* 6F1564 80238484 3C018024 */  lui       $at, %hi(D_8023CD60_6F5E40)
/* 6F1568 80238488 D422CD60 */  ldc1      $f2, %lo(D_8023CD60_6F5E40)($at)
/* 6F156C 8023848C 0808E169 */  j         .L802385A4
/* 6F1570 80238490 46000021 */   cvt.d.s  $f0, $f0
.L80238494:
/* 6F1574 80238494 86020064 */  lh        $v0, 0x64($s0)
/* 6F1578 80238498 24030168 */  addiu     $v1, $zero, 0x168
/* 6F157C 8023849C 14400002 */  bnez      $v0, .L802384A8
/* 6F1580 802384A0 0062001A */   div      $zero, $v1, $v0
/* 6F1584 802384A4 0007000D */  break     7
.L802384A8:
/* 6F1588 802384A8 2401FFFF */   addiu    $at, $zero, -1
/* 6F158C 802384AC 14410004 */  bne       $v0, $at, .L802384C0
/* 6F1590 802384B0 3C018000 */   lui      $at, 0x8000
/* 6F1594 802384B4 14610002 */  bne       $v1, $at, .L802384C0
/* 6F1598 802384B8 00000000 */   nop
/* 6F159C 802384BC 0006000D */  break     6
.L802384C0:
/* 6F15A0 802384C0 00001812 */   mflo     $v1
/* 6F15A4 802384C4 C608004C */  lwc1      $f8, 0x4c($s0)
/* 6F15A8 802384C8 3C014034 */  lui       $at, 0x4034
/* 6F15AC 802384CC 44811800 */  mtc1      $at, $f3
/* 6F15B0 802384D0 44801000 */  mtc1      $zero, $f2
/* 6F15B4 802384D4 46004021 */  cvt.d.s   $f0, $f8
/* 6F15B8 802384D8 46220001 */  sub.d     $f0, $f0, $f2
/* 6F15BC 802384DC 3C014018 */  lui       $at, 0x4018
/* 6F15C0 802384E0 44811800 */  mtc1      $at, $f3
/* 6F15C4 802384E4 44801000 */  mtc1      $zero, $f2
/* 6F15C8 802384E8 46200220 */  cvt.s.d   $f8, $f0
/* 6F15CC 802384EC 46004021 */  cvt.d.s   $f0, $f8
/* 6F15D0 802384F0 46220003 */  div.d     $f0, $f0, $f2
/* 6F15D4 802384F4 46200220 */  cvt.s.d   $f8, $f0
/* 6F15D8 802384F8 3C018024 */  lui       $at, %hi(D_8023CD68_6F5E48)
/* 6F15DC 802384FC D422CD68 */  ldc1      $f2, %lo(D_8023CD68_6F5E48)($at)
/* 6F15E0 80238500 46004021 */  cvt.d.s   $f0, $f8
/* 6F15E4 80238504 46220000 */  add.d     $f0, $f0, $f2
/* 6F15E8 80238508 3C0142B4 */  lui       $at, 0x42b4
/* 6F15EC 8023850C 44811000 */  mtc1      $at, $f2
/* 6F15F0 80238510 46200220 */  cvt.s.d   $f8, $f0
/* 6F15F4 80238514 44830000 */  mtc1      $v1, $f0
/* 6F15F8 80238518 00000000 */  nop
/* 6F15FC 8023851C 46800020 */  cvt.s.w   $f0, $f0
/* 6F1600 80238520 86030066 */  lh        $v1, 0x66($s0)
/* 6F1604 80238524 24020004 */  addiu     $v0, $zero, 4
/* 6F1608 80238528 E6020024 */  swc1      $f2, 0x24($s0)
/* 6F160C 8023852C E6080050 */  swc1      $f8, 0x50($s0)
/* 6F1610 80238530 14620009 */  bne       $v1, $v0, .L80238558
/* 6F1614 80238534 E6000028 */   swc1     $f0, 0x28($s0)
/* 6F1618 80238538 3C013FF4 */  lui       $at, 0x3ff4
/* 6F161C 8023853C 44811800 */  mtc1      $at, $f3
/* 6F1620 80238540 44801000 */  mtc1      $zero, $f2
/* 6F1624 80238544 46004021 */  cvt.d.s   $f0, $f8
/* 6F1628 80238548 46220002 */  mul.d     $f0, $f0, $f2
/* 6F162C 8023854C 00000000 */  nop
/* 6F1630 80238550 46200020 */  cvt.s.d   $f0, $f0
/* 6F1634 80238554 E6000050 */  swc1      $f0, 0x50($s0)
.L80238558:
/* 6F1638 80238558 C60C0024 */  lwc1      $f12, 0x24($s0)
/* 6F163C 8023855C 3C0140C9 */  lui       $at, 0x40c9
/* 6F1640 80238560 34210FD0 */  ori       $at, $at, 0xfd0
/* 6F1644 80238564 44810000 */  mtc1      $at, $f0
/* 6F1648 80238568 C6140044 */  lwc1      $f20, 0x44($s0)
/* 6F164C 8023856C C616003C */  lwc1      $f22, 0x3c($s0)
/* 6F1650 80238570 AE000018 */  sw        $zero, 0x18($s0)
/* 6F1654 80238574 46006302 */  mul.s     $f12, $f12, $f0
/* 6F1658 80238578 00000000 */  nop
/* 6F165C 8023857C AE00001C */  sw        $zero, 0x1c($s0)
/* 6F1660 80238580 4600A521 */  cvt.d.s   $f20, $f20
/* 6F1664 80238584 3C0143B4 */  lui       $at, 0x43b4
/* 6F1668 80238588 44810000 */  mtc1      $at, $f0
/* 6F166C 8023858C 4600B5A1 */  cvt.d.s   $f22, $f22
/* 6F1670 80238590 0C00A85B */  jal       sin_rad
/* 6F1674 80238594 46006303 */   div.s    $f12, $f12, $f0
/* 6F1678 80238598 3C018024 */  lui       $at, %hi(D_8023CD70_6F5E50)
/* 6F167C 8023859C D422CD70 */  ldc1      $f2, %lo(D_8023CD70_6F5E50)($at)
/* 6F1680 802385A0 46000021 */  cvt.d.s   $f0, $f0
.L802385A4:
/* 6F1684 802385A4 46220002 */  mul.d     $f0, $f0, $f2
/* 6F1688 802385A8 00000000 */  nop
/* 6F168C 802385AC 46360002 */  mul.d     $f0, $f0, $f22
/* 6F1690 802385B0 00000000 */  nop
/* 6F1694 802385B4 46360000 */  add.d     $f0, $f0, $f22
/* 6F1698 802385B8 4620A500 */  add.d     $f20, $f20, $f0
/* 6F169C 802385BC 4620A520 */  cvt.s.d   $f20, $f20
/* 6F16A0 802385C0 E6140044 */  swc1      $f20, 0x44($s0)
/* 6F16A4 802385C4 24040100 */  addiu     $a0, $zero, 0x100
/* 6F16A8 802385C8 8E060058 */  lw        $a2, 0x58($s0)
/* 6F16AC 802385CC 0C098F3F */  jal       set_animation
/* 6F16B0 802385D0 24050001 */   addiu    $a1, $zero, 1
/* 6F16B4 802385D4 24020001 */  addiu     $v0, $zero, 1
/* 6F16B8 802385D8 AE620070 */  sw        $v0, 0x70($s3)
.L802385DC:
/* 6F16BC 802385DC 8E630070 */  lw        $v1, 0x70($s3)
/* 6F16C0 802385E0 24020002 */  addiu     $v0, $zero, 2
/* 6F16C4 802385E4 10620094 */  beq       $v1, $v0, .L80238838
/* 6F16C8 802385E8 28620003 */   slti     $v0, $v1, 3
/* 6F16CC 802385EC 10400005 */  beqz      $v0, .L80238604
/* 6F16D0 802385F0 24020001 */   addiu    $v0, $zero, 1
/* 6F16D4 802385F4 10620008 */  beq       $v1, $v0, .L80238618
/* 6F16D8 802385F8 0000102D */   daddu    $v0, $zero, $zero
/* 6F16DC 802385FC 0808E27C */  j         .L802389F0
/* 6F16E0 80238600 00000000 */   nop
.L80238604:
/* 6F16E4 80238604 24020003 */  addiu     $v0, $zero, 3
/* 6F16E8 80238608 106200BD */  beq       $v1, $v0, .L80238900
/* 6F16EC 8023860C 0000102D */   daddu    $v0, $zero, $zero
/* 6F16F0 80238610 0808E27C */  j         .L802389F0
/* 6F16F4 80238614 00000000 */   nop
.L80238618:
/* 6F16F8 80238618 C6020044 */  lwc1      $f2, 0x44($s0)
/* 6F16FC 8023861C 3C013FC9 */  lui       $at, 0x3fc9
/* 6F1700 80238620 34210FD0 */  ori       $at, $at, 0xfd0
/* 6F1704 80238624 44810000 */  mtc1      $at, $f0
/* 6F1708 80238628 00000000 */  nop
/* 6F170C 8023862C 4602003C */  c.lt.s    $f0, $f2
/* 6F1710 80238630 00000000 */  nop
/* 6F1714 80238634 45000004 */  bc1f      .L80238648
/* 6F1718 80238638 24040100 */   addiu    $a0, $zero, 0x100
/* 6F171C 8023863C 8E06005C */  lw        $a2, 0x5c($s0)
/* 6F1720 80238640 0C098F3F */  jal       set_animation
/* 6F1724 80238644 24050001 */   addiu    $a1, $zero, 1
.L80238648:
/* 6F1728 80238648 C6060000 */  lwc1      $f6, ($s0)
/* 6F172C 8023864C C6000030 */  lwc1      $f0, 0x30($s0)
/* 6F1730 80238650 C6040004 */  lwc1      $f4, 4($s0)
/* 6F1734 80238654 C6560144 */  lwc1      $f22, 0x144($s2)
/* 6F1738 80238658 46003180 */  add.s     $f6, $f6, $f0
/* 6F173C 8023865C C6000034 */  lwc1      $f0, 0x34($s0)
/* 6F1740 80238660 C6020038 */  lwc1      $f2, 0x38($s0)
/* 6F1744 80238664 46002100 */  add.s     $f4, $f4, $f0
/* 6F1748 80238668 C6000008 */  lwc1      $f0, 8($s0)
/* 6F174C 8023866C C6540148 */  lwc1      $f20, 0x148($s2)
/* 6F1750 80238670 46020000 */  add.s     $f0, $f0, $f2
/* 6F1754 80238674 E6060000 */  swc1      $f6, ($s0)
/* 6F1758 80238678 E6040004 */  swc1      $f4, 4($s0)
/* 6F175C 8023867C E6000008 */  swc1      $f0, 8($s0)
/* 6F1760 80238680 C6400148 */  lwc1      $f0, 0x148($s2)
/* 6F1764 80238684 46003086 */  mov.s     $f2, $f6
/* 6F1768 80238688 E6000018 */  swc1      $f0, 0x18($s0)
/* 6F176C 8023868C E6420144 */  swc1      $f2, 0x144($s2)
/* 6F1770 80238690 0C00A85B */  jal       sin_rad
/* 6F1774 80238694 C60C0044 */   lwc1     $f12, 0x44($s0)
/* 6F1778 80238698 C6020050 */  lwc1      $f2, 0x50($s0)
/* 6F177C 8023869C 46001082 */  mul.s     $f2, $f2, $f0
/* 6F1780 802386A0 00000000 */  nop
/* 6F1784 802386A4 C6000004 */  lwc1      $f0, 4($s0)
/* 6F1788 802386A8 46020000 */  add.s     $f0, $f0, $f2
/* 6F178C 802386AC E6400148 */  swc1      $f0, 0x148($s2)
/* 6F1790 802386B0 C6000008 */  lwc1      $f0, 8($s0)
/* 6F1794 802386B4 E640014C */  swc1      $f0, 0x14c($s2)
/* 6F1798 802386B8 C6020010 */  lwc1      $f2, 0x10($s0)
/* 6F179C 802386BC C6400148 */  lwc1      $f0, 0x148($s2)
/* 6F17A0 802386C0 4602003C */  c.lt.s    $f0, $f2
/* 6F17A4 802386C4 00000000 */  nop
/* 6F17A8 802386C8 45000007 */  bc1f      .L802386E8
/* 6F17AC 802386CC 4600B306 */   mov.s    $f12, $f22
/* 6F17B0 802386D0 86020064 */  lh        $v0, 0x64($s0)
/* 6F17B4 802386D4 28420003 */  slti      $v0, $v0, 3
/* 6F17B8 802386D8 54400002 */  bnel      $v0, $zero, .L802386E4
/* 6F17BC 802386DC E6420148 */   swc1     $f2, 0x148($s2)
/* 6F17C0 802386E0 4600B306 */  mov.s     $f12, $f22
.L802386E4:
/* 6F17C4 802386E4 C6400148 */  lwc1      $f0, 0x148($s2)
.L802386E8:
/* 6F17C8 802386E8 8E460144 */  lw        $a2, 0x144($s2)
/* 6F17CC 802386EC 46000007 */  neg.s     $f0, $f0
/* 6F17D0 802386F0 44070000 */  mfc1      $a3, $f0
/* 6F17D4 802386F4 0C00A720 */  jal       atan2
/* 6F17D8 802386F8 4600A387 */   neg.s    $f14, $f20
/* 6F17DC 802386FC 46000007 */  neg.s     $f0, $f0
/* 6F17E0 80238700 E6400164 */  swc1      $f0, 0x164($s2)
/* 6F17E4 80238704 86020066 */  lh        $v0, 0x66($s0)
/* 6F17E8 80238708 C6400148 */  lwc1      $f0, 0x148($s2)
/* 6F17EC 8023870C 28420003 */  slti      $v0, $v0, 3
/* 6F17F0 80238710 10400013 */  beqz      $v0, .L80238760
/* 6F17F4 80238714 E600001C */   swc1     $f0, 0x1c($s0)
/* 6F17F8 80238718 C60C0024 */  lwc1      $f12, 0x24($s0)
/* 6F17FC 8023871C 3C0140C9 */  lui       $at, 0x40c9
/* 6F1800 80238720 34210FD0 */  ori       $at, $at, 0xfd0
/* 6F1804 80238724 44810000 */  mtc1      $at, $f0
/* 6F1808 80238728 C6140044 */  lwc1      $f20, 0x44($s0)
/* 6F180C 8023872C 46006302 */  mul.s     $f12, $f12, $f0
/* 6F1810 80238730 00000000 */  nop
/* 6F1814 80238734 C616003C */  lwc1      $f22, 0x3c($s0)
/* 6F1818 80238738 4600A521 */  cvt.d.s   $f20, $f20
/* 6F181C 8023873C 3C0143B4 */  lui       $at, 0x43b4
/* 6F1820 80238740 44810000 */  mtc1      $at, $f0
/* 6F1824 80238744 4600B5A1 */  cvt.d.s   $f22, $f22
/* 6F1828 80238748 0C00A85B */  jal       sin_rad
/* 6F182C 8023874C 46006303 */   div.s    $f12, $f12, $f0
/* 6F1830 80238750 3C018024 */  lui       $at, %hi(D_8023CD78_6F5E58)
/* 6F1834 80238754 D422CD78 */  ldc1      $f2, %lo(D_8023CD78_6F5E58)($at)
/* 6F1838 80238758 0808E1E9 */  j         .L802387A4
/* 6F183C 8023875C 46000021 */   cvt.d.s  $f0, $f0
.L80238760:
/* 6F1840 80238760 C60C0024 */  lwc1      $f12, 0x24($s0)
/* 6F1844 80238764 3C0140C9 */  lui       $at, 0x40c9
/* 6F1848 80238768 34210FD0 */  ori       $at, $at, 0xfd0
/* 6F184C 8023876C 44810000 */  mtc1      $at, $f0
/* 6F1850 80238770 C6140044 */  lwc1      $f20, 0x44($s0)
/* 6F1854 80238774 46006302 */  mul.s     $f12, $f12, $f0
/* 6F1858 80238778 00000000 */  nop
/* 6F185C 8023877C C616003C */  lwc1      $f22, 0x3c($s0)
/* 6F1860 80238780 4600A521 */  cvt.d.s   $f20, $f20
/* 6F1864 80238784 3C0143B4 */  lui       $at, 0x43b4
/* 6F1868 80238788 44810000 */  mtc1      $at, $f0
/* 6F186C 8023878C 4600B5A1 */  cvt.d.s   $f22, $f22
/* 6F1870 80238790 0C00A85B */  jal       sin_rad
/* 6F1874 80238794 46006303 */   div.s    $f12, $f12, $f0
/* 6F1878 80238798 3C018024 */  lui       $at, %hi(D_8023CD80_6F5E60)
/* 6F187C 8023879C D422CD80 */  ldc1      $f2, %lo(D_8023CD80_6F5E60)($at)
/* 6F1880 802387A0 46000021 */  cvt.d.s   $f0, $f0
.L802387A4:
/* 6F1884 802387A4 46220002 */  mul.d     $f0, $f0, $f2
/* 6F1888 802387A8 00000000 */  nop
/* 6F188C 802387AC 46360002 */  mul.d     $f0, $f0, $f22
/* 6F1890 802387B0 00000000 */  nop
/* 6F1894 802387B4 46360000 */  add.d     $f0, $f0, $f22
/* 6F1898 802387B8 4620A500 */  add.d     $f20, $f20, $f0
/* 6F189C 802387BC 4620A520 */  cvt.s.d   $f20, $f20
/* 6F18A0 802387C0 E6140044 */  swc1      $f20, 0x44($s0)
/* 6F18A4 802387C4 C60C0024 */  lwc1      $f12, 0x24($s0)
/* 6F18A8 802387C8 C6000028 */  lwc1      $f0, 0x28($s0)
/* 6F18AC 802387CC 46006300 */  add.s     $f12, $f12, $f0
/* 6F18B0 802387D0 0C00A6C9 */  jal       clamp_angle
/* 6F18B4 802387D4 E60C0024 */   swc1     $f12, 0x24($s0)
/* 6F18B8 802387D8 96020064 */  lhu       $v0, 0x64($s0)
/* 6F18BC 802387DC E6000024 */  swc1      $f0, 0x24($s0)
/* 6F18C0 802387E0 2442FFFF */  addiu     $v0, $v0, -1
/* 6F18C4 802387E4 A6020064 */  sh        $v0, 0x64($s0)
/* 6F18C8 802387E8 00021400 */  sll       $v0, $v0, 0x10
/* 6F18CC 802387EC 14400080 */  bnez      $v0, .L802389F0
/* 6F18D0 802387F0 0000102D */   daddu    $v0, $zero, $zero
/* 6F18D4 802387F4 C6000010 */  lwc1      $f0, 0x10($s0)
/* 6F18D8 802387F8 24040100 */  addiu     $a0, $zero, 0x100
/* 6F18DC 802387FC E6400148 */  swc1      $f0, 0x148($s2)
/* 6F18E0 80238800 C6000018 */  lwc1      $f0, 0x18($s0)
/* 6F18E4 80238804 C602001C */  lwc1      $f2, 0x1c($s0)
/* 6F18E8 80238808 8E060060 */  lw        $a2, 0x60($s0)
/* 6F18EC 8023880C 46020001 */  sub.s     $f0, $f0, $f2
/* 6F18F0 80238810 3C013FE6 */  lui       $at, 0x3fe6
/* 6F18F4 80238814 34216666 */  ori       $at, $at, 0x6666
/* 6F18F8 80238818 44811000 */  mtc1      $at, $f2
/* 6F18FC 8023881C 24050001 */  addiu     $a1, $zero, 1
/* 6F1900 80238820 E602003C */  swc1      $f2, 0x3c($s0)
/* 6F1904 80238824 46000007 */  neg.s     $f0, $f0
/* 6F1908 80238828 0C098F3F */  jal       set_animation
/* 6F190C 8023882C E6000044 */   swc1     $f0, 0x44($s0)
/* 6F1910 80238830 0808E27C */  j         .L802389F0
/* 6F1914 80238834 24020001 */   addiu    $v0, $zero, 1
.L80238838:
/* 6F1918 80238838 82820083 */  lb        $v0, 0x83($s4)
/* 6F191C 8023883C 10400063 */  beqz      $v0, .L802389CC
/* 6F1920 80238840 24020001 */   addiu    $v0, $zero, 1
/* 6F1924 80238844 A6020064 */  sh        $v0, 0x64($s0)
/* 6F1928 80238848 86020064 */  lh        $v0, 0x64($s0)
/* 6F192C 8023884C 24030168 */  addiu     $v1, $zero, 0x168
/* 6F1930 80238850 14400002 */  bnez      $v0, .L8023885C
/* 6F1934 80238854 0062001A */   div      $zero, $v1, $v0
/* 6F1938 80238858 0007000D */  break     7
.L8023885C:
/* 6F193C 8023885C 2401FFFF */   addiu    $at, $zero, -1
/* 6F1940 80238860 14410004 */  bne       $v0, $at, .L80238874
/* 6F1944 80238864 3C018000 */   lui      $at, 0x8000
/* 6F1948 80238868 14610002 */  bne       $v1, $at, .L80238874
/* 6F194C 8023886C 00000000 */   nop
/* 6F1950 80238870 0006000D */  break     6
.L80238874:
/* 6F1954 80238874 00001812 */   mflo     $v1
/* 6F1958 80238878 C6020018 */  lwc1      $f2, 0x18($s0)
/* 6F195C 8023887C C600001C */  lwc1      $f0, 0x1c($s0)
/* 6F1960 80238880 3C013FE6 */  lui       $at, 0x3fe6
/* 6F1964 80238884 34216666 */  ori       $at, $at, 0x6666
/* 6F1968 80238888 44814000 */  mtc1      $at, $f8
/* 6F196C 8023888C C604001C */  lwc1      $f4, 0x1c($s0)
/* 6F1970 80238890 46001081 */  sub.s     $f2, $f2, $f0
/* 6F1974 80238894 C6000018 */  lwc1      $f0, 0x18($s0)
/* 6F1978 80238898 3C0142B4 */  lui       $at, 0x42b4
/* 6F197C 8023889C 44813000 */  mtc1      $at, $f6
/* 6F1980 802388A0 46040001 */  sub.s     $f0, $f0, $f4
/* 6F1984 802388A4 E608003C */  swc1      $f8, 0x3c($s0)
/* 6F1988 802388A8 E6060024 */  swc1      $f6, 0x24($s0)
/* 6F198C 802388AC 46001087 */  neg.s     $f2, $f2
/* 6F1990 802388B0 E6020044 */  swc1      $f2, 0x44($s0)
/* 6F1994 802388B4 3C018024 */  lui       $at, %hi(D_8023CD88_6F5E68)
/* 6F1998 802388B8 D422CD88 */  ldc1      $f2, %lo(D_8023CD88_6F5E68)($at)
/* 6F199C 802388BC 46000005 */  abs.s     $f0, $f0
/* 6F19A0 802388C0 46000021 */  cvt.d.s   $f0, $f0
/* 6F19A4 802388C4 46220003 */  div.d     $f0, $f0, $f2
/* 6F19A8 802388C8 46200020 */  cvt.s.d   $f0, $f0
/* 6F19AC 802388CC E6000050 */  swc1      $f0, 0x50($s0)
/* 6F19B0 802388D0 44830000 */  mtc1      $v1, $f0
/* 6F19B4 802388D4 00000000 */  nop
/* 6F19B8 802388D8 46800020 */  cvt.s.w   $f0, $f0
/* 6F19BC 802388DC E6000028 */  swc1      $f0, 0x28($s0)
/* 6F19C0 802388E0 C6400144 */  lwc1      $f0, 0x144($s2)
/* 6F19C4 802388E4 E6000000 */  swc1      $f0, ($s0)
/* 6F19C8 802388E8 C6400148 */  lwc1      $f0, 0x148($s2)
/* 6F19CC 802388EC E6000004 */  swc1      $f0, 4($s0)
/* 6F19D0 802388F0 C640014C */  lwc1      $f0, 0x14c($s2)
/* 6F19D4 802388F4 24020003 */  addiu     $v0, $zero, 3
/* 6F19D8 802388F8 E6000008 */  swc1      $f0, 8($s0)
/* 6F19DC 802388FC AE620070 */  sw        $v0, 0x70($s3)
.L80238900:
/* 6F19E0 80238900 C60C0024 */  lwc1      $f12, 0x24($s0)
/* 6F19E4 80238904 3C0140C9 */  lui       $at, 0x40c9
/* 6F19E8 80238908 34210FD0 */  ori       $at, $at, 0xfd0
/* 6F19EC 8023890C 4481B000 */  mtc1      $at, $f22
/* 6F19F0 80238910 00000000 */  nop
/* 6F19F4 80238914 46166302 */  mul.s     $f12, $f12, $f22
/* 6F19F8 80238918 00000000 */  nop
/* 6F19FC 8023891C C6140000 */  lwc1      $f20, ($s0)
/* 6F1A00 80238920 3C0143B4 */  lui       $at, 0x43b4
/* 6F1A04 80238924 4481C000 */  mtc1      $at, $f24
/* 6F1A08 80238928 4600A521 */  cvt.d.s   $f20, $f20
/* 6F1A0C 8023892C 0C00A85B */  jal       sin_rad
/* 6F1A10 80238930 46186303 */   div.s    $f12, $f12, $f24
/* 6F1A14 80238934 C6020050 */  lwc1      $f2, 0x50($s0)
/* 6F1A18 80238938 46001082 */  mul.s     $f2, $f2, $f0
/* 6F1A1C 8023893C 00000000 */  nop
/* 6F1A20 80238940 C60C0024 */  lwc1      $f12, 0x24($s0)
/* 6F1A24 80238944 46166302 */  mul.s     $f12, $f12, $f22
/* 6F1A28 80238948 00000000 */  nop
/* 6F1A2C 8023894C 3C018024 */  lui       $at, %hi(D_8023CD90_6F5E70)
/* 6F1A30 80238950 D420CD90 */  ldc1      $f0, %lo(D_8023CD90_6F5E70)($at)
/* 6F1A34 80238954 460010A1 */  cvt.d.s   $f2, $f2
/* 6F1A38 80238958 46201083 */  div.d     $f2, $f2, $f0
/* 6F1A3C 8023895C 4622A500 */  add.d     $f20, $f20, $f2
/* 6F1A40 80238960 46186303 */  div.s     $f12, $f12, $f24
/* 6F1A44 80238964 4620A520 */  cvt.s.d   $f20, $f20
/* 6F1A48 80238968 0C00A85B */  jal       sin_rad
/* 6F1A4C 8023896C E6140000 */   swc1     $f20, ($s0)
/* 6F1A50 80238970 C6020050 */  lwc1      $f2, 0x50($s0)
/* 6F1A54 80238974 46001082 */  mul.s     $f2, $f2, $f0
/* 6F1A58 80238978 00000000 */  nop
/* 6F1A5C 8023897C C60C0024 */  lwc1      $f12, 0x24($s0)
/* 6F1A60 80238980 C6000028 */  lwc1      $f0, 0x28($s0)
/* 6F1A64 80238984 46006300 */  add.s     $f12, $f12, $f0
/* 6F1A68 80238988 C6000004 */  lwc1      $f0, 4($s0)
/* 6F1A6C 8023898C 46020001 */  sub.s     $f0, $f0, $f2
/* 6F1A70 80238990 E60C0024 */  swc1      $f12, 0x24($s0)
/* 6F1A74 80238994 0C00A6C9 */  jal       clamp_angle
/* 6F1A78 80238998 E6000004 */   swc1     $f0, 4($s0)
/* 6F1A7C 8023899C C6020000 */  lwc1      $f2, ($s0)
/* 6F1A80 802389A0 E6000024 */  swc1      $f0, 0x24($s0)
/* 6F1A84 802389A4 E6420144 */  swc1      $f2, 0x144($s2)
/* 6F1A88 802389A8 C6000004 */  lwc1      $f0, 4($s0)
/* 6F1A8C 802389AC E6400148 */  swc1      $f0, 0x148($s2)
/* 6F1A90 802389B0 C6000008 */  lwc1      $f0, 8($s0)
/* 6F1A94 802389B4 E640014C */  swc1      $f0, 0x14c($s2)
/* 6F1A98 802389B8 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 6F1A9C 802389BC 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 6F1AA0 802389C0 30422000 */  andi      $v0, $v0, 0x2000
/* 6F1AA4 802389C4 10400003 */  beqz      $v0, .L802389D4
/* 6F1AA8 802389C8 00000000 */   nop
.L802389CC:
/* 6F1AAC 802389CC 0808E27C */  j         .L802389F0
/* 6F1AB0 802389D0 24020002 */   addiu    $v0, $zero, 2
.L802389D4:
/* 6F1AB4 802389D4 96030064 */  lhu       $v1, 0x64($s0)
/* 6F1AB8 802389D8 2463FFFF */  addiu     $v1, $v1, -1
/* 6F1ABC 802389DC A6030064 */  sh        $v1, 0x64($s0)
/* 6F1AC0 802389E0 00031C00 */  sll       $v1, $v1, 0x10
/* 6F1AC4 802389E4 10600002 */  beqz      $v1, .L802389F0
/* 6F1AC8 802389E8 24020001 */   addiu    $v0, $zero, 1
/* 6F1ACC 802389EC 0000102D */  daddu     $v0, $zero, $zero
.L802389F0:
/* 6F1AD0 802389F0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 6F1AD4 802389F4 8FB40020 */  lw        $s4, 0x20($sp)
/* 6F1AD8 802389F8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6F1ADC 802389FC 8FB20018 */  lw        $s2, 0x18($sp)
/* 6F1AE0 80238A00 8FB10014 */  lw        $s1, 0x14($sp)
/* 6F1AE4 80238A04 8FB00010 */  lw        $s0, 0x10($sp)
/* 6F1AE8 80238A08 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 6F1AEC 80238A0C D7B80038 */  ldc1      $f24, 0x38($sp)
/* 6F1AF0 80238A10 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 6F1AF4 80238A14 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 6F1AF8 80238A18 03E00008 */  jr        $ra
/* 6F1AFC 80238A1C 27BD0048 */   addiu    $sp, $sp, 0x48
