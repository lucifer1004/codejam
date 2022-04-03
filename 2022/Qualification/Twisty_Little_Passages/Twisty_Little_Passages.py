from sys import stdin, stdout
from random import randint
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(1, t + 1):
    n, k = read_ints()
    u, d = read_ints()
    seen = dict()
    memo = dict()
    seen[u] = memo[u] = d
    for i in range(k):
        if i % 2 == 0:
            print('W')
        else:
            print(f'T {randint(1, n)}')

        stdout.flush()
        u, d = read_ints()
        seen[u] = d
        if i % 2 == 1:
            memo[u] = d

    davg = sum(memo.values()) / len(memo)
    dtot = sum(seen.values()) + davg * (n - len(seen))
    print('E', round(dtot / 2))
    stdout.flush()
