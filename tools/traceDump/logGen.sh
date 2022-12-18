# Generating assembly hex
echo "Parsing assembly..."
python ./scripts/assemblyParser.py --asm ./asm/$1 --hex ./asm/assembly.hex

# Dump sbt output
cd ../../
echo "Dumping sbt output..."
sbt "testOnly nucleusrv.components.TopTest -- -DwriteVcd=1 -DprogramFile=./tools/traceDump/asm/assembly.hex" > ./tools/traceDump/trace/sbtDump.log
echo "sbt output dumped"

# Generating log
cd ./tools/traceDump/
echo "Generating log..."
python ./scripts/sbtToLog.py --asm ./asm/$1 --sbt_dump ./trace/sbtDump.log --log ./trace/nrv.log
echo "Log generated"
