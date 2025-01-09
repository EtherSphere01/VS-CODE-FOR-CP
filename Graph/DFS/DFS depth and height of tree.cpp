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
vector<ll> depth(100001, 0), height(100001, 0);

void dfs(ll node, ll parent)
{

    for (ll child : adj[node])
    {
        if (child != parent)
        {
            depth[child] = depth[node] + 1;
            dfs(child, node);
            height[node] = max(height[node], height[child] + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << "Node: " << i << " Depth: " << depth[i] << " Height: " << height[i] << nline;
    }
}