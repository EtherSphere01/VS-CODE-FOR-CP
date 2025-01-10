#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        queue<char> q;
        for (char ch : s)
        {
            q.push(ch);
        }

        int zero = 0;
        bool f = true;

        while (!q.empty())
        {
            if (q.front() == '1')
            {
                if (zero == 0)
                {
                    f = false;
                    break;
                }
                else
                {
                    zero--;
                }
            }
            else
            {
                zero++;
            }
            q.pop();
        }

        if (zero == 0 && f == true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}