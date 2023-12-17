#!/bin/bash

# Function to perform sorting in descending order
sort_descending() {
    local array=("$@")
    local size=${#array[@]}

    for ((i = 0; i < size - 1; i++)); do
        for ((j = 0; j < size - i - 1; j++)); do
            if ((array[j] < array[j + 1])); then
                # Swap elements if they are in the wrong order
                temp=${array[j]}
                array[j]=${array[j + 1]}
                array[j + 1]=$temp
            fi
        done
    done

    # Display the sorted array
    echo "Parent (Descending Order): ${array[@]}"
}

# Array to be sorted
array=(5 2 9 1 5 6 8 3 7 4)

# Fork a child process
if pid=$(exec bash -c 'echo $PPID'); then
    # Parent process
    echo "Parent process ID: $$"
    
    # Call the function to sort the array in descending order
    sort_descending "${array[@]}"
else
    # Child process
    echo "Child process ID: $$"
    
    # Sort the array in ascending order
    sorted_array=($(echo "${array[@]}" | tr ' ' '\n' | sort -n))
    
    # Display the sorted array in ascending order
    echo "Child (Ascending Order): ${sorted_array[@]}"
fi
