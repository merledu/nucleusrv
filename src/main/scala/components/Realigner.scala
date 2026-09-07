/*  
    Created by @Abdulwadodd as part of Google Summer of Code program 2022.
    
    Description:
    This module is instantiated in-between the InstructionFetch and rest of the core.
    It receives instruction address (PC) from the core and the corresponding instruction from memory
    If the Address is word aligned then it simply pass the signals b/w core and memory.
    If the address is misaligned, then the state machine of Realigner module comes into action.
    State machine performs the following operations:
      1. Store the upper half word of current instruction,
         Halt the PC for one cycle, and 
         send the address to the next instruction.
         Meanwhile, NOP will be fed to the core.
      2. After one cycle, when the instruction arrives, 
         the  lower half word of this instruction is concatenated
         with the previously stored upper-half word. And this new 
         instruction will be fed to the core.  */

package nucleusrv.components
import chisel3._
import chisel3.util._ 

class Realigner extends Module {
  val io = IO(new Bundle {
    //Input
    val ral_address_i      = Input(UInt(32.W))
    val ral_instruction_i  = Input(UInt(32.W))
    val ral_jmp            = Input(Bool())
    val stall              = Input(Bool())
    val is_comp            = Input(Bool())
    // Outputs
    val ral_instruction_o  = Output(UInt(32.W))
    val addri              = Output(Bool())
    val misaligned_word    = Output(Bool())
    val misaligned_word_uh = Output(Bool())
    val nop_sel            = Output(Bool())
  })

  // 1st bit of address, which represents misalignment
  val addri = io.ral_address_i(1)
  io.addri := addri

  /* control signals */
  val conc_sel = Wire(Bool())   
  val nop_sel  = Wire(Bool()) 
  val uh_is_comp = WireInit(false.B)
  val uh_is_comp_reg  = RegInit(false.B)
  
  conc_sel := false.B
  nop_sel := false.B
  uh_is_comp := Vector("b00", "b01", "b10").map(
    _.U === io.ral_instruction_i(17, 16)
  ) reduce (_ || _)
  uh_is_comp_reg := Mux(
    io.ral_instruction_i =/= 0.U,
    /*!addri && */uh_is_comp,
    uh_is_comp_reg
  )

  // Register to store Lower half word
  val lhw_reg = RegInit(0.U(16.W))     
  val conc_instr = Wire(UInt(32.W)) 
  lhw_reg := Mux(nop_sel, io.ral_instruction_i(31,16), lhw_reg)
  /* Concatenated Instruction: {real_instruction_i(15,0),lhw_reg} */
  conc_instr := Cat(io.ral_instruction_i(15,0),lhw_reg)
  
  /* Instruction for the NRV core */  
  io.ral_instruction_o := MuxCase(io.ral_instruction_i, Vector(
    (addri && !uh_is_comp) -> "h00000013".asUInt(32.W),
    conc_sel -> conc_instr
  ))
  io.misaligned_word := conc_sel

  /*****************
   * Controller *
   ******************/
  // The two states
  val state0 :: state1 :: Nil = Enum (2)

  // The state register
  val stateReg = RegInit(state0)

  // Next state logic
  switch(stateReg){
    is (state0) {
      when (io.stall) {
        stateReg := state0
      }.elsewhen (io.ral_jmp) {
        stateReg := state0
      }.elsewhen (addri && !uh_is_comp/*io.is_comp*/) {
        stateReg := state1
      }.otherwise{
        stateReg := state0
      }
    }
    is (state1) {
      when (io.stall) {
        stateReg := state1
      }.otherwise {
        stateReg := state0
      }
    }
  }

  // Output logic
  nop_sel               := (stateReg === state0) && addri && !uh_is_comp/*io.is_comp*/ && (io.ral_instruction_i =/= 0.U)
  conc_sel              := (stateReg === state1) && (io.ral_instruction_i =/= 0.U)
  io.misaligned_word_uh := (stateReg === state1)
  io.nop_sel            := nop_sel
}
