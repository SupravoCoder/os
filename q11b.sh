#!/bin/bash

# Input two numbers
echo "Enter first number:"
read num1
echo "Enter second number:"
read num2

# Print original numbers
echo "Original numbers: num1 = $num1, num2 = $num2"

# Swap numbers without using third variable
num1=$((num1 + num2))
num2=$((num1 - num2))
num1=$((num1 - num2))

# Print swapped numbers
echo "Swapped numbers: num1 = $num1, num2 = $num2"
