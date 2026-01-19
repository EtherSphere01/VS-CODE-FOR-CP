#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    if (n < 10)
    {
        long long val = (n - 1) * 10;
        cout << val + 1 << endl;
    }
    else
    {
        long long val = 1;
        string maxi = to_string(n);
        int count = 0;
        while (val < n)
        {
            long long val2 = n - val;
            string s = to_string(val2);
            string ss = to_string(val);
            string sss = s + ss;
            if (sss.size() > maxi.size() || (sss.size() == maxi.size() && sss > maxi))
            {
                maxi = sss;
            }
            val = val * 10;
            count++;
        }

        cout << maxi << endl;
    }
}