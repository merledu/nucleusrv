import chisel3._
import chisel3.util._
import chisel3.experimental._

class DatacacheSRAMTop extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val clk_i    = Input(Clock())
    val rst_i    = Input(Bool())

    val csb_i    = Input(Bool())
    val addr_i   = Input(UInt(13.W))
    val wdata_i  = Input(UInt(148.W))
    val wmask_i  = Input(UInt(4.W))
    val we_i     = Input(Bool())
    val rdata_o  = Output(UInt(32.W))
  })

  // Inline SystemVerilog Module
  setInline("datacache_sramTop.sv",
    """
    |module datacache_sramTop #(
    |    parameter IFILE_IN = ""
    |)(
    |  input logic clk_i,
    |  input logic rst_i,
    |
    |  // sram interface in
    |  input logic csb_i,
    |  input logic [12:0] addr_i,
    |  input logic [147:0] wdata_i,
    |  input logic [3:0] wmask_i,
    |  input logic we_i,
    |  output logic [31:0] rdata_o
    |);
    |
    |  logic csb;
    |  logic [12:0] addr_o;
    |  logic [147:0] wdata_o;
    |  logic [3:0] wmask_o;
    |  logic we_o;
    |  logic [31:0] rdata_i;
    |
    |  logic rvalid;
    |
    |  always_ff @(negedge clk_i or posedge rst_i) begin
    |    if (rst_i) begin
    |      csb <= '1;
    |      addr_o <= '0;
    |      wdata_o <= '0;
    |      wmask_o <= '0;
    |      we_o <= '1;
    |    end else begin
    |      csb <= csb_i;
    |      addr_o <= addr_i;
    |      wdata_o <= wdata_i;
    |      wmask_o <= wmask_i;
    |      we_o <= we_i;
    |    end
    |  end
    |
    |  datacache_sram #(
    |    .NUM_WMASKS (4),
    |    .DATA_WIDTH (32),
    |    .ADDR_WIDTH (11),
    |    .RAM_DEPTH (1 << 11),
    |    .DELAY (3),
    |    .IZERO (0),
    |    .IFILE (IFILE_IN)
    |  ) memory (
    |    .clk0(clk_i),
    |    .csb0(csb_i),
    |    .web0(we_i),
    |    .wmask0(wmask_i),
    |    .addr0(addr_i),
    |    .din0(wdata_i),
    |    .dout0(rdata_o),
    |    .clk1('0),
    |    .csb1('1),
    |    .addr1('0),
    |    .dout1()
    |  );
    |
    |  always_ff @(posedge clk_i or posedge rst_i) begin
    |    if (rst_i) begin
    |      rvalid <= 1'b0;
    |    end else if (!we_i) begin
    |      rvalid <= 1'b0;
    |    end else if (!csb_i && we_i) begin
    |      rvalid <= 1'b1;
    |    end
    |  end
    |
    |endmodule
    """.stripMargin)
}
