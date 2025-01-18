#!/bin/bash

read -p "Enter first number: " num1
read -p "Enter second number: " num2
read -p "Enter third number: " num3

if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]; then
  max=$num1
elif [ $num2 -gt $num3 ]; then
  max=$num2
else
  max=$num3
fi

echo "The maximum number is $max."
