#!/bin/bash

echo "Enter Any Number"
read n

echo -n "result"

if [ $((n % 2)) -eq 0 ]; then
    echo "$n is Even"
else
    echo "$n is Odd"
fi

# How to run this script?
# vim evenOdd.sh
#  chmod +x evenOdd.sh
# ankitmajee@AnkitMajee:~$ ./evenOdd.sh