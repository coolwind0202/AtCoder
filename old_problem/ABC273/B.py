X, K = map(int, input().split())

current = X

for i in range(K):
    current = round(current, -i - 1)
    # round関数どう使う？
    # round(2051, -2) -> 2100
    # round(2050, -2) -> 2000 なんだこれ？
    print(current)

print(current)