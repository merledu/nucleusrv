#!/usr/bin/env bash
# Environment setup for NucleusRV development

export RISCV_TOOLCHAIN="/tools/riscv/riscv32-elf-ubuntu-24.04-gcc-nightly-2025.01.20-nightly"
export PATH="${RISCV_TOOLCHAIN}/bin:/tools/spike/bin:${PATH}"
export NRV_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo "=== NucleusRV Environment Initialized ==="
echo "NRV_ROOT:        ${NRV_ROOT}"
echo "RISC-V GCC:      $(which riscv32-unknown-elf-gcc 2>/dev/null || echo 'Not Found')"
echo "SBT:             $(which sbt 2>/dev/null || echo 'Not Found')"
echo "Verilator:       $(which verilator 2>/dev/null || echo 'Not Found')"
echo "========================================="
