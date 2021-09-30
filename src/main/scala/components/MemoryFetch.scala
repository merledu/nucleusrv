
package components
import chisel3._

class MemoryFetchIO extends Bundle{
  val aluResultIn: UInt = Input(UInt(32.W))
  val writeData: UInt = Input(UInt(32.W))
  val writeEnable: Bool = Input(Bool())
  val readEnable: Bool = Input(Bool())
  val readData: UInt = Output(UInt(32.W))
  val dmem = Flipped(new DMemIO)
}

class MemoryFetch extends Module {
  val io = IO(new MemoryFetchIO)

//  val dataMem: DataMemory = Module(new DataMemory)
//  dataMem.io.address := io.aluResultIn
//  dataMem.io.writeData := io.writeData
//  dataMem.io.writeEnable := io.writeEnable
//  dataMem.io.readEnable := io.readEnable

  io.dmem.address := io.aluResultIn
  io.dmem.writeData := io.writeData
  io.dmem.writeEnable := io.writeEnable
  io.dmem.readEnable := io.readEnable

  //io.ctl_PcSrc := io.ctl_branch_taken

  io.readData := io.dmem.readData
}
