#!/bin/bash

#g++ -O3 -static -std=c++17 -o KOT KOT.cpp
#g++ -O3 -static -std=c++17 -o KOT_1 KOT_1.cpp
#g++ -O3 -static -std=c++17 -o KOT_2 KOT_2.cpp
#g++ -O3 -static -std=c++17 -o KOT_3 KOT_3.cpp

while true; do
    python3 gen.py > t.in
    ./KOT < t.in > a.out
    ./KOT_1 < t.in > b.out
    ./KOT_2 < t.in > c.out
    ./KOT_3 < t.in > d.out
    diff -wB a.out b.out || break
    diff -wB b.out c.out || break
    diff -wB c.out d.out || break
    echo -n "."
done
