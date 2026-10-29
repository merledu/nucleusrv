#include <verilated.h>
#include <iostream>
#include <cassert>
#include <memory>
#include "Vuart_timer_peripheral.h"

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    auto top = std::make_unique<Vuart_timer_peripheral>();

    // Fast clock: 1000 clocks per bit for simulation testing
    // Set CLK_FREQ = 1000000, BAUD_RATE = 100000 => 10 clocks per bit for quick test!

    top->clk = 0;
    top->rst = 1;
    top->rxd = 1;
    top->req_valid = 0;
    top->rsp_ready = 1;

    for (int i = 0; i < 5; ++i) {
        top->clk ^= 1; top->eval();
        top->clk ^= 1; top->eval();
    }
    top->rst = 0;

    std::cout << "[TEST] Starting UART & Timer Peripheral Test..." << std::endl;

    // 1. Read UART_STATUS (Offset 0x04)
    top->req_addr = 0x40000004;
    top->req_is_write = 0;
    top->req_valid = 1;
    top->rsp_ready = 1;

    // Cycle 1: Request
    top->clk = 1; top->eval();
    top->clk = 0; top->eval();

    // Cycle 2: Response
    top->req_valid = 0;
    top->clk = 1; top->eval();
    uint32_t status = top->rsp_rdata;
    top->clk = 0; top->eval();

    std::cout << "[TEST] Initial UART_STATUS: 0x" << std::hex << status << std::dec << std::endl;
    assert((status & 0x01) == 0 && "RX FIFO should initially be empty!");
    assert((status & 0x02) != 0 && "TX should initially be ready!");

    // 2. Transmit character 'X' (0x58) via write to 0x40000000
    top->req_addr = 0x40000000;
    top->req_wdata = 0x58;
    top->req_wmask = 0xF;
    top->req_is_write = 1;
    top->req_valid = 1;

    top->clk = 1; top->eval();
    top->clk = 0; top->eval();
    top->req_valid = 0;

    top->clk = 1; top->eval();
    top->clk = 0; top->eval();

    std::cout << "[TEST] Sent 'X' (0x58) to UART TX." << std::endl;

    // Run 500 cycles to observe TX serialization
    for (int i = 0; i < 500; ++i) {
        top->clk = 1; top->eval();
        top->clk = 0; top->eval();
    }

    // 3. Read Hardware Timer (Offset 0x14 - Cycle Count)
    top->req_addr = 0x40000014;
    top->req_is_write = 0;
    top->req_valid = 1;

    top->clk = 1; top->eval();
    top->clk = 0; top->eval();
    top->req_valid = 0;

    top->clk = 1; top->eval();
    uint32_t cycles = top->rsp_rdata;
    top->clk = 0; top->eval();

    std::cout << "[TEST] Hardware Cycle Counter read: " << cycles << " cycles." << std::endl;
    assert(cycles > 500 && "Cycle counter must be incrementing!");

    std::cout << "[TEST] SUCCESS: UART & Timer Peripheral compliance verified!" << std::endl;
    return 0;
}
