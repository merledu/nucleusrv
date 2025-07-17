package nucleusrv.components

import chisel3._

class ForwardingUnit(F: Boolean) extends Module {
  val io = IO(new Bundle {
    val ex_reg_rd = Input(UInt(5.W))
    val mem_reg_rd = Input(UInt(5.W))
    val reg_rs1 = Input(UInt(5.W))
    val reg_rs2 = Input(UInt(5.W))
    val ex_regWrite = Input(Vec(if (F) 2 else 1, Bool()))
    val mem_regWrite = Input(Vec(if (F) 2 else 1, Bool()))

    val forwardA = Output(UInt(2.W))
    val forwardB = Output(UInt(2.W))

    // F
    val f_read = if (F) Some(Input(Vec(3, Bool()))) else None
    val reg_rs3 = if (F) Some(Input(UInt(5.W))) else None
    val forwardC = if (F) Some(Output(UInt(2.W))) else None
  })

  io.forwardA := DontCare
  io.forwardB := DontCare
  
  when (
    (io.reg_rs1 === io.ex_reg_rd)
    && Mux(io.ex_regWrite(0), io.ex_reg_rd =/= 0.U, 1.B)
    && (
      if (F) (!io.f_read.get(0) && io.ex_regWrite(0)) || (io.f_read.get(0) && io.ex_regWrite(1))
      else io.ex_regWrite(0)
    )
  ) {
    io.forwardA := 1.U
  }.elsewhen (
    (io.reg_rs1 === io.mem_reg_rd)
    && Mux(io.mem_regWrite(0), io.mem_reg_rd =/= 0.U, 1.B)
    && (
      if (F) (!io.f_read.get(0) && io.mem_regWrite(0)) || (io.f_read.get(0) && io.mem_regWrite(1))
      else io.mem_regWrite(0)
    )
  ) {
    io.forwardA := 2.U
  }.otherwise {
    io.forwardA := 0.U
  }

  when (
    (io.reg_rs2 === io.ex_reg_rd)
    && Mux(io.ex_regWrite(0), io.ex_reg_rd =/= 0.U, 1.B)
    && (
      if (F) (!io.f_read.get(1) && io.ex_regWrite(0)) || (io.f_read.get(1) && io.ex_regWrite(1))
      else io.ex_regWrite(0)
    )
  ) {
    io.forwardB := 1.U
  }.elsewhen (
    (io.reg_rs2 === io.mem_reg_rd)
    && Mux(io.mem_regWrite(0), io.mem_reg_rd =/= 0.U, 1.B)
    && (
      if (F) (!io.f_read.get(1) && io.mem_regWrite(0)) || (io.f_read.get(1) && io.mem_regWrite(1))
      else io.mem_regWrite(0)
    )
  ) {
    io.forwardB := 2.U
  }.otherwise {
    io.forwardB := 0.U
  }

  if (F) {
    when (
      (io.reg_rs3.get === io.ex_reg_rd)
      && (io.f_read.get(2) && io.ex_regWrite(1))
    ) {
      io.forwardC.get := 1.U
    }.elsewhen (
      (io.reg_rs3.get === io.mem_reg_rd)
      && (io.f_read.get(2) && io.mem_regWrite(1))
    ) {
      io.forwardC.get := 2.U
    }.otherwise {
      io.forwardC.get := 0.U
    }
  }
}
