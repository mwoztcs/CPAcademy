from random import randint

n = 100
m = 100
q = 10000
print(n, m, q)

for i in range(0, q):
    tc = randint(0, 19)
    if tc < 14:
        r = randint(1, n)
        c = randint(1, m)
        print('S', r, c)
    elif tc < 17:
        r = randint(1, n)
        print('R', r)
    elif tc < 20:
        c = randint(1, m)
        print('C', c)
    else:
        print('A')
