from random import randint

n = 200
k = 100
print(n, k)

for i in range(0, n):
    for j in range(0, n):
        x = randint(1, 100)
        print(x, end=" ")
    print()
