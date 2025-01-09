#include <bits/stdc++.h>

using namespace std;

#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);              \
    cout.precision(numeric_limits<double>::max_digits10);

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> a[i];
    }

    set<int> pos1;
    for (int i = 1; i < n + 1; i++)
    {
        if (a[i] == 1)
            pos1.insert(i);
    }

    int l = 1, r = n;
    vector<pair<int, int>> ans;
    while (l < r)
    {
        if (a[l] == 0)
        {
            l++;
            continue;
        }
        while (r > l && a[r] != 0)
            r--;
        if (r <= l)
            break;

        if (a[l] == 1)
        {
            swap(a[l], a[r]);
            ans.push_back({l, r});
            pos1.erase(l);
            pos1.insert(r);
        }
        else
        {
            int j = *pos1.rbegin();
            swap(a[l], a[j]);
            swap(a[l], a[r]);
            ans.push_back({l, j});
            ans.push_back({l, r});
            pos1.erase(j);
            pos1.insert(r);
        }
        l++;
    }

    r = n;
    while (l < r)
    {
        if (a[l] == 1)
        {
            l++;
            continue;
        }
        while (r > l && a[r] == 2)
        {
            r--;
        }
        if (r <= l)
            break;
        swap(a[l], a[r]);
        ans.push_back({l, r});
        l++;
    }

    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i.first << ' ' << i.second << '\n';
}

int32_t main()
{
    fastIO;

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}