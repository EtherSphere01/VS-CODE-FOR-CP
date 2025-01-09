#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll maximumSubArraySum(vector<ll>&arr){
    ll n = arr.size();
    ll maxSum = LONG_MIN, currSum = 0;

    for (ll i = 0; i < n; i++){
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if(currSum < 0) currSum = 0;
    }
    return maxSum;
}

int main(){
    vector<ll>arr = {-200, -30, 40, -20, 50, -30};
    cout << maximumSubArraySum(arr) << endl;
}