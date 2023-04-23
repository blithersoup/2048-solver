#include "moves.hpp"
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

namespace hello {
void fill_left(matrix &prev) {
  matrix mat;
  for (auto row : prev) {
    int sum = std::accumulate(row.begin(), row.end(), 0);
    vector<int> new_row = {sum, 0, 0, 0};
    mat.emplace_back(new_row);
  }

  prev = mat;
}

void flip(matrix &prev) {
  matrix mat;
  for (auto row : prev) {
    vector<int> new_row;
    for (decltype(new_row)::reverse_iterator i; i != new_row.rend(); i++) {
      new_row.push_back(*i);
    }
    mat.push_back(new_row);
  }

  prev = mat;
}

void transpose(matrix &prev) {
  matrix mat(prev[0].size(), vector<int>());

  for (auto i = 0; i < prev.size(); i++) {
    for (auto j = 0; j < prev[i].size(); j++) {
      mat[j].push_back(prev[i][j]);
    }
  }
  prev = mat;
}

void combine(matrix &prev) {
  matrix mat(4, vector<int>(4));

  for (auto i = 0; i < prev.size(); i++) {
    for (auto j = 0; j < prev[i].size() - 1; j++) {
      if (prev[i][j] == prev[i][j + 1]) {
        mat[i][j] = prev[i][j] * 2;
        mat[i][j] = 0;
      } else {
        mat[i][j] = prev[i][j];
      }
    }
  }
  prev = mat;
}

matrix left(matrix prev) {
  fill_left(prev);
  combine(prev);
  fill_left(prev);
  return prev;
}

matrix right(matrix prev) {
  flip(prev);
  fill_left(prev);
  combine(prev);
  fill_left(prev);
  flip(prev);
  return prev;
}

matrix up(matrix prev) {
  transpose(prev);
  fill_left(prev);
  combine(prev);
  fill_left(prev);
  transpose(prev);
  return prev;
}

matrix down(matrix prev) {
  transpose(prev);
  flip(prev);
  fill_left(prev);
  combine(prev);
  fill_left(prev);
  flip(prev);
  transpose(prev);
  return prev;
}
}
