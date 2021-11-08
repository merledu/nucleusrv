package components

import chisel3._
import org.scalatest._
import chiseltest._
import chisel3.experimental.BundleLiterals._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation


class MultiplierTest extends FreeSpec with ChiselScalatestTester {

  "Multiplier Test" in {
    test(new Multiplier()).withAnnotations(Seq(VerilatorBackendAnnotation)) { c =>
      c.io.src_a.poke(5.S)
      c.io.src_b.poke(5.S)
      c.io.op.poke(0.U)
      c.clock.step(100)
      c.io.output.expect(25.S)
    }
  }
}