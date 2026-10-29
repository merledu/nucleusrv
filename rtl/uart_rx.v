`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: uart_rx
// Description: Standard 8-N-1 UART receiver with midpoint sampling
//////////////////////////////////////////////////////////////////////////////////

module uart_rx #(
    parameter CLK_FREQ = 50000000,
    parameter BAUD_RATE = 115200
)(
    input  wire       clk,
    input  wire       rst,
    input  wire       rxd,
    output reg  [7:0] rx_data,
    output reg        rx_valid
);

    localparam CLKS_PER_BIT = CLK_FREQ / BAUD_RATE;

    localparam STATE_IDLE  = 2'd0;
    localparam STATE_START = 2'd1;
    localparam STATE_DATA  = 2'd2;
    localparam STATE_STOP  = 2'd3;

    // Double-flop synchronizer for RX line
    reg [2:0] rxd_sync = 3'b111;
    always @(posedge clk) begin
        rxd_sync <= {rxd_sync[1:0], rxd};
    end
    wire rxd_clean = rxd_sync[2];

    reg [1:0]  state = STATE_IDLE;
    reg [31:0] clk_cnt = 32'd0;
    reg [2:0]  bit_idx = 3'd0;
    reg [7:0]  data_buf = 8'd0;

    always @(posedge clk) begin
        if (rst) begin
            state    <= STATE_IDLE;
            clk_cnt  <= 16'd0;
            bit_idx  <= 3'd0;
            data_buf <= 8'd0;
            rx_data  <= 8'd0;
            rx_valid <= 1'b0;
        end else begin
            rx_valid <= 1'b0; // Default single-cycle pulse

            case (state)
                STATE_IDLE: begin
                    clk_cnt <= 16'd0;
                    bit_idx <= 3'd0;
                    if (rxd_clean == 1'b0) begin // Falling edge / Start bit detected
                        state <= STATE_START;
                    end
                end

                STATE_START: begin
                    // Sample at the middle of the start bit
                    if (clk_cnt == (CLKS_PER_BIT / 2)) begin
                        if (rxd_clean == 1'b0) begin
                            clk_cnt <= 16'd0;
                            state   <= STATE_DATA;
                        end else begin
                            state <= STATE_IDLE; // Glitch, return to idle
                        end
                    end else begin
                        clk_cnt <= clk_cnt + 16'd1;
                    end
                end

                STATE_DATA: begin
                    if (clk_cnt < CLKS_PER_BIT - 1) begin
                        clk_cnt <= clk_cnt + 16'd1;
                    end else begin
                        clk_cnt           <= 16'd0;
                        data_buf[bit_idx] <= rxd_clean;
                        if (bit_idx < 3'd7) begin
                            bit_idx <= bit_idx + 3'd1;
                        end else begin
                            bit_idx <= 3'd0;
                            state   <= STATE_STOP;
                        end
                    end
                end

                STATE_STOP: begin
                    // Wait for stop bit
                    if (clk_cnt < CLKS_PER_BIT - 1) begin
                        clk_cnt <= clk_cnt + 16'd1;
                    end else begin
                        clk_cnt  <= 16'd0;
                        rx_data  <= data_buf;
                        rx_valid <= (rxd_clean == 1'b1); // Validate stop bit
                        state    <= STATE_IDLE;
                    end
                end

                default: state <= STATE_IDLE;
            endcase
        end
    end

endmodule
