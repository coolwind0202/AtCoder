N = int(input())

A = list(map(int, input().split()))
B = list(map(int, input().split()))

town_monsters = list(A)
result = 0

for i in range(N):
    # 勇者1は街1を全力で倒すのが最良なので、あとに続く勇者 i は 全力で街 i を全力で倒すのが最良
    rest_monsters = A[i]
    potential = B[i]

    damage = min(potential, A[i])
    A[i] -= damage
    potential -= damage
    result += damage

    if potential >= 0:
        A[i + 1] -= potential
        result += potential

print(result)
