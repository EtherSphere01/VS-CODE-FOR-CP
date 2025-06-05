#include <iostream>
#include <vector>
#include <numeric>   
#include <algorithm> 
#include <cmath> 
long long calculate_gcd(long long a, long long b)
{
    while (b)
    {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    long long a_max = -1;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        if (a_max == -1 || a[i] > a_max)
        {
            a_max = a[i];
        }
    }

    std::vector<long long> diffs;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < a_max)
        {
            diffs.push_back(a_max - a[i]);
        }
    }

    long long z_val = diffs[0];
    for (size_t i = 1; i < diffs.size(); ++i)
    {
        z_val = calculate_gcd(z_val, diffs[i]);
    }

    long long y_val = 0;
    for (long long d : diffs)
    {
        y_val += d / z_val;
    }

    std::cout << y_val << " " << z_val << std::endl;

    return 0;
}