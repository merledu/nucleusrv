// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VNUCLEUSRV_SOC_TOP_H_
#define VERILATED_VNUCLEUSRV_SOC_TOP_H_  // guard

#include "verilated.h"
#include "verilated_save.h"
#include "svdpi.h"

class Vnucleusrv_soc_top__Syms;
class Vnucleusrv_soc_top___024root;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vnucleusrv_soc_top VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vnucleusrv_soc_top__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk,0,0);
    VL_OUT8(&hdmi_tx_clk_p,0,0);
    VL_IN8(&btn_rst,0,0);
    VL_IN8(&uart_rxd,0,0);
    VL_OUT8(&uart_txd,0,0);
    VL_OUT8(&hdmi_tx_clk_n,0,0);
    VL_OUT8(&hdmi_tx_p,2,0);
    VL_OUT8(&hdmi_tx_n,2,0);
    VL_OUT8(&led,3,0);
    VL_IN8(&btn,3,0);
    VL_IN8(&sw,2,0);
    VL_INOUT8(&DDR_ba,2,0);
    VL_INOUT8(&DDR_cas_n,0,0);
    VL_INOUT8(&DDR_ck_n,0,0);
    VL_INOUT8(&DDR_ck_p,0,0);
    VL_INOUT8(&DDR_cke,0,0);
    VL_INOUT8(&DDR_cs_n,0,0);
    VL_INOUT8(&DDR_dm,3,0);
    VL_INOUT8(&DDR_dqs_n,3,0);
    VL_INOUT8(&DDR_dqs_p,3,0);
    VL_INOUT8(&DDR_odt,0,0);
    VL_INOUT8(&DDR_ras_n,0,0);
    VL_INOUT8(&DDR_reset_n,0,0);
    VL_INOUT8(&DDR_we_n,0,0);
    VL_INOUT8(&FIXED_IO_ddr_vrn,0,0);
    VL_INOUT8(&FIXED_IO_ddr_vrp,0,0);
    VL_INOUT8(&FIXED_IO_ps_clk,0,0);
    VL_INOUT8(&FIXED_IO_ps_porb,0,0);
    VL_INOUT8(&FIXED_IO_ps_srstb,0,0);
    VL_INOUT16(&DDR_addr,14,0);
    VL_INOUT(&DDR_dq,31,0);
    VL_INOUT64(&FIXED_IO_mio,53,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vnucleusrv_soc_top___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vnucleusrv_soc_top(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vnucleusrv_soc_top(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vnucleusrv_soc_top();
  private:
    VL_UNCOPYABLE(Vnucleusrv_soc_top);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Serialization functions
    friend VerilatedSerialize& operator<<(VerilatedSerialize& os, Vnucleusrv_soc_top& rhs);
    friend VerilatedDeserialize& operator>>(VerilatedDeserialize& os, Vnucleusrv_soc_top& rhs);

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
};

#endif  // guard
