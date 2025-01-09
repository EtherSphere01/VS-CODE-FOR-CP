#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

#define N 2
void multiply(ll a[N][N], ll b[N][N])
{
    ll mul[N][N];
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            mul[i][j] = 0;
            for (ll k = 0; k < N; k++)
            {
                mul[i][j] += (a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            a[i][j] = mul[i][j] % MOD;
        }
    }
}

void power(ll F[N][N], ll n)
{
    if (n == 0 || n == 1)
        return;
    ll M[N][N] = {{1, 1}, {1, 0}};
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0)
        multiply(F, M);
}

ll fib(ll n)
{
    ll F[N][N] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
}

int main()
{
    ll n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}

// Time Complexity: O(log(n))
// Space Complexity: O(1)