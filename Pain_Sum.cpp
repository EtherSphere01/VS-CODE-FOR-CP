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
    ll n, q;
    cin >> n >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        ll right = r / 3;
        ll right_rem = r % 3;
        ll left = l / 3;
        ll left_rem = l % 3;

        ll totalsum = (right * (right + 1)) / 2;
        totalsum *= 3;

        ll leftsum = left * (left + 1) / 2;
        leftsum *= 3;
        // leftsum += (left + 1) * (left_rem--);
        if (left_rem == 0)
        {
            leftsum -= left;
        }
        else if (left_rem == 2)
        {
            leftsum += left + 1;
        }
        totalsum -= leftsum;

        ll rightele = (right + 1) * right_rem;
        totalsum += rightele;
        out(totalsum);
    }
}

int main()
{
    fast;
    solve();
}