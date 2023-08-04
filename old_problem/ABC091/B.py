N = int(input())

blue_card = {}
for _ in range(N):
    s = input()
    blue_card[s] = blue_card.get(s, 0) + 1

red_card = {}
M = int(input())

for _ in range(M):
    s = input()
    red_card[s] = red_card.get(s, 0) + 1

max_point = -1

for string in blue_card.keys():
    blue_count = blue_card.get(string, 0)
    red_count = red_card.get(string, 0)

    point = blue_count - red_count
    if point > max_point:
        max_point = point

print(max(max_point, 0))