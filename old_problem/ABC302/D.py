from bisect import bisect_right

N, M, D = map(int, input().split())

A = list(map(int, input().split()))
B = list(map(int, input().split()))

B.sort()

max_sum = -1

for a in A:
    b_index = bisect_right(B, a + D) - 1
    if b_index < 0:
        continue

    b = B[b_index]

    if not(a - D <= b <= a + D):
        continue

    max_sum = max(max_sum, a + b)

print(max_sum)