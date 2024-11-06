import os
import csv

# Directory paths
v_report_dir = "v_report"
diff_dir = "/home/mlatif/nucleusrv/imperas-riscv-tests/work/rv32i_m/Vi"
csv_file = os.path.join(v_report_dir, "comparison_report.csv")

# Create v_report directory if it doesn't exist
if not os.path.exists(v_report_dir):
    os.makedirs(v_report_dir)

# Initialize the CSV file with headers
with open(csv_file, mode="w", newline='') as file:
    writer = csv.writer(file)
    writer.writerow(["File Name", "Status"])

# Iterate through all .diff files in the directory
diff_files = [f for f in os.listdir(diff_dir) if f.endswith(".diff")]

if not diff_files:
    print(f"Error: No .diff files found in {diff_dir}!")
    exit(1)

for diff_file in diff_files:
    diff_file_path = os.path.join(diff_dir, diff_file)
    all_pass = True

    # Read and compare values from the diff file
    with open(diff_file_path, "r") as file:
        for line in file:
            # Remove "/" from the line
            cleaned_line = line.replace("/", "")
            
            # Split the cleaned line into two values using space as the delimiter
            values = cleaned_line.split()

            # Ensure we have at least two values to compare
            if len(values) < 2:
                continue

            value1 = values[0]
            value2 = values[1]

            # Compare the two values
            if value1 != value2:
                all_pass = False

    # Strip the .diff extension from the file name
    test_file_name = os.path.splitext(diff_file)[0]

    # Write the test file name (without .diff) and pass/fail status to the CSV file
    with open(csv_file, mode="a", newline='') as file:
        writer = csv.writer(file)
        if all_pass:
            writer.writerow([test_file_name, "PASS"])
        else:
            writer.writerow([test_file_name, "FAIL"])

print(f"Comparison completed. CSV report generated at {csv_file}.")

