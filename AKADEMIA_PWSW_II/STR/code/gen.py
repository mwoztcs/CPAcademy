from random import randint

n = randint(100000, 200000)
G = set()

for i in range(1, n):
    u = randint(1, i)
    G.add((u, i+1))

add = 100000
for i in range(0, add):
    u = randint(1, n)
    v = randint(1, n)
    if u != v:
        u, v = min(u, v), max(u, v)
        G.add((u, v))

print("{} {}".format(n, len(G)));
for (u, v) in G:
    print("{} {}".format(u, v))
