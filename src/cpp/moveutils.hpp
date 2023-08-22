#pragma once
#include "matrix.hpp"

namespace hello {
vector<matrix> generate_all_moves(matrix);
vector<matrix> generate_after_moves(matrix);
bool isEnd(matrix);

// bool moveboard(matrix, void(matrix));

bool add_num(matrix&);

int calc_score(matrix&);
}
