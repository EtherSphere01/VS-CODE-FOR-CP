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
#define PI 3.141592653589793238462
#define andd &&
#define orr ||
#define nott !
#define yes cout << "YES" << nline
#define no cout << "NO" << nline
#define out(x) cout << x << nline
typedef long long ll;

void solve()
{
    ll x, y, z, n;
    cin >> x >> y >> z >> n;

    ll totalclass = x * y;

    ll total_needed = ceil(totalclass * 0.6);
    ll class_korbo = total_needed - n;
    ll class_baki = (x - z) * y;

    vector<ll> v;
    if (class_baki >= class_korbo)
    {
        cout << "Yes" << nline;
        ll week_baki = x - z;
        ll count = y;
        while (class_korbo > 0)
        {
            if (class_korbo >= y)
            {
                v.push_back(y);
                class_korbo -= y;
            }
            else
            {
                v.push_back(class_korbo);
                class_korbo = 0;
            }
        }

        for (int i = 0; i < week_baki; i++)
        {
            v.push_back(0);
        }

        sort(v.begin(), v.end());
        vector<ll> v1;
        for (ll i = v.size() - 1; i >= week_baki; i--)
        {
            v1.push_back(v[i]);
        }
        // cout << nline;
        sort(v1.begin(), v1.end());
        for (int i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << sp;
        }
        cout << nline;
    }
    else
    {
        cout << "No" << nline;
    }
}

int main()
{
    fastio();

    solve();
}
