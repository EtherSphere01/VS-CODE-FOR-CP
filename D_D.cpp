#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {

        long long n;
        cin >> n;

        vector<long long> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = i; j < n; j++) {
                sum += v[j];
            }
            v.push_back(sum / n);
        }

        long long start = v.size() - n;
        long long end = v.size() - 1;

        long long sum1 = 0;
        for (long long i = start; i <= end; i++) sum1 += v[i];

        vector<long long> vv;
        long long val = 100000;

        long long L = start;
        long long R = end;

        while (val--) {
            vv.push_back(sum1 / n);
            sum1 -= v[L];
            L++;
            R++;
            sum1 += v[R];
        }

        long long q;
        cin >> q;

        while (q--) {
            long long ind;
            cin >> ind;

            if (ind <= (long long)v.size()) {
                cout << v[ind - 1] << "\n";
            } else {
                cout << vv[ind - v.size() - 1] << "\n";
            }
        }
    }
    return 0;
}
