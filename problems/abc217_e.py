Q = int(input())

A = []

for q in range(Q):
    query = input()
    if query == "2":
        print(A[0])
        A.pop(0)
        pass
    elif query == "3":
        A.sort()
        pass
    else:
        x = int(query[2:])

        A.append(x)
        pass
