
package components
import chisel3._

class MemoryFetch extends Module {
  val io = IO(new Bundle {
    val aluResultIn: UInt = Input(UInt(32.W))
    val writeData: UInt = Input(UInt(32.W))
    val writeEnable: Bool = Input(Bool())
    val readEnable: Bool = Input(Bool())
    //val ctl_branch_taken = Input(Bool())

    val readData: UInt = Output(UInt(32.W))
    //val ctl_PcSrc = Output(Bool())
  })

  val dataMem: DataMemory = Module(new DataMemory)
  dataMem.io.address := io.aluResultIn
  dataMem.io.writeData := io.writeData
  dataMem.io.writeEnable := io.writeEnable
  dataMem.io.readEnable := io.readEnable

  //io.ctl_PcSrc := io.ctl_branch_taken

  io.readData := dataMem.io.readData
}
