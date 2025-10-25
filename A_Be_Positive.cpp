#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        bool check = false;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                check = true;
            }
        }
        if (!check)
            break;
    }
}

void recursion_bubble_sort(vector<int> &arr, int n)
{
    if (n <= 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    recursion_bubble_sort(arr, n - 1);
}

void selection_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int mini_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini_index])
            {
                mini_index = j;
            }
        }
        swap(arr[i], arr[mini_index]);
    }
}

void recursion_selection_sort(vector<int> &arr, int start, int n)
{
    if (start == n - 1)
    {
        return;
    }

    int mini_index = start;
    for (int i = start + 1; i < n; i++)
    {
        if (arr[i] < arr[mini_index])
        {
            mini_index = i;
        }
    }
    swap(arr[start], arr[mini_index]);
    recursion_selection_sort(arr, start + 1, n);
}

void insertion_sort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

void recursion_insertion_sort(vector<int> &arr, int n)
{
    if (n <= 1)
    {
        return;
    }

    recursion_insertion_sort(arr, n - 1);
    int value = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > value)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = value;
}

void merge_array(vector<int> &arr, int mid, int left, int right)
{

    vector<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= right)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i - left];
    }
}

void merge(vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = (left + right) / 2;
    merge(arr, 0, mid);
    merge(arr, mid + 1, right);
    merge_array(arr, mid, left, right);
}

int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[left];
    int i = left;
    int j = right;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= right)
        {
            i++;
        }
        while (arr[j] > pivot && j >= left)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[left]);
    return j;
}

void quick_sort(vector<int> &arr, int left, int right)
{

    if (left < right)
    {

        int partition_index = partition(arr, left, right);
        quick_sort(arr, left, partition_index - 1);
        quick_sort(arr, partition_index + 1, right);
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

    // recursion_bubble_sort(arr, n);
    // selection_sort(arr);
    // recursion_selection_sort(arr, 0, n);
    // insertion_sort(arr);
    // recursion_insertion_sort(arr, n);
    // merge(arr, 0, n - 1);
    quick_sort(arr, 0, n - 1);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}