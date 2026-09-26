// ============================================================================
// File: fpga/zybo_nrv_top.v
// Module: zybo_nrv_top
// Description: Top-level FPGA wrapper for NucleusRV Pong on Zybo Z7.
//              Uses OSERDESE2 HDMI output for reliable display.
// ============================================================================

`timescale 1ns / 1ps

module zybo_nrv_top (
    input  wire       clk,             // 125 MHz onboard oscillator
    input  wire       btn_rst,         // Reset button (Active High)
    input  wire       btn_up,          // Pmod JE je[1]: paddle up (active-high)
    input  wire       btn_dn,          // Pmod JE je[2]: paddle down (active-high)
    // HDMI Output Ports
    output wire       hdmi_tx_clk_p,
    output wire       hdmi_tx_clk_n,
    output wire [2:0] hdmi_tx_p,
    output wire [2:0] hdmi_tx_n,
    output wire       hdmi_out_en,     // HDMI buffer enable pin (Zybo Z7)
    // Diagnostic LEDs
    output wire [3:0] led
);

    assign hdmi_out_en = 1'b1;

    // ------------------------------------------------------------------------
    // 1. Clock Generation
    // ------------------------------------------------------------------------
    wire clk25MHz;   // 25 MHz pixel clock
    wire clk_5x;     // 125 MHz TMDS 5x clock (for OSERDESE2 DDR)
    wire clk_cpu;    // 10 MHz CPU clock
    wire locked;

    clk_wiz_0 u_clk_wiz (
        .clk_in1  (clk),
        .reset    (btn_rst),
        .clk_out1 (clk25MHz),
        .clk_out2 (clk_5x),
        .clk_out3 (clk_cpu),
        .locked   (locked)
    );

    wire rst = !locked || btn_rst;

    // Framebuffer signals
    wire [15:0] fb_read_addr;
    wire [15:0] fb_pixel_data;

    // ------------------------------------------------------------------------
    // 2. Button-Based Paddle Control (Pmod JE: je[1]=up, je[2]=down)
    // ------------------------------------------------------------------------
    reg [2:0] btn_up_sync = 3'b0;
    reg [2:0] btn_dn_sync = 3'b0;

    always @(posedge clk_cpu) begin
        btn_up_sync <= {btn_up_sync[1:0], btn_up};
        btn_dn_sync <= {btn_dn_sync[1:0], btn_dn};
    end

    reg [18:0] repeat_cnt = 0;
    reg [7:0]  game_rx_byte = 0;
    reg        game_rx_dv = 0;

    always @(posedge clk_cpu) begin
        game_rx_dv <= 1'b0;
        if (rst) begin
            repeat_cnt <= 0;
        end else if (btn_up_sync[2] || btn_dn_sync[2]) begin
            if (repeat_cnt == 0) begin
                game_rx_byte <= btn_up_sync[2] ? 8'h77 : 8'h73;
                game_rx_dv <= 1'b1;
                repeat_cnt <= 19'd300_000;
            end else begin
                repeat_cnt <= repeat_cnt - 1;
            end
        end else begin
            repeat_cnt <= 0;
        end
    end

    // ------------------------------------------------------------------------
    // 4. NucleusRV Core Instance
    // ------------------------------------------------------------------------
    wire [31:0] core_pin;

    Top u_nucleusrv (
        .clock(clk_cpu),
        .clk_pixel(clk25MHz),
        .reset(rst),
        .io_pin(core_pin),
        .fb_read_addr(fb_read_addr),
        .fb_pixel_data(fb_pixel_data),
        .uart_rx_byte(game_rx_byte),
        .uart_rx_dv(game_rx_dv),
        .uart_tx_byte(),
        .uart_tx_dv()
    );

    // ------------------------------------------------------------------------
    // 5. VGA Video Timing Generator (640x480 @ 60Hz)
    // ------------------------------------------------------------------------
    wire [9:0] pixel_x;
    wire [9:0] pixel_y;
    wire       video_active;
    wire       hsync;
    wire       vsync;

    vga_timing u_vga_timing (
        .clk(clk25MHz),
        .rst(rst),
        .pixel_x(pixel_x),
        .pixel_y(pixel_y),
        .video_active(video_active),
        .hsync(hsync),
        .vsync(vsync)
    );

    // ------------------------------------------------------------------------
    // 6. Framebuffer Read + RGB Conversion (with pipeline alignment)
    // ------------------------------------------------------------------------
    // Stage 0 (combinational): compute framebuffer address from pixel coords
    wire in_fb_region = (pixel_x >= 10'd64 && pixel_x < 10'd576 &&
                         pixel_y >= 10'd48 && pixel_y < 10'd432);
    wire [7:0] fb_x = (pixel_x - 10'd64) >> 1;
    wire [7:0] fb_y = (pixel_y - 10'd48) >> 1;
    assign fb_read_addr = in_fb_region ? (fb_y * 16'd256 + fb_x) : 16'd0;

    // Stage 1 (registered): BRAM read takes 1 cycle, so pipeline the control signals
    reg video_active_d1 = 0;
    reg in_fb_region_d1 = 0;
    reg hsync_d1 = 1;
    reg vsync_d1 = 1;

    always @(posedge clk25MHz) begin
        video_active_d1 <= video_active;
        in_fb_region_d1 <= in_fb_region;
        hsync_d1        <= hsync;
        vsync_d1        <= vsync;
    end

    // Now fb_pixel_data and the _d1 signals are aligned (both 1-cycle delayed)
    wire is_visible = video_active_d1 && in_fb_region_d1;
    wire [7:0] red8   = is_visible ? {fb_pixel_data[15:11], fb_pixel_data[15:13]} : 8'h00;
    wire [7:0] green8 = is_visible ? {fb_pixel_data[10:5],  fb_pixel_data[10:9]}  : 8'h00;
    wire [7:0] blue8  = is_visible ? {fb_pixel_data[4:0],   fb_pixel_data[4:2]}   : 8'h00;

    // ------------------------------------------------------------------------
    // 7. HDMI Transmitter (OSERDESE2 based)
    // ------------------------------------------------------------------------
    hdmi_tx u_hdmi_tx (
        .pixclk         (clk25MHz),
        .clk_5x         (clk_5x),
        .rst            (rst),
        .red            (red8),
        .green          (green8),
        .blue           (blue8),
        .hsync          (hsync_d1),
        .vsync          (vsync_d1),
        .video_enable   (video_active_d1),
        .hdmi_tx_clk_p  (hdmi_tx_clk_p),
        .hdmi_tx_clk_n  (hdmi_tx_clk_n),
        .hdmi_tx_p      (hdmi_tx_p),
        .hdmi_tx_n      (hdmi_tx_n)
    );

    // Diagnostic Heartbeat
    reg [24:0] heartbeat = 25'd0;
    always @(posedge clk25MHz) heartbeat <= heartbeat + 1'b1;

    assign led[0] = locked;
    assign led[1] = heartbeat[24];
    assign led[2] = vsync;
    assign led[3] = video_active;

endmodule

// ============================================================================
// VGA Timing Generator (640x480 @ 60Hz with 25 MHz pixel clock)
// NEGATIVE sync polarity (standard for 640x480 DVI/HDMI)
// ============================================================================
module vga_timing (
    input  wire       clk,
    input  wire       rst,
    output reg  [9:0] pixel_x,
    output reg  [9:0] pixel_y,
    output wire       video_active,
    output wire       hsync,
    output wire       vsync
);
    localparam H_ACTIVE = 640, H_FRONT = 16, H_SYNC = 96, H_BACK = 48, H_TOTAL = 800;
    localparam V_ACTIVE = 480, V_FRONT = 10, V_SYNC = 2,  V_BACK = 33, V_TOTAL = 525;

    reg [9:0] h_cnt = 0;
    reg [9:0] v_cnt = 0;

    always @(posedge clk) begin
        if (rst) begin
            h_cnt <= 0;
            v_cnt <= 0;
        end else begin
            if (h_cnt == H_TOTAL - 1) begin
                h_cnt <= 0;
                if (v_cnt == V_TOTAL - 1) v_cnt <= 0;
                else v_cnt <= v_cnt + 1;
            end else begin
                h_cnt <= h_cnt + 1;
            end
        end
    end

    // NEGATIVE sync polarity: HIGH during active/blanking, LOW during sync pulse
    assign hsync = ~(h_cnt >= (H_ACTIVE + H_FRONT) && h_cnt < (H_ACTIVE + H_FRONT + H_SYNC));
    assign vsync = ~(v_cnt >= (V_ACTIVE + V_FRONT) && v_cnt < (V_ACTIVE + V_FRONT + V_SYNC));
    assign video_active = (h_cnt < H_ACTIVE) && (v_cnt < V_ACTIVE);

    always @(*) begin
        pixel_x = h_cnt;
        pixel_y = v_cnt;
    end
endmodule
