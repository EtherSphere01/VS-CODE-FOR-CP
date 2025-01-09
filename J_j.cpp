#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793238462;
bool isIntersecting(pair<double, double> el1, pair<double, double> el2)
{
    double lo = max(el1.first, el2.first);
    double hi = min(el1.second, el2.second);
    if (lo <= hi)
        return true;
    return false;
}
int main()
{

    int a, n;
    cin >> a >> n;
    vector<pair<double, double>> v;
    for (int i = 0; i < n; i++)
    {
        int x, h;
        cin >> x >> h;
        double sinTheta = sin(a * PI / 180.0);
        double value = h / sinTheta;
        double vumi = sin((90 - a) * PI / 180.0) * value;
        v.push_back({x, x + vumi});
        // cout<<x<<" "<<x+vumi<<endl;
    }
    sort(v.begin(), v.end());

    // for(auto it:v){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    // v.push_back({75, 400});

    int si = v.size();
    bool val = 0;

    pair<double, double> temp = v[0];
    double ans = 0;
    int check = 0;
    for (int i = 0; i < si; i++)
    {
        check = 0;
        val = isIntersecting(v[i], temp);

        if (val)
        {
            temp.second = max(temp.second, v[i].second);
        }
        else
        {
            ans += (temp.second - temp.first);
            temp = v[i];
            check = 1;
        }
    }

    ans += (temp.second - temp.first);

    cout << fixed << setprecision(14) << ans << endl;
}
