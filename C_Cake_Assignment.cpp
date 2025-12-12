#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);                   \
    cout.precision(numeric_limits<double>::max_digits10);
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
#define vc vector<char>
#define vs vector<string>
#define vpair vector<pair<ll, ll>>

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

int n;
int x[105];
int dp[105][100100];

int rec(int level, int left)
{
    // pruning
    if (left < 0)
    {
        return 0;
    }
    // basecase
    if (level == n + 1)
    {
        if (left == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // caching check
    if (dp[level][left] != -1)
    {
        return dp[level][left];
    }
    // transition
    int ans = 0;
    if (rec(level + 1, left) == 1)
    {
        ans = 1;
    }
    else if (rec(level + 1, left - x[level]) == 1)
    {
        ans = 1;
    }

    return dp[level][left] = ans;
}

void print_set(int level, int left)
{
    if (level == n + 1)
    {
        return;
    }

    if (rec(level + 1, left) == 1)
    {
        print_set(level + 1, left);
    }
    else if (rec(level + 1, left - x[level]) == 1)
    {
        cout << x[level] << sp;
        print_set(level + 1, left - x[level]);
    }
}

void solve()
{
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }

    memset(dp, -1, sizeof(dp));
    while (q--)
    {
        int t;
        cin >> t;

        if (rec(1, t) == 1)
        {
            print_set(1, t);
            cout << nline;
        }
        else
        {
            cout << -1 << nline;
        }
    }
}

int main()
{
    fastio();

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    solve();

#ifndef ONLINE_JUDGE
    cerr << "Time : " << (1000 * ((double)clock()) / (double)CLOCKS_PER_SEC) * 0.001 << "s\n";
#endif
}