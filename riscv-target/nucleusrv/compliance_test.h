// RISC-V Compliance Test Header File
// Copyright (c) 2017, Codasip Ltd. All Rights Reserved.
// See LICENSE for license details.
//
// Description: Common header file for RV32I tests

#ifndef _COMPLIANCE_TEST_H
#define _COMPLIANCE_TEST_H


//-----------------------------------------------------------------------
// RV Compliance Macros
//-----------------------------------------------------------------------


#define RV_COMPLIANCE_HALT              \
		la a0, data_begin;	 \
                la a1, data_end; \
                li a2, 0x80000000; \
        extract_data: \
        		lw a4, 0(a0); \
        		beq a0, a1, extract_data; \
        		addi a0, a0, 4; \
        		sw a4, 0(a2); \
        		j extract_data; \
        halt: \
        		j halt;

#define RV_COMPLIANCE_RV32M 											\


#define RV_COMPLIANCE_CODE_BEGIN                                              \
        .section .text.init;                                            \
        .align  4;                                                      \
        .globl _start;                                                  \
		_start:	\


#define RV_COMPLIANCE_CODE_END

#define RV_COMPLIANCE_DATA_BEGIN .align 4; .global data_begin; data_begin:

#define RV_COMPLIANCE_DATA_END .align 4; .global data_end; data_end:

#endif