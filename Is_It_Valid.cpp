#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        queue<char> q;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            q.push(s[i]);
        }

        int one = 0, zero = 0;

        while (!q.empty())
        {
            if (q.front() == '1')
            {
                if (zero == 0)
                {
                    one++;
                }
                else
                {
                    zero--;
                }
            }
            else
            {
                if (one == 0)
                {
                    zero++;
                }
                else
                {
                    one--;
                }
            }
            q.pop();
        }

        if (one == 0 and zero == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}