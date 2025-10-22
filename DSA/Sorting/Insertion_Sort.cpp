#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}

void recursion_insertion_sort(vector<int> &arr, int size)
{
    if (size <= 1)
    {
        return;
    }

    recursion_insertion_sort(arr, size - 1);

    int value = arr[size - 1];
    int j = size - 2;

    while (j >= 0 && arr[j] > value)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = value;
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
    recursion_insertion_sort(arr, n);

    for (auto i : arr)
    {
        cout << i << " ";
    }
}