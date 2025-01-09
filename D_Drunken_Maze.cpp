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

ll n, m;

vector<vector<pair<ll, ll>>> path;
vector<vector<bool>> vis;

ll sx, sy, ex, ey;

vector<pair<ll, ll>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(ll x, ll y)
{
    if (x < 0 or x >= n or y < 0 or y >= m)
        return false;
    if (vis[x][y])
        return false;
    return true;
}

void bfs()
{
    queue<pair<ll, ll>> q;
    q.push({sx, sy});
    while (!q.empty())
    {
        ll cx = q.front().first;
        ll cy = q.front().second;
        q.pop();
        for (auto mv : moves)
        {
            ll mvx = mv.first;
            ll mvy = mv.second;
            if (isValid(cx + mvx, cy + mvy))
            {
                q.push({cx + mvx, cy + mvy});
                vis[cx + mvx][cy + mvy] = true;
                path[cx + mvx][cy + mvy] = {mvx, mvy};
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    path.resize(n);
    vis.resize(n);
    for (ll i = 0; i < n; ++i)
    {
        path[i].resize(m);
        vis[i].resize(m);
    }
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j)
        {
            path[i][j] = {-1, -1};
            char c;
            cin >> c;
            if (c == '#')
            {
                vis[i][j] = true;
            }
            if (c == 'S')
            {
                sx = i;
                sy = j;
            }
            if (c == 'T')
            {
                ex = i;
                ey = j;
            }
        }
    }
    bfs();

    if (!vis[ex][ey])
    {
        cout << "-1" << endl;
        return 0;
    }

    vector<pair<ll, ll>> ans;
    pair<ll, ll> end = {ex, ey};

    while (end.first != sx or end.second != sy)
    {
        ans.push_back(path[end.first][end.second]);
        end.first -= ans.back().first;
        end.second -= ans.back().second;
    }

    reverse(ans.begin(), ans.end());
    string s = "";
    for (auto c : ans)
    {
        if (c.first == 1 and c.second == 0)
        {
            s += "D";
        }
        else if (c.first == -1 and c.second == 0)
        {
            s += "U";
        }
        else if (c.first == 0 and c.second == 1)
        {
            s += "R";
        }
        else if (c.first == 0 and c.second == -1)
        {
            s += "L";
        }
    }
    cout << endl;
    // cout << s << endl;

    char current = s[0];
    int count = 0;

    int distance = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == current)
        {
            count++;
            distance++;
        }
        else
        {
            count = 1;
            current = s[i];
            distance++;
        }
        if (count == 3 && i != s.size() - 1)
        {
            if (s[i] == s[i + 1])
            {
                distance += 2;
                count = 1;
            }
            else
                count = 0;
        }
    }
    cout << distance << nline;
}
