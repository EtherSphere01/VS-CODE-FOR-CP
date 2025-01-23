#include <bits/stdc++.h>
using namespace std;

void solve(string sen)
{
    map<string, int> mp;
    stringstream ss(sen);
    string word;

    pair<string, int> p;
    p = {"", 0};
    while (ss >> word)
    {
        mp[word]++;
        if (mp[word] > p.second)
        {
            p = {word, mp[word]};
        }
    }

    cout << p.first << " " << p.second << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string sen;
        getline(cin, sen);
        solve(sen);
    }
    return 0;
}