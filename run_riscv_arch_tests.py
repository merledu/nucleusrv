from subprocess import run
from sys import exit
from os.path import dirname, abspath, join
from os import chdir

ROOT = dirname(abspath(__file__))
RISCOF = join(ROOT, 'riscof')
RISCV_TEST_SUITE = join(RISCOF, 'riscv-arch-test', 'riscv-test-suite')
RISCV_TEST_SUITE_ENV = join(RISCV_TEST_SUITE, 'env')
CONFIG = join(RISCOF, 'config.ini')
WORK_DIR = join(RISCOF, 'riscof_work')

if __name__ == '__main__':
    try:
        chdir(RISCOF)
        run([
            'riscof',
            'run',
            '--suite', RISCV_TEST_SUITE,
            '--env', RISCV_TEST_SUITE_ENV,
            '--no-browser'
        ],
            text = True
        )
        chdir(ROOT)
    except Exception as e:
        print(e)
        exit(1)
