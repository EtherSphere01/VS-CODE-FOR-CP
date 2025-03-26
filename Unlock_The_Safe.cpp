#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve()
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N), B(N);
    int total_moves = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
        total_moves += abs(A[i] - B[i]);
    }

    // Check if we can reach exactly K moves
    if (total_moves <= K && (K - total_moves) % 2 == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}
