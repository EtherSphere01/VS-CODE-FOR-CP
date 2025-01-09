#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string a, b;
        cin >> a >> b;
        string ans = "";
        for (int i = 0; i < a.size(); i++)
        {
            string sub = a.substr(i, b.size());
            if (sub == b)
            {
                ans += '#';
                i += b.size() - 1;
            }
            else
            {
                ans += a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}