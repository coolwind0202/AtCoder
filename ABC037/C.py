N, K = map(int, input().split())

a = list(map(int, input().split()))

before_sum = sum(a[:K])
result = before_sum

for i in range(K, N):
    # ここから見る要素は、前回のsumの一個次の値である。
    current_sum = before_sum - a[i - K] + a[i] # before_sumの先頭要素を引いて、今の要素を足して新しい部分和を得る
    result += current_sum
    before_sum = current_sum

print(result)

