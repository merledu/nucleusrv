from argparse import ArgumentParser
from os.path import join

if __name__ == '__main__':
    parser = ArgumentParser()
    parser.add_argument('out', help = 'Output directory path,')
    args = parser.parse_args()
    print('In the slplitter')
    with open(
        join(args.out, 'dmem0.hex')
    ) as f:
        data = f.readlines()
    dmem = tuple(
        (data[2 * i], data[2 * i + 1])
        for i in range(len(data) // 2)
    )
    for i in range(2):
        with open(
            join(args.out, f'dmem{i}.hex'
        ), 'w') as f:
            for j in range(len(dmem)):
                print(f'{dmem[j][i] = }')
                f.write(dmem[j][i])
