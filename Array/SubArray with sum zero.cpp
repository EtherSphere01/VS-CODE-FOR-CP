#include<bits/stdc++.h>

using namespace std;
#define ll long long

bool zerosubarraysum(vector<ll> a){
    unordered_set<ll> s;
    ll presum = 0;
    for(ll i = 0; i < a.size(); i++){
        presum += a[i];
        if(presum == 0){
            return true;
        }
        if(s.find(presum) != s.end()){
            return true;
        }
        s.insert(presum);
    }
    return false;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    bool ans = zerosubarraysum(a);

    if(ans){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}