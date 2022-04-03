from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(1, t + 1):
    ans = [f"Case #{case_num}:"]
    n = read_int()
    s = list(read_ints())
    s.sort()
    now = 0
    for si in s:
        if si < now + 1:
            continue
        else:
            now += 1

    ans.append(str(now))
    print(' '.join(ans))
