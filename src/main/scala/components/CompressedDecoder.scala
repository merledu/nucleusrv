/*
  Created by @Abdulwadodd as part of Google Summer of Code program 2022.
  
  Description:
  This decoder decodes all RISC-V Compressed (16-bit) Instructions into 
  its 32-bit equivalent instructions.
  Whenever the compressed instruction is encountered, 
  it sets the is_comp signal which is responsible for selecting
  the increment of PC by 2 rather than 4. */

package nucleusrv.components
import chisel3._
import chisel3.util._ 

class CompressedDecoder extends Module {
  val io = IO(new Bundle {
    //Input
    val instruction_i = Input(UInt(32.W))
    // Outputs
    val is_comp = Output(Bool())
    val instruction_o = Output(UInt(32.W))
  })

  val OPCODE_LOAD   = "h03".asUInt(7.W)
  val OPCODE_OP_IMM = "h13".asUInt(7.W)
  val OPCODE_STORE  = "h23".asUInt(7.W)
  val OPCODE_OP     = "h33".asUInt(7.W)
  val OPCODE_LUI    = "h37".asUInt(7.W) 
  val OPCODE_BRANCH = "h63".asUInt(7.W)
  val OPCODE_JALR   = "h67".asUInt(7.W)
  val OPCODE_JAL    = "h6f".asUInt(7.W)

  //Default values
  io.is_comp := false.B 
  io.instruction_o := io.instruction_i 

  switch (io.instruction_i(1,0)) {

    // C0
    is ("b00".U) {

      switch (io.instruction_i(15, 14)) {

        is ("b00".U) { 
          // c.addi4spn -> addi rd', x2, imm
          io.is_comp := true.B
          io.instruction_o := Cat("b00".asUInt(2.W), io.instruction_i(10, 7), io.instruction_i(12, 11), io.instruction_i(5), 
                              io.instruction_i(6),"b00".asUInt(2.W),"h02".asUInt(5.W), "b000".asUInt(3.W), "b01".asUInt(2.W), io.instruction_i(4, 2),OPCODE_OP_IMM)
        }

        is ("b01".U) {
          // c.lw -> lw rd', imm(rs1')
          io.is_comp := true.B
          io.instruction_o := Cat(Fill(5,"b0".U), io.instruction_i(5), io.instruction_i(12, 10), io.instruction_i(6),
                              "b0001".asUInt(4.W), io.instruction_i(9,7),"b010".asUInt(3.W),"b01".asUInt(2.W), io.instruction_i(4, 2), OPCODE_LOAD)
        }

        is ("b11".U) {
          // c.sw -> sw rs2', imm(rs1')
          io.is_comp := true.B
          io.instruction_o := Cat(Fill(5,"b0".U), io.instruction_i(5), io.instruction_i(12), "b01".asUInt(2.W), io.instruction_i(4,2),
                              "b01".asUInt(2.W), io.instruction_i(9,7),"b010".asUInt(3.W), io.instruction_i(11, 10), io.instruction_i(6), "b00".asUInt(2.W), OPCODE_STORE)
        }

        is ("b10".U) {
          // illegal instruction
          io.is_comp := false.B
          io.instruction_o := io.instruction_i
        }
      }
    }

    // C1

    // Register address checks for RV32E are performed in the regular instruction decoder.
    // If this check fails, an illegal instruction exception is triggered and the controller
    // writes the actual faulting instruction to mtval.
    is ("b01".U) {

      switch (io.instruction_i(15, 13)) {

        is ("b000".U) {
          // c.addi -> addi rd, rd, nzimm
          // c.nop
          io.is_comp := true.B
          io.instruction_o := Cat(Fill(6,io.instruction_i(12)), io.instruction_i(12), io.instruction_i(6,2),
                              io.instruction_i(11,7),"b000".asUInt(3.W), io.instruction_i(11, 7), OPCODE_OP_IMM)
        }
        
        is ("b001".U) {
          // 001: c.jal -> jal x1, imm   
          io.is_comp := true.B
          io.instruction_o := Cat(io.instruction_i(12), io.instruction_i(8), io.instruction_i(10,9), io.instruction_i(6),
                              io.instruction_i(7),io.instruction_i(2), io.instruction_i(11), io.instruction_i(5,3), 
                              Fill(9,io.instruction_i(12)), "b0000".asUInt(4.W), ~io.instruction_i(15), OPCODE_JAL)
        }

        is ("b101".U) {
          // 101: c.j   -> jal x0, imm
          io.is_comp := true.B
          io.instruction_o := Cat(io.instruction_i(12), io.instruction_i(8), io.instruction_i(10,9), io.instruction_i(6),
                              io.instruction_i(7),io.instruction_i(2), io.instruction_i(11), io.instruction_i(5,3), 
                              Fill(9,io.instruction_i(12)), "b0000".asUInt(4.W), ~io.instruction_i(15), OPCODE_JAL)
        }
        
        is ("b010".U) {
          // c.li -> addi rd, x0, nzimm
          // (c.li hints are translated into an addi hint)
          io.is_comp := true.B
          io.instruction_o := Cat(Fill(6,io.instruction_i(12)), io.instruction_i(12), io.instruction_i(6,2), "b00000".asUInt(5.W),
                              "b000".asUInt(3.W), io.instruction_i(11,7), OPCODE_OP_IMM)          
        }

        is ("b011".U) {
          // c.lui -> lui rd, imm
          // (c.lui hints are translated into a lui hint)
          io.is_comp := true.B
          io.instruction_o := Cat(Fill(15,io.instruction_i(12)), io.instruction_i(6,2), io.instruction_i(11,7), OPCODE_LUI)
          
          when(io.instruction_i(11,7) === "h02".asUInt(5.W)) {
            // c.addi16sp -> addi x2, x2, nzimm
             io.instruction_o := Cat(Fill(3,io.instruction_i(12)), io.instruction_i(4,3), io.instruction_i(5), io.instruction_i(2),
                                  io.instruction_i(6), "b0000".asUInt(4.W), "h02".asUInt(5.W), "b000".asUInt(3.W), "h02".asUInt(5.W), OPCODE_OP_IMM)
          }
        }

        is ("b100".U) {    

          switch (io.instruction_i(11,10)) {

            is ("b00".U) {
              // c.srli -> srli rd, rd, shamt
              io.is_comp := true.B
              io.instruction_o := Cat("b0".U, io.instruction_i(10),"b00000".asUInt(5.W), io.instruction_i(6,2), "b01".asUInt(2.W), io.instruction_i(9,7),
                                  "b101".asUInt(3.W),"b01".asUInt(2.W), io.instruction_i(9, 7), OPCODE_OP_IMM)
            }

            is ("b01".U) {
              // c.srai -> srai rd, rd, shamt
              io.is_comp := true.B
              io.instruction_o := Cat("b0".U, io.instruction_i(10),"b00000".asUInt(5.W), io.instruction_i(6,2), "b01".asUInt(2.W), io.instruction_i(9,7),
                                  "b101".asUInt(3.W),"b01".asUInt(2.W), io.instruction_i(9, 7), OPCODE_OP_IMM)
            }              

            is ("b10".U) {
              // c.andi -> andi rd, rd, imm
              io.is_comp := true.B
              io.instruction_o := Cat(Fill(6,io.instruction_i(12)), io.instruction_i(12),io.instruction_i(6,2), "b01".asUInt(2.W), io.instruction_i(9,7),
                                  "b111".asUInt(3.W),"b01".asUInt(2.W), io.instruction_i(9, 7), OPCODE_OP_IMM)
            }

            is ("b11".U) {

              switch (io.instruction_i(6,5)) {

                is ("b00".U) {
                  // c.sub -> sub rd', rd', rs2'
                  io.is_comp := true.B
                  io.instruction_o := Cat("b01".asUInt(2.W), "b00000".asUInt(5.W), "b01".asUInt(2.W), io.instruction_i(4,2), "b01".asUInt(2.W),
                                      io.instruction_i(9,7), "b000".asUInt(3.W), "b01".asUInt(2.W), io.instruction_i(9,7), OPCODE_OP)
                }

                is ("b01".U) {
                  // c.xor -> xor rd', rd', rs2'
                  io.is_comp := true.B
                  io.instruction_o := Cat(Fill(7,"b0".U), "b01".asUInt(2.W), io.instruction_i(4,2), "b01".asUInt(2.W),
                                      io.instruction_i(9,7), "b100".asUInt(3.W), "b01".asUInt(2.W), io.instruction_i(9,7), OPCODE_OP)
                }

                is ("b10".U) {
                  // c.or  -> or  rd', rd', rs2'
                  io.is_comp := true.B
                  io.instruction_o := Cat(Fill(7,"b0".U), "b01".asUInt(2.W), io.instruction_i(4,2), "b01".asUInt(2.W),
                                      io.instruction_i(9,7), "b110".asUInt(3.W), "b01".asUInt(2.W), io.instruction_i(9,7), OPCODE_OP)
                }

                is ("b11".U) {
                  // c.and -> and rd', rd', rs2'
                  io.is_comp := true.B
                  io.instruction_o := Cat(Fill(7,"b0".U), "b01".asUInt(2.W), io.instruction_i(4,2), "b01".asUInt(2.W),
                                      io.instruction_i(9,7), "b111".asUInt(3.W), "b01".asUInt(2.W), io.instruction_i(9,7), OPCODE_OP)
                }
              }
            }
          }
        }

        is ("b110".U) {
          //c.beqz -> beq rs1', x0, imm
          io.is_comp := true.B
          io.instruction_o := Cat(Fill(4,io.instruction_i(12)), io.instruction_i(6,5), io.instruction_i(2), Fill(5,"b0".U), "b01".asUInt(2.W),
                              io.instruction_i(9,7), "b00".asUInt(2.W), io.instruction_i(13), io.instruction_i(11,10), io.instruction_i(4,3),
                              io.instruction_i(12), OPCODE_BRANCH)
        }

        is ("b111".U) {
          //c.bnez -> bne rs1', x0, imm
          io.is_comp := true.B
          io.instruction_o := Cat(Fill(4,io.instruction_i(12)), io.instruction_i(6,5), io.instruction_i(2), Fill(5,"b0".U), "b01".asUInt(2.W),
                              io.instruction_i(9,7), "b00".asUInt(2.W), io.instruction_i(13), io.instruction_i(11,10), io.instruction_i(4,3),
                              io.instruction_i(12), OPCODE_BRANCH)
        }
      }
    }

    // C2

    // Register address checks for RV32E are performed in the regular instruction decoder.
    // If this check fails, an illegal instruction exception is triggered and the controller
    // writes the actual faulting instruction to mtval.

    is ("b10".U) {

      switch (io.instruction_i(15,14)) {

        is ("b00".U) {
          // c.slli -> slli rd, rd, shamt
          // (c.ssli hints are translated into a slli hint)
          io.is_comp := true.B
          io.instruction_o := Cat(Fill(7,"b0".U), io.instruction_i(6,2), io.instruction_i(11,7), "b001".asUInt(3.W),
                              io.instruction_i(11,7), OPCODE_OP_IMM)
        }

        is ("b01".U) {
          // c.lwsp -> lw rd, imm(x2)
          io.is_comp := true.B
          io.instruction_o := Cat(Fill(4,"b0".U), io.instruction_i(3,2), io.instruction_i(12), io.instruction_i(6,4), "b00".asUInt(2.W), "h02".U(5.W),
                              "b010".asUInt(3.W), io.instruction_i(11,7), OPCODE_LOAD)
        }

        is ("b10".U) {

          when(io.instruction_i(12) === "b0".U ) {

            when(io.instruction_i(6,2) =/= "b0".asUInt(5.W)) {

              // c.mv -> add rd/rs1, x0, rs2
              // (c.mv hints are translated into an add hint)
              io.is_comp := true.B
              io.instruction_o := Cat(Fill(7,"b0".U), io.instruction_i(6,2),Fill(8,"b0".U), io.instruction_i(11,7), OPCODE_OP)
            } .otherwise {

               // c.jr -> jalr x0, rd/rs1, 0
              io.is_comp := true.B
              io.instruction_o := Cat(Fill(12,"b0".U), io.instruction_i(11,7),Fill(8,"b0".U), OPCODE_JALR)
            }
          } .otherwise {
            
            when(io.instruction_i(6,2) =/= "b0".asUInt(5.W)) {
              // c.add -> add rd, rd, rs2
              // (c.add hints are translated into an add hint)
              io.is_comp := true.B
              io.instruction_o := Cat(Fill(7,"b0".U), io.instruction_i(6,2), io.instruction_i(11,7), "b000".asUInt(3.W), io.instruction_i(11,7), OPCODE_OP)
            } .otherwise {
              
              when(io.instruction_i(11,7) === "b0".asUInt(5.W)) {
                // c.ebreak -> ebreak
                io.is_comp := true.B
                io.instruction_o := "h0010_0073".asUInt(32.W)
              } .otherwise {
                // c.jalr -> jalr x1, rs1, 0
                io.is_comp := true.B
                io.instruction_o := Cat(Fill(12,"b0".U), io.instruction_i(11,7),Fill(7,"b0".U), "b1".U, OPCODE_JALR)
              }
            }
          }
        }

        is ("b11".U) {
          // c.swsp -> sw rs2, imm(x2)
          io.is_comp := true.B
          io.instruction_o := Cat(Fill(4,"b0".U), io.instruction_i(8,7), io.instruction_i(12), io.instruction_i(6,2), "h02".asUInt(5.W), "b010".asUInt(3.W),
                              io.instruction_i(11,9), "b00".asUInt(2.W), OPCODE_STORE)
        }
      }
    }

    is ("b11".U) {
      // illegal instruction
      io.is_comp := false.B
      io.instruction_o := io.instruction_i

    }
  }
  when(io.instruction_i === "h0".asUInt(32.W)){
    // illegal instruction
      io.is_comp := false.B
      io.instruction_o := io.instruction_i
  }
}
