// RISC-V Architectural Validation Test FMADD-D-DYN-RNE-01
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
// Description: Testing instruction 'fmadd.d'.

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


    
    RVTEST_CASE(0,"//check ISA:=regex(.*32.*);check ISA:=regex(.*I.*D.*);def TEST_CASE_1=True;",fmadd.d)

    RVTEST_SIGBASE(x5,signature_1_0)

 
    # Testcase 0:  rs1:x30(0x40934a3d70a3d70a), rs2:x16(0xc11bdedc00000000), result rd:x0(0xc1c0d0775b2e147b)
    li  x8, MASK_XLEN(0xc11bdedc00000000)
    li  x7, MASK_XLEN(0xc11bdedc00000000)
    li  x6, MASK_XLEN(0x40934a3d70a3d70a)
    fmv.d.x f16, x8
    fmv.d.x f16, x7
    fmv.d.x f30, x6
    fmadd.d f0, f30, f16, f16
    csrrci x6, fcsr, 0x1F
        sd x6, 0(x5)
    fmv.x.d x7, f0
    fsd f0, 8(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xc1c0d0775b2e147b)  


 
    # Testcase 1:  rs1:x29(0x0000000000000000), rs2:x15(0x3ff0000000000000), result rd:x1(0x3ff0000000000000)
    li  x8, MASK_XLEN(0x3ff0000000000000)
    li  x7, MASK_XLEN(0x3ff0000000000000)
    li  x6, MASK_XLEN(0x0)
    fmv.d.x f15, x8
    fmv.d.x f15, x7
    fmv.d.x f29, x6
    fmadd.d f1, f29, f15, f15
    csrrci x6, fcsr, 0x1F
        sd x6, 16(x5)
    fmv.x.d x7, f1
    fsd f1, 24(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x3ff0000000000000)  


 
    # Testcase 2:  rs1:x28(0x4194e5fec7333333), rs2:x14(0x4215f7421c388000), result rd:x2(0x43bcb0d351ab69dc)
    li  x8, MASK_XLEN(0x4215f7421c388000)
    li  x7, MASK_XLEN(0x4215f7421c388000)
    li  x6, MASK_XLEN(0x4194e5fec7333333)
    fmv.d.x f14, x8
    fmv.d.x f14, x7
    fmv.d.x f28, x6
    fmadd.d f2, f28, f14, f14
    csrrci x6, fcsr, 0x1F
        sd x6, 32(x5)
    fmv.x.d x7, f2
    fsd f2, 40(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x43bcb0d351ab69dc)  


 
    # Testcase 3:  rs1:x27(0xc03178d4fdf3b646), rs2:x13(0x3f187bf7c82319e0), result rd:x3(0xbf5934df79b06cb0)
    li  x8, MASK_XLEN(0x3f187bf7c82319e0)
    li  x7, MASK_XLEN(0x3f187bf7c82319e0)
    li  x6, MASK_XLEN(0xc03178d4fdf3b646)
    fmv.d.x f13, x8
    fmv.d.x f13, x7
    fmv.d.x f27, x6
    fmadd.d f3, f27, f13, f13
    csrrci x6, fcsr, 0x1F
        sd x6, 48(x5)
    fmv.x.d x7, f3
    fsd f3, 56(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xbf5934df79b06cb0)  


 
    # Testcase 4:  rs1:x26(0x3f187bf7c82319e0), rs2:x12(0xc03178d4fdf3b646), result rd:x4(0xc031793ff06f8f10)
    li  x8, MASK_XLEN(0xc03178d4fdf3b646)
    li  x7, MASK_XLEN(0xc03178d4fdf3b646)
    li  x6, MASK_XLEN(0x3f187bf7c82319e0)
    fmv.d.x f12, x8
    fmv.d.x f12, x7
    fmv.d.x f26, x6
    fmadd.d f4, f26, f12, f12
    csrrci x6, fcsr, 0x1F
        sd x6, 64(x5)
    fmv.x.d x7, f4
    fsd f4, 72(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xc031793ff06f8f10)  




    

    RVTEST_SIGBASE(x1,signature_2_0)

 
    # Testcase 5:  rs1:x25(0x4215f7421c388000), rs2:x11(0x4194e5fec7333333), result rd:x5(0x43bcb0d34c32d2d5)
    li  x4, MASK_XLEN(0x4194e5fec7333333)
    li  x3, MASK_XLEN(0x4194e5fec7333333)
    li  x2, MASK_XLEN(0x4215f7421c388000)
    fmv.d.x f11, x4
    fmv.d.x f11, x3
    fmv.d.x f25, x2
    fmadd.d f5, f25, f11, f11
    csrrci x2, fcsr, 0x1F
        sd x2, 0(x1)
    fmv.x.d x3, f5
    fsd f5, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x43bcb0d34c32d2d5)  


 
    # Testcase 6:  rs1:x24(0x3ff0000000000000), rs2:x10(0x0000000000000000), result rd:x6(0x0000000000000000)
    li  x4, MASK_XLEN(0x0)
    li  x3, MASK_XLEN(0x0)
    li  x2, MASK_XLEN(0x3ff0000000000000)
    fmv.d.x f10, x4
    fmv.d.x f10, x3
    fmv.d.x f24, x2
    fmadd.d f6, f24, f10, f10
    csrrci x2, fcsr, 0x1F
        sd x2, 16(x1)
    fmv.x.d x3, f6
    fsd f6, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x0000000000000000)  


 
    # Testcase 7:  rs1:x23(0xc11bdedc00000000), rs2:x9(0x40934a3d70a3d70a), result rd:x7(0xc1c0ccf916666666)
    li  x4, MASK_XLEN(0x40934a3d70a3d70a)
    li  x3, MASK_XLEN(0x40934a3d70a3d70a)
    li  x2, MASK_XLEN(0xc11bdedc00000000)
    fmv.d.x f9, x4
    fmv.d.x f9, x3
    fmv.d.x f23, x2
    fmadd.d f7, f23, f9, f9
    csrrci x2, fcsr, 0x1F
        sd x2, 32(x1)
    fmv.x.d x3, f7
    fsd f7, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xc1c0ccf916666666)  


 
    # Testcase 8:  rs1:x22(0x40934a3d70a3d70a), rs2:x8(0xc11bdedc00000000), result rd:x8(0xc1c0d0775b2e147b)
    li  x4, MASK_XLEN(0xc11bdedc00000000)
    li  x3, MASK_XLEN(0xc11bdedc00000000)
    li  x2, MASK_XLEN(0x40934a3d70a3d70a)
    fmv.d.x f8, x4
    fmv.d.x f8, x3
    fmv.d.x f22, x2
    fmadd.d f8, f22, f8, f8
    csrrci x2, fcsr, 0x1F
        sd x2, 48(x1)
    fmv.x.d x3, f8
    fsd f8, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xc1c0d0775b2e147b)  


 
    # Testcase 9:  rs1:x21(0x0000000000000000), rs2:x7(0x3ff0000000000000), result rd:x9(0x3ff0000000000000)
    li  x4, MASK_XLEN(0x3ff0000000000000)
    li  x3, MASK_XLEN(0x3ff0000000000000)
    li  x2, MASK_XLEN(0x0)
    fmv.d.x f7, x4
    fmv.d.x f7, x3
    fmv.d.x f21, x2
    fmadd.d f9, f21, f7, f7
    csrrci x2, fcsr, 0x1F
        sd x2, 64(x1)
    fmv.x.d x3, f9
    fsd f9, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x3ff0000000000000)  




    

    RVTEST_SIGBASE(x1,signature_3_0)

 
    # Testcase 10:  rs1:x20(0x4194e5fec7333333), rs2:x6(0x4215f7421c388000), result rd:x10(0x43bcb0d351ab69dc)
    li  x9, MASK_XLEN(0x4215f7421c388000)
    li  x8, MASK_XLEN(0x4215f7421c388000)
    li  x7, MASK_XLEN(0x4194e5fec7333333)
    fmv.d.x f6, x9
    fmv.d.x f6, x8
    fmv.d.x f20, x7
    fmadd.d f10, f20, f6, f6
    csrrci x7, fcsr, 0x1F
        sd x7, 0(x1)
    fmv.x.d x8, f10
    fsd f10, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x43bcb0d351ab69dc)  


 
    # Testcase 11:  rs1:x19(0xc03178d4fdf3b646), rs2:x5(0x3f187bf7c82319e0), result rd:x11(0xbf5934df79b06cb0)
    li  x9, MASK_XLEN(0x3f187bf7c82319e0)
    li  x8, MASK_XLEN(0x3f187bf7c82319e0)
    li  x7, MASK_XLEN(0xc03178d4fdf3b646)
    fmv.d.x f5, x9
    fmv.d.x f5, x8
    fmv.d.x f19, x7
    fmadd.d f11, f19, f5, f5
    csrrci x7, fcsr, 0x1F
        sd x7, 16(x1)
    fmv.x.d x8, f11
    fsd f11, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xbf5934df79b06cb0)  


 
    # Testcase 12:  rs1:x18(0x3f187bf7c82319e0), rs2:x4(0xc03178d4fdf3b646), result rd:x12(0xc031793ff06f8f10)
    li  x9, MASK_XLEN(0xc03178d4fdf3b646)
    li  x8, MASK_XLEN(0xc03178d4fdf3b646)
    li  x7, MASK_XLEN(0x3f187bf7c82319e0)
    fmv.d.x f4, x9
    fmv.d.x f4, x8
    fmv.d.x f18, x7
    fmadd.d f12, f18, f4, f4
    csrrci x7, fcsr, 0x1F
        sd x7, 32(x1)
    fmv.x.d x8, f12
    fsd f12, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xc031793ff06f8f10)  


 
    # Testcase 13:  rs1:x17(0x4215f7421c388000), rs2:x3(0x4194e5fec7333333), result rd:x13(0x43bcb0d34c32d2d5)
    li  x9, MASK_XLEN(0x4194e5fec7333333)
    li  x8, MASK_XLEN(0x4194e5fec7333333)
    li  x7, MASK_XLEN(0x4215f7421c388000)
    fmv.d.x f3, x9
    fmv.d.x f3, x8
    fmv.d.x f17, x7
    fmadd.d f13, f17, f3, f3
    csrrci x7, fcsr, 0x1F
        sd x7, 48(x1)
    fmv.x.d x8, f13
    fsd f13, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x43bcb0d34c32d2d5)  


 
    # Testcase 14:  rs1:x16(0x3ff0000000000000), rs2:x2(0x0000000000000000), result rd:x14(0x0000000000000000)
    li  x9, MASK_XLEN(0x0)
    li  x8, MASK_XLEN(0x0)
    li  x7, MASK_XLEN(0x3ff0000000000000)
    fmv.d.x f2, x9
    fmv.d.x f2, x8
    fmv.d.x f16, x7
    fmadd.d f14, f16, f2, f2
    csrrci x7, fcsr, 0x1F
        sd x7, 64(x1)
    fmv.x.d x8, f14
    fsd f14, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x0000000000000000)  




    

    RVTEST_SIGBASE(x2,signature_4_0)

 
    # Testcase 15:  rs1:x15(0xc11bdedc00000000), rs2:x1(0x40934a3d70a3d70a), result rd:x15(0xc1c0ccf916666666)
    li  x5, MASK_XLEN(0x40934a3d70a3d70a)
    li  x4, MASK_XLEN(0x40934a3d70a3d70a)
    li  x3, MASK_XLEN(0xc11bdedc00000000)
    fmv.d.x f1, x5
    fmv.d.x f1, x4
    fmv.d.x f15, x3
    fmadd.d f15, f15, f1, f1
    csrrci x3, fcsr, 0x1F
        sd x3, 0(x2)
    fmv.x.d x4, f15
    fsd f15, 8(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xc1c0ccf916666666)  


 
    # Testcase 16:  rs1:x14(0x40934a3d70a3d70a), rs2:x0(0xc11bdedc00000000), result rd:x16(0xc1c0d0775b2e147b)
    li  x5, MASK_XLEN(0xc11bdedc00000000)
    li  x4, MASK_XLEN(0xc11bdedc00000000)
    li  x3, MASK_XLEN(0x40934a3d70a3d70a)
    fmv.d.x f0, x5
    fmv.d.x f0, x4
    fmv.d.x f14, x3
    fmadd.d f16, f14, f0, f0
    csrrci x3, fcsr, 0x1F
        sd x3, 16(x2)
    fmv.x.d x4, f16
    fsd f16, 24(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xc1c0d0775b2e147b)  


 
    # Testcase 17:  rs1:x13(0x0000000000000000), rs2:x30(0x3ff0000000000000), result rd:x17(0x3ff0000000000000)
    li  x5, MASK_XLEN(0x3ff0000000000000)
    li  x4, MASK_XLEN(0x3ff0000000000000)
    li  x3, MASK_XLEN(0x0)
    fmv.d.x f31, x5
    fmv.d.x f30, x4
    fmv.d.x f13, x3
    fmadd.d f17, f13, f30, f31
    csrrci x3, fcsr, 0x1F
        sd x3, 32(x2)
    fmv.x.d x4, f17
    fsd f17, 40(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x3ff0000000000000)  


 
    # Testcase 18:  rs1:x12(0x4194e5fec7333333), rs2:x29(0x4215f7421c388000), result rd:x18(0x43bcb0d351ab69dc)
    li  x5, MASK_XLEN(0x4215f7421c388000)
    li  x4, MASK_XLEN(0x4215f7421c388000)
    li  x3, MASK_XLEN(0x4194e5fec7333333)
    fmv.d.x f30, x5
    fmv.d.x f29, x4
    fmv.d.x f12, x3
    fmadd.d f18, f12, f29, f30
    csrrci x3, fcsr, 0x1F
        sd x3, 48(x2)
    fmv.x.d x4, f18
    fsd f18, 56(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x43bcb0d351ab69dc)  


 
    # Testcase 19:  rs1:x11(0xc03178d4fdf3b646), rs2:x28(0x3f187bf7c82319e0), result rd:x19(0xbf5934df79b06cb0)
    li  x5, MASK_XLEN(0x3f187bf7c82319e0)
    li  x4, MASK_XLEN(0x3f187bf7c82319e0)
    li  x3, MASK_XLEN(0xc03178d4fdf3b646)
    fmv.d.x f29, x5
    fmv.d.x f28, x4
    fmv.d.x f11, x3
    fmadd.d f19, f11, f28, f29
    csrrci x3, fcsr, 0x1F
        sd x3, 64(x2)
    fmv.x.d x4, f19
    fsd f19, 72(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xbf5934df79b06cb0)  




    

    RVTEST_SIGBASE(x1,signature_5_0)

 
    # Testcase 20:  rs1:x10(0x3f187bf7c82319e0), rs2:x27(0xc03178d4fdf3b646), result rd:x20(0xc031793ff06f8f10)
    li  x4, MASK_XLEN(0xc03178d4fdf3b646)
    li  x3, MASK_XLEN(0xc03178d4fdf3b646)
    li  x2, MASK_XLEN(0x3f187bf7c82319e0)
    fmv.d.x f28, x4
    fmv.d.x f27, x3
    fmv.d.x f10, x2
    fmadd.d f20, f10, f27, f28
    csrrci x2, fcsr, 0x1F
        sd x2, 0(x1)
    fmv.x.d x3, f20
    fsd f20, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xc031793ff06f8f10)  


 
    # Testcase 21:  rs1:x9(0x4215f7421c388000), rs2:x26(0x4194e5fec7333333), result rd:x21(0x43bcb0d34c32d2d5)
    li  x4, MASK_XLEN(0x4194e5fec7333333)
    li  x3, MASK_XLEN(0x4194e5fec7333333)
    li  x2, MASK_XLEN(0x4215f7421c388000)
    fmv.d.x f27, x4
    fmv.d.x f26, x3
    fmv.d.x f9, x2
    fmadd.d f21, f9, f26, f27
    csrrci x2, fcsr, 0x1F
        sd x2, 16(x1)
    fmv.x.d x3, f21
    fsd f21, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x43bcb0d34c32d2d5)  


 
    # Testcase 22:  rs1:x8(0x3ff0000000000000), rs2:x25(0x0000000000000000), result rd:x22(0x0000000000000000)
    li  x4, MASK_XLEN(0x0)
    li  x3, MASK_XLEN(0x0)
    li  x2, MASK_XLEN(0x3ff0000000000000)
    fmv.d.x f26, x4
    fmv.d.x f25, x3
    fmv.d.x f8, x2
    fmadd.d f22, f8, f25, f26
    csrrci x2, fcsr, 0x1F
        sd x2, 32(x1)
    fmv.x.d x3, f22
    fsd f22, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x0000000000000000)  


 
    # Testcase 23:  rs1:x7(0xc11bdedc00000000), rs2:x24(0x40934a3d70a3d70a), result rd:x23(0xc1c0ccf916666666)
    li  x4, MASK_XLEN(0x40934a3d70a3d70a)
    li  x3, MASK_XLEN(0x40934a3d70a3d70a)
    li  x2, MASK_XLEN(0xc11bdedc00000000)
    fmv.d.x f25, x4
    fmv.d.x f24, x3
    fmv.d.x f7, x2
    fmadd.d f23, f7, f24, f25
    csrrci x2, fcsr, 0x1F
        sd x2, 48(x1)
    fmv.x.d x3, f23
    fsd f23, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xc1c0ccf916666666)  


 
    # Testcase 24:  rs1:x6(0x40934a3d70a3d70a), rs2:x23(0xc11bdedc00000000), result rd:x24(0xc1c0d0775b2e147b)
    li  x4, MASK_XLEN(0xc11bdedc00000000)
    li  x3, MASK_XLEN(0xc11bdedc00000000)
    li  x2, MASK_XLEN(0x40934a3d70a3d70a)
    fmv.d.x f24, x4
    fmv.d.x f23, x3
    fmv.d.x f6, x2
    fmadd.d f24, f6, f23, f24
    csrrci x2, fcsr, 0x1F
        sd x2, 64(x1)
    fmv.x.d x3, f24
    fsd f24, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xc1c0d0775b2e147b)  




    

    RVTEST_SIGBASE(x6,signature_6_0)

 
    # Testcase 25:  rs1:x5(0x0000000000000000), rs2:x22(0x3ff0000000000000), result rd:x25(0x3ff0000000000000)
    li  x9, MASK_XLEN(0x3ff0000000000000)
    li  x8, MASK_XLEN(0x3ff0000000000000)
    li  x7, MASK_XLEN(0x0)
    fmv.d.x f23, x9
    fmv.d.x f22, x8
    fmv.d.x f5, x7
    fmadd.d f25, f5, f22, f23
    csrrci x7, fcsr, 0x1F
        sd x7, 0(x6)
    fmv.x.d x8, f25
    fsd f25, 8(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x3ff0000000000000)  


 
    # Testcase 26:  rs1:x4(0x4194e5fec7333333), rs2:x21(0x4215f7421c388000), result rd:x26(0x43bcb0d351ab69dc)
    li  x9, MASK_XLEN(0x4215f7421c388000)
    li  x8, MASK_XLEN(0x4215f7421c388000)
    li  x7, MASK_XLEN(0x4194e5fec7333333)
    fmv.d.x f22, x9
    fmv.d.x f21, x8
    fmv.d.x f4, x7
    fmadd.d f26, f4, f21, f22
    csrrci x7, fcsr, 0x1F
        sd x7, 16(x6)
    fmv.x.d x8, f26
    fsd f26, 24(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x43bcb0d351ab69dc)  


 
    # Testcase 27:  rs1:x3(0xc03178d4fdf3b646), rs2:x20(0x3f187bf7c82319e0), result rd:x27(0xbf5934df79b06cb0)
    li  x9, MASK_XLEN(0x3f187bf7c82319e0)
    li  x8, MASK_XLEN(0x3f187bf7c82319e0)
    li  x7, MASK_XLEN(0xc03178d4fdf3b646)
    fmv.d.x f21, x9
    fmv.d.x f20, x8
    fmv.d.x f3, x7
    fmadd.d f27, f3, f20, f21
    csrrci x7, fcsr, 0x1F
        sd x7, 32(x6)
    fmv.x.d x8, f27
    fsd f27, 40(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xbf5934df79b06cb0)  


 
    # Testcase 28:  rs1:x2(0x3f187bf7c82319e0), rs2:x19(0xc03178d4fdf3b646), result rd:x28(0xc031793ff06f8f10)
    li  x9, MASK_XLEN(0xc03178d4fdf3b646)
    li  x8, MASK_XLEN(0xc03178d4fdf3b646)
    li  x7, MASK_XLEN(0x3f187bf7c82319e0)
    fmv.d.x f20, x9
    fmv.d.x f19, x8
    fmv.d.x f2, x7
    fmadd.d f28, f2, f19, f20
    csrrci x7, fcsr, 0x1F
        sd x7, 48(x6)
    fmv.x.d x8, f28
    fsd f28, 56(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xc031793ff06f8f10)  


 
    # Testcase 29:  rs1:x1(0x4215f7421c388000), rs2:x18(0x4194e5fec7333333), result rd:x29(0x43bcb0d34c32d2d5)
    li  x9, MASK_XLEN(0x4194e5fec7333333)
    li  x8, MASK_XLEN(0x4194e5fec7333333)
    li  x7, MASK_XLEN(0x4215f7421c388000)
    fmv.d.x f19, x9
    fmv.d.x f18, x8
    fmv.d.x f1, x7
    fmadd.d f29, f1, f18, f19
    csrrci x7, fcsr, 0x1F
        sd x7, 64(x6)
    fmv.x.d x8, f29
    fsd f29, 72(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x43bcb0d34c32d2d5)  




    

    RVTEST_SIGBASE(x1,signature_7_0)

 
    # Testcase 30:  rs1:x0(0x3ff0000000000000), rs2:x17(0x0000000000000000), result rd:x30(0x0000000000000000)
    li  x4, MASK_XLEN(0x0)
    li  x3, MASK_XLEN(0x0)
    li  x2, MASK_XLEN(0x3ff0000000000000)
    fmv.d.x f18, x4
    fmv.d.x f17, x3
    fmv.d.x f0, x2
    fmadd.d f30, f0, f17, f18
    csrrci x2, fcsr, 0x1F
        sd x2, 0(x1)
    fmv.x.d x3, f30
    fsd f30, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x0000000000000000)  


	
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

