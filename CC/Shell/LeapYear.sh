#!/bin/bash

echo "Enter a year"
read n

if [ $((n % 400)) -eq 0 ] || [ $((n % 4)) -eq 0 ] && [ $((n % 100)) -ne 0 ]; then
    echo "$n is a Leap Year"
else
    echo "$n is not a Leap Year"
fi
# How to run this script?
#  chmod +x LeapYear.sh
# ankitmajee@AnkitMajee:~$ ./LeapYear.sh

