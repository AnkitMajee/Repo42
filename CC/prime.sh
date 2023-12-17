#!/bin/bash

echo "Enter a number:"
read num

# Function to check if a number is prime
is_prime() {
    local n=$1
    if [ $n -lt 2 ]; then
        echo "$n is not a prime number"
    else
        for ((i = 2; i <= n / 2; i++)); do
            if [ $((n % i)) -eq 0 ]; then
                echo "$n is not a prime number"
                return
            fi
        done
        echo "$n is a prime number"
    fi
}

# Call the function
is_prime $num
