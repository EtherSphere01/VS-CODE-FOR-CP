#include "bits/stdc++.h"
using namespace std;
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int N = 0;
vector<int> fact(51);
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b;

    int cnt = 0, cnt2 = 0, cnt3 = 0;
    ;
    rep(i, 0, n)
    {
        cin >> a[i];
        if (a[i] > 0)
            cnt++;
        else if (a[i] < 0)
            cnt2++;
        else
            cnt3++;
    }

    if (is_sorted(all(a)))
    {
        cout << 0 << endl;
        return;
    }
    vector<pii> sol;
    if (cnt + cnt3 == n)
    {

        rep(i, 1, n)
        {
            sol.pb({i, i - 1});
        }
    }
    else if (cnt2 + cnt3 == n)
    {

        for (int i = n - 2; i >= 0; i--)
        {
            sol.pb({i, i + 1});
        }
    }
    else
    {
        int mxidx = max_element(all(a)) - a.begin();
        int mnidx = min_element(all(a)) - a.begin();
        int mx = a[mxidx];
        int mn = a[mnidx];
        int c = 0;
        if (mx >= abs(mn))
        {
            if (cnt2 <= 12)
            {
                rep(i, 0, n)
                {
                    if (a[i] < 0)
                        sol.pb({i, mxidx});
                }
                rep(i, 1, n)
                {
                    sol.pb({i, i - 1});
                }
            }
            else
            {
                while (mn > -20)
                {
                    mn += mn;
                    sol.pb({mnidx, mnidx});
                }
                rep(i, 0, n)
                {
                    if (a[i] > 0)
                        sol.pb({i, mnidx});
                }
                for (int i = n - 2; i >= 0; i--)
                {
                    sol.pb({i, i + 1});
                }
            }
        }
        else
        {
            if (cnt <= 12)
            {
                rep(i, 0, n)
                {
                    if (a[i] > 0)
                        sol.pb({i, mnidx});
                }
                for (int i = n - 2; i >= 0; i--)
                {
                    sol.pb({i, i + 1});
                }
            }
            else
            {
                while (mx < 20)
                {
                    mx += mx;
                    sol.pb({mxidx, mxidx});
                }
                rep(i, 0, n)
                {
                    if (a[i] < 0)
                        sol.pb({i, mxidx});
                }
                rep(i, 1, n)
                {
                    sol.pb({i, i - 1});
                }
            }
        }
    }
    cout << sol.size() << endl;
    for (auto x : sol)
        cout << x.first + 1 << " " << x.second + 1 << endl;

    return;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    fact[1] = 1;
    rep(i, 2, 22) fact[i] = fact[i - 1] * (i);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}