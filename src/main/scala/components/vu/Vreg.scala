package nucleusrv.components.vu

import chisel3._
import chisel3.util._
import chisel3.experimental._
import chisel3.stage.ChiselStage


class vregfile extends Module {
  val io = IO (new Bundle {
    val vs1_addr = Input(UInt(5.W))
    val vs2_addr = Input(UInt(5.W))
    val vd_addr = Input(UInt(5.W))
    val vs0_data = Output (SInt(128.W))
    val vs1_data = Output(SInt(128.W))
    val vs2_data = Output(SInt(128.W))
    val vddata_o = Output(SInt(128.W))
    val vd_data = Input(SInt(128.W))
    val reg_write = Input(Bool())
  })

  val register = RegInit(VecInit(Seq.fill(32)(0.S(128.W))))

io.vs1_data := register(io.vs1_addr)
io.vs2_data := register(io.vs2_addr)
io.vs0_data := register(0.U)
io.vddata_o := register(io.vd_addr)

  when (io.reg_write) {
      register(io.vd_addr) := io.vd_data
  }
}
