`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: bus_interconnect
// Description: Decoupled Memory Bus Interconnect & Address Decoder for NucleusRV
//
// Address Decoding:
//   0x0000_0000 - 0x0FFF_FFFF : Internal Memory / Boot RAM (Slave 0)
//   0x1000_0000 - 0x1FFF_FFFF : External DDR3 via data cache (Slave 3)
//   0x2000_0000 - 0x2FFF_FFFF : Same DDR3, uncached (Slave 3)
//   0x4000_0000 - 0x4FFF_FFFF : Peripherals (UART, Timer, Keyboard) (Slave 1)
//   0x5000_0000 - 0x5FFF_FFFF : Video Subsystem (Framebuffer & Palette) (Slave 2)
//////////////////////////////////////////////////////////////////////////////////

module bus_interconnect (
    input  wire        clk,
    input  wire        rst,

    // Master (from NucleusRV Core dmem)
    input  wire        m_req_valid,
    output wire        m_req_ready,
    input  wire [31:0] m_req_addr,
    input  wire [31:0] m_req_wdata,
    input  wire [3:0]  m_req_wmask,
    input  wire        m_req_is_write,

    output wire        m_rsp_valid,
    input  wire        m_rsp_ready,
    output wire [31:0] m_rsp_rdata,

    // Slave 0: Internal RAM
    output wire        s0_req_valid,
    input  wire        s0_req_ready,
    output wire [31:0] s0_req_addr,
    output wire [31:0] s0_req_wdata,
    output wire [3:0]  s0_req_wmask,
    output wire        s0_req_is_write,
    input  wire        s0_rsp_valid,
    output wire        s0_rsp_ready,
    input  wire [31:0] s0_rsp_rdata,

    // Slave 1: Peripherals (UART / Timer)
    output wire        s1_req_valid,
    input  wire        s1_req_ready,
    output wire [31:0] s1_req_addr,
    output wire [31:0] s1_req_wdata,
    output wire [3:0]  s1_req_wmask,
    output wire        s1_req_is_write,
    input  wire        s1_rsp_valid,
    output wire        s1_rsp_ready,
    input  wire [31:0] s1_rsp_rdata,

    // Slave 2: Video (Framebuffer & Palette)
    output wire        s2_req_valid,
    input  wire        s2_req_ready,
    output wire [31:0] s2_req_addr,
    output wire [31:0] s2_req_wdata,
    output wire [3:0]  s2_req_wmask,
    output wire        s2_req_is_write,
    input  wire        s2_rsp_valid,
    output wire        s2_rsp_ready,
    input  wire [31:0] s2_rsp_rdata,

    // Slave 3: External AXI / DDR3
    output wire        s3_req_valid,
    input  wire        s3_req_ready,
    output wire [31:0] s3_req_addr,
    output wire [31:0] s3_req_wdata,
    output wire [3:0]  s3_req_wmask,
    output wire        s3_req_is_write,
    input  wire        s3_rsp_valid,
    output wire        s3_rsp_ready,
    input  wire [31:0] s3_rsp_rdata
);

    // Decode target slave based on address prefix [31:28]
    wire [3:0] addr_prefix = m_req_addr[31:28];
    wire [1:0] sel_target = (addr_prefix == 4'h4) ? 2'd1 : // Peripherals
                            (addr_prefix == 4'h5) ? 2'd2 : // Video
                            (addr_prefix == 4'h1) ? 2'd3 : // External DDR3 (cached)
                            (addr_prefix == 4'h2) ? 2'd3 : // External DDR3 (uncached alias)
                                                    2'd0;  // Internal RAM

    // Track active target for response routing
    reg [1:0] active_target = 2'd0;
    always @(posedge clk) begin
        if (rst) begin
            active_target <= 2'd0;
        end else if (m_req_valid && m_req_ready) begin
            active_target <= sel_target;
        end
    end

    // The core only waits for load data and never for store acknowledgements, so a
    // response reaches it only while a read it issued is outstanding. Anything else
    // (store acks, stray responses) is drained from the slave and dropped.
    reg read_pending = 1'b0;
    wire slave_rsp_valid;
    always @(posedge clk) begin
        if (rst) begin
            read_pending <= 1'b0;
        end else if (m_req_valid && m_req_ready && !m_req_is_write) begin
            read_pending <= 1'b1;
        end else if (read_pending && slave_rsp_valid && m_rsp_ready) begin
            read_pending <= 1'b0;
        end
    end

    // Request Routing
    assign s0_req_valid = m_req_valid && (sel_target == 2'd0);
    assign s1_req_valid = m_req_valid && (sel_target == 2'd1);
    assign s2_req_valid = m_req_valid && (sel_target == 2'd2);
    assign s3_req_valid = m_req_valid && (sel_target == 2'd3);

    assign m_req_ready = (sel_target == 2'd0) ? s0_req_ready :
                         (sel_target == 2'd1) ? s1_req_ready :
                         (sel_target == 2'd2) ? s2_req_ready :
                                                s3_req_ready;

    // Common request signals broadcast to all slaves
    assign s0_req_addr     = m_req_addr;
    assign s0_req_wdata    = m_req_wdata;
    assign s0_req_wmask    = m_req_wmask;
    assign s0_req_is_write = m_req_is_write;

    assign s1_req_addr     = m_req_addr;
    assign s1_req_wdata    = m_req_wdata;
    assign s1_req_wmask    = m_req_wmask;
    assign s1_req_is_write = m_req_is_write;

    assign s2_req_addr     = m_req_addr;
    assign s2_req_wdata    = m_req_wdata;
    assign s2_req_wmask    = m_req_wmask;
    assign s2_req_is_write = m_req_is_write;

    assign s3_req_addr     = m_req_addr;
    assign s3_req_wdata    = m_req_wdata;
    assign s3_req_wmask    = m_req_wmask;
    assign s3_req_is_write = m_req_is_write;

    // Response Routing
    assign slave_rsp_valid = (active_target == 2'd0) ? s0_rsp_valid :
                             (active_target == 2'd1) ? s1_rsp_valid :
                             (active_target == 2'd2) ? s2_rsp_valid :
                                                       s3_rsp_valid;
    assign m_rsp_valid = read_pending && slave_rsp_valid;

    assign m_rsp_rdata = (active_target == 2'd0) ? s0_rsp_rdata :
                         (active_target == 2'd1) ? s1_rsp_rdata :
                         (active_target == 2'd2) ? s2_rsp_rdata :
                                                   s3_rsp_rdata;

    // Slaves not currently addressed can always retire a leftover response
    assign s0_rsp_ready = (active_target != 2'd0) || m_rsp_ready;
    assign s1_rsp_ready = (active_target != 2'd1) || m_rsp_ready;
    assign s2_rsp_ready = (active_target != 2'd2) || m_rsp_ready;
    assign s3_rsp_ready = (active_target != 2'd3) || m_rsp_ready;

endmodule
