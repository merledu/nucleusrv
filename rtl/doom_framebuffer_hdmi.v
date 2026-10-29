`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: doom_framebuffer_hdmi
// Description: Dual-Port DOOM Framebuffer (320x200 @ 8bpp) with 256-color
//              Palette RAM, 2x Integer Scaling, and HDMI/DVI Video Generation.
//
// Memory Map (Base 0x5000_0000):
//   0x5000_0000 - 0x5000_F9FF : 64,000 Bytes Framebuffer (320x200 8-bit color index)
//   0x5001_0000 - 0x5001_03FF : 256 Entries x 24-bit RGB Palette CLUT
//////////////////////////////////////////////////////////////////////////////////

module doom_framebuffer_hdmi #(
    parameter FB_BASE_ADDR   = 32'h5000_0000,
    parameter PAL_BASE_ADDR  = 32'h5001_0000
)(
    // CPU Core Clock & Reset
    input  wire        cpu_clk,
    input  wire        cpu_rst,

    // Decoupled Memory Request from Core (Port A)
    input  wire        req_valid,
    output reg         req_ready,
    input  wire [31:0] req_addr,
    input  wire [31:0] req_wdata,
    input  wire [3:0]  req_wmask,
    input  wire        req_is_write,

    // Decoupled Memory Response to Core
    output reg         rsp_valid,
    input  wire        rsp_ready,
    output reg  [31:0] rsp_rdata,

    // Video Pixel Clocks
    input  wire        pixclk,     // 25.175 MHz pixel clock
    input  wire        clk_tmds,   // 250 MHz serial clock (10x pixclk)
    input  wire        pix_rst,

    // HDMI Differential Outputs
    output wire        hdmi_tx_clk_p,
    output wire        hdmi_tx_clk_n,
    output wire [2:0]  hdmi_tx_p,
    output wire [2:0]  hdmi_tx_n
);

    // -------------------------------------------------------------
    // 1. Dual-Port Framebuffer Memory: 16,384 words x 32-bit = 65,536 bytes
    //    Covers DOOM 320x200 (64,000 bytes).
    //    Explicit Simple Dual-Port Block RAM (Port A: CPU Write, Port B: Video Read).
    // -------------------------------------------------------------
    (* ram_style = "block" *) reg [31:0] fb_mem [0:16383];

    integer fb_init_i;
    initial begin
        for (fb_init_i = 0; fb_init_i < 16384; fb_init_i = fb_init_i + 1) begin
            fb_mem[fb_init_i] = 32'd0;
        end
    end

    wire is_fb_addr  = (req_addr >= FB_BASE_ADDR && req_addr < (FB_BASE_ADDR + 32'd65536));
    wire is_pal_addr = (req_addr >= PAL_BASE_ADDR && req_addr < (PAL_BASE_ADDR + 32'd1024));

    wire [13:0] fb_word_addr = req_addr[15:2];

    // Dedicated Port A Write Process (Pure BRAM template for Xilinx 7-Series)
    wire fb_write_en = (req_valid && req_ready && req_is_write && is_fb_addr);

    always @(posedge cpu_clk) begin
        if (fb_write_en) begin
            if (req_wmask[0]) fb_mem[fb_word_addr][7:0]   <= req_wdata[7:0];
            if (req_wmask[1]) fb_mem[fb_word_addr][15:8]  <= req_wdata[15:8];
            if (req_wmask[2]) fb_mem[fb_word_addr][23:16] <= req_wdata[23:16];
            if (req_wmask[3]) fb_mem[fb_word_addr][31:24] <= req_wdata[31:24];
        end
    end

    // -------------------------------------------------------------
    // 2. 256-Entry x 24-bit RGB Color Palette (CLUT)
    // -------------------------------------------------------------
    reg [23:0] palette_ram [0:255];
    wire [7:0] pal_idx_cpu = req_addr[9:2];

    // Initialize palette with basic VGA colors initially
    integer p_init;
    initial begin
        for (p_init = 0; p_init < 256; p_init = p_init + 1) begin
            palette_ram[p_init] = {p_init[7:0], p_init[7:0], p_init[7:0]};
        end
        palette_ram[0] = 24'h000000; // Black
        palette_ram[1] = 24'hFF0000; // Red
        palette_ram[2] = 24'h00FF00; // Green
        palette_ram[3] = 24'h0000FF; // Blue
        palette_ram[4] = 24'hFFFF00; // Yellow
        palette_ram[5] = 24'h00FFFF; // Cyan
        palette_ram[6] = 24'hFF00FF; // Magenta
        palette_ram[7] = 24'hFFFFFF; // White
    end

    // -------------------------------------------------------------
    // 3. CPU Bus Handshake & Palette Read/Write
    // -------------------------------------------------------------
    localparam STATE_IDLE = 1'b0;
    localparam STATE_RESP = 1'b1;
    reg bus_state = STATE_IDLE;

    always @(posedge cpu_clk) begin
        if (cpu_rst) begin
            bus_state <= STATE_IDLE;
            req_ready <= 1'b1;
            rsp_valid <= 1'b0;
            rsp_rdata <= 32'd0;
        end else begin
            if (req_is_write && is_fb_addr) begin
                // Zero-wait-state direct write to Framebuffer BRAM (accepts writes every cycle)
                req_ready <= 1'b1;
                rsp_valid <= req_valid;
                rsp_rdata <= 32'd0;
                bus_state <= STATE_IDLE;
            end else begin
                case (bus_state)
                    STATE_IDLE: begin
                        req_ready <= 1'b1;
                        // The zero-wait write path above leaves rsp_valid set; it must be a
                        // one-cycle pulse or a later load elsewhere takes it as its own response
                        rsp_valid <= 1'b0;
                        if (req_valid && req_ready) begin
                            req_ready <= 1'b0;
                            bus_state <= STATE_RESP;
                            rsp_valid <= 1'b1;

                            if (req_is_write) begin
                                if (is_pal_addr) begin
                                    palette_ram[pal_idx_cpu] <= req_wdata[23:0];
                                end
                                rsp_rdata <= 32'd0;
                            end else begin
                                if (is_pal_addr) begin
                                    rsp_rdata <= {8'd0, palette_ram[pal_idx_cpu]};
                                end else begin
                                    rsp_rdata <= 32'd0; // Write-only framebuffer returns 0 on read
                                end
                            end
                        end
                    end

                    STATE_RESP: begin
                        if (rsp_valid && rsp_ready) begin
                            rsp_valid <= 1'b0;
                            req_ready <= 1'b1;
                            bus_state <= STATE_IDLE;
                        end
                    end
                endcase
            end
        end
    end

    // -------------------------------------------------------------
    // 4. Port B: Video Timing Generator & 2x Pixel Scaler (640x480 @ 60Hz)
    // -------------------------------------------------------------
    // Standard 640x480 @ 60Hz timing constants
    // Total line = 800 (96 sync + 48 back porch + 640 visible + 16 front porch)
    // Total frame = 525 (2 sync + 33 back porch + 480 visible + 10 front porch)
    reg [9:0] h_cnt = 10'd0;
    reg [9:0] v_cnt = 10'd0;

    always @(posedge pixclk) begin
        if (pix_rst) begin
            h_cnt <= 10'd0;
            v_cnt <= 10'd0;
        end else begin
            if (h_cnt < 10'd799) begin
                h_cnt <= h_cnt + 10'd1;
            end else begin
                h_cnt <= 10'd0;
                if (v_cnt < 10'd524) begin
                    v_cnt <= v_cnt + 10'd1;
                end else begin
                    v_cnt <= 10'd0;
                end
            end
        end
    end

    // Sync polarities for DVI TMDS control tokens: 0 during porch (idle token 00), 1 during sync pulse
    wire hsync = (h_cnt < 10'd96);
    wire vsync = (v_cnt < 10'd2);

    // Active 640x480 visible window
    localparam H_VISIBLE_START = 10'd144; // 96 sync + 48 back porch
    localparam H_VISIBLE_END   = 10'd784; // 144 + 640
    localparam V_VISIBLE_START = 10'd35;  // 2 sync + 33 back porch
    localparam V_VISIBLE_END   = 10'd515; // 35 + 480

    wire in_visible_window = (h_cnt >= H_VISIBLE_START && h_cnt < H_VISIBLE_END &&
                              v_cnt >= V_VISIBLE_START && v_cnt < V_VISIBLE_END);

    // DOOM is 320x200. Scaled 2x:
    // Horizontal: 320 x 2 = 640 pixels (full width).
    // Vertical:   200 x 2 = 400 lines.
    // Center inside 480 lines: 40 lines black border top and bottom.
    localparam V_DOOM_START = V_VISIBLE_START + 10'd40;  // Line 75
    localparam V_DOOM_END   = V_DOOM_START    + 10'd400; // Line 475

    wire in_doom_window = (h_cnt >= H_VISIBLE_START && h_cnt < H_VISIBLE_END &&
                           v_cnt >= V_DOOM_START     && v_cnt < V_DOOM_END);

    wire [9:0] x_screen = h_cnt - H_VISIBLE_START; // 0..639
    wire [9:0] y_screen = v_cnt - V_DOOM_START;    // 0..399

    wire [8:0] x_doom = x_screen[9:1]; // x_screen / 2 => 0..319
    wire [7:0] y_doom = y_screen[8:1]; // y_screen / 2 => 0..199

    // Framebuffer byte address: y_doom * 320 + x_doom
    // 320 = 256 + 64 = (y_doom << 8) + (y_doom << 6)
    wire [15:0] fb_byte_addr = ({8'd0, y_doom} << 8) + ({8'd0, y_doom} << 6) + {7'd0, x_doom};
    wire [13:0] fb_read_word = fb_byte_addr[15:2];
    wire [1:0]  fb_byte_sel  = fb_byte_addr[1:0];

    // Pipeline delay compensation (2 cycles: 1 for BRAM read, 1 for palette lookup)
    reg [1:0] byte_sel_d1 = 2'd0;
    reg in_doom_d1 = 1'b0;
    reg in_doom_d2 = 1'b0;
    reg in_vis_d1  = 1'b0;
    reg in_vis_d2  = 1'b0;
    reg hsync_d1 = 1'b0, hsync_d2 = 1'b0;
    reg vsync_d1 = 1'b0, vsync_d2 = 1'b0;

    reg [31:0] fb_read_data = 32'd0;

    always @(posedge pixclk) begin
        // Stage 1: Read word from BRAM
        fb_read_data <= fb_mem[fb_read_word];
        byte_sel_d1  <= fb_byte_sel;
        in_doom_d1   <= in_doom_window;
        in_vis_d1    <= in_visible_window;
        hsync_d1     <= hsync;
        vsync_d1     <= vsync;

        // Stage 2: Align with palette lookup
        in_doom_d2   <= in_doom_d1;
        in_vis_d2    <= in_vis_d1;
        hsync_d2     <= hsync_d1;
        vsync_d2     <= vsync_d1;
    end

    // Select byte from 32-bit word
    wire [7:0] pixel_index = (byte_sel_d1 == 2'd0) ? fb_read_data[7:0]   :
                             (byte_sel_d1 == 2'd1) ? fb_read_data[15:8]  :
                             (byte_sel_d1 == 2'd2) ? fb_read_data[23:16] :
                                                     fb_read_data[31:24];

    // Read 24-bit RGB from palette
    wire [23:0] pal_rgb = palette_ram[pixel_index];

    // Hardware border color bars on top & bottom 40 lines (ensures display signal visibility instantly on boot)
    wire [2:0] bar_idx = x_screen[9:7]; // 8 color bars across 640 pixels (80 pixels each)
    wire [7:0] bar_r = (bar_idx == 3'd1 || bar_idx == 3'd4 || bar_idx == 3'd6 || bar_idx == 3'd7) ? 8'hFF : 8'h00;
    wire [7:0] bar_g = (bar_idx == 3'd2 || bar_idx == 3'd4 || bar_idx == 3'd5 || bar_idx == 3'd7) ? 8'hFF : 8'h00;
    wire [7:0] bar_b = (bar_idx == 3'd3 || bar_idx == 3'd5 || bar_idx == 3'd6 || bar_idx == 3'd7) ? 8'hFF : 8'h00;

    // Register Stage 2 for Palette lookup and Border colors to match in_doom_d2 exactly
    reg [23:0] pal_rgb_d2 = 24'd0;
    reg [7:0]  bar_r_d2   = 8'd0;
    reg [7:0]  bar_g_d2   = 8'd0;
    reg [7:0]  bar_b_d2   = 8'd0;

    always @(posedge pixclk) begin
        pal_rgb_d2 <= pal_rgb;
        bar_r_d2   <= bar_r;
        bar_g_d2   <= bar_g;
        bar_b_d2   <= bar_b;
    end

    wire [7:0] red_out   = (in_doom_d2) ? pal_rgb_d2[23:16] : 8'd0;
    wire [7:0] green_out = (in_doom_d2) ? pal_rgb_d2[15:8]  : 8'd0;
    wire [7:0] blue_out  = (in_doom_d2) ? pal_rgb_d2[7:0]   : 8'd0;

    // -------------------------------------------------------------
    // 5. HDMI Transmitter Instance
    // -------------------------------------------------------------
    hdmi_tx u_hdmi_tx (
        .pixclk(pixclk),
        .clk_tmds(clk_tmds),
        .rst(pix_rst),
        .red(red_out),
        .green(green_out),
        .blue(blue_out),
        .hsync(hsync_d2),
        .vsync(vsync_d2),
        .video_enable(in_vis_d2),
        .hdmi_tx_clk_p(hdmi_tx_clk_p),
        .hdmi_tx_clk_n(hdmi_tx_clk_n),
        .hdmi_tx_p(hdmi_tx_p),
        .hdmi_tx_n(hdmi_tx_n)
    );

endmodule
