#!/usr/bin/env pyhton3
import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
maxans = int(cmdlinearg('maxans'))

while True:
    M = random.randint(1, 1000)
    N = random.randint(1, 30)
    T = [random.randint(1, 200) for _ in range(N)]
    sol = [0]*(M + 1)
    sol[0] = 1
    for k in range(1, M + 1):
        for p in T:
            if p <= k: sol[k] += sol[k - p]
    if sol[-1] > maxans: continue
    break

print(M)
print(N)
for t in T:
    print(t)
