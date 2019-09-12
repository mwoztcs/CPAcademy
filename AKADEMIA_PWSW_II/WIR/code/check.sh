#!/bin/bash

g++ -O3 -static -std=c++17 -o gen generate.cpp

while true; do
    ./gen > t.in
    ./WIR_1 < t.in > a.out
    ./WIR < t.in > b.out
    diff -wB a.out b.out || break
    echo -n "."
done
