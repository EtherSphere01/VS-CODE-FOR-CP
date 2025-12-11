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

int queen[20];
char grid[8][8];
bool check(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int prow = i;
        int pcol = queen[i];

        if (pcol == col || abs(prow - row) == abs(pcol - col))
        {
            return 0;
        }
    }
    return 1;
}

int rec(int level)
{
    if (level == 8)
    {
        return 1;
    }

    int ans = 0;
    for (int col = 0; col < 8; col++)
    {
        if (grid[level][col] != '*' && check(level, col))
        {
            queen[level] = col;
            ans += rec(level + 1);
            queen[level] = -1;
        }
    }

    return ans;
}
void solve()
{

    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++)
        {
            grid[i][j] = s[j];
        }
    }
    for (int i = 0; i < 20; i++)
    {
        queen[i] = -1;
    }

    int ans = rec(0);
    out(ans);
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
