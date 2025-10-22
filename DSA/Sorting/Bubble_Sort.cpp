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

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubble_sort(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}