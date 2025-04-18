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
#define in(a)         \
    for (auto &x : a) \
        cin >> x;
#define showr(v, s, n)         \
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

void solve()
{

    ll n, weight;
    cin >> n >> weight;
    vl w(n), v(n);
    in(w);
    in(v);

    ll dp[n + 1][weight + 1];
    mem0(dp);

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= weight; j++)
        {
            if (w[i - 1] <= j)
            {
                ll pick = v[i - 1] + dp[i - 1][j - w[i - 1]];
                ll notpick = dp[i - 1][j];
                dp[i][j] = max(pick, notpick);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    out(dp[n][weight]);
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
        solve();
}