N = int(input())

persons = {}

S = []
for i in range(N):
    name = input()
    persons[name] = persons.get(name, 0) + 1

max_person_name = ""
max_person_count = 0

for item in persons.items():
    key = item[0]
    value = item[1]

    if max_person_count < value:
        max_person_count = value
        max_person_name = key
# 辞書のソートはどうしよう？

print(max_person_name)
