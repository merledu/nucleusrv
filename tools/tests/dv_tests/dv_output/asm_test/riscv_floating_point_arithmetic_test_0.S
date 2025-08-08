.include "user_define.h"
.globl _start
.section .text
_start:           
                  .include "user_init.s"
                  csrr x5, 0xf14
                  li x6, 0
                  beq x5, x6, 0f

0: la x29, h0_start
jalr x0, x29, 0
h0_start:
                  li x31, 0x4000112d
                  csrw 0x301, x31
kernel_sp:        
                  la x19, kernel_stack_end

trap_vec_init:    
                  la x31, mtvec_handler
                  ori x31, x31, 0
                  csrw 0x305, x31 # MTVEC

mepc_setup:       
                  la x31, init
                  csrw 0x341, x31

init_machine_mode:
                  li x31, 0x3800
                  csrw 0x300, x31 # MSTATUS
                  li x31, 0x0
                  csrw 0x304, x31 # MIE
                  mret
init:             
                  li x31, 0x7d8d17
                  fmv.w.x f0, x31
                  li x31, 0x91462
                  fmv.w.x f1, x31
                  li x31, 0xff800000
                  fmv.w.x f2, x31
                  li x31, 0xcc5d8
                  fmv.w.x f3, x31
                  li x31, 0x7fc00000
                  fmv.w.x f4, x31
                  li x31, 0x305dd0
                  fmv.w.x f5, x31
                  li x31, 0x7f7fffff
                  fmv.w.x f6, x31
                  li x31, 0xff7fffff
                  fmv.w.x f7, x31
                  li x31, 0xff7fffff
                  fmv.w.x f8, x31
                  li x31, 0xff800000
                  fmv.w.x f9, x31
                  li x31, 0x7f800001
                  fmv.w.x f10, x31
                  li x31, 0xff800000
                  fmv.w.x f11, x31
                  li x31, 0x7ba40029
                  fmv.w.x f12, x31
                  li x31, 0x0
                  fmv.w.x f13, x31
                  li x31, 0xef5483cd
                  fmv.w.x f14, x31
                  li x31, 0x7f800000
                  fmv.w.x f15, x31
                  li x31, 0x98550
                  fmv.w.x f16, x31
                  li x31, 0xfca6ae2a
                  fmv.w.x f17, x31
                  li x31, 0xff7fffff
                  fmv.w.x f18, x31
                  li x31, 0x67fee
                  fmv.w.x f19, x31
                  li x31, 0x7fc00000
                  fmv.w.x f20, x31
                  li x31, 0x7f800001
                  fmv.w.x f21, x31
                  li x31, 0x80000000
                  fmv.w.x f22, x31
                  li x31, 0x9ae44
                  fmv.w.x f23, x31
                  li x31, 0xff800000
                  fmv.w.x f24, x31
                  li x31, 0x7fc00000
                  fmv.w.x f25, x31
                  li x31, 0xff7fffff
                  fmv.w.x f26, x31
                  li x31, 0xff800000
                  fmv.w.x f27, x31
                  li x31, 0x66c8c9
                  fmv.w.x f28, x31
                  li x31, 0xc83826a3
                  fmv.w.x f29, x31
                  li x31, 0x1887d
                  fmv.w.x f30, x31
                  li x31, 0x7f7fffff
                  fmv.w.x f31, x31
                  fsrmi 4
                  li x0, 0x80000000
                  li x1, 0xd8d82443
                  li x2, 0x9
                  li x3, 0x1
                  li x4, 0x80000000
                  li x5, 0xf178bb10
                  li x6, 0xf0af4263
                  li x7, 0x4ad9b7df
                  li x8, 0xf8f04999
                  li x9, 0x0
                  li x10, 0x40350be
                  li x11, 0x358d70f8
                  li x12, 0x0
                  li x13, 0x80000000
                  li x14, 0xff082611
                  li x15, 0x7c50aa93
                  li x16, 0x0
                  li x17, 0x80000000
                  li x18, 0xe
                  li x20, 0x5
                  li x21, 0x80000000
                  li x22, 0xf83b5627
                  li x23, 0x80000000
                  li x24, 0x0
                  li x25, 0x0
                  li x26, 0x0
                  li x28, 0x0
                  li x29, 0x6646e326
                  li x30, 0x1782d6b0
                  li x31, 0x9
                  la x27, user_stack_end
main:             mulhsu      t0, a6, a0
                  c.srai      a3, 8
                  c.addi16sp  sp, 176
                  fsqrt.s    ft6, fs9
                  fnmsub.s   fs10, fs8, ft8, fa0
                  fclass.d   a6, fs0
                  rem         a0, gp, s11
                  ori         a4, a7, -655
                  addi        zero, a7, 439
                  fcvt.d.w   ft7, a6
                  fle.d      s8, ft6, fs7
                  c.slli      a1, 10
                  fsgnjn.d   fs0, fa0, fs8
                  fsgnjx.d   fa0, fa1, fa1
                  fsub.s     fs5, fa4, fs7
                  c.addi16sp  sp, -16
                  fclass.s   t0, ft11
                  c.srli      a3, 14
                  xor         zero, a6, t3
                  feq.d      a6, fs4, ft6
                  fmv.w.x    fa7, a6
                  slti        a3, tp, -124
                  fmsub.s    fa6, fs9, ft3, ft6
                  fsgnjx.s   fa1, ft7, fs9
                  c.sub       a3, a3
                  fmin.d     fs10, fs0, fs5
                  sra         a4, s5, t6
                  srli        a7, s7, 15
                  fmv.x.w    gp, ft3
                  c.mv        tp, s9
                  fdiv.s     fs0, fs0, ft10
                  mulhu       a1, s4, tp
                  fsgnjx.s   ft11, ft0, fs3
                  c.andi      a1, -1
                  fmul.s     ft3, fs3, fa2
                  fsgnjn.d   fs5, ft8, fs10
                  c.nop
                  fmin.d     fa1, ft6, fa7
                  sll         gp, t6, ra
                  c.lui       a2, 23
                  mulh        s7, s11, t6
                  mulhu       s1, s3, gp
                  srli        s8, t5, 28
                  mul         zero, a0, a1
                  sll         a0, gp, s0
                  la x29, test_done
                  jalr x0, x29, 0
test_done:        
                  li gp, 1
                  ecall
write_tohost:     
                  sw gp, tohost, t5

_exit:            
                  j write_tohost

instr_end:        
                  nop

.section .data
.align 6; .global tohost; tohost: .dword 0;
.align 6; .global fromhost; fromhost: .dword 0;
.section .user_stack,"aw",@progbits;
.align 2
user_stack_start:
.rept 4999
.4byte 0x0
.endr
user_stack_end:
.4byte 0x0
.align 2
kernel_instr_start:
.text
.align 2
mtvec_handler:    
                  csrrw x27, 0x340, x27
                  add x27, x19, zero
                  1: addi x27, x27, -124
                  sw x1, 4(x27)
                  sw x2, 8(x27)
                  sw x3, 12(x27)
                  sw x4, 16(x27)
                  sw x5, 20(x27)
                  sw x6, 24(x27)
                  sw x7, 28(x27)
                  sw x8, 32(x27)
                  sw x9, 36(x27)
                  sw x10, 40(x27)
                  sw x11, 44(x27)
                  sw x12, 48(x27)
                  sw x13, 52(x27)
                  sw x14, 56(x27)
                  sw x15, 60(x27)
                  sw x16, 64(x27)
                  sw x17, 68(x27)
                  sw x18, 72(x27)
                  sw x19, 76(x27)
                  sw x20, 80(x27)
                  sw x21, 84(x27)
                  sw x22, 88(x27)
                  sw x23, 92(x27)
                  sw x24, 96(x27)
                  sw x25, 100(x27)
                  sw x26, 104(x27)
                  sw x27, 108(x27)
                  sw x28, 112(x27)
                  sw x29, 116(x27)
                  sw x30, 120(x27)
                  sw x31, 124(x27)
                  csrr x31, 0x300 # MSTATUS
                  csrr x31, 0x342 # MCAUSE
                  srli x31, x31, 31
                  bne x31, x0, mmode_intr_handler

mmode_exception_handler:
                  csrr x31, 0x341 # MEPC
                  csrr x31, 0x342 # MCAUSE
                  li x30, 0xb # ECALL_MMODE
                  beq x31, x30, ecall_handler
                  li x30, 0x2 # ILLEGAL_INSTRUCTION
                  beq x31, x30, illegal_instr_handler
                  csrr x30, 0x343 # MTVAL
                  1: la x29, test_done
                  jalr x1, x29, 0

ecall_handler:    
                  la x31, _start
                  sw x0, 0(x31)
                  sw x1, 4(x31)
                  sw x2, 8(x31)
                  sw x3, 12(x31)
                  sw x4, 16(x31)
                  sw x5, 20(x31)
                  sw x6, 24(x31)
                  sw x7, 28(x31)
                  sw x8, 32(x31)
                  sw x9, 36(x31)
                  sw x10, 40(x31)
                  sw x11, 44(x31)
                  sw x12, 48(x31)
                  sw x13, 52(x31)
                  sw x14, 56(x31)
                  sw x15, 60(x31)
                  sw x16, 64(x31)
                  sw x17, 68(x31)
                  sw x18, 72(x31)
                  sw x19, 76(x31)
                  sw x20, 80(x31)
                  sw x21, 84(x31)
                  sw x22, 88(x31)
                  sw x23, 92(x31)
                  sw x24, 96(x31)
                  sw x25, 100(x31)
                  sw x26, 104(x31)
                  sw x27, 108(x31)
                  sw x28, 112(x31)
                  sw x29, 116(x31)
                  sw x30, 120(x31)
                  sw x31, 124(x31)
                  la x29, write_tohost
                  jalr x0, x29, 0

illegal_instr_handler:
                  csrr  x31, 0x341
                  addi  x31, x31, 4
                  csrw  0x341, x31
                  lw x1, 4(x27)
                  lw x2, 8(x27)
                  lw x3, 12(x27)
                  lw x4, 16(x27)
                  lw x5, 20(x27)
                  lw x6, 24(x27)
                  lw x7, 28(x27)
                  lw x8, 32(x27)
                  lw x9, 36(x27)
                  lw x10, 40(x27)
                  lw x11, 44(x27)
                  lw x12, 48(x27)
                  lw x13, 52(x27)
                  lw x14, 56(x27)
                  lw x15, 60(x27)
                  lw x16, 64(x27)
                  lw x17, 68(x27)
                  lw x18, 72(x27)
                  lw x19, 76(x27)
                  lw x20, 80(x27)
                  lw x21, 84(x27)
                  lw x22, 88(x27)
                  lw x23, 92(x27)
                  lw x24, 96(x27)
                  lw x25, 100(x27)
                  lw x26, 104(x27)
                  lw x27, 108(x27)
                  lw x28, 112(x27)
                  lw x29, 116(x27)
                  lw x30, 120(x27)
                  lw x31, 124(x27)
                  addi x27, x27, 124
                  add x19, x27, zero
                  csrrw x27, 0x340, x27
                  mret

pt_fault_handler: 

.align 2
mmode_intr_handler:
                  csrr  x31, 0x300 # MSTATUS;
                  csrr  x31, 0x304 # MIE;
                  csrr  x31, 0x344 # MIP;
                  csrrc x31, 0x344, x31 # MIP;
                  lw x1, 4(x27)
                  lw x2, 8(x27)
                  lw x3, 12(x27)
                  lw x4, 16(x27)
                  lw x5, 20(x27)
                  lw x6, 24(x27)
                  lw x7, 28(x27)
                  lw x8, 32(x27)
                  lw x9, 36(x27)
                  lw x10, 40(x27)
                  lw x11, 44(x27)
                  lw x12, 48(x27)
                  lw x13, 52(x27)
                  lw x14, 56(x27)
                  lw x15, 60(x27)
                  lw x16, 64(x27)
                  lw x17, 68(x27)
                  lw x18, 72(x27)
                  lw x19, 76(x27)
                  lw x20, 80(x27)
                  lw x21, 84(x27)
                  lw x22, 88(x27)
                  lw x23, 92(x27)
                  lw x24, 96(x27)
                  lw x25, 100(x27)
                  lw x26, 104(x27)
                  lw x27, 108(x27)
                  lw x28, 112(x27)
                  lw x29, 116(x27)
                  lw x30, 120(x27)
                  lw x31, 124(x27)
                  addi x27, x27, 124
                  add x19, x27, zero
                  csrrw x27, 0x340, x27
                  mret;

kernel_instr_end: nop
.align 2
kernel_data_start:
.section .kernel_stack,"aw",@progbits;
.align 2
kernel_stack_start:
.rept 4999
.4byte 0x0
.endr
kernel_stack_end:
.4byte 0x0
