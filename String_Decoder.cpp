#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define sp " "
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define andd &&
#define orr ||
#define nott !
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define yes cout << "YES" << nline
#define no cout << "NO" << nline
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
#define vl vector<ll>
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vpair vector<pair<ll, ll>>
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void solve()
{

    string s;
    cin >> s;
    map<char, ll> m;
    ll n = s.size();
    char last_char;
    string newstr = "";
    for (ll i = 0; i < n; i++)
    {
        if (s[i] >= 'a' andd s[i] <= 'z')
            last_char = s[i];
        else
        {
            if (s[i] == '0')
                continue;
            ll dig = s[i] - '0';
            for (ll j = 0; j < dig; j++)
            {
                newstr += last_char;
            }
        }
    }
    out(newstr);
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
        solve();
}