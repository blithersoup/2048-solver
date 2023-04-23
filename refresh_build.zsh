#!/bin/zsh

pip uninstall solvera
rm -rf build
mkdir build && cd $_
cmake ..
cmake --build .
cd ..
