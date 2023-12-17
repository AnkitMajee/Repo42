#!/bin/bash

echo "Enter the lower limit of the range:"
read lower_limit

echo "Enter the upper limit of the range:"
read upper_limit

# Function to check if a number is prime
is_prime() {
    local n=$1
    if [ $n -lt 2 ]; then
        return 1  # Not a prime number
    fi
    for ((i = 2; i <= n / 2; i++)); do
        if [ $((n % i)) -eq 0 ]; then
            return 1  # Not a prime number
        fi
    done
    return 0  # Prime number
}

echo "Prime numbers in the range $lower_limit to $upper_limit are:"

# Loop through the range and check for prime numbers
for ((num = lower_limit; num <= upper_limit; num++)); do
    is_prime $num
    if [ $? -eq 0 ]; then
        echo $num
    fi
done
