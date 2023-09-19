import itertools


def solve():
    n = int(input())
    ans = 0

    l = [input() for _ in range(n)]
    combinations = ["".join(s) for s in itertools.permutations(l)]
    for s in combinations:
        c = s.count("AB")
        if c > ans:
            ans = c

    print(ans)


solve()
