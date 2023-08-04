import itertools

A = int(input())
B = int(input())
C = int(input())
D = int(input())
E = int(input())

times = [A, B, C, D, E]

min_time = 100000000

for pattern in itertools.permutations(times, 5):
    current = 0

    for time in pattern:
        if current % 10 != 0:
            current += (10 - (current % 10))
        current += time

    if min_time > current:
        min_time = current

print(min_time)