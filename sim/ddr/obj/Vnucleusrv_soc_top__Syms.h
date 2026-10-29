// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VNUCLEUSRV_SOC_TOP__SYMS_H_
#define VERILATED_VNUCLEUSRV_SOC_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vnucleusrv_soc_top.h"

// INCLUDE MODULE CLASSES
#include "Vnucleusrv_soc_top___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vnucleusrv_soc_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vnucleusrv_soc_top* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vnucleusrv_soc_top___024root   TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_TOP;
    VerilatedScope __Vscope_nucleusrv_soc_top;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_bus;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__CompressedDecoder;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__Execute;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__Execute__ForwardingUnit;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__Execute__alu;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__Execute__aluCtl;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__Execute__amoAlu;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__Execute__mdu;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__InstructionDecode;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__InstructionDecode__atomicDecoder;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__InstructionDecode__bu;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__InstructionDecode__control;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__InstructionDecode__csr;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__InstructionDecode__csrController;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__InstructionDecode__csr__csrRegFile;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__InstructionDecode__hdu;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__InstructionDecode__immediate;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__InstructionDecode__registers;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__InstructionFetch;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__MEM;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__Realigner;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__ReservationFile;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_core__pc;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_dcache;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_dcache__u_axi;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_icache;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_icache__u_axi;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_periph;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_periph__u_uart_rx;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_periph__u_uart_tx;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_pll;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_video;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_video__u_hdmi_tx;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_video__u_hdmi_tx__enc_b;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_video__u_hdmi_tx__enc_g;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_video__u_hdmi_tx__enc_r;
    VerilatedScope __Vscope_nucleusrv_soc_top__u_zynq_soc;

    // CONSTRUCTORS
    Vnucleusrv_soc_top__Syms(VerilatedContext* contextp, const char* namep, Vnucleusrv_soc_top* modelp);
    ~Vnucleusrv_soc_top__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
    void __Vserialize(VerilatedSerialize& os);
    void __Vdeserialize(VerilatedDeserialize& os);
};

#endif  // guard
