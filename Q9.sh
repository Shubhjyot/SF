#!/bin/bash

echo "Enter a number"
read number

is_prime(){
    local num=$1

    if [ $num -lt 2 ]; then 
    return 1 #not prime
    fi

    for ((i=2;i*i<=num;i++)) do
    if [ $((num%i)) -eq 0 ]; then 
        return 1 #not prime
    fi 
    done

    return 0 #prime

}

is_prime "$number"

if [ $? -eq 0 ]; then 
    echo "$number is Prime"
else 
    echo "$number is not Prime"
fi
