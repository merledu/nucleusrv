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

class CSRRegFile extends Module{
    val io = IO(new CSRRegFileIO)

    /***************** Initializations *****************/
    // Registers
    val MISA_REG            = RegInit(0.U(32.W))
    val MARCHID_REG         = RegInit(0.U(32.W))
    val MHARTID_REG         = RegInit(0.U(32.W))
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
    val MSTATUS_MPP_REG     = RegInit(0.U(2.W))
    val MSTATUS_SPP_REG     = RegInit(0.U(1.W))
    val MSTATUS_MPIE_REG    = RegInit(0.U(1.W))
    val MSTATUS_UBE_REG     = RegInit(0.U(1.W))
    val MSTATUS_SPIE_REG    = RegInit(0.U(1.W))
    val MSTATUS_MIE_REG     = RegInit(0.U(1.W))
    val MSTATUS_SIE_REG     = RegInit(0.U(1.W))

    // MIE
    val MIE_MEIE_REG        = RegInit(0.U(1.W))
    val MIE_MTIE_REG        = RegInit(0.U(1.W))
    val MIE_MSIE_REG        = RegInit(0.U(1.W))

    // MIP
    val MIP_MEIP_REG        = RegInit(0.U(1.W))
    val MIP_MTIP_REG        = RegInit(0.U(1.W))
    val MIP_MSIP_REG        = RegInit(0.U(1.W))

    // MCOUNTINHIBIT
    val MCOUNTINHIBIT_CY_REG = RegInit(0.U(1.W))
    val MCOUNTINHIBIT_IR_REG = RegInit(0.U(1.W))

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
    MISA_REG                := io.MISA.i_value
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

    // Wires
    val w_data                  = Wire(UInt(32.W))
    val r_data                  = Wire(UInt(32.W))
    val MSTATUS_WIRE            = WireInit(Cat("b0".U(9.W),MSTATUS_TSR_REG, MSTATUS_TW_REG, MSTATUS_TVM_REG, MSTATUS_MXR_REG, MSTATUS_SUM_REG, MSTATUS_MPRV_REG, "b0".U(4.W), MSTATUS_MPP_REG, "b0".U(2.W), MSTATUS_SPP_REG, MSTATUS_MPIE_REG, MSTATUS_UBE_REG, MSTATUS_SPIE_REG, "b0".U(1.W), MSTATUS_MIE_REG, "b0".U(1.W), MSTATUS_SIE_REG, "b0".U(1.W)))
    val MIE_WIRE                = WireInit(Cat("b0".U(21.W), MIE_MEIE_REG, "b0".U(3.W), MIE_MTIE_REG, "b0".U(3.W), MIE_MSIE_REG, "b0".U(3.W)))
    val MIP_WIRE                = WireInit(Cat("b0".U(21.W), MIP_MEIP_REG, "b0".U(3.W), MIP_MTIP_REG, "b0".U(3.W), MIP_MSIP_REG, "b0".U(3.W)))
    val MCAUSE_WLRL_WIRE        = WireInit(MCAUSE_REG(30,0))
    val MCAUSE_INTERRUPT_WIRE   = WireInit(MCAUSE_REG(31))
    val MTVEC_MODE_WIRE         = WireInit(MTVEC_REG(1,0))
    val MTVEC_BASE_WIRE         = WireInit(MTVEC_REG(31,2))
    val MCOUNTINHIBIT_WIRE      = WireInit(Cat("b0".U(29.W),MCOUNTINHIBIT_IR_REG, "b0".U(1.W), MCOUNTINHIBIT_CY_REG))
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
    when(!MCOUNTINHIBIT_CY_REG){    
        MCYCLE_REG := MCYCLE_REG + 1.U
        when(MCYCLE_REG === 0.U){
            MCYCLEH_REG := MCYCLEH_REG + 1.U
        }
    }
    /***************************************************/

    /****************** time counter *******************/
    // Increment time counter every cycle
    TIME_REG := TIME_REG + 1.U
    when(TIME_REG === 0.U){
        TIMEH_REG := TIMEH_REG + 1.U
    }
    /***************************************************/

    /****************** instret counter ******************/
    when(io.MINSTRET.i_instr_retired && !MCOUNTINHIBIT_IR_REG){
        MINSTRET_REG := MINSTRET_REG + 1.U
    }
    when(io.MINSTRET.i_instr_retired && MINSTRET_REG === 0.U && !MCOUNTINHIBIT_IR_REG){
        MINSTRETH_REG := MINSTRETH_REG + 1.U
    }
    /***************************************************/

    /****************** Read Logic ******************/
    var READ,WRITE,SET,CLEAR = Wire(UInt(2.W))
    Seq(READ,WRITE,SET,CLEAR) zip Seq(csr_opr.READ, csr_opr.WRITE, csr_opr.SET, csr_opr.CLEAR) map (x => x._1 := x._2)

    val READ_CASES = Array(
        AddressMap.MISA    -> MISA_REG,
        AddressMap.MHARTID -> MHARTID_REG,
        AddressMap.MARCHID -> MARCHID_REG,
        AddressMap.MSTATUS -> MSTATUS_WIRE,
        AddressMap.MCAUSE  -> MCAUSE_REG,
        AddressMap.MTVEC   -> MTVEC_REG,
        AddressMap.MEPC    -> MEPC_REG,
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
        AddressMap.TIME    -> TIME_REG,
        AddressMap.TIMEH   -> TIMEH_REG
    )

    r_data := MuxLookup(io.CSR.i_addr, DontCare, READ_CASES)

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
            is(AddressMap.MSTATUS){
                MSTATUS_TSR_REG  := w_data(22)
                MSTATUS_TW_REG   := w_data(21)
                MSTATUS_TVM_REG  := w_data(20)
                MSTATUS_MXR_REG  := w_data(19)
                MSTATUS_SUM_REG  := w_data(18)
                MSTATUS_MPRV_REG := w_data(17)
                MSTATUS_MPP_REG  := w_data(12,11)
                MSTATUS_SPP_REG  := w_data(8)
                MSTATUS_MPIE_REG := w_data(7)
                MSTATUS_UBE_REG  := w_data(6)
                MSTATUS_SPIE_REG := w_data(5)
                MSTATUS_MIE_REG  := w_data(3)
                MSTATUS_SIE_REG  := w_data(1)
            }
            is(AddressMap.MCAUSE){
                MCAUSE_REG       := w_data
            }
            is(AddressMap.MTVEC){
                MTVEC_REG        := w_data
            }
            is(AddressMap.MEPC){
                MEPC_REG         := w_data
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
            }
            is(AddressMap.MIP){
                MIP_MEIP_REG     := w_data(11)
                MIP_MTIP_REG     := w_data(7)
                MIP_MSIP_REG     := w_data(3)
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
}
