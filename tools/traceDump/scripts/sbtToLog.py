from argparse import ArgumentParser
from re import match, sub, split
from icecream import ic

def readSBTlog(sbtFile):
    traceDict = {
        'ClkCycle' : [],
        'pc_rdata' : [],
        'pc_wdata' : [],
        'insn'     : [],
        'mode'     : [],
        'rs1_addr' : [],
        'rs1_rdata': [],
        'rs2_addr' : [],
        'rs2_rdata': [],
        'rd_addr'  : [],
        'rd_wdata' : [],
        'mem_addr' : [],
        'mem_rdata': [],
        'mem_wdata': []
    }

    with open(sbtFile, 'r', encoding='UTF-8') as f:
        sbtLog = f.readlines()

    trace = [
        sub('\s', '', line).split(',') for line in sbtLog
            if match('ClkCycle:\s+\d+.*', line)
    ]

    for line in trace:
        for i in range(len(line)):
            line[i] = line[i].split(':')

    for line in trace:
        for param in line:
            traceDict[param[0]].append(param[1])

    return traceDict


def readAsm(asmFile):
    with open(asmFile, 'r', encoding='UTF-8') as f:
        asm = f.readlines()

    inst = {
        split('\s+', line)[1]: split('\s+', line, maxsplit=2)[2].replace('\n', '') for line in asm
            if match('[0-9a-f]+:\s+[0-9a-f]+\s+[a-z]+', line)
    }

    for k in inst.keys():
        if match('[a-z]+\s+.+', inst[k]):
            inst[k]    = split('\s+', inst[k])
            inst[k][1] = inst[k][1].split(',')
        else:
            inst[k] = [inst[k]]

    return inst


def sbtToLog(sbtFile, asmFile, logFile):
    sbt = readSBTlog(sbtFile)
    asm = readAsm(asmFile)

    with open(logFile, 'w', encoding='UTF-8') as f:
        for k in sbt:
            f.write('{0:10}'.format(k))
        f.write('inst_str\n')

        for i in range(len(sbt['ClkCycle'])):
            for k in sbt.keys():
                f.write('{0:10}'.format(sbt[k][i]))
            inst_str = asm[sbt['insn'][i]]
            if len(inst_str) > 1:
                f.write('{0:8}{1}\n'.format(inst_str[0], ', '.join(inst_str[1])))
            else:
                f.write('{0}\n'.format(inst_str[0]))

    return


def main():
    parser = ArgumentParser()
    parser.add_argument('--sbt_dump', type=str, help='SBT dump by core')
    parser.add_argument('--asm', type=str, help='Objdump file')
    parser.add_argument('--log', type=str, help='Output core log')
    args = parser.parse_args()

    sbtToLog(args.sbt_dump, args.asm, args.log)
    
if __name__ == '__main__':
    main()
