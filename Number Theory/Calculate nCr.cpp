#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

ll binpow(ll a,ll b) {
    ll ans = 1;
    while(b > 0) {
        if((b & 1) == 1) ans *= a;
        a *= a;
        b = b >> 1;
    }
    return ans;
}
 
ll binpowMOD(ll a,ll b) {
    ll ans = 1;
    while(b > 0) {
        if((b & 1) == 1) {
        	ans *= a;
        	ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b = b >> 1;
    }
    return ans;
}
 

const ll MAX = 2e5 + 7;
vector<ll> fact(MAX);
 
ll add(ll a, ll b) {
	return (a + b) % MOD;
}
 
ll sub(ll a, ll b) {
	return ((a - b) % MOD + MOD) % MOD;
}
 
ll mult(ll a, ll b) {
	return ((a * b) % MOD);
}
 
ll inv(ll a) {
	return binpowMOD(a, MOD - 2);
}
 
ll divide(ll a, ll b) {
	return mult(a, inv(b));
}
 
ll nCr(ll n, ll r) {
    //call the preFactorial() function before calling this function
	if(n < r) return 0;
	return divide(fact[n], mult(fact[r], fact[n - r]));
}
 
void preFactorial() {
	fact[0] = 1;
	for(ll i = 1; i < MAX; i++) fact[i] = mult(i, fact[i - 1]);
}

int main(){
    preFactorial();
    cout << nCr(5, 3) << endl;
}