#!/bin/bash

set -e

BIN_DIR=$(which $0)
BIN_DIR=$(dirname $BIN_DIR)
BIN_DIR=$(cd $BIN_DIR; pwd)
ROOT_DIR=$(cd $BIN_DIR/..; pwd)
cd $ROOT_DIR

cd $ROOT_DIR/build
echo "=== BUILDING ==="
if [ "$1" == "make" ]; then
    echo "=== EXEC MAKE ONLY ==="
else
    cmake ..
fi

make -j8
cd -
cp ./build/clips-project ./dist/
echo "install in " $ROOT_DIR/dist
