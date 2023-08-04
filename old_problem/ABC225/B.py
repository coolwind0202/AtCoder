N = int(input())

nodes = [set() for _ in range(N)]

for i in range(N - 1):
    a, b = map(int, input().split())
    nodes[a - 1].add(b - 1)
    nodes[b - 1].add(a - 1)

for node in nodes:
    if len(node) == N - 1:
        print("Yes")
        break
else:
    print("No")