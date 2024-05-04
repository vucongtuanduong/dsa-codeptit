#!/bin/bash
# Get the directory of the C++ file
dir=$(dirname -- "$1")

# Get the base name of the C++ file
filename=$(basename -- "$1")
filename="${filename%.*}"

# Compile the C++ file
g++ $1 -o "$dir/$filename.exe"

# If compilation was successful, run the program with input.txt
if [ $? -eq 0 ]; then
    "$dir/$filename.exe" < "$dir/input.txt"
fi