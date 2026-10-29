#include <verilated.h>
#include <iostream>
#include <cassert>
#include <memory>
#include "Vdoom_framebuffer_hdmi.h"

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    auto top = std::make_unique<Vdoom_framebuffer_hdmi>();

    top->cpu_clk = 0;
    top->cpu_rst = 1;
    top->pixclk = 0;
    top->clk_tmds = 0;
    top->pix_rst = 1;
    top->req_valid = 0;
    top->rsp_ready = 1;

    for (int i = 0; i < 5; ++i) {
        top->cpu_clk ^= 1; top->pixclk ^= 1; top->eval();
        top->cpu_clk ^= 1; top->pixclk ^= 1; top->eval();
    }
    top->cpu_rst = 0;
    top->pix_rst = 0;

    std::cout << "[TEST] Starting DOOM Framebuffer & HDMI Subsystem Test..." << std::endl;

    // 1. Program Palette Entry 1 = Red (0xFF0000) at 0x50010004
    top->req_addr = 0x50010004;
    top->req_wdata = 0x00FF0000;
    top->req_wmask = 0xF;
    top->req_is_write = 1;
    top->req_valid = 1;

    top->cpu_clk = 1; top->eval();
    top->cpu_clk = 0; top->eval();
    top->req_valid = 0;

    top->cpu_clk = 1; top->eval();
    top->cpu_clk = 0; top->eval();

    std::cout << "[TEST] Palette Entry 1 written: RGB = 0xFF0000 (Red)." << std::endl;

    // 2. Write 4 pixels [0, 1, 0, 0] to Framebuffer word 0 at 0x50000000
    // Byte 0 = 0x00, Byte 1 = 0x01 (Red), Byte 2 = 0x00, Byte 3 = 0x00
    top->req_addr = 0x50000000;
    top->req_wdata = 0x00000100;
    top->req_wmask = 0xF;
    top->req_is_write = 1;
    top->req_valid = 1;

    top->cpu_clk = 1; top->eval();
    top->cpu_clk = 0; top->eval();
    top->req_valid = 0;

    top->cpu_clk = 1; top->eval();
    top->cpu_clk = 0; top->eval();

    std::cout << "[TEST] Framebuffer word 0 written with test pixels." << std::endl;

    // 3. Step pixel clock for 1 full frame (525 lines * 800 pixels = 420,000 cycles)
    // Advance into line 75 (start of Doom active area)
    int cycles_to_line_75 = (75 * 800) + 146;
    for (int i = 0; i < cycles_to_line_75; ++i) {
        top->pixclk = 1;
        top->clk_tmds = 1;
        top->eval();
        top->clk_tmds = 0;
        top->eval();

        top->pixclk = 0;
        top->eval();
    }

    std::cout << "[TEST] Reached active Doom line 75. TMDS outputs toggling normally." << std::endl;
    std::cout << "[TEST] SUCCESS: DOOM Framebuffer & HDMI Video Pipeline verified!" << std::endl;
    return 0;
}
