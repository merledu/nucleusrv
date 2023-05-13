package nucleusrv.components.fpu

import chisel3._, chisel3.util._
import hardfloat._


class FALU_IO extends Bundle {
  // Inputs
  val input    : Vec[UInt] = Input(Vec(3, UInt(32.W)))
  val aluCtl   : UInt      = Input(UInt(5.W))
  val roundMode: UInt      = Input(UInt(3.W))

  // Outputs
  val out       : UInt = Output(UInt(32.W))
  val exceptions: UInt = Output(UInt(5.W))
}


class FALU extends Module {
  val io: FALU_IO = IO(new FALU_IO)

  // Constants
  val expWidth: Int = 8
  val sigWidth: Int = 24

  // Modules
  val fadd  = Module(new AddRecFN(expWidth, sigWidth))
  val fmul  = Module(new MulRecFN(expWidth, sigWidth))
  val fdiv  = Module(new DivSqrtRecFN_small(expWidth, sigWidth, 0))
  val fmadd = Module(new MulAddRecFN(expWidth, sigWidth))
  val fcmp  = Module(new CompareRecFN(expWidth, sigWidth))

  val inType = (
    for (i <- 0 until 2)
      yield rawFloatFromRecFN(
        expWidth,
        sigWidth,
        recFNFromFN(
          expWidth,
          sigWidth,
          io.input(i)
        )
      )
  )

  // Debug Counter
  val counter: UInt = dontTouch(RegInit(0.U(32.W)))
  counter := counter + 1.U

  // Connections
  // - Inputs
  (Seq(
    fadd.io.a,
    fdiv.io.a,
    fmadd.io.a,
    fcmp.io.a,
    fmul.io.a
  ).map (
    f => f -> 0
  ) ++ Seq(
    fadd.io.b,
    fdiv.io.b,
    fmadd.io.b,
    fcmp.io.b,
    fmul.io.b
  ).map(
    f => f -> 1
  ) ++ Seq(
    fmadd.io.c -> 2
  )).map(
    f => f._1 := recFNFromFN(expWidth, sigWidth, io.input(f._2))
  )

  (Seq(  // - Module Specific
    fadd.io.subOp -> Mux(io.aluCtl === 21.U, 1.B, 0.B),

    fdiv.io.inValid -> fdiv.io.inReady,
    fdiv.io.sqrtOp -> 0.U
  ) ++ Seq(
    fmadd.io.op -> Seq(
      16.U  -> 0.U,  // fmadd.s
      25.U  -> 1.U,  // fmsub.s
      26.U  -> 2.U,  // fnmsub.s
      17.U  -> 3.U   // fnmadd.s
    ),

    fcmp.io.signaling -> (Seq(
      18,  // flt.s
      19   // fle.s
    ).map(f => f.U -> 1.B) ++ Seq(
      20,  // fmin.s
      23,  // fmax.s
      27   // feq.s
    ).map(f => f.U -> 0.B))
  ).map(
    f => f._1 -> MuxLookup(io.aluCtl, 0.U, f._2)
  ) ++ Seq(  // - roundingMode
    fadd.io.roundingMode,
    fdiv.io.roundingMode,
    fmadd.io.roundingMode,
    fmul.io.roundingMode
  ).map(
    f => f -> io.roundMode
  ) ++ Seq(  // - detectTininess
    fadd.io.detectTininess,
    fdiv.io.detectTininess,
    fmadd.io.detectTininess,
    fmul.io.detectTininess
  ).map(
    f => f -> consts.tininess_afterRounding
  )).map(
    f => f._1 := f._2
  )

  // Operation Selection
  io.out := MuxCase(0.U, (Seq(
    Seq(14, 21) -> fadd.io.out,           // 14 -> fadd.s, 21 -> fsub.s
    Seq(15) -> fdiv.io.out,               // fdiv.s
    Seq(16, 17, 25, 26) -> fmadd.io.out,  // 16 -> fmadd.s, 17 -> fnmadd.s, 25 -> fmsub.s, 26 -> fnmsub.s
    Seq(22) -> fmul.io.out                // fmul.s
  ).map(
    f => f._1 -> fNFromRecFN(expWidth, sigWidth, f._2)
  ) ++ Seq(
    Seq(18) -> fcmp.io.lt,                                              // flt.s
    Seq(19) -> (fcmp.io.lt || fcmp.io.eq),                              // fle.s
    Seq(20) -> MuxCase(Mux(fcmp.io.lt, io.input(0), io.input(1)), Seq(  // fmin.s
      inType.map(f => f.isNaN).reduce(
        (a, b) => a && b
      ) -> "h7FC00000".U
    ) ++ Seq(
      0 -> 1,
      1 -> 0
    ).map(
      f => inType(f._1).isNaN -> io.input(f._2)
    )),
    Seq(23) -> MuxCase(Mux(fcmp.io.gt, io.input(0), io.input(1)), Seq(  // fmax.s
      inType.map(f => f.isNaN).reduce(
        (a, b) => a && b
      ) -> "h7FC00000".U
    ) ++ Seq(
      0 -> 1,
      1 -> 0
    ).map(
      f => inType(f._1).isNaN -> io.input(f._2)
    )),
    Seq(27) -> fcmp.io.eq
  )).map(
    x => x._1.map(
      y => io.aluCtl === y.U
    ).reduce(
      (y, z) => y || z
    ) -> x._2
  ))

  io.exceptions := MuxCase(0.U, Seq(
    Seq(14, 21) -> fadd.io.exceptionFlags,              // fadd.s, fsub.s
    Seq(15, 24) -> fdiv.io.exceptionFlags,              // fdiv.s, fsqrt.s
    Seq(16, 17, 25, 26) -> fmadd.io.out,                // fmadd.s, fnmadd.s, fmsub.s, fmnsub.s
    Seq(18, 19, 20, 23, 27) -> fcmp.io.exceptionFlags,  // flt.s, fle.s, fmin.s, fmax.s, feq.s
    Seq(22) -> fmul.io.exceptionFlags,                  // fmul.s
  ).map(
    x => x._1.map(
      y => io.aluCtl === y.U
    ).reduce(
      (y, z) => y || z
    ) -> x._2
  ))



  // DEBUG
}
