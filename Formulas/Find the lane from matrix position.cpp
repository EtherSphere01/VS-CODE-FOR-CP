#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll findLane(ll row, ll col, ll x, ll y){
    ll n = max(row, col);
    ll lane = min(min(x,n-x+1), min(y, n-y+1));
    return lane;
}

int main(){
    ll row = 6, col = 6, x = 2, y = 5;
    cout << findLane(row, col, x, y) << endl;
    return 0;
}