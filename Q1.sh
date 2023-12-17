bubbleSort() {
    local array=("$@")
    local n=${#array[@]}
    for ((i = 0; i < n-1; i++)); do
        for ((j = 0; j < n-i-1; j++)); do
            if [[ ${array[j]} -lt ${array[j+1]} ]]; then
                # Swap
                temp=${array[j]}
                array[j]=${array[j+1]}
                array[j+1]=$temp
            fi
        done
    done
    echo "${array[@]}"
}

data=(12 5 7 18 3)
echo "Original Array: ${data[@]}"

# Run the child process in the background
{
    sorted_asc=($(bubbleSort "${data[@]}"))
    echo "Child process (Ascending Order): ${sorted_asc[@]}"
} &

# Run the parent process
sorted_desc=($(bubbleSort "${data[@]}"))
echo "Parent process (Descending Order): ${sorted_desc[@]}"

# Wait for the background process to finish
wait
