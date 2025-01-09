#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define INF 1e18
#define nline "\n"
#define sp " "
#define all(x) x.begin(), x.end()

vector<ll> adj[100001];
vector<bool> vis(100001, false);

bool dfs(ll node, ll parent)
{
    vis[node] = true;
    for (ll child : adj[node])
    {
        if (!vis[child])
        {
            if (dfs(child, node))
            {
                return true;
            }
        }
        else if (child != parent)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool cycle = false;
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1))
            {
                cycle = true;
                break;
            }
        }
    }
    if (cycle)
    {
        cout << "Cycle is present" << nline;
    }
    else
    {
        cout << "Cycle is not present" << nline;
    }
    return 0;
}