// RISC-V Architectural Validation Test FLW-01
//
//
// Copyright (c) 2005-2023 Imperas Software Ltd., www.imperas.com
//
// The contents of this file are provided under the Software License
// Agreement that you accepted before downloading this file.
//
// This source forms part of the Software and can be used for educational,
// training, and demonstration purposes but cannot be used for derivative
// works except in cases where the derivative works require OVP technology
// to run.
//
// For open source models released under licenses that you can use for
// derivative works, please visit www.OVPworld.org or www.imperas.com
// for the location of the open source models.
//
    

//
// Specification: F Standard Extension for Single-Precision Floating-Point, Version 2.2
// Description: Testing instruction 'flw'.

#include "model_test.h"
#include "arch_test.h"
RVTEST_ISA("RV32IF")

.section .text.init
.globl rvtest_entry_point
rvtest_entry_point:
RVMODEL_BOOT
RVTEST_CODE_BEGIN





    # enable floating point unit
    li x1,  1 << 13
    csrs mstatus, x1
    # set rounding mode
	li x1,  0
	csrw fcsr, x1


#ifdef TEST_CASE_1


    
    RVTEST_CASE(0,"//check ISA:=regex(.*32.*);check ISA:=regex(.*I.*F.*);def TEST_CASE_1=True;",flw)

    RVTEST_SIGBASE(x5,signature_1_0)

    # Testcase 0:  imm:0x800, result rd:x0(0xfffffffe)
    la  x30, test_data
    addi    x30, x30,0
    li     x6, MASK_XLEN(2048)
    add    x30, x30, x6
    flw f0, -2048(x30)
    csrrci x6, fcsr, 0x1F
    sw x6, 0(x5)
        fmv.x.w x7, f0
    fsw f0, 4(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xfffffffe)

    # Testcase 1:  imm:0x800, result rd:x1(0xfffffffd)
    la  x29, test_data
    addi    x29, x29,4
    li     x6, MASK_XLEN(2048)
    add    x29, x29, x6
    flw f1, -2048(x29)
    csrrci x6, fcsr, 0x1F
    sw x6, 8(x5)
        fmv.x.w x7, f1
    fsw f1, 12(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xfffffffd)

    # Testcase 2:  imm:0x800, result rd:x2(0xfffffffb)
    la  x28, test_data
    addi    x28, x28,8
    li     x6, MASK_XLEN(2048)
    add    x28, x28, x6
    flw f2, -2048(x28)
    csrrci x6, fcsr, 0x1F
    sw x6, 16(x5)
        fmv.x.w x7, f2
    fsw f2, 20(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xfffffffb)

    # Testcase 3:  imm:0x800, result rd:x3(0xfffffff7)
    la  x27, test_data
    addi    x27, x27,12
    li     x6, MASK_XLEN(2048)
    add    x27, x27, x6
    flw f3, -2048(x27)
    csrrci x6, fcsr, 0x1F
    sw x6, 24(x5)
        fmv.x.w x7, f3
    fsw f3, 28(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xfffffff7)

    # Testcase 4:  imm:0x800, result rd:x4(0xffffffef)
    la  x26, test_data
    addi    x26, x26,16
    li     x6, MASK_XLEN(2048)
    add    x26, x26, x6
    flw f4, -2048(x26)
    csrrci x6, fcsr, 0x1F
    sw x6, 32(x5)
        fmv.x.w x7, f4
    fsw f4, 36(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xffffffef)



    

    RVTEST_SIGBASE(x1,signature_2_0)

    # Testcase 5:  imm:0x800, result rd:x5(0xffffffdf)
    la  x25, test_data
    addi    x25, x25,20
    li     x2, MASK_XLEN(2048)
    add    x25, x25, x2
    flw f5, -2048(x25)
    csrrci x2, fcsr, 0x1F
    sw x2, 0(x1)
        fmv.x.w x3, f5
    fsw f5, 4(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffdf)

    # Testcase 6:  imm:0x0, result rd:x6(0xffffffbf)
    la  x24, test_data
    addi    x24, x24,24
    li     x2, MASK_XLEN(0)
    add    x24, x24, x2
    flw f6, 0(x24)
    csrrci x2, fcsr, 0x1F
    sw x2, 8(x1)
        fmv.x.w x3, f6
    fsw f6, 12(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffbf)

    # Testcase 7:  imm:0x800, result rd:x7(0xffffff7f)
    la  x23, test_data
    addi    x23, x23,28
    li     x2, MASK_XLEN(2048)
    add    x23, x23, x2
    flw f7, -2048(x23)
    csrrci x2, fcsr, 0x1F
    sw x2, 16(x1)
        fmv.x.w x3, f7
    fsw f7, 20(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffff7f)

    # Testcase 8:  imm:0x800, result rd:x8(0xfffffeff)
    la  x22, test_data
    addi    x22, x22,32
    li     x2, MASK_XLEN(2048)
    add    x22, x22, x2
    flw f8, -2048(x22)
    csrrci x2, fcsr, 0x1F
    sw x2, 24(x1)
        fmv.x.w x3, f8
    fsw f8, 28(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xfffffeff)

    # Testcase 9:  imm:0x800, result rd:x9(0xfffffdff)
    la  x21, test_data
    addi    x21, x21,36
    li     x2, MASK_XLEN(2048)
    add    x21, x21, x2
    flw f9, -2048(x21)
    csrrci x2, fcsr, 0x1F
    sw x2, 32(x1)
        fmv.x.w x3, f9
    fsw f9, 36(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xfffffdff)



    

    RVTEST_SIGBASE(x1,signature_3_0)

    # Testcase 10:  imm:0x800, result rd:x10(0xfffffeff)
    la  x20, test_data
    addi    x20, x20,40
    li     x7, MASK_XLEN(2048)
    add    x20, x20, x7
    flw f10, -2048(x20)
    csrrci x7, fcsr, 0x1F
    sw x7, 0(x1)
        fmv.x.w x8, f10
    fsw f10, 4(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xfffffeff)

    # Testcase 11:  imm:0x800, result rd:x11(0xfffff7ff)
    la  x19, test_data
    addi    x19, x19,44
    li     x7, MASK_XLEN(2048)
    add    x19, x19, x7
    flw f11, -2048(x19)
    csrrci x7, fcsr, 0x1F
    sw x7, 8(x1)
        fmv.x.w x8, f11
    fsw f11, 12(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xfffff7ff)

    # Testcase 12:  imm:0x800, result rd:x12(0xffffefff)
    la  x18, test_data
    addi    x18, x18,48
    li     x7, MASK_XLEN(2048)
    add    x18, x18, x7
    flw f12, -2048(x18)
    csrrci x7, fcsr, 0x1F
    sw x7, 16(x1)
        fmv.x.w x8, f12
    fsw f12, 20(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffefff)

    # Testcase 13:  imm:0x800, result rd:x13(0xffffdfff)
    la  x17, test_data
    addi    x17, x17,52
    li     x7, MASK_XLEN(2048)
    add    x17, x17, x7
    flw f13, -2048(x17)
    csrrci x7, fcsr, 0x1F
    sw x7, 24(x1)
        fmv.x.w x8, f13
    fsw f13, 28(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffdfff)

    # Testcase 14:  imm:0x0, result rd:x14(0xffffefff)
    la  x16, test_data
    addi    x16, x16,56
    li     x7, MASK_XLEN(0)
    add    x16, x16, x7
    flw f14, 0(x16)
    csrrci x7, fcsr, 0x1F
    sw x7, 32(x1)
        fmv.x.w x8, f14
    fsw f14, 36(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffefff)



    

    RVTEST_SIGBASE(x2,signature_4_0)

    # Testcase 15:  imm:0x800, result rd:x15(0xffff7fff)
    la  x15, test_data
    addi    x15, x15,60
    li     x3, MASK_XLEN(2048)
    add    x15, x15, x3
    flw f15, -2048(x15)
    csrrci x3, fcsr, 0x1F
    sw x3, 0(x2)
        fmv.x.w x4, f15
    fsw f15, 4(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xffff7fff)

    # Testcase 16:  imm:0x800, result rd:x16(0xfffeffff)
    la  x14, test_data
    addi    x14, x14,64
    li     x3, MASK_XLEN(2048)
    add    x14, x14, x3
    flw f16, -2048(x14)
    csrrci x3, fcsr, 0x1F
    sw x3, 8(x2)
        fmv.x.w x4, f16
    fsw f16, 12(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xfffeffff)

    # Testcase 17:  imm:0x800, result rd:x17(0xfffdffff)
    la  x13, test_data
    addi    x13, x13,68
    li     x3, MASK_XLEN(2048)
    add    x13, x13, x3
    flw f17, -2048(x13)
    csrrci x3, fcsr, 0x1F
    sw x3, 16(x2)
        fmv.x.w x4, f17
    fsw f17, 20(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xfffdffff)

    # Testcase 18:  imm:0x800, result rd:x18(0xfffbffff)
    la  x12, test_data
    addi    x12, x12,72
    li     x3, MASK_XLEN(2048)
    add    x12, x12, x3
    flw f18, -2048(x12)
    csrrci x3, fcsr, 0x1F
    sw x3, 24(x2)
        fmv.x.w x4, f18
    fsw f18, 28(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xfffbffff)

    # Testcase 19:  imm:0x800, result rd:x19(0xfff7ffff)
    la  x11, test_data
    addi    x11, x11,76
    li     x3, MASK_XLEN(2048)
    add    x11, x11, x3
    flw f19, -2048(x11)
    csrrci x3, fcsr, 0x1F
    sw x3, 32(x2)
        fmv.x.w x4, f19
    fsw f19, 36(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xfff7ffff)



    

    RVTEST_SIGBASE(x1,signature_5_0)

    # Testcase 20:  imm:0x800, result rd:x20(0xffefffff)
    la  x10, test_data
    addi    x10, x10,80
    li     x2, MASK_XLEN(2048)
    add    x10, x10, x2
    flw f20, -2048(x10)
    csrrci x2, fcsr, 0x1F
    sw x2, 0(x1)
        fmv.x.w x3, f20
    fsw f20, 4(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffefffff)

    # Testcase 21:  imm:0x800, result rd:x21(0xffdfffff)
    la  x9, test_data
    addi    x9, x9,84
    li     x2, MASK_XLEN(2048)
    add    x9, x9, x2
    flw f21, -2048(x9)
    csrrci x2, fcsr, 0x1F
    sw x2, 8(x1)
        fmv.x.w x3, f21
    fsw f21, 12(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffdfffff)

    # Testcase 22:  imm:0x0, result rd:x22(0xffbfffff)
    la  x8, test_data
    addi    x8, x8,88
    li     x2, MASK_XLEN(0)
    add    x8, x8, x2
    flw f22, 0(x8)
    csrrci x2, fcsr, 0x1F
    sw x2, 16(x1)
        fmv.x.w x3, f22
    fsw f22, 20(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffbfffff)

    # Testcase 23:  imm:0x800, result rd:x23(0xff7fffff)
    la  x7, test_data
    addi    x7, x7,92
    li     x2, MASK_XLEN(2048)
    add    x7, x7, x2
    flw f23, -2048(x7)
    csrrci x2, fcsr, 0x1F
    sw x2, 24(x1)
        fmv.x.w x3, f23
    fsw f23, 28(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xff7fffff)

    # Testcase 24:  imm:0x800, result rd:x24(0xfeffffff)
    la  x6, test_data
    addi    x6, x6,96
    li     x2, MASK_XLEN(2048)
    add    x6, x6, x2
    flw f24, -2048(x6)
    csrrci x2, fcsr, 0x1F
    sw x2, 32(x1)
        fmv.x.w x3, f24
    fsw f24, 36(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xfeffffff)



    

    RVTEST_SIGBASE(x6,signature_6_0)

    # Testcase 25:  imm:0x800, result rd:x25(0xfdffffff)
    la  x5, test_data
    addi    x5, x5,100
    li     x7, MASK_XLEN(2048)
    add    x5, x5, x7
    flw f25, -2048(x5)
    csrrci x7, fcsr, 0x1F
    sw x7, 0(x6)
        fmv.x.w x8, f25
    fsw f25, 4(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xfdffffff)

    # Testcase 26:  imm:0x800, result rd:x26(0xfeffffff)
    la  x4, test_data
    addi    x4, x4,104
    li     x7, MASK_XLEN(2048)
    add    x4, x4, x7
    flw f26, -2048(x4)
    csrrci x7, fcsr, 0x1F
    sw x7, 8(x6)
        fmv.x.w x8, f26
    fsw f26, 12(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xfeffffff)

    # Testcase 27:  imm:0x800, result rd:x27(0xf7ffffff)
    la  x3, test_data
    addi    x3, x3,108
    li     x7, MASK_XLEN(2048)
    add    x3, x3, x7
    flw f27, -2048(x3)
    csrrci x7, fcsr, 0x1F
    sw x7, 16(x6)
        fmv.x.w x8, f27
    fsw f27, 20(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xf7ffffff)

    # Testcase 28:  imm:0x800, result rd:x28(0xefffffff)
    la  x2, test_data
    addi    x2, x2,112
    li     x7, MASK_XLEN(2048)
    add    x2, x2, x7
    flw f28, -2048(x2)
    csrrci x7, fcsr, 0x1F
    sw x7, 24(x6)
        fmv.x.w x8, f28
    fsw f28, 28(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xefffffff)

    # Testcase 29:  imm:0x800, result rd:x29(0xdfffffff)
    la  x1, test_data
    addi    x1, x1,116
    li     x7, MASK_XLEN(2048)
    add    x1, x1, x7
    flw f29, -2048(x1)
    csrrci x7, fcsr, 0x1F
    sw x7, 32(x6)
        fmv.x.w x8, f29
    fsw f29, 36(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xdfffffff)



    

    RVTEST_SIGBASE(x2,signature_7_0)

    # Testcase 30:  imm:0x0, result rd:x30(0xefffffff)
    la  x1, test_data
    addi    x1, x1,120
    li     x3, MASK_XLEN(0)
    add    x1, x1, x3
    flw f30, 0(x1)
    csrrci x3, fcsr, 0x1F
    sw x3, 0(x2)
        fmv.x.w x4, f30
    fsw f30, 4(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xefffffff)

	
#endif


RVTEST_CODE_END
RVMODEL_HALT

RVTEST_DATA_BEGIN
.align 4
rvtest_data:
.word 0xbabecafe

# Input data section.
	.data

	.align 4
test_data:

	.word 0xfffffffe
	.word 0xfffffffd
	.word 0xfffffffb
	.word 0xfffffff7
	.word 0xffffffef
	.word 0xffffffdf
	.word 0xffffffbf
	.word 0xffffff7f
	.word 0xfffffeff
	.word 0xfffffdff
	.word 0xfffffeff
	.word 0xfffff7ff
	.word 0xffffefff
	.word 0xffffdfff
	.word 0xffffefff
	.word 0xffff7fff
	.word 0xfffeffff
	.word 0xfffdffff
	.word 0xfffbffff
	.word 0xfff7ffff
	.word 0xffefffff
	.word 0xffdfffff
	.word 0xffbfffff
	.word 0xff7fffff
	.word 0xfeffffff
	.word 0xfdffffff
	.word 0xfeffffff
	.word 0xf7ffffff
	.word 0xefffffff
	.word 0xdfffffff
	.word 0xefffffff
	.word 0x7fffffff
	.word 0xffffffff
	.word 0x00000001
	.word 0x00000002
	.word 0x00000004
	.word 0x00000008
	.word 0x00000010
	.word 0x00000020
	.word 0x00000040
	.word 0x00000080
	.word 0x00000100
	.word 0x00000200
	.word 0x00000400
	.word 0x00000800
	.word 0x00001000
	.word 0x00002000
	.word 0x00004000
	.word 0x00008000
	.word 0x00000001
	.word 0x00000002
	.word 0x00040000
	.word 0x00080000
	.word 0x00000010
	.word 0x00000020
	.word 0x00400000
	.word 0x00800000
	.word 0x00000100
	.word 0x00000200
	.word 0x04000000
	.word 0x08000000
	.word 0x00001000
	.word 0x00002000
	.word 0x40000000
	.word 0x80000000
	.word 0x00000000

RVTEST_DATA_END

RVMODEL_DATA_BEGIN




signature_1_0:
	.fill 5, 8, 0xdeadbeef
signature_2_0:
	.fill 5, 8, 0xdeadbeef
signature_3_0:
	.fill 5, 8, 0xdeadbeef
signature_4_0:
	.fill 5, 8, 0xdeadbeef
signature_5_0:
	.fill 5, 8, 0xdeadbeef
signature_6_0:
	.fill 5, 8, 0xdeadbeef
signature_7_0:
	.fill 5, 8, 0xdeadbeef


#ifdef rvtest_mtrap_routine

mtrap_sigptr:
    .fill 64*(XLEN/32),4,0xdeadbeef

#endif

#ifdef rvtest_gpr_save

gpr_save:
    .fill 32*(XLEN/32),4,0xdeadbeef

#endif

RVMODEL_DATA_END

