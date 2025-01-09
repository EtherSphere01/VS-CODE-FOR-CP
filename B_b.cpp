#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define PI 3.141592653589793238462
#define andd &&
#define orr ||
#define nott !
#define yes cout << "YES" << nline
#define no cout << "NO" << nline
#define out(x) cout << x << nline
typedef long long ll;

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
template <class T>
using oset = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    ll n, q;
    cin >> n >> q;

    map<ll, ll> integer, digit_value;
    oset<ll> s;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        integer[x]++;
        s.insert(x);
        while (x > 0)
        {
            digit_value[x % 10]++;
            x /= 10;
        }
    }

    // for (auto i : s)
    // {
    //     cout << i << sp;
    // }
    // cout << nline;

    while (q--)
    {
        char c;
        ll x;
        cin >> c;
        cin >> x;

        if (c == '+')
        {
            if (integer[x] == 0)
            {
                integer[x]++;
                s.insert(x);
                while (x > 0)
                {
                    digit_value[x % 10]++;
                    x /= 10;
                }
            }
            else
            {
                integer[x] = 0;
                s.erase(x);
                while (x > 0)
                {
                    digit_value[x % 10]--;
                    x /= 10;
                }
            }
        }
        else if (c == '-')
        {
            if (s.size() >= x)
            {
                ll value = *s.find_by_order(x - 1);
                integer[value] = 0;
                s.erase(value);
                while (value > 0)
                {
                    digit_value[value % 10]--;
                    value /= 10;
                }
            }
            else
            {
                continue;
            }
        }
        else
        {
            if (integer[x] == 0)
            {
                cout << -1 << nline;
            }
            else
            {
                ll ans = 0;
                while (x > 0)
                {
                    ans += digit_value[x % 10];
                    x /= 10;
                }
                cout << ans << nline;
            }
        }
    }
}

int main()
{
    fastio();
    solve();
}
