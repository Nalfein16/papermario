.include "macro.inc"

.section .data

dlabel D_E007EC30
.word 0x323C4650, 0x5A646964, 0x00000000, 0x00000000

dlabel D_E007EC40
.double 0.05

dlabel jtbl_E007EC48
.word LE007E270_37F990, LE007E2C0_37F9E0, LE007E314_37FA34, LE007E334_37FA54, LE007E354_37FA74, LE007E3A0_37FAC0, LE007E3C8_37FAE8, 0

dlabel D_E007EC68
.double 0.01

dlabel D_E007EC70
.double 0.9, 0.0
