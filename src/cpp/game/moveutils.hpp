#include <vector>
#pragma once
using std::vector;

using matrix = vector<vector<int>> &;

void fill_left(matrix);
void flip(matrix);
void transpose(matrix);
void combine(matrix);
auto any_zeroes(matrix);
bool add_num(matrix);
bool add_all_num(matrix, vector<matrix> &);
auto moves_no_added(matrix);
