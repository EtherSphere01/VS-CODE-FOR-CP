#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;

        if (t == 0)
        {
            int x;
            cin >> x;
            pq.push(x);
            cout << pq.top() << endl;
        }
        else if (t == 1)
        {
            if (pq.empty())
            {
                cout << "Empty" << endl;
                continue;
            }
            cout << pq.top() << endl;
        }
        else
        {
            if (!pq.empty())
            {
                pq.pop();
            }

            if (pq.empty())
            {
                cout << "Empty" << endl;
                continue;
            }
            cout << pq.top() << endl;
        }
    }
}