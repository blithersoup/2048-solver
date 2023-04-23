#include "moves.hpp"
#include "moveutils.hpp"
#include <cmath>
using std::equal;

#include <iostream>
using std::cout;

namespace hello {

int calc_score(matrix board) {
  int score = 0;
  for (auto row : board) {
    for (int x : row) {
      if (x > 2) {
        score += ((x - 1) * (std::pow(2, x)));
      }
    }
  }
  return score;
}

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

bool moveboard(matrix& prev, matrix movefunc(matrix)) {
  prev = movefunc(prev);
  return add_num(prev);
}


vector<matrix> generate_all_moves(matrix prev) {
  auto cp(prev);
  vector<matrix> ret;
  bool end;
  end = moveboard(cp, left);
  if (!end and prev != cp) {
    ret.push_back(cp);
  }
  cp = prev;
  end = moveboard(cp, right);
  if (!end and prev != cp) {
    ret.push_back(cp);
  }
  cp = prev;
  end = moveboard(cp, up);
  if (!end and prev != cp) {
    ret.push_back(cp);
  }
  cp = prev;
  end = moveboard(cp, down);
  if (!end and prev != cp) {
    ret.push_back(cp);
  }
  return ret;
}



bool add_num(matrix& prev) {
  if (!any_zeroes(prev)) {
    return false;
  }
  int added = 1 << (rand() & 1 + 1);
  int x, y;
  while (true) {
    x = rand() % 4;
    y = rand() % 4;
    if (prev[x][y] == 0) {
      prev[x][y] = added;
      return true;
    }
  }
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
  matrix moved = left(board);
  for (auto x : moved) {
    for (auto y : x) {
      cout << y <<" ";
    }
    cout << "\n";
  }
  cout << "\n\n";
  if (!equal(moved.begin(), moved.end(), board.begin())) {
    return true;
  }
  moved = right(board);
  if (!equal(moved.begin(), moved.end(), board.begin())) {
    return true;
  }
  moved = up(board); 
  if (!equal(moved.begin(), moved.end(), board.begin())) {
    return true;
  }
  moved = down(board);
  if (!equal(moved.begin(), moved.end(), board.begin())) {
    return true;
  }
  return false;
}
}
