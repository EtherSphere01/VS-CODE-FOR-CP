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

ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};

void solve()
{
    ll row, col, d;
    cin >> row >> col >> d;
    vector<string> s(row);
    for (ll i = 0; i < row; i++)
        cin >> s[i];

    ll maxi = (ll)INF;
    vector<vector<ll>> dist(row, vector<ll>(col, maxi));
    queue<pair<ll, ll>> q;

    for (ll i = 0; i < row; i++)
    {
        for (ll j = 0; j < col; j++)
        {
            if (s[i][j] == 'H')
            {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        ll x = q.front().ff;
        ll y = q.front().ss;
        q.pop();
        ll d = dist[x][y];
        for (ll i = 0; i < 4; i++)
        {
            ll new_x = x + dx[i], new_y = y + dy[i];
            if (new_x < 0 orr new_y < 0 orr new_x >= row orr new_y >= col orr s[new_x][new_y] == '#' orr dist[new_x][new_y] != maxi)
                continue;
            dist[new_x][new_y] = d + 1;
            q.push({new_x, new_y});
        }
    }

    ll ans = 0;
    for (ll i = 0; i < row; i++)
    {
        for (ll j = 0; j < col; j++)
        {
            if (dist[i][j] <= d)
                ans++;

            // cout << dist[i][j] << " ";
        }
        // cout << endl;
    }
    cout << ans << endl;
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
