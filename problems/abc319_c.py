from itertools import permutations

l = [None] * 3

for i in range(3):
    l[i] = list(map(int, input().split()))

total = 0
cnt = 0
for p in permutations(range(9), 9):
    x = [[] for _ in range(3)]
    y = [[] for _ in range(3)]

    z1 = []
    z2 = []
    for index in p:
        r = index//3
        c = index % 3
        v = l[r][c]
        x[r].append(v)
        y[c].append(v)

        if len(x[r]) == 3:
            if x[r][0] == x[r][1] and x[r][0] != x[r][2]:
                cnt += 1
                break

        if len(y[c]) == 3:
            if y[c][0] == y[c][1] and y[c][0] != y[c][2]:
                cnt += 1
                break

        if r == c:
            z1.append(v)

        if r == 2 - c:
            z2.append(v)

        if len(z1) == 3:
            if z1[0] == z1[1] and z1[0] != z1[2]:
                cnt += 1
                break
        if len(z2) == 3:
            if z2[0] == z2[1] and z2[0] != z2[2]:
                cnt += 1
                break
    total += 1


print(1 - cnt / total)
