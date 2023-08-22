# 2048-solver

<img src="videos/demo.gif" width="300" height="300"/>

## Overview

This is an implementation of 2048 in Python with Pygame with the ability to switch to move completion with several algorithms.  The move algorithms are implemented in C++, and are called within Python using a cppyy build system.

### Build system

The build system is done with Cmake, and uses cppyy to create a useable python library.  `CMakeLists.txt` follows the cppyy install instructions for cmake by configuring the cppyy dependencies, setting flags, and including source files.  By running `refresh_build.zsh`, the make command is run with `cmake --build . --parallel $(nproc --all) ` and the output wheel file is installed with `pip install dist/*.whl --force-reinstall`.  To compile with release flags, set `CMAKE_BUILD_TYPE` to `Release` in `refresh_build.zsh`.

### cpp function calls

The library is imported to python with 
```python
import solvera
from cppyy.gbl import hello
```
Functions are then called from the `hello` namespace as a python library.

STL containers can also be instantiated in python, and are used in the instantiation of the game class.
```python
from cppyy.gbl.std import vector
...
self.board = vector[vector[int]] (4, vector[int] (4, 0))
```

### Algorithms

#### Minimax with ab pruning

This algorithm alternates between min and max steps, with the player as the score maximizer and the random addition of tiles as a minimizer.  While the addition of tiles is not adversarial, it helps in considering the worst case near the end of the game.  

The function is called recursively by including depth, alpha, beta, and turn variables for keeping the state of the tree.  Branches are pruned if a > b, meaning that the min or max player must have a better branch to search.  At the max depth, the current score of the board is returned or a minimum value if the game is over.  For each level, the function is recursively called by iterating through the results of the `generate_after_moves` and `generate_all_moves` functions for the min and max players.

#### Beam search

This assumes a single random addition of a tile and expands along each step, then cutting down the search size to a maximum of a set width, repeated a set number of times. To do this, there is a queue of pairs of scores and boards that gets sorted with
```c++
sort(new_q.begin(), new_q.end(), [](const auto &a, const auto &b){ return a.first > b.first; });
```
and resized with
```c++
new_q.resize(min(new_q.size(), MAX_WIDTH));
```

#### MCTS

Work in progress- no working prototype

### Game

The game itself is represented as an instance of a class that holds the game state.  The screen is refreshed within the game loop by presenting the game board as premade tiles.  The game takes user input with arrow keys for movement, the keys 1-3 corresponding to switching to the modes `player`, `minimax`, and `beam` respectively, and 5 and 6 speeds up and slows down the refresh rate.  The purpose of this is mostly to implement the solving function, so there may be some breaking issues.

### Refresh timing system

The refresh system is created by two infinitely looping asynchronous functions that call await for the set time at the end of each loop.  This is also set up to break out whenever there is a command to exit from pygame.

The loops are instantiated with 
```python
loop = asyncio.get_event_loop()
loop.create_task(gameloop())
loop.create_task(autoloop())
loop.run_forever()
```

Because the auto loop and game loop are run concurrently with different refresh rates, it allows for a slower or variable refresh rate for algorithmically created moves while still accepting user input.

## Requirements

cmake 3.5

## To start

```bash
zsh refresh_build.zsh
python3 src/py/exec.py
```

## Build
```bash
conda create -n solver-env python=3 cmake cxx-compiler c-compiler clangdev libcxx libstdcxx-ng libgcc-ng pytest python-clang cppyy-backend
conda activate solver-env
pip install cppyy clang

zsh refresh_build.zsh
```

