#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    n = 6;
    vector<long long> v;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    long long sum = 0;
    sum = sum + (v[0] * v[2] * v[4]);
    sum = sum + (v[0] * v[2] * v[5]) + (v[0] * v[3] * v[4]) + (v[0] * v[3] * v[5]) + (v[1] * v[2] * v[4]) + (v[1] * v[2] * v[5]) + (v[1] * v[3] * v[4]) + (v[1] * v[3] * v[5]);
    cout << sum << endl;
}