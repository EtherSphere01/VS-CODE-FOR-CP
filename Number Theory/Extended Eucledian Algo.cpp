#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
// Time Complexity: O(log(min(a, b))); Space Complexity: O(log(min(a, b)))

int main()
{
    long long a, b;
    cin >> a >> b;
    long long x, y;
    cout << gcd(a, b, x, y) << endl;
    cout << x << " " << y << endl;
    return 0;
}