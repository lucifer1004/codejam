from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(1, t + 1):
    r, c = read_ints()
    print(f"Case #{case_num}:")

    data = [['.'] * (2 * c + 1) for _ in range(2 * r + 1)]
    for i in range(2 * r + 1):
        if i % 2 == 0:
            for j in range(2 * c + 1):
                if j % 2 == 0:
                    data[i][j] = '+'
                else:
                    data[i][j] = '-'
        else:
            for j in range(2 * c + 1):
                if j % 2 == 0:
                    data[i][j] = '|'
                else:
                    data[i][j] = '.'

    data[0][0] = data[0][1] = data[1][0] = '.'
    for i in range(2 * r + 1):
        print(''.join(data[i]))
