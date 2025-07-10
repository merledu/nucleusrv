from os.path import dirname, abspath, join, isdir
from subprocess import run
from argparse import ArgumentParser
from sys import exit
from shutil import rmtree
from os import walk
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
    parser.add_argument('app', help = 'The object whose main method is to be invoked')
    parser.add_argument('mod', help = 'Top module name')
    parser.add_argument(
        '--timing',
        action = 'store_const',
        const = '--timing',
        help = 'Enable timing support'
    )
    parser.add_argument(
        '--sbt_args',
        default = '',
        help = 'Comma-separated sbt args'
    )
    args = parser.parse_args()
    target_dir = join(ROOT, 'out', args.app)
    if isdir(target_dir):
        rmtree(target_dir)
    execute_sp(
        f"sbt 'runMain {args.app} {' '.join(args.sbt_args.split(','))} --target-dir {target_dir}'",
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
        '--no-timing' if args.timing is None \
            else args.timing,
        '-j', '0',
        '--top', args.mod,
        '--Mdir', join(target_dir, 'obj_dir'),
        'nrv_tb.cpp'
    ) + sv_files, text = True)
    execute_sp([join(
        target_dir,
        'obj_dir',
        f'V{args.mod}'
    )], text = True)
