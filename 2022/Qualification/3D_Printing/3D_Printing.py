from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(1, t + 1):
    ans = [f"Case #{case_num}:"]
    data = [[] for _ in range(4)]
    for _ in range(3):
        printer = list(read_ints())
        for j in range(4):
            data[j].append(printer[j])
    lb = [min(di) for di in data]
    if sum(lb) < 1000000:
        ans.append("IMPOSSIBLE")
    else:
        need = 1000000
        for j in range(4):
            used = min(need, lb[j])
            need -= used
            ans.append(str(used))

    print(' '.join(ans))
