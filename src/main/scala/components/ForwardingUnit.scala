
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

    val reg_rs3 = if (F) Some(Input(UInt(5.W))) else None
    val fInst = if (F) Some(Input(Vec(3, Bool()))) else None
    val forwardC = if (F) Some(Output(UInt(2.W))) else None
 })

  io.forwardA := DontCare
  io.forwardB := DontCare
  io.forwardC.get := DontCare

  val fInst = if (F) io.fInst.get else WireInit(Vec(3, 1.B))

  when(
    ((io.reg_rs1 === io.ex_reg_rd) && (!fInst(0) === !fInst(1))) && (
    ((io.ex_reg_rd =/= 0.U) && !fInst(1)) && (io.ex_regWrite && !fInst(1))) && (
      if (F) (
        ((io.reg_rs1 === io.ex_reg_rd) && (fInst(0) === fInst(2))) && (io.ex_regWrite && fInst(1))
      ) else 1.B
    )) {
    io.forwardA := 1.U
  }.elsewhen(
      ((io.reg_rs1 === io.mem_reg_rd) && (!fInst(0) === !fInst(2))) && (
        (io.mem_reg_rd =/= 0.U) && !fInst(2)) && (io.mem_regWrite && !fInst(2)) && (
          if (F) (
            ((io.reg_rs1 === io.mem_reg_rd) && (fInst(0) === fInst(2))) && (
              (io.mem_regWrite && fInst(2))
            )
          ) else 1.B
        )
    ) {
      io.forwardA := 2.U
    }
    .otherwise {
      io.forwardA := 0.U
    }

  when(
    ((io.reg_rs2 === io.ex_reg_rd) && (!fInst(0) === !fInst(1))) && (
    ((io.ex_reg_rd =/= 0.U) && !fInst(1)) && (io.ex_regWrite && !fInst(1))) && (
      if (F) (
        ((io.reg_rs1 === io.ex_reg_rd) && (fInst(0) === fInst(2))) && (io.ex_regWrite && fInst(1))
      ) else 1.B
    )
  ) {
    io.forwardB := 1.U
  }.elsewhen(
      ((io.reg_rs2 === io.mem_reg_rd) && (!fInst(0) === !fInst(2))) && (
      ((io.mem_reg_rd =/= 0.U) && (!fInst(2))) && (io.mem_regWrite && !fInst(2)) && (
        if (F) (
          ((io.reg_rs2 === io.mem_reg_rd) && (fInst(0) === fInst(2))) && (io.mem_regWrite && fInst(2))
        ) else 1.B
      ))
    ) {
      io.forwardB := 2.U
    }
    .otherwise {
      io.forwardB := 0.U
    }

  if (F) {
    when (
      ((io.reg_rs3.get === io.ex_reg_rd) && (fInst(0) === fInst(1))) && (io.ex_regWrite && fInst(1))
    ) {
      io.forwardC.get := 1.U
    }.elsewhen (
      ((io.reg_rs3.get === io.mem_reg_rd) && (fInst(0) === fInst(2))) && (io.mem_regWrite && fInst(2))
    ) {
      io.forwardC.get := 2.U
    } otherwise {
      io.forwardC.get := 0.U
    }
  }
}
