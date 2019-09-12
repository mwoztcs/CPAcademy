from random import randint

n = 200000
m = 200000
print(n, m)

for i in range(0, n):
    x = randint(1, m)
    print(x, end=" ")
