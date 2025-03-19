from subprocess import run
from sys import exit
from argparse import ArgumentParser
from os.path import dirname, abspath, isdir, join
from shutil import rmtree
from os import chdir

ROOT = dirname(
    abspath(__file__)
)
OUT = join(ROOT, 'out', 'nrv')

if __name__ == '__main__':
    parser = ArgumentParser()
    parser.add_argument('imem', help = 'Absolute path to imem file')
    parser.add_argument('dmem', help = 'Absolute path to dmem file')
    args = parser.parse_args()

    if isdir(OUT):
        rmtree(OUT)

    try:
        run(
            f"sbt 'runMain nucleusrv.components.NRVDriver {args.imem} {args.dmem} --target-dir {OUT}'",
            shell = True,
            text = True
        )
        chdir(OUT)
        run(
            "(echo '/* verilator lint_off WIDTH */' && cat Top.v) > temp && mv temp Top.v",
            shell = True,
            text = True
        )
        run([
            'verilator',
            '--cc',
            '--exe',
            '--build',
            '--trace',
            '../../tb_Top.cpp',
            'Top.v'
        ], text = True)
        run(
            './obj_dir/VTop &> temp',
            shell = True,
            text = True
        )
        chdir(ROOT)
    except Exception as e:
        print(e)
        exit(1)
