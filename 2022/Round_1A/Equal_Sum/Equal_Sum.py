from os import getenv
from sys import stdin, stdout
from random import randint
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


A = [1 << x for x in range(30)]
s = set(A)
pr = []
l = 1
for i in range(30):
    step = 1 << i
    while l in s or (l + step) in s:
        l += 1
    A.append(l)
    A.append(l + step)
    s.add(l)
    s.add(l + step)
    pr.append((1 << i, l, l + step))

m = max(A)
A += list(range(m + 1, m + 10)) + [m + 25]
s = set(A)

OJ = getenv('ONLINE_JUDGE')
INF = int(1e9)
N = 100


def gen():
    sb = set()
    for _ in range(N):
        x = randint(1, INF)
        while x in s or x in sb:
            x = randint(1, INF)
        sb.add(x)
    v = sorted(list(sb))
    if sum(v) % 2 == 1:
        v[-1] += 1
    return v


t = read_int() if OJ else 1
for case_num in range(t):
    if OJ:
        read_int()
    print(' '.join(map(str, A)))
    stdout.flush()

    b = list(read_ints()) if OJ else gen()
    b.sort()
    pre = 0
    suf = sum(b)
    pivot = 0
    for i in range(N):
        pre += b[i]
        suf -= b[i]
        if pre >= suf:
            pivot = i
            break
    delta = pre - suf

    L = b[:pivot + 1] + [m + 1, m + 2, m + 3, m + 4, m + 25]
    R = b[pivot + 1:] + [m + 5, m + 6, m + 7, m + 8, m + 9]
    for i in range(30):
        u, v, w = pr[i]

        if delta & (1 << (i + 1)) == 0:
            L += [u, v]
            R += [w]
        else:
            L += [v]
            R += [u, w]

    assert(sum(L) == sum(R))
    print(' '.join(map(str, L)))
    stdout.flush()
