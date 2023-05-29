package nucleusrv.components.fpu

import chisel3._, chisel3.util._


class FControlIO extends Bundle with Parameters {
  val fAluCtl = Input(UInt((f5Width + fFmtWidth + fOpcodeWidth).W))
  val rm      = Input(UInt(rmWidth.W))
  val rs2     = Input(UInt(regAddrWidth.W))

  val aluCtl = Output(UInt(5.W))
}


class FControl extends RawModule with Parameters {
  val io = IO(new FControlIO)

  io.aluCtl := MuxCase(0.U, Seq(
    ((io.fAluCtl === "b11010001010011".U) && !io.rs2.orR)                          -> 10.U,  // fcvt.s.w
    ((io.fAluCtl === "b11010001010011".U) && io.rs2.orR)                           -> 11.U,  // fcvt.s.wu
    ((io.fAluCtl === "b11000001010011".U) && io.rs2.orR)                           -> 12.U,  // fcvt.wu.s
    ((io.fAluCtl === "b11000001010011".U) && !io.rs2.orR)                          -> 13.U,  // fcvt.w.s
    (io.fAluCtl === "b00000001010011".U)                                           -> 14.U,  // fadd.s
    (io.fAluCtl === "b00011001010011".U)                                           -> 15.U,  // fdiv.s
    (io.fAluCtl((fFmtWidth + fOpcodeWidth) - 1, 0) === "b001000011".U)             -> 16.U,  // fmadd.s
    (io.fAluCtl((fFmtWidth + fOpcodeWidth) - 1, 0) === "b001001111".U)             -> 17.U,  // fnmadd.s
    (io.fAluCtl === "b10100001010011".U)                                           -> 18.U,  // flt.s
    (io.fAluCtl === "b10100001010011".U)                                           -> 19.U,  // fle.s
    (Cat(io.rm, io.fAluCtl) === "b00000101001010011".U)                            -> 20.U,  // fmin.s
    (io.fAluCtl === "b00001001010011".U)                                           -> 21.U,  // fsub.s
    (io.fAluCtl === "b00010001010011".U)                                           -> 22.U,  // fmul.s
    (Cat(io.rm, io.fAluCtl) === "b00100101001010011".U)                            -> 23.U,  // fmax.s
    ((io.fAluCtl === "b01011001010011".U) && !io.rs2.orR)                          -> 24.U,  // fsqrt.s
    (io.fAluCtl((fFmtWidth + fOpcodeWidth) - 1, 0) === "b001000111".U)             -> 25.U,  // fmsub.s
    (io.fAluCtl((fFmtWidth + fOpcodeWidth) - 1, 0) === "b001001011".U)             -> 26.U,  // fnmsub.s
    (Cat(io.rm, io.fAluCtl) === "b01010100001010011".U)                            -> 27.U,  // feq.s
    (Cat(io.rm, io.fAluCtl) === "b00000100001010011".U)                            -> 28.U,  // fsgnj.s
    (Cat(io.rm, io.fAluCtl) === "b00100100001010011".U)                            -> 29.U,  // fsgnjn.s
    (Cat(io.rm, io.fAluCtl) === "b01000100001010011".U)                            -> 30.U,  // fsgnjx.s
    ((io.fAluCtl === "b11110001010011".U) || (io.fAluCtl === "b11100001010011".U)) -> 31.U  // fmv.x.w or fmv.w.x
  ))
}
