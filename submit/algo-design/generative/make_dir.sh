#!/bin/bash


mkdir $1
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
cd ..