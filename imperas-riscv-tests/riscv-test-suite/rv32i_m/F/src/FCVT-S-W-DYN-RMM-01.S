// RISC-V Architectural Validation Test FCVT-S-W-DYN-RMM-01
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
// Description: Testing instruction 'fcvt.s.w'.

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
	li x1,  128
	csrw fcsr, x1


#ifdef TEST_CASE_1


    
    RVTEST_CASE(0,"//check ISA:=regex(.*32.*);check ISA:=regex(.*I.*F.*);def TEST_CASE_1=True;",fcvt.s.w)

    RVTEST_SIGBASE(x5,signature_1_0)

    # Testcase 0:  rs1:x30(0x3f9e0419), rs2:x16(0xbf800000), result rd:x0(0x00000000)
    li  x30, MASK_XLEN(0x3f9e0419)
    fcvt.s.w f0, x30
    csrrci x6, fcsr, 0x1F
    sw x6, 0(x5)
    fmv.x.w x7, f0
    fsw f0, 4(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x4e7e7810)  

    # Testcase 1:  rs1:x29(0x00000000), rs2:x15(0x3a2b48ef), result rd:x1(0x00000000)
    li  x29, MASK_XLEN(0x0)
    fcvt.s.w f1, x29
    csrrci x6, fcsr, 0x1F
    sw x6, 8(x5)
    fmv.x.w x7, f1
    fsw f1, 12(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x00000000)  

    # Testcase 2:  rs1:x28(0xc1458794), rs2:x14(0x3f800000), result rd:x2(0x00000000)
    li  x28, MASK_XLEN(0xc1458794)
    fcvt.s.w f2, x28
    csrrci x6, fcsr, 0x1F
    sw x6, 16(x5)
    fmv.x.w x7, f2
    fsw f2, 20(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xce7ae9e2)  

    # Testcase 3:  rs1:x27(0xc61a5229), rs2:x13(0x4c50e7e7), result rd:x3(0x00000000)
    li  x27, MASK_XLEN(0xc61a5229)
    fcvt.s.w f3, x27
    csrrci x6, fcsr, 0x1F
    sw x6, 24(x5)
    fmv.x.w x7, f3
    fsw f3, 28(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0xce6796b7)  

    # Testcase 4:  rs1:x26(0x4c50e7e7), rs2:x12(0xc61a5229), result rd:x4(0x00000000)
    li  x26, MASK_XLEN(0x4c50e7e7)
    fcvt.s.w f4, x26
    csrrci x6, fcsr, 0x1F
    sw x6, 32(x5)
    fmv.x.w x7, f4
    fsw f4, 36(x5)
    RVMODEL_IO_ASSERT_GPR_EQ(x6, x7, 0x4e98a1d0)  



    

    RVTEST_SIGBASE(x1,signature_2_0)

    # Testcase 5:  rs1:x25(0x3f800000), rs2:x11(0xc1458794), result rd:x5(0x00000000)
    li  x25, MASK_XLEN(0x3f800000)
    fcvt.s.w f5, x25
    csrrci x2, fcsr, 0x1F
    sw x2, 0(x1)
    fmv.x.w x3, f5
    fsw f5, 4(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x4e7e0000)  

    # Testcase 6:  rs1:x24(0x3a2b48ef), rs2:x10(0x00000000), result rd:x6(0x00000000)
    li  x24, MASK_XLEN(0x3a2b48ef)
    fcvt.s.w f6, x24
    csrrci x2, fcsr, 0x1F
    sw x2, 8(x1)
    fmv.x.w x3, f6
    fsw f6, 12(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x4e68ad24)  

    # Testcase 7:  rs1:x23(0xbf800000), rs2:x9(0x3f9e0419), result rd:x7(0x00000000)
    li  x23, MASK_XLEN(0xbf800000)
    fcvt.s.w f7, x23
    csrrci x2, fcsr, 0x1F
    sw x2, 16(x1)
    fmv.x.w x3, f7
    fsw f7, 20(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xce810000)  

    # Testcase 8:  rs1:x22(0x3f9e0419), rs2:x8(0xbf800000), result rd:x8(0x00000000)
    li  x22, MASK_XLEN(0x3f9e0419)
    fcvt.s.w f8, x22
    csrrci x2, fcsr, 0x1F
    sw x2, 24(x1)
    fmv.x.w x3, f8
    fsw f8, 28(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x4e7e7810)  

    # Testcase 9:  rs1:x21(0x00000000), rs2:x7(0x3a2b48ef), result rd:x9(0x00000000)
    li  x21, MASK_XLEN(0x0)
    fcvt.s.w f9, x21
    csrrci x2, fcsr, 0x1F
    sw x2, 32(x1)
    fmv.x.w x3, f9
    fsw f9, 36(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x00000000)  



    

    RVTEST_SIGBASE(x1,signature_3_0)

    # Testcase 10:  rs1:x20(0xc1458794), rs2:x6(0x3f800000), result rd:x10(0x00000000)
    li  x20, MASK_XLEN(0xc1458794)
    fcvt.s.w f10, x20
    csrrci x7, fcsr, 0x1F
    sw x7, 0(x1)
    fmv.x.w x8, f10
    fsw f10, 4(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xce7ae9e2)  

    # Testcase 11:  rs1:x19(0xc61a5229), rs2:x5(0x4c50e7e7), result rd:x11(0x00000000)
    li  x19, MASK_XLEN(0xc61a5229)
    fcvt.s.w f11, x19
    csrrci x7, fcsr, 0x1F
    sw x7, 8(x1)
    fmv.x.w x8, f11
    fsw f11, 12(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xce6796b7)  

    # Testcase 12:  rs1:x18(0x4c50e7e7), rs2:x4(0xc61a5229), result rd:x12(0x00000000)
    li  x18, MASK_XLEN(0x4c50e7e7)
    fcvt.s.w f12, x18
    csrrci x7, fcsr, 0x1F
    sw x7, 16(x1)
    fmv.x.w x8, f12
    fsw f12, 20(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x4e98a1d0)  

    # Testcase 13:  rs1:x17(0x3f800000), rs2:x3(0xc1458794), result rd:x13(0x00000000)
    li  x17, MASK_XLEN(0x3f800000)
    fcvt.s.w f13, x17
    csrrci x7, fcsr, 0x1F
    sw x7, 24(x1)
    fmv.x.w x8, f13
    fsw f13, 28(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x4e7e0000)  

    # Testcase 14:  rs1:x16(0x3a2b48ef), rs2:x2(0x00000000), result rd:x14(0x00000000)
    li  x16, MASK_XLEN(0x3a2b48ef)
    fcvt.s.w f14, x16
    csrrci x7, fcsr, 0x1F
    sw x7, 32(x1)
    fmv.x.w x8, f14
    fsw f14, 36(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x4e68ad24)  



    

    RVTEST_SIGBASE(x2,signature_4_0)

    # Testcase 15:  rs1:x15(0xbf800000), rs2:x1(0x3f9e0419), result rd:x15(0x00000000)
    li  x15, MASK_XLEN(0xbf800000)
    fcvt.s.w f15, x15
    csrrci x3, fcsr, 0x1F
    sw x3, 0(x2)
    fmv.x.w x4, f15
    fsw f15, 4(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xce810000)  

    # Testcase 16:  rs1:x14(0x3f9e0419), rs2:x0(0xbf800000), result rd:x16(0x00000000)
    li  x14, MASK_XLEN(0x3f9e0419)
    fcvt.s.w f16, x14
    csrrci x3, fcsr, 0x1F
    sw x3, 8(x2)
    fmv.x.w x4, f16
    fsw f16, 12(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x4e7e7810)  

    # Testcase 17:  rs1:x13(0x00000000), rs2:x30(0x3a2b48ef), result rd:x17(0x00000000)
    li  x13, MASK_XLEN(0x0)
    fcvt.s.w f17, x13
    csrrci x3, fcsr, 0x1F
    sw x3, 16(x2)
    fmv.x.w x4, f17
    fsw f17, 20(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0x00000000)  

    # Testcase 18:  rs1:x12(0xc1458794), rs2:x29(0x3f800000), result rd:x18(0x00000000)
    li  x12, MASK_XLEN(0xc1458794)
    fcvt.s.w f18, x12
    csrrci x3, fcsr, 0x1F
    sw x3, 24(x2)
    fmv.x.w x4, f18
    fsw f18, 28(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xce7ae9e2)  

    # Testcase 19:  rs1:x11(0xc61a5229), rs2:x28(0x4c50e7e7), result rd:x19(0x00000000)
    li  x11, MASK_XLEN(0xc61a5229)
    fcvt.s.w f19, x11
    csrrci x3, fcsr, 0x1F
    sw x3, 32(x2)
    fmv.x.w x4, f19
    fsw f19, 36(x2)
    RVMODEL_IO_ASSERT_GPR_EQ(x3, x4, 0xce6796b7)  



    

    RVTEST_SIGBASE(x1,signature_5_0)

    # Testcase 20:  rs1:x10(0x4c50e7e7), rs2:x27(0xc61a5229), result rd:x20(0x00000000)
    li  x10, MASK_XLEN(0x4c50e7e7)
    fcvt.s.w f20, x10
    csrrci x2, fcsr, 0x1F
    sw x2, 0(x1)
    fmv.x.w x3, f20
    fsw f20, 4(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x4e98a1d0)  

    # Testcase 21:  rs1:x9(0x3f800000), rs2:x26(0xc1458794), result rd:x21(0x00000000)
    li  x9, MASK_XLEN(0x3f800000)
    fcvt.s.w f21, x9
    csrrci x2, fcsr, 0x1F
    sw x2, 8(x1)
    fmv.x.w x3, f21
    fsw f21, 12(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x4e7e0000)  

    # Testcase 22:  rs1:x8(0x3a2b48ef), rs2:x25(0x00000000), result rd:x22(0x00000000)
    li  x8, MASK_XLEN(0x3a2b48ef)
    fcvt.s.w f22, x8
    csrrci x2, fcsr, 0x1F
    sw x2, 16(x1)
    fmv.x.w x3, f22
    fsw f22, 20(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x4e68ad24)  

    # Testcase 23:  rs1:x7(0xbf800000), rs2:x24(0x3f9e0419), result rd:x23(0x00000000)
    li  x7, MASK_XLEN(0xbf800000)
    fcvt.s.w f23, x7
    csrrci x2, fcsr, 0x1F
    sw x2, 24(x1)
    fmv.x.w x3, f23
    fsw f23, 28(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0xce810000)  

    # Testcase 24:  rs1:x6(0x3f9e0419), rs2:x23(0xbf800000), result rd:x24(0x00000000)
    li  x6, MASK_XLEN(0x3f9e0419)
    fcvt.s.w f24, x6
    csrrci x2, fcsr, 0x1F
    sw x2, 32(x1)
    fmv.x.w x3, f24
    fsw f24, 36(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x4e7e7810)  



    

    RVTEST_SIGBASE(x6,signature_6_0)

    # Testcase 25:  rs1:x5(0x00000000), rs2:x22(0x3a2b48ef), result rd:x25(0x00000000)
    li  x5, MASK_XLEN(0x0)
    fcvt.s.w f25, x5
    csrrci x7, fcsr, 0x1F
    sw x7, 0(x6)
    fmv.x.w x8, f25
    fsw f25, 4(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x00000000)  

    # Testcase 26:  rs1:x4(0xc1458794), rs2:x21(0x3f800000), result rd:x26(0x00000000)
    li  x4, MASK_XLEN(0xc1458794)
    fcvt.s.w f26, x4
    csrrci x7, fcsr, 0x1F
    sw x7, 8(x6)
    fmv.x.w x8, f26
    fsw f26, 12(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xce7ae9e2)  

    # Testcase 27:  rs1:x3(0xc61a5229), rs2:x20(0x4c50e7e7), result rd:x27(0x00000000)
    li  x3, MASK_XLEN(0xc61a5229)
    fcvt.s.w f27, x3
    csrrci x7, fcsr, 0x1F
    sw x7, 16(x6)
    fmv.x.w x8, f27
    fsw f27, 20(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0xce6796b7)  

    # Testcase 28:  rs1:x2(0x4c50e7e7), rs2:x19(0xc61a5229), result rd:x28(0x00000000)
    li  x2, MASK_XLEN(0x4c50e7e7)
    fcvt.s.w f28, x2
    csrrci x7, fcsr, 0x1F
    sw x7, 24(x6)
    fmv.x.w x8, f28
    fsw f28, 28(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x4e98a1d0)  

    # Testcase 29:  rs1:x1(0x3f800000), rs2:x18(0xc1458794), result rd:x29(0x00000000)
    li  x1, MASK_XLEN(0x3f800000)
    fcvt.s.w f29, x1
    csrrci x7, fcsr, 0x1F
    sw x7, 32(x6)
    fmv.x.w x8, f29
    fsw f29, 36(x6)
    RVMODEL_IO_ASSERT_GPR_EQ(x7, x8, 0x4e7e0000)  



    

    RVTEST_SIGBASE(x1,signature_7_0)

    # Testcase 30:  rs1:x0(0x3a2b48ef), rs2:x17(0x00000000), result rd:x30(0x00000000)
    li  x0, MASK_XLEN(0x3a2b48ef)
    fcvt.s.w f30, x0
    csrrci x2, fcsr, 0x1F
    sw x2, 0(x1)
    fmv.x.w x3, f30
    fsw f30, 4(x1)
    RVMODEL_IO_ASSERT_GPR_EQ(x2, x3, 0x00000000)  

	
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

