from os import chdir, sep
from subprocess import run
from os.path import dirname, abspath, join
from argparse import ArgumentParser
from shutil import rmtree

from ruamel.yaml import YAML

ROOT = dirname(abspath(__file__))
RISCOF = join(ROOT, 'riscof')
RISCV_TEST_SUITE = join(RISCOF, 'riscv-arch-test', 'riscv-test-suite')
RISCV_TEST_SUITE_ENV = join(RISCV_TEST_SUITE, 'env')
CONFIG = join(RISCOF, 'manual_config.ini')
WORK_DIR = join(RISCOF, 'riscof_work')

yaml = YAML(
    typ = 'safe',
    pure = True
)

def simulate_and_compare(testlist, test, f):
    imem = join(testlist[test]["work_dir"], "dut", "imem.hex")
    dmem = join(testlist[test]["work_dir"], "dut", "dmem.hex")
    test_name = testlist[test]['work_dir'].split('/')[-1]
    out = join(ROOT, "out", test_name)
    nrv_sig_file = join(testlist[test]["work_dir"], "dut", "DUT-nucleusrv.signature")
    ref_sig_file = join(testlist[test]["work_dir"], "ref", "Reference-spike.signature")
    print(f'Simulating and comparing test: {test_name}')
    chdir(out)
    run(
        f'./obj_dir/VTop > {nrv_sig_file}',
        shell = True,
        text = True
    )
    with open(nrv_sig_file) as n:
        nrv_sig = n.readlines()
    with open(ref_sig_file) as r:
        ref_sig = r.readlines()
    if len(nrv_sig) != len(ref_sig):
        f.write(f'| {test_name:50} | {" " * 4} | \u2718    |\n')
        f.flush()
        #rmtree(out)
        print('\u2718 Failed')
        return False
    for i in range(min((len(nrv_sig), len(ref_sig)))):
        if nrv_sig[i] != ref_sig[i]:
            f.write(f'| {test_name:50} | {" " * 4} | \u2718    |\n')
            f.flush()
            #rmtree(out)
            print('\u2718 Failed')
            return False
    else:
        f.write(f'| {test_name:50} | \u2714    | {" " * 4} |\n')
        f.flush()
        #print(f'{out = }')
        rmtree(out)
        print('\u2714 Passed')
    return True

if __name__ == '__main__':
    parser = ArgumentParser()
    parser.add_argument('--test', help = 'Name of single riscv-arch-test test')
    args = parser.parse_args()
    try:
        chdir(RISCOF)
        run([
            'riscof',
            'run',
            '--suite', RISCV_TEST_SUITE,
            '--env', RISCV_TEST_SUITE_ENV,
            '--no-browser',
            '--config', CONFIG
        ],
            text = True
        )
        with open(
            join(WORK_DIR, 'test_list.yaml')
        ) as f:
            testlist = yaml.load(f)
        with open(
            join(WORK_DIR, 'test_log.md'),
            'w'
        ) as f:
            f.write(
                f'\n| {"Test Name":50} | Pass | Fail |\n'
                f'| {"-" * 50} | {"-" * 4} | {"-" * 4} |\n'
            )
            f.flush()
            if args.test is not None:
                test = args.test
                for test_path in testlist:
                    if args.test == test_path.split(sep)[-1]:
                        test = test_path
                        break
                if test not in testlist:
                    print(f'Test {args.test} not found in test_list.yaml')
                    exit(1)
                else:
                    simulate_and_compare(testlist, test, f)
            else:
                for test in testlist:
                    passed = simulate_and_compare(testlist, test, f)
                    #if not passed:
                    #    break
            f.write('\n\n')
    except Exception as e:
        print(e)
        exit(1)
