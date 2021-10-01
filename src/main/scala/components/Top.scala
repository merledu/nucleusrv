
package components
import chisel3._
import caravan.bus.wishbone.{WishboneConfig, WBRequest, WBResponse}

class Top (implicit val config:WishboneConfig) extends Module{
  val io = IO(new Bundle() {
    val pin = Output(UInt(32.W))
  })

//  val imem: InstructionMemory = Module(new InstructionMemory)
//  val dmem: DataMemory = Module(new DataMemory)
  val core: Core = Module(new Core(new WBRequest, new WBResponse))

//  core.io.imem <> imem.io
//  core.io.dmem <> dmem.io
  io.pin := core.io.pin

}
