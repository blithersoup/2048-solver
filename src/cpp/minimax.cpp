#include "moves.hpp"
#include "moveutils.hpp"
#include <algorithm>
#include <climits>
#include <vector>

using namespace hello;

using std::max;
using std::min;
using std::vector;

//#include <iostream>
//using std::cout;

const int MAX_DEPTH = 6;

static int minimax(matrix array, int depth, bool turn, int a,
                   int b) {
  if (isEnd(array)) {
    return INT_MIN;
  }
  if (depth == MAX_DEPTH) 
    return calc_score(array);

  if (turn) { // generate moves from post move board
    int ret = INT_MIN;
    for (auto &move_score : generate_all_moves(array)) {
      int val = minimax(move_score, depth + 1, false, a, b);
      ret = max(ret, val);
      a = max(a, val);
      if (a > b) {
        break;
      }
    }
    return ret;
  }

  else { // generate placements from
    int ret = INT_MAX;

    for (auto &move : generate_after_moves(array)) {
      int val = minimax(move, depth + 1, true, a, b);
      ret = min(ret, val);
      b = min(a, val);
      if (a > b) {
        break;
      }
    }
    return ret;
  }
}

namespace hello {

void minimax_result(matrix &board) {
  int ret_down = -1, ret_left = -1, ret_right = -1, ret_up = -1;
  matrix cp = board;
  left(cp);
  if (board != cp)
    ret_left = minimax(cp, 0, false, INT_MIN, INT_MAX);
  cp = board;
  right(cp);
  if (board != cp)
    ret_right = minimax(cp, 0, false, INT_MIN, INT_MAX);
  cp = board;
  up(cp);
  if (board != cp)
    ret_up = minimax(cp, 0, false, INT_MIN, INT_MAX);
  cp = board;
  down(cp);
  if (board != cp)
    ret_down = minimax(cp, 0, false, INT_MIN, INT_MAX);

  int max_score = max(max(ret_left, ret_right), max(ret_up, ret_down));

  // cout << ret_down << " " << ret_left << " " << ret_right << " " << ret_up << "\n";

  if (ret_left == max_score)
    left(board);
  else if (ret_right == max_score)
    right(board);
  else if (ret_up == max_score)
    up(board);
  else
    down(board);

}

} // namespace hello
