// gcd(a,b) -> gcd(b,a%b) where a>b and do this until b=0;

#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    while (a > 0 and b > 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    if (a == 0)
        return b;
    else
        return a;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}

// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(1)
// lcm = (a*b)/gcd(a,b) where a and b are the two numbers.
