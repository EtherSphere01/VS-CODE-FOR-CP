#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool isValid(int x, int y, int n, int m)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    bool rec(vector<vector<char>> &board, string &word, int index, int x, int y, vector<vector<bool>> &visited)
    {
        if (index == word.size())
        {
            return true;
        }
        int n = board.size();
        int m = board[0].size();
        bool ans = false;
        for (int i = 0; i < 4; i++)
        {
            int newX = x + moves[i][0];
            int newY = y + moves[i][1];
            if (isValid(newX, newY, n, m) && !visited[newX][newY] && board[newX][newY] == word[index])
            {
                visited[newX][newY] = true;
                ans = ans || rec(board, word, index + 1, newX, newY, visited);
                visited[newX][newY] = false;
            }
        }
        return ans;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    visited[i][j] = true;
                    if (rec(board, word, 1, i, j, visited))
                    {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};