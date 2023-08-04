import math

N = int(input())

h = list(map(int, input().split()))

dp = [math.inf] * N
dp[0] = 0

for i in range(1, N):
    dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i])
    if i >= 2:
        dp[i] = min(dp[i - 2] + abs(h[i] - h[i - 2]), dp[i])

print(dp[N - 1])

"""
import sys
sys.setrecursionlimit(10**6)

N = int(input())

h = list(map(int, input().split()))

memo = [None] * N


def dfs(i):
    if memo[i] is not None:
        return memo[i]

    if i + 1 < N:
        dfs_value = memo[i + 1]
        if dfs_value is None:
            dfs_value = memo[i + 1] = dfs(i + 1)

        x = dfs_value + abs(h[i + 1] - h[i])
    else:
        return 0

    if i + 2 < N:
        dfs_value = memo[i + 2]
        if dfs_value is None:
            dfs_value = memo[i + 2] = dfs(i + 2)
        y = dfs_value + abs(h[i + 2] - h[i])
    else:
        return x

    return min(x, y)


print(dfs(0))
"""
