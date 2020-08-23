from random import randint

n = 200000
q = 200000

print(n, q)

for i in range(0, n):
    x = randint(-100000000, 100000000)
    y = randint(-100000000, 100000000)
    print(x, y)

for i in range(0, q):
    x = randint(-100000000, 100000000)
    y = randint(-100000000, 100000000)
    print(x, y)
