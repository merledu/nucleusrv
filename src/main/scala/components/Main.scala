package components
import java.io.{File, FileWriter}
import chisel3.stage.ChiselStage

object Main extends App {
  (new ChiselStage).emitVerilog(new CPU, args)
}
