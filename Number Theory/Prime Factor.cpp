#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> primeFactor(ll n) {
    vector<ll>ans;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                ans.push_back(i);
                n /= i;
            }
        }
    }
    if(n > 1) {
        ans.push_back(n);
    }
    return ans;
}

int main() {
    int n = 20;
    vector<ll> factors = primeFactor(n);

    cout << "Prime Factors of " << n << ":" << endl;
    for (ll factor : factors) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}

/*
Complexity Analysis
Time Complexity: O(sqrt(N)(logN)) where N is the input number.
Space Complexity : O(1).
*/
                                
                            