import argparse
from re import sub, search, split
import re

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--log', type=str, help='core log file')
    parser.add_argument('--disass', type = str, help = 'Suite Disassembly')
    parser.add_argument('--ref_sig', type = str, help = 'Refrence Signature File')
    parser.add_argument('--signature', type=str, help='core signature file')
    args = parser.parse_args()
    
    with open(args.ref_sig, 'r', encoding = 'UTF-8') as ref:
        ref_sig = ref.readlines()

    signatures = []
    sign_region = []
    
    with open(args.disass, 'r', encoding='UTF-8') as f:
        elfLog = f.readlines()

    elfLog = [sub('\n', '', _) for _ in elfLog]


    logList = [_ for _ in elfLog if search('^[0-9a-f]+:\s+[0-9a-f]+.+', _)]
    logList = [split('\s+', _) for _ in logList]

    for i in range (len(logList)-1):
        if logList[i][1] == 'deadbeef':
            sign_region.append(logList[i][0][:8])
    modified_list = ['0' + element[1:] for element in sign_region]

    with open(args.log, 'r') as file:
        for line in file:
            columns = line.split()
            mem_addr = columns[11]
            mem_wdata = columns[13]
            mem_inst_str = columns[14]
            if (mem_inst_str == "sw") and (mem_addr in modified_list):
                signatures.append(mem_wdata + "\n")

    valid_sigs = []
    for i in range(len(ref_sig)):
        valid_sigs.append(signatures[i])
        
    with open(args.signature, 'w', encoding='UTF-8') as f:
        for sig in valid_sigs:
            f.write(sig) 



if __name__ == '__main__':
    main()
