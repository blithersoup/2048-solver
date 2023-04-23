#include <vector>
#include <climits>
#include <algorithm>
#include "moves.hpp"
#include "moveutils.hpp"
using namespace hello;
using std::vector;
using std::max;
using std::min;

const int MAX_DEPTH = 6;

static int minimax(vector<vector<int>> array, int depth, bool turn, int a, int b) {
    if (isEnd(array) or depth == MAX_DEPTH) {
        return calc_score(array);
    }

    if (turn) { //generate moves from post move board
        int ret = INT_MIN;
        
        for (auto move_score : generate_all_moves(array)) {
            int val = minimax(move_score, depth + 1, false, a, b);
            ret = max(ret, val);
            a = max(a, val);
            if (a > b) {
                break;
            }
        }
        return ret;
    }

    else { //generate placements from 
        int ret = INT_MAX;

        for (auto move : generate_after_moves(array)) {
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

void minimax_result(vector<vector<int>> &board) {

    int ret_left = minimax(left(board), 0, false, INT_MAX, INT_MIN);
    int ret_right = minimax(right(board), 0, false, INT_MAX, INT_MIN);
    int ret_up = minimax(up(board), 0, false, INT_MAX, INT_MIN);
    int ret_down = minimax(down(board), 0, false, INT_MAX, INT_MIN);
    
    int max_score = max(max(ret_left, ret_right), max(ret_up, ret_down));

    if (ret_left == max_score) 
        board = left(board);
    else if (ret_right == max_score) 
        board = right(board);
    else if (ret_up == max_score) 
        board = up(board);
    else 
        board = down(board);

  add_num(board);
}

}
