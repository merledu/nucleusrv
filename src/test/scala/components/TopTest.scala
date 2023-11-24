package nucleusrv.components

import chisel3._ 
import chiseltest._ 
import org.scalatest.freespec.AnyFreeSpec

//import chiseltest.experimental.TestOptionBuilder._
//import chiseltest.internal.VerilatorBackendAnnotation

class TopTest extends AnyFreeSpec with ChiselScalatestTester {
  def getProgramFile: Option[String] = {
    if (scalaTestContext.value.get.configMap.contains("programFile")) {
      Some(scalaTestContext.value.get.configMap("programFile").toString)
    } else {
      None
    }
  }

  def getDataFile: Option[String] = {
    if (scalaTestContext.value.get.configMap.contains("dataFile")) {
      Some(scalaTestContext.value.get.configMap("dataFile").toString)
    } else {
      None
    }
  }

  "Top Test" in {
      // implicit val config = WishboneConfig(32,32) //getConfig
      val programFile = getProgramFile
      val dataFile = getDataFile
      // test(new Top(new WBRequest(), new WBResponse(), Module(new WishboneAdapter()), Module(new WishboneAdapter()), programFile)).withAnnotation(Seq(VerilatorBackendAnnotation)){ c =>
        test(new Top(programFile, dataFile)).withAnnotations(Seq(VerilatorBackendAnnotation)){ c =>
          c.clock.setTimeout(0)
          c.clock.step(300)
      }
  }
  // printf("logs enclosed\n")
}