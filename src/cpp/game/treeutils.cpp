#include "moves.hpp"
#include "moveutils.hpp"
#include <vector>

vector<vector<int>> minimax(vector<vector<int>> prev) {
  vector<decltype(prev)> moves;
  auto cp(prev);
  moveboard(cp, left);
  add_all_num(prev, moves);
  cp = prev;
  moveboard(cp, right);
  add_all_num(prev, moves);
  cp = prev;
  moveboard(cp, up);
  add_all_num(prev, moves);
  cp = prev;
  moveboard(cp, down);
  add_all_num(prev, moves);
  return cp;
}
