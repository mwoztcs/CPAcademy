#!/bin/bash

#g++ -O3 -static -std=c++17 -o LAM LAM.cpp
#g++ -O3 -static -std=c++17 -o LAM_1 LAM_1.cpp
#g++ -O3 -static -std=c++17 -o LAM_2 LAM_2.cpp

while true; do
    python3 gen.py > t.in
    ./LAM < t.in > a.out
    ./LAM_1 < t.in > b.out
    ./LAM_2 < t.in > c.out
    diff -wB a.out b.out || break
    diff -wB b.out c.out || break
    echo -n "."
done
