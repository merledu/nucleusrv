.section .text
.globl _start
_start:
    # ---- AMOADD.W test ----
    la   x1, amo_addr     # x1 = address
    li   x2, 1            # x2 = addend
    amoadd.w x3, x2, (x1) # mem[x1] = mem[x1] + x2, x3 = old value

    # ---- LR/SC test ----
    la   x4, lrsc_addr
    lr.w x5, (x4)         # load reserved
    li   x6, 0xAA         # store value
    sc.w x7, x6, (x4)     # try store

    j .                   # stop here (infinite loop)

.section .data
amo_addr:
    .word 5
lrsc_addr:
    .word 0