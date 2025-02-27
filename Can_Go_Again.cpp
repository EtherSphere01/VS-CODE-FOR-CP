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

const ll E = 1e6 + 5;
vector<pair<ll, ll>> adj[E];
vector<ll> dist(E, INF);

bool bellman_ford(ll src, ll n)
{
    dist[src] = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            for (auto child : adj[j])
            {
                ll child_node = child.fi;
                ll child_weight = child.se;

                if (child_weight + dist[j] < dist[child_node] andd dist[j] != INF)
                {
                    dist[child_node] = dist[j] + child_weight;
                }
            }
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        for (auto child : adj[i])
        {
            ll child_node = child.fi;
            ll child_weight = child.se;

            if (child_weight + dist[i] < dist[child_node] andd dist[i] != INF)
            {
                return false;
            }
        }
    }

    return true;
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }

    ll src;
    cin >> src;
    bool f = bellman_ford(src, n);

    if (f == false)
    {
        out("Negative Cycle Detected");
        ll q;
        cin >> q;
        while (q--)
        {
            ll x;
            cin >> x;
        }
        return;
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll node;
        cin >> node;
        if (dist[node] == INF)
        {
            out("Not Possible");
        }
        else
        {
            out(dist[node]);
        }
    }
}

int main()
{
    fast;
    solve();
}