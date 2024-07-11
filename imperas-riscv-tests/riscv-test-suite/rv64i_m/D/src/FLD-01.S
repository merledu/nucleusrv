// RISC-V Architectural Validation Test FLD-01
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
// Specification: D Standard Extension for Double-Precision Floating-Point, Version 2.2
// Description: Testing instruction 'fld'.

#include "model_test.h"
#include "arch_test.h"
RVTEST_ISA("RV64ID")

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


    
    RVTEST_CASE(0,"//check ISA:=regex(.*32.*);check ISA:=regex(.*I.*D.*);def TEST_CASE_1=True;",fld)

    RVTEST_SIGBASE(x5,signature_1_0)

    # Testcase 0:  imm:0x800, result rd:x0(0xfffffffffffffffe)
    la  x30, test_data
    addi    x30, x30,0
    li     x6, MASK_XLEN(2048)
    add    x30, x30, x6
    fld f0, -2048(x30)
    csrrci x6, fcsr, 0x1F
    sd x6, 0(x5)
        fmv.x.d x7, f0
    fsd f0, 8(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xfffffffffffffffe)

    # Testcase 1:  imm:0x800, result rd:x1(0xfffffffffffffffd)
    la  x29, test_data
    addi    x29, x29,8
    li     x6, MASK_XLEN(2048)
    add    x29, x29, x6
    fld f1, -2048(x29)
    csrrci x6, fcsr, 0x1F
    sd x6, 16(x5)
        fmv.x.d x7, f1
    fsd f1, 24(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xfffffffffffffffd)

    # Testcase 2:  imm:0x800, result rd:x2(0xfffffffffffffffb)
    la  x28, test_data
    addi    x28, x28,16
    li     x6, MASK_XLEN(2048)
    add    x28, x28, x6
    fld f2, -2048(x28)
    csrrci x6, fcsr, 0x1F
    sd x6, 32(x5)
        fmv.x.d x7, f2
    fsd f2, 40(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xfffffffffffffffb)

    # Testcase 3:  imm:0x800, result rd:x3(0xfffffffffffffff7)
    la  x27, test_data
    addi    x27, x27,24
    li     x6, MASK_XLEN(2048)
    add    x27, x27, x6
    fld f3, -2048(x27)
    csrrci x6, fcsr, 0x1F
    sd x6, 48(x5)
        fmv.x.d x7, f3
    fsd f3, 56(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xfffffffffffffff7)

    # Testcase 4:  imm:0x800, result rd:x4(0xffffffffffffffef)
    la  x26, test_data
    addi    x26, x26,32
    li     x6, MASK_XLEN(2048)
    add    x26, x26, x6
    fld f4, -2048(x26)
    csrrci x6, fcsr, 0x1F
    sd x6, 64(x5)
        fmv.x.d x7, f4
    fsd f4, 72(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xffffffffffffffef)



    

    RVTEST_SIGBASE(x1,signature_2_0)

    # Testcase 5:  imm:0x800, result rd:x5(0xffffffffffffffdf)
    la  x25, test_data
    addi    x25, x25,40
    li     x2, MASK_XLEN(2048)
    add    x25, x25, x2
    fld f5, -2048(x25)
    csrrci x2, fcsr, 0x1F
    sd x2, 0(x1)
        fmv.x.d x3, f5
    fsd f5, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffffffffffdf)

    # Testcase 6:  imm:0x0, result rd:x6(0xffffffffffffffbf)
    la  x24, test_data
    addi    x24, x24,48
    li     x2, MASK_XLEN(0)
    add    x24, x24, x2
    fld f6, 0(x24)
    csrrci x2, fcsr, 0x1F
    sd x2, 16(x1)
        fmv.x.d x3, f6
    fsd f6, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffffffffffbf)

    # Testcase 7:  imm:0x800, result rd:x7(0xffffffffffffff7f)
    la  x23, test_data
    addi    x23, x23,56
    li     x2, MASK_XLEN(2048)
    add    x23, x23, x2
    fld f7, -2048(x23)
    csrrci x2, fcsr, 0x1F
    sd x2, 32(x1)
        fmv.x.d x3, f7
    fsd f7, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffffffffff7f)

    # Testcase 8:  imm:0x800, result rd:x8(0xfffffffffffffeff)
    la  x22, test_data
    addi    x22, x22,64
    li     x2, MASK_XLEN(2048)
    add    x22, x22, x2
    fld f8, -2048(x22)
    csrrci x2, fcsr, 0x1F
    sd x2, 48(x1)
        fmv.x.d x3, f8
    fsd f8, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xfffffffffffffeff)

    # Testcase 9:  imm:0x800, result rd:x9(0xfffffffffffffdff)
    la  x21, test_data
    addi    x21, x21,72
    li     x2, MASK_XLEN(2048)
    add    x21, x21, x2
    fld f9, -2048(x21)
    csrrci x2, fcsr, 0x1F
    sd x2, 64(x1)
        fmv.x.d x3, f9
    fsd f9, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xfffffffffffffdff)



    

    RVTEST_SIGBASE(x1,signature_3_0)

    # Testcase 10:  imm:0x800, result rd:x10(0xfffffffffffffeff)
    la  x20, test_data
    addi    x20, x20,80
    li     x7, MASK_XLEN(2048)
    add    x20, x20, x7
    fld f10, -2048(x20)
    csrrci x7, fcsr, 0x1F
    sd x7, 0(x1)
        fmv.x.d x8, f10
    fsd f10, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xfffffffffffffeff)

    # Testcase 11:  imm:0x800, result rd:x11(0xfffffffffffff7ff)
    la  x19, test_data
    addi    x19, x19,88
    li     x7, MASK_XLEN(2048)
    add    x19, x19, x7
    fld f11, -2048(x19)
    csrrci x7, fcsr, 0x1F
    sd x7, 16(x1)
        fmv.x.d x8, f11
    fsd f11, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xfffffffffffff7ff)

    # Testcase 12:  imm:0x800, result rd:x12(0xffffffffffffefff)
    la  x18, test_data
    addi    x18, x18,96
    li     x7, MASK_XLEN(2048)
    add    x18, x18, x7
    fld f12, -2048(x18)
    csrrci x7, fcsr, 0x1F
    sd x7, 32(x1)
        fmv.x.d x8, f12
    fsd f12, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffffffffffefff)

    # Testcase 13:  imm:0x800, result rd:x13(0xffffffffffffdfff)
    la  x17, test_data
    addi    x17, x17,104
    li     x7, MASK_XLEN(2048)
    add    x17, x17, x7
    fld f13, -2048(x17)
    csrrci x7, fcsr, 0x1F
    sd x7, 48(x1)
        fmv.x.d x8, f13
    fsd f13, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffffffffffdfff)

    # Testcase 14:  imm:0x0, result rd:x14(0xffffffffffffefff)
    la  x16, test_data
    addi    x16, x16,112
    li     x7, MASK_XLEN(0)
    add    x16, x16, x7
    fld f14, 0(x16)
    csrrci x7, fcsr, 0x1F
    sd x7, 64(x1)
        fmv.x.d x8, f14
    fsd f14, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffffffffffefff)



    

    RVTEST_SIGBASE(x2,signature_4_0)

    # Testcase 15:  imm:0x800, result rd:x15(0xffffffffffff7fff)
    la  x15, test_data
    addi    x15, x15,120
    li     x3, MASK_XLEN(2048)
    add    x15, x15, x3
    fld f15, -2048(x15)
    csrrci x3, fcsr, 0x1F
    sd x3, 0(x2)
        fmv.x.d x4, f15
    fsd f15, 8(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xffffffffffff7fff)

    # Testcase 16:  imm:0x800, result rd:x16(0xfffffffffffeffff)
    la  x14, test_data
    addi    x14, x14,128
    li     x3, MASK_XLEN(2048)
    add    x14, x14, x3
    fld f16, -2048(x14)
    csrrci x3, fcsr, 0x1F
    sd x3, 16(x2)
        fmv.x.d x4, f16
    fsd f16, 24(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xfffffffffffeffff)

    # Testcase 17:  imm:0x800, result rd:x17(0xfffffffffffdffff)
    la  x13, test_data
    addi    x13, x13,136
    li     x3, MASK_XLEN(2048)
    add    x13, x13, x3
    fld f17, -2048(x13)
    csrrci x3, fcsr, 0x1F
    sd x3, 32(x2)
        fmv.x.d x4, f17
    fsd f17, 40(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xfffffffffffdffff)

    # Testcase 18:  imm:0x800, result rd:x18(0xfffffffffffbffff)
    la  x12, test_data
    addi    x12, x12,144
    li     x3, MASK_XLEN(2048)
    add    x12, x12, x3
    fld f18, -2048(x12)
    csrrci x3, fcsr, 0x1F
    sd x3, 48(x2)
        fmv.x.d x4, f18
    fsd f18, 56(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xfffffffffffbffff)

    # Testcase 19:  imm:0x800, result rd:x19(0xfffffffffff7ffff)
    la  x11, test_data
    addi    x11, x11,152
    li     x3, MASK_XLEN(2048)
    add    x11, x11, x3
    fld f19, -2048(x11)
    csrrci x3, fcsr, 0x1F
    sd x3, 64(x2)
        fmv.x.d x4, f19
    fsd f19, 72(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xfffffffffff7ffff)



    

    RVTEST_SIGBASE(x1,signature_5_0)

    # Testcase 20:  imm:0x800, result rd:x20(0xffffffffffefffff)
    la  x10, test_data
    addi    x10, x10,160
    li     x2, MASK_XLEN(2048)
    add    x10, x10, x2
    fld f20, -2048(x10)
    csrrci x2, fcsr, 0x1F
    sd x2, 0(x1)
        fmv.x.d x3, f20
    fsd f20, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffffffefffff)

    # Testcase 21:  imm:0x800, result rd:x21(0xffffffffffdfffff)
    la  x9, test_data
    addi    x9, x9,168
    li     x2, MASK_XLEN(2048)
    add    x9, x9, x2
    fld f21, -2048(x9)
    csrrci x2, fcsr, 0x1F
    sd x2, 16(x1)
        fmv.x.d x3, f21
    fsd f21, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffffffdfffff)

    # Testcase 22:  imm:0x0, result rd:x22(0xffffffffffbfffff)
    la  x8, test_data
    addi    x8, x8,176
    li     x2, MASK_XLEN(0)
    add    x8, x8, x2
    fld f22, 0(x8)
    csrrci x2, fcsr, 0x1F
    sd x2, 32(x1)
        fmv.x.d x3, f22
    fsd f22, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffffffbfffff)

    # Testcase 23:  imm:0x800, result rd:x23(0xffffffffff7fffff)
    la  x7, test_data
    addi    x7, x7,184
    li     x2, MASK_XLEN(2048)
    add    x7, x7, x2
    fld f23, -2048(x7)
    csrrci x2, fcsr, 0x1F
    sd x2, 48(x1)
        fmv.x.d x3, f23
    fsd f23, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffffff7fffff)

    # Testcase 24:  imm:0x800, result rd:x24(0xfffffffffeffffff)
    la  x6, test_data
    addi    x6, x6,192
    li     x2, MASK_XLEN(2048)
    add    x6, x6, x2
    fld f24, -2048(x6)
    csrrci x2, fcsr, 0x1F
    sd x2, 64(x1)
        fmv.x.d x3, f24
    fsd f24, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xfffffffffeffffff)



    

    RVTEST_SIGBASE(x6,signature_6_0)

    # Testcase 25:  imm:0x800, result rd:x25(0xfffffffffdffffff)
    la  x5, test_data
    addi    x5, x5,200
    li     x7, MASK_XLEN(2048)
    add    x5, x5, x7
    fld f25, -2048(x5)
    csrrci x7, fcsr, 0x1F
    sd x7, 0(x6)
        fmv.x.d x8, f25
    fsd f25, 8(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xfffffffffdffffff)

    # Testcase 26:  imm:0x800, result rd:x26(0xfffffffffeffffff)
    la  x4, test_data
    addi    x4, x4,208
    li     x7, MASK_XLEN(2048)
    add    x4, x4, x7
    fld f26, -2048(x4)
    csrrci x7, fcsr, 0x1F
    sd x7, 16(x6)
        fmv.x.d x8, f26
    fsd f26, 24(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xfffffffffeffffff)

    # Testcase 27:  imm:0x800, result rd:x27(0xfffffffff7ffffff)
    la  x3, test_data
    addi    x3, x3,216
    li     x7, MASK_XLEN(2048)
    add    x3, x3, x7
    fld f27, -2048(x3)
    csrrci x7, fcsr, 0x1F
    sd x7, 32(x6)
        fmv.x.d x8, f27
    fsd f27, 40(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xfffffffff7ffffff)

    # Testcase 28:  imm:0x800, result rd:x28(0xffffffffefffffff)
    la  x2, test_data
    addi    x2, x2,224
    li     x7, MASK_XLEN(2048)
    add    x2, x2, x7
    fld f28, -2048(x2)
    csrrci x7, fcsr, 0x1F
    sd x7, 48(x6)
        fmv.x.d x8, f28
    fsd f28, 56(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffffffefffffff)

    # Testcase 29:  imm:0x800, result rd:x29(0xffffffffdfffffff)
    la  x1, test_data
    addi    x1, x1,232
    li     x7, MASK_XLEN(2048)
    add    x1, x1, x7
    fld f29, -2048(x1)
    csrrci x7, fcsr, 0x1F
    sd x7, 64(x6)
        fmv.x.d x8, f29
    fsd f29, 72(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffffffdfffffff)



    

    RVTEST_SIGBASE(x2,signature_7_0)

    # Testcase 30:  imm:0x0, result rd:x30(0xffffffffefffffff)
    la  x1, test_data
    addi    x1, x1,240
    li     x3, MASK_XLEN(0)
    add    x1, x1, x3
    fld f30, 0(x1)
    csrrci x3, fcsr, 0x1F
    sd x3, 0(x2)
        fmv.x.d x4, f30
    fsd f30, 8(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xffffffffefffffff)

	
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

	.dword 0xfffffffffffffffe
	.dword 0xfffffffffffffffd
	.dword 0xfffffffffffffffb
	.dword 0xfffffffffffffff7
	.dword 0xffffffffffffffef
	.dword 0xffffffffffffffdf
	.dword 0xffffffffffffffbf
	.dword 0xffffffffffffff7f
	.dword 0xfffffffffffffeff
	.dword 0xfffffffffffffdff
	.dword 0xfffffffffffffeff
	.dword 0xfffffffffffff7ff
	.dword 0xffffffffffffefff
	.dword 0xffffffffffffdfff
	.dword 0xffffffffffffefff
	.dword 0xffffffffffff7fff
	.dword 0xfffffffffffeffff
	.dword 0xfffffffffffdffff
	.dword 0xfffffffffffbffff
	.dword 0xfffffffffff7ffff
	.dword 0xffffffffffefffff
	.dword 0xffffffffffdfffff
	.dword 0xffffffffffbfffff
	.dword 0xffffffffff7fffff
	.dword 0xfffffffffeffffff
	.dword 0xfffffffffdffffff
	.dword 0xfffffffffeffffff
	.dword 0xfffffffff7ffffff
	.dword 0xffffffffefffffff
	.dword 0xffffffffdfffffff
	.dword 0xffffffffefffffff
	.dword 0xffffffff7fffffff
	.dword 0xffffffffffffffff
	.dword 0xfffffffeffffffff
	.dword 0xfffffffdffffffff
	.dword 0xfffffffbffffffff
	.dword 0xfffffff7ffffffff
	.dword 0xffffffefffffffff
	.dword 0xffffffdfffffffff
	.dword 0xffffffbfffffffff
	.dword 0xffffff7fffffffff
	.dword 0xfffffeffffffffff
	.dword 0xfffffdffffffffff
	.dword 0xfffffeffffffffff
	.dword 0xfffff7ffffffffff
	.dword 0xffffefffffffffff
	.dword 0xffffdfffffffffff
	.dword 0xffffefffffffffff
	.dword 0xffff7fffffffffff
	.dword 0xfffeffffffffffff
	.dword 0xfffdffffffffffff
	.dword 0xfffbffffffffffff
	.dword 0xfff7ffffffffffff
	.dword 0xffefffffffffffff
	.dword 0xffdfffffffffffff
	.dword 0xffbfffffffffffff
	.dword 0xff7fffffffffffff
	.dword 0xfeffffffffffffff
	.dword 0xfdffffffffffffff
	.dword 0xfeffffffffffffff
	.dword 0xf7ffffffffffffff
	.dword 0xefffffffffffffff
	.dword 0xdfffffffffffffff
	.dword 0xefffffffffffffff
	.dword 0x7fffffffffffffff
	.dword 0xffffffffffffffff
	.dword 0x0000000000000001
	.dword 0x0000000000000002
	.dword 0x0000000000000004
	.dword 0x0000000000000008
	.dword 0x0000000000000010
	.dword 0x0000000000000020
	.dword 0x0000000000000040
	.dword 0x0000000000000080
	.dword 0x0000000000000100
	.dword 0x0000000000000200
	.dword 0x0000000000000400
	.dword 0x0000000000000800
	.dword 0x0000000000001000
	.dword 0x0000000000002000
	.dword 0x0000000000004000
	.dword 0x0000000000008000
	.dword 0x0000000000010000
	.dword 0x0000000000020000
	.dword 0x0000000000040000
	.dword 0x0000000000080000
	.dword 0x0000000000100000
	.dword 0x0000000000200000
	.dword 0x0000000000400000
	.dword 0x0000000000800000
	.dword 0x0000000001000000
	.dword 0x0000000002000000
	.dword 0x0000000004000000
	.dword 0x0000000008000000
	.dword 0x0000000010000000
	.dword 0x0000000020000000
	.dword 0x0000000040000000
	.dword 0x0000000080000000
	.dword 0x0000000000000000
	.dword 0x0000000100000000
	.dword 0x0000000200000000
	.dword 0x0000000400000000
	.dword 0x0000000800000000
	.dword 0x0000001000000000
	.dword 0x0000002000000000
	.dword 0x0000004000000000
	.dword 0x0000008000000000
	.dword 0x0000010000000000
	.dword 0x0000020000000000
	.dword 0x0000040000000000
	.dword 0x0000080000000000
	.dword 0x0000100000000000
	.dword 0x0000200000000000
	.dword 0x0000400000000000
	.dword 0x0000800000000000
	.dword 0x0001000000000000
	.dword 0x0002000000000000
	.dword 0x0004000000000000
	.dword 0x0008000000000000
	.dword 0x0010000000000000
	.dword 0x0020000000000000
	.dword 0x0040000000000000
	.dword 0x0080000000000000
	.dword 0x0100000000000000
	.dword 0x0200000000000000
	.dword 0x0400000000000000
	.dword 0x0800000000000000
	.dword 0x1000000000000000
	.dword 0x2000000000000000
	.dword 0x4000000000000000
	.dword 0x8000000000000000
	.dword 0x0000000000000000

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

