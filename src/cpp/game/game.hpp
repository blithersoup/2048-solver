#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
using namespace std;

void fill_left(vector<vector<int>> &);
void flip(vector<vector<int>> &);
void transpose(vector<vector<int>> &);
void combine(vector<vector<int>> &);
bool any_zeroes(vector<vector<int>>);
bool add_num(vector<vector<int>> &);
bool add_all_num(vector<vector<int>>, vector<vector<vector<int>>> &);
auto moves_no_added(vector<vector<int>> );

bool moveboard(vector<vector<int>> &, void(vector<vector<int>> &));
bool move_all(vector<vector<int>> &, vector<vector<vector<int>>> &, void(vector<vector<int>> &));
void left(vector<vector<int>> &);
void right(vector<vector<int>> &);
void up(vector<vector<int>> &);
void down(vector<vector<int>> &);
auto all_move(vector<vector<int>>);
int eval_board(vector<vector<int>>);

#endif