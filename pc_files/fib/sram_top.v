/* verilator lint_off ASSIGNDLY */
/* verilator lint_off PINCONNECTEMPTY */
/* verilator lint_off WIDTH */
/* verilator lint_off UNUSED */
/* verilator lint_off SYNCASYNCNET */

module sram_top #(
    parameter IFILE_IN = ""
)
(
  input wire clk_i,
  input wire rst_i,

// sram interface in
  input  wire        csb_i,
  input  wire [27:0] addr_i,
  input  wire [31:0] wdata_i,
  input  wire [3:0]  wmask_i,
  input  wire        we_i,
  output wire [31:0] rdata_o

);

reg          csb;
reg  [12:0]  addr_o;
reg  [31:0]  wdata_o;
reg  [3:0]   wmask_o;
reg          we_o;
wire [31:0]  rdata_i;

reg  rvalid;

always @(negedge clk_i) begin
  if(rst_i) begin
    csb <= 1'b1;
    addr_o <= 13'b0;
    wdata_o <= 32'b0;
    wmask_o <= 4'b0;
    we_o <= 1'b1;
  end else begin
    csb <= csb_i;
    addr_o <= addr_i;
    wdata_o <= wdata_i;
    wmask_o <= wmask_i;
    we_o <= we_i;
  end
end

sram #(
  .NUM_WMASKS (4),
  .DATA_WIDTH (32),
  .ADDR_WIDTH (13),
  .RAM_DEPTH (1 << 13),
  // FIXME: This delay is arbitrary.
  .DELAY (3),
  .IZERO (0) , // binary / Initial RAM with zeros (has priority over INITFILE)
  .IFILE (IFILE_IN)
 ) memory (
/*`ifdef USE_POWER_PINS
	.vdd,
	.gnd,
`endif */
    .clk0(clk_i),
    .csb0(csb_i),
    .web0(we_i),
    .wmask0(wmask_i),
    .addr0(addr_i),
    .din0(wdata_i),
    .dout0(rdata_o),
    .clk1(1'b0),
    .csb1(1'b1),
    .addr1(13'b0),
    .dout1()
 );

always @(posedge clk_i or posedge rst_i) begin
    if (rst_i) begin
     rvalid <= 1'b0;
    end else if (!we_i) begin
     rvalid <= 1'b0;
    end else if(!csb_i && we_i) begin
     rvalid <= 1'b1;
    end
end

endmodule
