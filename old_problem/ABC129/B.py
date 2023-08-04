N = int(input())
weights = list(map(int, input().split()))

all_weight_sum = sum(weights)

min_diff_part_sum = 10 ** 10

for n in range(1, N + 1):
    # 部分和問題？なんかアルゴリズムあったよね
    # 全体和の和を先に取れば、もう一方の和は一方の和から計算できる

    part = weights[:n]
    s1 = sum(part)

    s2 = all_weight_sum - s1

    diff = abs(s1 - s2)
    if min_diff_part_sum > diff:
        min_diff_part_sum = diff

print(min_diff_part_sum)