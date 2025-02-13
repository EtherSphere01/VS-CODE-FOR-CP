#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

template <typename T>
using os = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using oms = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// read question properly
// don't forget newlines!!!!!!
// take care about cin >> t;
// comment the optimization before debugging
// ALWAYS USE FIXED << SETPRECISION WHILE OUTPUTTING FLOATS

ll func(ll n)
{
    return (n - 1) / 2;
}

void solve()
{
    ll n;
    cin >> n;
    ia(p, n);

    if (n == 1 || n == 2)
    {
        yes;
        return;
    }

    f(i, n)
    {
        p[i]--;
    }
    ll ip[n];
    f(i, n)
    {
        ip[p[i]] = i;
    }

    if ((p[0] == 0 && p[n - 1] == 1) || (p[0] == 1 && p[n - 1] == 0))
    {
        multiset<ll> ms;
        set<ll> ind;
        ind.insert(0);
        ind.insert(n - 1);
        ms.insert(n - 2);
        for (ll i = 2; i < n; i++)
        {
            auto it = ind.lower_bound(ip[i]);
            assert(it != ind.end());
            ll a = *it;
            ll b = *prev(it);
            if (func(a - b - 1) != func(*ms.rbegin()))
            {
                no;
                return;
            }
            if ((a - b) % 2 == 0)
            {
                if ((a + b) / 2 != ip[i])
                {
                    no;
                    return;
                }
            }
            else
            {
                if ((a + b) / 2 != ip[i] && (a + b) / 2 + 1 != ip[i])
                {
                    no;
                    return;
                }
            }
            ms.erase(ms.find(a - b - 1));
            ms.insert(ip[i] - b - 1);
            ms.insert(a - ip[i] - 1);
            ind.insert(ip[i]);
        }
        yes;
    }
    else
    {
        no;
        return;
    }
}

int main()
{
#ifdef PRADY
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t T = clock();
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

#ifdef PRADY
    cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
#endif
    return 0;
}