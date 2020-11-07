#!/bin/bash

IFS=$'\n'

if test -f $3; then
    rm $3 
fi

./$1 Scenarios/$2.json >> $3







