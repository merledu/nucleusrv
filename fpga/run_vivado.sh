#!/usr/bin/env bash
# Helper script to run Vivado batch build for NucleusRV DOOM on Zybo Z7

set -e

VIVADO_CMD="vivado"

if ! command -v vivado &> /dev/null; then
    if [ -f "/opt/vivado_2018.2/settings64.sh" ]; then
        source /opt/vivado_2018.2/settings64.sh
    fi
fi

if ! command -v vivado &> /dev/null; then
    # Try searching common paths
    POSSIBLE_VIVADO=$(find /opt /tools /home -name "vivado" -type f -executable 2>/dev/null | head -n 1)
    if [ -n "$POSSIBLE_VIVADO" ]; then
        VIVADO_CMD="$POSSIBLE_VIVADO"
    else
        echo "=========================================================="
        echo "Error: 'vivado' not found in PATH."
        echo "Please load your Vivado environment first, for example:"
        echo "  source /path/to/Xilinx/Vivado/<version>/settings64.sh"
        echo "Then run this script again."
        echo "=========================================================="
        exit 1
    fi
fi

echo "=========================================================="
echo "Starting Vivado Bitstream Build for Zybo Z7-10..."
echo "Vivado Executable: $VIVADO_CMD"
echo "=========================================================="

$VIVADO_CMD -mode batch -source fpga/build_bitstream.tcl
