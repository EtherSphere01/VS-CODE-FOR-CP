#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getChanges(const vector<vector<int>> &mat, int base)
{
    int n = mat.size();
    int m = mat[0].size();
    int changes = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int expected = base + i + j;
            if (mat[i][j] != expected)
            {
                changes++;
            }
        }
    }
    return changes;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> mat[i][j];

        // Try all values from mat[0][0] - 1, mat[0][0], mat[0][0] + 1
        // to account for minor misalignment
        int ans = n * m;
        for (int delta = -1; delta <= 1; ++delta)
        {
            int base = mat[0][0] + delta;
            ans = min(ans, getChanges(mat, base));
        }

        cout << ans << endl;
    }

    return 0;
}
