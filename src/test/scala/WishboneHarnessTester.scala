import caravan.bus.wishbone.WishboneConfig
import chisel3._
import org.scalatest._
import chiseltest._
import chiseltest.ChiselScalatestTester
import chiseltest.internal.VerilatorBackendAnnotation
import chiseltest.experimental.TestOptionBuilder._
import org.scalatest.FreeSpec
class WishboneHarnessTester extends FreeSpec with ChiselScalatestTester {
  def getFile: Option[String] = {
    if (scalaTestContext.value.get.configMap.contains("memFile")) {
      Some(scalaTestContext.value.get.configMap("memFile").toString)
    } else {
      None
    }
  }
  "Wishbone plus Core" in {
    implicit val config = WishboneConfig(32,32)
    val programFile = getFile
    test(new WishboneHarness(programFile)).withAnnotations(Seq(VerilatorBackendAnnotation)) {c =>
      c.clock.step(999)
    }
  }
}
