N = int(input())
S = input()
T = input()

def simillar(a, b):
    if a == b:
        return True
    if (a == "1" and b == "l") or (a == "l" and b == "1"):
        return True
    if (a == "0" and b == "o") or (a == "o" and b == "0"):
        return True
    return False

for i in range(N):
    s = S[i]
    t = T[i]

    if not simillar(s, t):
        print("No")
        break
else:
    print("Yes")