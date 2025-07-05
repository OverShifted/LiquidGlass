#!/bin/bash

cmake -S . -B build -D CMAKE_BUILD_TYPE=Release
cmake --build build -j $(nproc)
