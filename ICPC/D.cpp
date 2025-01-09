#include <iostream>
using namespace std;

const int MOD = 998244353;

// Function to perform modular exponentiation: (base^exp) % mod
long long mod_exp(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main()
{
    int N;
    cin >> N;

    long long red_sum = 0, green_sum = 0;

    // Read the weights of red apples
    long long red[N];
    for (int i = 0; i < N; i++)
    {
        cin >> red[i];
        red_sum += red[i];
    }

    // Read the weights of green apples
    long long green[N];
    for (int i = 0; i < N; i++)
    {
        cin >> green[i];
        green_sum += green[i];
    }

    // Calculate the total expected weight sum
    long long total_weight_sum = (red_sum + green_sum) / 2;

    // Calculate Q and its modular inverse
    long long Q = N;
    long long Q_inv = mod_exp(Q, MOD - 2, MOD);

    // For each K from 1 to N, compute the result
    for (int K = 1; K <= N; K++)
    {
        long long P = K * total_weight_sum % MOD;
        long long result = (P * Q_inv) % MOD;
        cout << result << endl;
    }

    return 0;
}
