#include <vector>
#pragma once
using std::vector;

using matrix = vector<vector<int>>;

void fill_left(matrix);
void flip(matrix);
void transpose(matrix);
void combine(matrix);

matrix left(matrix);
matrix right(matrix);
matrix up(matrix);
matrix down(matrix);