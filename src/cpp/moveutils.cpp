#include "moves.hpp"
#include "moveutils.hpp"
#include <cmath>
// using std::equal;

#include <iostream>
// using std::cout;
#define LOG2(X) ((int) (8*sizeof (unsigned int) - __builtin_clz((unsigned)(X)) - 1)) // https://stackoverflow.com/a/11376759


namespace hello {

int calc_score(matrix &board) {
  int score = 0;
  for (auto row : board) {
    for (int x : row) {
      if (x > 2) {
        score += ((x - 1) * LOG2(x));
      }
    }
  }
  return score;
}

/*
static bool any_zeroes(matrix prev) {
  for (auto row : prev) {
    for (auto i : row) {
      if (i == 0) {
        return true;
      }
    }
  }
  return false;
}
*/


/*
bool moveboard(matrix &prev, matrix movefunc(matrix)) {
  prev = movefunc(prev);
  return add_num(prev);
}*/

vector<matrix> generate_all_moves(matrix prev) {
  auto cp(prev);
  vector<matrix> ret;
  bool end = true;
  
  left(cp);
  end = add_num(prev);
  if (end) {
    ret.push_back(cp);
  }
  cp = prev;
  right(cp);
  end = add_num(prev);
  if (end) {
    ret.push_back(cp);
  }
  cp = prev;
  up(cp);
  end = add_num(prev);
  if (end) {
    ret.push_back(cp);
  }
  cp = prev;
  down(cp);
  end = add_num(prev);
  if (end) {
    ret.push_back(cp);
  }
  return ret;
}

bool add_num(matrix &prev) {
  int added = 1 << ((rand() & 1) + 1);
  int x, y;
  for (int i = 0; i < 100; i++) {
    x = rand() % 4;
    y = rand() % 4;
    if (prev[x][y] == 0) {
      prev[x][y] = added;
      return true;
    }
  }
  return false;
}

vector<matrix> generate_after_moves(matrix prev) {
  vector<matrix> res;
  for (auto i = 0; i < 4; i++) {
    for (auto j = 0; j < 4; j++) {
      if (prev[i][j] == 0) {
        prev[i][j] = 2;
        res.push_back(prev);
        prev[i][j] = 4;
        res.push_back(prev);
        prev[i][j] = 0;
      }
    }
  }
  return res;
}

bool isEnd(matrix board) {
  matrix moved (board);
  left(moved);
  if (board != moved) {
    return false;
  }
  moved = board;
  right(moved);
  if (board != moved) {
    return false;
  }
  moved = board;
  up(moved);
  if (board != moved) {
    return false;
  }
  moved = board;
  down(moved);
  if (board != moved) {
    return false;
  }
  return true;
}
} // namespace hello
