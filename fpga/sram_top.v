// SPDX-License-Identifier: Apache-2.0
// ============================================================================
// File: fpga/sram_top.v
// Description: SRAM Top Module with Memory Address Decoder (32 KB SRAM + 150 KB Framebuffer BRAM + UART MMIO)
// ============================================================================

`timescale 1ns / 1ps

module sram_top #(
    parameter IFILE_IN = "pong.hex"
)
(
    input  wire        clk_i,
    input  wire        clk_pixel_i, // 25 MHz pixel clock for framebuffer reads
    input  wire        rst_i,

    // CPU SRAM interface
    input  wire        csb_i,      // Active low chip select
    input  wire [31:0] addr_i,     // Full 32-bit CPU memory address
    input  wire [31:0] wdata_i,    // Write data
    input  wire [3:0]  wmask_i,    // Byte write masks
    input  wire        we_i,       // Active low write enable (0=write, 1=read)
    output wire [31:0] rdata_o,    // Read data

    // Framebuffer Read Port for HDMI Controller
    input  wire [15:0] fb_read_addr,
    output wire [15:0] fb_pixel_data,

    // UART Hardware Ports
    input  wire [7:0]  uart_rx_byte,
    input  wire        uart_rx_dv,
    output reg  [7:0]  uart_tx_byte,
    output reg         uart_tx_dv
);

    // Address decode (used by SRAM gating and framebuffer)
    wire is_fb = (addr_i >= 32'h0000_4000 && addr_i <= 32'h0000_9FFF);
    wire is_uart_addr = (addr_i == 32'h0001_0000);

    // ------------------------------------------------------------------------
    // 1. 32 KB Instruction/Data SRAM (Address Range 0x0000_0000 - 0x0000_7FFF byte = 0x0000 - 0x1FFF word)
    // ------------------------------------------------------------------------
    wire [31:0] sram_rdata_raw;
    wire [12:0] sram_addr = addr_i[12:0]; // Direct word address (8192 x 32-bit)
    wire sram_csb_gated = csb_i | is_fb | is_uart_addr;

    sram #(
        .NUM_WMASKS (4),
        .DATA_WIDTH (32),
        .ADDR_WIDTH (13),
        .RAM_DEPTH  (8192),
        .DELAY      (3),
        .IZERO      (0),
        .IFILE      (IFILE_IN)
    ) memory (
        .clk0   (clk_i),
        .csb0   (sram_csb_gated),
        .web0   (we_i),
        .wmask0 (wmask_i),
        .addr0  (sram_addr),
        .din0   (wdata_i),
        .dout0  (sram_rdata_raw),
        .clk1   (1'b0),
        .csb1   (1'b1),
        .addr1  (13'b0),
        .dout1  ()
    );

    // ------------------------------------------------------------------------
    // 2. 96 KB Dual-Port Framebuffer BRAM (256x192 RGB565)
    // Byte range: 0x0001_0000 to 0x0002_7FFF -> Word range: 0x0000_4000 to 0x0000_9FFF
    // Split into even (fb0) and odd (fb1) pixel banks for clean BRAM inference
    // ------------------------------------------------------------------------
    (* ram_style = "block" *) reg [15:0] framebuffer0 [0:24575];
    (* ram_style = "block" *) reg [15:0] framebuffer1 [0:24575];

    integer fb_init_i;
    initial begin
        for (fb_init_i = 0; fb_init_i < 24576; fb_init_i = fb_init_i + 1) begin
            framebuffer0[fb_init_i] = 16'h001F; // Blue background default
            framebuffer1[fb_init_i] = 16'h001F; // Blue background default
        end
    end

    // Port A: CPU Write
    wire is_fb_write = (!csb_i) && (!we_i) && is_fb;
    wire [14:0] fb_word_idx = (addr_i[14:0] - 15'h4000);

    // Bank 0 (Even Pixel) CPU Write
    always @(posedge clk_i) begin
        if (is_fb_write) begin
            if (wmask_i[0] || wmask_i[1])
                framebuffer0[fb_word_idx] <= wdata_i[15:0];
        end
    end

    // Bank 1 (Odd Pixel) CPU Write
    always @(posedge clk_i) begin
        if (is_fb_write) begin
            if (wmask_i[2] || wmask_i[3])
                framebuffer1[fb_word_idx] <= wdata_i[31:16];
        end
    end

    // Port B: HDMI Scanout Read
    wire [14:0] read_word_idx = fb_read_addr[15:1];
    wire        read_is_odd   = fb_read_addr[0];

    reg [15:0] fb0_pixel_r;
    reg [15:0] fb1_pixel_r;
    reg        read_is_odd_r;

    always @(posedge clk_pixel_i) begin
        fb0_pixel_r   <= framebuffer0[read_word_idx];
        fb1_pixel_r   <= framebuffer1[read_word_idx];
        read_is_odd_r <= read_is_odd;
    end

    assign fb_pixel_data = read_is_odd_r ? fb1_pixel_r : fb0_pixel_r;

    // ------------------------------------------------------------------------
    // 3. UART MMIO Register (Byte 0x0004_0000 -> Word 0x0001_0000)
    // ------------------------------------------------------------------------
    wire is_uart = (!csb_i) && (addr_i == 32'h0001_0000);

    always @(posedge clk_i or posedge rst_i) begin
        if (rst_i) begin
            uart_tx_byte <= 8'd0;
            uart_tx_dv   <= 1'b0;
        end else begin
            uart_tx_dv <= 1'b0;
            if (is_uart && !we_i) begin
                uart_tx_byte <= wdata_i[7:0];
                uart_tx_dv   <= 1'b1;
            end
        end
    end

    // ------------------------------------------------------------------------
    // 4. UART RX Latch with Data-Ready Flag (bit 31)
    // ------------------------------------------------------------------------
    reg uart_rx_ready;
    reg [7:0] uart_rx_latch;

    always @(posedge clk_i or posedge rst_i) begin
        if (rst_i) begin
            uart_rx_ready <= 1'b0;
            uart_rx_latch <= 8'd0;
        end else if (uart_rx_dv) begin
            uart_rx_latch <= uart_rx_byte;
            uart_rx_ready <= 1'b1;
        end else if (is_uart_read_r) begin
            uart_rx_ready <= 1'b0;
        end
    end

    // ------------------------------------------------------------------------
    // 5. CPU Read Multiplexer (combinational — no extra latency)
    // ------------------------------------------------------------------------
    reg is_uart_read_r;
    always @(posedge clk_i) begin
        is_uart_read_r <= (!csb_i) && is_uart_addr && we_i;
    end

    assign rdata_o = is_uart_read_r ? {uart_rx_ready, 23'd0, uart_rx_latch} : sram_rdata_raw;

endmodule
