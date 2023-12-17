#!/bin/bash

echo "Enter the number of terms for fibonacci series"
read num_terms

a=0
b=1

echo "Fibonacci series upto $num_terms is:"
for ((i=0;i<=num_terms;i++)); do
    echo -n "$a "

next=$((a + b))

a=$b
b=$next
done

echo