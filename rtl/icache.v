`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: icache
// Description: Instruction cache for NucleusRV execution from DDR3.
//              16 KB, direct-mapped, 32-byte lines refilled with one AXI4 burst.
//
// Handshake with the core's fetch unit:
//   - a request is accepted once; cpu_req_ready stays low until its response is taken
//   - the response is held until rsp_ready (the core may be stalled when it arrives)
// Hit: accepted in cycle t, instruction in t+1. Miss: burst refill, then respond.
//////////////////////////////////////////////////////////////////////////////////

module icache (
    input  wire        clk,
    input  wire        rst,

    // CPU instruction fetch
    input  wire        cpu_req_valid,
    output wire        cpu_req_ready,
    input  wire [31:0] cpu_req_addr,
    output wire        cpu_rsp_valid,
    input  wire        rsp_ready,
    output wire [31:0] cpu_rsp_rdata,

    // AXI4 master (read only) to DDR3
    output wire [31:0] m_axi_araddr,
    output wire [7:0]  m_axi_arlen,
    output wire [2:0]  m_axi_arsize,
    output wire [1:0]  m_axi_arburst,
    output wire [3:0]  m_axi_arcache,
    output wire [2:0]  m_axi_arprot,
    output wire        m_axi_arvalid,
    input  wire        m_axi_arready,
    input  wire [31:0] m_axi_rdata,
    input  wire [1:0]  m_axi_rresp,
    input  wire        m_axi_rlast,
    input  wire        m_axi_rvalid,
    output wire        m_axi_rready
);

    localparam LINES = 512;                       // 512 x 32 B = 16 KB

    (* ram_style = "block" *) reg [31:0] data_ram [0:LINES*8-1];
    reg [13:0]      tag_ram [0:LINES-1];
    reg [LINES-1:0] valid = {LINES{1'b0}};

    localparam S_IDLE   = 3'd0;
    localparam S_LOOKUP = 3'd1;
    localparam S_RF_CMD = 3'd2;
    localparam S_RF     = 3'd3;
    localparam S_RESP   = 3'd4;

    reg [2:0]  state = S_IDLE;
    reg [31:0] s_addr = 32'd0;
    reg [31:0] resp_word = 32'd0;

    wire [8:0]  s_line = s_addr[13:5];
    wire [2:0]  s_word = s_addr[4:2];
    wire [13:0] s_tag  = s_addr[27:14];

    assign cpu_req_ready = (state == S_IDLE);
    wire accept = cpu_req_valid && cpu_req_ready;

    reg [31:0] rd_q;
    reg [13:0] tag_q;
    always @(posedge clk) begin
        rd_q  <= data_ram[cpu_req_addr[13:2]];
        tag_q <= tag_ram[cpu_req_addr[13:5]];
    end

    wire hit = valid[s_line] && (tag_q == s_tag);

    assign cpu_rsp_valid = ((state == S_LOOKUP) && hit) || (state == S_RESP);
    assign cpu_rsp_rdata = (state == S_RESP) ? resp_word : rd_q;

    // AXI burst master (reads only)
    wire        cmd_ready, rd_beat_valid, mst_done;
    wire [2:0]  rd_idx, wr_idx_unused;
    wire [31:0] rd_data;
    wire        unused_awvalid, unused_wvalid, unused_bready, unused_wlast;
    wire [31:0] unused_awaddr, unused_wdata;
    wire [7:0]  unused_awlen;
    wire [2:0]  unused_awsize, unused_awprot;
    wire [1:0]  unused_awburst;
    wire [3:0]  unused_awcache, unused_wstrb;

    always @(posedge clk) begin
        if (state == S_RF && rd_beat_valid) data_ram[{s_line, rd_idx}] <= rd_data;
    end

    always @(posedge clk) begin
        if (rst) begin
            state <= S_IDLE;
            valid <= {LINES{1'b0}};
        end else begin
            case (state)
                S_IDLE: if (accept) begin
                    s_addr <= cpu_req_addr;
                    state  <= S_LOOKUP;
                end
                S_LOOKUP: begin
                    if (hit) begin
                        if (rsp_ready) state <= S_IDLE;
                        else begin
                            resp_word <= rd_q;
                            state <= S_RESP;
                        end
                    end else begin
                        state <= S_RF_CMD;
                    end
                end
                S_RF_CMD: if (cmd_ready) state <= S_RF;
                S_RF: begin
                    if (rd_beat_valid && rd_idx == s_word) resp_word <= rd_data;
                    if (mst_done) begin
                        tag_ram[s_line] <= s_tag;
                        valid[s_line]   <= 1'b1;
                        state           <= S_RESP;
                    end
                end
                S_RESP: if (rsp_ready) state <= S_IDLE;
                default: state <= S_IDLE;
            endcase
        end
    end

    axi4_line_master u_axi (
        .clk(clk), .rst(rst),
        .cmd_valid(state == S_RF_CMD), .cmd_ready(cmd_ready), .cmd_write(1'b0),
        .cmd_addr({4'h1, s_addr[27:5], 5'd0}), .cmd_len(3'd7),
        .wr_idx(wr_idx_unused), .wr_data(32'd0), .wr_strb(4'd0),
        .rd_beat_valid(rd_beat_valid), .rd_idx(rd_idx), .rd_data(rd_data),
        .done(mst_done),
        .m_axi_awaddr(unused_awaddr), .m_axi_awlen(unused_awlen), .m_axi_awsize(unused_awsize),
        .m_axi_awburst(unused_awburst), .m_axi_awcache(unused_awcache), .m_axi_awprot(unused_awprot),
        .m_axi_awvalid(unused_awvalid), .m_axi_awready(1'b0),
        .m_axi_wdata(unused_wdata), .m_axi_wstrb(unused_wstrb), .m_axi_wlast(unused_wlast),
        .m_axi_wvalid(unused_wvalid), .m_axi_wready(1'b0),
        .m_axi_bresp(2'b00), .m_axi_bvalid(1'b0), .m_axi_bready(unused_bready),
        .m_axi_araddr(m_axi_araddr), .m_axi_arlen(m_axi_arlen), .m_axi_arsize(m_axi_arsize),
        .m_axi_arburst(m_axi_arburst), .m_axi_arcache(m_axi_arcache), .m_axi_arprot(m_axi_arprot),
        .m_axi_arvalid(m_axi_arvalid), .m_axi_arready(m_axi_arready),
        .m_axi_rdata(m_axi_rdata), .m_axi_rresp(m_axi_rresp), .m_axi_rlast(m_axi_rlast),
        .m_axi_rvalid(m_axi_rvalid), .m_axi_rready(m_axi_rready)
    );

endmodule
