package nucleusrv.components.vu

import chisel3._
import chisel3.util._

class ImmdValGen extends Bundle {
    val instruction = Input ( UInt (32. W ) )
    // val pc = Input(UInt(32.W))
	// val s_imm = Output(SInt(32.W))
	// val sb_imm = Output(SInt(32.W))
	// val uj_imm = Output(SInt(32.W))
	// val u_imm = Output(SInt(32.W))
	// val i_imm = Output(SInt(32.W))
	val z_imm = Output(SInt(32.W))
	val addi_imm = Output(SInt(32.W))
}

class ImmdValGen1 extends Module {
    val io = IO (new ImmdValGen )
// Start coding here
    //S-type
	// val s_imm_ = Cat (io.instruction(31,25),io.instruction(11,7))
	// io.s_imm := (Cat(Fill(20,s_imm_(11)),s_imm_)).asSInt
	// SB-type
	// val sb_imm_ = Cat (io.instruction(31),io.instruction(7),io.instruction(30,25),io.instruction(11,8),"b0".U)
	// io.sb_imm := ((Cat(Fill(19,sb_imm_(12)),sb_imm_)) + io.pc).asSInt
	// UJ-type
	// val uj_imm_ = Cat (io.instruction(31),io.instruction(19,12),io.instruction(20),io.instruction(30,21),"b0".U)
	// io.uj_imm := ((Cat(Fill(12,uj_imm_(20)),uj_imm_)) + io.pc).asSInt
	// U-type
	// io.u_imm := (Cat(io.instruction(31,12),Fill(12,"b0".U))).asSInt
	// I-type
	// io.i_imm := (Cat(Fill(20,io.instruction(31)),io.instruction(31,20))).asSInt

	io.z_imm:= (Cat(Fill(21,io.instruction(30)),io.instruction(30,20))).asSInt
	io.addi_imm := Cat(Fill(27, 0.U), io.instruction(19,15)).asSInt
}