// lowest common ancestor means the lowest node in the tree that has both the nodes as its parent
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

const int N = 100001;
vector<ll> adj[N];
vector<ll> par(N, -1);

void dfs(ll node, ll parent = -1)
{
    par[node] = parent;
    for (auto child : adj[node])
    {
        if (child != parent)
        {
            dfs(child, node);
        }
    }
}

vector<ll> path(ll node)
{
    vector<ll> p;
    while (node != -1)
    {
        p.pb(node);
        node = par[node];
    }
    reverse(p.begin(), p.end());
    return p;
}

int main()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);

    ll x, y;
    cin >> x >> y;
    vector<ll> path_x = path(x);
    vector<ll> path_y = path(y);

    ll lca = -1;

    ll length = min(path_x.size(), path_y.size());
    for (ll i = 0; i < length; i++)
    {
        if (path_x[i] == path_y[i])
        {
            lca = path_x[i];
        }
        else
            break;
    }

    cout << lca << nline;
}