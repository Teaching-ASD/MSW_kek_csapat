#!/bin/bash
IFS=$'\n'

rm winner.txt

for i in player1 player2 player3
do
    for j in player1 player2 player3
    do
    if [ $i != $j ]
    then
         ./a.out Units/$i.json Units/$j.json >> winner.txt
    fi
    done
done