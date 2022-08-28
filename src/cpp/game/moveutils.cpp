#include "game.hpp"
#include <numeric>
#include <algorithm>
#include <functional>

void fill_left(vector<vector<int>> &prev)
{
    vector<vector<int>> mat;
    for (auto row : prev)
    {
        int sum = std::accumulate(row.begin(), row.end(), decltype(row)::value_type(0));
        vector<int> new_row = {sum, 0, 0, 0};
        mat.emplace_back(new_row);
    }

    prev = mat;
}

void flip(vector<vector<int>> &prev)
{
    vector<vector<int>> mat;
    for (auto row : prev)
    {
        vector<int> new_row;
        for (decltype(new_row)::reverse_iterator i; i != new_row.rend(); i++)
        {
            new_row.push_back(*i);
        }
        mat.push_back(new_row);
    }

    prev = mat;
}

void transpose(vector<vector<int>> &prev)
{
    vector<vector<int>> mat(prev[0].size(), vector<int>());

    for (auto i = 0; i < prev.size(); i++)
    {
        for (auto j = 0; j < prev[i].size(); j++)
        {
            mat[j].push_back(prev[i][j]);
        }
    }
    prev = mat;
}

void combine(vector<vector<int>> &prev)
{
    vector<vector<int>> mat(prev[0].size(), vector<int>());

    for (auto i = 0; i < prev.size(); i++)
    {
        for (auto j = 0; j < prev[i].size() - 1; j++)
        {
            if (prev[i][j] == prev[i][j + 1])
            {
                mat[i][j] = prev[i][j] * 2;
                mat[i][j] = 0;
            }
            else
            {
                mat[i][j] = prev[i][j];
            }
        }
    }
    prev = mat;
}

bool any_zeroes(vector<vector<int>> prev)
{
    for (auto row : prev)
    {
        for (auto i : row)
        {
            if (i == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool add_num(vector<vector<int>> &prev)
{
    if (!any_zeroes(prev))
    {
        return false;
    }
    int added = 1 << (rand() & 1 + 1);
    int x, y;
    while (true)
    {
        x = rand() % 4;
        y = rand() % 4;
        if (prev[x][y] == 0)
        {
            prev[x][y] = added;
            return true;
        }
    }
}

bool add_all_num(vector<vector<int>> prev, vector<vector<vector<int>>> &res)
{
    if (!any_zeroes(prev))
    {
        return false;
    }

    for (auto i = 0; i < 4; i++)
    {
        for (auto j = 0; j < 4; j++)
        {
            if (prev[i][j] == 0)
            {
                prev[i][j] = 2;
                res.push_back(prev);
                prev[i][j] = 4;
                res.push_back(prev);
                prev[i][j] = 0;
            }
        }
    }
    return true;
}

int eval_board(vector<vector<int>> prev)
{
    int score(0), zeroes(0);
    for (auto row : prev)
    {
        for (auto num : row)
        {
            if (!num)
                zeroes++;
            score += num;
        }
    }
    return score / zeroes;
}

auto moves_no_added(vector<vector<int>> prev)
{
    vector<decltype(prev)> moves;
    auto cp(prev);
    moveboard(cp, left);
    moves.push_back(cp);
    cp = prev;
    moveboard(cp, right);
    moves.push_back(cp);
    cp = prev;
    moveboard(cp, up);
    moves.push_back(cp);
    cp = prev;
    moveboard(cp, down);
    moves.push_back(cp);
    return moves;
}