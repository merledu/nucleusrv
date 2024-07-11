// RISC-V Architectural Validation Test FCVT-LU-S-RNE-01
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
// Description: Testing instruction 'fcvt.lu.s'.

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
	li x1,  32
	csrw fcsr, x1


#ifdef TEST_CASE_1


    
    RVTEST_CASE(0,"//check ISA:=regex(.*32.*);check ISA:=regex(.*I.*F.*);def TEST_CASE_1=True;",fcvt.lu.s)

    RVTEST_SIGBASE(x5,signature_1_0)

 
    # Testcase 0:  rs1:x30(0x000000003f9e0419), result rd:x0(0x0000000000000000)
    li  x6, MASK_XLEN(0x3f9e0419)
    fmv.w.x f30, x6
    fcvt.lu.s x0, f30, rne
    csrrci x6, fcsr, 0x1F
    sw x6, 0(x5)
        sw x0, 8(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x0, 0x0000000000000000) 
 
    # Testcase 1:  rs1:x29(0x0000000000000000), result rd:x1(0x0000000000000000)
    li  x6, MASK_XLEN(0x0)
    fmv.w.x f29, x6
    fcvt.lu.s x1, f29, rne
    csrrci x6, fcsr, 0x1F
    sw x6, 16(x5)
        sw x1, 24(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x1, 0x0000000000000000) 
 
    # Testcase 2:  rs1:x28(0x00000000c1458794), result rd:x2(0x0000000000000000)
    li  x6, MASK_XLEN(0xc1458794)
    fmv.w.x f28, x6
    fcvt.lu.s x2, f28, rne
    csrrci x6, fcsr, 0x1F
    sw x6, 32(x5)
        sw x2, 40(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x2, 0x0000000000000000) 
 
    # Testcase 3:  rs1:x27(0x00000000c61a5229), result rd:x3(0x0000000000000000)
    li  x6, MASK_XLEN(0xc61a5229)
    fmv.w.x f27, x6
    fcvt.lu.s x3, f27, rne
    csrrci x6, fcsr, 0x1F
    sw x6, 48(x5)
        sw x3, 56(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x3, 0x0000000000000000) 
 
    # Testcase 4:  rs1:x26(0x000000004c50e7e7), result rd:x4(0x0000000003439f9c)
    li  x6, MASK_XLEN(0x4c50e7e7)
    fmv.w.x f26, x6
    fcvt.lu.s x4, f26, rne
    csrrci x6, fcsr, 0x1F
    sw x6, 64(x5)
        sw x4, 72(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x4, 0x0000000003439f9c) 


    

    RVTEST_SIGBASE(x1,signature_2_0)

 
    # Testcase 5:  rs1:x25(0x000000003f800000), result rd:x5(0x0000000000000001)
    li  x2, MASK_XLEN(0x3f800000)
    fmv.w.x f25, x2
    fcvt.lu.s x5, f25, rne
    csrrci x2, fcsr, 0x1F
    sw x2, 0(x1)
        sw x5, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x5, 0x0000000000000001) 
 
    # Testcase 6:  rs1:x24(0x000000003a2b48ef), result rd:x6(0x0000000000000000)
    li  x2, MASK_XLEN(0x3a2b48ef)
    fmv.w.x f24, x2
    fcvt.lu.s x6, f24, rne
    csrrci x2, fcsr, 0x1F
    sw x2, 16(x1)
        sw x6, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x6, 0x0000000000000000) 
 
    # Testcase 7:  rs1:x23(0x00000000bf800000), result rd:x7(0x0000000000000000)
    li  x2, MASK_XLEN(0xbf800000)
    fmv.w.x f23, x2
    fcvt.lu.s x7, f23, rne
    csrrci x2, fcsr, 0x1F
    sw x2, 32(x1)
        sw x7, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x7, 0x0000000000000000) 
 
    # Testcase 8:  rs1:x22(0x000000003f9e0419), result rd:x8(0x0000000000000001)
    li  x2, MASK_XLEN(0x3f9e0419)
    fmv.w.x f22, x2
    fcvt.lu.s x8, f22, rne
    csrrci x2, fcsr, 0x1F
    sw x2, 48(x1)
        sw x8, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x8, 0x0000000000000001) 
 
    # Testcase 9:  rs1:x21(0x0000000000000000), result rd:x9(0x0000000000000000)
    li  x2, MASK_XLEN(0x0)
    fmv.w.x f21, x2
    fcvt.lu.s x9, f21, rne
    csrrci x2, fcsr, 0x1F
    sw x2, 64(x1)
        sw x9, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x9, 0x0000000000000000) 


    

    RVTEST_SIGBASE(x1,signature_3_0)

 
    # Testcase 10:  rs1:x20(0x00000000c1458794), result rd:x10(0x0000000000000000)
    li  x7, MASK_XLEN(0xc1458794)
    fmv.w.x f20, x7
    fcvt.lu.s x10, f20, rne
    csrrci x7, fcsr, 0x1F
    sw x7, 0(x1)
        sw x10, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x10, 0x0000000000000000) 
 
    # Testcase 11:  rs1:x19(0x00000000c61a5229), result rd:x11(0x0000000000000000)
    li  x7, MASK_XLEN(0xc61a5229)
    fmv.w.x f19, x7
    fcvt.lu.s x11, f19, rne
    csrrci x7, fcsr, 0x1F
    sw x7, 16(x1)
        sw x11, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x11, 0x0000000000000000) 
 
    # Testcase 12:  rs1:x18(0x000000004c50e7e7), result rd:x12(0x0000000003439f9c)
    li  x7, MASK_XLEN(0x4c50e7e7)
    fmv.w.x f18, x7
    fcvt.lu.s x12, f18, rne
    csrrci x7, fcsr, 0x1F
    sw x7, 32(x1)
        sw x12, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x12, 0x0000000003439f9c) 
 
    # Testcase 13:  rs1:x17(0x000000003f800000), result rd:x13(0x0000000000000001)
    li  x7, MASK_XLEN(0x3f800000)
    fmv.w.x f17, x7
    fcvt.lu.s x13, f17, rne
    csrrci x7, fcsr, 0x1F
    sw x7, 48(x1)
        sw x13, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x13, 0x0000000000000001) 
 
    # Testcase 14:  rs1:x16(0x000000003a2b48ef), result rd:x14(0x0000000000000000)
    li  x7, MASK_XLEN(0x3a2b48ef)
    fmv.w.x f16, x7
    fcvt.lu.s x14, f16, rne
    csrrci x7, fcsr, 0x1F
    sw x7, 64(x1)
        sw x14, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x14, 0x0000000000000000) 


    

    RVTEST_SIGBASE(x2,signature_4_0)

 
    # Testcase 15:  rs1:x15(0x00000000bf800000), result rd:x15(0x0000000000000000)
    li  x3, MASK_XLEN(0xbf800000)
    fmv.w.x f15, x3
    fcvt.lu.s x15, f15, rne
    csrrci x3, fcsr, 0x1F
    sw x3, 0(x2)
        sw x15, 8(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x15, 0x0000000000000000) 
 
    # Testcase 16:  rs1:x14(0x000000003f9e0419), result rd:x16(0x0000000000000001)
    li  x3, MASK_XLEN(0x3f9e0419)
    fmv.w.x f14, x3
    fcvt.lu.s x16, f14, rne
    csrrci x3, fcsr, 0x1F
    sw x3, 16(x2)
        sw x16, 24(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x16, 0x0000000000000001) 
 
    # Testcase 17:  rs1:x13(0x0000000000000000), result rd:x17(0x0000000000000000)
    li  x3, MASK_XLEN(0x0)
    fmv.w.x f13, x3
    fcvt.lu.s x17, f13, rne
    csrrci x3, fcsr, 0x1F
    sw x3, 32(x2)
        sw x17, 40(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x17, 0x0000000000000000) 
 
    # Testcase 18:  rs1:x12(0x00000000c1458794), result rd:x18(0x0000000000000000)
    li  x3, MASK_XLEN(0xc1458794)
    fmv.w.x f12, x3
    fcvt.lu.s x18, f12, rne
    csrrci x3, fcsr, 0x1F
    sw x3, 48(x2)
        sw x18, 56(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x18, 0x0000000000000000) 
 
    # Testcase 19:  rs1:x11(0x00000000c61a5229), result rd:x19(0x0000000000000000)
    li  x3, MASK_XLEN(0xc61a5229)
    fmv.w.x f11, x3
    fcvt.lu.s x19, f11, rne
    csrrci x3, fcsr, 0x1F
    sw x3, 64(x2)
        sw x19, 72(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x19, 0x0000000000000000) 


    

    RVTEST_SIGBASE(x1,signature_5_0)

 
    # Testcase 20:  rs1:x10(0x000000004c50e7e7), result rd:x20(0x0000000003439f9c)
    li  x2, MASK_XLEN(0x4c50e7e7)
    fmv.w.x f10, x2
    fcvt.lu.s x20, f10, rne
    csrrci x2, fcsr, 0x1F
    sw x2, 0(x1)
        sw x20, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x20, 0x0000000003439f9c) 
 
    # Testcase 21:  rs1:x9(0x000000003f800000), result rd:x21(0x0000000000000001)
    li  x2, MASK_XLEN(0x3f800000)
    fmv.w.x f9, x2
    fcvt.lu.s x21, f9, rne
    csrrci x2, fcsr, 0x1F
    sw x2, 16(x1)
        sw x21, 24(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x21, 0x0000000000000001) 
 
    # Testcase 22:  rs1:x8(0x000000003a2b48ef), result rd:x22(0x0000000000000000)
    li  x2, MASK_XLEN(0x3a2b48ef)
    fmv.w.x f8, x2
    fcvt.lu.s x22, f8, rne
    csrrci x2, fcsr, 0x1F
    sw x2, 32(x1)
        sw x22, 40(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x22, 0x0000000000000000) 
 
    # Testcase 23:  rs1:x7(0x00000000bf800000), result rd:x23(0x0000000000000000)
    li  x2, MASK_XLEN(0xbf800000)
    fmv.w.x f7, x2
    fcvt.lu.s x23, f7, rne
    csrrci x2, fcsr, 0x1F
    sw x2, 48(x1)
        sw x23, 56(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x23, 0x0000000000000000) 
 
    # Testcase 24:  rs1:x6(0x000000003f9e0419), result rd:x24(0x0000000000000001)
    li  x2, MASK_XLEN(0x3f9e0419)
    fmv.w.x f6, x2
    fcvt.lu.s x24, f6, rne
    csrrci x2, fcsr, 0x1F
    sw x2, 64(x1)
        sw x24, 72(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x24, 0x0000000000000001) 


    

    RVTEST_SIGBASE(x6,signature_6_0)

 
    # Testcase 25:  rs1:x5(0x0000000000000000), result rd:x25(0x0000000000000000)
    li  x7, MASK_XLEN(0x0)
    fmv.w.x f5, x7
    fcvt.lu.s x25, f5, rne
    csrrci x7, fcsr, 0x1F
    sw x7, 0(x6)
        sw x25, 8(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x25, 0x0000000000000000) 
 
    # Testcase 26:  rs1:x4(0x00000000c1458794), result rd:x26(0x0000000000000000)
    li  x7, MASK_XLEN(0xc1458794)
    fmv.w.x f4, x7
    fcvt.lu.s x26, f4, rne
    csrrci x7, fcsr, 0x1F
    sw x7, 16(x6)
        sw x26, 24(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x26, 0x0000000000000000) 
 
    # Testcase 27:  rs1:x3(0x00000000c61a5229), result rd:x27(0x0000000000000000)
    li  x7, MASK_XLEN(0xc61a5229)
    fmv.w.x f3, x7
    fcvt.lu.s x27, f3, rne
    csrrci x7, fcsr, 0x1F
    sw x7, 32(x6)
        sw x27, 40(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x27, 0x0000000000000000) 
 
    # Testcase 28:  rs1:x2(0x000000004c50e7e7), result rd:x28(0x0000000003439f9c)
    li  x7, MASK_XLEN(0x4c50e7e7)
    fmv.w.x f2, x7
    fcvt.lu.s x28, f2, rne
    csrrci x7, fcsr, 0x1F
    sw x7, 48(x6)
        sw x28, 56(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x28, 0x0000000003439f9c) 
 
    # Testcase 29:  rs1:x1(0x000000003f800000), result rd:x29(0x0000000000000001)
    li  x7, MASK_XLEN(0x3f800000)
    fmv.w.x f1, x7
    fcvt.lu.s x29, f1, rne
    csrrci x7, fcsr, 0x1F
    sw x7, 64(x6)
        sw x29, 72(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x29, 0x0000000000000001) 


    

    RVTEST_SIGBASE(x1,signature_7_0)

 
    # Testcase 30:  rs1:x0(0x000000003a2b48ef), result rd:x30(0x0000000000000000)
    li  x2, MASK_XLEN(0x3a2b48ef)
    fmv.w.x f0, x2
    fcvt.lu.s x30, f0, rne
    csrrci x2, fcsr, 0x1F
    sw x2, 0(x1)
        sw x30, 8(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x30, 0x0000000000000000) 
	
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

