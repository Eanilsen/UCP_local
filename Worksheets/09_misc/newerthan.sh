#!/bin/bash

while true; do
    echo "Which file is the newest?"
    echo "Enter the name of the first file"
    read f1
    echo "Enter the name of the second file"
    read f2
    if [ $f2 -nt $f1 ]; then
        echo "$f2 is newer than $f1" 
        break;
    else if [ $f1 -nt $f2 ]; then
        echo "$f1 is newer than $f2"
        break;
    else
        echo "Error"
    fi
    fi
done
