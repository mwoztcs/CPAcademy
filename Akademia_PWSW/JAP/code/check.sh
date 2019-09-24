#!/bin/bash

#g++ -O3 -static -std=c++17 -o KOT KOT.cpp
#g++ -O3 -static -std=c++17 -o KOT_1 KOT_1.cpp
#g++ -O3 -static -std=c++17 -o KOT_2 KOT_2.cpp
#g++ -O3 -static -std=c++17 -o KOT_3 KOT_3.cpp

while true; do
    ./gen > t.in
    ./JAP < t.in > a.out
    ./japxd < t.in > b.out
    diff -wB a.out b.out || break
    echo -n "."
done
