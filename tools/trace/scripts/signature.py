import argparse
def count_lines_and_trim_file(file_path1, file_path2):

    with open(file_path1, 'r') as file1:
        lines_count = len(file1.readlines())
        print(lines_count)

    with open(file_path2, 'r') as file2:
        lines = [line.strip() for line in file2.readlines()]

    trimmed_lines = lines[:lines_count]
    print(trimmed_lines)

    with open(file_path2, 'w') as file2:
        file2.write('\n'.join(trimmed_lines))

    return trimmed_lines

#driverscode
parser = argparse.ArgumentParser()
parser.add_argument('--signature', type=str, help='core signature file')
parser.add_argument('--reference', type=str, help='reference file')
args = parser.parse_args()
# file_path1 = '/home/hamna/Downloads/nucleusrv/imperas-riscv-tests/riscv-test-suite/rv32i_m/C/references/C-ADDI16SP-01.reference_output'  
# file_path2 = '/home/hamna/Downloads/nucleusrv/imperas-riscv-tests/work/rv32i_m/C/C-ADDI16SP-01.signature.output'  

trimmed_lines = count_lines_and_trim_file(args.reference, args.signature)

print("Trimmed lines:")
for line in trimmed_lines:
    print(line)

print(f"Trimmed data written back to {args.signature}.")
