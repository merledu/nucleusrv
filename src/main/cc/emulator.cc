#include <verilated.h>
#include <iostream>

#include <verilated_fst_c.h>	// Trace file format header

using namespace std;

vluint64_t main_time = 0;       // Current simulation time
        // This is a 64-bit integer to reduce wrap over issues and
        // allow modulus.  You can also use a double, if you wish.

double sc_time_stamp () { // Called by $time in Verilog
  return main_time;       // converts to double, to match
                          // what SystemC does
}

VTop* top; // target design
VerilatedFstC* tfp;

// TODO Provide command-line options like vcd filename, timeout count, etc.
const long timeout = 10000L;

void tick() {
  top->clock = 1;
  top->eval();
  if (tfp) tfp->dump((double) main_time);
  main_time++;

  top->clock = 0;
  top->eval();
  if (tfp) tfp->dump((double) main_time);
  main_time++;
}

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);   // Remember args
  top = new VTop; // target design

  Verilated::traceEverOn(true);	// Verilator must compute traced signals
  VL_PRINTF("Enabling waves...\n");
  tfp = new VerilatedFstC;
  top->trace(tfp, 99);	// Trace 99 levels of hierarchy
  tfp->open("generated-src/dump.vcd"); // Open the dump file

  cout << "Starting simulation!\n";

  // reset
  top->reset = 1;
  for (size_t i = 0; i < 5 ; i++) {
    tick();
  }

  // start
  top->reset = 0;

  do {
    tick();
  } while(main_time < timeout);

  // Run for 10 more clocks
  for (size_t i = 0 ; i < 10 ; i++) {
    tick();
  }

  if (main_time >= timeout) {
    cerr << "Simulation terminated by timeout at time " << main_time
         << " (cycle " << main_time / 10 << ")"<< endl;
//    return EXIT_FAILURE;
  } else {
    cerr << "Simulation completed at time " << main_time <<
           " (cycle " << main_time / 10 << ")"<< endl;
  }

  if (tfp) tfp->close();
  delete tfp;
  delete top;

  cout << "Finishing simulation!\n";

  return 0;
}