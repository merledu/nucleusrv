

#define mseccfg         0x747

#define OK              0x00000000
#define FAILED          0x0000000F

#define MODE_M          0x00000010
#define MODE_S          0x00000020
#define MODE_U          0x00000030

#define ACCESS_X        0x00000100
#define ACCESS_W        0x00000200
#define ACCESS_R        0x00000300



////////////////////////////////////////////////////////////////////////////////
// DEFINE PTE
////////////////////////////////////////////////////////////////////////////////

#define PTE(_PADDR, _DAGUXWRV) \
    (((_PADDR)/4) + (_DAGUXWRV))

//#define PTE_X(_PADDR, _DAGUXWRV, _N, _PBMT) \
//    (((_PADDR)/4) + (_DAGUXWRV) + (_N)<<63 + (_PBMT)<<61)

////////////////////////////////////////////////////////////////////////////////
// DAGUXWRV MACRO
// D:   dirty
// A:   accessed
// G:   global
// U:   user-accessible
// X:   execute
// W:   write
// R:   read
// V:   valid
////////////////////////////////////////////////////////////////////////////////

#define DAGUXWRV_INT(_D, _A, _G, _U, _X, _W, _R, _V) \
    _D<<7 + _A<<6 + _G<<5 + _U<<4 + _X<<3 + _W<<2 + _R<<1 + _V<<0

// leaf entries
#define DAGUXWRV    DAGUXWRV_INT(1,1,1,1,1,1,1,1)
#define DAG_XWRV    DAGUXWRV_INT(1,1,1,0,1,1,1,1)
#define DAGU__RV    DAGUXWRV_INT(1,1,1,1,0,0,1,1)
#define DAG___RV    DAGUXWRV_INT(1,1,1,0,0,0,1,1)
#define DAGU_WRV    DAGUXWRV_INT(1,1,1,1,0,1,1,1)
#define DAG__WRV    DAGUXWRV_INT(1,1,1,0,0,1,1,1)
#define DAGUX__V    DAGUXWRV_INT(1,1,1,1,1,0,0,1)
#define DAG_X__V    DAGUXWRV_INT(1,1,1,0,1,0,0,1)
#define DAGUX_RV    DAGUXWRV_INT(1,1,1,1,1,0,1,1)
#define DAG_X_RV    DAGUXWRV_INT(1,1,1,0,1,0,1,1)
#define DA__XWRV    DAGUXWRV_INT(1,1,0,0,1,1,1,1)
#define DA___WRV    DAGUXWRV_INT(1,1,0,0,0,1,1,1)
#define _____WRV    DAGUXWRV_INT(0,0,0,0,0,1,1,1)

// non-leaf entries
#define NEXT_GV     DAGUXWRV_INT(0,0,1,0,0,0,0,1)

// invalid entries
#define DAG_XWR_    DAGUXWRV_INT(1,1,1,0,1,1,1,0)
#define DAGUXWR_    DAGUXWRV_INT(1,1,1,1,1,1,1,0)
#define DAG_XW_V    DAGUXWRV_INT(1,1,1,0,1,1,0,1)
#define _AG_XWRV    DAGUXWRV_INT(0,1,1,0,1,1,1,1)
#define _AGUXWRV    DAGUXWRV_INT(0,1,1,1,1,1,1,1)
#define D_G_XWRV    DAGUXWRV_INT(1,0,1,0,1,1,1,1)
#define D_GUXWRV    DAGUXWRV_INT(1,0,1,1,1,1,1,1)
#define D______V    DAGUXWRV_INT(1,0,0,0,0,0,0,1)
#define _A_____V    DAGUXWRV_INT(0,1,0,0,0,0,0,1)
#define ___U___V    DAGUXWRV_INT(0,0,0,1,0,0,0,1)

////////////////////////////////////////////////////////////////////////////////
// SET UP PAGE TABLES (destroys t0-t1)
////////////////////////////////////////////////////////////////////////////////

.macro SETUP_SVX_32 _MODE, _ASID, _BASE, _CSR=satp
        li          t1, \_MODE<<31      // mode
        li          t0, \_ASID<<22      // ASID
        or          t1, t1, t0
        la          t0, \_BASE          // table base address
        srli        t0, t0, 12
        or          t1, t1, t0
        csrw        \_CSR, t1
.endm
.macro SETUP_SVX_64 _MODE, _ASID, _BASE, _CSR=satp
        li          t1, \_MODE<<60      // mode
        li          t0, \_ASID<<44      // ASID
        or          t1, t1, t0
        la          t0, \_BASE          // table base address
        srli        t0, t0, 12
        or          t1, t1, t0
        csrw        \_CSR, t1
.endm
.macro SETUP_SV32 _ASID, _BASE, _CSR=satp
        SETUP_SVX_32  1, \_ASID, \_BASE, \_CSR
.endm
.macro SETUP_SV39 _ASID, _BASE, _CSR=satp
        SETUP_SVX_64  8, \_ASID, \_BASE, \_CSR
.endm
.macro SETUP_SV48 _ASID, _BASE, _CSR=satp
        SETUP_SVX_64  9, \_ASID, \_BASE, \_CSR
.endm
.macro SETUP_SV57 _ASID, _BASE, _CSR=satp
        SETUP_SVX_64 10, \_ASID, \_BASE, \_CSR
.endm

////////////////////////////////////////////////////////////////////////////////
// FIX UP 32-BIT TABLE ENTRY AT _SRC SO IT REFERENCES _DST (destroys t0-t2)
////////////////////////////////////////////////////////////////////////////////

.macro PTE_FIXUP_32 _SRC, _DST
        la          t0, \_SRC
        la          t1, \_DST
        srli        t1, t1, 2
        lw          t2, (t0)
        or          t2, t2, t1
        sw          t2, (t0)
.endm

////////////////////////////////////////////////////////////////////////////////
// FIX UP 64-BIT TABLE ENTRY AT _SRC SO IT REFERENCES _DST (destroys t0-t2)
////////////////////////////////////////////////////////////////////////////////

.macro PTE_FIXUP_64 _SRC, _DST
        la          t0, \_SRC
        la          t1, \_DST
        srli        t1, t1, 2
        ld          t2, (t0)
        or          t2, t2, t1
        sd          t2, (t0)
.endm

////////////////////////////////////////////////////////////////////////////////
// DEFINE PMP ENTRY OF GIVEN BASE AND SIZE
////////////////////////////////////////////////////////////////////////////////

#define PMP_ENTRY_NA(_BASE, _SIZE)  (((_BASE) + ((_SIZE)/2) - 1) >> 2)

#define PMP_CFG(_L, _MODE, _PRIV)   (((_L)<<7) + ((_MODE)<<3) + (_PRIV))

#ifdef RVMODEL_ASSERT        
        #define ASSERT_WRITE_STR(_SP, _STR)     RVMODEL_IO_WRITE_STR(_SP, _STR)
#else
        #define ASSERT_WRITE_STR(_SP, _STR) 
#endif

.align 4

defaultMScratch:
        .fill 16, 8, 0

defaultSScratch:
        .fill 16, 8, 0

defaultVSScratch:
        .fill 16, 8, 0

defaultUScratch:
        .fill 16, 8, 0

////////////////////////////////////////////////////////////////////////////////
// SETUP_*HANDLER <base>, <scratch>: set exception handler address and
// scratch area address for exception taken to each mode (destroys t0)
////////////////////////////////////////////////////////////////////////////////

.macro SETUP_M_HANDLER _BASE=defaultMHandler, _SCRATCH=defaultMScratch
        la          t0, \_BASE
        csrw        mtvec, t0
        la          t0, \_SCRATCH
        csrw        mscratch, t0
.endm

.macro SETUP_S_HANDLER _BASE=defaultSHandler, _SCRATCH=defaultSScratch
        la          t0, \_BASE
        csrw        stvec, t0
        la          t0, \_SCRATCH
        csrw        sscratch, t0
.endm

.macro SETUP_VS_HANDLER _BASE=defaultVSHandler, _SCRATCH=defaultVSScratch
        la          t0, \_BASE
        csrw        vstvec, t0
        la          t0, \_SCRATCH
        csrw        vsscratch, t0
.endm

.macro SETUP_U_HANDLER _BASE=defaultUHandler, _SCRATCH=defaultUScratch
        la          t0, \_BASE
        csrw        utvec, t0
        la          t0, \_SCRATCH
        csrw        uscratch, t0
.endm




.macro APPLY_S_Q _TGT

        // set mstatus.MPP=1 (return to Supervisor mode)
        li          t0, 1<<11
        csrs        mstatus, t0

        // set resume address
        la          t0, \_TGT
        csrw        mepc, t0

        // get resume address on mode switch return
        la          s8, 100f

        // return to switch mode
        mret
100:
.endm


.macro APPLY_U_Q _TGT

        // set mstatus.MPP=0 (return to User mode)
        li          t0, 1<<11
        csrc        mstatus, t0

        // set resume address
        la          t0, \_TGT
        csrw        mepc, t0

        // get resume address on mode switch return
        la          s8, 100f

        // return to switch mode
        mret
100:
.endm


#define TEST_ACCESS_X(_NUM, _REGION, _MODE) \
        li          s7, 0; \
        call  mapped##_REGION; \
        li t2, (_NUM << 24)|(_REGION << 16) | ACCESS_X|_MODE; \
        or t2, t2, s7; \
        sw t2, 0(s4); \
        addi s4, s4, 4;

#define TEST_ACCESS_W(_NUM, _REGION, _MODE) \
        li          s7, 0; \
        la          a6, mapped##_REGION; \
        li    t0, 0x00018082; \
        sw    t0, 0(a6); \
        nop; \
        li t2, (_NUM << 24)|(_REGION << 16) | ACCESS_W|_MODE; \
        or t2, t2, s7; \
        sw t2, 0(s4); \
        addi s4, s4, 4;

#define TEST_ACCESS_R(_NUM, _REGION, _MODE) \
        li          s7, 0; \
        la          a6, mapped##_REGION; \
        lw    t0, 0(a6); \
        nop; \
        li t2, (_NUM << 24)|(_REGION << 16) | ACCESS_R|_MODE; \
        or t2, t2, s7; \
        sw t2, 0(s4); \
        addi s4, s4, 4;

#define TEST_MMU_ACCESS_X(_NUM, _ADDR, _MODE) \
        li          s7, 0; \
        li         s6, 0; \
        li      t2, _ADDR; \
        jalr    ra, t2, 0; \
        li t2, (_NUM << 24)| ACCESS_X|_MODE; \
        or t2, t2, s7; \
        sw t2, 0(s4); \
        sw s6, 4(s4); \
        addi s4, s4, 8;

#define TEST_MMU_ACCESS_W(_NUM, _ADDR, _MODE) \
        li          s7, 0; \
        li          s6, 0; \
        li          a6, _ADDR; \
        li    t0, 0x00018082; \
        SREG    t0, 0(a6); \
        nop; \
        li t2, (_NUM << 24) | ACCESS_W|_MODE; \
        or t2, t2, s7; \
        sw t2, 0(s4); \
        sw s6, 4(s4); \
        addi s4, s4, 8;

#define TEST_MMU_ACCESS_R(_NUM, _ADDR, _MODE) \
        li          s7, 0; \
        li          s6, 0; \
        li          a6, _ADDR; \
        LREG    s6, 0(a6); \
        nop; \
        li t2, (_NUM << 24) | ACCESS_R|_MODE; \
        or t2, t2, s7; \
        sw t2, 0(s4); \
        sw s6, 4(s4); \
        addi s4, s4, 8;

#define JUMP_TO_ENTRY(_ADDR) \
        li          t0, _ADDR; \
        jalr        x0, t0, 0;

.balign 64

customHandler:
        li          s7, 10
        csrr        t1, mcause
                                     
        // handle ecall-from-U instruction (code 0x8)
        li          t0, CAUSE_USER_ECALL
        bne         t1, t0, 1f
        
        call           write_tohost

        // special code: resume in Machine mode
        jr          s8

1:      // handle ecall-from-S instruction (code 0x9)
        li          t0, CAUSE_SUPERVISOR_ECALL
        bne         t1, t0, 1f

        call           write_tohost

        // special code: resume in Machine mode
        jr          s8

1:      li          t0, CAUSE_MACHINE_ECALL
        bne         t1, t0, 1f

        call           write_tohost

        // handle fault type
1:      li          t0, 1
        beq         t1, t0, 3f
        li          t0, 12
        beq         t1, t0, 3f
        j           1f

3:      // instruction access fault: resume at ra
        //li          s7, 0x02
        csrw        mepc, ra
        j           2f

        // data access fault / mode switch : skip faulting instruction
1:      
        //li          s7, 0x03
        csrr        t0, mepc
        addi        t0, t0, 4
        csrw        mepc, t0

        // set failure code
2:      
        csrr        s7, mcause 

        mret