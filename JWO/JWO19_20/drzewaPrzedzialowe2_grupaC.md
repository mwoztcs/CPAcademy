# Zaawansowane drzewa przedziałowe

Poniżej znajdują się notatki z Jagiellońskich Warsztatów Olimpijskich, dotyczące zaawansowanych drzew przedziałowych dla grupy C.

## Przykładowe implementacje drzew przedział-przedział



## Fenwick Tree

W czasie zajęć wspominaliśmy również o nieco innym drzewie, znanym jako drzewo Fenwicka (ang. Fenwick tree) lub drzewo indeksowane binarnie (ang. binary indexed tree). Drzewo to sprawdza się bardzo dobrze, gdy chcemy wykonywać operację punkt-przedział, ponieważ działa ono dla dowolnej operacji łącznej, a ponadto jest prostsze w implementacji i zużywa mniej pamięci: potrzebujemy jedynie `n + O(1)` komórek pamięci.

Poniżej znajduje się implementacja tego drzewa w następującym przypadku:

* update: dodaj *add* w punkcie *x*
* query: zwróc sumę na przedziale [*p, q*]

```c++
void update(int x, int add){
    while(x <= n){
        Tree[x] += add;
        x += x&(-x);
    }
}

int pref_query(int x){
    int sum = 0;
    while(x > 0){
        sum += Tree[x];
        x -= x&(-x);
    }
    return sum;
}

int query(int p, int q){
    return pref_query(q)-pref_query(p-1);
}
```

Powyższy przykład jest najczęściej spotykanym, co nie oznacza jednak, że nie da się tej struktury wykorzystać jakoś inaczej. Możemy np. spróbować zrealizować następujące dwie operacje:

* update: dodaj *add* na przedziale [*p, q*]
* query: zwróć sumę w punkcie *x*

Tym razem będziemy potrzebować większej dozy pomysłowości, aby zrealizować te operacje. Aby podać wartość w punkcie *x* zwrócimy wartość z całego przedziału [*1, x*], a to dlatego, że nasz operacja *update* będzie dodawała wartość *add* w punkcie *p* i wartość *-add* w punkcie *q+1*. Wtedy, jak można zauważyć, każde zapytanie o wartość w tym przedziale będzie zwiększone o *add*, zaś poza tym przedziałem wartość ta nie będzie brana pod uwagę (jeżeli pytamy o wcześniejszy punkt) lub zniesie się z wartością w punkcie *q+1* (jeżeli pytamy o jeden z dalszych punktów).

```c++
void update_single(int x, int add){
    while(x <= n){
        Tree[x] += add;
        x += x&(-x);
    }
}

void update(int p, int q, int add){
    update_single(p, add);
    update_single(q+1, -add);
}

int query(int x){
    int sum = 0;
    while(x > 0){
        sum += Tree[x];
        x -= x&(-x);
    }
    return sum;
}
```

Poniżej znajduje się link do zadania z Olimpiady Informatycznej, które opierało się na wykorzystaniu drzewa Fenwicka.

* [Rozliczenia - XXVI OI, etap II, dzień próbny](https://szkopul.edu.pl/problemset/problem/7feyJYY7uz_g6iGLS_QPwJVG/site/?key=statement)


## Chińskie drzewa przedziałowe

Poniżej znajdują się dwa artykuły dotyczące problemu `(max, +)` na drzewach przedział-przedział. W pierwszym artykule można znaleźć rozwiązanie problemu z wykorzystaniem struktur kubełkowych, zaś w drugim rozwiązanie wykorzystujące chińskie drzewa przedziałowe. Aby jeszcze bardziej docenić drugi pomysł zalecamy czytanie artykułów w podanej kolejności.

* [Złośliwy problem (max, +) i kubełkowe struktury danych](http://www.deltami.edu.pl/temat/informatyka/algorytmy/2013/03/30/problem-max.pdf)
* [Problem (max, +) kontratakuje](http://www.deltami.edu.pl/temat/informatyka/algorytmy/2018/08/26/2018-09-delta-iko.pdf)


## Przykłady zadań z wykorzystaniem zaawansowanych drzew przedziałowych

Poniżej znajduje się link do artykułu o zadaniu z sortowaniem przedziałów, o którym po krótce opowiedzieliśmy w jednej z grup.

* [Hacker Cups and Balls](http://www.deltami.edu.pl/temat/informatyka/algorytmy/2017/09/20/Hacker_Cups_and_Balls/)
