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
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define andd &&
#define orr ||
#define nott !
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define yes cout << "YES" << nline
#define no cout << "NO" << nline
#define yesno(f) \
    if (f)       \
        yes;     \
    else         \
        no
#define noyes(f) \
    if (!f)      \
        yes;     \
    else         \
        no
#define out(x) cout << x << nline
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define in(a)         \
    for (auto &x : a) \
        cin >> x;
#define showr(v, s, n)         \
    for (ll i = s; i < n; i++) \
        cout << v[i] << sp;
#define show(v)      \
    for (auto i : v) \
        cout << i << sp;
#define show_rev(v, s, n)       \
    for (ll i = s; i >= n; i--) \
        cout << v[i] << sp;
#define show_pair(v, s, n)     \
    for (ll i = s; i < n; i++) \
        cout << v[i].ff << sp << v[i].ss << nline;
#define vl vector<ll>
#define vi vector<int>
#define ll long long
#define lld long double
#define ull unsigned long long
#define pair <ll, ll> pair<ll, ll>
#define vpair vector<pair<ll, ll>>
#define vvpair vector<vector<pair<ll, ll>>>
#define vll vector<long long>
#define vvll vector<vector<long long>>

class dsu
{
private:
    vector<ll> par;
    vector<ll> sz;

public:
    dsu(ll n)
    {
        par = vector<ll>(n);
        iota(all(par), 0);
        sz = vector<ll>(n, 1);
    }
    ll find(ll u)
    {
        if (par[u] != par[par[u]])
        {
            par[u] = find(par[par[u]]);
        }
        return par[u];
    }

    bool connected(ll u, ll v)
    {
        return find(u) == find(v);
    }

    bool join(ll u, ll v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] < sz[v])
            swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        return true;
    }
};

int main()
{
    dsu uf(5);
    uf.join(0, 1);
    uf.join(1, 2);
    uf.join(3, 4);
    if (uf.connected(0, 2))
        cout << "0 and 2 are connected" << nline;
    if (uf.connected(0, 3))
    {
        cout << '0' << sp << '3' << " are connected" << nline;
    }
}