file = open("simulation/log.txt", "r")
lines = file.readlines()
relevant = []
for i in lines:
    if i[:2] == "PC":
        relevant.append(i)
    
file.close()

logs = []
for i in relevant:
    a = i.split(",")
    inst = []
    if a[1][7:] != "00000000" or a[2][9:11] != " 0":
        for i in a:
            i = i.split(":")
            inst.append(i[1])
        logs+=inst

for i in range(0,len(logs)):
    if logs[i][-1] != "\n":
        logs[i] = logs[i][1:] + ","


file = open("simulation/nrv_log.csv", "w")
file.writelines(["PC,", "INST,", "REG_NO,", "REG_VAL", "\n"]+logs)
file.close()