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
        hi = i - 3
        found = False
        while lo <= hi:
            mid = (lo + hi) >> 1
            m = query(now[mid], now[i - 2], i)
            if m == now[i - 2]:
                now.append(i)
                found = True
                break
            elif m == now[mid]:
                hi = mid - 1
            else:
                lo = mid + 1
        if not found:
            now = now[:lo] + [i] + now[lo:]
        assert(len(now) == i)
    guess(now)
