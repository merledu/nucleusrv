// RISC-V Architectural Validation Test FCVT-S-D-RDN-01
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
// Description: Testing instruction 'fcvt.s.d'.

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


    
    RVTEST_CASE(0,"//check ISA:=regex(.*32.*);check ISA:=regex(.*I.*D.*);def TEST_CASE_1=True;",fcvt.s.d)

    RVTEST_SIGBASE(x5,signature_1_0)

 
    # Testcase 0:  rs1:x30(0x40934a3d70a3d70a), result rd:x0(0xffffffff449a51eb)
    li  x6, MASK_XLEN(0x40934a3d70a3d70a)
    fmv.d.x f30, x6
    fcvt.s.d f0, f30, rdn
    csrrci x6, fcsr, 0x1F
    sd x6, 0(x5)
    fmv.x.d x7, f0
    fsd f0, 8(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xffffffff449a51eb)  

 
    # Testcase 1:  rs1:x29(0x0000000000000000), result rd:x1(0xffffffff00000000)
    li  x6, MASK_XLEN(0x0)
    fmv.d.x f29, x6
    fcvt.s.d f1, f29, rdn
    csrrci x6, fcsr, 0x1F
    sd x6, 16(x5)
    fmv.x.d x7, f1
    fsd f1, 24(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xffffffff00000000)  

 
    # Testcase 2:  rs1:x28(0x4194e5fec7333333), result rd:x2(0xffffffff4ca72ff6)
    li  x6, MASK_XLEN(0x4194e5fec7333333)
    fmv.d.x f28, x6
    fcvt.s.d f2, f28, rdn
    csrrci x6, fcsr, 0x1F
    sd x6, 32(x5)
    fmv.x.d x7, f2
    fsd f2, 40(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xffffffff4ca72ff6)  

 
    # Testcase 3:  rs1:x27(0xc03178d4fdf3b646), result rd:x3(0xffffffffc18bc6a8)
    li  x6, MASK_XLEN(0xc03178d4fdf3b646)
    fmv.d.x f27, x6
    fcvt.s.d f3, f27, rdn
    csrrci x6, fcsr, 0x1F
    sd x6, 48(x5)
    fmv.x.d x7, f3
    fsd f3, 56(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xffffffffc18bc6a8)  

 
    # Testcase 4:  rs1:x26(0x3f187bf7c82319e0), result rd:x4(0xffffffff38c3dfbe)
    li  x6, MASK_XLEN(0x3f187bf7c82319e0)
    fmv.d.x f26, x6
    fcvt.s.d f4, f26, rdn
    csrrci x6, fcsr, 0x1F
    sd x6, 64(x5)
    fmv.x.d x7, f4
    fsd f4, 72(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xffffffff38c3dfbe)  



    

    RVTEST_SIGBASE(x1,signature_2_0)

 
    # Testcase 5:  rs1:x25(0x4215f7421c388000), result rd:x5(0xffffffff50afba10)
    li  x2, MASK_XLEN(0x4215f7421c388000)
    fmv.d.x f25, x2
    fcvt.s.d f5, f25, rdn
    csrrci x2, fcsr, 0x1F
    sd x2, 0(x1)
    fmv.x.d x3, f5
    fsd f5, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffff50afba10)  

 
    # Testcase 6:  rs1:x24(0x3ff0000000000000), result rd:x6(0xffffffff3f800000)
    li  x2, MASK_XLEN(0x3ff0000000000000)
    fmv.d.x f24, x2
    fcvt.s.d f6, f24, rdn
    csrrci x2, fcsr, 0x1F
    sd x2, 16(x1)
    fmv.x.d x3, f6
    fsd f6, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffff3f800000)  

 
    # Testcase 7:  rs1:x23(0xc11bdedc00000000), result rd:x7(0xffffffffc8def6e0)
    li  x2, MASK_XLEN(0xc11bdedc00000000)
    fmv.d.x f23, x2
    fcvt.s.d f7, f23, rdn
    csrrci x2, fcsr, 0x1F
    sd x2, 32(x1)
    fmv.x.d x3, f7
    fsd f7, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffffc8def6e0)  

 
    # Testcase 8:  rs1:x22(0x40934a3d70a3d70a), result rd:x8(0xffffffff449a51eb)
    li  x2, MASK_XLEN(0x40934a3d70a3d70a)
    fmv.d.x f22, x2
    fcvt.s.d f8, f22, rdn
    csrrci x2, fcsr, 0x1F
    sd x2, 48(x1)
    fmv.x.d x3, f8
    fsd f8, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffff449a51eb)  

 
    # Testcase 9:  rs1:x21(0x0000000000000000), result rd:x9(0xffffffff00000000)
    li  x2, MASK_XLEN(0x0)
    fmv.d.x f21, x2
    fcvt.s.d f9, f21, rdn
    csrrci x2, fcsr, 0x1F
    sd x2, 64(x1)
    fmv.x.d x3, f9
    fsd f9, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffff00000000)  



    

    RVTEST_SIGBASE(x1,signature_3_0)

 
    # Testcase 10:  rs1:x20(0x4194e5fec7333333), result rd:x10(0xffffffff4ca72ff6)
    li  x7, MASK_XLEN(0x4194e5fec7333333)
    fmv.d.x f20, x7
    fcvt.s.d f10, f20, rdn
    csrrci x7, fcsr, 0x1F
    sd x7, 0(x1)
    fmv.x.d x8, f10
    fsd f10, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffffff4ca72ff6)  

 
    # Testcase 11:  rs1:x19(0xc03178d4fdf3b646), result rd:x11(0xffffffffc18bc6a8)
    li  x7, MASK_XLEN(0xc03178d4fdf3b646)
    fmv.d.x f19, x7
    fcvt.s.d f11, f19, rdn
    csrrci x7, fcsr, 0x1F
    sd x7, 16(x1)
    fmv.x.d x8, f11
    fsd f11, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffffffc18bc6a8)  

 
    # Testcase 12:  rs1:x18(0x3f187bf7c82319e0), result rd:x12(0xffffffff38c3dfbe)
    li  x7, MASK_XLEN(0x3f187bf7c82319e0)
    fmv.d.x f18, x7
    fcvt.s.d f12, f18, rdn
    csrrci x7, fcsr, 0x1F
    sd x7, 32(x1)
    fmv.x.d x8, f12
    fsd f12, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffffff38c3dfbe)  

 
    # Testcase 13:  rs1:x17(0x4215f7421c388000), result rd:x13(0xffffffff50afba10)
    li  x7, MASK_XLEN(0x4215f7421c388000)
    fmv.d.x f17, x7
    fcvt.s.d f13, f17, rdn
    csrrci x7, fcsr, 0x1F
    sd x7, 48(x1)
    fmv.x.d x8, f13
    fsd f13, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffffff50afba10)  

 
    # Testcase 14:  rs1:x16(0x3ff0000000000000), result rd:x14(0xffffffff3f800000)
    li  x7, MASK_XLEN(0x3ff0000000000000)
    fmv.d.x f16, x7
    fcvt.s.d f14, f16, rdn
    csrrci x7, fcsr, 0x1F
    sd x7, 64(x1)
    fmv.x.d x8, f14
    fsd f14, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffffff3f800000)  



    

    RVTEST_SIGBASE(x2,signature_4_0)

 
    # Testcase 15:  rs1:x15(0xc11bdedc00000000), result rd:x15(0xffffffffc8def6e0)
    li  x3, MASK_XLEN(0xc11bdedc00000000)
    fmv.d.x f15, x3
    fcvt.s.d f15, f15, rdn
    csrrci x3, fcsr, 0x1F
    sd x3, 0(x2)
    fmv.x.d x4, f15
    fsd f15, 8(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xffffffffc8def6e0)  

 
    # Testcase 16:  rs1:x14(0x40934a3d70a3d70a), result rd:x16(0xffffffff449a51eb)
    li  x3, MASK_XLEN(0x40934a3d70a3d70a)
    fmv.d.x f14, x3
    fcvt.s.d f16, f14, rdn
    csrrci x3, fcsr, 0x1F
    sd x3, 16(x2)
    fmv.x.d x4, f16
    fsd f16, 24(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xffffffff449a51eb)  

 
    # Testcase 17:  rs1:x13(0x0000000000000000), result rd:x17(0xffffffff00000000)
    li  x3, MASK_XLEN(0x0)
    fmv.d.x f13, x3
    fcvt.s.d f17, f13, rdn
    csrrci x3, fcsr, 0x1F
    sd x3, 32(x2)
    fmv.x.d x4, f17
    fsd f17, 40(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xffffffff00000000)  

 
    # Testcase 18:  rs1:x12(0x4194e5fec7333333), result rd:x18(0xffffffff4ca72ff6)
    li  x3, MASK_XLEN(0x4194e5fec7333333)
    fmv.d.x f12, x3
    fcvt.s.d f18, f12, rdn
    csrrci x3, fcsr, 0x1F
    sd x3, 48(x2)
    fmv.x.d x4, f18
    fsd f18, 56(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xffffffff4ca72ff6)  

 
    # Testcase 19:  rs1:x11(0xc03178d4fdf3b646), result rd:x19(0xffffffffc18bc6a8)
    li  x3, MASK_XLEN(0xc03178d4fdf3b646)
    fmv.d.x f11, x3
    fcvt.s.d f19, f11, rdn
    csrrci x3, fcsr, 0x1F
    sd x3, 64(x2)
    fmv.x.d x4, f19
    fsd f19, 72(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xffffffffc18bc6a8)  



    

    RVTEST_SIGBASE(x1,signature_5_0)

 
    # Testcase 20:  rs1:x10(0x3f187bf7c82319e0), result rd:x20(0xffffffff38c3dfbe)
    li  x2, MASK_XLEN(0x3f187bf7c82319e0)
    fmv.d.x f10, x2
    fcvt.s.d f20, f10, rdn
    csrrci x2, fcsr, 0x1F
    sd x2, 0(x1)
    fmv.x.d x3, f20
    fsd f20, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffff38c3dfbe)  

 
    # Testcase 21:  rs1:x9(0x4215f7421c388000), result rd:x21(0xffffffff50afba10)
    li  x2, MASK_XLEN(0x4215f7421c388000)
    fmv.d.x f9, x2
    fcvt.s.d f21, f9, rdn
    csrrci x2, fcsr, 0x1F
    sd x2, 16(x1)
    fmv.x.d x3, f21
    fsd f21, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffff50afba10)  

 
    # Testcase 22:  rs1:x8(0x3ff0000000000000), result rd:x22(0xffffffff3f800000)
    li  x2, MASK_XLEN(0x3ff0000000000000)
    fmv.d.x f8, x2
    fcvt.s.d f22, f8, rdn
    csrrci x2, fcsr, 0x1F
    sd x2, 32(x1)
    fmv.x.d x3, f22
    fsd f22, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffff3f800000)  

 
    # Testcase 23:  rs1:x7(0xc11bdedc00000000), result rd:x23(0xffffffffc8def6e0)
    li  x2, MASK_XLEN(0xc11bdedc00000000)
    fmv.d.x f7, x2
    fcvt.s.d f23, f7, rdn
    csrrci x2, fcsr, 0x1F
    sd x2, 48(x1)
    fmv.x.d x3, f23
    fsd f23, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffffc8def6e0)  

 
    # Testcase 24:  rs1:x6(0x40934a3d70a3d70a), result rd:x24(0xffffffff449a51eb)
    li  x2, MASK_XLEN(0x40934a3d70a3d70a)
    fmv.d.x f6, x2
    fcvt.s.d f24, f6, rdn
    csrrci x2, fcsr, 0x1F
    sd x2, 64(x1)
    fmv.x.d x3, f24
    fsd f24, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffff449a51eb)  



    

    RVTEST_SIGBASE(x6,signature_6_0)

 
    # Testcase 25:  rs1:x5(0x0000000000000000), result rd:x25(0xffffffff00000000)
    li  x7, MASK_XLEN(0x0)
    fmv.d.x f5, x7
    fcvt.s.d f25, f5, rdn
    csrrci x7, fcsr, 0x1F
    sd x7, 0(x6)
    fmv.x.d x8, f25
    fsd f25, 8(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffffff00000000)  

 
    # Testcase 26:  rs1:x4(0x4194e5fec7333333), result rd:x26(0xffffffff4ca72ff6)
    li  x7, MASK_XLEN(0x4194e5fec7333333)
    fmv.d.x f4, x7
    fcvt.s.d f26, f4, rdn
    csrrci x7, fcsr, 0x1F
    sd x7, 16(x6)
    fmv.x.d x8, f26
    fsd f26, 24(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffffff4ca72ff6)  

 
    # Testcase 27:  rs1:x3(0xc03178d4fdf3b646), result rd:x27(0xffffffffc18bc6a8)
    li  x7, MASK_XLEN(0xc03178d4fdf3b646)
    fmv.d.x f3, x7
    fcvt.s.d f27, f3, rdn
    csrrci x7, fcsr, 0x1F
    sd x7, 32(x6)
    fmv.x.d x8, f27
    fsd f27, 40(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffffffc18bc6a8)  

 
    # Testcase 28:  rs1:x2(0x3f187bf7c82319e0), result rd:x28(0xffffffff38c3dfbe)
    li  x7, MASK_XLEN(0x3f187bf7c82319e0)
    fmv.d.x f2, x7
    fcvt.s.d f28, f2, rdn
    csrrci x7, fcsr, 0x1F
    sd x7, 48(x6)
    fmv.x.d x8, f28
    fsd f28, 56(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffffff38c3dfbe)  

 
    # Testcase 29:  rs1:x1(0x4215f7421c388000), result rd:x29(0xffffffff50afba10)
    li  x7, MASK_XLEN(0x4215f7421c388000)
    fmv.d.x f1, x7
    fcvt.s.d f29, f1, rdn
    csrrci x7, fcsr, 0x1F
    sd x7, 64(x6)
    fmv.x.d x8, f29
    fsd f29, 72(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xffffffff50afba10)  



    

    RVTEST_SIGBASE(x1,signature_7_0)

 
    # Testcase 30:  rs1:x0(0x3ff0000000000000), result rd:x30(0xffffffff3f800000)
    li  x2, MASK_XLEN(0x3ff0000000000000)
    fmv.d.x f0, x2
    fcvt.s.d f30, f0, rdn
    csrrci x2, fcsr, 0x1F
    sd x2, 0(x1)
    fmv.x.d x3, f30
    fsd f30, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xffffffff3f800000)  

	
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

