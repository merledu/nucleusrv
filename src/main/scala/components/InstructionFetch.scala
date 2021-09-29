
package components
import chisel3._
import chisel3.util._ 

import caravan.bus.common.{BusConfig, AbstrRequest, AbstrResponse}

class InstructionFetch(val req:AbstrRequest, val rsp:AbstrResponse)(implicit val config:BusConfig) extends Module {
  val io = IO(new Bundle {
    val PCPlusOffset: UInt = Input(UInt(32.W))
    val PcSrc: Bool = Input(Bool())
    val instruction: UInt = Output(UInt(32.W))
    val PC: UInt = Output(UInt(32.W))
//    val PCounter: UInt = Output(UInt(32.W))
    val PcWrite: Bool = Input(Bool())
  })

  val IMEM: InstructionMemory = Module(new InstructionMemory(req,rsp))

  //  val PC: UInt = RegInit(0.U(32.W))
//  val counter: SInt = RegInit(-4.S(32.W))
//  IMEM.io.address := PC >> 2
//  io.instruction := IMEM.io.instruction

  //Program Counter Implementation
  val PCPlusFour: UInt = io.PC + 4.U
  val pcNext: UInt = Wire(UInt(32.W))

  pcNext := Mux(io.PcWrite, io.PC, Mux(io.PcSrc, io.PCPlusOffset, PCPlusFour))
  IMEM.io.address := pcNext

  io.instruction := IMEM.io.instruction

  io.PC := pcNext


  // Program Counter implementation
//  val PCPlusFour: UInt = PC + 4.U
//  val counterPlusFour: SInt = counter + 4.S
//
//  when(io.PcWrite) {
//    when(io.PcSrc) {
//      PC := io.PCPlusOffset
//      counter := io.PCPlusOffset.asSInt() - 4.S
//    }.otherwise {
//      PC := PCPlusFour
//      counter := counterPlusFour
//    }
//  }.otherwise {
//    PC := io.PCounter
//    counter := io.PC.asSInt()
//  }
//  io.PCounter := PC
//  io.PC:= counter.asUInt()
}
