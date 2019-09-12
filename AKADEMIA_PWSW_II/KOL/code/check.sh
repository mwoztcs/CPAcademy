#!/bin/bash

while true; do
    ./gen > t.in 
    #./KOL_1 < t.in > a.out
    ./KOL_2 < t.in > b.out
    ./KOL < t.in > c.out
    #diff -wB a.out b.out || break
    diff -wB b.out c.out || break
    echo -n "."
done
