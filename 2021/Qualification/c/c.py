t = int(input())


def solve(nums, c):
    n = len(nums)
    lo = n - 1
    hi = n * (n + 1) // 2 - 1
    if c < lo or c > hi:
        return []
    elif c == lo:
        return nums
    elif c >= n + n - 2:
        return solve(nums[1:], c - n)[::-1] + nums[:1]
    else:
        pos = c - n + 2
        return nums[:pos][::-1] + nums[pos:]


for case_num in range(1, t + 1):
    n, c = map(int, input().split())
    ans = solve([i for i in range(1, n + 1)], c)
    if len(ans) == 0:
        print('Case #{}: IMPOSSIBLE'.format(case_num))
    else:
        print('Case #{}: {}'.format(case_num, ' '.join(map(str, ans))))
