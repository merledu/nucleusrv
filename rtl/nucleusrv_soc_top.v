`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: nucleusrv_soc_top
// Description: Full SoC Top-Level for DOOM on Digilent Zybo Z7-10 (XC7Z010).
//              Integrates NucleusRV (RV32IM), 16KB ICache + 16KB DCache, Dual-Port Framebuffer + HDMI TX,
//              UART & Button Peripherals, and Zynq PS7 512MB DDR3 via AXI HP0.
//////////////////////////////////////////////////////////////////////////////////

module nucleusrv_soc_top #(
    parameter CLK_FREQ   = 25000000, // 25 MHz core and pixel clock
    parameter BAUD_RATE  = 115200,
    parameter BOOT_HEX   = "/home/ar/nucleusrv/tools/out/program.hex"
)(
    // Clock & Reset
    input  wire        clk,            // 125 MHz onboard oscillator (K17 on Zybo Z7)
    input  wire        btn_rst,        // Active-high reset: slide switch SW3 (T16), up = held in reset

    // UART Serial Port (Terminal Keyboard Input + Debug Output on Pmod JE)
    input  wire        uart_rxd,       // USB-UART RX (J15 on Pmod JE)
    output wire        uart_txd,       // USB-UART TX (V12 on Pmod JE)

    // HDMI Output (DVI / TMDS Differential Pairs)
    output wire        hdmi_tx_clk_p,
    output wire        hdmi_tx_clk_n,
    output wire [2:0]  hdmi_tx_p,
    output wire [2:0]  hdmi_tx_n,

    // Status LEDs
    output wire [3:0]  led,

    // Hardware Push Buttons & Switches for direct on-board control
    input  wire [3:0]  btn,            // {BTN0, BTN3, BTN2, BTN1} (K18, Y16, K19, P16)
    input  wire [2:0]  sw,             // SW[2:0] (G15, P15, W13); SW3 is the reset

    // Zynq Hard DDR3 Memory Controller Interface
    inout  wire [14:0] DDR_addr,
    inout  wire [2:0]  DDR_ba,
    inout  wire        DDR_cas_n,
    inout  wire        DDR_ck_n,
    inout  wire        DDR_ck_p,
    inout  wire        DDR_cke,
    inout  wire        DDR_cs_n,
    inout  wire [3:0]  DDR_dm,
    inout  wire [31:0] DDR_dq,
    inout  wire [3:0]  DDR_dqs_n,
    inout  wire [3:0]  DDR_dqs_p,
    inout  wire        DDR_odt,
    inout  wire        DDR_ras_n,
    inout  wire        DDR_reset_n,
    inout  wire        DDR_we_n,
    inout  wire        FIXED_IO_ddr_vrn,
    inout  wire        FIXED_IO_ddr_vrp,
    inout  wire [53:0] FIXED_IO_mio,
    inout  wire        FIXED_IO_ps_clk,
    inout  wire        FIXED_IO_ps_porb,
    inout  wire        FIXED_IO_ps_srstb
);

    // -------------------------------------------------------------
    // 1. Clock & Reset Management
    // -------------------------------------------------------------
    wire clk25MHz;   // 25.0 MHz Core, Pixel & AXI Clock
    wire clk_tmds;   // 250.0 MHz TMDS Serializer Clock
    wire pll_locked;

    zybo_pll u_pll (
        .clk_in(clk),
        .rst(1'b0),         // video keeps running through a CPU reset
        .clk_pixel(clk25MHz),
        .clk_tmds(clk_tmds),
        .locked(pll_locked)
    );

    // The reset switch is asynchronous to clk25MHz: synchronise it
    reg [1:0] rst_sync = 2'b11;
    always @(posedge clk25MHz) rst_sync <= {rst_sync[0], btn_rst};
    wire sys_rst = rst_sync[1] || !pll_locked;

    // -------------------------------------------------------------
    // 2. NucleusRV Processor Core (RV32IM)
    // -------------------------------------------------------------
    wire        imem_req_ready, imem_req_valid, imem_req_is_write;
    wire [31:0] imem_req_addr, imem_req_wdata;
    wire [3:0]  imem_req_wmask;
    wire        imem_rsp_ready, imem_rsp_valid;
    wire [31:0] imem_rsp_rdata;

    wire        dmem_req_ready, dmem_req_valid, dmem_req_is_write;
    wire [31:0] dmem_req_addr, dmem_req_wdata;
    wire [3:0]  dmem_req_wmask;
    wire        dmem_rsp_ready, dmem_rsp_valid;
    wire [31:0] dmem_rsp_rdata;

    wire [31:0] core_pin;

    Core u_core (
        .clock(clk25MHz),
        .reset(sys_rst),

        .io_pin(core_pin),
        .io_stall(1'b0),

        // DMEM
        .io_dmemReq_ready(dmem_req_ready),
        .io_dmemReq_valid(dmem_req_valid),
        .io_dmemReq_bits_addrRequest(dmem_req_addr),
        .io_dmemReq_bits_dataRequest(dmem_req_wdata),
        .io_dmemReq_bits_activeByteLane(dmem_req_wmask),
        .io_dmemReq_bits_isWrite(dmem_req_is_write),
        .io_dmemRsp_ready(dmem_rsp_ready),
        .io_dmemRsp_valid(dmem_rsp_valid),
        .io_dmemRsp_bits_dataResponse(dmem_rsp_rdata),

        // IMEM
        .io_imemReq_ready(imem_req_ready),
        .io_imemReq_valid(imem_req_valid),
        .io_imemReq_bits_addrRequest(imem_req_addr),
        .io_imemReq_bits_dataRequest(imem_req_wdata),
        .io_imemReq_bits_activeByteLane(imem_req_wmask),
        .io_imemReq_bits_isWrite(imem_req_is_write),
        .io_imemRsp_ready(imem_rsp_ready),
        .io_imemRsp_valid(imem_rsp_valid),
        .io_imemRsp_bits_dataResponse(imem_rsp_rdata)
    );

    // -------------------------------------------------------------
    // 3. Boot / Internal Block RAM (16 KB on-chip BRAM)
    // -------------------------------------------------------------
    localparam RAM_WORDS = 4096;
    (* ram_style = "block" *) reg [31:0] boot_ram [0:RAM_WORDS-1];

    integer i;
    initial begin
        // Default built-in bootloader: jump directly to DDR3 entry point (0x10000000)
        // 0x00000000: lui  t0, 0x10000  (t0 = 0x10000000)
        // 0x00000004: jalr x0, 0(t0)   (jump to 0x10000000)
        boot_ram[0] = 32'h100002b7;
        boot_ram[1] = 32'h000280e7;
        for (i = 2; i < RAM_WORDS; i = i + 1) begin
            boot_ram[i] = 32'h00000013; // nop (addi x0, x0, 0)
        end
        if (BOOT_HEX != "") begin
            $readmemh(BOOT_HEX, boot_ram);
        end
    end

    // Instruction Fetch Multiplexer:
    // If address < 0x1000_0000: On-chip Boot BRAM (1 cycle)
    // If address >= 0x1000_0000: ICache -> DDR3 (1 cycle hit, burst miss)
    wire is_boot_imem = (imem_req_addr < 32'h1000_0000);

    // Boot BRAM instruction read. The response is held until the core accepts it,
    // because the core may be stalled in the cycle the data comes back.
    reg [31:0] boot_imem_rdata = 32'd0;
    reg        boot_imem_rsp_val = 1'b0;
    wire       boot_imem_req_ready = !(boot_imem_rsp_val && !imem_rsp_ready);
    always @(posedge clk25MHz) begin
        if (sys_rst) begin
            boot_imem_rsp_val <= 1'b0;
            boot_imem_rdata   <= 32'd0;
        end else begin
            if (boot_imem_rsp_val && imem_rsp_ready) boot_imem_rsp_val <= 1'b0;
            if (imem_req_valid && is_boot_imem && boot_imem_req_ready) begin
                boot_imem_rsp_val <= 1'b1;
                boot_imem_rdata   <= boot_ram[(imem_req_addr[15:2]) % RAM_WORDS];
            end
        end
    end

    // Source of the outstanding fetch; the response is routed by it, not by the current PC
    reg imem_src_boot = 1'b1;
    always @(posedge clk25MHz) begin
        if (sys_rst) imem_src_boot <= 1'b1;
        else if (imem_req_valid && imem_req_ready) imem_src_boot <= is_boot_imem;
    end

    // ICache instruction read (for DDR3 space 0x1000_0000 - 0x1FFF_FFFF)
    wire icache_cpu_req_valid = imem_req_valid && !is_boot_imem;
    wire icache_cpu_req_ready;
    wire icache_cpu_rsp_valid;
    wire [31:0] icache_cpu_rsp_rdata;

    wire [31:0] imem_axi_araddr, imem_axi_rdata;
    wire [7:0]  imem_axi_arlen;
    wire [2:0]  imem_axi_arsize, imem_axi_arprot;
    wire [1:0]  imem_axi_arburst, imem_axi_rresp;
    wire [3:0]  imem_axi_arcache;
    wire        imem_axi_arvalid, imem_axi_arready, imem_axi_rvalid, imem_axi_rready, imem_axi_rlast;

    icache u_icache (
        .clk(clk25MHz),
        .rst(sys_rst),
        .cpu_req_valid(icache_cpu_req_valid),
        .cpu_req_ready(icache_cpu_req_ready),
        .cpu_req_addr(imem_req_addr),
        .cpu_rsp_valid(icache_cpu_rsp_valid),
        .rsp_ready(imem_rsp_ready && !imem_src_boot),
        .cpu_rsp_rdata(icache_cpu_rsp_rdata),

        .m_axi_araddr(imem_axi_araddr),
        .m_axi_arlen(imem_axi_arlen),
        .m_axi_arsize(imem_axi_arsize),
        .m_axi_arburst(imem_axi_arburst),
        .m_axi_arcache(imem_axi_arcache),
        .m_axi_arprot(imem_axi_arprot),
        .m_axi_arvalid(imem_axi_arvalid),
        .m_axi_arready(imem_axi_arready),
        .m_axi_rdata(imem_axi_rdata),
        .m_axi_rresp(imem_axi_rresp),
        .m_axi_rlast(imem_axi_rlast),
        .m_axi_rvalid(imem_axi_rvalid),
        .m_axi_rready(imem_axi_rready)
    );

    // Mux back to core imem port
    assign imem_req_ready = is_boot_imem ? boot_imem_req_ready : icache_cpu_req_ready;
    assign imem_rsp_valid = imem_src_boot ? boot_imem_rsp_val : icache_cpu_rsp_valid;
    assign imem_rsp_rdata = imem_src_boot ? boot_imem_rdata   : icache_cpu_rsp_rdata;

    // -------------------------------------------------------------
    // 4. Memory Bus Interconnect
    // -------------------------------------------------------------
    // Slave 0: Internal RAM (Data port)
    wire        s0_req_valid, s0_req_ready, s0_req_is_write, s0_rsp_valid, s0_rsp_ready;
    wire [31:0] s0_req_addr, s0_req_wdata, s0_rsp_rdata;
    wire [3:0]  s0_req_wmask;

    // Slave 1: UART & Timer Peripherals (0x4000_0000)
    wire        s1_req_valid, s1_req_ready, s1_req_is_write, s1_rsp_valid, s1_rsp_ready;
    wire [31:0] s1_req_addr, s1_req_wdata, s1_rsp_rdata;
    wire [3:0]  s1_req_wmask;

    // Slave 2: Framebuffer & Palette RAM (0x5000_0000)
    wire        s2_req_valid, s2_req_ready, s2_req_is_write, s2_rsp_valid, s2_rsp_ready;
    wire [31:0] s2_req_addr, s2_req_wdata, s2_rsp_rdata;
    wire [3:0]  s2_req_wmask;

    // Slave 3: External DDR3 Memory (0x1000_0000)
    wire        s3_req_valid, s3_req_ready, s3_req_is_write, s3_rsp_valid, s3_rsp_ready;
    wire [31:0] s3_req_addr, s3_req_wdata, s3_rsp_rdata;
    wire [3:0]  s3_req_wmask;

    bus_interconnect u_bus (
        .clk(clk25MHz),
        .rst(sys_rst),

        // Master (Core DMEM)
        .m_req_valid(dmem_req_valid),
        .m_req_ready(dmem_req_ready),
        .m_req_addr(dmem_req_addr),
        .m_req_wdata(dmem_req_wdata),
        .m_req_wmask(dmem_req_wmask),
        .m_req_is_write(dmem_req_is_write),
        .m_rsp_valid(dmem_rsp_valid),
        .m_rsp_ready(dmem_rsp_ready),
        .m_rsp_rdata(dmem_rsp_rdata),

        // Slave 0: Internal Boot RAM
        .s0_req_valid(s0_req_valid),
        .s0_req_ready(s0_req_ready),
        .s0_req_addr(s0_req_addr),
        .s0_req_wdata(s0_req_wdata),
        .s0_req_wmask(s0_req_wmask),
        .s0_req_is_write(s0_req_is_write),
        .s0_rsp_valid(s0_rsp_valid),
        .s0_rsp_ready(s0_rsp_ready),
        .s0_rsp_rdata(s0_rsp_rdata),

        // Slave 1: Peripherals
        .s1_req_valid(s1_req_valid),
        .s1_req_ready(s1_req_ready),
        .s1_req_addr(s1_req_addr),
        .s1_req_wdata(s1_req_wdata),
        .s1_req_wmask(s1_req_wmask),
        .s1_req_is_write(s1_req_is_write),
        .s1_rsp_valid(s1_rsp_valid),
        .s1_rsp_ready(s1_rsp_ready),
        .s1_rsp_rdata(s1_rsp_rdata),

        // Slave 2: Framebuffer & Palette
        .s2_req_valid(s2_req_valid),
        .s2_req_ready(s2_req_ready),
        .s2_req_addr(s2_req_addr),
        .s2_req_wdata(s2_req_wdata),
        .s2_req_wmask(s2_req_wmask),
        .s2_req_is_write(s2_req_is_write),
        .s2_rsp_valid(s2_rsp_valid),
        .s2_rsp_ready(s2_rsp_ready),
        .s2_rsp_rdata(s2_rsp_rdata),

        // Slave 3: External DDR3 Memory
        .s3_req_valid(s3_req_valid),
        .s3_req_ready(s3_req_ready),
        .s3_req_addr(s3_req_addr),
        .s3_req_wdata(s3_req_wdata),
        .s3_req_wmask(s3_req_wmask),
        .s3_req_is_write(s3_req_is_write),
        .s3_rsp_valid(s3_rsp_valid),
        .s3_rsp_ready(s3_rsp_ready),
        .s3_rsp_rdata(s3_rsp_rdata)
    );

    // DMEM Port to Internal Boot RAM
    reg [31:0] dmem_bram_rdata = 32'd0;
    reg        dmem_bram_rsp_val = 1'b0;
    assign s0_req_ready = 1'b1;
    assign s0_rsp_valid = dmem_bram_rsp_val;
    assign s0_rsp_rdata = dmem_bram_rdata;

    wire [11:0] bram_word_addr = (s0_req_addr[15:2]) % RAM_WORDS;

    always @(posedge clk25MHz) begin
        if (sys_rst) begin
            dmem_bram_rsp_val <= 1'b0;
            dmem_bram_rdata   <= 32'd0;
        end else begin
            dmem_bram_rsp_val <= s0_req_valid;
            if (s0_req_valid) begin
                if (s0_req_is_write) begin
                    if (s0_req_wmask[0]) boot_ram[bram_word_addr][7:0]   <= s0_req_wdata[7:0];
                    if (s0_req_wmask[1]) boot_ram[bram_word_addr][15:8]  <= s0_req_wdata[15:8];
                    if (s0_req_wmask[2]) boot_ram[bram_word_addr][23:16] <= s0_req_wdata[23:16];
                    if (s0_req_wmask[3]) boot_ram[bram_word_addr][31:24] <= s0_req_wdata[31:24];
                    dmem_bram_rdata <= 32'd0;
                end else begin
                    dmem_bram_rdata <= boot_ram[bram_word_addr];
                end
            end
        end
    end

    // -------------------------------------------------------------
    // 5. Hardware Peripherals (UART, Millisecond Timer, Buttons, Switches)
    // -------------------------------------------------------------
    uart_timer_peripheral #(
        .CLK_FREQ(CLK_FREQ),
        .BAUD_RATE(BAUD_RATE)
    ) u_periph (
        .clk(clk25MHz),
        .rst(sys_rst),

        .req_valid(s1_req_valid),
        .req_ready(s1_req_ready),
        .req_addr(s1_req_addr),
        .req_wdata(s1_req_wdata),
        .req_wmask(s1_req_wmask),
        .req_is_write(s1_req_is_write),

        .rsp_valid(s1_rsp_valid),
        .rsp_ready(s1_rsp_ready),
        .rsp_rdata(s1_rsp_rdata),

        .rxd(uart_rxd),
        .txd(uart_txd),

        .btn_in(btn),
        .sw_in({1'b0, sw})
    );

    // -------------------------------------------------------------
    // 6. Video: DOOM Dual-Port Framebuffer (320x200 @ 8bpp) & HDMI TX
    // -------------------------------------------------------------
    doom_framebuffer_hdmi u_video (
        .cpu_clk(clk25MHz),
        .cpu_rst(sys_rst),

        .req_valid(s2_req_valid),
        .req_ready(s2_req_ready),
        .req_addr(s2_req_addr),
        .req_wdata(s2_req_wdata),
        .req_wmask(s2_req_wmask),
        .req_is_write(s2_req_is_write),

        .rsp_valid(s2_rsp_valid),
        .rsp_ready(s2_rsp_ready),
        .rsp_rdata(s2_rsp_rdata),

        .pixclk(clk25MHz),
        .clk_tmds(clk_tmds),
        .pix_rst(sys_rst),

        .hdmi_tx_clk_p(hdmi_tx_clk_p),
        .hdmi_tx_clk_n(hdmi_tx_clk_n),
        .hdmi_tx_p(hdmi_tx_p),
        .hdmi_tx_n(hdmi_tx_n)
    );

    // -------------------------------------------------------------
    // 7. Zynq PS7 (512 MB DDR3) via AXI4 HP0: data cache (slave 3) + icache
    // -------------------------------------------------------------
    wire [31:0] dmem_axi_awaddr, dmem_axi_wdata, dmem_axi_araddr, dmem_axi_rdata;
    wire [7:0]  dmem_axi_awlen, dmem_axi_arlen;
    wire [2:0]  dmem_axi_awsize, dmem_axi_arsize, dmem_axi_awprot, dmem_axi_arprot;
    wire [1:0]  dmem_axi_awburst, dmem_axi_arburst, dmem_axi_bresp, dmem_axi_rresp;
    wire [3:0]  dmem_axi_awcache, dmem_axi_arcache, dmem_axi_wstrb;
    wire        dmem_axi_awvalid, dmem_axi_awready, dmem_axi_wvalid, dmem_axi_wready, dmem_axi_wlast;
    wire        dmem_axi_bvalid, dmem_axi_bready, dmem_axi_arvalid, dmem_axi_arready;
    wire        dmem_axi_rvalid, dmem_axi_rready, dmem_axi_rlast;

    zynq_soc_wrapper u_zynq_soc (
        .DDR_addr(DDR_addr),
        .DDR_ba(DDR_ba),
        .DDR_cas_n(DDR_cas_n),
        .DDR_ck_n(DDR_ck_n),
        .DDR_ck_p(DDR_ck_p),
        .DDR_cke(DDR_cke),
        .DDR_cs_n(DDR_cs_n),
        .DDR_dm(DDR_dm),
        .DDR_dq(DDR_dq),
        .DDR_dqs_n(DDR_dqs_n),
        .DDR_dqs_p(DDR_dqs_p),
        .DDR_odt(DDR_odt),
        .DDR_ras_n(DDR_ras_n),
        .DDR_reset_n(DDR_reset_n),
        .DDR_we_n(DDR_we_n),
        .FIXED_IO_ddr_vrn(FIXED_IO_ddr_vrn),
        .FIXED_IO_ddr_vrp(FIXED_IO_ddr_vrp),
        .FIXED_IO_mio(FIXED_IO_mio),
        .FIXED_IO_ps_clk(FIXED_IO_ps_clk),
        .FIXED_IO_ps_porb(FIXED_IO_ps_porb),
        .FIXED_IO_ps_srstb(FIXED_IO_ps_srstb),
        .clk_25mhz(clk25MHz),
        .reset_n(~sys_rst),

        // Data cache
        .s_axi_dmem_awid(1'b0),
        .s_axi_dmem_awaddr(dmem_axi_awaddr),
        .s_axi_dmem_awlen(dmem_axi_awlen),
        .s_axi_dmem_awsize(dmem_axi_awsize),
        .s_axi_dmem_awburst(dmem_axi_awburst),
        .s_axi_dmem_awlock(1'b0),
        .s_axi_dmem_awcache(dmem_axi_awcache),
        .s_axi_dmem_awprot(dmem_axi_awprot),
        .s_axi_dmem_awqos(4'd0),
        .s_axi_dmem_awvalid(dmem_axi_awvalid),
        .s_axi_dmem_awready(dmem_axi_awready),
        .s_axi_dmem_wdata(dmem_axi_wdata),
        .s_axi_dmem_wstrb(dmem_axi_wstrb),
        .s_axi_dmem_wlast(dmem_axi_wlast),
        .s_axi_dmem_wvalid(dmem_axi_wvalid),
        .s_axi_dmem_wready(dmem_axi_wready),
        .s_axi_dmem_bid(),
        .s_axi_dmem_bresp(dmem_axi_bresp),
        .s_axi_dmem_bvalid(dmem_axi_bvalid),
        .s_axi_dmem_bready(dmem_axi_bready),
        .s_axi_dmem_arid(1'b0),
        .s_axi_dmem_araddr(dmem_axi_araddr),
        .s_axi_dmem_arlen(dmem_axi_arlen),
        .s_axi_dmem_arsize(dmem_axi_arsize),
        .s_axi_dmem_arburst(dmem_axi_arburst),
        .s_axi_dmem_arlock(1'b0),
        .s_axi_dmem_arcache(dmem_axi_arcache),
        .s_axi_dmem_arprot(dmem_axi_arprot),
        .s_axi_dmem_arqos(4'd0),
        .s_axi_dmem_arvalid(dmem_axi_arvalid),
        .s_axi_dmem_arready(dmem_axi_arready),
        .s_axi_dmem_rid(),
        .s_axi_dmem_rdata(dmem_axi_rdata),
        .s_axi_dmem_rresp(dmem_axi_rresp),
        .s_axi_dmem_rlast(dmem_axi_rlast),
        .s_axi_dmem_rvalid(dmem_axi_rvalid),
        .s_axi_dmem_rready(dmem_axi_rready),

        // Instruction cache (read only)
        .s_axi_imem_awid(1'b0),
        .s_axi_imem_awaddr(32'd0),
        .s_axi_imem_awlen(8'd0),
        .s_axi_imem_awsize(3'b010),
        .s_axi_imem_awburst(2'b01),
        .s_axi_imem_awlock(1'b0),
        .s_axi_imem_awcache(4'b0011),
        .s_axi_imem_awprot(3'b000),
        .s_axi_imem_awqos(4'd0),
        .s_axi_imem_awvalid(1'b0),
        .s_axi_imem_awready(),
        .s_axi_imem_wdata(32'd0),
        .s_axi_imem_wstrb(4'd0),
        .s_axi_imem_wlast(1'b0),
        .s_axi_imem_wvalid(1'b0),
        .s_axi_imem_wready(),
        .s_axi_imem_bid(),
        .s_axi_imem_bresp(),
        .s_axi_imem_bvalid(),
        .s_axi_imem_bready(1'b1),
        .s_axi_imem_arid(1'b0),
        .s_axi_imem_araddr(imem_axi_araddr),
        .s_axi_imem_arlen(imem_axi_arlen),
        .s_axi_imem_arsize(imem_axi_arsize),
        .s_axi_imem_arburst(imem_axi_arburst),
        .s_axi_imem_arlock(1'b0),
        .s_axi_imem_arcache(imem_axi_arcache),
        .s_axi_imem_arprot(imem_axi_arprot),
        .s_axi_imem_arqos(4'd0),
        .s_axi_imem_arvalid(imem_axi_arvalid),
        .s_axi_imem_arready(imem_axi_arready),
        .s_axi_imem_rid(),
        .s_axi_imem_rdata(imem_axi_rdata),
        .s_axi_imem_rresp(imem_axi_rresp),
        .s_axi_imem_rlast(imem_axi_rlast),
        .s_axi_imem_rvalid(imem_axi_rvalid),
        .s_axi_imem_rready(imem_axi_rready)
    );

    // Data cache in front of DDR3 (0x1xxx_xxxx cached, 0x2xxx_xxxx uncached alias)
    dcache u_dcache (
        .clk(clk25MHz),
        .rst(sys_rst),
        .req_valid(s3_req_valid),
        .req_ready(s3_req_ready),
        .req_addr(s3_req_addr),
        .req_wdata(s3_req_wdata),
        .req_wmask(s3_req_wmask),
        .req_is_write(s3_req_is_write),
        .rsp_valid(s3_rsp_valid),
        .rsp_ready(s3_rsp_ready),
        .rsp_rdata(s3_rsp_rdata),

        .m_axi_awaddr(dmem_axi_awaddr),
        .m_axi_awlen(dmem_axi_awlen),
        .m_axi_awsize(dmem_axi_awsize),
        .m_axi_awburst(dmem_axi_awburst),
        .m_axi_awcache(dmem_axi_awcache),
        .m_axi_awprot(dmem_axi_awprot),
        .m_axi_awvalid(dmem_axi_awvalid),
        .m_axi_awready(dmem_axi_awready),
        .m_axi_wdata(dmem_axi_wdata),
        .m_axi_wstrb(dmem_axi_wstrb),
        .m_axi_wlast(dmem_axi_wlast),
        .m_axi_wvalid(dmem_axi_wvalid),
        .m_axi_wready(dmem_axi_wready),
        .m_axi_bresp(dmem_axi_bresp),
        .m_axi_bvalid(dmem_axi_bvalid),
        .m_axi_bready(dmem_axi_bready),
        .m_axi_araddr(dmem_axi_araddr),
        .m_axi_arlen(dmem_axi_arlen),
        .m_axi_arsize(dmem_axi_arsize),
        .m_axi_arburst(dmem_axi_arburst),
        .m_axi_arcache(dmem_axi_arcache),
        .m_axi_arprot(dmem_axi_arprot),
        .m_axi_arvalid(dmem_axi_arvalid),
        .m_axi_arready(dmem_axi_arready),
        .m_axi_rdata(dmem_axi_rdata),
        .m_axi_rresp(dmem_axi_rresp),
        .m_axi_rlast(dmem_axi_rlast),
        .m_axi_rvalid(dmem_axi_rvalid),
        .m_axi_rready(dmem_axi_rready)
    );

    // -------------------------------------------------------------
    // 8. Heartbeat & Diagnostic LEDs
    // -------------------------------------------------------------
    reg [24:0] hb_cnt = 25'd0;
    always @(posedge clk25MHz) begin
        if (sys_rst) hb_cnt <= 25'd0;
        else hb_cnt <= hb_cnt + 25'd1;
    end

    // LED 2: Responsive pulse stretcher (~83ms) triggered on ANY instruction fetch or bus request
    reg [20:0] led2_stretcher = 21'd0;
    always @(posedge clk25MHz) begin
        if (sys_rst) begin
            led2_stretcher <= 21'd0;
        end else if (imem_req_valid || s0_req_valid || s1_req_valid || s2_req_valid || s3_req_valid) begin
            led2_stretcher <= 21'h1FFFFF;
        end else if (led2_stretcher != 21'd0) begin
            led2_stretcher <= led2_stretcher - 21'd1;
        end
    end

    assign led[0] = pll_locked;
    assign led[1] = hb_cnt[24];                 // ~0.75 Hz Heartbeat blink
    assign led[2] = (led2_stretcher != 21'd0);  // Solid ON when CPU is executing or bus active
    assign led[3] = ~uart_rxd | (|btn) | (|sw); // Blinks on UART RX or when buttons/switches active

endmodule
