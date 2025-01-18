#!/bin/bash

# Read the input number
echo "Enter a number:"
read number

# Initialize the factorial result to 1
factorial=1

# Loop from 1 to the input number
for (( i=1; i<=number; i++ ))
do
    factorial=$(( factorial * i ))
done

# Display the result
echo "The factorial of $number is $factorial"
