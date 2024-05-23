#!/usr/bin/python3

import sys
import itertools
from collections import defaultdict
from functools import reduce

# Constants
INF = float('inf')

# Fast input function (optional)
def read_ints():
    return map(int, sys.stdin.read().split())

def main():
    # Fast input initialization
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    def read():
        nonlocal idx
        val = data[idx]
        idx += 1
        return int(val)

    # Reading input
    n = read()
    m = read()
    
    costs = []
    books = []

    for i in range(m):
        k = read()
        c = read()
        costs.append(c)
        book_list = []
        for j in range(k):
            b = read() - 1
            p = read()
            book_list.append((b, p))
        books.append(book_list)

    ans = INF

    for mask in range(1 << m):
        total_cost = 0
        book_prices = defaultdict(list)
        for j in range(m):
            if mask & (1 << j):
                total_cost += costs[j]
                for b, p in books[j]:
                    book_prices[b].append(p)
        
        if len(book_prices) < n:
            continue

        works = True
        for i in range(n):
            if not book_prices[i]:
                works = False
                break
            total_cost += min(book_prices[i])
        
        if works:
            ans = min(ans, total_cost)

    print(ans)

if __name__ == "__main__":
    main()
