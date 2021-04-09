t = int(input())
for case_num in range(1, t + 1):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(n - 1):
        lo_idx = i
        for j in range(i + 1, n):
            if a[j] < a[lo_idx]:
                lo_idx = j
        ans += lo_idx - i + 1
        a = a[:i] + a[i:lo_idx+1][::-1] + a[lo_idx+1:]
    print('Case #{}: {}'.format(case_num, ans))
