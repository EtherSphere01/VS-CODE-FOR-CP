#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }

        map<int, int> freq;
        int mex = 0;
        for (auto &[x, y] : mp)
        {
            if (x == mex)
            {
                mex++;
                freq[y]++;
            }
        }

        vector<int> a(n + 1, 0);
        a[n] = 1;
        for (int i = n - 1; i > n - mex; i--)
        {
            a[i] = a[i + 1] + 1;
        }

        a[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i])
                break;
            a[i] = a[i - 1] + freq[i];
        }

        for (auto &x : a)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}