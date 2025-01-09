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

const ll N = 2e5 + 5;
vector<pair<ll, ll>> adj[N]; // {node, weight}
ll dist[N];

void bellman_fold(ll source)
{
    dist[source] = 0;
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = 1; j <= N; j++)
        {
            for (auto child : adj[j])
            {
                ll child_node = child.first;
                ll child_weight = child.second;

                if (dist[j] + child_weight < dist[child_node] and dist[j] != INF)
                {
                    dist[child_node] = dist[j] + child_weight;
                }
            }
        }
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }

    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }

    bellman_fold(1);

    for (ll i = 1; i <= n; i++)
    {
        cout << dist[i] << sp;
    }
    cout << nline;
    return 0;
}

// Time Complexity: O(n*m)
// Space Complexity: O(n+m)
// also work for negative weights
// can be used to detect negative cycle
