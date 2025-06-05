#include <iostream>
#include <vector>
#include <numeric>   // For std::gcd (C++17) or potentially __gcd (GNU extension)
#include <algorithm> // For std::swap (used in custom GCD)
#include <cmath>     // For std::abs (used in custom GCD, though not strictly needed if inputs positive)

// Custom GCD implementation
long long calculate_gcd(long long a, long long b)
{
    // Euclidean algorithm requires non-negative inputs for its standard form.
    // Since differences a_max - a_i (where a_i < a_max) are positive,
    // inputs 'a' and 'b' to this function during GCD calculation will be positive.
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

    // Problem constraints ensure 'diffs' will not be empty.
    // "It is guaranteed that there exists at least one such pair of indices (j, k) that a_j != a_k."
    // This means at least one a_i is less than a_max.

    long long z_val = diffs[0]; // Initialize z with the first difference
    for (size_t i = 1; i < diffs.size(); ++i)
    {
        // Using custom GCD. On C++17 compilers, std::gcd(z_val, diffs[i]) can be used.
        // On g++, __gcd(z_val, diffs[i]) is often available.
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