#include <bits/stdc++.h>

using namespace std;

void selection_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void recursion_selection_sort(vector<int> &arr, int start, int size)
{
    if (start >= size - 1)
    {
        return;
    }

    int min_index = start;
    for (int i = start; i < size; i++)
    {
        if (arr[i] < arr[min_index])
        {
            min_index = i;
        }
    }
    int temp = arr[start];
    arr[start] = arr[min_index];
    arr[min_index] = temp;
    recursion_selection_sort(arr, start + 1, size);
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

    recursion_selection_sort(arr, 0, n);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}