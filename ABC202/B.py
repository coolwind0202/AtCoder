S = input()

for c in "".join(reversed(S)):
    if c == "6":
        print("9", end="")
    elif c == "9":
        print("6", end="")
    else:
        print(c, end="")