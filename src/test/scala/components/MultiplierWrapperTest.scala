package components

import chisel3._ 
import chiseltest._ 
import org.scalatest.FreeSpec

import chiseltest.experimental.TestOptionBuilder._ 
import chiseltest.internal.VerilatorBackendAnnotation

import caravan.bus.wishbone._ 

class MultiplierWrapperTest extends FreeSpec with ChiselScalatestTester {
    "Multiplier Wrapper Test" in {
        implicit val config = WishboneConfig(32,32)
        test(new MultiplierWrapper(new WBRequest(), new WBResponse())).withAnnotations(Seq(VerilatorBackendAnnotation)){ c =>
            c.io.request.bits.isWrite.poke(true.B)
            c.io.request.bits.addrRequest.poke(4.U)
            c.io.request.bits.dataRequest.poke(6.U)
            c.io.request.bits.activeByteLane.poke("b1111".U)
            c.io.request.valid.poke(true.B)
            c.clock.step(10)

        }
        
    }
}