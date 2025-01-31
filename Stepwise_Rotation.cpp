#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

    ll n, q;
    cin >> n >> q;

    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll k;
    cin >> k;

    vector<ll> ans(n);
    for (ll i = 0; i < n; i++)
    {
        ans[(i + k) % n] = v[i];
    }

    vector<ll> prefix(n);
    prefix[0] = ans[0];
    for (ll i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + ans[i];
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == 0)
        {
            cout << prefix[r] << endl;
        }
        else
        {
            cout << prefix[r] - prefix[l - 1] << endl;
        }
    }
}