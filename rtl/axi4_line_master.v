`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: axi4_line_master
// Description: AXI4 master issuing one INCR burst at a time (1..8 beats of 32 bits),
//              used by the caches for line refills / write-backs and by the data
//              cache for single-beat uncached accesses.
//
// Command:  cmd_valid/cmd_ready, cmd_write, cmd_addr (burst start), cmd_len (beats-1).
// Writes:   beat k's data/strobe are read combinationally from wr_data/wr_strb while
//           wr_idx == k (the caller muxes its line buffer with wr_idx).
// Reads:    each beat is presented for one cycle on rd_beat_valid with rd_idx/rd_data.
// done:     one-cycle pulse when the last read beat arrives or the write response
//           returns.
//////////////////////////////////////////////////////////////////////////////////

module axi4_line_master (
    input  wire        clk,
    input  wire        rst,

    input  wire        cmd_valid,
    output wire        cmd_ready,
    input  wire        cmd_write,
    input  wire [31:0] cmd_addr,
    input  wire [2:0]  cmd_len,

    output wire [2:0]  wr_idx,
    input  wire [31:0] wr_data,
    input  wire [3:0]  wr_strb,

    output wire        rd_beat_valid,
    output wire [2:0]  rd_idx,
    output wire [31:0] rd_data,

    output reg         done,

    // AXI4 master
    output reg  [31:0] m_axi_awaddr,
    output reg  [7:0]  m_axi_awlen,
    output wire [2:0]  m_axi_awsize,
    output wire [1:0]  m_axi_awburst,
    output wire [3:0]  m_axi_awcache,
    output wire [2:0]  m_axi_awprot,
    output reg         m_axi_awvalid,
    input  wire        m_axi_awready,
    output wire [31:0] m_axi_wdata,
    output wire [3:0]  m_axi_wstrb,
    output wire        m_axi_wlast,
    output reg         m_axi_wvalid,
    input  wire        m_axi_wready,
    input  wire [1:0]  m_axi_bresp,
    input  wire        m_axi_bvalid,
    output wire        m_axi_bready,
    output reg  [31:0] m_axi_araddr,
    output reg  [7:0]  m_axi_arlen,
    output wire [2:0]  m_axi_arsize,
    output wire [1:0]  m_axi_arburst,
    output wire [3:0]  m_axi_arcache,
    output wire [2:0]  m_axi_arprot,
    output reg         m_axi_arvalid,
    input  wire        m_axi_arready,
    input  wire [31:0] m_axi_rdata,
    input  wire [1:0]  m_axi_rresp,
    input  wire        m_axi_rlast,
    input  wire        m_axi_rvalid,
    output wire        m_axi_rready
);

    localparam S_IDLE  = 2'd0;
    localparam S_READ  = 2'd1;
    localparam S_WRITE = 2'd2;
    localparam S_BRESP = 2'd3;

    reg [1:0] state = S_IDLE;
    reg [2:0] beat  = 3'd0;
    reg [2:0] len   = 3'd0;

    assign cmd_ready = (state == S_IDLE);

    // Fixed burst attributes: 4-byte beats, incrementing, normal non-cacheable bufferable
    assign m_axi_awsize  = 3'b010;
    assign m_axi_awburst = 2'b01;
    assign m_axi_awcache = 4'b0011;
    assign m_axi_awprot  = 3'b000;
    assign m_axi_arsize  = 3'b010;
    assign m_axi_arburst = 2'b01;
    assign m_axi_arcache = 4'b0011;
    assign m_axi_arprot  = 3'b000;

    assign wr_idx       = beat;
    assign m_axi_wdata  = wr_data;
    assign m_axi_wstrb  = wr_strb;
    assign m_axi_wlast  = (beat == len);
    assign m_axi_bready = (state == S_BRESP);

    assign m_axi_rready  = (state == S_READ);
    assign rd_beat_valid = (state == S_READ) && m_axi_rvalid;
    assign rd_idx        = beat;
    assign rd_data       = m_axi_rdata;

    always @(posedge clk) begin
        if (rst) begin
            state         <= S_IDLE;
            beat          <= 3'd0;
            len           <= 3'd0;
            done          <= 1'b0;
            m_axi_awvalid <= 1'b0;
            m_axi_wvalid  <= 1'b0;
            m_axi_arvalid <= 1'b0;
            m_axi_awaddr  <= 32'd0;
            m_axi_araddr  <= 32'd0;
            m_axi_awlen   <= 8'd0;
            m_axi_arlen   <= 8'd0;
        end else begin
            done <= 1'b0;
            case (state)
                S_IDLE: begin
                    beat <= 3'd0;
                    if (cmd_valid) begin
                        len <= cmd_len;
                        if (cmd_write) begin
                            m_axi_awaddr  <= cmd_addr;
                            m_axi_awlen   <= {5'd0, cmd_len};
                            m_axi_awvalid <= 1'b1;
                            m_axi_wvalid  <= 1'b1;
                            state         <= S_WRITE;
                        end else begin
                            m_axi_araddr  <= cmd_addr;
                            m_axi_arlen   <= {5'd0, cmd_len};
                            m_axi_arvalid <= 1'b1;
                            state         <= S_READ;
                        end
                    end
                end

                S_READ: begin
                    if (m_axi_arvalid && m_axi_arready) m_axi_arvalid <= 1'b0;
                    if (m_axi_rvalid) begin
                        beat <= beat + 3'd1;
                        if (m_axi_rlast) begin
                            done  <= 1'b1;
                            state <= S_IDLE;
                        end
                    end
                end

                S_WRITE: begin
                    // Address and data channels run independently; W beats may be
                    // accepted before AW.
                    if (m_axi_awvalid && m_axi_awready) m_axi_awvalid <= 1'b0;
                    if (m_axi_wvalid && m_axi_wready) begin
                        if (beat == len) begin
                            m_axi_wvalid <= 1'b0;
                        end else begin
                            beat <= beat + 3'd1;
                        end
                    end
                    if ((!m_axi_awvalid || m_axi_awready) &&
                        (!m_axi_wvalid || (m_axi_wready && beat == len))) begin
                        state <= S_BRESP;
                    end
                end

                S_BRESP: begin
                    if (m_axi_bvalid) begin
                        done  <= 1'b1;
                        state <= S_IDLE;
                    end
                end
            endcase
        end
    end

endmodule
