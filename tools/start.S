.section .text, "ax"
.global _start

_start:
    .cfi_startproc
    .cfi_undefined ra
    .option push
    .option norelax 
    .option pop
    nop
    la sp, __stack_top
    add s0, sp, zero
    jal zero, main
    .cfi_endproc
    .end