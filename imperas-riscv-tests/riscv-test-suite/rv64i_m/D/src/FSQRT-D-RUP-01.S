// RISC-V Architectural Validation Test FSQRT-D-RUP-01
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
// Description: Testing instruction 'fsqrt.d'.

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


    
    RVTEST_CASE(0,"//check ISA:=regex(.*32.*);check ISA:=regex(.*I.*D.*);def TEST_CASE_1=True;",fsqrt.d)

    RVTEST_SIGBASE(x5,signature_1_0)

 
    # Testcase 0:  rs1:x30(0x40934a3d70a3d70a), result rd:x0(0x4041917279aebb7f)
    li  x6, MASK_XLEN(0x40934a3d70a3d70a)
    fmv.d.x f30, x6
    fsqrt.d f0, f30, rup
    csrrci x6, fcsr, 0x1F
    sd x6, 0(x5)
    fmv.x.d x7, f0
    fsd f0, 8(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x4041917279aebb7f)  

 
    # Testcase 1:  rs1:x29(0x0000000000000000), result rd:x1(0x0000000000000000)
    li  x6, MASK_XLEN(0x0)
    fmv.d.x f29, x6
    fsqrt.d f1, f29, rup
    csrrci x6, fcsr, 0x1F
    sd x6, 16(x5)
    fmv.x.d x7, f1
    fsd f1, 24(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x0000000000000000)  

 
    # Testcase 2:  rs1:x28(0x4194e5fec7333333), result rd:x2(0x40c24931c04638c4)
    li  x6, MASK_XLEN(0x4194e5fec7333333)
    fmv.d.x f28, x6
    fsqrt.d f2, f28, rup
    csrrci x6, fcsr, 0x1F
    sd x6, 32(x5)
    fmv.x.d x7, f2
    fsd f2, 40(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x40c24931c04638c4)  

 
    # Testcase 3:  rs1:x27(0xc03178d4fdf3b646), result rd:x3(0x7ff8000000000000)
    li  x6, MASK_XLEN(0xc03178d4fdf3b646)
    fmv.d.x f27, x6
    fsqrt.d f3, f27, rup
    csrrci x6, fcsr, 0x1F
    sd x6, 48(x5)
    fmv.x.d x7, f3
    fsd f3, 56(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x7ff8000000000000)  

 
    # Testcase 4:  rs1:x26(0x3f187bf7c82319e0), result rd:x4(0x3f83cae9744237cf)
    li  x6, MASK_XLEN(0x3f187bf7c82319e0)
    fmv.d.x f26, x6
    fsqrt.d f4, f26, rup
    csrrci x6, fcsr, 0x1F
    sd x6, 64(x5)
    fmv.x.d x7, f4
    fsd f4, 72(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x3f83cae9744237cf)  



    

    RVTEST_SIGBASE(x1,signature_2_0)

 
    # Testcase 5:  rs1:x25(0x4215f7421c388000), result rd:x5(0x4102bf41bd2d3f16)
    li  x2, MASK_XLEN(0x4215f7421c388000)
    fmv.d.x f25, x2
    fsqrt.d f5, f25, rup
    csrrci x2, fcsr, 0x1F
    sd x2, 0(x1)
    fmv.x.d x3, f5
    fsd f5, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x4102bf41bd2d3f16)  

 
    # Testcase 6:  rs1:x24(0x3ff0000000000000), result rd:x6(0x3ff0000000000000)
    li  x2, MASK_XLEN(0x3ff0000000000000)
    fmv.d.x f24, x2
    fsqrt.d f6, f24, rup
    csrrci x2, fcsr, 0x1F
    sd x2, 16(x1)
    fmv.x.d x3, f6
    fsd f6, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x3ff0000000000000)  

 
    # Testcase 7:  rs1:x23(0xc11bdedc00000000), result rd:x7(0x7ff8000000000000)
    li  x2, MASK_XLEN(0xc11bdedc00000000)
    fmv.d.x f23, x2
    fsqrt.d f7, f23, rup
    csrrci x2, fcsr, 0x1F
    sd x2, 32(x1)
    fmv.x.d x3, f7
    fsd f7, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x7ff8000000000000)  

 
    # Testcase 8:  rs1:x22(0x40934a3d70a3d70a), result rd:x8(0x4041917279aebb7f)
    li  x2, MASK_XLEN(0x40934a3d70a3d70a)
    fmv.d.x f22, x2
    fsqrt.d f8, f22, rup
    csrrci x2, fcsr, 0x1F
    sd x2, 48(x1)
    fmv.x.d x3, f8
    fsd f8, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x4041917279aebb7f)  

 
    # Testcase 9:  rs1:x21(0x0000000000000000), result rd:x9(0x0000000000000000)
    li  x2, MASK_XLEN(0x0)
    fmv.d.x f21, x2
    fsqrt.d f9, f21, rup
    csrrci x2, fcsr, 0x1F
    sd x2, 64(x1)
    fmv.x.d x3, f9
    fsd f9, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x0000000000000000)  



    

    RVTEST_SIGBASE(x1,signature_3_0)

 
    # Testcase 10:  rs1:x20(0x4194e5fec7333333), result rd:x10(0x40c24931c04638c4)
    li  x7, MASK_XLEN(0x4194e5fec7333333)
    fmv.d.x f20, x7
    fsqrt.d f10, f20, rup
    csrrci x7, fcsr, 0x1F
    sd x7, 0(x1)
    fmv.x.d x8, f10
    fsd f10, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x40c24931c04638c4)  

 
    # Testcase 11:  rs1:x19(0xc03178d4fdf3b646), result rd:x11(0x7ff8000000000000)
    li  x7, MASK_XLEN(0xc03178d4fdf3b646)
    fmv.d.x f19, x7
    fsqrt.d f11, f19, rup
    csrrci x7, fcsr, 0x1F
    sd x7, 16(x1)
    fmv.x.d x8, f11
    fsd f11, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x7ff8000000000000)  

 
    # Testcase 12:  rs1:x18(0x3f187bf7c82319e0), result rd:x12(0x3f83cae9744237cf)
    li  x7, MASK_XLEN(0x3f187bf7c82319e0)
    fmv.d.x f18, x7
    fsqrt.d f12, f18, rup
    csrrci x7, fcsr, 0x1F
    sd x7, 32(x1)
    fmv.x.d x8, f12
    fsd f12, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x3f83cae9744237cf)  

 
    # Testcase 13:  rs1:x17(0x4215f7421c388000), result rd:x13(0x4102bf41bd2d3f16)
    li  x7, MASK_XLEN(0x4215f7421c388000)
    fmv.d.x f17, x7
    fsqrt.d f13, f17, rup
    csrrci x7, fcsr, 0x1F
    sd x7, 48(x1)
    fmv.x.d x8, f13
    fsd f13, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x4102bf41bd2d3f16)  

 
    # Testcase 14:  rs1:x16(0x3ff0000000000000), result rd:x14(0x3ff0000000000000)
    li  x7, MASK_XLEN(0x3ff0000000000000)
    fmv.d.x f16, x7
    fsqrt.d f14, f16, rup
    csrrci x7, fcsr, 0x1F
    sd x7, 64(x1)
    fmv.x.d x8, f14
    fsd f14, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x3ff0000000000000)  



    

    RVTEST_SIGBASE(x2,signature_4_0)

 
    # Testcase 15:  rs1:x15(0xc11bdedc00000000), result rd:x15(0x7ff8000000000000)
    li  x3, MASK_XLEN(0xc11bdedc00000000)
    fmv.d.x f15, x3
    fsqrt.d f15, f15, rup
    csrrci x3, fcsr, 0x1F
    sd x3, 0(x2)
    fmv.x.d x4, f15
    fsd f15, 8(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x7ff8000000000000)  

 
    # Testcase 16:  rs1:x14(0x40934a3d70a3d70a), result rd:x16(0x4041917279aebb7f)
    li  x3, MASK_XLEN(0x40934a3d70a3d70a)
    fmv.d.x f14, x3
    fsqrt.d f16, f14, rup
    csrrci x3, fcsr, 0x1F
    sd x3, 16(x2)
    fmv.x.d x4, f16
    fsd f16, 24(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x4041917279aebb7f)  

 
    # Testcase 17:  rs1:x13(0x0000000000000000), result rd:x17(0x0000000000000000)
    li  x3, MASK_XLEN(0x0)
    fmv.d.x f13, x3
    fsqrt.d f17, f13, rup
    csrrci x3, fcsr, 0x1F
    sd x3, 32(x2)
    fmv.x.d x4, f17
    fsd f17, 40(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x0000000000000000)  

 
    # Testcase 18:  rs1:x12(0x4194e5fec7333333), result rd:x18(0x40c24931c04638c4)
    li  x3, MASK_XLEN(0x4194e5fec7333333)
    fmv.d.x f12, x3
    fsqrt.d f18, f12, rup
    csrrci x3, fcsr, 0x1F
    sd x3, 48(x2)
    fmv.x.d x4, f18
    fsd f18, 56(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x40c24931c04638c4)  

 
    # Testcase 19:  rs1:x11(0xc03178d4fdf3b646), result rd:x19(0x7ff8000000000000)
    li  x3, MASK_XLEN(0xc03178d4fdf3b646)
    fmv.d.x f11, x3
    fsqrt.d f19, f11, rup
    csrrci x3, fcsr, 0x1F
    sd x3, 64(x2)
    fmv.x.d x4, f19
    fsd f19, 72(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x7ff8000000000000)  



    

    RVTEST_SIGBASE(x1,signature_5_0)

 
    # Testcase 20:  rs1:x10(0x3f187bf7c82319e0), result rd:x20(0x3f83cae9744237cf)
    li  x2, MASK_XLEN(0x3f187bf7c82319e0)
    fmv.d.x f10, x2
    fsqrt.d f20, f10, rup
    csrrci x2, fcsr, 0x1F
    sd x2, 0(x1)
    fmv.x.d x3, f20
    fsd f20, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x3f83cae9744237cf)  

 
    # Testcase 21:  rs1:x9(0x4215f7421c388000), result rd:x21(0x4102bf41bd2d3f16)
    li  x2, MASK_XLEN(0x4215f7421c388000)
    fmv.d.x f9, x2
    fsqrt.d f21, f9, rup
    csrrci x2, fcsr, 0x1F
    sd x2, 16(x1)
    fmv.x.d x3, f21
    fsd f21, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x4102bf41bd2d3f16)  

 
    # Testcase 22:  rs1:x8(0x3ff0000000000000), result rd:x22(0x3ff0000000000000)
    li  x2, MASK_XLEN(0x3ff0000000000000)
    fmv.d.x f8, x2
    fsqrt.d f22, f8, rup
    csrrci x2, fcsr, 0x1F
    sd x2, 32(x1)
    fmv.x.d x3, f22
    fsd f22, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x3ff0000000000000)  

 
    # Testcase 23:  rs1:x7(0xc11bdedc00000000), result rd:x23(0x7ff8000000000000)
    li  x2, MASK_XLEN(0xc11bdedc00000000)
    fmv.d.x f7, x2
    fsqrt.d f23, f7, rup
    csrrci x2, fcsr, 0x1F
    sd x2, 48(x1)
    fmv.x.d x3, f23
    fsd f23, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x7ff8000000000000)  

 
    # Testcase 24:  rs1:x6(0x40934a3d70a3d70a), result rd:x24(0x4041917279aebb7f)
    li  x2, MASK_XLEN(0x40934a3d70a3d70a)
    fmv.d.x f6, x2
    fsqrt.d f24, f6, rup
    csrrci x2, fcsr, 0x1F
    sd x2, 64(x1)
    fmv.x.d x3, f24
    fsd f24, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x4041917279aebb7f)  



    

    RVTEST_SIGBASE(x6,signature_6_0)

 
    # Testcase 25:  rs1:x5(0x0000000000000000), result rd:x25(0x0000000000000000)
    li  x7, MASK_XLEN(0x0)
    fmv.d.x f5, x7
    fsqrt.d f25, f5, rup
    csrrci x7, fcsr, 0x1F
    sd x7, 0(x6)
    fmv.x.d x8, f25
    fsd f25, 8(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x0000000000000000)  

 
    # Testcase 26:  rs1:x4(0x4194e5fec7333333), result rd:x26(0x40c24931c04638c4)
    li  x7, MASK_XLEN(0x4194e5fec7333333)
    fmv.d.x f4, x7
    fsqrt.d f26, f4, rup
    csrrci x7, fcsr, 0x1F
    sd x7, 16(x6)
    fmv.x.d x8, f26
    fsd f26, 24(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x40c24931c04638c4)  

 
    # Testcase 27:  rs1:x3(0xc03178d4fdf3b646), result rd:x27(0x7ff8000000000000)
    li  x7, MASK_XLEN(0xc03178d4fdf3b646)
    fmv.d.x f3, x7
    fsqrt.d f27, f3, rup
    csrrci x7, fcsr, 0x1F
    sd x7, 32(x6)
    fmv.x.d x8, f27
    fsd f27, 40(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x7ff8000000000000)  

 
    # Testcase 28:  rs1:x2(0x3f187bf7c82319e0), result rd:x28(0x3f83cae9744237cf)
    li  x7, MASK_XLEN(0x3f187bf7c82319e0)
    fmv.d.x f2, x7
    fsqrt.d f28, f2, rup
    csrrci x7, fcsr, 0x1F
    sd x7, 48(x6)
    fmv.x.d x8, f28
    fsd f28, 56(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x3f83cae9744237cf)  

 
    # Testcase 29:  rs1:x1(0x4215f7421c388000), result rd:x29(0x4102bf41bd2d3f16)
    li  x7, MASK_XLEN(0x4215f7421c388000)
    fmv.d.x f1, x7
    fsqrt.d f29, f1, rup
    csrrci x7, fcsr, 0x1F
    sd x7, 64(x6)
    fmv.x.d x8, f29
    fsd f29, 72(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x4102bf41bd2d3f16)  



    

    RVTEST_SIGBASE(x1,signature_7_0)

 
    # Testcase 30:  rs1:x0(0x3ff0000000000000), result rd:x30(0x3ff0000000000000)
    li  x2, MASK_XLEN(0x3ff0000000000000)
    fmv.d.x f0, x2
    fsqrt.d f30, f0, rup
    csrrci x2, fcsr, 0x1F
    sd x2, 0(x1)
    fmv.x.d x3, f30
    fsd f30, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x3ff0000000000000)  

	
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

