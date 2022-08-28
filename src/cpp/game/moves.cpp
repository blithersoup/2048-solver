#include "game.hpp"

bool moveboard(vector<vector<int>> &prev, void movefunc(vector<vector<int>> &))
{
    movefunc(prev);
    return add_num(prev);
}

bool all_move(vector<vector<int>> &prev, vector<vector<vector<int>>> &res, void movefunc(vector<vector<int>> &))
{
    movefunc(prev);
    return add_all_num(prev, res);
}

void left(vector<vector<int>> &prev)
{
    fill_left(prev);
    combine(prev);
    fill_left(prev);
}

void right(vector<vector<int>> &prev)
{
    flip(prev);
    fill_left(prev);
    combine(prev);
    fill_left(prev);
    flip(prev);
}

void up(vector<vector<int>> &prev)
{
    transpose(prev);
    fill_left(prev);
    combine(prev);
    fill_left(prev);
    transpose(prev);
}

void down(vector<vector<int>> &prev)
{
    transpose(prev);
    flip(prev);
    fill_left(prev);
    combine(prev);
    fill_left(prev);
    flip(prev);
    transpose(prev);
}

auto all_moves(vector<vector<int>> prev)
{
    decltype(prev) cp(prev);
    vector<int> ret;
    bool end;
    end = moveboard(cp, right);
    if (!end and prev != cp)
    {
        ret.push_back(0);
    }
    cp = prev;
    end = moveboard(cp, right);
    if (!end and prev != cp)
    {
        ret.push_back(1);
    }
    cp = prev;
    end = moveboard(cp, up);
    if (!end and prev != cp)
    {
        ret.push_back(2);
    }
    cp = prev;
    end = moveboard(cp, down);
    if (!end and prev != cp)
    {
        ret.push_back(3);
    }
    return ret;
}

auto all_possible_results(vector<vector<int>> prev)
{
    decltype(prev) cp(prev);
    vector<decltype(prev)> ret;
    bool end;
    end = all_move(cp, ret, left);
    if (!end)
    {
    }
    cp = prev;
    end = all_move(cp, ret, right);
    if (!end and prev != cp)
    {
    }
    cp = prev;
    end = all_move(cp, ret, up);
    if (!end and prev != cp)
    {
    }
    cp = prev;
    end = all_move(cp, ret, down);
    if (!end and prev != cp)
    {
    }
    return ret;
}