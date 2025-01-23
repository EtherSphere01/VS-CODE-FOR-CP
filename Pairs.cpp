#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string, int> a, pair<string, int> b)
{
    if (a.first < b.first)
    {
        return true;
    }
    else if (a.first == b.first)
    {
        if (a.second > b.second)
        {
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<string, int>> v;
    while (n--)
    {
        string s;
        int x;
        cin >> s >> x;
        v.push_back(make_pair(s, x));
    }

    sort(v.begin(), v.end(), comp);

    for (auto i : v)
    {
        cout << i.first << " " << i.second << endl;
    }
}