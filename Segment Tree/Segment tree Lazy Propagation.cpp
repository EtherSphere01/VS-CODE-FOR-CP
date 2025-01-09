#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
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
#define show(v, s, n)          \
    for (ll i = s; i < n; i++) \
        cout << v[i] << sp;
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

vector<ll> arr, tree, lazy;

ll merge(ll left, ll right)
{
    return left + right;
}

void build(ll node, ll left, ll right)
{
    if (left == right)
    {
        tree[node] = arr[left];
        return;
    }

    ll mid = (left + right) / 2;
    ll left_node = 2 * node;
    ll right_node = 2 * node + 1;

    build(left_node, left, mid);
    build(right_node, mid + 1, right);
    tree[node] = merge(tree[left_node], tree[right_node]);
}

void update(ll node, ll left, ll right, ll l, ll r, ll value)
{
    if (lazy[node] != 0)
    {
        ll lazy_value = lazy[node];
        lazy[node] = 0;
        tree[node] += (right - left + 1) * lazy_value;
        if (left != right)
        {
            lazy[2 * node] += lazy_value;
            lazy[2 * node + 1] += lazy_value;
        }
    }

    if (r < left || l > right)
    {
        return;
    }

    if (left >= l && right <= r)
    {
        ll element = (right - left + 1);
        tree[node] += (element * value);

        if (left != right)
        {
            lazy[2 * node] += value;
            lazy[2 * node + 1] += value;
        }
        return;
    }

    ll mid = (left + right) / 2;
    ll left_node = 2 * node;
    ll right_node = 2 * node + 1;

    update(left_node, left, mid, l, r, value);
    update(right_node, mid + 1, right, l, r, value);
    tree[node] = merge(tree[left_node], tree[right_node]);
}

ll query(ll node, ll left, ll right, ll l, ll r)
{
    if (lazy[node] != 0)
    {
        ll lazy_value = lazy[node];
        lazy[node] = 0;
        tree[node] += (right - left + 1) * lazy_value;

        if (left != right)
        {
            lazy[2 * node] += lazy_value;
            lazy[2 * node + 1] += lazy_value;
        }
    }

    if (r < left || l > right)
    {
        return 0;
    }

    if (left >= l && right <= r)
    {
        return tree[node];
    }

    ll mid = (left + right) / 2;
    ll left_node = 2 * node;
    ll right_node = 2 * node + 1;
    ll left_answer = query(left_node, left, mid, l, r);
    ll right_answer = query(right_node, mid + 1, right, l, r);
    return merge(left_answer, right_answer);
}

void solve()
{
    ll n;
    cin >> n;
    arr.resize(n);
    tree.resize(4 * n);
    lazy.resize(4 * n);
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    build(1, 1, n);
    debug(tree);
    cout << query(1, 1, n, 1, n) << nline;
    update(1, 1, n, 5, n, 2);
    cout << query(1, 1, n, 1, n) << nline;
    cout << query(1, 1, n, 1, n) << nline;
    update(1, 1, n, 4, 4, 10);
    cout << query(1, 1, n, 1, n) << nline;
    debug(tree);
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

/*
class segtree_lazy
{
    vector<ll> tree, lazy;

public:
    segtree_lazy(ll n)
    {
        tree.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }
    ll merge(ll left, ll right)
    {
        return left + right;
    }

    void build(ll node, ll left, ll right)
    {
        if (left == right)
        {
            tree[node] = arr[left];
            return;
        }

        ll mid = (left + right) / 2;
        ll left_node = 2 * node;
        ll right_node = 2 * node + 1;

        build(left_node, left, mid);
        build(right_node, mid + 1, right);
        tree[node] = merge(tree[left_node], tree[right_node]);
    }

    void update(ll node, ll left, ll right, ll l, ll r, ll value)
    {
        if (lazy[node] != 0)
        {
            ll lazy_value = lazy[node];
            lazy[node] = 0;
            tree[node] += (right - left + 1) * lazy_value;
            if (left != right)
            {
                lazy[2 * node] += lazy_value;
                lazy[2 * node + 1] += lazy_value;
            }
        }

        if (r < left || l > right)
        {
            return;
        }

        if (left >= l && right <= r)
        {
            ll element = (right - left + 1);
            tree[node] += (element * value);

            if (left != right)
            {
                lazy[2 * node] += value;
                lazy[2 * node + 1] += value;
            }
            return;
        }

        ll mid = (left + right) / 2;
        ll left_node = 2 * node;
        ll right_node = 2 * node + 1;

        update(left_node, left, mid, l, r, value);
        update(right_node, mid + 1, right, l, r, value);
        tree[node] = merge(tree[left_node], tree[right_node]);
    }

    ll query(ll node, ll left, ll right, ll l, ll r)
    {
        if (lazy[node] != 0)
        {
            ll lazy_value = lazy[node];
            lazy[node] = 0;
            tree[node] += (right - left + 1) * lazy_value;

            if (left != right)
            {
                lazy[2 * node] += lazy_value;
                lazy[2 * node + 1] += lazy_value;
            }
        }

        if (r < left || l > right)
        {
            return 0;
        }

        if (left >= l && right <= r)
        {
            return tree[node];
        }

        ll mid = (left + right) / 2;
        ll left_node = 2 * node;
        ll right_node = 2 * node + 1;
        ll left_answer = query(left_node, left, mid, l, r);
        ll right_answer = query(right_node, mid + 1, right, l, r);
        return merge(left_answer, right_answer);
    }
};
*/