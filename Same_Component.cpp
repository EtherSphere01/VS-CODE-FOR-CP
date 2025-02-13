#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll nx = 1e3 + 10;
const ll mx = 1e3 + 10;
int cnt = 0;
char c[nx][mx];
ll n, m;
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
bool vis[nx][mx];

void dfs(ll x, ll y)
{
    vis[x][y] = true;
    for (ll i = 0; i < 4; i++)
    {
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && c[nx][ny] == '.' && !vis[nx][ny])
        {
            dfs(nx, ny);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
        }
    }

    ll startx, starty;
    ll endx, endy;
    cin >> startx >> starty >> endx >> endy;

    dfs(startx, starty);
    if(vis[endx][endy])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
