#!/bin/bash

# Function to describe files in different formats
describe_file() {
    local file=$1

    if [ ! -e "$file" ]; then
        echo "File not found: $file"
        exit 1
    fi

    echo "File: $file"
    
    # Display file information using stat
    echo "----- Basic File Information -----"
    stat --format="File Size: %s bytes" "$file"
    stat --format="Access Time: %x" "$file"
    stat --format="Modification Time: %y" "$file"
    stat --format="Change Time: %z" "$file"
    
    # Display permissions
    echo "----- Permissions -----"
    stat --format="Permissions: %a (%A)" "$file"
    
    # Display owner and group
    echo "----- Owner and Group -----"
    stat --format="Owner: %U (%u)" "$file"
    stat --format="Group: %G (%g)" "$file"

    # Display file type
    echo "----- File Type -----"
    stat --format="File Type: %F" "$file"

    # Display number of hard links
    echo "----- Hard Links -----"
    stat --format="Number of Hard Links: %h" "$file"

    # Display inode number
    echo "----- Inode Number -----"
    stat --format="Inode Number: %i" "$file"
}

# Example usage with a specific file
file_path="/path/to/your/file.txt"
describe_file "$file_path"
