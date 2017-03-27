#!/bin/sh
OUTPUT_DIR=custom_bin
SOURCE_ROOT=src

BOOST_LIBDIR=/usr/local/Cellar/boost/1.63.0/lib/

opt=$1
case $opt in
  clean) [ -d $OUTPUT_DIR ] && rm $OUTPUT_DIR/*
esac

BOOST_ROOT=/usr/local/boost_1_63_0/

[ -d $OUTPUT_DIR ] || mkdir $OUTPUT_DIR

c++ -I $BOOST_ROOT $SOURCE_ROOT/compile_example/compile_example.cpp -o $OUTPUT_DIR/compile_example
c++ -I $BOOST_ROOT $SOURCE_ROOT/link_example/link_example.cpp -o $OUTPUT_DIR/link_example \
  -L$BOOST_LIBDIR -lboost_regex-mt
c++ -I $BOOST_ROOT $SOURCE_ROOT/test_example/test_example.cpp -o $OUTPUT_DIR/test_example
c++ -I $BOOST_ROOT $SOURCE_ROOT/test_link_example/test_link_example.cpp -o $OUTPUT_DIR/test_link_example \
  -L$BOOST_LIBDIR -lboost_unit_test_framework-mt
c++ -I $BOOST_ROOT \
    $SOURCE_ROOT/bs/bubble_sort_tests.cpp \
    $SOURCE_ROOT/bs/bubble_sort.cpp \
    -o $OUTPUT_DIR/bubble_sort_tests \
    -std=c++14 \
    -L$BOOST_LIBDIR -lboost_unit_test_framework-mt
