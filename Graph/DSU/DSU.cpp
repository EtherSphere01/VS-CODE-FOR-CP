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

const ll N = 1e5 + 5;
ll parent[N];
ll size[N];

void make(ll v)
{
    parent[v] = v;
    size[v] = 1;
}

ll find(ll v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = find(parent[v]);
}

void Union(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (size[a] < size[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        make(i);
    }
    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        Union(a, b);
    }
    ll connected_components = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (find(i) == i)
        {
            connected_components++;
        }
    }
}

// Time Complexity: O(alpha(n)) where alpha(n) is the inverse Ackermann function. Over all Allmost O(1) for all practical values of n.