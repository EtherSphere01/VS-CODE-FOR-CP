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

vector<ll> spf;
vector<ll> createSpf(ll n)
{
    vector<ll> spff(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        spff[i] = i;
    }

    for (ll i = 2; i * i <= n; ++i)
    {
        if (spff[i] == i)
        {
            for (ll j = i * i; j <= n; j += i)
            {
                if (spff[j] == j)
                {
                    spff[j] = i;
                }
            }
        }
    }

    return spff;
}

vector<ll> primeFactorization(ll n)
{
    vector<ll> factors;
    ll temp_n = n;
    while (temp_n != 1 && temp_n < sz(spf))
    {
        factors.push_back(spf[temp_n]);
        temp_n /= spf[temp_n];
    }
    if (temp_n == 1)
    {
        return factors;
    }

    if (!factors.empty())
    {
        n = temp_n;
    }
    else
    {
        while (n % 2 == 0)
        {
            factors.push_back(2);
            n = n / 2;
        }
    }

    for (ll i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n = n / i;
        }
    }

    if (n > 2)
        factors.push_back(n);

    return factors;
}

void solve()
{

    ll n, k;
    cin >> n >> k;
    unordered_set<ll> s;
    bool is_one = false;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            is_one = true;
        }
        s.insert(x);
    }

    unordered_set<ll> unique_elements;
    if (is_one)
    {
        unique_elements.insert(1);
    }
    else
    {
        for (auto i : s)
        {

            vector<ll> factors = primeFactorization(i);
            for (auto factor : factors)
            {
                unique_elements.insert(factor);
            }
        }
    }

    for (auto i : unique_elements)
    {
        for (ll multiple = i; multiple <= k; multiple += i)
        {
            if (s.find(multiple) == s.end())
            {
                out(-1);
                return;
            }
        }
    }

    out(sz(unique_elements));
    vl ans;
    for (auto i : unique_elements)
    {
        ans.pb(i);
    }
    sort(all(ans));
    show(ans);
    cout << nline;
}

int main()
{
    fastio();

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    spf = createSpf(200000);
    int t;
    cin >> t;
    while (t--)
        solve();

#ifndef ONLINE_JUDGE
    cerr << "Time : " << (1000 * ((double)clock()) / (double)CLOCKS_PER_SEC) * 0.001 << "s\n";
#endif
}
