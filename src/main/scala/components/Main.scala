package components
import java.io.{File, FileWriter}
import chisel3.stage.ChiselStage

object Main extends App {
//  val chirrtl = firrtl.Parser.parse(chisel3.Driver.emit(() => new CPU()))
//
//  val writer = new FileWriter(new File(dir, s"${chirrtl.main}.fir"))
//  writer write chirrtl.serialize
//  writer.close()
//
//  val verilog = new FileWriter(new File(dir, s"${chirrtl.main}.v"))
//  verilog write (new firrtl.VerilogCompiler).compileAndEmit(firrtl.CircuitState(chirrtl, firrtl.ChirrtlForm)).getEmittedCircuit.value
//  verilog.close()

//  val imemVerilog = new FileWriter(new File(dir, s"${chirrtlImem.main}.v"))
//  imemVerilog write (new firrtl.VerilogCompiler).compileAndEmit(firrtl.CircuitState(chirrtlImem, firrtl.ChirrtlForm)).getEmittedCircuit.value
//  imemVerilog.close()

  (new ChiselStage).emitVerilog(new CPU, args)


//  val imem = new FileWriter(new File(dir, s"imem.v"))
//  imem write new ChiselStage().emitVerilog(new InstructionMemory)
//  imem.close()

}
