#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
    {
        if (a.second < b.second)
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{

    ll n;
    cin >> n;

    vector<pair<ll, ll>> arr(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    ll now = 0, cant = 0;
    // sort(arr.begin(), arr.end(), comp);

    ll time = 1;
    for (ll i = 0; i < n; i++)
    {
        ll arrive = time;
        ll maxwait = arr[i].first;
        ll serve = arr[i].second;

        if (now > arrive + maxwait)
        {
            cant++;
        }
        else
        {
            now = min(now, arrive) + serve;
            time++;
        }
        // time++;
    }

    cout << cant << endl;
}
