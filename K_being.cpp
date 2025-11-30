#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

void solve()
{
    int n;
    // Read the size of the grid
    if (!(cin >> n))
        return;

    // Vectors to store the total number of stones currently in each row and column
    vector<long long> row_counts(n, 0);
    vector<long long> col_counts(n, 0);

    // Read the grid
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int stones;
            cin >> stones;

            // Add stones to current row and column sums
            row_counts[i] += stones;
            col_counts[j] += stones;
        }
    }

    long long moves = 0;

    // Calculate moves needed to balance Rows
    // For every row, if it has more than n stones, the excess must be moved.
    for (int i = 0; i < n; ++i)
    {
        if (row_counts[i] > n)
        {
            moves += (row_counts[i] - n);
        }
    }

    // Calculate moves needed to balance Columns
    // For every column, if it has more than n stones, the excess must be moved.
    for (int i = 0; i < n; ++i)
    {
        if (col_counts[i] > n)
        {
            moves += (col_counts[i] - n);
        }
    }

    cout << moves << endl;
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}