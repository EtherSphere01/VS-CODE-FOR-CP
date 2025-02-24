#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define sp " "
#define pb push_back
#define ll long long

const ll N = 2e5 + 5;
vector<pair<ll, ll>> adj[N];
ll dist[N];
bool vis[N];

void dijkstra(ll source)
{
    dist[source] = 0;
    set<pair<ll, ll>> st;
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
        adj[b].pb({a, c});
    }

    dijkstra(1);

    for (ll i = 2; i <= n; i++)
    {
        if (dist[i] == INF)
        {
            cout << -1 << sp;
        }
        else
        {
            cout << dist[i] << sp;
        }
    }
    cout << nline;
}