t = int(input())
for case_num in range(1, t + 1):
    n = int(input())
    route = input()
    my_route = ''.join(['E' if s == 'S' else 'S' for s in route])
    print('Case #{}: {}'.format(case_num, my_route))
