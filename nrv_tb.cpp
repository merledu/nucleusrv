#include <verilated.h>
#include "verilated_vcd_c.h"
#include "VTop.h"

#define MAX_SIM_TIME 1500  // In cycles

int main(int argc, char **argv, char **env) {
	if (false && argc && argv && env) {}

	Verilated::mkdir("logs");

	const std::unique_ptr<VerilatedContext> contextp {new VerilatedContext};
	contextp->commandArgs(argc, argv);
	contextp->traceEverOn(true);

	VerilatedVcdC *tfp = new VerilatedVcdC;

	const std::unique_ptr<VTop> top {
		new VTop {contextp.get(), "TOP"}
	};
	top->trace(tfp, 5);

	tfp->open("logs/top.vcd");

	unsigned int sim_time = 0;
	top->clock = 1;
	while (!contextp->gotFinish() && sim_time < MAX_SIM_TIME) {
		top->clock ^= 1;  // Toggle clock
		if (sim_time <= 1) {
		    top->reset = 1;  // Assert reset
		} else {
		    top->reset = 0;  // Deassert reset
		}
		top->eval();  // Evaluate model
		tfp->dump(sim_time);
		++sim_time;
	}
	top->final();
	tfp->close();
	return 0;
}
