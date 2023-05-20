package nucleusrv.components

import chisel3._ 
import chiseltest._ 
import org.scalatest.FreeSpec

import chiseltest.experimental.TestOptionBuilder._ 
import chiseltest.internal.VerilatorBackendAnnotation
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.WriteVcdAnnotation

class TopTestCSR extends FreeSpec with ChiselScalatestTester {
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
        test(new Top(programFile, dataFile)).withAnnotations(Seq(VerilatorBackendAnnotation,WriteVcdAnnotation)){ c =>
          c.clock.setTimeout(0)
          c.clock.step(4)
          c.io.fcsr.expect(0.U)
          c.clock.step(1)
          c.io.fcsr.expect(31.U)
          c.clock.step(1)
          c.io.fcsr.expect(2.U)
          c.clock.step(1)
          c.io.fcsr.expect(66.U)
          c.clock.step(2)
          c.io.fcsr.expect(0.U)
          c.clock.step(3)
          c.io.fcsr.expect(31.U)
          c.clock.step(1)
          c.io.fcsr.expect(255.U)
          c.clock.step(2)
          c.io.fcsr.expect(0.U)
          c.clock.step(2)
          c.io.fcsr.expect(255.U)
          c.clock.step(1)
          c.io.fcsr.expect(224.U)
          c.clock.step(1)
          c.io.fcsr.expect(0.U)
          c.clock.step(3)
          c.io.fcsr.expect(31.U)
          c.clock.step(1)
          c.io.fcsr.expect(255.U)
          c.clock.step(2)
          c.io.fcsr.expect(33.U)
          c.clock.step(5)
          c.io.fcsr.expect(34.U)
          c.clock.step(1)
          c.io.fcsr.expect(66.U)
          c.clock.step(3)
          c.io.fcsr.expect(1.U)
          c.clock.step(1)
          c.io.fcsr.expect(2.U)
          c.clock.step(1)
          c.io.fcsr.expect(1.U)
          c.clock.step(1)
          c.io.fcsr.expect(0.U)
          c.clock.step(3)
          c.io.fcsr.expect(1.U)
          c.clock.step(1)
          c.io.fcsr.expect(2.U)
          c.clock.step(1)
          c.io.fcsr.expect(1.U)
          c.clock.step(1)
          c.io.fcsr.expect(0.U)
          c.clock.step(3)
          c.io.fcsr.expect(32.U)
          c.clock.step(1)
          c.io.fcsr.expect(64.U)
          c.clock.step(1)
          c.io.fcsr.expect(32.U)
          c.clock.step(1)
          c.io.fcsr.expect(0.U)
          c.clock.step(3)
          c.io.fcsr.expect(1.U)
          c.clock.step(1)
          c.io.fcsr.expect(2.U)
          c.clock.step(1)
          c.io.fcsr.expect(1.U)
          c.clock.step(10)
      }
  }



  // printf("logs enclosed\n")
}