def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)


t = int(input())
for case_num in range(1, t+1):
    n, l = map(int, input().split(' '))
    muls = list(map(int, input().split(' ')))
    primes = set()
    for i in range(l - 1):
        g = gcd(muls[i], muls[i + 1])
        r = muls[i] // g
        if g != 1 and r != 1:
            primes.add(g)
            primes.add(r)
            primes.add(muls[i + 1] // g)
    primes = list(primes)
    primes.sort()
    d = dict()
    for i in range(26):
        d[primes[i]] = chr(65 + i)
    mid = []
    for mul in muls:
        s = set()
        for prime in primes:
            if mul % prime == 0:
                s.add(prime)
                s.add(mul // prime)
                break
        mid.append(s)

    ans = [0 for i in range(l+1)]
    pivot = -1
    for i in range(l - 1):
        ans[i + 1] = mid[i].intersection(mid[i + 1])
        if (len(ans[i + 1]) == 1):
            pivot = i + 1

    ans[0] = mid[0]
    ans[l] = mid[l - 1]
    i = pivot
    while i > 0:
        i -= 1
        if len(ans[i]) == 1:
            continue
        ans[i] = ans[i].difference(ans[i + 1])

    i = pivot
    while i < l:
        i += 1
        if len(ans[i]) == 1:
            continue
        ans[i] = ans[i].difference(ans[i - 1])

    ans = list(map(lambda x: d[list(x)[0]], ans))
    print('Case #{}: {}'.format(case_num, ''.join(ans)))
