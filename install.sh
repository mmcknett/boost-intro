#!/bin/sh

# Limit install to release flavor.
FLAVOR=release

BUILD_DIR=build/$FLAVOR

install_bs_and_rit() {
    cd $BUILD_DIR/bs
    ninja install

    cd ../rit
    ninja install
}

setup_and_ninja_and_install() {
    ./bld.sh $FLAVOR
    install_bs_and_rit
}

[ -d $BUILD_DIR ] && install_bs_and_rit || setup_and_ninja_and_install
