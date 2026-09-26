// ============================================================================
// File: fpga/hdmi_tx.v
// Module: hdmi_tx
// Description: HDMI Transmitter using Xilinx 7-Series OSERDESE2 primitives
//              for reliable 10:1 DDR TMDS serialization.
// ============================================================================

`timescale 1ns / 1ps

module hdmi_tx (
    input  wire       pixclk,          // 25 MHz pixel clock (CLKDIV for OSERDES)
    input  wire       clk_5x,          // 125 MHz 5x clock (CLK for OSERDES DDR)
    input  wire       rst,             // Active-high reset
    input  wire [7:0] red,
    input  wire [7:0] green,
    input  wire [7:0] blue,
    input  wire       hsync,
    input  wire       vsync,
    input  wire       video_enable,

    output wire       hdmi_tx_clk_p,
    output wire       hdmi_tx_clk_n,
    output wire [2:0] hdmi_tx_p,
    output wire [2:0] hdmi_tx_n
);

    // TMDS encode each channel
    wire [9:0] tmds_red, tmds_green, tmds_blue;

    tmds_encoder enc_b (
        .clk(pixclk), .rst(rst),
        .video_data(blue),
        .control_data({vsync, hsync}),
        .video_enable(video_enable),
        .tmds_out(tmds_blue)
    );

    tmds_encoder enc_g (
        .clk(pixclk), .rst(rst),
        .video_data(green),
        .control_data(2'b00),
        .video_enable(video_enable),
        .tmds_out(tmds_green)
    );

    tmds_encoder enc_r (
        .clk(pixclk), .rst(rst),
        .video_data(red),
        .control_data(2'b00),
        .video_enable(video_enable),
        .tmds_out(tmds_red)
    );

    // Serialize TMDS clock: constant pattern 1111100000 = 25 MHz from 125 MHz DDR
    wire tmds_clk_serial;
    tmds_oserdes u_ser_clk (
        .pixclk(pixclk), .clk_5x(clk_5x), .rst(rst),
        .tmds_data(10'b0000011111),
        .serial_out(tmds_clk_serial)
    );

    OBUFDS #(.IOSTANDARD("TMDS_33")) obufds_clk (
        .I(tmds_clk_serial), .O(hdmi_tx_clk_p), .OB(hdmi_tx_clk_n)
    );

    // Serialize TMDS data channels
    wire serial_blue, serial_green, serial_red;

    tmds_oserdes u_ser_b (
        .pixclk(pixclk), .clk_5x(clk_5x), .rst(rst),
        .tmds_data(tmds_blue),
        .serial_out(serial_blue)
    );

    tmds_oserdes u_ser_g (
        .pixclk(pixclk), .clk_5x(clk_5x), .rst(rst),
        .tmds_data(tmds_green),
        .serial_out(serial_green)
    );

    tmds_oserdes u_ser_r (
        .pixclk(pixclk), .clk_5x(clk_5x), .rst(rst),
        .tmds_data(tmds_red),
        .serial_out(serial_red)
    );

    OBUFDS #(.IOSTANDARD("TMDS_33")) obufds_d0 (
        .I(serial_blue), .O(hdmi_tx_p[0]), .OB(hdmi_tx_n[0])
    );
    OBUFDS #(.IOSTANDARD("TMDS_33")) obufds_d1 (
        .I(serial_green), .O(hdmi_tx_p[1]), .OB(hdmi_tx_n[1])
    );
    OBUFDS #(.IOSTANDARD("TMDS_33")) obufds_d2 (
        .I(serial_red), .O(hdmi_tx_p[2]), .OB(hdmi_tx_n[2])
    );

endmodule

// ============================================================================
// OSERDESE2 10:1 DDR Serializer (master-slave cascade)
// Accepts 10-bit parallel data in pixclk domain, outputs serial bit stream.
// ============================================================================
module tmds_oserdes (
    input  wire       pixclk,     // 25 MHz pixel clock (CLKDIV)
    input  wire       clk_5x,     // 125 MHz 5x clock (CLK, DDR → 250 Mbps)
    input  wire       rst,
    input  wire [9:0] tmds_data,  // 10-bit TMDS symbol (bit 0 = first transmitted)
    output wire       serial_out
);

    wire cascade_shift1, cascade_shift2;

    OSERDESE2 #(
        .DATA_RATE_OQ ("DDR"),
        .DATA_RATE_TQ ("SDR"),
        .DATA_WIDTH   (10),
        .SERDES_MODE  ("MASTER"),
        .TRISTATE_WIDTH(1),
        .TBYTE_CTL    ("FALSE"),
        .TBYTE_SRC    ("FALSE")
    ) master (
        .OFB      (),
        .OQ       (serial_out),
        .SHIFTOUT1(),
        .SHIFTOUT2(),
        .TBYTEOUT (),
        .TFB      (),
        .TQ       (),
        .CLK      (clk_5x),
        .CLKDIV   (pixclk),
        .D1       (tmds_data[0]),
        .D2       (tmds_data[1]),
        .D3       (tmds_data[2]),
        .D4       (tmds_data[3]),
        .D5       (tmds_data[4]),
        .D6       (tmds_data[5]),
        .D7       (tmds_data[6]),
        .D8       (tmds_data[7]),
        .OCE      (1'b1),
        .RST      (rst),
        .SHIFTIN1 (cascade_shift1),
        .SHIFTIN2 (cascade_shift2),
        .T1       (1'b0),
        .T2       (1'b0),
        .T3       (1'b0),
        .T4       (1'b0),
        .TBYTEIN  (1'b0),
        .TCE      (1'b0)
    );

    OSERDESE2 #(
        .DATA_RATE_OQ ("DDR"),
        .DATA_RATE_TQ ("SDR"),
        .DATA_WIDTH   (10),
        .SERDES_MODE  ("SLAVE"),
        .TRISTATE_WIDTH(1),
        .TBYTE_CTL    ("FALSE"),
        .TBYTE_SRC    ("FALSE")
    ) slave (
        .OFB      (),
        .OQ       (),
        .SHIFTOUT1(cascade_shift1),
        .SHIFTOUT2(cascade_shift2),
        .TBYTEOUT (),
        .TFB      (),
        .TQ       (),
        .CLK      (clk_5x),
        .CLKDIV   (pixclk),
        .D1       (1'b0),
        .D2       (1'b0),
        .D3       (tmds_data[8]),
        .D4       (tmds_data[9]),
        .D5       (1'b0),
        .D6       (1'b0),
        .D7       (1'b0),
        .D8       (1'b0),
        .OCE      (1'b1),
        .RST      (rst),
        .SHIFTIN1 (1'b0),
        .SHIFTIN2 (1'b0),
        .T1       (1'b0),
        .T2       (1'b0),
        .T3       (1'b0),
        .T4       (1'b0),
        .TBYTEIN  (1'b0),
        .TCE      (1'b0)
    );

endmodule
