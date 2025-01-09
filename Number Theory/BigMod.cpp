#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18

typedef long long ll;
typedef unsigned long long ull;

ll bigmod(ll a, ll b)
{
    if (b == 0)
        return 1LL;
    ll x = bigmod(a, b / 2);
    x = (x * x) % MOD;
    if (b % 2 == 1)
        x = (x * a) % MOD;
    return x;
}

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if ((b & 1) == 1)
            ans *= a;
        a *= a;
        b = b >> 1;
    }
    return ans;
}

ll modadd(ll a, ll b)
{
    return (a % MOD + b % MOD) % MOD;
}

ll modsub(ll a, ll b)
{
    return (a % MOD - b % MOD + MOD) % MOD;
}

ll modmul(ll a, ll b)
{
    return (a % MOD * b % MOD) % MOD;
}

ll modinv(ll a)
{
    return bigmod(a, MOD - 2);
}

ll moddiv(ll a, ll b)
{
    return modmul(a, modinv(b));
}

int main()
{
    ll a, b, m;
    cin >> a >> b;
    cout << modmul(a, b) << endl;
    return 0;
}