#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define sp " "
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define andd &&
#define orr ||
#define nott !
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define yes cout << "YES" << nline
#define no cout << "NO" << nline
#define yesno(f) \
    if (f)       \
        yes;     \
    else         \
        no
#define noyes(f) \
    if (!f)      \
        yes;     \
    else         \
        no
#define out(x) cout << x << nline
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define showr(v, s, n)         \
    for (ll i = s; i < n; i++) \
        cout << v[i] << sp;
#define show(v)      \
    for (auto i : v) \
        cout << i << sp;
#define show_rev(v, s, n)       \
    for (ll i = s; i >= n; i--) \
        cout << v[i] << sp;
#define show_pair(v, s, n)     \
    for (ll i = s; i < n; i++) \
        cout << v[i].ff << sp << v[i].ss << nline;
#define vl vector<ll>
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vpair vector<pair<ll, ll>>

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<vector<ll>> dist;
ll n, m;
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
ll ans = 0;

bool isvalid(ll x, ll y)
{
    if (x < 0 orr x >= n orr y < 0 orr y >= m)
        return false;
    if (visited[x][y] orr grid[x][y] == 'T')
        return false;
    return true;
}

void bfs(ll startx, ll starty, ll endx, ll endy)
{
    visited[startx][starty] = true;
    queue<pair<ll, ll>> q;
    q.push({startx, starty});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        ll x = p.ff;
        ll y = p.ss;
        for (ll i = 0; i < 4; i++)
        {
            ll newx = x + dx[i];
            ll newy = y + dy[i];
            if (isvalid(newx, newy))
            {
                visited[newx][newy] = true;
                q.push({newx, newy});
                dist[newx][newy] = dist[x][y] + 1;
            }
        }
    }
}

void solve()
{
    ll k;

    while (cin >> k)
    {
        ans = 0;
        cin >> n;
        m = n;
        grid.resize(n, vector<char>(m));
        visited.resize(n, vector<bool>(m, false));
        dist.resize(n, vector<ll>(m, 0));
        ll startx, starty, endx, endy;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 'S')
                {
                    startx = i;
                    starty = j;
                }
                if (grid[i][j] == 'E')
                {
                    endx = i;
                    endy = j;
                }
            }
        }

        bfs(startx, starty, endx, endy);
        out(dist[endx][endy]);
    }
}

int main()
{

    solve();
}
