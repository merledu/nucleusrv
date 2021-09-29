import caravan.bus.tilelink.TilelinkConfig
import chisel3._
import org.scalatest._
import chiseltest._
import chiseltest.ChiselScalatestTester
import chiseltest.internal.VerilatorBackendAnnotation
import chiseltest.experimental.TestOptionBuilder._
import org.scalatest.FreeSpec
class TilelinkHarnessTester extends FreeSpec with ChiselScalatestTester {
  def getFile: Option[String] = {
    if (scalaTestContext.value.get.configMap.contains("memFile")) {
      Some(scalaTestContext.value.get.configMap("memFile").toString)
    } else {
      None
    }
  }
  "Tilelink plus Core" in {
    implicit val config = TilelinkConfig()
    val programFile = getFile
    test(new TilelinkHarness(programFile)).withAnnotations(Seq(VerilatorBackendAnnotation)) {c =>
      c.clock.step(999)
    }
  }
}
