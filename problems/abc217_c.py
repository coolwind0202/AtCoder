N = int(input())

ps = list(map(int, input().split()))
q = [None] * N

for i in range(1, N + 1):
    p = ps[i - 1]
    q[p - 1] = str(i)


print(" ".join(q))
