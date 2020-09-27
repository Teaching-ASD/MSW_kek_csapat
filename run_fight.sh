#!/bin/bash

IFS=$'\n'

if test -f $2; then
    rm $2 
fi

for i in 1 2 3 
do
    for j in 1 2 3 
    do
    if [ $i != $j ]
    then
         ./$1 Units/$i.json Units/$j.json >> $2
    fi
    done

done