#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int rem = 9261 - n;
    while (rem != 0)
    {
        v.push_back(1);
        rem--;
    }
    cout << v.size() + 1 << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << -1 * v[i] << " ";
    }
    cout << 21 << endl;
}