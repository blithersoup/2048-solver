# 2048-solver

pythonic and cpp implementations of the game 2048, and solver using trees

## Table of Contents

a

## Prerequisites

cmake 3.5

## To start

```bash
mkdir build && cd $_
cmake ..
cmake --build .
```

For running cpp functions on their own, build with `cmake -DTEST_EXEC=true ..`

Run `src/py/run.py`

## a
```
conda create -n solver-env python=3 cmake cxx-compiler c-compiler clangdev libcxx libstdcxx-ng libgcc-ng pytest python-clang cppyy-backend
conda activate solver-env
pip install cppyy clang


mkdir build && cd $_
cmake ..
cmake --build .
pip install dist/*.whl
cd ..

```

