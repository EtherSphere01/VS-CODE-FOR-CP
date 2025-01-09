#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> stations(N);
    vector<bool> seen(N + 1, false); // To mark which stations have been seen (1 to N)

    // Reading the station numbers and marking seen stations
    for (int i = 0; i < N; i++)
    {
        cin >> stations[i];
        if (stations[i] != 0)
        {
            seen[stations[i]] = true;
        }
    }

    // Filling in the missing station numbers
    int current = 1;
    for (int i = 0; i < N; i++)
    {
        if (stations[i] == 0)
        {
            // Find the next available station number
            while (seen[current])
            {
                current++;
            }
            stations[i] = current;
            seen[current] = true;
        }
    }

    // Now that we have all the stations, we need to find the peak
    // Peak will be the largest number in the ascent, so we find the position where the ascent ends
    int peak = -1;
    for (int i = 0; i < N - 1; i++)
    {
        if (stations[i] < stations[i + 1])
        {
            peak = i;
        }
    }

    // Output the correct itinerary
    for (int i = 0; i <= peak; i++)
    {
        cout << stations[i] << " ";
    }
    for (int i = peak + 1; i < N; i++)
    {
        cout << stations[i] << " ";
    }
    cout << endl;

    return 0;
}
