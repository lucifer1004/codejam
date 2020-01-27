t = int(input())
for case_num in range(1, t + 1):
    n = int(input())
    r = []
    while n > 0:
        r.append(n % 10)
        n = n // 10
    r.reverse()
    a = 0
    b = 0
    for i in r:
        if i == 5:
            a = a * 10 + 2
            b = b * 10 + 3
        else:
            if i == 0:
                a = a * 10
                b = b * 10
            else:
                a = a * 10 + 1
                b = b * 10 + i - 1
    print('Case #{}: {} {}'.format(case_num, a, b))
