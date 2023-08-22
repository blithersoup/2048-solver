#include "moves.hpp"
#include "moveutils.hpp"
#include "beam.hpp"
#include <algorithm>
#include <climits>
#include <vector>

using namespace hello;

using std::max;
using std::min;
using std::vector;
using std::sort;
using std::pair;

const size_t MAX_DEPTH = 6;
const size_t MAX_WIDTH = 5;

static int beam(matrix board) {
  vector<pair<int, matrix>> q;
  q.push_back({ calc_score(board), board });
  vector<pair<int, matrix>> new_q;

  for (unsigned i = 0; i < MAX_DEPTH; i++) {
    if (q.empty()) return 0; 
    new_q.clear();
    for (auto &[score, mat] : q) {
      if (!isEnd(mat)) {
        matrix cp = mat;

        left(cp);
        if (add_num(cp)) {
          new_q.push_back({ calc_score(cp), cp });
        }
        cp = mat;
        right(cp);
        if (add_num(cp)) {
          new_q.push_back({ calc_score(cp), cp });
        }
        cp = mat;
        up(cp);
        if (add_num(cp)) {
          new_q.push_back({ calc_score(cp), cp });
        }
        cp = mat;
        down(cp);
        if (add_num(cp)) {
          new_q.push_back({ calc_score(cp), cp });
        }
      }
    }

    sort(new_q.begin(), new_q.end(), [](const auto &a, const auto &b){ return a.first > b.first; });
    new_q.resize(min(new_q.size(), MAX_WIDTH));
    q = new_q;
  }

  return q[0].first;
}

namespace hello {

void beam_result(matrix &board) {
  matrix cp = board;
  left(cp);
  int ret_left = beam(cp);
  cp = board;
  right(cp);
  int ret_right = beam(cp);
  cp = board;
  up(cp);
  int ret_up = beam(cp);
  cp = board;
  down(cp);
  int ret_down = beam(cp);

  int max_score = max(max(ret_left, ret_right), max(ret_up, ret_down));

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
