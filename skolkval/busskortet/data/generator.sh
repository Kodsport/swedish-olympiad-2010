#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

compile gen_rand.py

use_solution js.cpp

samplegroup
sample 1
sample 2

group group1 33
tc_manual g2

group group2 67
include_group sample
include_group group1
tc_manual g1
tc_manual g3
tc g2-1 gen_rand n=10000
tc g2-2 gen_rand n=10000
tc g2-3 gen_rand n=10000
tc g2-4 gen_rand n=10000
tc g2-5 gen_rand n=10000
