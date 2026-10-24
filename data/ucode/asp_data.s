.include "macro.inc"

.section .rodata, "a"

nonmatching D_8010A9C0, 0x2C0

dlabel D_8010A9C0
.incbin "assets/ucode/asp_data.rodatabin.bin"
enddlabel D_8010A9C0
