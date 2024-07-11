// RISC-V Architectural Validation Test FSW-01
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
// Description: Testing instruction 'fsw'.

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


    
    RVTEST_CASE(0,"//check ISA:=regex(.*32.*);check ISA:=regex(.*I.*F.*);def TEST_CASE_1=True;",fsw)

    RVTEST_SIGBASE(x5,signature_1_0)

    # Clear memory
    sw      x0, 0(x5)
    # Load values and compute offsets
    li      x7, 0xbf800000
    fmv.w.x f16, x7
    addi    x30, x5,0
    li     x6, MASK_XLEN(2048)
    add    x30, x30, x6
    # Test Instruction 
    fsw      f16, -2048(x30)
    # Check results:  mem[test_1_res+0] = 0xbf800000
    lw x7, 0(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xbf800000)

    # Clear memory
    sw      x0, 4(x5)
    # Load values and compute offsets
    li      x7, 0x3a2b48ef
    fmv.w.x f15, x7
    addi    x29, x5,4
    li     x6, MASK_XLEN(2048)
    add    x29, x29, x6
    # Test Instruction 
    fsw      f15, -2048(x29)
    # Check results:  mem[test_1_res+4] = 0x3a2b48ef
    lw x7, 4(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x3a2b48ef)

    # Clear memory
    sw      x0, 8(x5)
    # Load values and compute offsets
    li      x7, 0x3f800000
    fmv.w.x f14, x7
    addi    x28, x5,8
    li     x6, MASK_XLEN(2048)
    add    x28, x28, x6
    # Test Instruction 
    fsw      f14, -2048(x28)
    # Check results:  mem[test_1_res+8] = 0x3f800000
    lw x7, 8(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x3f800000)

    # Clear memory
    sw      x0, 12(x5)
    # Load values and compute offsets
    li      x7, 0x4c50e7e7
    fmv.w.x f13, x7
    addi    x27, x5,12
    li     x6, MASK_XLEN(2048)
    add    x27, x27, x6
    # Test Instruction 
    fsw      f13, -2048(x27)
    # Check results:  mem[test_1_res+12] = 0x4c50e7e7
    lw x7, 12(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x4c50e7e7)

    # Clear memory
    sw      x0, 16(x5)
    # Load values and compute offsets
    li      x7, 0xc61a5229
    fmv.w.x f12, x7
    addi    x26, x5,16
    li     x6, MASK_XLEN(2048)
    add    x26, x26, x6
    # Test Instruction 
    fsw      f12, -2048(x26)
    # Check results:  mem[test_1_res+16] = 0xc61a5229
    lw x7, 16(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xc61a5229)



    

    RVTEST_SIGBASE(x1,signature_2_0)

    # Clear memory
    sw      x0, 0(x1)
    # Load values and compute offsets
    li      x3, 0xc1458794
    fmv.w.x f11, x3
    addi    x25, x1,0
    li     x2, MASK_XLEN(2048)
    add    x25, x25, x2
    # Test Instruction 
    fsw      f11, -2048(x25)
    # Check results:  mem[test_2_res+0] = 0xc1458794
    lw x3, 0(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xc1458794)

    # Clear memory
    sw      x0, 4(x1)
    # Load values and compute offsets
    li      x3, 0x0
    fmv.w.x f10, x3
    addi    x24, x1,4
    li     x2, MASK_XLEN(0)
    add    x24, x24, x2
    # Test Instruction 
    fsw      f10, 0(x24)
    # Check results:  mem[test_2_res+4] = 0x00000000
    lw x3, 4(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x00000000)

    # Clear memory
    sw      x0, 8(x1)
    # Load values and compute offsets
    li      x3, 0x3f9e0419
    fmv.w.x f9, x3
    addi    x23, x1,8
    li     x2, MASK_XLEN(2048)
    add    x23, x23, x2
    # Test Instruction 
    fsw      f9, -2048(x23)
    # Check results:  mem[test_2_res+8] = 0x3f9e0419
    lw x3, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x3f9e0419)

    # Clear memory
    sw      x0, 12(x1)
    # Load values and compute offsets
    li      x3, 0xbf800000
    fmv.w.x f8, x3
    addi    x22, x1,12
    li     x2, MASK_XLEN(2048)
    add    x22, x22, x2
    # Test Instruction 
    fsw      f8, -2048(x22)
    # Check results:  mem[test_2_res+12] = 0xbf800000
    lw x3, 12(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xbf800000)

    # Clear memory
    sw      x0, 16(x1)
    # Load values and compute offsets
    li      x3, 0x3a2b48ef
    fmv.w.x f7, x3
    addi    x21, x1,16
    li     x2, MASK_XLEN(2048)
    add    x21, x21, x2
    # Test Instruction 
    fsw      f7, -2048(x21)
    # Check results:  mem[test_2_res+16] = 0x3a2b48ef
    lw x3, 16(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x3a2b48ef)



    

    RVTEST_SIGBASE(x1,signature_3_0)

    # Clear memory
    sw      x0, 0(x1)
    # Load values and compute offsets
    li      x8, 0x3f800000
    fmv.w.x f6, x8
    addi    x20, x1,0
    li     x7, MASK_XLEN(2048)
    add    x20, x20, x7
    # Test Instruction 
    fsw      f6, -2048(x20)
    # Check results:  mem[test_3_res+0] = 0x3f800000
    lw x8, 0(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x3f800000)

    # Clear memory
    sw      x0, 4(x1)
    # Load values and compute offsets
    li      x8, 0x4c50e7e7
    fmv.w.x f5, x8
    addi    x19, x1,4
    li     x7, MASK_XLEN(2048)
    add    x19, x19, x7
    # Test Instruction 
    fsw      f5, -2048(x19)
    # Check results:  mem[test_3_res+4] = 0x4c50e7e7
    lw x8, 4(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x4c50e7e7)

    # Clear memory
    sw      x0, 8(x1)
    # Load values and compute offsets
    li      x8, 0xc61a5229
    fmv.w.x f4, x8
    addi    x18, x1,8
    li     x7, MASK_XLEN(2048)
    add    x18, x18, x7
    # Test Instruction 
    fsw      f4, -2048(x18)
    # Check results:  mem[test_3_res+8] = 0xc61a5229
    lw x8, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xc61a5229)

    # Clear memory
    sw      x0, 12(x1)
    # Load values and compute offsets
    li      x8, 0xc1458794
    fmv.w.x f3, x8
    addi    x17, x1,12
    li     x7, MASK_XLEN(2048)
    add    x17, x17, x7
    # Test Instruction 
    fsw      f3, -2048(x17)
    # Check results:  mem[test_3_res+12] = 0xc1458794
    lw x8, 12(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xc1458794)

    # Clear memory
    sw      x0, 16(x1)
    # Load values and compute offsets
    li      x8, 0x0
    fmv.w.x f2, x8
    addi    x16, x1,16
    li     x7, MASK_XLEN(0)
    add    x16, x16, x7
    # Test Instruction 
    fsw      f2, 0(x16)
    # Check results:  mem[test_3_res+16] = 0x00000000
    lw x8, 16(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x00000000)



    

    RVTEST_SIGBASE(x2,signature_4_0)

    # Clear memory
    sw      x0, 0(x2)
    # Load values and compute offsets
    li      x4, 0x3f9e0419
    fmv.w.x f1, x4
    addi    x15, x2,0
    li     x3, MASK_XLEN(2048)
    add    x15, x15, x3
    # Test Instruction 
    fsw      f1, -2048(x15)
    # Check results:  mem[test_4_res+0] = 0x3f9e0419
    lw x4, 0(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x3f9e0419)

    # Clear memory
    sw      x0, 4(x2)
    # Load values and compute offsets
    li      x4, 0xbf800000
    fmv.w.x f0, x4
    addi    x14, x2,4
    li     x3, MASK_XLEN(2048)
    add    x14, x14, x3
    # Test Instruction 
    fsw      f0, -2048(x14)
    # Check results:  mem[test_4_res+4] = 0xbf800000
    lw x4, 4(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xbf800000)

    # Clear memory
    sw      x0, 8(x2)
    # Load values and compute offsets
    li      x4, 0x3a2b48ef
    fmv.w.x f30, x4
    addi    x13, x2,8
    li     x3, MASK_XLEN(2048)
    add    x13, x13, x3
    # Test Instruction 
    fsw      f30, -2048(x13)
    # Check results:  mem[test_4_res+8] = 0x3a2b48ef
    lw x4, 8(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x3a2b48ef)

    # Clear memory
    sw      x0, 12(x2)
    # Load values and compute offsets
    li      x4, 0x3f800000
    fmv.w.x f29, x4
    addi    x12, x2,12
    li     x3, MASK_XLEN(2048)
    add    x12, x12, x3
    # Test Instruction 
    fsw      f29, -2048(x12)
    # Check results:  mem[test_4_res+12] = 0x3f800000
    lw x4, 12(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x3f800000)

    # Clear memory
    sw      x0, 16(x2)
    # Load values and compute offsets
    li      x4, 0x4c50e7e7
    fmv.w.x f28, x4
    addi    x11, x2,16
    li     x3, MASK_XLEN(2048)
    add    x11, x11, x3
    # Test Instruction 
    fsw      f28, -2048(x11)
    # Check results:  mem[test_4_res+16] = 0x4c50e7e7
    lw x4, 16(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x4c50e7e7)



    

    RVTEST_SIGBASE(x1,signature_5_0)

    # Clear memory
    sw      x0, 0(x1)
    # Load values and compute offsets
    li      x3, 0xc61a5229
    fmv.w.x f27, x3
    addi    x10, x1,0
    li     x2, MASK_XLEN(2048)
    add    x10, x10, x2
    # Test Instruction 
    fsw      f27, -2048(x10)
    # Check results:  mem[test_5_res+0] = 0xc61a5229
    lw x3, 0(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xc61a5229)

    # Clear memory
    sw      x0, 4(x1)
    # Load values and compute offsets
    li      x3, 0xc1458794
    fmv.w.x f26, x3
    addi    x9, x1,4
    li     x2, MASK_XLEN(2048)
    add    x9, x9, x2
    # Test Instruction 
    fsw      f26, -2048(x9)
    # Check results:  mem[test_5_res+4] = 0xc1458794
    lw x3, 4(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xc1458794)

    # Clear memory
    sw      x0, 8(x1)
    # Load values and compute offsets
    li      x3, 0x0
    fmv.w.x f25, x3
    addi    x8, x1,8
    li     x2, MASK_XLEN(0)
    add    x8, x8, x2
    # Test Instruction 
    fsw      f25, 0(x8)
    # Check results:  mem[test_5_res+8] = 0x00000000
    lw x3, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x00000000)

    # Clear memory
    sw      x0, 12(x1)
    # Load values and compute offsets
    li      x3, 0x3f9e0419
    fmv.w.x f24, x3
    addi    x7, x1,12
    li     x2, MASK_XLEN(2048)
    add    x7, x7, x2
    # Test Instruction 
    fsw      f24, -2048(x7)
    # Check results:  mem[test_5_res+12] = 0x3f9e0419
    lw x3, 12(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x3f9e0419)

    # Clear memory
    sw      x0, 16(x1)
    # Load values and compute offsets
    li      x3, 0xbf800000
    fmv.w.x f23, x3
    addi    x6, x1,16
    li     x2, MASK_XLEN(2048)
    add    x6, x6, x2
    # Test Instruction 
    fsw      f23, -2048(x6)
    # Check results:  mem[test_5_res+16] = 0xbf800000
    lw x3, 16(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xbf800000)



    

    RVTEST_SIGBASE(x6,signature_6_0)

    # Clear memory
    sw      x0, 0(x6)
    # Load values and compute offsets
    li      x8, 0x3a2b48ef
    fmv.w.x f22, x8
    addi    x5, x6,0
    li     x7, MASK_XLEN(2048)
    add    x5, x5, x7
    # Test Instruction 
    fsw      f22, -2048(x5)
    # Check results:  mem[test_6_res+0] = 0x3a2b48ef
    lw x8, 0(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x3a2b48ef)

    # Clear memory
    sw      x0, 4(x6)
    # Load values and compute offsets
    li      x8, 0x3f800000
    fmv.w.x f21, x8
    addi    x4, x6,4
    li     x7, MASK_XLEN(2048)
    add    x4, x4, x7
    # Test Instruction 
    fsw      f21, -2048(x4)
    # Check results:  mem[test_6_res+4] = 0x3f800000
    lw x8, 4(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x3f800000)

    # Clear memory
    sw      x0, 8(x6)
    # Load values and compute offsets
    li      x8, 0x4c50e7e7
    fmv.w.x f20, x8
    addi    x3, x6,8
    li     x7, MASK_XLEN(2048)
    add    x3, x3, x7
    # Test Instruction 
    fsw      f20, -2048(x3)
    # Check results:  mem[test_6_res+8] = 0x4c50e7e7
    lw x8, 8(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x4c50e7e7)

    # Clear memory
    sw      x0, 12(x6)
    # Load values and compute offsets
    li      x8, 0xc61a5229
    fmv.w.x f19, x8
    addi    x2, x6,12
    li     x7, MASK_XLEN(2048)
    add    x2, x2, x7
    # Test Instruction 
    fsw      f19, -2048(x2)
    # Check results:  mem[test_6_res+12] = 0xc61a5229
    lw x8, 12(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xc61a5229)

    # Clear memory
    sw      x0, 16(x6)
    # Load values and compute offsets
    li      x8, 0xc1458794
    fmv.w.x f18, x8
    addi    x1, x6,16
    li     x7, MASK_XLEN(2048)
    add    x1, x1, x7
    # Test Instruction 
    fsw      f18, -2048(x1)
    # Check results:  mem[test_6_res+16] = 0xc1458794
    lw x8, 16(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xc1458794)



    

    RVTEST_SIGBASE(x2,signature_7_0)

    # Clear memory
    sw      x0, 0(x2)
    # Load values and compute offsets
    li      x4, 0x0
    fmv.w.x f17, x4
    addi    x1, x2,0
    li     x3, MASK_XLEN(0)
    add    x1, x1, x3
    # Test Instruction 
    fsw      f17, 0(x1)
    # Check results:  mem[test_7_res+0] = 0x00000000
    lw x4, 0(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x00000000)

	
#endif


RVTEST_CODE_END
RVMODEL_HALT

RVTEST_DATA_BEGIN
.align 4
rvtest_data:
.word 0xbabecafe

# Input data section.
	.data

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

