package nucleusrv.components.vu

import chisel3._
import chisel3.util._
import chisel3.experimental._
import chisel3.stage.ChiselStage


class vregfile extends Module {
  val io = IO (new Bundle {
    val ins = Input(UInt(32.W))
    val vs1_addr = Input(UInt(5.W))
    val vs2_addr = Input(UInt(5.W))
    val vs3_addr = Input(UInt(5.W))
    val vd_addr = Input(UInt(5.W))
    val lmul_count = Input(UInt(4.W))
    val lmul_vs1in_vs2in = Input(UInt(4.W))
    val id_vc3 = Input(UInt(5.W))

    val vs0_data = Output (SInt(128.W))
    val vs1_data = Output(SInt(128.W))
    val vs2_data = Output(SInt(128.W))
    val vs3_data = Output(SInt(128.W))
    val vd_data = Input(SInt(128.W))
    val reg_write = Input(Bool())
    val reg_read = Input(Bool())
    
  })

  val register = RegInit(VecInit(Seq.fill(32)(0.S(128.W))))
  var vs1_in = io.vs1_addr+io.lmul_vs1in_vs2in
  var vs2_in = io.vs2_addr+io.lmul_vs1in_vs2in
  var vs3_in = io.vs3_addr + io.lmul_vs1in_vs2in
  var vsd_in = io.vd_addr+io.lmul_count
  dontTouch(vs1_in)
  dontTouch(vs2_in)
  dontTouch(vs3_in)
  dontTouch(vsd_in)

io.vs1_data := register(vs1_in)
io.vs2_data := register(vs2_in)
io.vs0_data := register(0.U)
io.vs3_data := register(vs3_in)

  when (io.reg_write === 1.B && io.reg_read === 0.B) {
      register(vsd_in) := io.vd_data
      io.vs1_data := 0.S
      io.vs2_data := 0.S
      io.vs0_data := 0.S
      io.vs3_data := 0.S
  }.elsewhen(io.reg_write === 0.B && io.reg_read === 1.B){
    io.vs1_data := register(vs1_in)
    io.vs2_data := register(vs2_in)
    io.vs0_data := register(0.U)
    io.vs3_data := register(vs3_in)
  }.elsewhen(io.reg_write === 1.B && io.reg_read === 1.B){
    register(vsd_in) := io.vd_data
    io.vs1_data := register(vs1_in)
    io.vs2_data := register(vs2_in)
    io.vs0_data := register(0.U)
    io.vs3_data := register(vs3_in)
  }.otherwise{
    io.vs1_data := 0.S
    io.vs2_data := 0.S
    io.vs0_data := 0.S
    io.vs3_data := 0.S

  }
val vs3_in_1 = RegInit(0.U(5.W))
when (io.ins(6,0)==="b0100111".U){
   vs3_in_1 := io.vs3_addr + io.id_vc3
  io.vs3_data := register(vs3_in_1)
}

}