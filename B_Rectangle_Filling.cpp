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
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> gr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> gr[i];
    }

    bool possible = false;

    // Check if top-left and bottom-right are the same
    if (gr[0][0] == gr[n - 1][m - 1])
    {
        possible = true;
    }

    // Check for a path from top-left to top-right or bottom-left
    char start_color = gr[0][0];
    bool path1_found = false;
    for (int j = 0; j < m - 1; ++j)
    {
        if (gr[0][j] == start_color && gr[0][j + 1] == start_color)
        {
            path1_found = true;
            break;
        }
    }
    if (path1_found)
    {
        char end_color_at_top_right = gr[0][m - 1];
        if (end_color_at_top_right == gr[n - 1][m - 1])
        {
            possible = true;
        }
    }

    bool path2_found = false;
    for (int i = 0; i < n - 1; ++i)
    {
        if (gr[i][0] == start_color && gr[i + 1][0] == start_color)
        {
            path2_found = true;
            break;
        }
    }
    if (path2_found)
    {
        char end_color_at_bottom_left = gr[n - 1][0];
        if (end_color_at_bottom_left == gr[n - 1][m - 1])
        {
            possible = true;
        }
    }

    // Check for a path from bottom-right to top-right or bottom-left
    char end_color = gr[n - 1][m - 1];
    bool path3_found = false;
    for (int j = 0; j < m - 1; ++j)
    {
        if (gr[n - 1][j] == end_color && gr[n - 1][j + 1] == end_color)
        {
            path3_found = true;
            break;
        }
    }

    if (path3_found)
    {
        if (gr[0][0] == gr[0][m - 1])
        {
            possible = true;
        }
    }

    bool path4_found = false;
    for (int i = 0; i < n - 1; ++i)
    {
        if (gr[i][m - 1] == end_color && gr[i + 1][m - 1] == end_color)
        {
            path4_found = true;
            break;
        }
    }
    if (path4_found)
    {
        if (gr[0][0] == gr[n - 1][0])
        {
            possible = true;
        }
    }

    if (possible)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    fastio();

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();

#ifndef ONLINE_JUDGE
    cerr << "Time : " << (1000 * ((double)clock()) / (double)CLOCKS_PER_SEC) * 0.001 << "s\n";
#endif
}
