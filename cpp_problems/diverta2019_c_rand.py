import random

n = random.randint(1, 10)
print(n)
a = ["".join([chr(random.randint(65, 90))
             for __ in range(random.randint(2, 10))]) for _ in range(n)]
for i in a:
    print(i)
