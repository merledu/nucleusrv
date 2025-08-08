package nucleusrv.components

import chisel3._
import chisel3.util._
import hardfloat._

import FCONSTS._

object FSignInject {
  def apply(
    rs1: UInt,
    rs2: UInt,
    op: UInt
  ) = MuxLookup(op, 0.U, Vector(
    rs2(31),
    !rs2(31),
    rs1(31) ^ rs2(31)
  ).zipWithIndex map (
    f => (f._2 + 10).U -> (f._1 ## rs1(30, 0))
  ))
}

class FPUIO extends Bundle {
  val in = Input(Vec(3, UInt(32.W)))
  val aluOp = Input(UInt(5.W))
  val rm = Input(UInt(3.W))
  val div_sqrt_valid = Input(Bool())

  val out = Output(UInt(32.W))
  val exceptions = Output(Vec(5, Bool()))
  val div_sqrt_ready = Output(Bool())
  val div_sqrt_valid_out = Output(Bool())
}

class FPU(
  exp_width: Int,
  sig_width: Int
) extends Module {
  val io = IO(new FPUIO)

  val madd = Module(new MulAddRecFN(exp_width, sig_width)).io
  val add = Module(new AddRecFN(exp_width, sig_width)).io
  val mul = Module(new MulRecFN(exp_width, sig_width)).io
  val div = Module(new DivSqrtRecFN_small(exp_width, sig_width, 0)).io
  val cmp = Module(new CompareRecFN(exp_width, sig_width)).io
  val f_to_i = Module(new RecFNToIN(exp_width, sig_width, 32)).io
  val i_to_f = Module(new INToRecFN(32, 8, 24)).io
  val raw_in = VecInit((0 until 2).map(
    f => rawFloatFromFN(exp_width, sig_width, io.in(f))
  ))
  val op_out = VecInit(
    madd.out,
    add.out,
    mul.out,
    div.out,
    i_to_f.out
  ).map(
    fNFromRecFN(exp_width, sig_width, _)
  )

  madd.c := recFNFromFN(exp_width, sig_width, io.in(2))
  madd.op := MuxLookup(io.aluOp, 0.U, (2 to 4) map (
    f => f.U -> (f - 1).U
  ))
  add.subOp := io.aluOp === 6.U
  div.inValid := io.div_sqrt_valid
  div.sqrtOp := io.aluOp === 9.U
  cmp.signaling := (19 to 20).map(io.aluOp === _.U) reduce (_ || _)
  f_to_i.in := recFNFromFN(exp_width, sig_width, io.in(0))
  f_to_i.signedOut := io.aluOp === 15.U
  i_to_f.signedIn := io.aluOp === 22.U
  i_to_f.in := io.in(0)
  io.div_sqrt_valid_out := div.outValid_div || div.outValid_sqrt

  Vector(
    Vector(madd.a, madd.b),
    Vector(add.a, add.b),
    Vector(mul.a, mul.b),
    Vector(div.a, div.b),
    Vector(cmp.a, cmp.b)
  ) foreach (_.zipWithIndex foreach (
    f => f._1 := recFNFromFN(exp_width, sig_width, io.in(f._2))
  ))

  Vector(
    io.rm -> Vector(
      madd.roundingMode,
      add.roundingMode,
      mul.roundingMode,
      div.roundingMode,
      f_to_i.roundingMode,
      i_to_f.roundingMode
    ),
    consts.tininess_afterRounding -> Vector(
      madd.detectTininess,
      add.detectTininess,
      mul.detectTininess,
      div.detectTininess,
      i_to_f.detectTininess
    )
  ) foreach (
    f => f._2 foreach (_ := f._1)
  )

  io.div_sqrt_ready := div.inReady
  io.out := MuxCase(0.U, Vector(
    1 to 4,
    5 to 6,
    Vector(7)
  ).zipWithIndex.map(
    f => f._1.map(io.aluOp === _.U).reduce(_ || _) -> op_out(f._2)
  ) ++ (10 to 12).map(
    f => (io.aluOp === f.U) -> FSignInject(io.in(0), io.in(1), f.U)
  ) ++ Vector(cmp.lt, cmp.gt).zipWithIndex.map(  // fmin.s, fmax.s
    f => (io.aluOp === (f._2 + 13).U) -> MuxCase(
      Mux(cmp.eq || f._1, io.in(0), io.in(1)), Vector(
        (raw_in(0).isNaN && raw_in(1).isNaN) -> canon_nan,
        raw_in(0).isNaN -> io.in(1),
        raw_in(1).isNaN -> io.in(0),
        Vector(
          (0 to 1).map(io.in(_) === neg_zero).reduce(_ || _),
          (0 to 1).map(io.in(_) === pos_zero).reduce(_ || _),
        ).reduce(_ && _) -> (if (f._2 == 0) neg_zero else pos_zero)
      )
    )
  ) ++ (15 to 16).map(
    f => (io.aluOp === f.U) -> f_to_i.out
  ) ++ Vector(17, 24).map(
    f => (io.aluOp === f.U) -> io.in(0)
  ) ++ Vector(cmp.eq, cmp.lt, !cmp.gt).zipWithIndex.map(
    f => (io.aluOp === (f._2 + 18).U) -> Mux(raw_in(0).isNaN || raw_in(1).isNaN, 0.U, f._1)
  ) ++ Vector((io.aluOp === 21.U) -> classifyRecFN(
    exp_width,
    sig_width,
    recFNFromFN(exp_width, sig_width, io.in(0))
  )) ++ (22 to 23).map(
    f => (io.aluOp === f.U) -> op_out(4)
  ) ++ Vector((div.outValid_div || div.outValid_sqrt) -> op_out(3)))

  io.exceptions <> MuxCase(0.U, Vector(
    (1 to 4) -> madd.exceptionFlags,
    (5 to 6) -> add.exceptionFlags,
    Vector(7) -> mul.exceptionFlags,
    ((13 to 14) ++ (18 to 20)) -> cmp.exceptionFlags,
    (22 to 23) -> i_to_f.exceptionFlags
  ).map(
    f => f._1.map(io.aluOp === _.U).reduce(_ || _) -> f._2
  ) ++ (15 to 16).map(
    f => (io.aluOp === f.U) -> (
      (f_to_i.intExceptionFlags(2) | f_to_i.intExceptionFlags(1)) ## 0.U ## 0.U ## 0.U ## f_to_i.intExceptionFlags(0)
    )
  ) ++ Vector((div.outValid_div || div.outValid_sqrt) -> div.exceptionFlags)).asBools
}
