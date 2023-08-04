N = int(input())
S = input()

max_intersection = -1 # ここは0ではない！

for i in range(N):
  x = set(S[:i])
  y = set(S[i:])
  inter_count = len(x.intersection(y))

  if inter_count > max_intersection:
    max_intersection = inter_count


print(max_intersection)