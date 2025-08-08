// RISC-V Architectural Validation Test FCVT-D-S-01
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
// Description: Testing instruction 'fcvt.d.s'.

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


    
    RVTEST_CASE(0,"//check ISA:=regex(.*32.*);check ISA:=regex(.*I.*D.*);def TEST_CASE_1=True;",fcvt.d.s)

    RVTEST_SIGBASE(x5,signature_1_0)

 
    # Testcase 0:  rs1:x30(0xffffffff3f9e0419), result rd:x0(0x3ff3c08320000000)
    li  x6, MASK_XLEN(0xffffffff3f9e0419)
    fmv.d.x f30, x6
    fcvt.d.s f0, f30
    csrrci x6, fcsr, 0x1F
    sd x6, 0(x5)
    fmv.x.d x7, f0
    fsd f0, 8(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x3ff3c08320000000)  

 
    # Testcase 1:  rs1:x29(0xffffffff00000000), result rd:x1(0x0000000000000000)
    li  x6, MASK_XLEN(0xffffffff00000000)
    fmv.d.x f29, x6
    fcvt.d.s f1, f29
    csrrci x6, fcsr, 0x1F
    sd x6, 16(x5)
    fmv.x.d x7, f1
    fsd f1, 24(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x0000000000000000)  

 
    # Testcase 2:  rs1:x28(0xffffffffc1458794), result rd:x2(0xc028b0f280000000)
    li  x6, MASK_XLEN(0xffffffffc1458794)
    fmv.d.x f28, x6
    fcvt.d.s f2, f28
    csrrci x6, fcsr, 0x1F
    sd x6, 32(x5)
    fmv.x.d x7, f2
    fsd f2, 40(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xc028b0f280000000)  

 
    # Testcase 3:  rs1:x27(0xffffffffc61a5229), result rd:x3(0xc0c34a4520000000)
    li  x6, MASK_XLEN(0xffffffffc61a5229)
    fmv.d.x f27, x6
    fcvt.d.s f3, f27
    csrrci x6, fcsr, 0x1F
    sd x6, 48(x5)
    fmv.x.d x7, f3
    fsd f3, 56(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xc0c34a4520000000)  

 
    # Testcase 4:  rs1:x26(0xffffffff4c50e7e7), result rd:x4(0x418a1cfce0000000)
    li  x6, MASK_XLEN(0xffffffff4c50e7e7)
    fmv.d.x f26, x6
    fcvt.d.s f4, f26
    csrrci x6, fcsr, 0x1F
    sd x6, 64(x5)
    fmv.x.d x7, f4
    fsd f4, 72(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x418a1cfce0000000)  



    

    RVTEST_SIGBASE(x1,signature_2_0)

 
    # Testcase 5:  rs1:x25(0xffffffff3f800000), result rd:x5(0x3ff0000000000000)
    li  x2, MASK_XLEN(0xffffffff3f800000)
    fmv.d.x f25, x2
    fcvt.d.s f5, f25
    csrrci x2, fcsr, 0x1F
    sd x2, 0(x1)
    fmv.x.d x3, f5
    fsd f5, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x3ff0000000000000)  

 
    # Testcase 6:  rs1:x24(0xffffffff3a2b48ef), result rd:x6(0x3f45691de0000000)
    li  x2, MASK_XLEN(0xffffffff3a2b48ef)
    fmv.d.x f24, x2
    fcvt.d.s f6, f24
    csrrci x2, fcsr, 0x1F
    sd x2, 16(x1)
    fmv.x.d x3, f6
    fsd f6, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x3f45691de0000000)  

 
    # Testcase 7:  rs1:x23(0xffffffffbf800000), result rd:x7(0xbff0000000000000)
    li  x2, MASK_XLEN(0xffffffffbf800000)
    fmv.d.x f23, x2
    fcvt.d.s f7, f23
    csrrci x2, fcsr, 0x1F
    sd x2, 32(x1)
    fmv.x.d x3, f7
    fsd f7, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xbff0000000000000)  

 
    # Testcase 8:  rs1:x22(0xffffffff3f9e0419), result rd:x8(0x3ff3c08320000000)
    li  x2, MASK_XLEN(0xffffffff3f9e0419)
    fmv.d.x f22, x2
    fcvt.d.s f8, f22
    csrrci x2, fcsr, 0x1F
    sd x2, 48(x1)
    fmv.x.d x3, f8
    fsd f8, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x3ff3c08320000000)  

 
    # Testcase 9:  rs1:x21(0xffffffff00000000), result rd:x9(0x0000000000000000)
    li  x2, MASK_XLEN(0xffffffff00000000)
    fmv.d.x f21, x2
    fcvt.d.s f9, f21
    csrrci x2, fcsr, 0x1F
    sd x2, 64(x1)
    fmv.x.d x3, f9
    fsd f9, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x0000000000000000)  



    

    RVTEST_SIGBASE(x1,signature_3_0)

 
    # Testcase 10:  rs1:x20(0xffffffffc1458794), result rd:x10(0xc028b0f280000000)
    li  x7, MASK_XLEN(0xffffffffc1458794)
    fmv.d.x f20, x7
    fcvt.d.s f10, f20
    csrrci x7, fcsr, 0x1F
    sd x7, 0(x1)
    fmv.x.d x8, f10
    fsd f10, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xc028b0f280000000)  

 
    # Testcase 11:  rs1:x19(0xffffffffc61a5229), result rd:x11(0xc0c34a4520000000)
    li  x7, MASK_XLEN(0xffffffffc61a5229)
    fmv.d.x f19, x7
    fcvt.d.s f11, f19
    csrrci x7, fcsr, 0x1F
    sd x7, 16(x1)
    fmv.x.d x8, f11
    fsd f11, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xc0c34a4520000000)  

 
    # Testcase 12:  rs1:x18(0xffffffff4c50e7e7), result rd:x12(0x418a1cfce0000000)
    li  x7, MASK_XLEN(0xffffffff4c50e7e7)
    fmv.d.x f18, x7
    fcvt.d.s f12, f18
    csrrci x7, fcsr, 0x1F
    sd x7, 32(x1)
    fmv.x.d x8, f12
    fsd f12, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x418a1cfce0000000)  

 
    # Testcase 13:  rs1:x17(0xffffffff3f800000), result rd:x13(0x3ff0000000000000)
    li  x7, MASK_XLEN(0xffffffff3f800000)
    fmv.d.x f17, x7
    fcvt.d.s f13, f17
    csrrci x7, fcsr, 0x1F
    sd x7, 48(x1)
    fmv.x.d x8, f13
    fsd f13, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x3ff0000000000000)  

 
    # Testcase 14:  rs1:x16(0xffffffff3a2b48ef), result rd:x14(0x3f45691de0000000)
    li  x7, MASK_XLEN(0xffffffff3a2b48ef)
    fmv.d.x f16, x7
    fcvt.d.s f14, f16
    csrrci x7, fcsr, 0x1F
    sd x7, 64(x1)
    fmv.x.d x8, f14
    fsd f14, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x3f45691de0000000)  



    

    RVTEST_SIGBASE(x2,signature_4_0)

 
    # Testcase 15:  rs1:x15(0xffffffffbf800000), result rd:x15(0xbff0000000000000)
    li  x3, MASK_XLEN(0xffffffffbf800000)
    fmv.d.x f15, x3
    fcvt.d.s f15, f15
    csrrci x3, fcsr, 0x1F
    sd x3, 0(x2)
    fmv.x.d x4, f15
    fsd f15, 8(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xbff0000000000000)  

 
    # Testcase 16:  rs1:x14(0xffffffff3f9e0419), result rd:x16(0x3ff3c08320000000)
    li  x3, MASK_XLEN(0xffffffff3f9e0419)
    fmv.d.x f14, x3
    fcvt.d.s f16, f14
    csrrci x3, fcsr, 0x1F
    sd x3, 16(x2)
    fmv.x.d x4, f16
    fsd f16, 24(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x3ff3c08320000000)  

 
    # Testcase 17:  rs1:x13(0xffffffff00000000), result rd:x17(0x0000000000000000)
    li  x3, MASK_XLEN(0xffffffff00000000)
    fmv.d.x f13, x3
    fcvt.d.s f17, f13
    csrrci x3, fcsr, 0x1F
    sd x3, 32(x2)
    fmv.x.d x4, f17
    fsd f17, 40(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x0000000000000000)  

 
    # Testcase 18:  rs1:x12(0xffffffffc1458794), result rd:x18(0xc028b0f280000000)
    li  x3, MASK_XLEN(0xffffffffc1458794)
    fmv.d.x f12, x3
    fcvt.d.s f18, f12
    csrrci x3, fcsr, 0x1F
    sd x3, 48(x2)
    fmv.x.d x4, f18
    fsd f18, 56(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xc028b0f280000000)  

 
    # Testcase 19:  rs1:x11(0xffffffffc61a5229), result rd:x19(0xc0c34a4520000000)
    li  x3, MASK_XLEN(0xffffffffc61a5229)
    fmv.d.x f11, x3
    fcvt.d.s f19, f11
    csrrci x3, fcsr, 0x1F
    sd x3, 64(x2)
    fmv.x.d x4, f19
    fsd f19, 72(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xc0c34a4520000000)  



    

    RVTEST_SIGBASE(x1,signature_5_0)

 
    # Testcase 20:  rs1:x10(0xffffffff4c50e7e7), result rd:x20(0x418a1cfce0000000)
    li  x2, MASK_XLEN(0xffffffff4c50e7e7)
    fmv.d.x f10, x2
    fcvt.d.s f20, f10
    csrrci x2, fcsr, 0x1F
    sd x2, 0(x1)
    fmv.x.d x3, f20
    fsd f20, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x418a1cfce0000000)  

 
    # Testcase 21:  rs1:x9(0xffffffff3f800000), result rd:x21(0x3ff0000000000000)
    li  x2, MASK_XLEN(0xffffffff3f800000)
    fmv.d.x f9, x2
    fcvt.d.s f21, f9
    csrrci x2, fcsr, 0x1F
    sd x2, 16(x1)
    fmv.x.d x3, f21
    fsd f21, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x3ff0000000000000)  

 
    # Testcase 22:  rs1:x8(0xffffffff3a2b48ef), result rd:x22(0x3f45691de0000000)
    li  x2, MASK_XLEN(0xffffffff3a2b48ef)
    fmv.d.x f8, x2
    fcvt.d.s f22, f8
    csrrci x2, fcsr, 0x1F
    sd x2, 32(x1)
    fmv.x.d x3, f22
    fsd f22, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x3f45691de0000000)  

 
    # Testcase 23:  rs1:x7(0xffffffffbf800000), result rd:x23(0xbff0000000000000)
    li  x2, MASK_XLEN(0xffffffffbf800000)
    fmv.d.x f7, x2
    fcvt.d.s f23, f7
    csrrci x2, fcsr, 0x1F
    sd x2, 48(x1)
    fmv.x.d x3, f23
    fsd f23, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xbff0000000000000)  

 
    # Testcase 24:  rs1:x6(0xffffffff3f9e0419), result rd:x24(0x3ff3c08320000000)
    li  x2, MASK_XLEN(0xffffffff3f9e0419)
    fmv.d.x f6, x2
    fcvt.d.s f24, f6
    csrrci x2, fcsr, 0x1F
    sd x2, 64(x1)
    fmv.x.d x3, f24
    fsd f24, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x3ff3c08320000000)  



    

    RVTEST_SIGBASE(x6,signature_6_0)

 
    # Testcase 25:  rs1:x5(0xffffffff00000000), result rd:x25(0x0000000000000000)
    li  x7, MASK_XLEN(0xffffffff00000000)
    fmv.d.x f5, x7
    fcvt.d.s f25, f5
    csrrci x7, fcsr, 0x1F
    sd x7, 0(x6)
    fmv.x.d x8, f25
    fsd f25, 8(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x0000000000000000)  

 
    # Testcase 26:  rs1:x4(0xffffffffc1458794), result rd:x26(0xc028b0f280000000)
    li  x7, MASK_XLEN(0xffffffffc1458794)
    fmv.d.x f4, x7
    fcvt.d.s f26, f4
    csrrci x7, fcsr, 0x1F
    sd x7, 16(x6)
    fmv.x.d x8, f26
    fsd f26, 24(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xc028b0f280000000)  

 
    # Testcase 27:  rs1:x3(0xffffffffc61a5229), result rd:x27(0xc0c34a4520000000)
    li  x7, MASK_XLEN(0xffffffffc61a5229)
    fmv.d.x f3, x7
    fcvt.d.s f27, f3
    csrrci x7, fcsr, 0x1F
    sd x7, 32(x6)
    fmv.x.d x8, f27
    fsd f27, 40(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xc0c34a4520000000)  

 
    # Testcase 28:  rs1:x2(0xffffffff4c50e7e7), result rd:x28(0x418a1cfce0000000)
    li  x7, MASK_XLEN(0xffffffff4c50e7e7)
    fmv.d.x f2, x7
    fcvt.d.s f28, f2
    csrrci x7, fcsr, 0x1F
    sd x7, 48(x6)
    fmv.x.d x8, f28
    fsd f28, 56(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x418a1cfce0000000)  

 
    # Testcase 29:  rs1:x1(0xffffffff3f800000), result rd:x29(0x3ff0000000000000)
    li  x7, MASK_XLEN(0xffffffff3f800000)
    fmv.d.x f1, x7
    fcvt.d.s f29, f1
    csrrci x7, fcsr, 0x1F
    sd x7, 64(x6)
    fmv.x.d x8, f29
    fsd f29, 72(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x3ff0000000000000)  



    

    RVTEST_SIGBASE(x1,signature_7_0)

 
    # Testcase 30:  rs1:x0(0xffffffff3a2b48ef), result rd:x30(0x3f45691de0000000)
    li  x2, MASK_XLEN(0xffffffff3a2b48ef)
    fmv.d.x f0, x2
    fcvt.d.s f30, f0
    csrrci x2, fcsr, 0x1F
    sd x2, 0(x1)
    fmv.x.d x3, f30
    fsd f30, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x3f45691de0000000)  

	
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

