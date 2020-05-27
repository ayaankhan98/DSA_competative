#! /bin/bash

mkdir $C/$1
echo "Directory created"
cd $C/$1
touch input.txt output.txt solution.cpp
echo "Create input.txt output.txt solution.cpp"
cd ..
cp $HOME/cpp/template.cpp $C/$1/solution.cpp
echo "templated solution.cpp"
echo "Happy Coding....!"

