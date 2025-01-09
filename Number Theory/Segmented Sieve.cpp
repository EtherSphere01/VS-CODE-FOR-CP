#include<bits/stdc++.h>

using namespace std;
#define ll long long

vector<ll> findAllPrimes(ll n) {
    vector<ll> prime(n + 1, 1);
    
    prime[0] = prime[1] = 0; 
    
    for (ll i = 2; i*i <= n; ++i) {
        if (prime[i] == 1) {
            for (ll j = i * i; j <= n; j += i) {
                prime[j] = 0; 
            }
        }
    }
    
    return prime;
}

vector<ll>getPrimesInRange(ll L, ll R){
    vector<ll>prime = findAllPrimes(sqrt(R));
    vector<ll>isPrime(R-L+1, 1);

    for(ll i = 2; i*i <= R; i++){
        if(!prime[i]) continue;
        for(ll j = max(i*i, (L+i-1)/i*i); j <= R; j += i){
            isPrime[j-L] = 0;
        }
    }
    if(L == 1) isPrime[0] = 0;
    return isPrime;
}

void printPrimesInRange(ll L, ll R){
    // ll L = 30, R = 70;
    vector<ll>primes = getPrimesInRange(L, R);
    for(ll i = 0; i < primes.size(); i++){
        if(primes[i]) cout << i + L << " ";
    }
}

int main(){

    ll L = 30, R = 70;
    printPrimesInRange(L, R);
    cout << endl;

    return 0;
}

//Time Complexity: O(sqrt(R) + (R-L+1)loglog(R))
//Space Complexity: O(sqrt(R)) + O(R-L+1) = O(sqrt(R)) + O(R) = O(R)