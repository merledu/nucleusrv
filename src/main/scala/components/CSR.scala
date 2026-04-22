// Created by @Talha-Ahmed-1

package nucleusrv.components

import chisel3._
import chisel3.util._
import nucleusrv.csr._

class CSR(F: Boolean) extends Module{
    val io = IO(new Bundle{
        val i_misa_value        = Input(UInt(32.W))
        val i_mhartid_value     = Input(UInt(32.W))
        val i_marchid_value     = Input(UInt(32.W))
        val i_data              = Input(UInt(32.W))
        val i_imm               = Input(UInt(5.W))
        val o_data              = Output(UInt(32.W))
        val i_opr               = Input(UInt(3.W))
        val i_addr              = Input(UInt(12.W))
        val i_w_en              = Input(Bool())
        val i_instr_retired     = Input(Bool())
        val f_except            = if (F) Some(Input(Vec(5, Bool()))) else None
        val fcsr_o_data         = if (F) Some(Output(UInt(32.W))) else None
    })

    val csrRegFile = Module(new CSRRegFile(F))
    dontTouch(csrRegFile.io)

    csrRegFile.io.CSR.i_data               := Mux(io.i_opr(2), io.i_imm, io.i_data)
    csrRegFile.io.CSR.i_opr                := io.i_opr
    csrRegFile.io.MISA.i_value             := io.i_misa_value
    csrRegFile.io.MHARTID.i_value          := io.i_mhartid_value
    csrRegFile.io.MARCHID.i_value          := io.i_marchid_value
    csrRegFile.io.CSR.i_addr               := io.i_addr
    csrRegFile.io.CSR.i_w_en               := io.i_w_en
    csrRegFile.io.MINSTRET.i_instr_retired := io.i_instr_retired
    if (F) {
      csrRegFile.io.FCSR.get.except              <> io.f_except.get
      io.fcsr_o_data.get              := Cat(
                                          "b0".U(24.W),
                                          csrRegFile.io.FCSR.get.frm,
                                          csrRegFile.io.FCSR.get.nv,
                                          csrRegFile.io.FCSR.get.dz,
                                          csrRegFile.io.FCSR.get.of,
                                          csrRegFile.io.FCSR.get.uf,
                                          csrRegFile.io.FCSR.get.nx
                                       )
    }

    io.o_data                       := csrRegFile.io.CSR.o_data
    
}
