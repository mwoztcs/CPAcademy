#!/bin/bash

while true; do
    python3 gen.py > t.in
    ./WIE_1 < t.in > a.out
    ./WIE < t.in > b.out
    diff -wB a.out b.out || break
    if [ $(cat a.out) = "-1" ] ; then
        echo -n "x"
    else
        echo -n "."
    fi
done
