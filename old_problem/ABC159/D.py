import math

N = int(input())
A = list(map(int, input().split()))

ball_count = {}

for a in A:
    ball_count[a] = ball_count.get(a, 0) + 1

sum_comb = 0
ball_combs = {}

for number, count in ball_count.items():
    if count < 2:
        continue
    comb = math.comb(count, 2)
    ball_combs[number] = comb
    sum_comb += comb

ball_comb_exclude_one = {}

for number, count in ball_count.items():
    if count - 1 < 2:
        ball_comb_exclude_one[number] = sum_comb - ball_combs.get(number, 0)
        continue
    ball_comb_exclude_one[number] = sum_comb - ball_combs[number] + math.comb(count - 1, 2)

for a in A:
    print(ball_comb_exclude_one.get(a, 0))