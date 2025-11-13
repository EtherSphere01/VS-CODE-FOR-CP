// This will now compile correctly with your g++-15 build task.
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v = {4, 2, 5, 1, 3};
    sort(v.begin(), v.end());

    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}