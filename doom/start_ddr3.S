.section .text.init, "ax"
.global _start

_start:
    .cfi_startproc
    .cfi_undefined ra
    .option push
    .option norelax
    .option pop
    nop

    /* Initialize stack pointer to 0x107FFFF0 */
    la sp, __stack_top
    add s0, sp, zero

    /* Clear BSS section */
    la a0, __bss_start
    la a1, __bss_end
clear_bss_loop:
    bgeu a0, a1, bss_cleared
    sw zero, 0(a0)
    addi a0, a0, 4
    j clear_bss_loop

bss_cleared:
    /* Call main(0, NULL) */
    li a0, 0
    li a1, 0
    jal zero, main

    .cfi_endproc
    .end
