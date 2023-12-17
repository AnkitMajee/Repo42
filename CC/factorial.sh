#!/bin/bash

echo "Enter a number:"
read num

factorial=1
counter=1

while [ $counter -le $num ]; do
    factorial=$((factorial * counter))
    counter=$((counter + 1))
done

echo "Factorial of $num is $factorial"
