N = int(input())

t = []

min_time = 10 ** 10

for _ in range(N):
    t.append(int(input()))

for bits in range(2**N):
    a = []
    b = []
    for i in range(N):
        # 1ビットずつ取り出す
        is_a = (bits >> i) & 1
        if is_a:
            a.append(t[i])
        else:
            b.append(t[i])

    time = max(sum(a), sum(b))
    if min_time > time:
        min_time = time

print(min_time)