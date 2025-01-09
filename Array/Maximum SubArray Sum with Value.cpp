#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll maximumSubArraySumWithValue(vector<ll>&arr){
    ll n = arr.size();
    ll maxSum = LONG_MIN, currSum = 0;
    ll start = -1, end = -1, s=0;

    for (ll i = 0; i < n; i++){
        if(currSum == 0) s = i;
        currSum += arr[i];
        if(currSum > maxSum){
            maxSum = currSum;
            start = s;
            end = i;
        }
        if(currSum < 0) currSum = 0;
    }

    cout << "The subarray is: [";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;

    return maxSum;
}

int main(){
    vector<ll>arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << maximumSubArraySumWithValue(arr) << endl;
}