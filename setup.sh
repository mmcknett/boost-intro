#!/bin/sh
SRC_DIR=src
MESON_BLD_DIR=build

for dir in $SRC_DIR/*/ ; do
    dir=${dir#$SRC_DIR/}
    meson $MESON_BLD_DIR/$dir $SRC_DIR/$dir
done
