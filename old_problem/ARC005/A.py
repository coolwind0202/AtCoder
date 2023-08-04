_ = input()
strings = input().split()

count = 0

for i, string in enumerate(strings):
    s = string
    if i + 1 == len(strings):
        s = string[:len(string) - 1]
    if s in ["TAKAHASHIKUN", "Takahashikun", "takahashikun"]:
        count += 1

print(count)