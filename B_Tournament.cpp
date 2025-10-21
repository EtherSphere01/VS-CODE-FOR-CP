#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;

    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void merge_sort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main()
{

    vector<int> v = {5, 3, 6, 2, 5, 6, 21, 1, 5, 6, 1, 2, 3, 3, 44, 2};
    int siz = v.size();

    merge_sort(v, 0, siz - 1);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

// TIME COMPLEXITY: O(N log N)
// SPACE COMPLEXITY: O(N)