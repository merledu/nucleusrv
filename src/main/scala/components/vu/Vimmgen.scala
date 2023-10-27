package nucleusrv.components.vu

import chisel3._
import chisel3.util._

class ImmdValGen extends Bundle {
    val instruction = Input ( UInt (32. W ) )
	val z_imm = Output(SInt(32.W))
	val addi_imm = Output(SInt(32.W))
}

class ImmdValGen1 extends Module {
    val io = IO (new ImmdValGen )
	io.z_imm:= (Cat(Fill(21,io.instruction(30)),io.instruction(30,20))).asSInt
	io.addi_imm := Cat(Fill(27, 0.U), io.instruction(19,15)).asSInt
}