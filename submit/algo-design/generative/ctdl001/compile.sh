#!/bin/bash
filename=$(basename -- "$1")
filename="${filename%.*}"
g++ $1 -o $filename.exe && ./$filename.exe < input.txt