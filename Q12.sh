#!/bin/bash

echo "Enter a number:"
read original_number

sum_of_digits(){
    local num=$1
    local sum=0

    while [ $num -gt 0 ]; do
        digit=$((num%10))
        sum=$((sum+digit))
        num=$((num/10))
    done

    echo "Sum of individual digits: $sum"

}

sum_of_digits "$original_number"