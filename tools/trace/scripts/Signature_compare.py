import argparse

def compare_files(file1_path, file2_path):

    with open(file1_path, 'r') as file1, open(file2_path, 'r') as file2:
        content1 = file1.readlines()
        content2 = file2.readlines()
    print(content2)
        
    for i in range(len(content2)-1):
        if content1[i] == content2[i]:
            print (True)
        else:
            print(i)
            print (False)

# Drivers Code

parser = argparse.ArgumentParser()
parser.add_argument('--ref_sig', type=str, help='Refrence Model Signature File')
parser.add_argument('--dut_sig', type=str, help='DUT Signature File')
args = parser.parse_args()
file1_path = args.dut_sig
file2_path = args.ref_sig

compare_files(file1_path, file2_path)
