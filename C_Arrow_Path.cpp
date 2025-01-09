#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool check(int x, int y, vector<string> &a, vector<vector<bool>> &vis,
           int action)
{
    int n = a[0].size();
    // reached the end then return true
    if (x == 1 && y == n - 1)
        return true;

    // if (x,y) goes out of bound return false
    if (x < 0 || x > 1 || y < 0 || y >= n)
        return false;

    // if landed on the same block which is already landed , then bad and return
    // false
    if (vis[x][y] == true)
        return false;

    // mark the block as marked & go over all the next blocks.
    vis[x][y] = true;

    // iterate over all the direction in step 1. & then move the sign land on in
    // step 2.
    bool ans = false;
    if (action == 0)
    {
        ans = check(x - 1, y, a, vis, 1) || check(x + 1, y, a, vis, 1) ||
              check(x, y - 1, a, vis, 1) || check(x, y + 1, a, vis, 1);
    }
    else
    {
        if (a[x][y] == '>')
            ans = check(x, y + 1, a, vis, 0);
        else
            ans = check(x, y - 1, a, vis, 0);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> a(2);
    for (int i = 0; i < 2; i++)
        cin >> a[i];

    vector<vector<bool>> vis(2, vector<bool>(n, false));

    if (check(0, 0, a, vis, 0))
        cout << "YES"
             << "\n";
    else
        cout << "NO"
             << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout << setprecision(10);
    //        freopen("timber_input.txt", "r", stdin);
    //        freopen("timber_output.txt", "w", stdout);
    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}