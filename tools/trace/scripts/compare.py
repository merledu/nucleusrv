import argparse

def compare_files(DUTfile1_path : str, REFfile2_path : str):

    with open(DUTfile1_path, 'r') as file1, open(REFfile2_path, 'r') as file2:
        content1 = file1.readlines()
        content2 = file2.readlines()
    if(content1 == content2):
        print("Compliance Perfectly Passed !")

    elif(len(content1) != len(content2)):
        print("Warning : there are some test cases missing")
        count = 0
        for i in range(len(content2)):
            if content1[i] == content2[i]:
                count +=1
                print (i+1,"Passed")
            else:
                print("Failed")
                
                print (i+1,False)
   
        if count == len(content2):
            print("COMPLIANCE PASSED")

parser = argparse.ArgumentParser()
parser.add_argument('--ref_sig', type=str, help='Refrence Model Signature File')
parser.add_argument('--dut_sig', type=str, help='DUT Signature File')
args = parser.parse_args()
file1_path = args.dut_sig
file2_path = args.ref_sig

compare_files(file1_path, file2_path)

#use this command to run it in Terminal : 
# $ python3 compare.py --ref_sig ref_file_path --dut_sig dut_file_path