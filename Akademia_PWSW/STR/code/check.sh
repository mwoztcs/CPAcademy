#!/bin/bash
    
g++ -O3 -static -std=c++17 -o gen generate.cpp
g++ -O3 -static -std=c++17 -o STR_1 STR_1.cpp
g++ -O3 -static -std=c++17 -o SETUP_CHECK SETUP_CHECK.cpp

while true; do
    ./gen > t.in
    ./STR_1 < t.in > a.out
    cat t.in a.out > all.in
    ./SETUP_CHECK < all.in > all.out 
    if [ -s all.out ]; then
        break
    fi
    echo -n "."
done
