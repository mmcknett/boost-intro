#!/bin/sh
BUILD_DIR=build

ninja_test_all() {
    for dir in $BUILD_DIR/*/ ; do
        ninja test -C $dir
    done
}

setup_and_ninja_and_test() {
    ./bld.sh
    ninja_test_all
}

[ -d $BUILD_DIR ] && ninja_test_all || setup_and_ninja_and_test
