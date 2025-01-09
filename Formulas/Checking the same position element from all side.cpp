#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll cehckingFromAllSide(vector<vector<ll>>&arr){
    // One based index array
    // Row = i;
    // Column = j;
    ll count = 0;
    ll n = arr.size()-1;
    for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= n; j++){
            if(arr[i][j]!=arr[n-i+1][n-j+1]){
                count++;
            }
            
        }
    }
    return count / 2; // As we are counting twice from both side;
}

int main(){
    ll n;
    cin>>n;
    vector<vector<ll>>arr(n+1,vector<ll>(n+1,0));
    for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= n; j++){
            cin>>arr[i][j];
        }
    }
    cout<<cehckingFromAllSide(arr)<<endl;


}