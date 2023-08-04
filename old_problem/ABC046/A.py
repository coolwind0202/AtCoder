# ゾロ目数は常に9個

N = int(input())

number = 9 if N % 9 == 0 else N % 9

digit = (N - 1) // 9 + 1

print(str(number) * digit)