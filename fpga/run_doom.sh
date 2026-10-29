#!/usr/bin/env bash
# One-command runner for Full DOOM on Zybo Z7-10
set -e

XSDB_CMD="xsdb"

if ! command -v xsdb &> /dev/null; then
    if [ -f "/opt/vivado_2018.2/settings64.sh" ]; then
        source /opt/vivado_2018.2/settings64.sh
    fi
fi

if ! command -v xsdb &> /dev/null; then
    POSSIBLE_XSDB=$(find /opt /tools -name "xsdb" -type f -executable 2>/dev/null | head -n 1)
    if [ -n "$POSSIBLE_XSDB" ]; then
        XSDB_CMD="$POSSIBLE_XSDB"
    else
        echo "Error: 'xsdb' not found. Please source Vivado/SDK settings64.sh."
        exit 1
    fi
fi

echo "=========================================================="
echo "Starting Full DOOM on Digilent Zybo Z7-10..."
echo "XSDB: $XSDB_CMD"
echo "=========================================================="

$XSDB_CMD fpga/run_doom.tcl
