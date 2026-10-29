`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: uart_timer_peripheral
// Description: Memory-mapped UART (Terminal Keyboard + Debug Console)
//              and Hardware Millisecond Timer for NucleusRV.
//
// Memory Map (Offset from base 0x4000_0000):
//   0x00: UART_DATA   [7:0] Read: pop RX FIFO (keyboard); Write: push to TX
//   0x04: UART_STATUS [1:0] bit 0: rx_valid (key available), bit 1: tx_ready
//   0x10: TIMER_MS    [31:0] Read: elapsed milliseconds (for DG_GetTicksMs)
//   0x14: TIMER_CYC_L [31:0] Read: low 32 bits of 64-bit cycle counter
//   0x18: TIMER_CYC_H [31:0] Read: high 32 bits of 64-bit cycle counter
//////////////////////////////////////////////////////////////////////////////////

module uart_timer_peripheral #(
    parameter CLK_FREQ = 50000000,
    parameter BAUD_RATE = 115200,
    parameter FIFO_DEPTH = 64
)(
    input  wire        clk,
    input  wire        rst,

    // Decoupled Memory Request from Core
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

    // Physical UART Pins
    input  wire        rxd,
    output wire        txd,

    // Onboard Buttons & Switches
    input  wire [3:0]  btn_in,  // {BTN0, BTN3, BTN2, BTN1}
    input  wire [3:0]  sw_in    // SW[3:0]
);

    localparam CYCLES_PER_MS = CLK_FREQ / 1000;

    // -------------------------------------------------------------
    // 1. Hardware Timers
    // -------------------------------------------------------------
    reg [63:0] cycle_cnt = 64'd0;
    reg [31:0] ms_cnt    = 32'd0;
    reg [31:0] ms_subcnt = 32'd0;

    always @(posedge clk) begin
        if (rst) begin
            cycle_cnt <= 64'd0;
            ms_cnt    <= 32'd0;
            ms_subcnt <= 32'd0;
        end else begin
            cycle_cnt <= cycle_cnt + 64'd1;
            if (ms_subcnt >= CYCLES_PER_MS - 1) begin
                ms_subcnt <= 32'd0;
                ms_cnt    <= ms_cnt + 32'd1;
            end else begin
                ms_subcnt <= ms_subcnt + 32'd1;
            end
        end
    end

    // -------------------------------------------------------------
    // 2. UART Transmitter
    // -------------------------------------------------------------
    reg  [7:0] tx_byte = 8'd0;
    reg        tx_start = 1'b0;
    wire       tx_ready;

    uart_tx #(
        .CLK_FREQ(CLK_FREQ),
        .BAUD_RATE(BAUD_RATE)
    ) u_uart_tx (
        .clk(clk),
        .rst(rst),
        .tx_data(tx_byte),
        .tx_valid(tx_start),
        .tx_ready(tx_ready),
        .txd(txd)
    );

    // -------------------------------------------------------------
    // 3. UART Receiver & Keyboard FIFO
    // -------------------------------------------------------------
    wire [7:0] rx_byte;
    wire       rx_valid;

    uart_rx #(
        .CLK_FREQ(CLK_FREQ),
        .BAUD_RATE(BAUD_RATE)
    ) u_uart_rx (
        .clk(clk),
        .rst(rst),
        .rxd(rxd),
        .rx_data(rx_byte),
        .rx_valid(rx_valid)
    );

    // 64-Byte Circular FIFO Buffer for Incoming Keys
    reg [7:0] fifo_mem [0:FIFO_DEPTH-1];
    reg [5:0] fifo_wr_ptr = 6'd0;
    reg [5:0] fifo_rd_ptr = 6'd0;
    reg [6:0] fifo_count  = 7'd0;

    wire fifo_empty = (fifo_count == 7'd0);
    wire fifo_full  = (fifo_count == FIFO_DEPTH);
    wire [7:0] fifo_peek = fifo_mem[fifo_rd_ptr];

    // Read pop trigger
    reg fifo_pop = 1'b0;

    always @(posedge clk) begin
        if (rst) begin
            fifo_wr_ptr <= 6'd0;
            fifo_rd_ptr <= 6'd0;
            fifo_count  <= 7'd0;
        end else begin
            // Push incoming byte from UART
            if (rx_valid && !fifo_full) begin
                fifo_mem[fifo_wr_ptr] <= rx_byte;
                fifo_wr_ptr <= fifo_wr_ptr + 6'd1;
            end

            // Pop byte requested by CPU read
            if (fifo_pop && !fifo_empty) begin
                fifo_rd_ptr <= fifo_rd_ptr + 6'd1;
            end

            // Track count
            if ((rx_valid && !fifo_full) && !(fifo_pop && !fifo_empty)) begin
                fifo_count <= fifo_count + 7'd1;
            end else if (!(rx_valid && !fifo_full) && (fifo_pop && !fifo_empty)) begin
                fifo_count <= fifo_count - 7'd1;
            end
        end
    end

    // -------------------------------------------------------------
    // 4. Memory-Mapped Register Interface & Handshake
    // -------------------------------------------------------------
    localparam STATE_READY = 1'b0;
    localparam STATE_RESP  = 1'b1;
    reg bus_state = STATE_READY;

    wire [7:0] reg_offset = req_addr[7:0];

    always @(posedge clk) begin
        if (rst) begin
            bus_state <= STATE_READY;
            req_ready <= 1'b1;
            rsp_valid <= 1'b0;
            rsp_rdata <= 32'd0;
            tx_start  <= 1'b0;
            fifo_pop  <= 1'b0;
        end else begin
            tx_start <= 1'b0;
            fifo_pop <= 1'b0;

            case (bus_state)
                STATE_READY: begin
                    req_ready <= 1'b1;
                    if (req_valid && req_ready) begin
                        req_ready <= 1'b0;
                        bus_state <= STATE_RESP;
                        rsp_valid <= 1'b1;

                        if (req_is_write) begin
                            // WRITE
                            case (reg_offset)
                                8'h00: begin // UART_DATA TX
                                    tx_byte  <= req_wdata[7:0];
                                    tx_start <= 1'b1;
                                end
                                default: ;
                            endcase
                            rsp_rdata <= 32'd0;
                        end else begin
                            // READ
                            case (reg_offset)
                                8'h00: begin // UART_DATA RX (pop key)
                                    rsp_rdata <= {24'd0, fifo_peek};
                                    if (!fifo_empty) fifo_pop <= 1'b1;
                                end
                                8'h04: begin // UART_STATUS: [0]=rx_valid, [1]=tx_ready
                                    rsp_rdata <= {30'd0, tx_ready, !fifo_empty};
                                end
                                8'h08: begin // BUTTONS: [0]=BTN1 [1]=BTN2 [2]=BTN3 [3]=BTN0
                                    rsp_rdata <= {28'd0, btn_in};
                                end
                                8'h0C: begin // SWITCHES: [3:0] = SW[3:0]
                                    rsp_rdata <= {28'd0, sw_in};
                                end
                                8'h10: begin // TIMER_MS
                                    rsp_rdata <= ms_cnt;
                                end
                                8'h14: begin // TIMER_CYC_L
                                    rsp_rdata <= cycle_cnt[31:0];
                                end
                                8'h18: begin // TIMER_CYC_H
                                    rsp_rdata <= cycle_cnt[63:32];
                                end
                                default: rsp_rdata <= 32'hDEADBEEF;
                            endcase
                        end
                    end
                end

                STATE_RESP: begin
                    if (rsp_valid && rsp_ready) begin
                        rsp_valid <= 1'b0;
                        req_ready <= 1'b1;
                        bus_state <= STATE_READY;
                    end
                end
            endcase
        end
    end

endmodule
