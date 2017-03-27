#!/bin/sh
BUILD_DIR=build

ninja_all() {
    for dir in $BUILD_DIR/*/ ; do
        ninja -C $dir
    done
}

setup_and_ninja() {
    ./setup.sh
    ninja_all
}

[ -d $BUILD_DIR ] && ninja_all || setup_and_ninja
