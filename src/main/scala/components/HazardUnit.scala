
package nucleusrv.components
import chisel3._

class HazardUnit extends Module {
  val io = IO(new Bundle {
    val id_ex_memRead = Input(Bool())
    val ex_mem_memRead = Input(Bool())
    val id_ex_branch = Input(Bool())
    val id_ex_rd = Input(UInt(5.W))
    val ex_mem_rd = Input(UInt(5.W))
    val id_rs1 = Input(UInt(5.W))
    val id_rs2 = Input(UInt(5.W))
    val dmem_resp_valid = Input(Bool())
    val taken = Input(Bool())
    val jump = Input(UInt(2.W))
    val branch = Input(Bool())

    val if_reg_write = Output(Bool())
    val pc_write = Output(Bool())
    val ctl_mux = Output(Bool())
    val ifid_flush = Output(Bool())
    val take_branch = Output(Bool())
  })

  io.ctl_mux := true.B
  io.pc_write := true.B
  io.if_reg_write := true.B
  io.take_branch := true.B
  io.ifid_flush := false.B

//  load-use hazard
  when(
    (io.id_ex_memRead || io.branch) &&
      (io.id_ex_rd === io.id_rs1 || io.id_ex_rd === io.id_rs2 ) &&
      ((io.id_ex_rd =/= 0.U && io.id_rs1 =/= 0.U) ||
      (io.id_ex_rd =/= 0.U && io.id_rs2 =/= 0.U)) &&
      !io.id_ex_branch
  )
  {
    io.ctl_mux := false.B
    io.pc_write := false.B
    io.if_reg_write := false.B
    io.take_branch := false.B
  }

  when(io.ex_mem_memRead && io.branch && (io.ex_mem_rd === io.id_rs1 || io.ex_mem_rd === io.id_rs2)){
    io.ctl_mux := false.B
    io.pc_write := false.B
    io.if_reg_write := false.B
    io.take_branch := false.B
  }

  //branch hazard
  when(io.taken || io.jump =/= 0.U) {
    io.ifid_flush := true.B
  }.otherwise {
    io.ifid_flush := false.B
  }

}
