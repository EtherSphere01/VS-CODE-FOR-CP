#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define sp " "
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define andd &&
#define orr ||
#define nott !
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define yes cout << "YES" << nline
#define no cout << "NO" << nline
#define out(x) cout << x << nline
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define show(v, s, n)          \
    for (ll i = s; i < n; i++) \
        cout << v[i] << sp;
#define show(v)      \
    for (auto i : v) \
        cout << i << sp;
#define vl vector<ll>
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vpair vector<pair<ll, ll>>
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

const ll N = 1000;
vector<vector<ll>> dist(N, vector<ll>(N, INF));

void solve()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= n; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
        }
    }

    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    for (ll k = 1; k <= n; k++)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                if (dist[i][k] == INF || dist[k][j] == INF)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll src, dest;
        cin >> src >> dest;
        if (dist[src][dest] == INF)
        {
            out(-1);
        }
        else
        {
            out(dist[src][dest]);
        }
    }
}

int main()
{
    fast;
    solve();
}