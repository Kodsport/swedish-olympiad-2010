#!/usr/bin/env bash

PPATH=$(realpath ..)
REQUIRE_SAMPLE_REUSE=0
. ../../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution karl.cpp

samplegroup
limits maxans=2000000000
sample 1
sample 2

group group1 20
limits maxans=2000000
tc_manual g1

group group2 20
limits maxans=2000000
tc_manual g2

group group3 20
limits maxans=2000000
tc_manual g3

group group4 20
limits maxans=2000000000
tc_manual g4

group group5 20
limits maxans=2000000000
tc_manual g5
