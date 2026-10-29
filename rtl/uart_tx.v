`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: uart_tx
// Description: Standard 8-N-1 UART transmitter with configurable baud divider
//////////////////////////////////////////////////////////////////////////////////

module uart_tx #(
    parameter CLK_FREQ = 50000000,
    parameter BAUD_RATE = 115200
)(
    input  wire       clk,
    input  wire       rst,
    input  wire [7:0] tx_data,
    input  wire       tx_valid,
    output reg        tx_ready,
    output reg        txd
);

    localparam CLKS_PER_BIT = CLK_FREQ / BAUD_RATE;

    localparam STATE_IDLE  = 2'd0;
    localparam STATE_START = 2'd1;
    localparam STATE_DATA  = 2'd2;
    localparam STATE_STOP  = 2'd3;

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
            tx_ready <= 1'b1;
            txd      <= 1'b1;
        end else begin
            case (state)
                STATE_IDLE: begin
                    txd      <= 1'b1;
                    clk_cnt  <= 16'd0;
                    bit_idx  <= 3'd0;
                    tx_ready <= 1'b1;
                    if (tx_valid) begin
                        data_buf <= tx_data;
                        tx_ready <= 1'b0;
                        state    <= STATE_START;
                    end
                end

                STATE_START: begin
                    txd <= 1'b0; // Start bit
                    if (clk_cnt < CLKS_PER_BIT - 1) begin
                        clk_cnt <= clk_cnt + 16'd1;
                    end else begin
                        clk_cnt <= 16'd0;
                        state   <= STATE_DATA;
                    end
                end

                STATE_DATA: begin
                    txd <= data_buf[bit_idx];
                    if (clk_cnt < CLKS_PER_BIT - 1) begin
                        clk_cnt <= clk_cnt + 16'd1;
                    end else begin
                        clk_cnt <= 16'd0;
                        if (bit_idx < 3'd7) begin
                            bit_idx <= bit_idx + 3'd1;
                        end else begin
                            bit_idx <= 3'd0;
                            state   <= STATE_STOP;
                        end
                    end
                end

                STATE_STOP: begin
                    txd <= 1'b1; // Stop bit
                    if (clk_cnt < CLKS_PER_BIT - 1) begin
                        clk_cnt <= clk_cnt + 16'd1;
                    end else begin
                        clk_cnt  <= 16'd0;
                        tx_ready <= 1'b1;
                        state    <= STATE_IDLE;
                    end
                end

                default: state <= STATE_IDLE;
            endcase
        end
    end

endmodule
