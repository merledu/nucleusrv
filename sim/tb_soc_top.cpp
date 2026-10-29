#include <verilated.h>
#include <iostream>
#include <memory>
#include <string>
#include "Vnucleusrv_soc_top.h"
#include "Vnucleusrv_soc_top___024root.h"

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    auto top = std::make_unique<Vnucleusrv_soc_top>();

    const int CLKS_PER_BIT = 25000000 / 115200; // ~217 cycles per bit at 25MHz

    top->clk = 0;
    top->btn_rst = 1;
    top->uart_rxd = 1;

    for (int i = 0; i < 20; ++i) {
        top->clk ^= 1; top->eval();
        top->clk ^= 1; top->eval();
    }
    top->btn_rst = 0;

    std::cout << "[SOC_SIM] Core reset released. Running SoC simulation..." << std::endl;
    printf("[SOC_SIM] boot_ram[0] = 0x%08X, boot_ram[1] = 0x%08X, boot_ram[2] = 0x%08X\n",
           top->rootp->nucleusrv_soc_top__DOT__boot_ram[0],
           top->rootp->nucleusrv_soc_top__DOT__boot_ram[1],
           top->rootp->nucleusrv_soc_top__DOT__boot_ram[2]);

    // Software UART receiver in C++ testbench to capture core stdout
    enum { RX_IDLE, RX_START, RX_DATA, RX_STOP } rx_state = RX_IDLE;
    int rx_cnt = 0;
    int bit_idx = 0;
    uint8_t rx_byte = 0;
    std::string captured_output;

    // Keystroke injection state machine for uart_rxd
    enum { KEY_WAIT, KEY_START, KEY_BITS, KEY_STOP, KEY_DONE } key_state = KEY_WAIT;
    int key_cnt = 0;
    int key_bit = 0;
    uint8_t key_char = 'W'; // Inject 'W' key

    for (int cycle = 0; cycle < 1500000; ++cycle) {
        top->clk = 1; top->eval();
        if (top->rootp->nucleusrv_soc_top__DOT__dmem_req_valid) {
            uint32_t a = top->rootp->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_result;
            if (a >= 0x40000100) {
                static int vid_cnt = 0;
                if (vid_cnt < 30) {
                    vid_cnt++;
                    printf("[TARGET_REQ #%d at cycle %d] addr=0x%08X write=%d wdata=0x%08X\n",
                           vid_cnt, cycle, a, top->rootp->nucleusrv_soc_top__DOT__dmem_req_is_write,
                           top->rootp->nucleusrv_soc_top__DOT__dmem_req_wdata);
                }
            }
        }
        top->clk = 0; top->eval();

        // 1. Process Core TX (captured stdout)
        int txd = top->uart_txd;
        switch (rx_state) {
            case RX_IDLE:
                if (txd == 0) { // Start bit
                    rx_state = RX_START;
                    rx_cnt = CLKS_PER_BIT / 2;
                }
                break;
            case RX_START:
                if (--rx_cnt == 0) {
                    rx_state = RX_DATA;
                    rx_cnt = CLKS_PER_BIT;
                    bit_idx = 0;
                    rx_byte = 0;
                }
                break;
            case RX_DATA:
                if (--rx_cnt == 0) {
                    if (txd) rx_byte |= (1 << bit_idx);
                    rx_cnt = CLKS_PER_BIT;
                    if (++bit_idx == 8) {
                        rx_state = RX_STOP;
                    }
                }
                break;
            case RX_STOP:
                if (--rx_cnt == 0) {
                    rx_state = RX_IDLE;
                    captured_output += (char)rx_byte;
                    std::cout << (char)rx_byte << std::flush;
                }
                break;
        }

        // 2. Inject Key 'W' after banner has been printed (around cycle 120,000)
        switch (key_state) {
            case KEY_WAIT:
                top->uart_rxd = 1;
                if (cycle > 120000) {
                    std::cout << "\n[SOC_SIM] Injecting keypress 'W' (0x57) into uart_rxd..." << std::endl;
                    key_state = KEY_START;
                    key_cnt = CLKS_PER_BIT;
                    top->uart_rxd = 0; // Start bit
                }
                break;
            case KEY_START:
                if (--key_cnt == 0) {
                    key_state = KEY_BITS;
                    key_bit = 0;
                    key_cnt = CLKS_PER_BIT;
                    top->uart_rxd = (key_char >> key_bit) & 1;
                }
                break;
            case KEY_BITS:
                if (--key_cnt == 0) {
                    key_cnt = CLKS_PER_BIT;
                    if (++key_bit < 8) {
                        top->uart_rxd = (key_char >> key_bit) & 1;
                    } else {
                        key_state = KEY_STOP;
                        top->uart_rxd = 1; // Stop bit
                    }
                }
                break;
            case KEY_STOP:
                if (--key_cnt == 0) {
                    key_state = KEY_DONE;
                    top->uart_rxd = 1; // Idle line
                }
                break;
            case KEY_DONE:
                top->uart_rxd = 1;
                break;
        }
    }

    std::cout << "\n[SOC_SIM] Finished simulation cycles. Captured: " << captured_output << std::endl;

    // Check Framebuffer and Palette
    std::cout << "[SOC_SIM] Inspecting Palette RAM [0..7]:" << std::endl;
    for (int p = 0; p < 8; ++p) {
        printf("  Palette[%d] = 0x%06X\n", p, top->rootp->nucleusrv_soc_top__DOT__u_video__DOT__palette_ram[p]);
    }

    std::cout << "[SOC_SIM] Scanning entire 16,384 words of Framebuffer:" << std::endl;
    int non_zero_count = 0;
    for (int w = 0; w < 16384; ++w) {
        uint32_t val = top->rootp->nucleusrv_soc_top__DOT__u_video__DOT__fb_mem[w];
        if (val != 0) {
            if (non_zero_count < 10) {
                printf("  Non-zero at word %d (byte %d): 0x%08X\n", w, w*4, val);
            }
            non_zero_count++;
        }
    }
    printf("[SOC_SIM] Total non-zero words in fb_mem: %d / 16384\n", non_zero_count);
    uint32_t final_pc = top->rootp->nucleusrv_soc_top__DOT__u_core__DOT__pc__DOT__pc_reg;
    uint32_t mepc = top->rootp->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__csr__DOT__csrRegFile__DOT__MEPC_REG;
    printf("[SOC_SIM] Final PC = 0x%08X, MEPC = 0x%08X\n", final_pc, mepc);
    printf("[SOC_SIM] u_video bus_state = %d, req_ready = %d, req_valid = %d\n",
           top->rootp->nucleusrv_soc_top__DOT__u_video__DOT__bus_state,
           top->rootp->nucleusrv_soc_top__DOT__s2_req_ready,
           top->rootp->nucleusrv_soc_top__DOT__s2_req_valid);

    return 0;
}
