package nucleusrv.components.vu

import chisel3._
import chisel3.util._
import chisel3.experimental._
import chisel3.stage.ChiselStage


class vregfile extends Module {
  val io = IO (new Bundle {
    val ins = Input(UInt(32.W))
    val wb_ins = Input(UInt(32.W))
    val vs1_addr = Input(UInt(5.W))
    val vs2_addr = Input(UInt(5.W))
    val vs3_addr = Input(UInt(5.W))
    val vd_addr = Input(UInt(5.W))
    val lmul_count = Input(UInt(4.W))
    val lmul_vs1in_vs2in = Input(UInt(4.W))
    val id_vc3 = Input(UInt(5.W))
    val wb__emul = Input(UInt(5.W))

    val vs0_data = Output (SInt(128.W))
    val vs1_data = Output(SInt(128.W))
    val vs2_data = Output(SInt(128.W))
    val vs3_data = Output(SInt(128.W))
    val vd_data = Input(SInt(128.W))
    val reg_write = Input(Bool())
    val reg_read = Input(Bool())
    
  })
  val register = RegInit(VecInit(Seq.fill(32)(0.S(128.W))))
  // val id_emul_count = RegInit(0.U(32.W))
  // when(id_emul_count=/= io.emul-1.U && (io.ins(6,0)==="b0000111".U || io.ins(6,0)==="b0100111".U)){
  //   id_emul_count := id_emul_count +1.U
  // }.otherwise{
  //   id_emul_count := 0.U
  // }

  val vs1_in = Mux((io.ins(6,0)==="b1010111".U) && (io.ins(14,12)=/="b111".U),io.vs1_addr+io.lmul_vs1in_vs2in,Mux((io.ins(6,0)==="b0100111".U),io.vs1_addr+io.id_vc3,0.U))
  val vs2_in = Mux((io.ins(6,0)==="b1010111".U) && (io.ins(14,12)=/="b111".U),io.vs2_addr+io.lmul_vs1in_vs2in,Mux((io.ins(6,0)==="b0100111".U),io.vs1_addr+io.id_vc3,0.U))
  val vs3_in = Mux((io.ins(6,0)==="b1010111".U) && (io.ins(14,12)=/="b111".U),io.vs3_addr+io.lmul_vs1in_vs2in,Mux((io.ins(6,0)==="b0100111".U),io.vs1_addr+io.id_vc3,0.U))
  val vsd_in = Mux((io.wb_ins(6,0)==="b1010111".U) && (io.wb_ins(14,12)=/="b111".U),io.vd_addr+io.lmul_count,Mux(io.wb_ins(6,0)==="b0000111".U,io.vd_addr+io.wb__emul,0.U))

  // var vs1_in = io.vs1_addr+io.lmul_vs1in_vs2in
  // var vs2_in = io.vs2_addr+io.lmul_vs1in_vs2in
  // var vs3_in = io.vs3_addr + io.lmul_vs1in_vs2in
  // var vsd_in = io.vd_addr+io.lmul_count
  dontTouch(vs1_in)
  dontTouch(vs2_in)
  dontTouch(vs3_in)
  dontTouch(vsd_in)

io.vs1_data := register(vs1_in)
io.vs2_data := register(vs2_in)
io.vs0_data := register(0.U)
io.vs3_data := register(vs3_in)
register(0) := ("b0101011110001101011100101011111000110".U).asSInt

  when (io.reg_write === 1.B && io.reg_read === 0.B) {
      register(vsd_in) := io.vd_data
      io.vs1_data := 0.S
      io.vs2_data := 0.S
      io.vs0_data := register(0)
      io.vs3_data := 0.S
  }.elsewhen(io.reg_write === 0.B && io.reg_read === 1.B){
    io.vs1_data := register(vs1_in)
    io.vs2_data := register(vs2_in)
    io.vs0_data := register(0)
    io.vs3_data := register(vs3_in)
  }.elsewhen(io.reg_write === 1.B && io.reg_read === 1.B){
    register(vsd_in) := io.vd_data
    io.vs1_data := register(vs1_in)
    io.vs2_data := register(vs2_in)
    io.vs0_data := register(0)
    io.vs3_data := register(vs3_in)
  }.otherwise{
    io.vs1_data := 0.S
    io.vs2_data := 0.S
    io.vs0_data := register(0)
    io.vs3_data := 0.S

  }
  // when(io.wb__emul===  lmul_count){

  // }

when (io.ins(6,0)==="b0100111".U){
   val vs3_in_1 = io.vs3_addr + io.id_vc3
  io.vs3_data := register(vs3_in_1)
}

}