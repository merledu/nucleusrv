curr_dir=$PWD
echo "Current directory: $curr_dir"
sbt "testOnly nucleusrv.components.TopTest -- -DprogramFile=$curr_dir/simulation/machine.hex" > simulation/log.txt
python3 simulation/extract.py