// RISC-V Architectural Validation Test FSD-01
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
// Description: Testing instruction 'fsd'.

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


    
    RVTEST_CASE(0,"//check ISA:=regex(.*32.*);check ISA:=regex(.*I.*D.*);def TEST_CASE_1=True;",fsd)

    RVTEST_SIGBASE(x5,signature_1_0)

    # Clear memory
    sd      x0, 0(x5)
    # Load values and compute offsets
    li      x7, 0xc11bdedc00000000
    fmv.d.x f16, x7
    addi    x30, x5,0
    li     x6, MASK_XLEN(2048)
    add    x30, x30, x6
    # Test Instruction 
    fsd      f16, -2048(x30)
    # Check results:  mem[test_1_res+0] = 0xc11bdedc00000000
    ld x7, 0(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xc11bdedc00000000)

    # Clear memory
    sd      x0, 8(x5)
    # Load values and compute offsets
    li      x7, 0x3ff0000000000000
    fmv.d.x f15, x7
    addi    x29, x5,8
    li     x6, MASK_XLEN(2048)
    add    x29, x29, x6
    # Test Instruction 
    fsd      f15, -2048(x29)
    # Check results:  mem[test_1_res+8] = 0x3ff0000000000000
    ld x7, 8(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x3ff0000000000000)

    # Clear memory
    sd      x0, 16(x5)
    # Load values and compute offsets
    li      x7, 0x4215f7421c388000
    fmv.d.x f14, x7
    addi    x28, x5,16
    li     x6, MASK_XLEN(2048)
    add    x28, x28, x6
    # Test Instruction 
    fsd      f14, -2048(x28)
    # Check results:  mem[test_1_res+16] = 0x4215f7421c388000
    ld x7, 16(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x4215f7421c388000)

    # Clear memory
    sd      x0, 24(x5)
    # Load values and compute offsets
    li      x7, 0x3f187bf7c82319e0
    fmv.d.x f13, x7
    addi    x27, x5,24
    li     x6, MASK_XLEN(2048)
    add    x27, x27, x6
    # Test Instruction 
    fsd      f13, -2048(x27)
    # Check results:  mem[test_1_res+24] = 0x3f187bf7c82319e0
    ld x7, 24(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x3f187bf7c82319e0)

    # Clear memory
    sd      x0, 32(x5)
    # Load values and compute offsets
    li      x7, 0xc03178d4fdf3b646
    fmv.d.x f12, x7
    addi    x26, x5,32
    li     x6, MASK_XLEN(2048)
    add    x26, x26, x6
    # Test Instruction 
    fsd      f12, -2048(x26)
    # Check results:  mem[test_1_res+32] = 0xc03178d4fdf3b646
    ld x7, 32(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xc03178d4fdf3b646)



    

    RVTEST_SIGBASE(x1,signature_2_0)

    # Clear memory
    sd      x0, 0(x1)
    # Load values and compute offsets
    li      x3, 0x4194e5fec7333333
    fmv.d.x f11, x3
    addi    x25, x1,0
    li     x2, MASK_XLEN(2048)
    add    x25, x25, x2
    # Test Instruction 
    fsd      f11, -2048(x25)
    # Check results:  mem[test_2_res+0] = 0x4194e5fec7333333
    ld x3, 0(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x4194e5fec7333333)

    # Clear memory
    sd      x0, 8(x1)
    # Load values and compute offsets
    li      x3, 0x0
    fmv.d.x f10, x3
    addi    x24, x1,8
    li     x2, MASK_XLEN(0)
    add    x24, x24, x2
    # Test Instruction 
    fsd      f10, 0(x24)
    # Check results:  mem[test_2_res+8] = 0x0000000000000000
    ld x3, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x0000000000000000)

    # Clear memory
    sd      x0, 16(x1)
    # Load values and compute offsets
    li      x3, 0x40934a3d70a3d70a
    fmv.d.x f9, x3
    addi    x23, x1,16
    li     x2, MASK_XLEN(2048)
    add    x23, x23, x2
    # Test Instruction 
    fsd      f9, -2048(x23)
    # Check results:  mem[test_2_res+16] = 0x40934a3d70a3d70a
    ld x3, 16(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x40934a3d70a3d70a)

    # Clear memory
    sd      x0, 24(x1)
    # Load values and compute offsets
    li      x3, 0xc11bdedc00000000
    fmv.d.x f8, x3
    addi    x22, x1,24
    li     x2, MASK_XLEN(2048)
    add    x22, x22, x2
    # Test Instruction 
    fsd      f8, -2048(x22)
    # Check results:  mem[test_2_res+24] = 0xc11bdedc00000000
    ld x3, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xc11bdedc00000000)

    # Clear memory
    sd      x0, 32(x1)
    # Load values and compute offsets
    li      x3, 0x3ff0000000000000
    fmv.d.x f7, x3
    addi    x21, x1,32
    li     x2, MASK_XLEN(2048)
    add    x21, x21, x2
    # Test Instruction 
    fsd      f7, -2048(x21)
    # Check results:  mem[test_2_res+32] = 0x3ff0000000000000
    ld x3, 32(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x3ff0000000000000)



    

    RVTEST_SIGBASE(x1,signature_3_0)

    # Clear memory
    sd      x0, 0(x1)
    # Load values and compute offsets
    li      x8, 0x4215f7421c388000
    fmv.d.x f6, x8
    addi    x20, x1,0
    li     x7, MASK_XLEN(2048)
    add    x20, x20, x7
    # Test Instruction 
    fsd      f6, -2048(x20)
    # Check results:  mem[test_3_res+0] = 0x4215f7421c388000
    ld x8, 0(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x4215f7421c388000)

    # Clear memory
    sd      x0, 8(x1)
    # Load values and compute offsets
    li      x8, 0x3f187bf7c82319e0
    fmv.d.x f5, x8
    addi    x19, x1,8
    li     x7, MASK_XLEN(2048)
    add    x19, x19, x7
    # Test Instruction 
    fsd      f5, -2048(x19)
    # Check results:  mem[test_3_res+8] = 0x3f187bf7c82319e0
    ld x8, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x3f187bf7c82319e0)

    # Clear memory
    sd      x0, 16(x1)
    # Load values and compute offsets
    li      x8, 0xc03178d4fdf3b646
    fmv.d.x f4, x8
    addi    x18, x1,16
    li     x7, MASK_XLEN(2048)
    add    x18, x18, x7
    # Test Instruction 
    fsd      f4, -2048(x18)
    # Check results:  mem[test_3_res+16] = 0xc03178d4fdf3b646
    ld x8, 16(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xc03178d4fdf3b646)

    # Clear memory
    sd      x0, 24(x1)
    # Load values and compute offsets
    li      x8, 0x4194e5fec7333333
    fmv.d.x f3, x8
    addi    x17, x1,24
    li     x7, MASK_XLEN(2048)
    add    x17, x17, x7
    # Test Instruction 
    fsd      f3, -2048(x17)
    # Check results:  mem[test_3_res+24] = 0x4194e5fec7333333
    ld x8, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x4194e5fec7333333)

    # Clear memory
    sd      x0, 32(x1)
    # Load values and compute offsets
    li      x8, 0x0
    fmv.d.x f2, x8
    addi    x16, x1,32
    li     x7, MASK_XLEN(0)
    add    x16, x16, x7
    # Test Instruction 
    fsd      f2, 0(x16)
    # Check results:  mem[test_3_res+32] = 0x0000000000000000
    ld x8, 32(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x0000000000000000)



    

    RVTEST_SIGBASE(x2,signature_4_0)

    # Clear memory
    sd      x0, 0(x2)
    # Load values and compute offsets
    li      x4, 0x40934a3d70a3d70a
    fmv.d.x f1, x4
    addi    x15, x2,0
    li     x3, MASK_XLEN(2048)
    add    x15, x15, x3
    # Test Instruction 
    fsd      f1, -2048(x15)
    # Check results:  mem[test_4_res+0] = 0x40934a3d70a3d70a
    ld x4, 0(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x40934a3d70a3d70a)

    # Clear memory
    sd      x0, 8(x2)
    # Load values and compute offsets
    li      x4, 0xc11bdedc00000000
    fmv.d.x f0, x4
    addi    x14, x2,8
    li     x3, MASK_XLEN(2048)
    add    x14, x14, x3
    # Test Instruction 
    fsd      f0, -2048(x14)
    # Check results:  mem[test_4_res+8] = 0xc11bdedc00000000
    ld x4, 8(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xc11bdedc00000000)

    # Clear memory
    sd      x0, 16(x2)
    # Load values and compute offsets
    li      x4, 0x3ff0000000000000
    fmv.d.x f30, x4
    addi    x13, x2,16
    li     x3, MASK_XLEN(2048)
    add    x13, x13, x3
    # Test Instruction 
    fsd      f30, -2048(x13)
    # Check results:  mem[test_4_res+16] = 0x3ff0000000000000
    ld x4, 16(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x3ff0000000000000)

    # Clear memory
    sd      x0, 24(x2)
    # Load values and compute offsets
    li      x4, 0x4215f7421c388000
    fmv.d.x f29, x4
    addi    x12, x2,24
    li     x3, MASK_XLEN(2048)
    add    x12, x12, x3
    # Test Instruction 
    fsd      f29, -2048(x12)
    # Check results:  mem[test_4_res+24] = 0x4215f7421c388000
    ld x4, 24(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x4215f7421c388000)

    # Clear memory
    sd      x0, 32(x2)
    # Load values and compute offsets
    li      x4, 0x3f187bf7c82319e0
    fmv.d.x f28, x4
    addi    x11, x2,32
    li     x3, MASK_XLEN(2048)
    add    x11, x11, x3
    # Test Instruction 
    fsd      f28, -2048(x11)
    # Check results:  mem[test_4_res+32] = 0x3f187bf7c82319e0
    ld x4, 32(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x3f187bf7c82319e0)



    

    RVTEST_SIGBASE(x1,signature_5_0)

    # Clear memory
    sd      x0, 0(x1)
    # Load values and compute offsets
    li      x3, 0xc03178d4fdf3b646
    fmv.d.x f27, x3
    addi    x10, x1,0
    li     x2, MASK_XLEN(2048)
    add    x10, x10, x2
    # Test Instruction 
    fsd      f27, -2048(x10)
    # Check results:  mem[test_5_res+0] = 0xc03178d4fdf3b646
    ld x3, 0(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xc03178d4fdf3b646)

    # Clear memory
    sd      x0, 8(x1)
    # Load values and compute offsets
    li      x3, 0x4194e5fec7333333
    fmv.d.x f26, x3
    addi    x9, x1,8
    li     x2, MASK_XLEN(2048)
    add    x9, x9, x2
    # Test Instruction 
    fsd      f26, -2048(x9)
    # Check results:  mem[test_5_res+8] = 0x4194e5fec7333333
    ld x3, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x4194e5fec7333333)

    # Clear memory
    sd      x0, 16(x1)
    # Load values and compute offsets
    li      x3, 0x0
    fmv.d.x f25, x3
    addi    x8, x1,16
    li     x2, MASK_XLEN(0)
    add    x8, x8, x2
    # Test Instruction 
    fsd      f25, 0(x8)
    # Check results:  mem[test_5_res+16] = 0x0000000000000000
    ld x3, 16(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x0000000000000000)

    # Clear memory
    sd      x0, 24(x1)
    # Load values and compute offsets
    li      x3, 0x40934a3d70a3d70a
    fmv.d.x f24, x3
    addi    x7, x1,24
    li     x2, MASK_XLEN(2048)
    add    x7, x7, x2
    # Test Instruction 
    fsd      f24, -2048(x7)
    # Check results:  mem[test_5_res+24] = 0x40934a3d70a3d70a
    ld x3, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x40934a3d70a3d70a)

    # Clear memory
    sd      x0, 32(x1)
    # Load values and compute offsets
    li      x3, 0xc11bdedc00000000
    fmv.d.x f23, x3
    addi    x6, x1,32
    li     x2, MASK_XLEN(2048)
    add    x6, x6, x2
    # Test Instruction 
    fsd      f23, -2048(x6)
    # Check results:  mem[test_5_res+32] = 0xc11bdedc00000000
    ld x3, 32(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xc11bdedc00000000)



    

    RVTEST_SIGBASE(x6,signature_6_0)

    # Clear memory
    sd      x0, 0(x6)
    # Load values and compute offsets
    li      x8, 0x3ff0000000000000
    fmv.d.x f22, x8
    addi    x5, x6,0
    li     x7, MASK_XLEN(2048)
    add    x5, x5, x7
    # Test Instruction 
    fsd      f22, -2048(x5)
    # Check results:  mem[test_6_res+0] = 0x3ff0000000000000
    ld x8, 0(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x3ff0000000000000)

    # Clear memory
    sd      x0, 8(x6)
    # Load values and compute offsets
    li      x8, 0x4215f7421c388000
    fmv.d.x f21, x8
    addi    x4, x6,8
    li     x7, MASK_XLEN(2048)
    add    x4, x4, x7
    # Test Instruction 
    fsd      f21, -2048(x4)
    # Check results:  mem[test_6_res+8] = 0x4215f7421c388000
    ld x8, 8(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x4215f7421c388000)

    # Clear memory
    sd      x0, 16(x6)
    # Load values and compute offsets
    li      x8, 0x3f187bf7c82319e0
    fmv.d.x f20, x8
    addi    x3, x6,16
    li     x7, MASK_XLEN(2048)
    add    x3, x3, x7
    # Test Instruction 
    fsd      f20, -2048(x3)
    # Check results:  mem[test_6_res+16] = 0x3f187bf7c82319e0
    ld x8, 16(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x3f187bf7c82319e0)

    # Clear memory
    sd      x0, 24(x6)
    # Load values and compute offsets
    li      x8, 0xc03178d4fdf3b646
    fmv.d.x f19, x8
    addi    x2, x6,24
    li     x7, MASK_XLEN(2048)
    add    x2, x2, x7
    # Test Instruction 
    fsd      f19, -2048(x2)
    # Check results:  mem[test_6_res+24] = 0xc03178d4fdf3b646
    ld x8, 24(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xc03178d4fdf3b646)

    # Clear memory
    sd      x0, 32(x6)
    # Load values and compute offsets
    li      x8, 0x4194e5fec7333333
    fmv.d.x f18, x8
    addi    x1, x6,32
    li     x7, MASK_XLEN(2048)
    add    x1, x1, x7
    # Test Instruction 
    fsd      f18, -2048(x1)
    # Check results:  mem[test_6_res+32] = 0x4194e5fec7333333
    ld x8, 32(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x4194e5fec7333333)



    

    RVTEST_SIGBASE(x2,signature_7_0)

    # Clear memory
    sd      x0, 0(x2)
    # Load values and compute offsets
    li      x4, 0x0
    fmv.d.x f17, x4
    addi    x1, x2,0
    li     x3, MASK_XLEN(0)
    add    x1, x1, x3
    # Test Instruction 
    fsd      f17, 0(x1)
    # Check results:  mem[test_7_res+0] = 0x0000000000000000
    ld x4, 0(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x0000000000000000)

	
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

