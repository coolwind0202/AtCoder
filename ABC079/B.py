N = int(input())

ryukas = [2, 1]

for i in range(2, N + 1):
    ryukas.append(ryukas[i - 1] + ryukas[i - 2])

print(ryukas[N])