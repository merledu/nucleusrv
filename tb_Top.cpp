#include <verilated.h>
#include "VTop.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    VTop* top = new VTop;

    vluint64_t main_time = 0; // Current simulation time
    const vluint64_t sim_time = 10000; // Simulation time in cycles

    while (!Verilated::gotFinish() && main_time < sim_time) {
        if (main_time % 2 == 0) {
            top->clock = 1;  // Toggle clock
        } else {
            top->clock = 0;
        }

        if (main_time < 10) {
            top->reset = 1;  // Assert reset
        } else {
            top->reset = 0;  // Deassert reset
        }

        top->eval();  // Evaluate model

        main_time++;  // Time passes...
    }

    delete top;

    return 0;
}
