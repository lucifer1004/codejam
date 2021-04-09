from functools import lru_cache


@lru_cache(None)
def query(a, b, c):
    print(a, b, c)
    ans = int(input())
    assert(ans in [a, b, c])
    return ans


def guess(arr):
    print(' '.join(map(str, arr)))
    result = int(input())
    assert(result == 1)


t, n, q = map(int, input().split())
for _ in range(t):
    m = query(1, 2, 3)
    if m == 1:
        now = [2, 1, 3]
    else:
        now = [1, m, 5 - m]
    for i in range(4, n + 1):
        lo = 0
        hi = i - 2
        found = False
        while lo < hi:
            lm = lo + (hi - lo) // 3
            rm = hi - (hi - lo) // 3
            assert(lm < rm)
            m = query(now[lm], now[rm], i)
            if m == now[rm]:
                lo = rm
                if lo == i - 2:
                    now.append(i)
                    found = True
                    break
            elif m == now[lm]:
                hi = lm
                if hi == 0:
                    now = [i] + now
                    found = True
                    break
            else:
                if lm + 1 == rm:
                    now = now[:rm] + [i] + now[rm:]
                    found = True
                    break
                if lm == lo and rm == hi:
                    lm += 1
                lo = lm
                hi = rm

        if not found:
            now = now[:hi] + [i] + now[hi:]

        assert(len(now) == i)
        query.cache_clear()
    guess(now)
