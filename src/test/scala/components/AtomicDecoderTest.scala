package nucleusrv.components

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class AtomicDecoderTest extends AnyFlatSpec with ChiselScalatestTester {

  behavior of "AtomicDecoder"

  it should "decode LR, SC, and AMO instructions correctly" in {
    test(new AtomicDecoder).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>

        def makeInstr(funct5: String, funct3: String = "010", opcode: String = "0101111"): BigInt = {
          // funct5(31–27) + rs2(26–20)=0000000 + rs1(19–15)=00000 + funct3(14–12)
          // + rd(11–7)=00000 + opcode(6–0)
          val bin = funct5 + "0000000" + "00000" + funct3 + "00000" + opcode
          BigInt(bin, 2)
        }


      // LR.W (funct5=00010)
      dut.io.instr.poke(makeInstr("00010").U)
      dut.clock.step()
      dut.io.out.isLR.expect(true.B)
      dut.io.out.isSC.expect(false.B)
      dut.io.out.isAMO.expect(false.B)

      // SC.W (funct5=00011)
      dut.io.instr.poke(makeInstr("00011").U)
      dut.clock.step()
      dut.io.out.isLR.expect(false.B)
      dut.io.out.isSC.expect(true.B)
      dut.io.out.isAMO.expect(false.B)

      // AMOADD.W (funct5=00000)
      dut.io.instr.poke(makeInstr("00000").U)
      dut.clock.step()
      dut.io.out.isAMO.expect(true.B)
      dut.io.out.amoOp.expect(1.U)

      // AMOAND.W (funct5=01100)
      dut.io.instr.poke(makeInstr("01100").U)
      dut.clock.step()
      dut.io.out.isAMO.expect(true.B)
      dut.io.out.amoOp.expect(4.U)

      // AMOMAXU.W (funct5=11100)
      dut.io.instr.poke(makeInstr("11100").U)
      dut.clock.step()
      dut.io.out.isAMO.expect(true.B)
      dut.io.out.amoOp.expect(9.U)

      // Invalid opcode
      dut.io.instr.poke("b00000000000000000000000000000000".U)
      dut.clock.step()
      dut.io.out.isLR.expect(false.B)
      dut.io.out.isSC.expect(false.B)
      dut.io.out.isAMO.expect(false.B)
    }
  }
}
