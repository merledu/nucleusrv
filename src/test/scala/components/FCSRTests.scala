package nucleusrv.components

import chisel3._
import chisel3.util._
import org.scalatest._
import chiseltest._

class CSRTest extends FlatSpec with ChiselScalatestTester {
  behavior of "CSR"

  it should "perform FRCSR operation correctly" in {
    test(new CSR()) { c =>
      c.io.i_opr.poke("b010".U) // csrrs opcode
      c.io.i_addr.poke("h003".U) // CSR address for fcsr
      c.io.i_data.poke(1.U) // Data input to fcsr (dz high)
      c.io.i_w_en.poke(true.B) // Write enable signal for fcsr
      c.clock.step(1)
      c.io.o_data.expect(1.U) // Expected data output after fcsr operation (dz high)
    }
  }

  it should "perform FSCSR operation correctly" in {
    test(new CSR()) { c =>
      c.io.i_opr.poke("b001".U) // csrrw opcode
      c.io.i_addr.poke("h003".U) // CSR address for fcsr
      c.io.i_data.poke("b00000000000000000000000000100000".U) // Data input to fcsr
      c.io.i_w_en.poke(true.B) // Write enable signal for fcsr
      c.clock.step(1)
      c.io.o_data.expect("b00000000000000000000000000100000".U) // Expected data output after fcsr operation
    }
  }

  it should "perform FRRM operation correctly" in {
    test(new CSR()) { c =>
      c.io.i_opr.poke("b001".U) // csrrw opcode
      c.io.i_addr.poke("h003".U) // CSR address for fcsr
      c.io.i_data.poke("b00000000000000000000000001100000".U) // Data input to fcsr (RUP rounding)
      c.io.i_w_en.poke(true.B) // Write enable high signal for fcsr
      c.clock.step(1)
      c.io.i_w_en.poke(false.B) // Write enable low signal for fcsr
      c.clock.step(1)
      c.io.i_data.expect("b00000000000000000000000001100000".U)
      //c.io.o_data(6).expect(1.B) // Expected data output after fcsr operation
    }
  }

  it should "perform FSRM operation correctly" in {
    test(new CSR()) { c =>
      c.io.i_opr.poke("b001".U) // csrrw opcode
      c.io.i_addr.poke("h003".U) // CSR address for fcsr
      c.io.i_data.poke("b00000000000000000000000000000000".U) // Data input to fcsr (RNE rounding)
      c.io.i_w_en.poke(true.B) // Write enable signal for fcsr
      c.clock.step(1)
      c.io.i_data.expect("b00000000000000000000000000000000".U)
    }
  }

  it should "perform FRFLAGS operation correctly" in {
    test(new CSR()) { c =>
      c.io.i_opr.poke("b001".U) // csrrw opcode
      c.io.i_addr.poke("h003".U) // CSR address for fcsr
      c.io.i_data.poke("b00000000000000000000000000000100".U) // Data input to fcsr (OF flag)
      c.io.i_w_en.poke(true.B) // Write enable signal for fcsr
      c.clock.step(1)
      c.io.i_w_en.poke(false.B) // Write enable low signal for fcsr
      c.clock.step(1)
      c.io.i_data.expect("b00000000000000000000000000000100".U) 
    }
  }

  it should "perform FSFLAGS operation correctly" in {
    test(new CSR()) { c =>
      c.io.i_opr.poke("b001".U) // csrrw opcode
      c.io.i_addr.poke("h003".U) // CSR address for fcsr
      c.io.i_data.poke("b00000000000000000000000000000001".U) // Data input to fcsr (NV flag)
      c.io.i_w_en.poke(true.B) // Write enable signal for fcsr
      c.clock.step(1)
      c.io.i_data.expect("b00000000000000000000000000000001".U) 
    }
  }


  

}
