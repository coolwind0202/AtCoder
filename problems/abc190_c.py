N, M = map(int, input().split())

conditions = [False for _ in range(M)]

for _ in range(M):
    A, B = map(int, input().split())

K = int(input())

count = 0

for _ in range(K):
    C, D = map(int, input().split())

    if conditions[C - 1] == False:
        conditions[C - 1] = True
        count += 1
        continue

    if conditions[D - 1] == False:
        conditions[D - 1] = True
        count += 1
        continue

print(count)
