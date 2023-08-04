N, K = map(int, input().split())
sunukes_have_snack = set()
 
for i in range(K):
    input() # dは捨てる
    A = map(int, input().split())

    for a in A:
        sunukes_have_snack.add(a)

print(N - len(sunukes_have_snack))