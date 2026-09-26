package nucleusrv.components

import chisel3._
import chiseltest._
import org.scalatest.freespec.AnyFreeSpec
import chiseltest.simulator.{VerilatorBackendAnnotation, WriteVcdAnnotation, VerilatorFlags}
class TopTest extends AnyFreeSpec with ChiselScalatestTester {

  def getProgramFile: Option[String] = {
    if (scalaTestContext.value.get.configMap.contains("programFile")) {
      Some(scalaTestContext.value.get.configMap("programFile").toString)
    } else {
      None
    }
  }

  def getDataFile0: Option[String] = {
    if (scalaTestContext.value.get.configMap.contains("dataFile0")) {
      Some(scalaTestContext.value.get.configMap("dataFile0").toString)
    } else {
      None
    }
  }

    def getDataFile1: Option[String] = {
    if (scalaTestContext.value.get.configMap.contains("dataFile1")) {
      Some(scalaTestContext.value.get.configMap("dataFile1").toString)
    } else {
      None
    }
  }

  "Top Test" in {
    val programFile = getProgramFile
    val dataFile0 = getDataFile0
    val dataFile1 = getDataFile1

    
    test(new Top(programFile, dataFile0, dataFile1)).withAnnotations(Seq(
      VerilatorBackendAnnotation,
      // VerilatorFlags(Seq("--timing")),
      WriteVcdAnnotation 
    )) { c =>
      c.clock.setTimeout(0)
      c.clock.step(10000)
    }
  }
}
