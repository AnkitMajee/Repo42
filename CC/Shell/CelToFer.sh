#!/bin/bash

echo "Enter temperature in Celsius:"
read celsius

# Convert Celsius to Fahrenheit using the formula: F = (C * 9/5) + 32
fahrenheit=$(echo "scale=2; ($celsius * 9/5) + 32" | bc)

echo "$celsius degrees Celsius is equal to $fahrenheit degrees Fahrenheit"
