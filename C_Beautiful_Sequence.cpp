#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Step 1: Compute suffix count of 3s (number of 3s to the right of each index)
    vector<int> suffix3(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        suffix3[i] = suffix3[i + 1] + (a[i] == 3);
    }

    // Step 2: Count valid (1,2,3) sequences
    int count1 = 0, result = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            count1++; // Count `1`s as potential starts
        }
        else if (a[i] == 2)
        {
            result = (result + count1 * suffix3[i + 1]) % MOD;
            // Valid pairs are (count1 * number of 3s to the right)
        }
    }

    cout << result << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
