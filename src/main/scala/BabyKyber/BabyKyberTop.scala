
/* Created By Hamna Mohiuddin @hamnamohi as a Google Summer of Code 2024 Project.*/

package BabyKyber

import chisel3._
import chisel3.util._
import chisel3.experimental._
import chisel3.util.experimental._



class BabyKyberTop extends Module {
  val io = IO(new Bundle {
    val req = Flipped(Decoupled(new RequestIO))
    val rsp = Decoupled(new ResponseIO)
    val enable = Input(Bool())
    val key_enable = Input(Bool())
    val encryption_enable = Input(Bool())
    val decryption_enable = Input(Bool())
    val key_done = Output(Bool()) 
    val encryption_done = Output(Bool()) 
    val decryption_done = Output(Bool()) 
  })

  val validReg = RegInit(false.B)
  io.rsp.valid := validReg
  io.req.ready := true.B

  val rdata = Wire(SInt(32.W))

  // Instantiate the accelerator
  val bkyber = Module(new kybertop)

  // Connect clock and reset
  bkyber.io.clk := clock.asUInt()(0)
  bkyber.io.rst_n := !reset.asBool()

  // Connect control signals
  bkyber.io.enable := io.enable
  bkyber.io.key_enable := io.key_enable
  bkyber.io.encryption_enable := io.encryption_enable
  bkyber.io.decryption_enable := io.decryption_enable

  // Initialize request signals
  bkyber.io.data_Req := DontCare
  bkyber.io.addr_Req := DontCare
  bkyber.io.wen_Req := DontCare
  bkyber.io.bytelane_Req := DontCare
  io.key_done := bkyber.io.key_done
  io.encryption_done := bkyber.io.encryption_done
  io.decryption_done := bkyber.io.decryption_done
  dontTouch(io.req.valid)

  when(io.req.valid && io.req.bits.isWrite) {
    // Write operation - pass full address to SystemVerilog module
    bkyber.io.data_Req := io.req.bits.dataRequest.asSInt
    bkyber.io.addr_Req := io.req.bits.addrRequest.asSInt
    printf("BabyKyberTop WRITE: addr_received=0x%x, data=0x%x, addr_asSInt=0x%x\n", 
           io.req.bits.addrRequest, io.req.bits.dataRequest, bkyber.io.addr_Req.asUInt)
    // bkyber.io.data_Req := io.req.bits.dataRequest
    // bkyber.io.addr_Req := io.req.bits.addrRequest.asSint
    bkyber.io.wen_Req := io.req.bits.isWrite
    bkyber.io.bytelane_Req := io.req.bits.activeByteLane
    rdata := bkyber.io.data_Resp
    validReg := true.B
  }.elsewhen(io.req.valid && !io.req.bits.isWrite) {
    // Read operation - pass full address to SystemVerilog module
    validReg := true.B
    bkyber.io.wen_Req := false.B
    bkyber.io.addr_Req := io.req.bits.addrRequest.asSInt
    printf("BabyKyberTop READ: addr_received=0x%x, addr_asSInt=0x%x\n", 
           io.req.bits.addrRequest, bkyber.io.addr_Req.asUInt)
    rdata := bkyber.io.data_Resp
  }.otherwise {
    validReg := false.B
    rdata := DontCare
  }

io.rsp.bits.dataResponse := rdata.asUInt
}

class BabyKyberIO extends Bundle {
  val clk = Input(Bool())
  val rst_n = Input(Bool())
  val enable = Input(Bool())
  val key_enable = Input(Bool())
  val encryption_enable = Input(Bool())
  val decryption_enable = Input(Bool())
  val data_Req = Input(SInt(32.W))
  val addr_Req = Input(SInt(32.W))
  val wen_Req = Input(Bool())
  val bytelane_Req = Input(UInt(8.W))
  val data_Resp = Output(SInt(32.W))
  val key_done = Output(Bool())
  val encryption_done = Output(Bool()) 
  val decryption_done = Output(Bool()) 
}

class kybertop extends BlackBox with HasBlackBoxResource {
  val io = IO(new BabyKyberIO)
  addResource("/Baby_Kyber/kybertop.sv")
  addResource("/Baby_Kyber/Decrypt.sv")
  addResource("/Baby_Kyber/Encrypt.sv")
  addResource("/Baby_Kyber/KeyGeneration.sv")
  addResource("/Baby_Kyber/PolynomialMatrixMultiplication.sv")
  addResource("/Baby_Kyber/MatrixTranspose.sv")
}
