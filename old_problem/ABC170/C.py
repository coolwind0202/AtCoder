import bisect

X, N = map(int, input().split())
ps = list(map(int, input().split()))
ps.sort()

diff = 0

def is_in_ps(x):
    return x in ps

def is_in_ps_bisect(x):
    order = bisect.bisect_left(ps, x)
    if order == len(ps):
        return False
    if ps[order] != x:
        return False
    return True

while True:
    a = X + diff
    b = X - diff

    a_exists = is_in_ps_bisect(a)
    b_exists = is_in_ps_bisect(b)
    
    if not a_exists:
        if not b_exists:
            print(b)
            break
        print(a)
        break
    
    if not b_exists:
        print(b)
        break

    diff += 1