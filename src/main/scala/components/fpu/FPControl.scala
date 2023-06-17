package nucleusrv.components.fpu

import chisel3._, chisel3.util._


class FPControlIO extends Bundle with Parameters {
  val opcode = Input(UInt(fOpcodeWidth.W))
  val fmt    = Input(UInt(fFmtWidth.W))
  val funct5 = Input(UInt(f5Width.W))
  val rm     = Input(UInt(rmWidth.W))
  val rs2    = Input(UInt(regAddrWidth.W))

  val aluCtl = Output(UInt(5.W))
  val fWrite = Output(Bool())
  val iWrite = Output(Bool())
  val fRead  = Output(Bool())
  val fLoad  = Output(Bool())
  val fStore = Output(Bool())
}


class FPControl extends RawModule with Parameters {
  val io = IO(new FPControlIO)

  val fAluCtl = Cat(io.funct5, io.fmt, io.opcode)

  val aluCtl = MuxCase(0.U, Seq(
    ((fAluCtl === "b11010001010011".U) && !io.rs2.orR)                       -> 10.U,  // fcvt.s.w
    ((fAluCtl === "b11010001010011".U) && io.rs2.orR)                        -> 11.U,  // fcvt.s.wu
    ((fAluCtl === "b11000001010011".U) && io.rs2.orR)                        -> 12.U,  // fcvt.wu.s
    ((fAluCtl === "b11000001010011".U) && !io.rs2.orR)                       -> 13.U,  // fcvt.w.s
    (fAluCtl === "b00000001010011".U)                                        -> 14.U,  // fadd.s
    (fAluCtl === "b00011001010011".U)                                        -> 15.U,  // fdiv.s
    (fAluCtl((fFmtWidth + fOpcodeWidth) - 1, 0) === "b001000011".U)          -> 16.U,  // fmadd.s
    (fAluCtl((fFmtWidth + fOpcodeWidth) - 1, 0) === "b001001111".U)          -> 17.U,  // fnmadd.s
    (fAluCtl === "b10100001010011".U)                                        -> 18.U,  // flt.s
    (fAluCtl === "b10100001010011".U)                                        -> 19.U,  // fle.s
    (Cat(io.rm, fAluCtl) === "b00000101001010011".U)                         -> 20.U,  // fmin.s
    (fAluCtl === "b00001001010011".U)                                        -> 21.U,  // fsub.s
    (fAluCtl === "b00010001010011".U)                                        -> 22.U,  // fmul.s
    (Cat(io.rm, fAluCtl) === "b00100101001010011".U)                         -> 23.U,  // fmax.s
    ((fAluCtl === "b01011001010011".U) && !io.rs2.orR)                       -> 24.U,  // fsqrt.s
    (fAluCtl((fFmtWidth + fOpcodeWidth) - 1, 0) === "b001000111".U)          -> 25.U,  // fmsub.s
    (fAluCtl((fFmtWidth + fOpcodeWidth) - 1, 0) === "b001001011".U)          -> 26.U,  // fnmsub.s
    (Cat(io.rm, fAluCtl) === "b01010100001010011".U)                         -> 27.U,  // feq.s
    (Cat(io.rm, fAluCtl) === "b00000100001010011".U)                         -> 28.U,  // fsgnj.s
    (Cat(io.rm, fAluCtl) === "b00100100001010011".U)                         -> 29.U,  // fsgnjn.s
    (Cat(io.rm, fAluCtl) === "b01000100001010011".U)                         -> 30.U,  // fsgnjx.s
    ((fAluCtl === "b11110001010011".U) || (fAluCtl === "b11100001010011".U)) -> 31.U   // fmv.x.w or fmv.w.x
  ))

  val fRead = VecInit(Seq(
    "0100111",
    "1000011",
    "1000111",
    "1001011",
    "1001111"
  ).map(
    f => io.opcode === ("b" + f).U
  ) ++ Seq(
    (io.opcode === "b1010011".U) && !Seq(
      "1101000",
      "1111000"
    ).map(
      f => Cat(io.funct5, io.fmt) === ("b" + f).U
    ).reduce(_ || _)
  ))

  io.aluCtl := aluCtl

  io.fWrite := (io.opcode === "b0000111".U) || (Seq(
    10, 11,
  ) ++ (14 to 17).toSeq ++ (20 to 26).toSeq ++ (28 to 30)).map(
    f => aluCtl === f.U
  ).reduce(_ || _) || ((fAluCtl === "b11110001010011".U) && !(Cat(io.rm.orR, io.rs2).orR))

  io.iWrite := Seq(12, 13, 18, 19, 27).map(
    f => aluCtl === f.U
  ).reduce(_ || _) || ((fAluCtl === "b11100001010011".U) && !(Cat(io.rs2, io.rm).orR))

  io.fRead := fRead.asUInt.orR

  io.fLoad  := io.opcode === "b0000111".U
  io.fStore := io.opcode === "b0100111".U
}
