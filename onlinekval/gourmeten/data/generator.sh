#!/usr/bin/env bash

PPATH=$(realpath ..)
REQUIRE_SAMPLE_REUSE=0
. ../../../../../testdata_tools/gen.sh

ulimit -s unlimited

compile gen_random.py

use_solution karl.cpp

samplegroup
limits maxans=2000000000
sample 1
sample 2

group group1 60
limits maxans=2000000
tc 1
tc 2
tc_manual g1
tc_manual g2
tc_manual g3
tc rnd-small-1 gen_random maxans=2000000
tc rnd-small-2 gen_random maxans=2000000
tc rnd-small-3 gen_random maxans=2000000
tc rnd-small-4 gen_random maxans=2000000
tc rnd-small-5 gen_random maxans=2000000
tc rnd-small-6 gen_random maxans=2000000

group group2 40
limits maxans=2000000000
tc_manual g4
tc_manual g5
tc rnd-1 gen_random maxans=2000000000
tc rnd-2 gen_random maxans=2000000000
tc rnd-3 gen_random maxans=2000000000
tc rnd-4 gen_random maxans=2000000000
tc rnd-5 gen_random maxans=2000000000
tc rnd-6 gen_random maxans=2000000000
