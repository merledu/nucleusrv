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
        flag = 0
        for line in range(len(data)-1):
            if "<begin_signature>" in data[line]:
                flag += 1

            if (flag == 2) and ("<end_signature>" in data[line]):
                addlist.append(data[line][0:8])
            elif (flag == 2) and ("signature" in data[line]):
                if (data[line+1][0]=="8"):
                    addlist.append(data[line+1][0:8])
                if (data[line+2][0]=="8"):
                    addlist.append(data[line+2][0:8])
                if (data[line+3][0]=="8"):
                    addlist.append(data[line+3][0:8])
                    
            
                # if ("<begin_signature>:" in line) or ("<sig_end_canary>:" in line):
                #     colums = line.split(" ")
                    
                #     addlist.append(colums[0].replace(":", ""))
                #     # print(colums)

                # if "<sig_end_canary>:" in line:
                #     startcpy = False

                # if startcpy and "<signature_" not in line:
                #     colums= line.split("\t")
                #     addlist.append(colums[0].replace(":", ""))
                # if "<signature_1_0>:" in line:
                #     startcpy = True    
        # print(addlist)
        # print(flag)
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