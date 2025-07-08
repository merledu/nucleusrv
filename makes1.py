#!/bin/bash

# Define your list of test names
test_names=(
    "VADD-VX-SEW8_LMUL1"
    "VADD-VX-SEW16_LMUL1"
    "VADD-VX-SEW32_LMUL1"
)

# Set your device and ISA parameters
DEVICE="v"   # Example: 'v' for vector tests, change this if needed
ISA="rv32i"  # Example ISA, adjust according to your setup

# Loop through each test in the list
for TEST in "${test_names[@]}"; do
    echo "Running compliance test for: $TEST"
    
    # Run the original run_compliance script for each test
    ./run_compliance.sh "$ISA" "$TEST" "$DEVICE"
    
    # Check if the previous command ran successfully
    if [ $? -eq 0 ]; then
        echo "Test $TEST completed successfully."
    else
        echo "Test $TEST failed."
        exit 1  # Exit the loop if any test fails
    fi
done

echo "All tests completed."

