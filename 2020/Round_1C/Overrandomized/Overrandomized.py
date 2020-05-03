from collections import Counter


def read_int():
    return int(input())


t = read_int()
for case_num in range(1, t + 1):
    u = read_int()
    first = Counter()
    total = Counter()
    non_zero = set()
    for i in range(10000):
        s = input().split(' ')[1]
        total += Counter(s)
        non_zero.add(s[0])
        if not s[0] in first:
            first[s[0]] = 0
        first[s[0]] += 1
    chars = set(total)
    ans = [list(chars - non_zero)[0]]
    del first[ans[0]]
    cnt = [(first[key], key) for key in first]
    cnt.sort(reverse=True)
    rest = [v for u, v in cnt]
    ans += rest
    print('Case #{}: {}'.format(case_num, ''.join(ans)))
