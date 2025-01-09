#include<bits/stdc++.h>

using namespace std;
#define ll long long

vector<ll> divisors(ll n){
    vector<ll> divs;
    for(ll i = 1; i*i <= n; i++){
        if(n % i == 0){
            divs.push_back(i);
            if(i != n/i){
                divs.push_back(n/i);
            }
        }
    }
    return divs;
}

int main(){
    ll n = 36;
    vector<ll> divs = divisors(n);
    for(ll i = 0; i < divs.size(); i++){
        cout << divs[i] << " ";
    }
}

//Time complexity: O(sqrt(n))
//Auxiliary Space: O(sqrt(n)) -> depends on the number of divisors

