#!/bin/sh

# Use the full ISO8601 format
TIME=$(date -u +%FT%TZ)
LOGDIR="logs/rit_bis_perftest_$TIME"

[ -d $LOGDIR ] || mkdir $LOGDIR

# Run rit and bs and log the output
rit 1000 | bs > $LOGDIR/test_1000_out.log 2> $LOGDIR/test_1000_perf.log
rit 10000 | bs > $LOGDIR/test_10000_out.log 2> $LOGDIR/test_10000_perf.log
rit 100000 | bs > $LOGDIR/test_100000_out.log 2> $LOGDIR/test_100000_perf.log
rit 1000000 | bs > $LOGDIR/test_1000000_out.log 2> $LOGDIR/test_1000000_perf.log
