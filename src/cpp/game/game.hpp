#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
using namespace std;

void fill_left(vector<vector<int>>&);
void flip(vector<vector<int>>&);
void transpose(vector<vector<int>>&);
void combine(vector<vector<int>>&);
bool any_zeroes(vector<vector<int>>);
bool add_num(vector<vector<int>>&);

bool move_left(vector<vector<int>>&);
bool move_right(vector<vector<int>>&);
bool move_up(vector<vector<int>>&);
bool move_down(vector<vector<int>>&);
auto all_moves(vector<vector<int>>);

#endif