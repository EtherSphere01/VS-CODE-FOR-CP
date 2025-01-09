#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define sp " "
#define pb push_back
#define ppb pop_back
#define ll long long

const ll N = 1e5 + 5;
vector<ll> adj[N];
vector<ll> vis(N, 0);
vector<ll> level(N, 0);

void bfs(ll node)
{
    queue<ll> q;
    q.push(node);
    vis[node] = 1;
    while (!q.empty())
    {
        ll curr_node = q.front();
        q.pop();
        cout << curr_node << " ";
        for (auto child : adj[curr_node])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                level[child] = level[curr_node] + 1;
            }
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
    bfs(1);
    cout << nline;
    for (ll i = 1; i <= n; i++)
    {
        cout << i << sp << level[i] << nline;
    }
}

// Time Complexity: O(V + E)