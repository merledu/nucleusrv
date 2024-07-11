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
RVTEST_ISA("RV64IF")

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

    # Testcase 0:  imm:0x800, result rd:x0(0x00000000fffffffe)
    la  x30, test_data
    addi    x30, x30,0
    li     x6, MASK_XLEN(2048)
    add    x30, x30, x6
    flw f0, -2048(x30)
    csrrci x6, fcsr, 0x1F
    sw x6, 0(x5)
        fmv.x.w x7, f0
    li x6, 0xFFFFFFFF
    and x7, x7, x6
    fsw f0, 8(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x00000000fffffffe)

    # Testcase 1:  imm:0x800, result rd:x1(0x00000000fffffffd)
    la  x29, test_data
    addi    x29, x29,4
    li     x6, MASK_XLEN(2048)
    add    x29, x29, x6
    flw f1, -2048(x29)
    csrrci x6, fcsr, 0x1F
    sw x6, 16(x5)
        fmv.x.w x7, f1
    li x6, 0xFFFFFFFF
    and x7, x7, x6
    fsw f1, 24(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x00000000fffffffd)

    # Testcase 2:  imm:0x800, result rd:x2(0x00000000fffffffb)
    la  x28, test_data
    addi    x28, x28,8
    li     x6, MASK_XLEN(2048)
    add    x28, x28, x6
    flw f2, -2048(x28)
    csrrci x6, fcsr, 0x1F
    sw x6, 32(x5)
        fmv.x.w x7, f2
    li x6, 0xFFFFFFFF
    and x7, x7, x6
    fsw f2, 40(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x00000000fffffffb)

    # Testcase 3:  imm:0x800, result rd:x3(0x00000000fffffff7)
    la  x27, test_data
    addi    x27, x27,12
    li     x6, MASK_XLEN(2048)
    add    x27, x27, x6
    flw f3, -2048(x27)
    csrrci x6, fcsr, 0x1F
    sw x6, 48(x5)
        fmv.x.w x7, f3
    li x6, 0xFFFFFFFF
    and x7, x7, x6
    fsw f3, 56(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x00000000fffffff7)

    # Testcase 4:  imm:0x800, result rd:x4(0x00000000ffffffef)
    la  x26, test_data
    addi    x26, x26,16
    li     x6, MASK_XLEN(2048)
    add    x26, x26, x6
    flw f4, -2048(x26)
    csrrci x6, fcsr, 0x1F
    sw x6, 64(x5)
        fmv.x.w x7, f4
    li x6, 0xFFFFFFFF
    and x7, x7, x6
    fsw f4, 72(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x00000000ffffffef)



    

    RVTEST_SIGBASE(x1,signature_2_0)

    # Testcase 5:  imm:0x800, result rd:x5(0x00000000ffffffdf)
    la  x25, test_data
    addi    x25, x25,20
    li     x2, MASK_XLEN(2048)
    add    x25, x25, x2
    flw f5, -2048(x25)
    csrrci x2, fcsr, 0x1F
    sw x2, 0(x1)
        fmv.x.w x3, f5
    li x2, 0xFFFFFFFF
    and x3, x3, x2
    fsw f5, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x00000000ffffffdf)

    # Testcase 6:  imm:0x0, result rd:x6(0x00000000ffffffbf)
    la  x24, test_data
    addi    x24, x24,24
    li     x2, MASK_XLEN(0)
    add    x24, x24, x2
    flw f6, 0(x24)
    csrrci x2, fcsr, 0x1F
    sw x2, 16(x1)
        fmv.x.w x3, f6
    li x2, 0xFFFFFFFF
    and x3, x3, x2
    fsw f6, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x00000000ffffffbf)

    # Testcase 7:  imm:0x800, result rd:x7(0x00000000ffffff7f)
    la  x23, test_data
    addi    x23, x23,28
    li     x2, MASK_XLEN(2048)
    add    x23, x23, x2
    flw f7, -2048(x23)
    csrrci x2, fcsr, 0x1F
    sw x2, 32(x1)
        fmv.x.w x3, f7
    li x2, 0xFFFFFFFF
    and x3, x3, x2
    fsw f7, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x00000000ffffff7f)

    # Testcase 8:  imm:0x800, result rd:x8(0x00000000fffffeff)
    la  x22, test_data
    addi    x22, x22,32
    li     x2, MASK_XLEN(2048)
    add    x22, x22, x2
    flw f8, -2048(x22)
    csrrci x2, fcsr, 0x1F
    sw x2, 48(x1)
        fmv.x.w x3, f8
    li x2, 0xFFFFFFFF
    and x3, x3, x2
    fsw f8, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x00000000fffffeff)

    # Testcase 9:  imm:0x800, result rd:x9(0x00000000fffffdff)
    la  x21, test_data
    addi    x21, x21,36
    li     x2, MASK_XLEN(2048)
    add    x21, x21, x2
    flw f9, -2048(x21)
    csrrci x2, fcsr, 0x1F
    sw x2, 64(x1)
        fmv.x.w x3, f9
    li x2, 0xFFFFFFFF
    and x3, x3, x2
    fsw f9, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x00000000fffffdff)



    

    RVTEST_SIGBASE(x1,signature_3_0)

    # Testcase 10:  imm:0x800, result rd:x10(0x00000000fffffeff)
    la  x20, test_data
    addi    x20, x20,40
    li     x7, MASK_XLEN(2048)
    add    x20, x20, x7
    flw f10, -2048(x20)
    csrrci x7, fcsr, 0x1F
    sw x7, 0(x1)
        fmv.x.w x8, f10
    li x7, 0xFFFFFFFF
    and x8, x8, x7
    fsw f10, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x00000000fffffeff)

    # Testcase 11:  imm:0x800, result rd:x11(0x00000000fffff7ff)
    la  x19, test_data
    addi    x19, x19,44
    li     x7, MASK_XLEN(2048)
    add    x19, x19, x7
    flw f11, -2048(x19)
    csrrci x7, fcsr, 0x1F
    sw x7, 16(x1)
        fmv.x.w x8, f11
    li x7, 0xFFFFFFFF
    and x8, x8, x7
    fsw f11, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x00000000fffff7ff)

    # Testcase 12:  imm:0x800, result rd:x12(0x00000000ffffefff)
    la  x18, test_data
    addi    x18, x18,48
    li     x7, MASK_XLEN(2048)
    add    x18, x18, x7
    flw f12, -2048(x18)
    csrrci x7, fcsr, 0x1F
    sw x7, 32(x1)
        fmv.x.w x8, f12
    li x7, 0xFFFFFFFF
    and x8, x8, x7
    fsw f12, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x00000000ffffefff)

    # Testcase 13:  imm:0x800, result rd:x13(0x00000000ffffdfff)
    la  x17, test_data
    addi    x17, x17,52
    li     x7, MASK_XLEN(2048)
    add    x17, x17, x7
    flw f13, -2048(x17)
    csrrci x7, fcsr, 0x1F
    sw x7, 48(x1)
        fmv.x.w x8, f13
    li x7, 0xFFFFFFFF
    and x8, x8, x7
    fsw f13, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x00000000ffffdfff)

    # Testcase 14:  imm:0x0, result rd:x14(0x00000000ffffefff)
    la  x16, test_data
    addi    x16, x16,56
    li     x7, MASK_XLEN(0)
    add    x16, x16, x7
    flw f14, 0(x16)
    csrrci x7, fcsr, 0x1F
    sw x7, 64(x1)
        fmv.x.w x8, f14
    li x7, 0xFFFFFFFF
    and x8, x8, x7
    fsw f14, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x00000000ffffefff)



    

    RVTEST_SIGBASE(x2,signature_4_0)

    # Testcase 15:  imm:0x800, result rd:x15(0x00000000ffff7fff)
    la  x15, test_data
    addi    x15, x15,60
    li     x3, MASK_XLEN(2048)
    add    x15, x15, x3
    flw f15, -2048(x15)
    csrrci x3, fcsr, 0x1F
    sw x3, 0(x2)
        fmv.x.w x4, f15
    li x3, 0xFFFFFFFF
    and x4, x4, x3
    fsw f15, 8(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x00000000ffff7fff)

    # Testcase 16:  imm:0x800, result rd:x16(0x00000000fffeffff)
    la  x14, test_data
    addi    x14, x14,64
    li     x3, MASK_XLEN(2048)
    add    x14, x14, x3
    flw f16, -2048(x14)
    csrrci x3, fcsr, 0x1F
    sw x3, 16(x2)
        fmv.x.w x4, f16
    li x3, 0xFFFFFFFF
    and x4, x4, x3
    fsw f16, 24(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x00000000fffeffff)

    # Testcase 17:  imm:0x800, result rd:x17(0x00000000fffdffff)
    la  x13, test_data
    addi    x13, x13,68
    li     x3, MASK_XLEN(2048)
    add    x13, x13, x3
    flw f17, -2048(x13)
    csrrci x3, fcsr, 0x1F
    sw x3, 32(x2)
        fmv.x.w x4, f17
    li x3, 0xFFFFFFFF
    and x4, x4, x3
    fsw f17, 40(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x00000000fffdffff)

    # Testcase 18:  imm:0x800, result rd:x18(0x00000000fffbffff)
    la  x12, test_data
    addi    x12, x12,72
    li     x3, MASK_XLEN(2048)
    add    x12, x12, x3
    flw f18, -2048(x12)
    csrrci x3, fcsr, 0x1F
    sw x3, 48(x2)
        fmv.x.w x4, f18
    li x3, 0xFFFFFFFF
    and x4, x4, x3
    fsw f18, 56(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x00000000fffbffff)

    # Testcase 19:  imm:0x800, result rd:x19(0x00000000fff7ffff)
    la  x11, test_data
    addi    x11, x11,76
    li     x3, MASK_XLEN(2048)
    add    x11, x11, x3
    flw f19, -2048(x11)
    csrrci x3, fcsr, 0x1F
    sw x3, 64(x2)
        fmv.x.w x4, f19
    li x3, 0xFFFFFFFF
    and x4, x4, x3
    fsw f19, 72(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x00000000fff7ffff)



    

    RVTEST_SIGBASE(x1,signature_5_0)

    # Testcase 20:  imm:0x800, result rd:x20(0x00000000ffefffff)
    la  x10, test_data
    addi    x10, x10,80
    li     x2, MASK_XLEN(2048)
    add    x10, x10, x2
    flw f20, -2048(x10)
    csrrci x2, fcsr, 0x1F
    sw x2, 0(x1)
        fmv.x.w x3, f20
    li x2, 0xFFFFFFFF
    and x3, x3, x2
    fsw f20, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x00000000ffefffff)

    # Testcase 21:  imm:0x800, result rd:x21(0x00000000ffdfffff)
    la  x9, test_data
    addi    x9, x9,84
    li     x2, MASK_XLEN(2048)
    add    x9, x9, x2
    flw f21, -2048(x9)
    csrrci x2, fcsr, 0x1F
    sw x2, 16(x1)
        fmv.x.w x3, f21
    li x2, 0xFFFFFFFF
    and x3, x3, x2
    fsw f21, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x00000000ffdfffff)

    # Testcase 22:  imm:0x0, result rd:x22(0x00000000ffbfffff)
    la  x8, test_data
    addi    x8, x8,88
    li     x2, MASK_XLEN(0)
    add    x8, x8, x2
    flw f22, 0(x8)
    csrrci x2, fcsr, 0x1F
    sw x2, 32(x1)
        fmv.x.w x3, f22
    li x2, 0xFFFFFFFF
    and x3, x3, x2
    fsw f22, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x00000000ffbfffff)

    # Testcase 23:  imm:0x800, result rd:x23(0x00000000ff7fffff)
    la  x7, test_data
    addi    x7, x7,92
    li     x2, MASK_XLEN(2048)
    add    x7, x7, x2
    flw f23, -2048(x7)
    csrrci x2, fcsr, 0x1F
    sw x2, 48(x1)
        fmv.x.w x3, f23
    li x2, 0xFFFFFFFF
    and x3, x3, x2
    fsw f23, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x00000000ff7fffff)

    # Testcase 24:  imm:0x800, result rd:x24(0x00000000feffffff)
    la  x6, test_data
    addi    x6, x6,96
    li     x2, MASK_XLEN(2048)
    add    x6, x6, x2
    flw f24, -2048(x6)
    csrrci x2, fcsr, 0x1F
    sw x2, 64(x1)
        fmv.x.w x3, f24
    li x2, 0xFFFFFFFF
    and x3, x3, x2
    fsw f24, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x00000000feffffff)



    

    RVTEST_SIGBASE(x6,signature_6_0)

    # Testcase 25:  imm:0x800, result rd:x25(0x00000000fdffffff)
    la  x5, test_data
    addi    x5, x5,100
    li     x7, MASK_XLEN(2048)
    add    x5, x5, x7
    flw f25, -2048(x5)
    csrrci x7, fcsr, 0x1F
    sw x7, 0(x6)
        fmv.x.w x8, f25
    li x7, 0xFFFFFFFF
    and x8, x8, x7
    fsw f25, 8(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x00000000fdffffff)

    # Testcase 26:  imm:0x800, result rd:x26(0x00000000feffffff)
    la  x4, test_data
    addi    x4, x4,104
    li     x7, MASK_XLEN(2048)
    add    x4, x4, x7
    flw f26, -2048(x4)
    csrrci x7, fcsr, 0x1F
    sw x7, 16(x6)
        fmv.x.w x8, f26
    li x7, 0xFFFFFFFF
    and x8, x8, x7
    fsw f26, 24(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x00000000feffffff)

    # Testcase 27:  imm:0x800, result rd:x27(0x00000000f7ffffff)
    la  x3, test_data
    addi    x3, x3,108
    li     x7, MASK_XLEN(2048)
    add    x3, x3, x7
    flw f27, -2048(x3)
    csrrci x7, fcsr, 0x1F
    sw x7, 32(x6)
        fmv.x.w x8, f27
    li x7, 0xFFFFFFFF
    and x8, x8, x7
    fsw f27, 40(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x00000000f7ffffff)

    # Testcase 28:  imm:0x800, result rd:x28(0x00000000efffffff)
    la  x2, test_data
    addi    x2, x2,112
    li     x7, MASK_XLEN(2048)
    add    x2, x2, x7
    flw f28, -2048(x2)
    csrrci x7, fcsr, 0x1F
    sw x7, 48(x6)
        fmv.x.w x8, f28
    li x7, 0xFFFFFFFF
    and x8, x8, x7
    fsw f28, 56(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x00000000efffffff)

    # Testcase 29:  imm:0x800, result rd:x29(0x00000000dfffffff)
    la  x1, test_data
    addi    x1, x1,116
    li     x7, MASK_XLEN(2048)
    add    x1, x1, x7
    flw f29, -2048(x1)
    csrrci x7, fcsr, 0x1F
    sw x7, 64(x6)
        fmv.x.w x8, f29
    li x7, 0xFFFFFFFF
    and x8, x8, x7
    fsw f29, 72(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x00000000dfffffff)



    

    RVTEST_SIGBASE(x2,signature_7_0)

    # Testcase 30:  imm:0x0, result rd:x30(0x00000000efffffff)
    la  x1, test_data
    addi    x1, x1,120
    li     x3, MASK_XLEN(0)
    add    x1, x1, x3
    flw f30, 0(x1)
    csrrci x3, fcsr, 0x1F
    sw x3, 0(x2)
        fmv.x.w x4, f30
    li x3, 0xFFFFFFFF
    and x4, x4, x3
    fsw f30, 8(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x00000000efffffff)

	
#endif


RVTEST_CODE_END
RVMODEL_HALT

RVTEST_DATA_BEGIN
.align 4
rvtest_data:
.word 0xbabecafe

# Input data section.
	.data

	.align 8
test_data:

	.dword 0xfffffffdfffffffe
	.dword 0xfffffff7fffffffb
	.dword 0xffffffdfffffffef
	.dword 0xffffff7fffffffbf
	.dword 0xfffffdfffffffeff
	.dword 0xfffff7fffffffeff
	.dword 0xffffdfffffffefff
	.dword 0xffff7fffffffefff
	.dword 0xfffdfffffffeffff
	.dword 0xfff7fffffffbffff
	.dword 0xffdfffffffefffff
	.dword 0xff7fffffffbfffff
	.dword 0xfdfffffffeffffff
	.dword 0xf7fffffffeffffff
	.dword 0xdfffffffefffffff
	.dword 0x7fffffffefffffff
	.dword 0x00000001ffffffff
	.dword 0x0000000400000002
	.dword 0x0000001000000008
	.dword 0x0000004000000020
	.dword 0x0000010000000080
	.dword 0x0000040000000200
	.dword 0x0000100000000800
	.dword 0x0000400000002000
	.dword 0x0000000100008000
	.dword 0x0004000000000002
	.dword 0x0000001000080000
	.dword 0x0040000000000020
	.dword 0x0000010000800000
	.dword 0x0400000000000200
	.dword 0x0000100008000000
	.dword 0x4000000000002000
	.dword 0x0000000080000000

RVTEST_DATA_END

RVMODEL_DATA_BEGIN




signature_1_0:
	.fill 20, 4, 0xdeadbeef
signature_2_0:
	.fill 20, 4, 0xdeadbeef
signature_3_0:
	.fill 20, 4, 0xdeadbeef
signature_4_0:
	.fill 20, 4, 0xdeadbeef
signature_5_0:
	.fill 20, 4, 0xdeadbeef
signature_6_0:
	.fill 20, 4, 0xdeadbeef
signature_7_0:
	.fill 20, 4, 0xdeadbeef


#ifdef rvtest_mtrap_routine

mtrap_sigptr:
    .fill 64*(XLEN/32),4,0xdeadbeef

#endif

#ifdef rvtest_gpr_save

gpr_save:
    .fill 32*(XLEN/32),4,0xdeadbeef

#endif

RVMODEL_DATA_END

