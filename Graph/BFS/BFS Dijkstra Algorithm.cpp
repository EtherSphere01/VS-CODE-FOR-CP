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
bool vis[N];

void dijkstra(ll source)
{
    dist[source] = 0;
    set<pair<ll, ll>> st; // {distance, node}
    st.insert({0, source});

    while (!st.empty())
    {
        auto first_node = *st.begin();
        st.erase(st.begin());

        ll distance = first_node.first;
        ll node = first_node.second;

        if (vis[node])
        {
            continue;
        }
        vis[node] = true;

        for (auto child : adj[node])
        {
            ll child_node = child.first;
            ll child_weight = child.second;

            if (distance + child_weight < dist[child_node])
            {
                dist[child_node] = distance + child_weight;
                st.insert({dist[child_node], child_node});
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
        vis[i] = false;
    }

    for (ll i = 1; i <= m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }

    dijkstra(1);
    for (ll i = 1; i <= n; i++)
    {
        cout << dist[i] << sp;
    }
    return 0;
}

// Time Complexity: O((n+m)logn)
// Space Complexity: O(n+m)
// can be used to find shortest path between two nodes
// can not use for negative weights
// can not use to detect negative cycle