`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: dcache
// Description: Data cache in front of DDR3 (bus slave 3).
//              16 KB, direct-mapped, 32-byte lines, write-back + write-allocate.
//              0x1xxx_xxxx is cached; 0x2xxx_xxxx is an uncached alias of the same
//              DDR (single-beat access), for data other agents read (e.g. the
//              JTAG-visible console log).
//
// Bus handshake (what bus_interconnect / the core expect):
//   - a request is accepted once; req_ready stays low until it is finished
//   - loads get one response (rsp_valid) which is held until rsp_ready
//   - stores get no response
// Read hit: accepted in cycle t, data in t+1. Store hit: written in t+1.
// Miss: write back the victim line if dirty, refill the line, then finish.
//////////////////////////////////////////////////////////////////////////////////

module dcache (
    input  wire        clk,
    input  wire        rst,

    input  wire        req_valid,
    output wire        req_ready,
    input  wire [31:0] req_addr,
    input  wire [31:0] req_wdata,
    input  wire [3:0]  req_wmask,
    input  wire        req_is_write,

    output wire        rsp_valid,
    input  wire        rsp_ready,
    output wire [31:0] rsp_rdata,

    // AXI4 master to DDR3
    output wire [31:0] m_axi_awaddr,
    output wire [7:0]  m_axi_awlen,
    output wire [2:0]  m_axi_awsize,
    output wire [1:0]  m_axi_awburst,
    output wire [3:0]  m_axi_awcache,
    output wire [2:0]  m_axi_awprot,
    output wire        m_axi_awvalid,
    input  wire        m_axi_awready,
    output wire [31:0] m_axi_wdata,
    output wire [3:0]  m_axi_wstrb,
    output wire        m_axi_wlast,
    output wire        m_axi_wvalid,
    input  wire        m_axi_wready,
    input  wire [1:0]  m_axi_bresp,
    input  wire        m_axi_bvalid,
    output wire        m_axi_bready,
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

    // Address fields inside the 256 MB DDR window: [27:14] tag, [13:5] line, [4:2] word
    function [13:0] tag_of  (input [31:0] a); tag_of  = a[27:14]; endfunction
    function [8:0]  line_of (input [31:0] a); line_of = a[13:5];  endfunction
    function [2:0]  word_of (input [31:0] a); word_of = a[4:2];   endfunction

    // ---------------- storage ----------------
    (* ram_style = "block" *) reg [31:0] data_ram [0:LINES*8-1];
    reg [13:0]      tag_ram [0:LINES-1];
    reg [LINES-1:0] valid = {LINES{1'b0}};
    reg [LINES-1:0] dirty = {LINES{1'b0}};

    // ---------------- state ----------------
    localparam S_IDLE     = 4'd0;
    localparam S_LOOKUP   = 4'd1;
    localparam S_WB_READ  = 4'd2;   // copy the dirty victim line into the line buffer
    localparam S_WB_CMD   = 4'd3;
    localparam S_WB_WAIT  = 4'd4;
    localparam S_RF_CMD   = 4'd5;
    localparam S_RF_WAIT  = 4'd6;
    localparam S_STORE    = 4'd7;   // apply a store after its line was refilled
    localparam S_RESP     = 4'd8;   // hold a load response until accepted
    localparam S_UC_CMD   = 4'd9;
    localparam S_UC_WAIT  = 4'd10;

    reg [3:0]  state = S_IDLE;
    reg [31:0] s_addr = 32'd0;
    reg [31:0] s_wdata = 32'd0;
    reg [3:0]  s_wmask = 4'd0;
    reg        s_write = 1'b0;
    reg [31:0] resp_word = 32'd0;
    reg [13:0] victim_tag = 14'd0;
    reg [3:0]  wb_cnt = 4'd0;
    reg [31:0] line_buf [0:7];

    wire [8:0] s_line = line_of(s_addr);
    wire [2:0] s_word = word_of(s_addr);

    assign req_ready = (state == S_IDLE);
    wire accept   = req_valid && req_ready;
    wire uncached = (req_addr[31:28] == 4'h2);

    // ---------------- synchronous RAM reads ----------------
    reg  [11:0] rd_addr;
    reg  [31:0] rd_q;
    reg  [13:0] tag_q;
    always @(*) begin
        if (state == S_WB_READ) rd_addr = {s_line, wb_cnt[2:0]};
        else                    rd_addr = {line_of(req_addr), word_of(req_addr)};
    end
    always @(posedge clk) begin
        rd_q  <= data_ram[rd_addr];
        tag_q <= tag_ram[line_of(req_addr)];
    end

    // ---------------- RAM writes ----------------
    wire hit = valid[s_line] && (tag_q == tag_of(s_addr));

    // AXI master
    wire        cmd_ready, rd_beat_valid, mst_done;
    wire [2:0]  wr_idx, rd_idx;
    wire [31:0] rd_data;
    reg         cmd_valid;
    reg         cmd_write;
    reg  [31:0] cmd_addr;
    reg  [2:0]  cmd_len;
    reg  [31:0] wr_data_mux;
    reg  [3:0]  wr_strb_mux;

    reg        we;
    reg [11:0] wa;
    reg [31:0] wd;
    reg [3:0]  wm;
    always @(*) begin
        we = 1'b0; wa = {s_line, s_word}; wd = s_wdata; wm = s_wmask;
        if (state == S_LOOKUP && s_write && hit) begin
            we = 1'b1;
        end else if (state == S_STORE) begin
            we = 1'b1;
        end else if (state == S_RF_WAIT && rd_beat_valid) begin
            we = 1'b1; wa = {s_line, rd_idx}; wd = rd_data; wm = 4'b1111;
        end
    end
    always @(posedge clk) begin
        if (we) begin
            if (wm[0]) data_ram[wa][7:0]   <= wd[7:0];
            if (wm[1]) data_ram[wa][15:8]  <= wd[15:8];
            if (wm[2]) data_ram[wa][23:16] <= wd[23:16];
            if (wm[3]) data_ram[wa][31:24] <= wd[31:24];
        end
    end

    // ---------------- responses ----------------
    wire lookup_hit_load = (state == S_LOOKUP) && !s_write && hit;
    assign rsp_valid = lookup_hit_load || (state == S_RESP);
    assign rsp_rdata = (state == S_RESP) ? resp_word : rd_q;

    // ---------------- control ----------------
    always @(*) begin
        cmd_valid = 1'b0; cmd_write = 1'b0; cmd_addr = 32'd0; cmd_len = 3'd7;
        wr_data_mux = line_buf[wr_idx]; wr_strb_mux = 4'b1111;
        case (state)
            S_WB_CMD: begin
                cmd_valid = 1'b1; cmd_write = 1'b1;
                cmd_addr  = {4'h1, victim_tag, s_line, 5'd0};
            end
            S_RF_CMD: begin
                cmd_valid = 1'b1;
                cmd_addr  = {4'h1, s_addr[27:5], 5'd0};
            end
            S_UC_CMD: begin
                cmd_valid = 1'b1; cmd_write = s_write; cmd_len = 3'd0;
                cmd_addr  = {4'h1, s_addr[27:2], 2'd0};
            end
            default: ;
        endcase
        if (state == S_UC_CMD || state == S_UC_WAIT) begin
            wr_data_mux = s_wdata; wr_strb_mux = s_wmask;
        end
    end

    always @(posedge clk) begin
        if (rst) begin
            state <= S_IDLE;
            valid <= {LINES{1'b0}};
            dirty <= {LINES{1'b0}};
        end else begin
            case (state)
                S_IDLE: if (accept) begin
                    s_addr  <= req_addr;
                    s_wdata <= req_wdata;
                    s_wmask <= req_wmask;
                    s_write <= req_is_write;
                    state   <= uncached ? S_UC_CMD : S_LOOKUP;
                end

                S_LOOKUP: begin
                    if (hit) begin
                        if (s_write) begin
                            dirty[s_line] <= 1'b1;
                            state <= S_IDLE;
                        end else if (rsp_ready) begin
                            state <= S_IDLE;
                        end else begin
                            resp_word <= rd_q;
                            state <= S_RESP;
                        end
                    end else if (valid[s_line] && dirty[s_line]) begin
                        victim_tag <= tag_q;
                        wb_cnt     <= 4'd0;
                        state      <= S_WB_READ;
                    end else begin
                        state <= S_RF_CMD;
                    end
                end

                // rd_addr walks the victim line; rd_q lags one cycle behind wb_cnt
                S_WB_READ: begin
                    if (wb_cnt != 4'd0) line_buf[wb_cnt - 4'd1] <= rd_q;
                    if (wb_cnt == 4'd8) state <= S_WB_CMD;
                    else                wb_cnt <= wb_cnt + 4'd1;
                end

                S_WB_CMD:  if (cmd_ready) state <= S_WB_WAIT;
                S_WB_WAIT: if (mst_done) begin
                    dirty[s_line] <= 1'b0;
                    state <= S_RF_CMD;
                end

                S_RF_CMD:  if (cmd_ready) state <= S_RF_WAIT;
                S_RF_WAIT: begin
                    if (rd_beat_valid && rd_idx == s_word) resp_word <= rd_data;
                    if (mst_done) begin
                        tag_ram[s_line] <= tag_of(s_addr);
                        valid[s_line]   <= 1'b1;
                        dirty[s_line]   <= 1'b0;
                        state           <= s_write ? S_STORE : S_RESP;
                    end
                end

                S_STORE: begin
                    dirty[s_line] <= 1'b1;
                    state <= S_IDLE;
                end

                S_RESP: if (rsp_ready) state <= S_IDLE;

                S_UC_CMD:  if (cmd_ready) state <= S_UC_WAIT;
                S_UC_WAIT: begin
                    if (rd_beat_valid) resp_word <= rd_data;
                    if (mst_done) state <= s_write ? S_IDLE : S_RESP;
                end

                default: state <= S_IDLE;
            endcase
        end
    end

    axi4_line_master u_axi (
        .clk(clk), .rst(rst),
        .cmd_valid(cmd_valid), .cmd_ready(cmd_ready), .cmd_write(cmd_write),
        .cmd_addr(cmd_addr), .cmd_len(cmd_len),
        .wr_idx(wr_idx), .wr_data(wr_data_mux), .wr_strb(wr_strb_mux),
        .rd_beat_valid(rd_beat_valid), .rd_idx(rd_idx), .rd_data(rd_data),
        .done(mst_done),
        .m_axi_awaddr(m_axi_awaddr), .m_axi_awlen(m_axi_awlen), .m_axi_awsize(m_axi_awsize),
        .m_axi_awburst(m_axi_awburst), .m_axi_awcache(m_axi_awcache), .m_axi_awprot(m_axi_awprot),
        .m_axi_awvalid(m_axi_awvalid), .m_axi_awready(m_axi_awready),
        .m_axi_wdata(m_axi_wdata), .m_axi_wstrb(m_axi_wstrb), .m_axi_wlast(m_axi_wlast),
        .m_axi_wvalid(m_axi_wvalid), .m_axi_wready(m_axi_wready),
        .m_axi_bresp(m_axi_bresp), .m_axi_bvalid(m_axi_bvalid), .m_axi_bready(m_axi_bready),
        .m_axi_araddr(m_axi_araddr), .m_axi_arlen(m_axi_arlen), .m_axi_arsize(m_axi_arsize),
        .m_axi_arburst(m_axi_arburst), .m_axi_arcache(m_axi_arcache), .m_axi_arprot(m_axi_arprot),
        .m_axi_arvalid(m_axi_arvalid), .m_axi_arready(m_axi_arready),
        .m_axi_rdata(m_axi_rdata), .m_axi_rresp(m_axi_rresp), .m_axi_rlast(m_axi_rlast),
        .m_axi_rvalid(m_axi_rvalid), .m_axi_rready(m_axi_rready)
    );

endmodule
