# #!/bin/bash
# echo "Enter file name"
# read f
# echo number of lines
# wc -l <$f
# echo No. of words
# wc -w <$f
# echo No. of characters
# wc -c <$f

#!/bin/bash

# Function to count words, characters, and lines
count_stats() {
    local file=$1

    if [ ! -f "$file" ]; then
        echo "File not found: $file"
        exit 1
    fi

    words=$(wc -w < "$file")
    characters=$(wc -c < "$file")
    lines=$(wc -l < "$file")

    echo "Word count: $words"
    echo "Character count: $characters"
    echo "Line count: $lines"
}

# Example usage with a specific file
file_path="/Users/shubhjyot/Desktop/60009220197_D107/SF/ESE_SF/Q4text"
count_stats "$file_path"
