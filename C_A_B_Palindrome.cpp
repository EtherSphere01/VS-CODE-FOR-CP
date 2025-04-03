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

    ll a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    ll count = 0;
    ll tempa = a;
    ll tempb = b;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            a--;
        }
        else if (s[i] == '1')
        {
            b--;
        }
        else if (s[i] == '?')
        {
            count++;
        }
    }

    if (a < 0 orr b < 0)
    {
        out(-1);
        return;
    }

    ll n = s.size();
    for (ll i = 0; i < n; i++)
    {
        if (i == n - i - 1)
        {
            if (s[i] == '?')
            {
                if (a > 0 and tempa % 2 == 1)
                {
                    s[i] = '0';
                    a--;
                }
                else if (b > 0)
                {
                    s[i] = '1';
                    b--;
                }
                else
                {
                    out(-1);
                    return;
                }
            }
            continue;
        }
        if (s[i] == '?')
        {
            if (s[n - i - 1] == '?')
            {
                if (a >= 2)
                {
                    s[i] = '0';
                    s[n - i - 1] = '0';
                    a -= 2;
                }
                else if (b >= 2)
                {
                    s[i] = '1';
                    s[n - i - 1] = '1';
                    b -= 2;
                }
            }
            else if (s[n - i - 1] == '0')
            {
                if (a >= 1)
                {
                    s[i] = '0';
                    a--;
                }
                else
                {
                    out(-1);
                    return;
                }
            }
            else if (s[n - i - 1] == '1')
            {
                if (b >= 1)
                {
                    s[i] = '1';
                    b--;
                }
                else
                {
                    out(-1);
                    return;
                }
            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            out(-1);
            return;
        }
        else if (s[i] != s[n - i - 1])
        {
            out(-1);
            return;
        }
    }
    ll counta = 0;
    ll countb = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            counta++;
        }
        else if (s[i] == '1')
        {
            countb++;
        }
    }

    if (counta != tempa orr countb != tempb)
    {
        out(-1);
        return;
    }
    out(s);
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
