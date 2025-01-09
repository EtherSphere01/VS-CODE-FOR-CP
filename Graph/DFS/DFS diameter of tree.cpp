// diameter means the longest path between two nodes in a tree
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
vector<ll> depth(N, 0);
void dfs(ll node, ll parent = -1)
{
    for (auto child : adj[node])
    {
        if (child != parent)
        {
            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    }
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

    ll max_depth = 0;
    ll max_d_element = -1;

    dfs(1);

    for (ll i = 1; i <= n; i++)
    {
        if (depth[i] > max_depth)
        {
            max_depth = depth[i];
            max_d_element = i;
        }
        depth[i] = 0;
    }

    dfs(max_d_element);

    max_depth = 0;
    for (ll i = 1; i <= n; i++)
    {
        max_depth = max(max_depth, depth[i]);
    }
    cout << max_depth << nline;
}

// time complexity is O(n)+O(v+e) and space complexity is O(n)