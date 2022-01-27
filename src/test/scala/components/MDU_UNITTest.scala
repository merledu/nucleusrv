package nucleusrv.components
import chisel3._
import org.scalatest._
import chiseltest._
import chisel3.experimental.BundleLiterals._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation


class MultiplierTest extends FreeSpec with ChiselScalatestTester {

  "Multiplication and Division Operations" in {
    test(new MDU()).withAnnotations(Seq(VerilatorBackendAnnotation)) { c =>
      c.io.src_a.poke(11.S)
      c.io.src_b.poke(2.S)
      c.io.valid.poke(1.B)
      c.io.op.poke(7.U)
      c.clock.step(1)
      c.io.valid.poke(0.B)

      c.clock.step(100)
      // c.io.output.bits.expect(25.S)
    }
  }
}                             