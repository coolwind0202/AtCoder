N = int(input())

terms = [0 for _ in range(6)]

for i in range(N):
    M, m = map(float, input().split())
    if 35 <= M:
        terms[0] += 1
    if 30 <= M < 35:
        terms[1] += 1
    if 25 <= M < 30:
        terms[2] += 1
    if 25 <= m:
        terms[3] += 1
    if 0 > m and 0 <= M:
        terms[4] += 1
    if M < 0:
        terms[5] += 1

print(" ".join(map(lambda x: str(x), terms)))