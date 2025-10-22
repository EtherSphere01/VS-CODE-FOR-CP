#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
}

void quick_sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partition_index = partition(arr, low, high);
        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quick_sort(arr, 0, n - 1);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}