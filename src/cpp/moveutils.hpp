#pragma once
#include <vector>
using std::vector;

#define matrix vector<vector<int>>

namespace hello{
void fill_left(matrix);
void flip(matrix);
void transpose(matrix);
void combine(matrix);

matrix left(matrix);
matrix right(matrix);
matrix up(matrix);
matrix down(matrix);
}
