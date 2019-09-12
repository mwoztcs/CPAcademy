from random import randint

n = 100000
m = 100000
print(n, m)

print(1000000, 1)
for i in range(1, n):
    r = randint(0, 1000000)
    x = randint(0, 1)
    print(r, x)

print(1000000, 0)
for i in range(1, m):
    c = randint(0, 1000000)
    x = randint(0, 1)
    print(c, x)
