#include <verilated.h>
#include "verilated_vcd_c.h"
#include "VTop.h"

// NEW INCLUDES
#include <iostream>
#include <iomanip>
#include <cassert> // For assertions

#define MAX_SIM_TIME 1000 // Increased sim time to ensure code runs
#define CORE_COUNT 2      // From Top.scala NRVDriver

// --- Expected values from asm_test.S ---
const uint32_t EXP_AMO_OLD_VAL = 5;  // amoadd.w x3, ... -> x3 should be 5
const uint32_t EXP_LR_VAL = 0;       // lr.w x5, ... -> x5 should be 0
const uint32_t EXP_SC_VAL = 0;       // sc.w x7, ... -> x7 should be 0 (success)

int main(int argc, char **argv, char **env) {
    if (false && argc && argv && env) {}

    Verilated::mkdir("out/nucleusrv.components.NRVDriver/logs");

    const std::unique_ptr<VerilatedContext> contextp {new VerilatedContext};
    contextp->commandArgs(argc, argv);
    contextp->traceEverOn(true);

    VerilatedVcdC *tfp = new VerilatedVcdC;

    const std::unique_ptr<VTop> top {
        new VTop {contextp.get(), "TOP"}
    };
    top->trace(tfp, 5);

    tfp->open("out/nucleusrv.components.NRVDriver/logs/top.vcd");

    // --- Test tracking variables ---
    // We need to track checks for both cores
    bool core_checks[CORE_COUNT][3] = {0}; // [core_id][check_id]
    const int AMO_CHECK = 0;
    const int LR_CHECK = 1;
    const int SC_CHECK = 2;

    unsigned int sim_time = 0;
    top->clock = 1;
    printf("[%d] Simulation starting...\n", sim_time);

    while (!contextp->gotFinish() && sim_time < MAX_SIM_TIME) {
        top->clock ^= 1; // Toggle clock
        if (sim_time <= 1) {
            top->reset = 1; // Assert reset
        } else {
            top->reset = 0; // Deassert reset
        }
        top->eval(); // Evaluate model

        // --- Verification Logic (only check on rising clock edge) ---
        if (top->clock == 1 && top->reset == 0) {
            // Check Core 0 RVFI
            if (top->io_rvfi_0_valid_0) {
                uint8_t rd_addr = top->io_rvfi_0_rd_addr_0;
                uint32_t rd_wdata = top->io_rvfi_0_rd_wdata_0;

                // Check amoadd.w x3, ...
                if (rd_addr == 3 && !core_checks[0][AMO_CHECK]) {
                    assert(rd_wdata == EXP_AMO_OLD_VAL);
                    core_checks[0][AMO_CHECK] = true;
                }
                // Check lr.w x5, ...
                if (rd_addr == 5 && !core_checks[0][LR_CHECK]) {
                    assert(rd_wdata == EXP_LR_VAL);
                    core_checks[0][LR_CHECK] = true;
                }
                // Check sc.w x7, ...
                if (rd_addr == 7 && !core_checks[0][SC_CHECK]) {
                    assert(rd_wdata == EXP_SC_VAL);
                    core_checks[0][SC_CHECK] = true;
                }
            }

            // Check Core 1 RVFI
            if (top->io_rvfi_1_valid_0) {
                uint8_t rd_addr = top->io_rvfi_1_rd_addr_0;
                uint32_t rd_wdata = top->io_rvfi_1_rd_wdata_0;

                // Check amoadd.w x3, ...
                if (rd_addr == 3 && !core_checks[1][AMO_CHECK]) {
                    assert(rd_wdata == EXP_AMO_OLD_VAL);
                    core_checks[1][AMO_CHECK] = true;
                }
                // Check lr.w x5, ...
                if (rd_addr == 5 && !core_checks[1][LR_CHECK]) {
                    assert(rd_wdata == EXP_LR_VAL);
                    core_checks[1][LR_CHECK] = true;
                }
                // Check sc.w x7, ...
                if (rd_addr == 7 && !core_checks[1][SC_CHECK]) {
                    assert(rd_wdata == EXP_SC_VAL);
                    core_checks[1][SC_CHECK] = true;
                }
            }
        }
        
        tfp->dump(sim_time);
        ++sim_time;
    }
    printf("[%d] Simulation ended\n", sim_time);
    top->final();
    tfp->close();

    //--- Final Test Result Check ---
    bool all_passed = true;
    for (int i = 0; i < CORE_COUNT; i++) {
        for (int j = 0; j < 3; j++) {
            if (!core_checks[i][j]) {
                all_passed = false;
            }
        }
    }

    if (all_passed) {
        std::cout << "---------------------" << std::endl;
        std::cout << "    TEST PASSED!" << std::endl;
        std::cout << "---------------------" << std::endl;
    } else {
        std::cout << "---------------------" << std::endl;
        std::cout << "    TEST FAILED!" << std::endl;
        std::cout << "---------------------" << std::endl;
        for (int i = 0; i < CORE_COUNT; i++) {
            std::cout << "Core " << i << " Status:" << std::endl;
            std::cout << "  AMOADD Check: " << (core_checks[i][AMO_CHECK] ? "PASS" : "FAIL") << std::endl;
            std::cout << "  LR Check:     " << (core_checks[i][LR_CHECK] ? "PASS" : "FAIL") << std::endl;
            std::cout << "  SC Check:     " << (core_checks[i][SC_CHECK] ? "PASS" : "FAIL") << std::endl;
        }
        return 1; // Return error code
    }

    return 0;
}