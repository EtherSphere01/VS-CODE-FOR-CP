#include<bits/stdc++.h>

using namespace std;
#define ll long long

void accessFromAllSide(vector<vector<ll>>&arr){
    // One based index array
    // Row = Layers;
    // Column = i;

   ll n = arr.size()-1;
    ll span = n-2;
    for (ll layer = 1; layer <= n / 2; layer++, span-=2){
        for (ll i = 0; i <= max(1LL*0,span); i++){
            cout << arr[layer][layer+i]<< " ";
            cout << arr[layer+i][n-layer+1]<< " ";
            cout << arr[n-layer+1][n-layer+1-i]<< " ";
            cout << arr[n-layer+1-i][layer]<< " ";
             cout << endl;
        }
    }
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
    accessFromAllSide(arr);
}