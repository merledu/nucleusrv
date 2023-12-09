import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--log', type=str, help='imperas log file')
parser.add_argument('--signature', type = str, help='output signature file')
args = parser.parse_args()

signatures = []
with open(args.log, 'r') as file:
    for line in file:
        
        if "deadbeef" in line:
            break
        if len(line.strip()) == 8:
            signatures.append(line.strip())

with open(args.signature, 'w')as sig:
    for i in signatures:
        sig.write(i+'\n')
