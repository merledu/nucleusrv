/* verilator lint_off ASSIGNDLY */
/* verilator lint_off PINCONNECTEMPTY */
/* verilator lint_off WIDTH */
/* verilator lint_off UNUSED */
module sram_top #(
    parameter IFILE_IN = ""
)(
    input logic clk_i,
    input logic rst_i,

    // sram interface in
    input   logic        csb_i,
    input   logic [11:0] addr_i,
    input   logic [63:0] wdata_i,  // Adjusted for 64-bit data width
    input   logic [7:0]  wmask_i,  // Adjusted for 64-bit data width (8 masks)
    input   logic        we_i,
    output  logic [63:0] rdata_o   // Adjusted for 64-bit data width
);

    logic        csb;
    logic [11:0] addr_o;
    logic [63:0] wdata_o; // Adjusted for 64-bit data width
    logic [7:0]  wmask_o; // Adjusted for 64-bit data width (8 masks)
    logic        we_o;
    logic [63:0] rdata_i; // Adjusted for 64-bit data width

    logic rvalid;

    always_ff @(negedge clk_i) begin
        if (rst_i) begin
            csb <= '1;
            addr_o <= '0;
            wdata_o <= '0;
            wmask_o <= '0;
            we_o <= '1;
        end else begin
            csb <= csb_i;
            addr_o <= addr_i;
            wdata_o <= wdata_i;
            wmask_o <= wmask_i;
            we_o <= we_i;
        end
    end

    sram #(
        .NUM_WMASKS (8),     // Adjusted for 64-bit data width (8 masks)
        .DATA_WIDTH (64),    // Adjusted for 64-bit data width
        .ADDR_WIDTH (13),
        .RAM_DEPTH (1 << 13),
        .DELAY (3),          // This delay is arbitrary and can be adjusted
    ) u_sram (
        .clk_i(clk_i),
        .rst_i(rst_i),
        .csb_i(csb),
        .addr_i(addr_o),
        .wdata_i(wdata_o),
        .wmask_i(wmask_o),
        .we_i(we_o),
        .rdata_o(rdata_i)
    );

endmodule

