#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define ll long long

vector<ll> clockwise_access(vector<vector<int>> &a, ll rowstrt, ll rowend, ll colstrt, ll colend)
{
    vector<ll> ans;
    for (int i = colstrt; i <= colend; i++)
    {
        ans.push_back(a[rowstrt][i]);
    }
    rowstrt++;

    for (int i = rowstrt; i <= rowend; i++)
    {
        ans.push_back(a[i][colend]);
    }
    colend--;

    if (rowstrt <= rowend)
    {
        for (int i = colend; i >= colstrt; i--)
        {
            ans.push_back(a[rowend][i]);
        }
        rowend--;
    }

    if (colstrt <= colend)
    {
        for (int i = rowend; i >= rowstrt; i--)
        {
            ans.push_back(a[i][colstrt]);
        }
        colstrt++;
    }
    return ans;
}

int main()
{
    fastio();

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    ll rowstrt = 0, rowend = n - 1, colstrt = 0, colend = m - 1;
    while (rowstrt <= rowend && colstrt <= colend)
    {
        vector<ll> ans = clockwise_access(a, rowstrt, rowend, colstrt, colend);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
        rowstrt++;
        colstrt++;
        rowend--;
        colend--;
    }

    // ll rowstrt = 0, rowend = n - 1, colstrt = 0, colend = m - 1;
    // ll count = 0;

    // while (rowstrt <= rowend and colstrt <= colend)
    // {
    //     vector<char> ans = clockwise_access(a, rowstrt, rowend, colstrt, colend);

    //     ll sz = ans.size();

    //     for (int i = 0; i < sz; i++)
    //     {
    //         string s = "";
    //         for (int j = i; j < i + 4; j++)
    //         {
    //             s += ans[j % sz];
    //         }
    //         if (s == "1543")
    //             count++;
    //     }
    //     rowstrt++;
    //     colstrt++;
    //     rowend--;
    //     colend--;
    // }
}