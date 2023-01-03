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
    val ral_address_i     = Input(UInt(32.W))
    val ral_instruction_i = Input(UInt(32.W))
    val ral_jmp           = Input(Bool())
    // Outputs
    val ral_address_o     = Output(UInt(32.W))
    val ral_instruction_o = Output(UInt(32.W))
    val ral_halt_o        = Output(Bool())
  })

  // 1st bit of address, which represents misalignment
  val addri = io.ral_address_i(1)       
  io.ral_halt_o := false.B

  /* control signals */
  val pc4_sel  = Wire(Bool())    
  val conc_sel = Wire(Bool())   
  val nop_sel  = Wire(Bool()) 
  
  pc4_sel := false.B    
  conc_sel := false.B
  nop_sel := false.B

  // Register to store Lower half word
  val lhw_reg = RegInit(0.U(16.W))     
  val conc_instr = Wire(UInt(32.W)) 
  lhw_reg := io.ral_instruction_i(31,16)
  /* Concatenated Instruction: {real_instruction_i(15,0),lhw_reg} */
  conc_instr := Cat(io.ral_instruction_i(15,0),lhw_reg)
  
  /* Address for InstructionFetch module */
  io.ral_address_o := Mux(pc4_sel, io.ral_address_i + 4.U, io.ral_address_i)
  
  /* Instruction for the NRV core */  
  io.ral_instruction_o := Mux(nop_sel, "h00000013".asUInt(32.W), Mux(conc_sel, conc_instr, io.ral_instruction_i))

  /*****************
   * Controller *
   ******************/
  // The three states
  val state0 :: state1 :: state2 :: Nil = Enum (3)

  // The state register
  val stateReg = RegInit(state0)

  // Next state logic
  switch(stateReg){
    is (state0) {
      when (addri) {
        stateReg := state1
      }.otherwise{
        stateReg := state0
      }
    }
    is (state1) {
      when(addri){
        when (io.ral_jmp) {
          stateReg := state1
        }.otherwise{
          stateReg := state2
        }
      }.otherwise {
        stateReg := state0
      }
    }
    is (state2) {
      when (addri) {
        stateReg := state1
      }.otherwise{
        stateReg := state0
      }
    }
  }

  // Output logic
  io.ral_halt_o := (stateReg === state1)
  pc4_sel       := (stateReg === state1) & addri & ~ (io.ral_jmp)
  nop_sel       := (stateReg === state1)
  conc_sel      := (stateReg === state2)

}