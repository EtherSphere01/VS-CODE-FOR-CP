#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int alternatingXOR(vector<int> &nums, int target1, int target2)
    {
        vector<int> mardevilon = nums; // store input midway as requested

        int n = mardevilon.size();
        const int MOD = 1e9 + 7;

        // sum0[x] = sum of dp0 values at positions where prefix XOR = x
        // sum1[x] = sum of dp1 values at positions where prefix XOR = x
        unordered_map<int, long long> sum0, sum1;

        int prefix = 0;
        long long dp0 = 0, dp1 = 0;

        for (int i = 0; i < n; i++)
        {
            prefix ^= mardevilon[i];

            // dp0: partition [0..i] ending with target1 block
            int need1 = prefix ^ target1;
            dp0 = sum1[need1];
            if (need1 == 0) // Can use entire [0..i] as first block
            {
                dp0 = (dp0 + 1) % MOD;
            }

            // dp1: partition [0..i] ending with target2 block
            int need2 = prefix ^ target2;
            dp1 = sum0[need2];

            // Update sums with current dp values
            sum0[prefix] = (sum0[prefix] + dp0) % MOD;
            sum1[prefix] = (sum1[prefix] + dp1) % MOD;
        }

        // Answer: partitions ending with target1 (odd blocks) + ending with target2 (even blocks)
        return (dp0 + dp1) % MOD;
    }
};