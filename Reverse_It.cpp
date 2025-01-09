#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    int roll;
    string name;
    int marks;
    char sec;
};

int main()
{
    int n;
    cin >> n;
    Student s[n];

    for (int i = 0; i < n; i++)
    {
        cin >> s[i].name >> s[i].roll >> s[i].sec >> s[i].marks;
    }

    for (int i = 0; i < n / 2; i++)
    {
        swap(s[i].sec, s[n - i - 1].sec);
    }

    for (int i = 0; i < n; i++)
    {
        cout << s[i].name << " " << s[i].roll << " " << s[i].sec << " " << s[i].marks << endl;
    }
}