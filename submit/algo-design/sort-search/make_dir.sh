#!/bin/bash

# Save the current directory
current_dir=$(pwd)

# Check if the 'code' command is available
if ! command -v code &> /dev/null
then
    echo "'code' command could not be found"
    exit
fi

if [ -d "$1" ]; then
    cd $1
    count=$(ls -1 $1*.cpp 2>/dev/null | wc -l)
    filename=$1_$count.cpp

    touch $filename
    echo "#include <bits/stdc++.h>" >> $filename
    echo "using namespace std;" >> $filename
    echo "" >> $filename
    echo "int main() {" >> $filename
    echo "    // Write your code here" >> $filename
    echo "    return 0;" >> $filename
    echo "}" >> $filename

    code $filename
else
    mkdir -p $1
    cd $1
    touch $1.cpp $1.md input.txt

    echo "## $1" >> $1.md
    echo "#include <bits/stdc++.h>" >> $1.cpp
    echo "using namespace std;" >> $1.cpp
    echo "" >> $1.cpp
    echo "int main() {" >> $1.cpp
    echo "    // Write your code here" >> $1.cpp
    echo "    return 0;" >> $1.cpp
    echo "}" >> $1.cpp

    code $1.cpp
fi

# Go back to the original directory
cd $current_dir