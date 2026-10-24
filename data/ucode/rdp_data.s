.include "macro.inc"

.section .rodata, "a"

nonmatching D_8010A1C0, 0x800

dlabel D_8010A1C0
.incbin "Duke64-RE/assets/ucode/rdp_data.rodatabin.bin"
enddlabel D_8010A1C0
