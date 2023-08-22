#!/bin/zsh

rm -rf build
mkdir build && cd $_
CMAKE_BUILD_TYPE=Debug cmake ..
cmake --build . --parallel $(nproc --all) 
pip install dist/*.whl --force-reinstall
cd ..
