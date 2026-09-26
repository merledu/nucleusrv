// ============================================================================
// File: fpga/clk_wiz_0.v
// Module: clk_wiz_0
// Description: Clock Generator using Xilinx 7-Series PLLE2_BASE primitive.
//              Generates 25 MHz (pixel clock) and 125 MHz (5x TMDS DDR clock)
//              from 125 MHz input.
// ============================================================================

`timescale 1ns / 1ps

module clk_wiz_0 (
    input  wire clk_in1,  // 125 MHz input clock (Zybo onboard osc)
    input  wire reset,    // Reset (active high)
    output wire clk_out1, // 25 MHz pixel clock
    output wire clk_out2, // 125 MHz TMDS 5x clock (for OSERDESE2 DDR)
    output wire clk_out3, // 10 MHz CPU clock
    output wire locked    // PLL locked signal
);

    wire clkfb;
    wire clkout0_buf;
    wire clkout1_buf;
    wire clkout2_buf;

    PLLE2_BASE #(
        .BANDWIDTH("OPTIMIZED"),
        .CLKFBOUT_MULT(8),       // VCO = 125 MHz * 8 = 1000 MHz
        .CLKFBOUT_PHASE(0.0),
        .CLKIN1_PERIOD(8.000),   // 125 MHz input period = 8.0ns
        .CLKOUT0_DIVIDE(40),     // 1000 MHz / 40 = 25 MHz
        .CLKOUT0_DUTY_CYCLE(0.5),
        .CLKOUT0_PHASE(0.0),
        .CLKOUT1_DIVIDE(8),      // 1000 MHz / 8 = 125 MHz
        .CLKOUT1_DUTY_CYCLE(0.5),
        .CLKOUT1_PHASE(0.0),
        .CLKOUT2_DIVIDE(100),    // 1000 MHz / 100 = 10 MHz
        .CLKOUT2_DUTY_CYCLE(0.5),
        .CLKOUT2_PHASE(0.0),
        .DIVCLK_DIVIDE(1),
        .REF_JITTER1(0.010),
        .STARTUP_WAIT("FALSE")
    ) pll_inst (
        .CLKOUT0(clkout0_buf),
        .CLKOUT1(clkout1_buf),
        .CLKOUT2(clkout2_buf),
        .CLKOUT3(),
        .CLKOUT4(),
        .CLKOUT5(),
        .CLKFBOUT(clkfb),
        .LOCKED(locked),
        .CLKIN1(clk_in1),
        .PWRDWN(1'b0),
        .RST(reset),
        .CLKFBIN(clkfb)
    );

    BUFG bufg_out1 (
        .I(clkout0_buf),
        .O(clk_out1)
    );

    BUFG bufg_out2 (
        .I(clkout1_buf),
        .O(clk_out2)
    );

    BUFG bufg_out3 (
        .I(clkout2_buf),
        .O(clk_out3)
    );

endmodule
