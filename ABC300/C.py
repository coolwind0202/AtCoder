H, W = map(int, input().split())
N = min(H, W)

grid = []

for i in range(H):
    grid.append(input())

grid_candidates = {}
size_crosses = {}

for h in range(H):
    for w in range(W):
        candidate = grid_candidates.get((h, w))
        if candidate is not None:
            i = 1
            # 左下を見る
            while True:
                is_dot = h - i < 0 or w - i < 0 or grid[h - i][w - i] == "."
                if is_dot:
                    # 見ている場所が初めて . だった場合
                    # サイズの一致を確認
                    if candidate == i - 1:
                        size_crosses[i - 1] = size_crosses.get(i - 1, 0) + 1
                    break
                i += 1
            continue


        if grid[h][w] != "#":
            continue

        i = 1

        while True:
            is_dot = h + i >= H or w + i >= W or grid[h + i][w + i] == "."
            if is_dot:
                # 見ている場所が . の場合
                if i != 1:
                    grid_candidates[(h, w + i - 1)] = i - 1
                    # . の場所の1個左が、左斜め辺の始まり
                    # (W - 1 >= w + i - 1 >= w)であることが分かっている
                break
            i += 1

