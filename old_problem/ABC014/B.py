n, X = map(int, input().split())

a = list(map(int, input().split()))

sum_price = 0

for i in range(n):
    bit = (X >> i) & 1
    if bit:
        sum_price += a[i]

print(sum_price)