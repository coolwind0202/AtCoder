l = set(["ABC", "ARC", "AGC", "AHC"])

for _ in range(3):
    s = input()
    l.remove(s)

print(list(l)[0])
