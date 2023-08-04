import math

T = int(input())

for _ in range(T):
    S = input()
    digits = len(S)

    cycle = math.ceil(digits / 2)
    max_number = 0

    while cycle >= 1:
        if digits % cycle == 0:
            count = digits // cycle
            M = int(S[0:cycle])
            for i in range(count):
                m = int(S[i * cycle: (i + 1) * cycle])
                if m < M:
                    break
            else:
                number = int(S[0:cycle] * count)
                if max_number < number:
                    max_number = number
        cycle -= 1
    print(max_number)