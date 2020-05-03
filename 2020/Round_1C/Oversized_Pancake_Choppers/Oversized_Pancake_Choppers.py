from collections import Counter


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(1, t + 1):
    n, d = read_ints()
    a = read_ints()
    cnt_raw = Counter(a)
    fac = 1
    for i in range(2, d + 1):
        fac *= i
    cnt = dict()
    for key in cnt_raw:
        cnt[key * fac] = cnt_raw[key]
    lo = 1
    hi = max(cnt)
    while lo <= hi:
        mid = (lo + hi) // 2
        can_make = 0
        for i in cnt:
            can_make += i // mid * cnt[i]
        if can_make >= d:
            lo = mid + 1
        else:
            hi = mid - 1
    ans = d - 1
    bases = dict()
    for i in cnt:
        for j in range(1, d + 1):
            base = i // j
            if base <= hi:
                if not base in bases:
                    bases[base] = []
                bases[base].append(j)
    for base in bases:
        bases[base].sort()
        require = d
        slices = 0
        for k in bases[base]:
            if require < k:
                break
            total = cnt[base * k]
            need = require // k
            use = min(total, need)
            require -= use * k
            slices += use * (k - 1)
            if slices >= ans:
                break
        if require > 0:
            slices += require
        ans = min(ans, slices)
    print('Case #{}: {}'.format(case_num, ans))
