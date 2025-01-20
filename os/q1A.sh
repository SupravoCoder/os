#!/bin/bash

#Read input from the user

read -p "Enter a number: " number

#loop to reverse a number

rev=0

while [ $number -ne 0 ]; do
    rem=$((number % 10))
    rev=$((rev * 10 + rem))
    number=$((number / 10))
done

#display the reversed number
echo "The reversed number is: $rev"
