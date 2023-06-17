
package nucleusrv.components
import chisel3._

class ForwardingUnit(F :Boolean) extends Module {
  val io = IO(new Bundle {
    val ex_reg_rd = Input(UInt(5.W))
    val mem_reg_rd = Input(UInt(5.W))
    val reg_rs1 = Input(UInt(5.W))
    val reg_rs2 = Input(UInt(5.W))
    val ex_regWrite = Input(Bool())
    val mem_regWrite = Input(Bool())

    val forwardA = Output(UInt(2.W))
    val forwardB = Output(UInt(2.W))

    // F
    val rs3      = if (F) Some(Input(UInt(5.W))) else None
    val fRead    = if (F) Some(Input(Bool())) else None
    val fWrite   = if (F) Some(Input(Vec(2, Bool()))) else None
    val forwardC = if (F) Some(Output(UInt(2.W))) else None
 })

  io.forwardA := DontCare
  io.forwardB := DontCare
  if (F) io.forwardC.get := DontCare

  val fRead  = if (F) io.fRead.get else WireInit(0.B)
  val fWrite = if (F) io.fWrite.get else VecInit(0.B, 0.B)

  when(
    (((io.reg_rs1 === io.ex_reg_rd) && (!fRead === !fWrite(0))) && (
    ((io.ex_reg_rd =/= 0.U) && !fWrite(0)) && io.ex_regWrite)) || (
      if (F) (
        ((io.reg_rs1 === io.ex_reg_rd) && (fRead === fWrite(0))) && fWrite(0)
      ) else 0.B
    )) {
    io.forwardA := 1.U
  }.elsewhen(
      (((io.reg_rs1 === io.mem_reg_rd) && (!fRead(0) === !fWrite(1))) && (
      (io.mem_reg_rd =/= 0.U) && !fWrite(1)) && io.mem_regWrite) || (
        if (F) (
          ((io.reg_rs1 === io.mem_reg_rd) && (fRead === fWrite(1))) && fWrite(1)
        ) else 0.B
      )
    ) {
      io.forwardA := 2.U
    }
    .otherwise {
      io.forwardA := 0.U
    }

  when(
    (((io.reg_rs2 === io.ex_reg_rd) && (!fRead === !fWrite(0))) && (
    ((io.ex_reg_rd =/= 0.U) && !fWrite(0)) && io.ex_regWrite)) || (
      if (F) (
        ((io.reg_rs2 === io.ex_reg_rd) && (fRead === fWrite(0))) && fWrite(0)
      ) else 0.B
    )
  ) {
    io.forwardB := 1.U
  }.elsewhen(
      (((io.reg_rs2 === io.mem_reg_rd) && (!fRead === !fWrite(1))) && (
      ((io.mem_reg_rd =/= 0.U) && (!fWrite(1))) && io.mem_regWrite) || (
        if (F) (
          ((io.reg_rs2 === io.mem_reg_rd) && (fRead === fWrite(1))) && fWrite(1)
        ) else 0.B
      ))
    ) {
      io.forwardB := 2.U
    }
    .otherwise {
      io.forwardB := 0.U
    }

  if (F) {
    when (
      ((io.rs3.get === io.ex_reg_rd) && (fRead === fWrite(0))) && fWrite(0)
    ) {
      io.forwardC.get := 1.U
    }.elsewhen (
      ((io.rs3.get === io.mem_reg_rd) && (fRead === fWrite(1))) && fWrite(1)
    ) {
      io.forwardC.get := 2.U
    } otherwise {
      io.forwardC.get := 0.U
    }
  }
}
