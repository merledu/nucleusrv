# Generating assembly hex
python ./scripts/assemblyParser.py --asm ./asm/$1 --hex ./asm/assembly.hex

# Dump sbt output
cd ../../
echo "Dumping sbt output..."
sbt "testOnly nucleusrv.components.TopTest -- -DwriteVcd=1 -DprogramFile=./tools/trace/asm/assembly.hex" > ./tools/trace/logs/sbtDump.log

# Generating log
cd ./tools/trace
echo "Generating log..."
python ./scripts/sbtToLog.py --asm ./asm/$1 --sbt_dump ./logs/sbtDump.log --log ./logs/nrv.log