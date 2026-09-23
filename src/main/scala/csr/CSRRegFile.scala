// Created by @Talha-Ahmed-1

package nucleusrv.csr

import chisel3._
import chisel3.util._

case class CSROperations(
    val READ    :UInt   =   0.U(2.W),
    val WRITE   :UInt   =   1.U(2.W),
    val SET     :UInt   =   2.U(2.W),
    val CLEAR   :UInt   =   3.U(2.W)
)

class CSRRegFile(XLEN : Int) extends Module{
    val io = IO(new CSRRegFileIO(XLEN))

    /***************** Initializations *****************/
    // Registers
    val MISA_REG            = RegInit(io.MISA.i_value & ~((1.U << 18) | (1.U << 20)))
    val MARCHID_REG         = RegInit(0.U(32.W))
    val MHARTID_REG         = RegInit(0.U(32.W))
    val MEDELEG_REG         = RegInit(0.U(32.W))
    val MIDELEG_REG         = RegInit(0.U(32.W))
    val MEDELEGH_REG        = RegInit(0.U(32.W))
    val MCAUSE_REG          = RegInit(0.U(32.W))
    val MTVEC_REG           = RegInit(0.U(32.W))
    val MEPC_REG            = RegInit(0.U(32.W))
    val MSCRATCH_REG        = RegInit(0.U(32.W))
    val MTVAL_REG           = RegInit(0.U(32.W))
    val MCYCLE_REG          = RegInit(0.U(32.W))
    val MCYCLEH_REG         = RegInit(0.U(32.W))
    val MINSTRET_REG        = RegInit(0.U(32.W))
    val MINSTRETH_REG       = RegInit(0.U(32.W))
    
    // MSTATUS
    val MSTATUS_TSR_REG     = RegInit(0.U(1.W))
    val MSTATUS_TW_REG      = RegInit(0.U(1.W))
    val MSTATUS_TVM_REG     = RegInit(0.U(1.W))
    val MSTATUS_MXR_REG     = RegInit(0.U(1.W))
    val MSTATUS_SUM_REG     = RegInit(0.U(1.W))
    val MSTATUS_MPRV_REG    = RegInit(0.U(1.W))
    val MSTATUS_MPP_REG     = RegInit(3.U(2.W))
    val MSTATUS_SPP_REG     = RegInit(0.U(1.W))
    val MSTATUS_MPIE_REG    = RegInit(0.U(1.W))
    val MSTATUS_UBE_REG     = RegInit(0.U(1.W))
    val MSTATUS_SPIE_REG    = RegInit(0.U(1.W))
    val MSTATUS_MIE_REG     = RegInit(0.U(1.W))
    val MSTATUS_SIE_REG     = RegInit(0.U(1.W))

    // MSTATUS Extension Context
    val MSTATUS_FS_REG      = RegInit(0.U(2.W))
    val MSTATUS_VS_REG      = RegInit(0.U(2.W))

    // MSTATUSH
    val MSTATUSH_MBE_REG    = RegInit(0.U(1.W))
    val MSTATUSH_SBE_REG    = RegInit(0.U(1.W))

    // MENVCFG
    val MENVCFG_REG         = RegInit(0.U(32.W))
    val MENVCFGH_REG        = RegInit(0.U(32.W))

    // MIE
    val MIE_MEIE_REG        = RegInit(0.U(1.W))
    val MIE_MTIE_REG        = RegInit(0.U(1.W))
    val MIE_MSIE_REG        = RegInit(0.U(1.W))
    val MIE_SEIE_REG        = RegInit(0.U(1.W))
    val MIE_STIE_REG        = RegInit(0.U(1.W))
    val MIE_SSIE_REG        = RegInit(0.U(1.W))

    // MIP
    val MIP_MEIP_REG        = RegInit(0.U(1.W))
    val MIP_MTIP_REG        = RegInit(0.U(1.W))
    val MIP_MSIP_REG        = RegInit(0.U(1.W))
    val MIP_SEIP_REG        = RegInit(0.U(1.W)) // Writable by M-mode
    val MIP_STIP_REG        = RegInit(0.U(1.W)) // Writable by M-mode
    val MIP_SSIP_REG        = RegInit(0.U(1.W)) // Writable by M-mode

    // MCOUNTINHIBIT
    val MCOUNTINHIBIT_CY_REG = RegInit(0.U(1.W))
    val MCOUNTINHIBIT_IR_REG = RegInit(0.U(1.W))
    val MCOUNTINHIBIT_HPM_REG= RegInit(0.U(29.W))
    
    // MCOUNTEREN
    val MCOUNTEREN_CY_REG    = RegInit(0.U(1.W))
    val MCOUNTEREN_TM_REG    = RegInit(0.U(1.W))
    val MCOUNTEREN_IR_REG    = RegInit(0.U(1.W))
    val MCOUNTEREN_HPM_REG   = RegInit(0.U(29.W))

    // time
    val TIME_REG            = RegInit(0.U(32.W))
    val TIMEH_REG           = RegInit(0.U(32.W))

    //FCSR 
    val FCSR_NX_REG         = RegInit(0.B)
    val FCSR_UF_REG         = RegInit(0.B)
    val FCSR_OF_REG         = RegInit(0.B)
    val FCSR_DZ_REG         = RegInit(0.B)
    val FCSR_NV_REG         = RegInit(0.B)
    val FCSR_FRM_REG        = RegInit(0.U(3.W))

    /***************************************************/

    // Hardwired
    MHARTID_REG             := io.MHARTID.i_value
    MARCHID_REG             := io.MARCHID.i_value

    Vector(
      FCSR_NX_REG,
      FCSR_UF_REG,
      FCSR_OF_REG,
      FCSR_DZ_REG,
      FCSR_NV_REG
    ).zipWithIndex.foreach(
      f => f._1 := f._1 | io.FCSR.except(f._2)
    )
    io.FCSR.nx              := FCSR_NX_REG
    io.FCSR.uf              := FCSR_UF_REG
    io.FCSR.of              := FCSR_OF_REG
    io.FCSR.dz              := FCSR_DZ_REG
    io.FCSR.nv              := FCSR_NV_REG
    io.FCSR.frm             := FCSR_FRM_REG

    io.mtvec_val            := MTVEC_REG
    io.mepc_val             := MEPC_REG
    io.medeleg_val          := MEDELEG_REG
    io.mideleg_val          := MIDELEG_REG
    io.misa_val             := MISA_REG
 
    // Extension availability
    val has_s = MISA_REG(18)
    val has_u = MISA_REG(20)
    val has_f = MISA_REG(5)
    val has_v = MISA_REG(21)

    // Wires
    val w_data                  = Wire(UInt(32.W))
    val r_data                  = Wire(UInt(32.W))

    // SD Bit Calculation
    // SD is 1 if FS, VS, or XS are in Dirty state (11)
    val sd = (MSTATUS_FS_REG === 3.U) || (MSTATUS_VS_REG === 3.U)

    val MSTATUS_WIRE            = WireInit(Cat(sd, "b0".U(8.W), MSTATUS_TSR_REG, MSTATUS_TW_REG, MSTATUS_TVM_REG, MSTATUS_MXR_REG, MSTATUS_SUM_REG, MSTATUS_MPRV_REG, "b0".U(2.W), MSTATUS_FS_REG, MSTATUS_MPP_REG, MSTATUS_VS_REG, MSTATUS_SPP_REG, MSTATUS_MPIE_REG, MSTATUS_UBE_REG, MSTATUS_SPIE_REG, "b0".U(1.W), MSTATUS_MIE_REG, "b0".U(1.W), MSTATUS_SIE_REG, "b0".U(1.W)))
    val MSTATUSH_WIRE           = WireInit(Cat("b0".U(26.W), MSTATUSH_MBE_REG, MSTATUSH_SBE_REG, "b0".U(4.W)))
    
    val MIE_WIRE                = WireInit(Cat("b0".U(20.W), MIE_MEIE_REG, "b0".U(1.W), MIE_SEIE_REG, "b0".U(1.W), MIE_MTIE_REG, "b0".U(1.W), MIE_STIE_REG, "b0".U(1.W), MIE_MSIE_REG, "b0".U(1.W), MIE_SSIE_REG, "b0".U(1.W)))
    val MIP_WIRE                = WireInit(Cat("b0".U(20.W), MIP_MEIP_REG, "b0".U(1.W), MIP_SEIP_REG, "b0".U(1.W), MIP_MTIP_REG, "b0".U(1.W), MIP_STIP_REG, "b0".U(1.W), MIP_MSIP_REG, "b0".U(1.W), MIP_SSIP_REG, "b0".U(1.W)))
    val MCAUSE_WLRL_WIRE        = WireInit(MCAUSE_REG(30,0))
    val MCAUSE_INTERRUPT_WIRE   = WireInit(MCAUSE_REG(31))
    val MTVEC_MODE_WIRE         = WireInit(MTVEC_REG(1,0))
    val MTVEC_BASE_WIRE         = WireInit(MTVEC_REG(31,2))
    val MCOUNTINHIBIT_WIRE      = WireInit(Cat(MCOUNTINHIBIT_HPM_REG, MCOUNTINHIBIT_IR_REG, "b0".U(1.W), MCOUNTINHIBIT_CY_REG))
    val MCOUNTEREN_WIRE         = WireInit(Cat(MCOUNTEREN_HPM_REG, MCOUNTEREN_IR_REG, MCOUNTEREN_TM_REG, MCOUNTEREN_CY_REG))
    
    // MEPC Masking for R/W
    val has_c = MISA_REG(2)
    val mepc_mask = Mux(has_c, "hFFFFFFFE".U(32.W), "hFFFFFFFC".U(32.W))
    val mepc_read_val = MEPC_REG & mepc_mask

    val FFLAGS_WIRE             = WireInit(Cat(
                                    "b0".U(27.W),
                                    FCSR_NV_REG,
                                    FCSR_DZ_REG,
                                    FCSR_OF_REG,
                                    FCSR_UF_REG,
                                    FCSR_NX_REG
                                  ))
    val FRM_WIRE                = WireInit(Cat("b0".U(29.W),FCSR_FRM_REG))
    val FCSR_WIRE               = WireInit(Cat(
                                    "b0".U(24.W),
                                    FCSR_FRM_REG,
                                    FCSR_NV_REG,
                                    FCSR_DZ_REG,
                                    FCSR_OF_REG,
                                    FCSR_UF_REG,
                                    FCSR_NX_REG
                                  ))

    val csr_opr = CSROperations()
    /***************************************************/

    /****************** cycle counter ******************/
    when(!MCOUNTINHIBIT_CY_REG) {
        val CYCLE = Wire(UInt(64.W))
        CYCLE := Cat(MCYCLEH_REG, MCYCLE_REG) + 1.U
        MCYCLE_REG  := CYCLE(31,0)
        MCYCLEH_REG := CYCLE(63,32)
    }
    /***************************************************/

    /****************** time counter *******************/
    // Increment time counter every cycle
    val TIME = Wire(UInt(64.W))
    TIME      := Cat(TIMEH_REG, TIME_REG) + 1.U
    TIME_REG  := TIME(31,0)
    TIMEH_REG := TIME(63,32)
    /***************************************************/

    /****************** instret counter ******************/
    when(io.MINSTRET.i_instr_retired && !MCOUNTINHIBIT_IR_REG){
        val INSTRET = Wire(UInt(64.W))
        INSTRET := Cat(MINSTRETH_REG, MINSTRET_REG) + 1.U
        MINSTRET_REG  := INSTRET(31,0)
        MINSTRETH_REG := INSTRET(63,32)
    }
    /***************************************************/

    /****************** Read Logic ******************/
    var READ,WRITE,SET,CLEAR = Wire(UInt(2.W))
    Seq(READ,WRITE,SET,CLEAR) zip Seq(csr_opr.READ, csr_opr.WRITE, csr_opr.SET, csr_opr.CLEAR) map (x => x._1 := x._2)

    val READ_CASES = Array(
        AddressMap.MISA    -> MISA_REG,
        AddressMap.MHARTID -> MHARTID_REG,
        AddressMap.MARCHID -> MARCHID_REG,
        AddressMap.MEDELEG -> MEDELEG_REG,
        AddressMap.MIDELEG -> MIDELEG_REG,
        AddressMap.MEDELEGH-> MEDELEGH_REG,
        AddressMap.MSTATUS -> MSTATUS_WIRE,
        AddressMap.MSTATUSH-> MSTATUSH_WIRE,
        AddressMap.MENVCFG -> Mux(has_u, MENVCFG_REG, 0.U),
        AddressMap.MENVCFGH-> Mux(has_u, MENVCFGH_REG, 0.U),
        AddressMap.MCAUSE  -> MCAUSE_REG,
        AddressMap.MTVEC   -> MTVEC_REG,
        AddressMap.MEPC    -> mepc_read_val,
        AddressMap.MSCRATCH-> MSCRATCH_REG,
        AddressMap.MTVAL   -> MTVAL_REG,
        AddressMap.MIE     -> MIE_WIRE,
        AddressMap.MIP     -> MIP_WIRE,
        AddressMap.FFLAGS  -> FFLAGS_WIRE,
        AddressMap.FRM     -> FRM_WIRE,
        AddressMap.FCSR    -> FCSR_WIRE,
        AddressMap.MCYCLE  -> MCYCLE_REG,
        AddressMap.MCYCLEH -> MCYCLEH_REG,
        AddressMap.MINSTRET-> MINSTRET_REG,
        AddressMap.MINSTRETH-> MINSTRETH_REG,
        AddressMap.MCOUNTINHIBIT-> MCOUNTINHIBIT_WIRE,
        AddressMap.MCOUNTEREN -> MCOUNTEREN_WIRE,
        AddressMap.TIME    -> TIME_REG,
        AddressMap.TIMEH   -> TIMEH_REG
    )

    val is_hpm = (io.CSR.i_addr >= "hB03".U && io.CSR.i_addr <= "hB1F".U) || 
                 (io.CSR.i_addr >= "hB83".U && io.CSR.i_addr <= "hB9F".U) ||
                 (io.CSR.i_addr >= "h323".U && io.CSR.i_addr <= "h33F".U)

    r_data := Mux(is_hpm, 0.U, MuxLookup(io.CSR.i_addr, 0.U, READ_CASES)) 
    
    io.CSR.o_data := r_data
    /*************************************************/

    /****************** Write Logic ******************/
    val set_data   = r_data |  io.CSR.i_data
    val clear_data = r_data & ~io.CSR.i_data

    // Identify the operation
    w_data := MuxLookup(io.CSR.i_opr, DontCare, Array(
        WRITE -> io.CSR.i_data,
        SET   -> set_data,
        CLEAR -> clear_data
    ))

    // Write to the register
    when(io.CSR.i_w_en){
        switch(io.CSR.i_addr){
            is(AddressMap.MISA){
                // Mask out S (18) and U (20) to enforce M-mode only
                val mask = io.MISA.i_value(25,0) & ~((1.U << 18) | (1.U << 20))
                val w_ext = w_data(25,0) & mask
                val w_vec = VecInit(w_ext.asBools)
                
                val new_vec = Wire(Vec(26, Bool()))
                new_vec := w_vec

                // Dependencies
                // D(3) depends on F(5)
                val f = w_vec(5)
                val d = w_vec(3) && f
                new_vec(3) := d

                // Q(16) depends on D(3)
                val q = w_vec(16) && d
                new_vec(16) := q

                // S(18) depends on U(20)
                val u = w_vec(20)
                val s = w_vec(18) && u
                new_vec(18) := s

                MISA_REG := Cat(io.MISA.i_value(31,26), new_vec.asUInt)
            }
            is(AddressMap.MSTATUS){
                MSTATUS_TSR_REG  := w_data(22)
                MSTATUS_TW_REG   := w_data(21)
                MSTATUS_TVM_REG  := w_data(20)
                MSTATUS_MXR_REG  := w_data(19)
                MSTATUS_SUM_REG  := w_data(18)
                MSTATUS_MPRV_REG := w_data(17)
                
                // FS and VS writable only if extensions are enabled
                when(MISA_REG(5)) { MSTATUS_FS_REG := w_data(14,13) }
                when(MISA_REG(21)) { MSTATUS_VS_REG := w_data(10,9) }
             
                MSTATUS_MPP_REG  := w_data(12,11)
                MSTATUS_SPP_REG  := w_data(8)
                MSTATUS_MPIE_REG := w_data(7)
                MSTATUS_UBE_REG  := w_data(6)
                MSTATUS_SPIE_REG := w_data(5)
                MSTATUS_MIE_REG  := w_data(3)
                MSTATUS_SIE_REG  := w_data(1)
            }
            is(AddressMap.MSTATUSH){
               MSTATUSH_MBE_REG  := w_data(5)
               MSTATUSH_SBE_REG  := w_data(4)
            }
            is(AddressMap.MENVCFG){
                when(has_u) {
                    val mask = "h1F1".U(32.W)
                    MENVCFG_REG := w_data & mask
                }
            }
            is(AddressMap.MENVCFGH){
                when(has_u) {
                    val mask = "hF8000003".U(32.W)
                    MENVCFGH_REG := w_data & mask
                }
            }
            is(AddressMap.MEDELEG){
               when(has_s) {
                   val read_only_zero_mask = (1.U << 11)
                   MEDELEG_REG := w_data & ~read_only_zero_mask
               }
            }
            is(AddressMap.MEDELEGH){
               // Only exists for XLEN=32
               when(has_s) {
                    MEDELEGH_REG      := w_data
               }
            }
            is(AddressMap.MIDELEG){
               // Only exists if S-mode supported
               when(has_s) {
                   MIDELEG_REG       := w_data
               }
            }
            is(AddressMap.MCAUSE){
                MCAUSE_REG       := w_data
            }
            is(AddressMap.MTVEC){
                val mode = w_data(1,0)

                val mode_valid = mode === 0.U || mode === 1.U
                val new_mode = Mux(mode_valid, mode, MTVEC_REG(1,0))
                
                MTVEC_REG        := Cat(w_data(31,2), new_mode)
            }
            is(AddressMap.MEPC){
                MEPC_REG         := w_data & "hFFFFFFFE".U(32.W)
            }
            is(AddressMap.MSCRATCH){
                MSCRATCH_REG     := w_data
            }
            is(AddressMap.MTVAL){
                MTVAL_REG        := w_data
            }
            is(AddressMap.MIE){
                MIE_MEIE_REG     := w_data(11)
                MIE_MTIE_REG     := w_data(7)
                MIE_MSIE_REG     := w_data(3)
                
                // Supervisor Interrupt Enables (Writable only if S-mode supported)
                when(has_s) {
                    MIE_SEIE_REG := w_data(9)
                    MIE_STIE_REG := w_data(5)
                    MIE_SSIE_REG := w_data(1)
                }
            }
            is(AddressMap.MIP){
                // M-mode pending bits (MEIP, MTIP, MSIP) are read-only — set by external hardware
                when(has_s) {
                    MIP_SEIP_REG := w_data(9)
                    MIP_STIP_REG := w_data(5)
                    MIP_SSIP_REG := w_data(1)
                }
            }
            is(AddressMap.FCSR){
               FCSR_NX_REG       := w_data(0)
               FCSR_UF_REG       := w_data(1)
               FCSR_OF_REG       := w_data(2)
               FCSR_DZ_REG       := w_data(3)
               FCSR_NV_REG       := w_data(4)
               FCSR_FRM_REG      := w_data(7,5)
            }
            is(AddressMap.FFLAGS){
               FCSR_NX_REG       := w_data(0)
               FCSR_UF_REG       := w_data(1)
               FCSR_OF_REG       := w_data(2)
               FCSR_DZ_REG       := w_data(3)
               FCSR_NV_REG       := w_data(4)
            }
            is(AddressMap.FRM){
               FCSR_FRM_REG      := w_data(2,0)
            }
            is(AddressMap.MCYCLE){
                MCYCLE_REG        := w_data
            }
            is(AddressMap.MCYCLEH){
                MCYCLEH_REG       := w_data
            }
            is(AddressMap.MINSTRET){
                MINSTRET_REG      := w_data
            }
            is(AddressMap.MINSTRETH){
                MINSTRETH_REG     := w_data
            }
            is(AddressMap.MCOUNTINHIBIT){
                MCOUNTINHIBIT_CY_REG := w_data(0)
                MCOUNTINHIBIT_IR_REG := w_data(2)
                MCOUNTINHIBIT_HPM_REG:= w_data(31,3)
            }
            is(AddressMap.MCOUNTEREN){
                // Only exists if U-mode is supported
                when(has_u) {
                    MCOUNTEREN_CY_REG   := w_data(0)
                    MCOUNTEREN_TM_REG   := w_data(1)
                    MCOUNTEREN_IR_REG   := w_data(2)
                    MCOUNTEREN_HPM_REG  := w_data(31,3)
                }
            }
            is(AddressMap.TIME){
                TIME_REG         := w_data
            }
            is(AddressMap.TIMEH){
                TIMEH_REG        := w_data
            }
        }
    }
    /*************************************************/

    // Clear registers when extensions are disabled
    when(!has_s) {
        MEDELEG_REG      := 0.U
        MEDELEGH_REG     := 0.U
        MIDELEG_REG      := 0.U
        MSTATUS_TSR_REG  := 0.U
        MSTATUS_TVM_REG  := 0.U
        MSTATUS_MXR_REG  := 0.U
        MSTATUS_SUM_REG  := 0.U
        MSTATUS_SPP_REG  := 0.U
        MSTATUS_SPIE_REG := 0.U
        MSTATUS_SIE_REG  := 0.U
        
        MSTATUSH_SBE_REG := 0.U
        
        MIE_SEIE_REG     := 0.U
        MIE_STIE_REG     := 0.U
        MIE_SSIE_REG     := 0.U
        
        MIP_SEIP_REG     := 0.U
        MIP_STIP_REG     := 0.U
        MIP_SSIP_REG     := 0.U
    }

    when(!has_u) {
        MENVCFG_REG      := 0.U
        MENVCFGH_REG     := 0.U
    }

    when(!(has_s || has_u)) {
        MSTATUS_TW_REG   := 0.U
    }

    // Clear FS if F is disabled
    when(!has_f) {
        MSTATUS_FS_REG := 0.U
    }

    // Clear VS if V is disabled
    when(!has_v) {
        MSTATUS_VS_REG := 0.U
    }
}
