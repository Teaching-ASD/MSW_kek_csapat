#!/bin/bash
IFS=$'\n'

rm output.txt

for i in player1 player2 player3
do
    for j in player1 player2 player3
    do
    if [ $i != $j ]
    then
         ./$1 Units/$i.json Units/$j.json >> $2
    fi
    done
done