// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vinstructioncache_sramTop.h"
#include "Vinstructioncache_sramTop__Syms.h"

//============================================================
// Constructors

Vinstructioncache_sramTop::Vinstructioncache_sramTop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vinstructioncache_sramTop__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rst_i{vlSymsp->TOP.rst_i}
    , csb_i{vlSymsp->TOP.csb_i}
    , wmask_i{vlSymsp->TOP.wmask_i}
    , we_i{vlSymsp->TOP.we_i}
    , addr_i{vlSymsp->TOP.addr_i}
    , wdata_i{vlSymsp->TOP.wdata_i}
    , rdata_o{vlSymsp->TOP.rdata_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vinstructioncache_sramTop::Vinstructioncache_sramTop(const char* _vcname__)
    : Vinstructioncache_sramTop(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vinstructioncache_sramTop::~Vinstructioncache_sramTop() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vinstructioncache_sramTop___024root___eval_initial(Vinstructioncache_sramTop___024root* vlSelf);
void Vinstructioncache_sramTop___024root___eval_settle(Vinstructioncache_sramTop___024root* vlSelf);
void Vinstructioncache_sramTop___024root___eval(Vinstructioncache_sramTop___024root* vlSelf);
#ifdef VL_DEBUG
void Vinstructioncache_sramTop___024root___eval_debug_assertions(Vinstructioncache_sramTop___024root* vlSelf);
#endif  // VL_DEBUG
void Vinstructioncache_sramTop___024root___final(Vinstructioncache_sramTop___024root* vlSelf);

static void _eval_initial_loop(Vinstructioncache_sramTop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vinstructioncache_sramTop___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vinstructioncache_sramTop___024root___eval_settle(&(vlSymsp->TOP));
        Vinstructioncache_sramTop___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vinstructioncache_sramTop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vinstructioncache_sramTop::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vinstructioncache_sramTop___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vinstructioncache_sramTop___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vinstructioncache_sramTop::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vinstructioncache_sramTop::final() {
    Vinstructioncache_sramTop___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vinstructioncache_sramTop::hierName() const { return vlSymsp->name(); }
const char* Vinstructioncache_sramTop::modelName() const { return "Vinstructioncache_sramTop"; }
unsigned Vinstructioncache_sramTop::threads() const { return 1; }
