package components
import chisel3._

class HazardUnit extends Module {
  val io = IO(new Bundle {
    val memRead = Input(Bool())
    val rd = Input(UInt(5.W))
    val rs1 = Input(UInt(5.W))
    val rs2 = Input(UInt(5.W))
    val taken = Input(Bool())
    val jump = Input(UInt(2.W))

    val if_reg_write = Output(Bool())
    val pc_write = Output(Bool())
    val ctl_mux = Output(Bool())
    val ifid_flush = Output(Bool())

  })

  //load-use hazard
  when(io.memRead && (io.rd === io.rs1 || io.rd === io.rs2)) {
    io.ctl_mux := false.B
    io.pc_write := false.B
    io.if_reg_write := false.B
  }.otherwise {
    io.ctl_mux := true.B
    io.pc_write := true.B
    io.if_reg_write := true.B
  }

  //branch hazard
  when(io.taken || io.jump =/= 0.U) {
    io.ifid_flush := true.B
  }.otherwise {
    io.ifid_flush := false.B
  }

}
