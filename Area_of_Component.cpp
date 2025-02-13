#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll nx = 1e3 + 10;
const ll mx = 1e3 + 10;
char c[nx][mx];
ll n, m;
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
bool vis[nx][mx];
ll cnt = 0;

void dfs(ll x, ll y)
{
    vis[x][y] = true;
    cnt++;
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

    ll ans = LONG_MAX;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (c[i][j] == '.' && !vis[i][j])
            {
                cnt = 0;
                dfs(i, j);
                ans = min(ans, cnt);
            }
        }
    }
    if (ans == LONG_MAX || ans == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}
