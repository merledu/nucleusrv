package components

import chisel3._
import chisel3 . util._
import org.scalatest._
import chisel3.experimental._
import chiseltest._
import chisel3.experimental.BundleLiterals._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation



class MDUTests extends FreeSpec with ChiselScalatestTester {

  "MULTIPLICATION AND DIVISION UNIT" in {
    test(new MDU()).withAnnotations(Seq(VerilatorBackendAnnotation)) { c =>
        c.io.i_mdu_rs1.poke(1.U)
        c.io.i_mdu_rs2.poke(5.U)
        c.io.i_mdu_op.poke(2.U)
        c.io.i_mdu_valid.poke(1.B)
        

        c.clock.step(20)
        //c.io.o_mdu_ready.expect(1.B)
        //c.io.o_mdu_rd.expect(5.U)
    }
  }
}