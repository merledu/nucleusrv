import argparse


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--log', type=str, help='core log file')
    parser.add_argument('--signature', type=str, help='core signature file')
    args = parser.parse_args()
    
    signatures = []

    with open(args.log, 'r') as file:
        for line in file:
            columns = line.split()
            mem_wdata = columns[13]
            mem_inst_str = columns[14]
            print(mem_wdata)
            print(mem_inst_str)
            if mem_inst_str == "sw":
                signatures.append(mem_wdata + '\n')

    end_mark = signatures[0]
    valid_sigs = []
    check_flag = False

    for i in range(len(signatures)):
        if i > 0:
            check_flag = True
        if check_flag and end_mark == signatures[i]:
            break
        valid_sigs.append(signatures[i])
        
    with open(args.signature, 'w', encoding='UTF-8') as f:
        for sig in valid_sigs:
            f.write(sig) 
    
    # return None


if __name__ == '__main__':
    main()
