#!/bin/zsh

for i in {1..20000}
do
    echo $RANDOM >> data.txt
done
