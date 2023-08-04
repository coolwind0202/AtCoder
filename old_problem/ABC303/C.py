N, M, H, K = map(int, input().split())

S = input()

items = set()

for m in range(M):
    x, y = map(int, input().split())
    items.add((x, y))

health = H
current_position = (0, 0)

def get_dest(order, current):
    if order == "R":
        return (current[0] + 1, current[1])
    if order == "L":
        return (current[0] - 1, current[1])
    if order == "U":
        return (current[0], current[1] + 1)
    if order == "D":
        return (current[0], current[1] - 1)

for order in S:
    dest = get_dest(order, current_position)
    item_in_dest = dest in items
    next_health = health - 1

    if next_health < 0:
        # 体力が負になるので移動不可な位置
        print("No")
        break

    if item_in_dest and next_health < K:
        # まだ倒れない場合、アイテムを取れる
        next_health = K
        items.remove(dest)

    health = next_health
    current_position = dest
else:
    print("Yes")