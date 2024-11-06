#!/bin/bash

# Directory and file paths
V_REPORT_DIR="v_report"
DIFF_FILE="/home/mlatif/nucleusrv/imperas-riscv-tests/work/rv32i_m/Vi/VADD-VX-SEW8_LMUL1.diff"
CSV_FILE="$V_REPORT_DIR/comparison_report.csv"
DIFF_FILENAME=$(basename "$DIFF_FILE")

# Create v_report directory if it doesn't exist
if [ ! -d "$V_REPORT_DIR" ]; then
  mkdir "$V_REPORT_DIR"
fi

# Initialize the CSV file with headers
echo "File Name, Status" > "$CSV_FILE"

# Check if the .diff file exists
if [ ! -f "$DIFF_FILE" ]; then
  echo "Error: Diff file not found!" >> "$CSV_FILE"
  exit 1
fi

# Read and compare values from the diff file
ALL_PASS=true
while IFS= read -r line
do
  # Split the line into two values using space as delimiter
  value1=$(echo $line | awk '{print $1}')
  value2=$(echo $line | awk '{print $2}')
  
  # Compare the two values
  if [ "$value1" != "$value2" ]; then
    ALL_PASS=false
  fi
done < "$DIFF_FILE"

# Write the file name and pass/fail status to the CSV file
if [ "$ALL_PASS" = true ]; then
  echo "$DIFF_FILENAME, PASS" >> "$CSV_FILE"
else
  echo "$DIFF_FILENAME, FAIL" >> "$CSV_FILE"
fi

echo "Comparison completed. CSV report generated at $CSV_FILE."

