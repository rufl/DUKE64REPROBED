.include "macro.inc"

.section .text, "ax"

nonmatching D_800D1490, 0x1400

glabel D_800D1490
.incbin "assets/ucode/rdp.textbin.bin"
endlabel D_800D1490
