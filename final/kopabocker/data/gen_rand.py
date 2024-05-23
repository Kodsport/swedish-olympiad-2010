#!/usr/bin/python3

import sys
import random
import math
from random import randint

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))

bookstores = [[], []]
for i in range(n):
    num = randint(1,2)
    order = [0,1]
    random.shuffle(order)
    for j in range(num):
        bookstores[order[j]].append((i+1, randint(10, 10000//n)))

print(n, 2)
for b in bookstores:
    print(len(b), randint(10, 10000))
    for i in b:
        print(*i)
