#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> path;
vector<vector<bool>> vis;

int startx, starty, endx, endy;

vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isvalid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (vis[x][y])
        return false;
    return true;
}

void bfs()
{
    queue<pair<int, int>> q;
    q.push({startx, starty});
    vis[startx][starty] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (auto mv : moves)
        {
            int newx = x + mv.first;
            int newy = y + mv.second;
            if (isvalid(newx, newy))
            {
                q.push({newx, newy});
                vis[newx][newy] = true;
                path[newx][newy] = {x, y};
                if (newx == endx && newy == endy)
                    return;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    path.resize(n, vector<pair<int, int>>(m, {-1, -1}));
    vis.resize(n, vector<bool>(m, false));
    vector<string> ans(n);

    for (int i = 0; i < n; i++)
    {
        cin >> ans[i];
        for (int j = 0; j < m; j++)
        {
            if (ans[i][j] == '#')
            {
                vis[i][j] = true;
            }
            if (ans[i][j] == 'R')
            {
                startx = i;
                starty = j;
            }
            if (ans[i][j] == 'D')
            {
                endx = i;
                endy = j;
            }
        }
    }

    bfs();

    if (!vis[endx][endy])
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << endl;
        }
        return 0;
    }

    pair<int, int> end = {endx, endy};
    while (end.first != startx || end.second != starty)
    {
        end = path[end.first][end.second];
        if (end == make_pair(-1, -1))
            break;

        if (ans[end.first][end.second] != 'R' && ans[end.first][end.second] != 'D')
        {
            ans[end.first][end.second] = 'X';
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
}
