#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> spf;
vector<ll> createSpf(ll n) {
    vector<ll> spff(n + 1);
    for (ll i = 1; i<=n; i++) {
        spff[i] = i;
    }
    
    for (ll i = 2; i*i <= n; ++i) {
        if (spff[i] == i) {
            for (ll j = i * i; j <= n; j += i) {
                if(spff[j]==j){
                    spff[j] = i;
                }
            }
        }
    }
    
    return spff;
}

vector<ll> primeFactorization(ll n) {
    vector<ll> factors;
    while (n != 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }
    return factors;
}

int main(){
    ll n = 1e5;
    spf = createSpf(n);
   vector<ll>query ={15, 21, 66, 16, 33, 49, 25, 1000, 99991};
    for (ll i = 0; i < query.size(); i++) {
        cout << "Prime factorization of " << query[i] << " is: ";
        vector<ll> factors = primeFactorization(query[i]);
        for (ll j = 0; j < factors.size(); j++) {
            cout << factors[j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Time complexity: O(NloglogN)+O(Query*logN) -> O(NloglogN)
// Auxiliary Space: O(N) -> for storing the smallest prime factor of each number from 1 to N