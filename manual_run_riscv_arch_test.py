from os import chdir
from subprocess import run
from os.path import dirname, abspath, join

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

if __name__ == '__main__':
    test_log = []
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
            join(WORK_DIR, 'test.log'),
            'w'
        ) as f:
            f.write(f'{"Test Name":50} | {"Status"}\n')
            f.flush()
            for test in testlist:
                chdir(ROOT)
                imem = join(testlist[test]["work_dir"], "dut", "imem.hex")
                dmem = join(testlist[test]["work_dir"], "dut", "dmem.hex")
                test_name = testlist[test]['work_dir'].split('/')[-1]
                out = join(ROOT, "out", test_name)
                nrv_sig_file = join(testlist[test]["work_dir"], "dut", "DUT-nucleusrv.signature")
                ref_sig_file = join(testlist[test]["work_dir"], "ref", "Reference-spike.signature")
                run(
                    f'sbt "runMain nucleusrv.components.NRVDriver --imem {imem} --dmem {dmem} --target-dir {out}"',
                    shell = True,
                    text = True
                )
                chdir(out)
                run(
                    "(echo '/* verilator lint_off WIDTH */' && cat Top.v) > temp && mv temp Top.v",
                    shell = True,
                    text = True
                )
                run(
                    'verilator --cc --exe --build --trace --no-timing ../../tb_Top.cpp Top.v',
                    shell = True,
                    text = True
                )
                run(
                    f'./obj_dir/VTop &> {nrv_sig_file}',
                    shell = True,
                    text = True
                )
                with open(nrv_sig_file) as n:
                    nrv_sig = n.readlines()
                with open(ref_sig_file) as r:
                    ref_sig = r.readlines()
                if len(nrv_sig) != len(ref_sig):
                    #print(f'{test_name:50} | {"Failed"}')
                    f.write(f'{test_name:50} | {"Failed"}\n')
                    f.flush()
                    continue
                for i in range(min((len(nrv_sig), len(ref_sig)))):
                    if nrv_sig[i] != ref_sig[i]:
                        #print(f'{test_name:50} | {"Failed"}')
                        f.write(f'{test_name:50} | {"Failed"}\n')
                        f.flush()
                        break
                else:
                    #print(f'{test_name:50} | {"Passed"}')
                    f.write(f'{test_name:50} | {"Passed"}\n')
                    f.flush()
    except Exception as e:
        print(e)
        exit(1)
