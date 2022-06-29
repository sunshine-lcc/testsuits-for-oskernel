.section .text.entry
.globl _start
_start:
    mov x0, sp
    bl __start_main
