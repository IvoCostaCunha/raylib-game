#!/bin/bash

if [[ $# -eq 0 ]] ;
    then
        cmake -S . -B build -D CMAKE_BUILD_TYPE=Debug && cmake --build build && cmake --install build

else
	cmake -S . -B build -D CMAKE_BUILD_TYPE=$1 && cmake --build build && cmake --install build
fi
