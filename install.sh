#!/bin/sh
BUILD_DIR=build

cd $BUILD_DIR/bs
ninja install

cd ../rit
ninja install
