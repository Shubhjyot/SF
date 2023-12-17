# #!/bin/bash
# echo Enter a sentence:
# read sentence

# count_vowels(){
#     echo "$1" | tr -cd 'aeiouAEIOU' | wc -c
# }

# if["$pid" -eq 0]; then 
#     exec echo “Child process (word count) : $(echo $sentence | wc -w)”
# else 
#     pid=$!
#     wait "$pid"
#     echo “Parent process (vowel count):$(count_vowels “$sentence”)”
# fi

#!/bin/bash

echo "Enter a sentence:"
read sentence

count_vowels() {
    echo "$1" | tr -cd 'aeiouAEIOU' | wc -c
}

# Fork a child process
if pid=$(exec bash -c 'echo $PPID'); then
    # Parent process
    echo "Parent process ID: $$"
    wait "$pid"
    echo "Parent process (vowel count): $(count_vowels "$sentence")"
else
    # Child process
    echo "Child process ID: $$"
    exec echo "Child process (word count): $(echo "$sentence" | wc -w)"
fi
