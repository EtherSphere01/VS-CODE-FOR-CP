#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool check(int row, int col, int queens[])
    {
        for (int i = 0; i < row; i++)
        {
            if (queens[i] == col || abs(queens[i] - col) == abs(i - row))
            {
                return false;
            }
        }
        return true;
    }
    void rec(int level, int n, vector<vector<string>> &board, vector<string> &ans, int queens[])
    {
        if (level == n)
        {
            board.push_back(ans);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (check(level, col, queens))
            {
                queens[level] = col;
                ans[level][col] = 'Q';
                rec(level + 1, n, board, ans, queens);
                ans[level][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> board;
        vector<string> ans(n, string(n, '.'));
        int queens[n + 5] = {0};
        rec(0, n, board, ans, queens);

        return board;
    }
};