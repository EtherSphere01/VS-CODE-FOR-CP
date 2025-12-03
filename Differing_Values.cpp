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

    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll need = n - k;
    ll zero = 0, one = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zero++;
        else
            one++;
    }

    ll temp_zero = zero;
    ll temp_one = one;
    vector<char> ans(n, 'a');
    for (ll i = 0; i < need; i++)
    {
        if (ans[i] == 'a')
        {
            ans[i] = '0';
            ans[i + k] = '1';
            zero--;
            one--;

            if (zero < 0 or one < 0)
            {
                out("NO");
                return;
            }
        }
        else
        {
            if (ans[i] == '0')
            {
                ans[i + k] = '1';
                one--;
            }
            else
            {
                ans[i + k] = '0';
                zero--;
            }

            if (zero < 0 or one < 0)
            {
                out("NO");
                return;
            }
        }
    }

    for (ll i = need; i < n; i++)
    {
        if (ans[i] == 'a')
        {
            if (zero > 0)
            {
                ans[i] = '0';
                zero--;
            }
            else
            {
                ans[i] = '1';
                one--;
            }
        }
    }

    bool f = true;

    for (ll i = 0; i < n; i++)
    {
        if (ans[i] == 'a')
        {
            f = false;
            break;
        }
    }
    vector<char> ans2(n, 'a');

    for (ll i = 0; i < need; i++)
    {
        if (ans2[i] == 'a')
        {
            ans2[i] = '1';
            ans2[i + k] = '0';
            temp_zero--;
            temp_one--;

            if (temp_zero < 0 or temp_one < 0)
            {
                out("NO");
                return;
            }
        }
        else
        {
            if (ans2[i] == '0')
            {
                ans2[i + k] = '1';
                temp_one--;
            }
            else
            {
                ans2[i + k] = '0';
                temp_zero--;
            }

            if (temp_zero < 0 or temp_one < 0)
            {
                out("NO");
                return;
            }
        }
    }

    for (ll i = need; i < n; i++)
    {
        if (ans2[i] == 'a')
        {
            if (temp_zero > 0)
            {
                ans2[i] = '0';
                temp_zero--;
            }
            else
            {
                ans2[i] = '1';
                temp_one--;
            }
        }
    }

    bool f2 = true;
    for (ll i = 0; i < n; i++)
    {
        if (ans2[i] == 'a')
        {
            f2 = false;
            break;
        }
    }

    if (f or f2)
    {
        out("YES");
    }
    else
    {
        out("NO");
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
