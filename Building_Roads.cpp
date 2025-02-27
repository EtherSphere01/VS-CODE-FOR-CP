#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define sp " "
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define andd &&
#define orr ||
#define nott !
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define yes cout << "YES" << nline
#define no cout << "NO" << nline
#define out(x) cout << x << nline
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define show(v, s, n)          \
    for (ll i = s; i < n; i++) \
        cout << v[i] << sp;
#define show(v)      \
    for (auto i : v) \
        cout << i << sp;
#define vl vector<ll>
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vpair vector<pair<ll, ll>>
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

int find(vector<int> &par, int a)
{
    if (par[a] == a)
    {
        return a;
    }
    return par[a] = find(par, par[a]);
}

void union_opp(vector<int> &par, int a, int b)
{
    int x = find(par, a);
    int y = find(par, b);
    if (x != y)
    {
        par[x] = y;
    }
}

void solve()
{

    int n, m;
    cin >> n >> m;
    vector<int> par(n + 1);

    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        union_opp(par, x, y);
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++)
    {
        if (find(par, i) != find(par, 1))
        {
            ans.push_back({1, i});
            union_opp(par, 1, i);
        }
    }

    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i.first << " " << i.second << endl;
    }
}

int main()
{
    fast;
    solve();
}