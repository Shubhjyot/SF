# #!/bin/bash

# echo "Enter source folder:"
# read source_folder

# echo "Enter Destination folder:"
# read destination_folder

# cp "$source_dir"/* "$destination_dir"/
# echo "Files copied successfully"

#!/bin/bash

# Source and destination directories
source_dir="/Users/shubhjyot/Desktop/60009220197_D107/SF/ESE_SF/source_dir"
destination_dir="/Users/shubhjyot/Desktop/60009220197_D107/SF/ESE_SF/destination_dir"

# Check if source directory exists
if [ ! -d "$source_dir" ]; then
    echo "Source directory does not exist."
    exit 1
fi

# Check if destination directory exists; if not, create it
if [ ! -d "$destination_dir" ]; then
    mkdir -p "$destination_dir"
fi

# Copy files from source to destination
cp "$source_dir"/* "$destination_dir"/

# Check if the copy operation was successful
if [ $? -eq 0 ]; then
    echo "Files copied successfully."
else
    echo "Error copying files."
fi
