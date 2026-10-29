// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vnucleusrv_soc_top__pch.h"

//============================================================
// Constructors

Vnucleusrv_soc_top::Vnucleusrv_soc_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vnucleusrv_soc_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , hdmi_tx_clk_p{vlSymsp->TOP.hdmi_tx_clk_p}
    , btn_rst{vlSymsp->TOP.btn_rst}
    , uart_rxd{vlSymsp->TOP.uart_rxd}
    , uart_txd{vlSymsp->TOP.uart_txd}
    , hdmi_tx_clk_n{vlSymsp->TOP.hdmi_tx_clk_n}
    , hdmi_tx_p{vlSymsp->TOP.hdmi_tx_p}
    , hdmi_tx_n{vlSymsp->TOP.hdmi_tx_n}
    , led{vlSymsp->TOP.led}
    , btn{vlSymsp->TOP.btn}
    , sw{vlSymsp->TOP.sw}
    , DDR_ba{vlSymsp->TOP.DDR_ba}
    , DDR_cas_n{vlSymsp->TOP.DDR_cas_n}
    , DDR_ck_n{vlSymsp->TOP.DDR_ck_n}
    , DDR_ck_p{vlSymsp->TOP.DDR_ck_p}
    , DDR_cke{vlSymsp->TOP.DDR_cke}
    , DDR_cs_n{vlSymsp->TOP.DDR_cs_n}
    , DDR_dm{vlSymsp->TOP.DDR_dm}
    , DDR_dqs_n{vlSymsp->TOP.DDR_dqs_n}
    , DDR_dqs_p{vlSymsp->TOP.DDR_dqs_p}
    , DDR_odt{vlSymsp->TOP.DDR_odt}
    , DDR_ras_n{vlSymsp->TOP.DDR_ras_n}
    , DDR_reset_n{vlSymsp->TOP.DDR_reset_n}
    , DDR_we_n{vlSymsp->TOP.DDR_we_n}
    , FIXED_IO_ddr_vrn{vlSymsp->TOP.FIXED_IO_ddr_vrn}
    , FIXED_IO_ddr_vrp{vlSymsp->TOP.FIXED_IO_ddr_vrp}
    , FIXED_IO_ps_clk{vlSymsp->TOP.FIXED_IO_ps_clk}
    , FIXED_IO_ps_porb{vlSymsp->TOP.FIXED_IO_ps_porb}
    , FIXED_IO_ps_srstb{vlSymsp->TOP.FIXED_IO_ps_srstb}
    , DDR_addr{vlSymsp->TOP.DDR_addr}
    , DDR_dq{vlSymsp->TOP.DDR_dq}
    , FIXED_IO_mio{vlSymsp->TOP.FIXED_IO_mio}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vnucleusrv_soc_top::Vnucleusrv_soc_top(const char* _vcname__)
    : Vnucleusrv_soc_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vnucleusrv_soc_top::~Vnucleusrv_soc_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vnucleusrv_soc_top___024root___eval_debug_assertions(Vnucleusrv_soc_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vnucleusrv_soc_top___024root___eval_static(Vnucleusrv_soc_top___024root* vlSelf);
void Vnucleusrv_soc_top___024root___eval_initial(Vnucleusrv_soc_top___024root* vlSelf);
void Vnucleusrv_soc_top___024root___eval_settle(Vnucleusrv_soc_top___024root* vlSelf);
void Vnucleusrv_soc_top___024root___eval(Vnucleusrv_soc_top___024root* vlSelf);

void Vnucleusrv_soc_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vnucleusrv_soc_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vnucleusrv_soc_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vnucleusrv_soc_top___024root___eval_static(&(vlSymsp->TOP));
        Vnucleusrv_soc_top___024root___eval_initial(&(vlSymsp->TOP));
        Vnucleusrv_soc_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vnucleusrv_soc_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vnucleusrv_soc_top::eventsPending() { return false; }

uint64_t Vnucleusrv_soc_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vnucleusrv_soc_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vnucleusrv_soc_top___024root___eval_final(Vnucleusrv_soc_top___024root* vlSelf);

VL_ATTR_COLD void Vnucleusrv_soc_top::final() {
    Vnucleusrv_soc_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vnucleusrv_soc_top::hierName() const { return vlSymsp->name(); }
const char* Vnucleusrv_soc_top::modelName() const { return "Vnucleusrv_soc_top"; }
unsigned Vnucleusrv_soc_top::threads() const { return 1; }
void Vnucleusrv_soc_top::prepareClone() const { contextp()->prepareClone(); }
void Vnucleusrv_soc_top::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vnucleusrv_soc_top::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vnucleusrv_soc_top::trace()' called on model that was Verilated without --trace option");
}

//============================================================
// Model serialization

VerilatedSerialize& operator<<(VerilatedSerialize& os, Vnucleusrv_soc_top& rhs) {
    Verilated::quiesce();
    rhs.vlSymsp->__Vserialize(os);
    return os;
}

VerilatedDeserialize& operator>>(VerilatedDeserialize& os, Vnucleusrv_soc_top& rhs) {
    Verilated::quiesce();
    rhs.vlSymsp->__Vdeserialize(os);
    return os;
}
