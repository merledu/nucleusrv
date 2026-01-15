OUT_DIR=nucleusrv.components.NRVDriver
TARGET_DIR=$PWD/out/$OUT_DIR

if [ -d "$TARGET_DIR" ]; then
    echo "Delete previous build dir: $TARGET_DIR"
    rm -rf "$TARGET_DIR"
fi

sbt "runMain $OUT_DIR \
    --imem tools/tests/atomic_instructions/imem.hex \
    --dmem tools/tests/atomic_instructions/dmem.hex \
    --target-dir $TARGET_DIR"

echo "Running Verilator..."
rm -rf 
verilator \
    --cc \
    --exe \
    --build \
    --trace \
    -Wno-fatal \
    -Wno-lint \
    -Wno-style \
    --no-timing \
    -j 0 \
    --top Top \
    --Mdir "$TARGET_DIR/obj_dir" \
    nrv_tb_A_LR_SC_extensions.cpp \
    $TARGET_DIR/sram_top.v \
    $TARGET_DIR/sram.v \
    $TARGET_DIR/Top.v

$TARGET_DIR/obj_dir/VTop