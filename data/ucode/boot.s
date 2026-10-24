.include "macro.inc"

.section .text, "ax"

nonmatching D_800D13C0, 0xD0

glabel D_800D13C0
.incbin "assets/ucode/boot.textbin.bin"
endlabel D_800D13C0
