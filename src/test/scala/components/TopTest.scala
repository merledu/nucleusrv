package components

import chisel3._ 
import chiseltest._ 
import org.scalatest.FreeSpec

import chiseltest.experimental.TestOptionBuilder._ 
import chiseltest.internal.VerilatorBackendAnnotation

import caravan.bus.common.BusConfig
import caravan.bus.wishbone.{WishboneConfig, WBRequest, WBResponse, WishboneAdapter}

class TopTest extends FreeSpec with ChiselScalaTester {
    def getFile: Option[String] = {
    if (scalaTestContext.value.get.configMap.contains("memFile")) {
      Some(scalaTestContext.value.get.configMap("memFile").toString)
    } else {
      None
    }
//     def getConfig:BusConfig  = {
//     if (scalaTestContext.value.get.configMap.contains("config")) {
//       scalaTestContext.value.get.configMap("config").toString
//     } else {
//       WishboneConfig(32,32)
//     }
//   }

  "Top Test" in {
      implicit val config = WishboneConfig(32,32) //getConfig
      val programFile = getFile
      // test(new Top(new WBRequest(), new WBResponse(), Module(new WishboneAdapter()), Module(new WishboneAdapter()), programFile)).withAnnotation(Seq(VerilatorBackendAnnotation)){ c =>
        test(new Top(programFile)).withAnnotations(Seq(VerilatorBackendAnnotation)){ c =>
        c.clock.step(999)
      }
  }
}