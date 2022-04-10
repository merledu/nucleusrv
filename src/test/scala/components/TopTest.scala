package nucleusrv.components

import chisel3._ 
import chiseltest._ 
import org.scalatest.FreeSpec

import chiseltest.experimental.TestOptionBuilder._ 
import chiseltest.internal.VerilatorBackendAnnotation

import caravan.bus.common.BusConfig
// import caravan.bus.wishbone.{WishboneConfig, WBRequest, WBResponse}

class TopTest extends FreeSpec with ChiselScalatestTester {
    def getFile: Option[String] = {
    if (scalaTestContext.value.get.configMap.contains("memFile")) {
      Some(scalaTestContext.value.get.configMap("memFile").toString)
    } else {
      None
    }
    }

  "Top Test" in {
      // implicit val config = WishboneConfig(32,32) //getConfig
      val programFile = getFile
      // test(new Top(new WBRequest(), new WBResponse(), Module(new WishboneAdapter()), Module(new WishboneAdapter()), programFile)).withAnnotation(Seq(VerilatorBackendAnnotation)){ c =>
        test(new Top(programFile)).withAnnotations(Seq(VerilatorBackendAnnotation)){ c =>
          c.clock.setTimeout(0)
          c.clock.step(10000)
      }
  }
}