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
vector<ll> subtree_sum(N, 0);
vector<ll> even_count(N, 0);

void dfs(ll node, ll parent = 0)
{

    if (node % 2 == 0)
    {
        even_count[node] += 1;
    }
    subtree_sum[node] += node;

    for (auto child : adj[node])
    {
        if (child != parent)
        {
            dfs(child, node);
            subtree_sum[node] += subtree_sum[child];
            even_count[node] += even_count[child];
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
    dfs(1);

    for (ll i = 1; i <= n; i++)
    {
        cout << "Node: " << i << " Subtree Sum: " << subtree_sum[i] << " Even Count: " << even_count[i] << nline;
    }
}