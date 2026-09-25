.section .text, "ax"
.global _start

_start:
    .cfi_startproc
    .cfi_undefined ra
    .option push
    .option norelax
    .option pop
    nop
    li sp, 0x00007FF8   /* 8-byte aligned stack pointer at top of 32 KB SRAM */
    add s0, sp, zero
    jal zero, main
    .cfi_endproc
    .end
