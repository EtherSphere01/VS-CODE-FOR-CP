#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n - 1; i >= 1; i--)
    {
        int is_swapped = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                is_swapped = 1;
            }
        }
        if (is_swapped == 0)
        {
            break;
        }
    }
}

void recursion_bubble_sort(vector<int> &arr, int size)
{
    if (size <= 0)
    {
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    recursion_bubble_sort(arr, size - 1);
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

    recursion_bubble_sort(arr, n);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}