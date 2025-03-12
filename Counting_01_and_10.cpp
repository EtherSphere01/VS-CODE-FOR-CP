#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100000;
const long long MOD = 1e18; // Given constraint

vector<long long> dp(MAX_N + 1, 0);

void precompute()
{
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 4;

    for (int n = 4; n <= MAX_N; n++)
    {
        dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3];
        if (dp[n] > MOD)
            dp[n] = MOD; // To prevent overflow
    }
}

int main()
{
    precompute();

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        cout << dp[N] << endl;
    }

    return 0;
}
