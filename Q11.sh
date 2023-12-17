#!/bin/bash

echo "Enter a number:"
read original_number

reverse_number(){
    local num=$1
    local reversed=0

    while [ $num -gt 0 ]; do
    digit=$((num%10))
    reversed=$((reversed*10+digit))
    num=$((num/10))

    done

    echo "Reversed Number: $reversed"
}

reverse_number "$original_number"