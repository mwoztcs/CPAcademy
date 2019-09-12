#!/bin/bash
    
g++ -O3 -static -std=c++17 -o gen generate.cpp
g++ -O3 -static -std=c++17 -o STR_1 STR_1.cpp

while true; do
    ./gen > t.in
    ./STR_1 < t.in > a.out
    cat t.in a.out > all.in
    ./SETUP_CHECK < all.in > all.out 
    diff -wB all.out ac.out || break
    echo -n "."
done
