#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long

bool isIntersecting(ll l1, ll r1, ll l2, ll r2)
{
    ll lo = max(l1, l2);
    ll hi = min(r1, r2);
    if (lo <= hi)
        return true;
    return false;
}

int main()
{
    fastio();

    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    bool check = isIntersecting(l1, r1, l2, r2);
    if (check)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}