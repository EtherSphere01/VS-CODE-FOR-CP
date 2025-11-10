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

    ll n;
    cin >> n;
    vl a(n);
    in(a);
    string s;
    cin >> s;

    string x = "";
    for (ll i = 0; i < n; i++)
    {
        x += '0';
    }

    if (s[0] == '1' || s[n - 1] == '1')
    {
        out(-1);
        return;
    }

    for (ll i = 0; i < n; i++)
    {
        if (a[i] == n || a[i] == 1)
        {
            if (s[i] == '1')
            {
                out(-1);
                return;
            }
        }
    }

    vpair b;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            b.push_back({a[i], i});
        }
    }

    if (b.empty())
    {
        out(0);
        return;
    }

    sort(all(b));

    auto small = b[0];
    auto large = b[b.size() - 1];

    vpair ans;

    ll small_indx = -1, large_indx = -1;
    for (ll i = small.ss; i >= 0; i--)
    {
        if (a[i] < small.ff)
        {
            small_indx = i;
        }
    }

    for (ll i = small.ss + 1; i < n; i++)
    {
        if (a[i] > small.ff)
        {
            large_indx = i;
        }
    }

    if (small_indx != -1 && large_indx != -1 && small_indx < large_indx)
    {
        ll low = min(a[small_indx], a[large_indx]);
        ll high = max(a[small_indx], a[large_indx]);
        for (ll i = small_indx + 1; i <= large_indx - 1; i++)
        {
            if (low < a[i] && a[i] < high)
                x[i] = '1';
        }
        ans.push_back({small_indx, large_indx});
    }

    small_indx = -1, large_indx = -1;
    for (ll i = small.ss; i >= 0; i--)
    {
        if (a[i] > small.ff)
        {
            large_indx = i;
        }
    }

    for (ll i = small.ss + 1; i < n; i++)
    {
        if (a[i] < small.ff)
        {
            small_indx = i;
        }
    }

    if (small_indx != -1 && large_indx != -1 && large_indx < small_indx)
    {
        ll low = min(a[small_indx], a[large_indx]);
        ll high = max(a[small_indx], a[large_indx]);
        for (ll i = large_indx + 1; i <= small_indx - 1; i++)
        {
            if (low < a[i] && a[i] < high)
                x[i] = '1';
        }
        ans.push_back({large_indx, small_indx});
    }

    //

    small_indx = -1, large_indx = -1;
    for (ll i = large.ss; i >= 0; i--)
    {
        if (a[i] < large.ff)
        {
            small_indx = i;
        }
    }

    for (ll i = large.ss + 1; i < n; i++)
    {
        if (a[i] > large.ff)
        {
            large_indx = i;
        }
    }

    if (small_indx != -1 && large_indx != -1 && small_indx < large_indx)
    {
        ll low = min(a[small_indx], a[large_indx]);
        ll high = max(a[small_indx], a[large_indx]);
        for (ll i = small_indx + 1; i <= large_indx - 1; i++)
        {
            if (low < a[i] && a[i] < high)
                x[i] = '1';
        }
        ans.push_back({small_indx, large_indx});
    }

    small_indx = -1, large_indx = -1;
    for (ll i = large.ss; i >= 0; i--)
    {
        if (a[i] > large.ff)
        {
            large_indx = i;
        }
    }

    for (ll i = large.ss + 1; i < n; i++)
    {
        if (a[i] < large.ff)
        {
            small_indx = i;
        }
    }

    if (small_indx != -1 && large_indx != -1 && large_indx < small_indx)
    {
        ll low = min(a[small_indx], a[large_indx]);
        ll high = max(a[small_indx], a[large_indx]);
        for (ll i = large_indx + 1; i <= small_indx - 1; i++)
        {
            if (low < a[i] && a[i] < high)
                x[i] = '1';
        }
        ans.push_back({large_indx, small_indx});
    }

    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            if (x[i] == '1')
            {
                continue;
            }
            else
            {
                out(-1);
                return;
            }
        }
    }

    if (ans.size() == 0)
    {
        cout << 1 << nline << 1 << sp << n << nline;
        return;
    }

    out(ans.size());
    for (auto i : ans)
    {
        cout << i.ff + 1 << sp << i.ss + 1 << nline;
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
