#!/bin/bash

echo "Enter three numbers:"
read num1
read num2
read num3

# Function to find the biggest of three numbers
find_biggest() {
    local a=$1
    local b=$2
    local c=$3

    if [ $a -gt $b ] && [ $a -gt $c ]; then
        echo "$a is the biggest."
    elif [ $b -gt $a ] && [ $b -gt $c ]; then
        echo "$b is the biggest."
    else
        echo "$c is the biggest."
    fi
}

# Call the function with the entered numbers
find_biggest "$num1" "$num2" "$num3"
