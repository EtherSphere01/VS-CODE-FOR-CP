#include <bits/stdc++.h>
using namespace std;
#define ll long long;
#define sp " ";

int main()
{
    char s[1000000];
    while (cin.getline(s, 1000000))
    {
        int size = strlen(s);
        sort(s, s + size);
        for (int i = 0; i < size; i++)
        {
            if (s[i] == ' ')
                continue;
            cout << s[i];
        }
        cout << endl;
    }
}