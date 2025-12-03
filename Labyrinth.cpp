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

int n, m;
vector<vector<char>> grid;
vector<vector<pair<int, int>>> parent;
vector<vector<int>> visited;

bool is_valid(int x, int y)
{
    return (x >= 0 and x < n and y >= 0 and y < m and grid[x][y] != '#' and visited[x][y] == 0);
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool bfs(int start_x, int start_y, int end_x, int end_y)
{
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = 1;
    parent[start_x][start_y] = {-1, -1};

    while (!q.empty())
    {
        auto ele = q.front();
        q.pop();
        int x = ele.ff;
        int y = ele.ss;

        if (x == end_x and y == end_y)
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (is_valid(new_x, new_y))
            {
                q.push({new_x, new_y});
                visited[new_x][new_y] = 1;
                parent[new_x][new_y] = {x, y};
            }
        }
    }

    return false;
}

void solve()
{
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    parent.resize(n, vector<pair<int, int>>(m, {-1, -1}));
    visited.resize(n, vector<int>(m, 0));

    int start_x = -1, start_y = -1;
    int end_x = -1, end_y = -1;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            grid[i][j] = s[j];
            if (s[j] == 'A')
            {
                start_x = i;
                start_y = j;
            }
            else if (s[j] == 'B')
            {
                end_x = i;
                end_y = j;
            }
        }
    }

    if (bfs(start_x, start_y, end_x, end_y))
    {
        yes;
        vector<char> path;
        int x = end_x;
        int y = end_y;
        while (x != start_x or y != start_y)
        {
            auto p = parent[x][y];
            int px = p.ff;
            int py = p.ss;
            if (px == x - 1 and py == y)
            {
                path.pb('D');
            }
            else if (px == x + 1 and py == y)
            {
                path.pb('U');
            }
            else if (px == x and py == y - 1)
            {
                path.pb('R');
            }
            else if (px == x and py == y + 1)
            {
                path.pb('L');
            }
            x = px;
            y = py;
        }

        reverse(all(path));
        out(sz(path));
        for (auto c : path)
        {
            cout << c;
        }
        cout << nline;
    }
    else
    {
        no;
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
