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

void dfs(ll node)
{
    vis[node] = true;
    cout << node << sp;
    for (ll child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
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
    dfs(1);
    return 0;
}