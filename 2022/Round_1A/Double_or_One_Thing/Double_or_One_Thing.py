from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(1, t + 1):
    ans = [f"Case #{case_num}:"]
    s = input()
    last = [chr(ord('A') - 1)] * 2
    result = []
    for c in s[::-1]:
        if c < last[0]:
            result.append(c * 2)
            last[1] = last[0]
            last[0] = c
        elif c == last[0] and c < last[1]:
            result.append(c * 2)
        else:
            result.append(c)
            last[1] = last[0]
            last[0] = c
    ans.append(''.join(result[::-1]))

    print(' '.join(ans))
