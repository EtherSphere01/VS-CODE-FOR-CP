#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // Represent the attendance for each time slot as a bitmask
    vector<int> attendance(n, 0);
    for (int i = 0; i < n; ++i)
    {
        string row;
        cin >> row;
        for (int j = 0; j < m; ++j)
        {
            if (row[j] == 'Y')
            {
                attendance[i] |= (1 << j); // Mark judge j as attending on-site for time slot i
            }
        }
    }

    int maxAttendance = 0;
    int bestFirst = -1, bestSecond = -1;

    // Check all pairs of time slots
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int combinedAttendance = attendance[i] | attendance[j];   // Union of attendance
            int onSiteCount = __builtin_popcount(combinedAttendance); // Count the number of 1s in the bitmask

            // Update the best pair based on the problem's rules
            if (onSiteCount > maxAttendance ||
                (onSiteCount == maxAttendance && (i < bestFirst || (i == bestFirst && j < bestSecond))))
            {
                maxAttendance = onSiteCount;
                bestFirst = i;
                bestSecond = j;
            }
        }
    }

    // Output the result
    if (maxAttendance > 0)
    {
        cout << bestFirst + 1 << " " << bestSecond + 1 << endl; // Convert to 1-based index
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
