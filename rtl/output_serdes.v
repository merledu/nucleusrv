`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: output_serdes
// Description: 10:1 TMDS Serializer using Xilinx 7-Series OSERDESE2 Primitives
//              in Master/Slave 5:1 DDR cascade (Digilent rgb2dvi standard).
//              Provides zero-jitter, pin-matched hardware TMDS serialization.
//////////////////////////////////////////////////////////////////////////////////

module output_serdes (
    input  wire       pixel_clk,   // 25.0 MHz Pixel Clock (CLKDIV)
    input  wire       serial_clk,  // 125.0 MHz Serial Clock (5x Pixel Clock, CLK)
    input  wire       rst,
    input  wire [9:0] data_in,     // 10-bit TMDS word (LSB transmitted first)
    output wire       data_out_p,  // TMDS positive differential output
    output wire       data_out_n   // TMDS negative differential output
);

`ifdef VERILATOR
    // Behavioral simulation model for Verilator
    /* verilator lint_off UNUSEDSIGNAL */
    wire _unused_signals = &{1'b0, pixel_clk, serial_clk, rst, data_in[9:1]};
    /* verilator lint_on UNUSEDSIGNAL */

    assign data_out_p = data_in[0];
    assign data_out_n = ~data_in[0];

`else
    // Hardware implementation for Xilinx 7-Series (OSERDESE2 Master/Slave Cascade)
    wire s_data_out;
    wire ocascade1, ocascade2;

    // DVI transmits LSB first (data_in[0] .. data_in[9])
    // OSERDESE2 transmits D1 first in DDR mode
    OSERDESE2 #(
        .DATA_RATE_OQ      ("DDR"),
        .DATA_RATE_TQ      ("SDR"),
        .DATA_WIDTH        (10),
        .TRISTATE_WIDTH    (1),
        .TBYTE_CTL         ("FALSE"),
        .TBYTE_SRC         ("FALSE"),
        .SERDES_MODE       ("MASTER")
    ) oserdes_master (
        .OFB               (),
        .OQ                (s_data_out),
        .SHIFTOUT1         (),
        .SHIFTOUT2         (),
        .TBYTEOUT          (),
        .TFB               (),
        .TQ                (),
        .CLK               (serial_clk), // 125 MHz high-speed DDR clock
        .CLKDIV            (pixel_clk),  // 25 MHz divided parallel clock
        .D1                (data_in[0]),
        .D2                (data_in[1]),
        .D3                (data_in[2]),
        .D4                (data_in[3]),
        .D5                (data_in[4]),
        .D6                (data_in[5]),
        .D7                (data_in[6]),
        .D8                (data_in[7]),
        .OCE               (1'b1),
        .RST               (rst),
        .SHIFTIN1          (ocascade1),
        .SHIFTIN2          (ocascade2),
        .T1                (1'b0),
        .T2                (1'b0),
        .T3                (1'b0),
        .T4                (1'b0),
        .TBYTEIN           (1'b0),
        .TCE               (1'b0)
    );

    OSERDESE2 #(
        .DATA_RATE_OQ      ("DDR"),
        .DATA_RATE_TQ      ("SDR"),
        .DATA_WIDTH        (10),
        .TRISTATE_WIDTH    (1),
        .TBYTE_CTL         ("FALSE"),
        .TBYTE_SRC         ("FALSE"),
        .SERDES_MODE       ("SLAVE")
    ) oserdes_slave (
        .OFB               (),
        .OQ                (),
        .SHIFTOUT1         (ocascade1),
        .SHIFTOUT2         (ocascade2),
        .TBYTEOUT          (),
        .TFB               (),
        .TQ                (),
        .CLK               (serial_clk),
        .CLKDIV            (pixel_clk),
        .D1                (1'b0),
        .D2                (1'b0),
        .D3                (data_in[8]),
        .D4                (data_in[9]),
        .D5                (1'b0),
        .D6                (1'b0),
        .D7                (1'b0),
        .D8                (1'b0),
        .OCE               (1'b1),
        .RST               (rst),
        .SHIFTIN1          (1'b0),
        .SHIFTIN2          (1'b0),
        .T1                (1'b0),
        .T2                (1'b0),
        .T3                (1'b0),
        .T4                (1'b0),
        .TBYTEIN           (1'b0),
        .TCE               (1'b0)
    );

    // Xilinx 7-Series Differential TMDS Output Buffer
    OBUFDS #(
        .IOSTANDARD("TMDS_33")
    ) obufds_inst (
        .I (s_data_out),
        .O (data_out_p),
        .OB(data_out_n)
    );
`endif

endmodule
