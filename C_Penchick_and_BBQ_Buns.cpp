#include <bits/stdc++.h>
using namespace std;

vector<int> precal = {1, 2, 2, 3, 3, 4, 4, 5, 5, 1, 6, 6, 7, 7, 12, 12, 11, 11, 10, 10, 9, 9, 13, 8, 8, 1, 13};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int tt;
    cin >> tt;

    while (tt--)
    {
        int n;
        cin >> n;
        if (n % 2 == 0)
        {
            for (int i = 1, j = 1; i <= n; i += 2, j++)
            {
                cout << j << " " << j << " ";
            }
            cout << "\n";
        }
        else if (n < 27)
        {
            cout << -1 << "\n";
        }
        else
        {
            vector<int> finalAnswer = precal;
            int left = n - 27;
            for (int i = 1, j = 14; i <= left; i += 2, j++)
            {
                finalAnswer.push_back(j);
                finalAnswer.push_back(j);
            }
            for (auto &i : finalAnswer)
                cout << i << " ";
            cout << "\n";
        }
    }
}