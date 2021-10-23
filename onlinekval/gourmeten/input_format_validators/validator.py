import sys, re

intreg = "(0|[1-9][0-9]*)"
RE = re.compile("^"+intreg+"$")

line = sys.stdin.readline()
assert RE.match(line)
M = int(line)
assert 1 <= M <= 1000

line = sys.stdin.readline()
assert RE.match(line)
N = int(line)
assert 1 <= N <= 30

for _ in range(N):
    line = sys.stdin.readline()
    assert RE.match(line)
    T = int(line)
    assert 1 <= T <= 200

assert len(sys.stdin.readline()) == 0, "Trailing input"

sys.exit(42)
