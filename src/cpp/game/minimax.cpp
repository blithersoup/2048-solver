#include <vector>
#include <climits>
#include <algorithm>
#include "moves.hpp"
#include "moveutils.hpp"
using std::vector;
using std::pair;
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

//extern "C"
int* minimax_result(int* in) {
    vector<vector<int>> board;
    int o = 0;
    for (int i = 0; i < 4; i++) {
        vector<int> row;
        for (int j = 0; j < 4; j++) {
            row.push_back(in[o++]);
        }
        board.push_back(row);
    }

    int ret_left = minimax(left(board), 0, false, INT_MAX, INT_MIN);
    int ret_right = minimax(right(board), 0, false, INT_MAX, INT_MIN);
    int ret_up = minimax(up(board), 0, false, INT_MAX, INT_MIN);
    int ret_down = minimax(down(board), 0, false, INT_MAX, INT_MIN);
    
    vector<int> scores { ret_left, ret_down, ret_up, ret_down };

    int max_score = *std::max_element(scores.begin(), scores.end());

    if (ret_left == max_score) {
        board = left(board);
        add_num(board);
    }
    else if (ret_right == max_score) {
        board = right(board);
        add_num(board);
    }
    else if (ret_up == max_score) {
        board = up(board);
        add_num(board);
    }
    else {
        board = down(board);
        add_num(board);
    }
    o = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            in[o++] = board[i][j];
        }
    }

    return in;
}