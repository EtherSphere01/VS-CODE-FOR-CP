#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define sp " "
#define pb push_back
#define ppb pop_back
#define ll long long

const ll N = 1e5 + 5;
ll lev[8][8];
ll vis[8][8];

ll get_x(string s)
{
    return s[0] - 'a';
}
ll get_y(string s)
{
    return s[1] - '1';
}

bool isvalid(ll x, ll y)
{
    if (x >= 0 && x < 8 && y >= 0 && y < 8)
    {
        return true;
    }
    return false;
}

vector<pair<ll, ll>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

ll bfs(string source, string desti)
{
    queue<pair<ll, ll>> q;
    ll source_x = get_x(source);
    ll source_y = get_y(source);
    ll desti_x = get_x(desti);
    ll desti_y = get_y(desti);

    q.push({source_x, source_y});
    vis[source_x][source_y] = 1;
    lev[source_x][source_y] = 0;
    while (!q.empty())
    {
        pair<ll, ll> v = q.front();
        q.pop();
        ll x = v.first;
        ll y = v.second;

        for (auto move : moves)
        {
            ll new_x = move.first + x;
            ll new_y = move.second + y;
            if (isvalid(new_x, new_y) and !vis[new_x][new_y])
            {
                q.push({new_x, new_y});
                vis[new_x][new_y] = 1;
                lev[new_x][new_y] = lev[x][y] + 1;
            }
        }
        if (lev[desti_x][desti_y] != INF)
        {
            return lev[desti_x][desti_y];
        }
    }
}

int main()
{
    ll n;
    cin >> n;
    while (n--)
    {
        for (ll i = 0; i < 8; i++)
        {
            for (ll j = 0; j < 8; j++)
            {
                lev[i][j] = INF;
                vis[i][j] = 0;
            }
        }
        string start, end;
        cin >> start >> end;
        cout << bfs(start, end) << nline;
    }
}