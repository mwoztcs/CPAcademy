#!/bin/bash

while true; do
    python3 gen.py > t.in
    ./SMO_1 < t.in > a.out
    ./SMO_2 < t.in > b.out
    ./SMO < t.in > c.out
    diff -wB a.out b.out || break
    diff -wB b.out c.out || break
    echo -n "."
done
