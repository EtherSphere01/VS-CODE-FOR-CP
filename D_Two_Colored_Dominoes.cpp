

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s[n];
        for (int i = 0; i < n; i++)
            cin >> s[i];
        string ans[n];
        bool f = true;
        for (int i = 0; i < n; i++)
        {
            ans[i].resize(m);
            for (int j = 0; j < m; j++)
                ans[i][j] = '.';
        }
        for (int i = 0; i < n - 1; i++)
        {
            int cnt = 0, cnt2 = 0;
            for (int j = 0; j < m; j++)
            {
                if (s[i][j] == 'U')
                {
                    cnt ^= 1;
                    if (cnt)
                        ans[i][j] = 'W', ans[i + 1][j] = 'B';
                    else
                        ans[i][j] = 'B', ans[i + 1][j] = 'W';
                }
            }
            if (cnt)
            {
                f = false;
                break;
            }
        }
        for (int j = 0; j < m - 1; j++)
        {
            int cnt = 0, cnt2 = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i][j] == 'L')
                {
                    cnt2 ^= 1;
                    if (cnt2)
                        ans[i][j] = 'W', ans[i][j + 1] = 'B';
                    else
                        ans[i][j] = 'B', ans[i][j + 1] = 'W';
                }
            }
            if (cnt2)
            {
                f = false;
                break;
            }
        }
        if (!f)
        {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << '\n';
        }
    }
}