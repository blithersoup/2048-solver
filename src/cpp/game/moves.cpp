#include "moves.hpp"
#include "moveutils.hpp"

bool moveboard(matrix &prev, void movefunc(matrix &)) {
  movefunc(prev);
  return add_num(prev);
}

bool all_move(matrix &prev, vector<matrix> &res, void movefunc(matrix &)) {
  movefunc(prev);
  return add_all_num(prev, res);
}

void left(matrix &prev) {
  fill_left(prev);
  combine(prev);
  fill_left(prev);
}

void right(matrix &prev) {
  flip(prev);
  fill_left(prev);
  combine(prev);
  fill_left(prev);
  flip(prev);
}

void up(matrix &prev) {
  transpose(prev);
  fill_left(prev);
  combine(prev);
  fill_left(prev);
  transpose(prev);
}

void down(matrix &prev) {
  transpose(prev);
  flip(prev);
  fill_left(prev);
  combine(prev);
  fill_left(prev);
  flip(prev);
  transpose(prev);
}

auto all_moves(matrix &prev) {
  auto cp(prev);
  vector<int> ret;
  bool end;
  end = moveboard(cp, left);
  if (!end and prev != cp) {
    ret.push_back(0);
  }
  cp = prev;
  end = moveboard(cp, right);
  if (!end and prev != cp) {
    ret.push_back(1);
  }
  cp = prev;
  end = moveboard(cp, up);
  if (!end and prev != cp) {
    ret.push_back(2);
  }
  cp = prev;
  end = moveboard(cp, down);
  if (!end and prev != cp) {
    ret.push_back(3);
  }
  return ret;
}

auto all_possible_results(matrix &prev) {
  matrix cp(prev);
  vector<matrix> ret;
  bool end = all_move(cp, ret, left);

  if (!end) {
  }
  cp = prev;
  end = all_move(cp, ret, right);
  if (!end and prev != cp) {
  }
  cp = prev;
  end = all_move(cp, ret, up);
  if (!end and prev != cp) {
  }
  cp = prev;
  end = all_move(cp, ret, down);
  if (!end and prev != cp) {
  }
  return ret;
}
