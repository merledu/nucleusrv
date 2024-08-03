package nucleusrv.components

import chisel3._
import chisel3.util._
import nucleusrv.csr._

class CSR extends Module{
    val io = IO(new Bundle{
        val i_misa_value        = Input(UInt(32.W))
        val i_mhartid_value     = Input(UInt(32.W))
        val i_data              = Input(UInt(32.W))
        val i_imm               = Input(UInt(5.W))
        val o_data              = Output(UInt(32.W))
        val i_opr               = Input(UInt(3.W))
        val i_addr              = Input(UInt(12.W))
        val i_w_en              = Input(Bool())
        val fcsr_o_data         = Output(UInt(32.W))
    })

    val csrRegFile = Module(new CSRRegFile)
    dontTouch(csrRegFile.io)

    csrRegFile.io.CSR.i_data        := Mux(io.i_opr(2), io.i_imm, io.i_data)
    csrRegFile.io.CSR.i_opr         := io.i_opr
    csrRegFile.io.MISA.i_value      := io.i_misa_value
    csrRegFile.io.MHARTID.i_value   := io.i_mhartid_value
    csrRegFile.io.CSR.i_addr        := io.i_addr
    csrRegFile.io.CSR.i_w_en        := io.i_w_en

    io.o_data                       := csrRegFile.io.CSR.o_data
    io.fcsr_o_data                  := Cat("b0".U(24.W),csrRegFile.io.FCSR.frm,csrRegFile.io.FCSR.nv,csrRegFile.io.FCSR.dz,csrRegFile.io.FCSR.of,csrRegFile.io.FCSR.uf,csrRegFile.io.FCSR.nx)
}
