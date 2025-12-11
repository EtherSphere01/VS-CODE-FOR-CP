#include <bits/stdc++.h>
using namespace std;

#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);              \
    cout.precision(numeric_limits<double>::max_digits10);

#define int long long

const int INF = 1e18;

void CoderAbhi27()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    } // n
    // INPUT

    int ans = 0;
    int mx2 = -INF, mn1 = INF;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2)
        {
            ans -= a[i];
            mx = max(mx, 2 * a[i] + i - mn1);
            mx2 = max(mx2, 2 * a[i] - i);
        }
        else
        {
            ans += a[i];
            mn1 = min(mn1, 2 * a[i] + i);
            mx = max(mx, mx2 - 2 * a[i] + i);
        }
    } // n
    if (n % 2)
    {
        mx = max(mx, n - 1);
    }
    else
    {
        mx = max(mx, n - 2);
    }
    ans += mx;
    cout << ans << '\n';
}

// tc : O(n)
// sc : O(n)

int32_t main()
{
    fastIO;

    int t = 1;
    cin >> t;
    while (t--)
    {
        CoderAbhi27();
    }
    return 0;
}