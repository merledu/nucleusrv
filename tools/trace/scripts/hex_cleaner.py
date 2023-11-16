import argparse
parser = argparse.ArgumentParser()
parser.add_argument('--hex', type=str, help='core hex file')
args = parser.parse_args()
a = f"{args.hex}"

file = open(a, 'r')
hex = file.read()

input_data = hex

lines = input_data.split('\n')
output_lines = []

cafe_found = False

for line in lines:
	output_lines.append(line)
	if "cafe" in line or "deadbeef" in line or "babe" in line:
		cafe_found = True
	if cafe_found:
		output_lines.remove(line)

file.close()
result = '\n'.join(output_lines)

file2 = open(a, 'w')
file2.write(result)
file2.close()
