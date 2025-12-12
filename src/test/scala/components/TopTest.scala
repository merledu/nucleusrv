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

  def getDataFile: Option[String] = {
    if (scalaTestContext.value.get.configMap.contains("dataFile")) {
      Some(scalaTestContext.value.get.configMap("dataFile").toString)
    } else {
      None
    }
  }

  "Top Test" in {
    val programFile = getProgramFile
    val dataFile = getDataFile

    
    test(new Top(programFile, dataFile)).withAnnotations(Seq(
      VerilatorBackendAnnotation,
      VerilatorFlags(Seq("--timing")),
      WriteVcdAnnotation 
    )) { c =>
      c.clock.setTimeout(0)
      c.clock.step(10000)
    }
  }
}
