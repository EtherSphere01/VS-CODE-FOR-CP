#include<bits/stdc++.h>

using namespace std;
#define ll long long

bool findSubString(string s, string check){
    size_t found = s.find(check);
    if (found != string::npos){
        return true;
    }
    return false;
}

int main(){
    string s = "Hello World";
    string check = "Worl";
    cout << findSubString(s, check);
}

// Complexity analysis:
// Time Complexity: O(N*M), where N is the size of the string(str) and M is the size of the substring to be searched.
// Auxiliary Space: O(1) 