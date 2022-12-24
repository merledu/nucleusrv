from re import search, sub, split
from argparse import ArgumentParser

class AssemblyParser:
    def __init__(self, fileName):
        self.hexList = []

        # Reading dump file
        with open(fileName, 'r', encoding='UTF-8') as f:
            elfLog = f.readlines()

        elfLog = [sub('\n', '', _) for _ in elfLog]

        # Refining the log
        self.logList = [_ for _ in elfLog if search('^[0-9a-f]+:\s+[0-9a-f]+.+', _)]
        self.logList = [split('\s+', _) for _ in self.logList]


    def dumpHex(self, hexFile):
        # Write assembly.hex
        self.hexList = [_[1] for _ in self.logList]

        with open(hexFile, 'w', encoding='UTF-8') as f:
            for i in range(len(self.hexList)):
                f.write(f'{self.hexList[i]}\n')
            f.write('\n')


def main():
    parser = ArgumentParser()
    parser.add_argument('--asm', type=str, help='Input objdump assembly file')
    parser.add_argument('--hex', type=str, help='Output hex file')
    args = parser.parse_args()

    asmParser = AssemblyParser(args.asm)
    asmParser.dumpHex(args.hex)

if __name__ == '__main__':
    main()
