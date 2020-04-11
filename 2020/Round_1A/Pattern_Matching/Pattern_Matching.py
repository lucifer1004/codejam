t = int(input())
for case_num in range(1, t + 1):
    n = int(input())
    patterns = []
    for i in range(n):
        pattern = input()
        patterns.append(pattern.split('*'))
    prefix = ""
    suffix = ""
    match = True
    for pattern in patterns:
        p = pattern[0]
        q = pattern[-1]
        for i in range(min(len(prefix), len(p))):
            if prefix[i] != p[i]:
                match = False
                break
        for i in range(min(len(suffix), len(q))):
            if suffix[-1-i] != q[-1-i]:
                match = False
                break
        if not match:
            break
        if len(p) > len(prefix):
            prefix = p
        if len(q) > len(suffix):
            suffix = q
    if not match:
        print('Case #{}: *'.format(case_num))
    else:
        ans = prefix
        for pattern in patterns:
            for i in range(1, len(pattern) - 1):
                ans += pattern[i]
        ans += suffix
        print('Case #{}: {}'.format(case_num, ans))
