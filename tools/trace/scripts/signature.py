import argparse
def read_file_and_modify_list(file_path):
        with open(file_path, 'r') as file:
            lines = [line.strip() for line in file.readlines()]

            if lines and lines.count(lines[0]) > 1:
                second_occurrence_index = lines.index(lines[0], lines.index(lines[0]) + 1)

                lines = lines[:second_occurrence_index]

            return lines

def write_list_to_file(file_path, lines):
        with open(file_path, 'w') as file:
          
            file.write('\n'.join(lines))


#driverscode
parser = argparse.ArgumentParser()
parser.add_argument('--signature', type=str, help='core signature file')
args = parser.parse_args()
file_path = args.signature 
modified_lines_list = read_file_and_modify_list(file_path)

if modified_lines_list is not None:
    write_list_to_file(file_path, modified_lines_list)
    
