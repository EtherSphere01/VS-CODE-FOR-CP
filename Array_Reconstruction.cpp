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

const ll N = 2e5 + 5;
vl dp;
ll track = 0;
ll getans(ll n)
{
    if (n < 0)
    {
        return 0;
    }
    // track++;
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    for (ll i = 1; i <= n; i++)
    {
        dp[n] = getans(n - i);
        if (dp[n] == 0)
        {
            dp[n] = i;
            return dp[n];
        }
    }
    return dp[n];
}

void solve()
{

    ll n;
    cin >> n;
    vl a(n);
    ll sum = 0;
    track = 0;
    for (ll i = 0; i < n - 2; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll presum;
    cin >> presum;
    ll need = presum - sum;

   dp.resize(need + 1, -1);
    dp[0] = 0;
    getans(need);
    for (ll i = 1; i <= n; i++)
    {
        if (dp[i] != -1)
            track++;
    }
    out(track);
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
        solve();
}