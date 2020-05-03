def read_int():
    return int(input())


t = read_int()
for case_num in range(1, t + 1):
    s = input().split(' ')
    x = int(s[0])
    y = int(s[1])
    path = s[2]
    ans = -1
    curr = 0
    if x == 0 and y == 0:
        ans = 0
    else:
        for c in path:
            if c == 'E':
                x += 1
            elif c == 'W':
                x -= 1
            elif c == 'N':
                y += 1
            else:
                y -= 1
            curr += 1
            if abs(x) + abs(y) <= curr:
                ans = curr
                break
    print('Case #{}: {}'.format(case_num, ans if ans >= 0 else 'IMPOSSIBLE'))
