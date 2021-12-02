
package components
import chisel3._
import chisel3.util._

class ALU extends Module {
  val io = IO(new Bundle {
    val input1: UInt = Input(UInt(32.W))
    val input2: UInt = Input(UInt(32.W))
    val aluCtl: UInt = Input(UInt(4.W))

    val zero: Bool = Output(Bool())
    val result: UInt = Output(UInt(32.W))
  })
  io.result := MuxCase(
    0.U,
    Array(
      (io.aluCtl === 0.U) -> (io.input1 & io.input2),
      (io.aluCtl === 1.U) -> (io.input1 | io.input2),
      (io.aluCtl === 2.U) -> (io.input1 + io.input2),
      (io.aluCtl === 3.U) -> (io.input1 - io.input2),
      (io.aluCtl === 4.U) -> (io.input1.asSInt < io.input2.asSInt).asUInt,
      (io.aluCtl === 5.U) -> (io.input1 < io.input2),
      (io.aluCtl === 6.U) -> (io.input1 << io.input2(4, 0)),
      (io.aluCtl === 7.U) -> (io.input1 >> io.input2(4, 0)),
      (io.aluCtl === 8.U) -> (io.input1.asSInt >> io.input2(4, 0)).asUInt,
      (io.aluCtl === 9.U) -> (io.input1 ^ io.input2)
    )
  )
  io.zero := DontCare
}


// class Mux4 extends Component {
// val io = new Bundle {
// val in0 = Bits(width = 1, dir = ’input);
// val in1 = Bits(width = 1, dir = ’input);
// val in2 = Bits(width = 1, dir = ’input);
// val in3 = Bits(width = 1, dir = ’input);
// val sel = Bits(width = 2, dir = ’input);
// val out = Bits(width = 1, dir = ’output);
// }
// val m0 = new Mux2();
// m0.io.sel := io.sel(0); m0.io.in0 := io.in0; m0.io.in1 := io.in1;
// val m1 = new Mux2();
// m1.io.sel := io.sel(0); m1.io.in0 := io.in2; m1.io.in1 := io.in3;
// val m3 = new Mux2();
// m3.io.sel := io.sel(1); m3.io.in0 := m0.io.out; m3.io.in1 := m1.io.out;
// io.out := m3.io.out;
// }