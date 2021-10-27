
package nucleusrv.components
import chisel3._

class ForwardingUnit extends Module {
  val io = IO(new Bundle {
    val ex_reg_rd = Input(UInt(5.W))
    val mem_reg_rd = Input(UInt(5.W))
    val reg_rs1 = Input(UInt(5.W))
    val reg_rs2 = Input(UInt(5.W))
    val ex_regWrite = Input(Bool())
    val mem_regWrite = Input(Bool())

    val forwardA = Output(UInt(2.W))
    val forwardB = Output(UInt(2.W))
  })

  io.forwardA := DontCare
  io.forwardB := DontCare
  
  when(io.reg_rs1 === io.ex_reg_rd && io.ex_reg_rd =/= 0.U && io.ex_regWrite) {
    io.forwardA := 1.U
  }.elsewhen(
      io.reg_rs1 === io.mem_reg_rd && io.mem_reg_rd =/= 0.U && io.mem_regWrite
    ) {
      io.forwardA := 2.U
    }
    .otherwise {
      io.forwardA := 0.U
    }

  when(io.reg_rs2 === io.ex_reg_rd && io.ex_reg_rd =/= 0.U && io.ex_regWrite) {
    io.forwardB := 1.U
  }.elsewhen(
      io.reg_rs2 === io.mem_reg_rd && io.mem_reg_rd =/= 0.U && io.mem_regWrite
    ) {
      io.forwardB := 2.U
    }
    .otherwise {
      io.forwardB := 0.U
    }
}
