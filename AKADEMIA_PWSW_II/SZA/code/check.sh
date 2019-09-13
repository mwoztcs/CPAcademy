#!/bin/bash

while true; do
    ./gen > t.in
    ./SZA_1 < t.in > a.out
    ./SZA_2 < t.in > b.out
    ./SZA < t.in > c.out
    diff -wB a.out b.out || break
    diff -wB b.out c.out || break
    echo -n "."
done
