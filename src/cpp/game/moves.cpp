#include "game.hpp"
#include <vector>

bool move_left(vector<vector<int>> &prev)
{
    fill_left(prev);
    combine(prev);
    fill_left(prev);
    return add_num(prev);
}

bool move_right(vector<vector<int>> &prev)
{
    flip(prev);
    fill_left(prev);
    combine(prev);
    fill_left(prev);
    flip(prev);
    return add_num(prev);
}

bool move_up(vector<vector<int>> &prev)
{
    transpose(prev);
    fill_left(prev);
    combine(prev);
    fill_left(prev);
    transpose(prev);
    return add_num(prev);
}

bool move_down(vector<vector<int>> &prev)
{
    transpose(prev);
    flip(prev);
    fill_left(prev);
    combine(prev);
    fill_left(prev);
    flip(prev);
    transpose(prev);
    return add_num(prev);
}

auto all_moves(vector<vector<int>> prev)
{
    vector<vector<int>> cp(prev);
    vector<int> ret;
    move_left(cp);
    if (prev != cp)
    {
        ret.emplace_back(0);
    }
    cp = prev;
    move_right(cp);
    if (prev != cp)
    {
        ret.push_back(1);
    }
    cp = prev;
    move_up(cp);
    if (prev != cp)
    {
        ret.push_back(2);
    }
    cp = prev;
    move_down(cp);
    if (prev != cp)
    {
        ret.push_back(3);
    }
    return ret;
}