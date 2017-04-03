#!/bin/sh
function test()
{
    input_filename=$1
    expected_output_filename=$2
    BS_ACTUAL=$(bs < $input_filename)
    BS_EXPECTED=$(cat $expected_output_filename)
    if [ "$BS_EXPECTED" != "$BS_ACTUAL" ]
    then
        echo "bs did not produce the correct output.  Actual: [$BS_ACTUAL], Expected: [$BS_EXPECTED]"
        exit 1
    fi
}

test bs_test_input bs_test_output
