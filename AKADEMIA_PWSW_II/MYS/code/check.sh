#!/bin/bash

while true; do
    ./gen > t.in
    ./MYS_1 < t.in > a.out
    ./MYS_2 < t.in > b.out
    ./MYS < t.in > c.out
    diff -wB a.out b.out || break
    diff -wB b.out c.out || break
    echo -n "."
done
