from math import exp
from random import random, randint
import numpy as np

T = 1
P = 86
N = 100
M = 10000


def solve(x, cheat=False):
    if cheat and random() < 0.5:
        return '1'
    return '1' if random() < 1 / (1 + exp(-x)) else '0'


skill = np.random.uniform(6, size=N)
cheater = randint(0, N - 1)
skill[cheater] = 6.0

difficulty = np.random.uniform(6, size=M)
results = [''.join([solve(skill[i] - difficulty[j])
                    for j in range(M)]) for i in range(N)]
cheater_result = [
    ''.join([solve(skill[cheater] - difficulty[j], True) for j in range(M)])]
results[cheater] = cheater_result

print(T)
print(P)
for i in range(N):
    print(results[i])
print('Cheater is', cheater + 1)
