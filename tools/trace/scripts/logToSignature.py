import argparse
from re import sub, search, split
import re


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--log', type=str, help='core log file')
    parser.add_argument('--disass', type=str, help='Suite Disassembly')
    parser.add_argument('--signature', type=str, help='core signature file')
    args = parser.parse_args()

    # with open(args.ref_sig, 'r', encoding='UTF-8') as ref:
    #     ref_sig = ref.readlines()

    signatures = []
    addlist = []
    startcpy = False
    with open(args.disass, "r") as f:
        data = f.readlines()
        for line in data:
            if ":" in line:
                if "<begin_signature>:" in line or "<sig_end_canary>:" in line:
                    colums = line.split(" ")
                    addlist.append(colums[0].replace(":", ""))
                    # print(colums)

                if "<sig_end_canary>:" in line:
                    startcpy = False

                if startcpy and "<signature_" not in line:
                    colums= line.split("\t")
                    addlist.append(colums[0].replace(":", ""))
                if "<signature_x1_0>:" in line:
                    startcpy = True    

    addlist = ['0' + element[1:] for element in addlist]

    with open(args.log, 'r') as file:
        for line in file:
            columns = line.split()
            mem_addr = columns[11]
            mem_wdata = columns[13]
            mem_inst_str = columns[14]
            if (mem_inst_str == "sw") and (mem_addr in addlist):
                signatures.append(mem_wdata + "\n")
    
    #print(len(addlist))
    #print(len(signatures))
    #valid_sigs = []
    #for i in range(len(addlist) - 1):
        #valid_sigs.append(signatures[i])
    
    with open(args.signature, 'w', encoding='UTF-8') as f:
        for sig in signatures:
        #for sig in valid_sigs:
            f.write(sig)


if __name__ == '__main__':
    main()
