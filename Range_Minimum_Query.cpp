#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

typedef long long ll;
#define vl vector<ll>
vl arr, tree;

ll merge(ll left, ll right)
{
    return min(left, right);
}

void build(ll node, ll left, ll right)
{
    if (left == right)
    {
        tree[node] = arr[left];
        return;
    }

    ll mid = (left + right) / 2;
    ll left_node = 2 * node;
    ll right_node = 2 * node + 1;

    build(left_node, left, mid);
    build(right_node, mid + 1, right);
    tree[node] = merge(tree[left_node], tree[right_node]);
}

ll query(ll node, ll left, ll right, ll l, ll r)
{
    if (l > right || r < left)
    {
        return INT_MAX;
    }
    if (left >= l && right <= r)
    {
        return tree[node];
    }

    ll mid = (left + right) / 2;
    ll left_node = 2 * node;
    ll right_node = 2 * node + 1;

    ll leftt = query(left_node, left, mid, l, r);
    ll rightt = query(right_node, mid + 1, right, l, r);
    return merge(leftt, rightt);
}

void solve()
{
    ll n;
    cin >> n;
    arr.resize(n + 1);
    tree.resize(4 * n + 1);

    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    build(1, 1, n);
    ll q;
    cin >> q;
    while (q--)
    {
        ll left, right;
        cin >> left >> right;
        left++;
        right++;
        cout << query(1, 1, n, left, right) << endl;
    }
}

int main()
{
    fastio();
    solve();
}
