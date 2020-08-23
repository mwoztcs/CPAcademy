#!/bin/bash

while true; do
    python3 gen.py > t.in
    ./WYK_1 < t.in > a.out
    ./WYK < t.in > b.out
    diff -wB a.out b.out || break
    echo -n "."
done
