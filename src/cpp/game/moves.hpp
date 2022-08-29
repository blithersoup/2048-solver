#include <vector>
#pragma once
using std::vector;

using matrix = vector<vector<int>>;

bool moveboard(matrix, void(matrix &));
bool move_all(matrix, vector<matrix> &, void(matrix));
void left(matrix);
void right(matrix);
void up(matrix);
void down(matrix);
bool all_move(matrix);
auto eval_board(matrix);
