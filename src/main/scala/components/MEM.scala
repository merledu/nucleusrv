package components
import chisel3._

class MemoryFetch extends Module {
  val io = IO(new Bundle {
    val aluResultIn = Input(UInt(32.W))
    val writeData = Input(UInt(32.W))
    val writeEnable = Input(Bool())
    val readEnable = Input(Bool())
    //val ctl_branch_taken = Input(Bool())

    val readData = Output(UInt(32.W))
    //val ctl_PcSrc = Output(Bool())
  })

  val dataMem = Module(new DataMemory)
  dataMem.io.address := io.aluResultIn
  dataMem.io.writeData := io.writeData
  dataMem.io.writeEnable := io.writeEnable
  dataMem.io.readEnable := io.readEnable

  //io.ctl_PcSrc := io.ctl_branch_taken

  io.readData := dataMem.io.readData
}
