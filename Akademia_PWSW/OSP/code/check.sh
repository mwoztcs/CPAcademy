#!/bin/bash

while true; do
    python3 gen.py > t.in
    ./OSP_1 < t.in > a.out
    ./OSP < t.in > b.out
    diff -Bw a.out b.out || break
    echo -n "."
done
