from os.path import \
    dirname, \
    abspath, \
    join, \
    isdir, \
    split
from subprocess import run
from argparse import ArgumentParser
from sys import exit
from shutil import rmtree
from os import walk, makedirs, chdir
from re import search

ROOT = dirname(
    abspath(__file__)
)

def execute_sp(cmd, **kwargs):
    exec_sp = run(cmd, **kwargs)
    exec_sp.check_returncode()
    if exec_sp.returncode != 0:
        exit(1)

if __name__ == '__main__':
    parser = ArgumentParser()
    parser.add_argument('prog', help = 'Path to RISC-V assembly or C program')
    #parser.add_argument('app', help = 'The object whose main method is to be invoked')
    #parser.add_argument('mod', help = 'Top module name')
    parser.add_argument(
        '--timing',
        action = 'store_const',
        const = '--timing',
        help = 'Enable timing support'
    )
    #parser.add_argument(
    #    '--sbt_args',
    #    default = '',
    #    help = 'Comma-separated sbt args'
    #)
    args = parser.parse_args()
    prog_name = split(args.prog)[-1]
    target_dir = join(ROOT, 'out', prog_name)
    elf = join(target_dir, prog_name.split('.')[0])
    if isdir(target_dir):
        rmtree(target_dir)
    makedirs(target_dir)
    execute_sp((
        'riscv32-unknown-elf-gcc',
        '-static',
        '-mcmodel=medany',
        '-fvisibility=hidden',
        '-nostdlib',
        '-nostartfiles',
        '-g',
        '-T', join(ROOT, "riscof", "nucleusrv", "env", "link.ld"),
        '-march=rv32if',
        '-mabi=ilp32f',
        '-o', elf,
        args.prog
    ), text = True)
    execute_sp(
        f'riscv32-unknown-elf-objdump -d -Mno-aliases {elf} > {elf}.objdump',
        shell = True,
        text = True
    )
    execute_sp((
        'riscv32-unknown-elf-objcopy',
        '-O', 'binary',
        '-j', '.text',
        elf,
        join(target_dir, 'imem.bin')
    ), text = True)
    execute_sp((
        'riscv32-unknown-elf-objcopy',
        '-O', 'binary',
        '-j', '.data',
        elf,
        join(target_dir, 'dmem.bin')
    ), text = True)
    execute_sp(
        f'hexdump -v -e \'1/4 "%08x\\n"\' {join(target_dir, "imem.bin")} > {join(target_dir, "imem.hex")}',
        shell = True,
        text = True
    )
    execute_sp(
        f'hexdump -v -e \'1/4 "%08x\\n"\' {join(target_dir, "dmem.bin")} > {join(target_dir, "dmem.hex")}',
        shell = True,
        text = True
    )
    execute_sp(
        f"sbt 'runMain nucleusrv.components.NRVDriver --imem {join(target_dir, 'imem.hex')} --dmem {join(target_dir, 'dmem.hex')} --target-dir {target_dir}'",
        shell = True,
        text = True
    )
    sv_files = tuple(
        join(target_dir, file)
        for file in next(walk(target_dir))[-1]
            if search(r'\.s?v$', file)
    )
    execute_sp((
        'verilator',
        '--cc',
        '--exe',
        '--build',
        '--trace',
        '-Wno-fatal',
        '-Wno-lint',
        '-Wno-style',
        '--no-timing' if args.timing is None else args.timing,
        '-j', '0',
        '--top', 'Top',
        '--Mdir', join(target_dir, 'obj_dir'),
        join(ROOT, 'nrv_tb.cpp')
    ) + sv_files, text = True)
    chdir(target_dir)
    execute_sp([join(
        target_dir,
        'obj_dir',
        'VTop'
    )], text = True)
    chdir(ROOT)

