#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sp " "

void solve()
{
    int n, sum;
    cin >> n >> sum;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i != j and j != k and i != k)
                {
                    if (arr[i] + arr[j] + arr[k] == sum)
                    {
                        cout << "YES" << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}