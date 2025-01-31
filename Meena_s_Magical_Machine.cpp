#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    stack<ll> s;
    ll totalsum = 0;

    while (t--)
    {
        ll x;
        cin >> x;

        if (x == 1)
        {
            if (s.empty())
            {
                cout << 0 << endl;
                continue;
            }
            else
            {
                cout << totalsum << endl;
            }
        }
        else if (x == 2)
        {
            ll p;
            cin >> p;

            s.push(p);
            totalsum += p;
        }
        else if (x == 3)
        {
            if (s.empty())
            {
                continue;
            }
            ll p = s.top();
            s.pop();
            totalsum -= p;
        }
    }
}