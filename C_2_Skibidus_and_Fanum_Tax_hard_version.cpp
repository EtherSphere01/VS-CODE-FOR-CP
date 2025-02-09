#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];

    // If already sorted, return "YES"
    if (is_sorted(a.begin(), a.end()))
    {
        cout << "YES\n";
        return;
    }

    // Sort b for efficient selection
    sort(b.begin(), b.end());

    // Previous selected value
    int prev = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int original = a[i];

        // Find best b[j] using binary search
        auto it = lower_bound(b.begin(), b.end(), a[i]); // First b[j] >= a[i]
        int transformed = (it != b.end()) ? (*it - a[i]) : INT_MAX;

        // Ensure non-decreasing order
        if (transformed >= prev)
        {
            prev = transformed;
        }
        else if (original >= prev)
        {
            prev = original;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
