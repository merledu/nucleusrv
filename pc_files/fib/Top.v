// NucleusRV on Arty A7-100T -- fibonacci PASS display.
//
// SW0 DOWN = hold reset.  SW0 UP = run.  Green LEDs LD4..LD7.
// The RGB LEDs (silkscreen LD0..LD3) are held off.
//
//   PASS  fib(10) = 55 :  LD4 LD5 LD6 ON, LD7 OFF   = 0111, low nibble of 55
//
// 55 is computed through all five extensions -- F builds F(1..5) in floating
// point, A accumulates F(6) atomically, I forms k = 2*F(6)-F(5), M multiplies
// F(5)*k, C encodes a fifth of it in 16 bits.  So 55 on the write-back bus is
// the proof that every one of I, M, F, A and C executed correctly; there is
// no constant 55 anywhere in the image to fake it.
//
// LD7 doubles as a life sign: it blinks off the raw 100 MHz oscillator,
// independent of the core, and goes dark only when PASS latches.  So a
// dark LD7 with dark LD4-LD6 means the bitstream/clock/pins are wrong,
// not the CPU -- an ambiguity that cost days to find the first time.
//
// The core runs from a BUFG'd divided clock (~1.56 MHz), NOT 100 MHz.
// This is a full RV32GC core (FPU, FP divider, MDU, compressed decoder)
// routed by VPR, which does not close timing at 100 MHz; f4pga emits a
// bitstream regardless and the core then executes garbage.  That was the
// actual bug.  The program is ~100 instructions, so it still completes in
// about 63 microseconds -- instant to the eye.

module Top (
  input  wire CLK100MHZ,
  input  wire sw_run,
  input  wire sw_step,
  output wire g_ld4,
  output wire g_ld5,
  output wire g_ld6,
  output wire g_ld7,
  output wire rgb0_r, output wire rgb0_g, output wire rgb0_b,
  output wire rgb1_r, output wire rgb1_g, output wire rgb1_b,
  output wire rgb2_r, output wire rgb2_g, output wire rgb2_b,
  output wire rgb3_r, output wire rgb3_g, output wire rgb3_b
);

  parameter HB_BITS = 26;   // 100 MHz / 2^26 ~= 1.5 Hz blink
  parameter CLK_DIV = 6;    // core clock = 100 MHz / 2^6 = 1.5625 MHz

  // ---- 1. life sign: free running, independent of everything ----------
  reg [HB_BITS-1:0] hb_cnt = {HB_BITS{1'b0}};
  always @(posedge CLK100MHZ)
    hb_cnt <= hb_cnt + 1'b1;
  wire   heartbeat = hb_cnt[HB_BITS-1];

  // ---- 2. slow clock for the core -------------------------------------
  reg [CLK_DIV-1:0] div = {CLK_DIV{1'b0}};
  always @(posedge CLK100MHZ)
    div <= div + 1'b1;

  // Route the divided clock through a global buffer.  Without this the
  // clock reaches every flop in the core over general routing, which VPR
  // handles badly on a design this size.  BUFG is an f4pga/Yosys xc7
  // primitive; Verilator needs the one-line stub in bufg_sim.v.
  wire core_clk;
  BUFG bufg_core (.I(div[CLK_DIV-1]), .O(core_clk));

  // ---- 3. core, switch and milestones, all on the slow clock ----------
  reg  [2:0]  sw_sync = 3'b000;
  reg  [31:0] pin_d   = 32'h0;
  reg         cpu_ran  = 1'b0;   // core reached k = 11  (F, A and I done)
  reg         fib_done = 1'b0;   // core reached 55       (M done too)

  wire        sw_active = sw_sync[2];
  wire [31:0] p;

  always @(posedge core_clk) begin
    sw_sync <= {sw_sync[1:0], sw_run};
    pin_d   <= p;
    if (!sw_active) begin
      cpu_ran  <= 1'b0;
      fib_done <= 1'b0;
    end else begin
      /* 11 : k = 2*F(6) - F(5).  Reaching it means F produced F(5)=5, A
              produced F(6)=8, and I did the shift and subtract.
         55 : F(5) * k through the MDU -- the whole chain, M included.
         Simulation confirms 55 never reaches this bus if any one of the
         five extensions is broken (see tools/tests/fib5/main.c). */
      if (p == 32'd11 || pin_d == 32'd11) cpu_ran  <= 1'b1;
      if (p == 32'd55 || pin_d == 32'd55) fib_done <= 1'b1;
    end
  end

  // PASS pattern is 0111: LD4 LD5 LD6 on, LD7 off.
  assign g_ld4 = fib_done;
  assign g_ld5 = fib_done | cpu_ran;
  assign g_ld6 = fib_done | sw_active;
  assign g_ld7 = fib_done ? 1'b0 : heartbeat;

  assign rgb0_r = 1'b0; assign rgb0_g = 1'b0; assign rgb0_b = 1'b0;
  assign rgb1_r = 1'b0; assign rgb1_g = 1'b0; assign rgb1_b = 1'b0;
  assign rgb2_r = 1'b0; assign rgb2_g = 1'b0; assign rgb2_b = 1'b0;
  assign rgb3_r = 1'b0; assign rgb3_g = 1'b0; assign rgb3_b = 1'b0;

  NucleusRV nrv (
    .clock  (core_clk),
    .reset  (~sw_active),
    .io_pin (p)
  );

endmodule
