#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> arr(n); // Store value and index

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i; // Store index
    }

    // Sort in descending order based on values
    sort(arr.rbegin(), arr.rend());

    vector<bool> painted(n, false);
    vector<int> chosenIndices; // To store chosen indices

    int cost = 0;

    // Select k elements with highest values
    for (int i = 0; i < k; i++)
    {
        int idx = arr[i].second;
        painted[idx] = true;
        chosenIndices.push_back(idx);
        cost += arr[i].first;
    }

    // Sort chosen indices to find the last painted element efficiently
    sort(chosenIndices.begin(), chosenIndices.end());

    // Find the last painted element
    int last_painted = chosenIndices.back(); // Rightmost selected index
    while (last_painted + 1 < n && painted[last_painted + 1] == false)
    {
        last_painted++;
    }

    cost += arr[k - 1].first; // The value of last painted element (from sorted array)

    cout << cost << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
