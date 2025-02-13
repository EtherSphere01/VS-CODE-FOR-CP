#include <bits/stdc++.h>
using namespace std;

int p, q;
vector<vector<int>> lev;
vector<vector<int>> vis;

bool isvalid(int x, int y)
{
    if (x >= 0 && x < p && y >= 0 && y < q)
    {
        return true;
    }
    return false;
}

vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

int bfs(int startx, int starty, int endx, int endy)
{
    queue<pair<int, int>> que;

    que.push({startx, starty});
    vis[startx][starty] = 1;
    lev[startx][starty] = 0;

    while (!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for (auto move : moves)
        {
            int new_x = x + move.first;
            int new_y = y + move.second;

            if (isvalid(new_x, new_y) && !vis[new_x][new_y])
            {
                que.push({new_x, new_y});
                vis[new_x][new_y] = 1;
                lev[new_x][new_y] = lev[x][y] + 1;

                if (new_x == endx && new_y == endy)
                {
                    return lev[new_x][new_y];
                }
            }
        }
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        cin >> p >> q;

        lev.assign(p, vector<int>(q, -1));
        vis.assign(p, vector<int>(q, 0));

        int startx, starty, endx, endy;
        cin >> startx >> starty >> endx >> endy;

        if (startx == endx && starty == endy)
        {
            cout << 0 << endl;
            continue;
        }

        int ans = bfs(startx, starty, endx, endy);
        cout << ans << endl;
    }
}
