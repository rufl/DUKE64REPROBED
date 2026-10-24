.include "macro.inc"

.section .text, "ax"

nonmatching D_800D2890, 0xE20

glabel D_800D2890
.incbin "assets/ucode/asp.textbin.bin"
endlabel D_800D2890
