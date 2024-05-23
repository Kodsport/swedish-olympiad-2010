#!/bin/bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution joshua.cpp

compile gen_rand.py

samplegroup
sample 1

group group1 30
tc g1-1 gen_rand n=10
tc g1-2 gen_rand n=99
tc g1-3 gen_rand n=100
tc g1-4 gen_rand n=100

group group2 70
include_group sample
include_group group1
tc_manual g2-1
tc_manual g2-2
tc_manual g2-3
tc_manual g2-4
tc_manual g2-5