`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: decoupled_to_axi_master
// Description: Bridge converting Decoupled Core Memory Requests to AXI4-Lite Master
//////////////////////////////////////////////////////////////////////////////////

module decoupled_to_axi_master (
    input  wire        clk,
    input  wire        rst,

    // Decoupled Slave Port (from Core / Interconnect)
    input  wire        req_valid,
    output reg         req_ready,
    input  wire [31:0] req_addr,
    input  wire [31:0] req_wdata,
    input  wire [3:0]  req_wmask,
    input  wire        req_is_write,

    output reg         rsp_valid,
    input  wire        rsp_ready,
    output reg  [31:0] rsp_rdata,

    // AXI4-Lite Master Interface
    // Write Address Channel
    output reg  [31:0] m_axi_awaddr,
    output reg         m_axi_awvalid,
    input  wire        m_axi_awready,

    // Write Data Channel
    output reg  [31:0] m_axi_wdata,
    output reg  [3:0]  m_axi_wstrb,
    output reg         m_axi_wvalid,
    input  wire        m_axi_wready,

    // Write Response Channel
    input  wire [1:0]  m_axi_bresp,
    input  wire        m_axi_bvalid,
    output reg         m_axi_bready,

    // Read Address Channel
    output reg  [31:0] m_axi_araddr,
    output reg         m_axi_arvalid,
    input  wire        m_axi_arready,

    // Read Data Channel
    input  wire [31:0] m_axi_rdata,
    input  wire [1:0]  m_axi_rresp,
    input  wire        m_axi_rvalid,
    output reg         m_axi_rready
);

    localparam STATE_IDLE       = 3'd0;
    localparam STATE_WRITE_ADDR = 3'd1;
    localparam STATE_WRITE_DATA = 3'd2;
    localparam STATE_WRITE_RESP = 3'd3;
    localparam STATE_READ_ADDR  = 3'd4;
    localparam STATE_READ_DATA  = 3'd5;
    localparam STATE_CORE_RESP  = 3'd6;

    reg [2:0] state = STATE_IDLE;

    always @(posedge clk) begin
        if (rst) begin
            state         <= STATE_IDLE;
            req_ready     <= 1'b1;
            rsp_valid     <= 1'b0;
            rsp_rdata     <= 32'd0;
            m_axi_awaddr  <= 32'd0;
            m_axi_awvalid <= 1'b0;
            m_axi_wdata   <= 32'd0;
            m_axi_wstrb   <= 4'd0;
            m_axi_wvalid  <= 1'b0;
            m_axi_bready  <= 1'b0;
            m_axi_araddr  <= 32'd0;
            m_axi_arvalid <= 1'b0;
            m_axi_rready  <= 1'b0;
        end else begin
            case (state)
                STATE_IDLE: begin
                    req_ready <= 1'b1;
                    rsp_valid <= 1'b0;
                    if (req_valid && req_ready) begin
                        req_ready <= 1'b0;
                        if (req_is_write) begin
                            m_axi_awaddr  <= req_addr;
                            m_axi_awvalid <= 1'b1;
                            m_axi_wdata   <= req_wdata;
                            m_axi_wstrb   <= req_wmask;
                            m_axi_wvalid  <= 1'b1;
                            state         <= STATE_WRITE_ADDR;
                        end else begin
                            m_axi_araddr  <= req_addr;
                            m_axi_arvalid <= 1'b1;
                            m_axi_rready  <= 1'b1;
                            state         <= STATE_READ_ADDR;
                        end
                    end
                end

                STATE_WRITE_ADDR: begin
                    if (m_axi_awready) begin
                        m_axi_awvalid <= 1'b0;
                    end
                    if (m_axi_wready) begin
                        m_axi_wvalid  <= 1'b0;
                    end
                    if ((!m_axi_awvalid || m_axi_awready) && (!m_axi_wvalid || m_axi_wready)) begin
                        m_axi_bready <= 1'b1;
                        state        <= STATE_WRITE_RESP;
                    end
                end

                STATE_WRITE_RESP: begin
                    // Writes complete silently: the core does not wait for a store response,
                    // so one here would be taken as the data of the next load (or never
                    // be accepted once the bus has switched to another slave, deadlocking).
                    if (m_axi_bvalid && m_axi_bready) begin
                        m_axi_bready <= 1'b0;
                        req_ready    <= 1'b1;
                        state        <= STATE_IDLE;
                    end
                end

                STATE_READ_ADDR: begin
                    if (m_axi_arready) begin
                        m_axi_arvalid <= 1'b0;
                        if (m_axi_rvalid && m_axi_rready) begin
                            m_axi_rready <= 1'b0;
                            rsp_rdata    <= m_axi_rdata;
                            rsp_valid    <= 1'b1;
                            state        <= STATE_CORE_RESP;
                        end else begin
                            state        <= STATE_READ_DATA;
                        end
                    end
                end

                STATE_READ_DATA: begin
                    if (m_axi_rvalid && m_axi_rready) begin
                        m_axi_rready <= 1'b0;
                        rsp_rdata    <= m_axi_rdata;
                        rsp_valid    <= 1'b1;
                        state        <= STATE_CORE_RESP;
                    end
                end

                STATE_CORE_RESP: begin
                    if (rsp_valid && rsp_ready) begin
                        rsp_valid <= 1'b0;
                        req_ready <= 1'b1;
                        state     <= STATE_IDLE;
                    end
                end

                default: state <= STATE_IDLE;
            endcase
        end
    end

endmodule
