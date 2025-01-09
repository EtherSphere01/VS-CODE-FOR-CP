#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    int roll;
    string name;
    int math_marks = 0;
    int eng_marks = 0;
    int total_marks = 0;
    int cls;
    char sec;
};

bool comp(Student a, Student b)
{
    if (a.total_marks == b.total_marks)
    {
        return a.roll < b.roll;
    }
    return a.total_marks > b.total_marks;
}

int main()
{
    int n;
    cin >> n;
    Student s[n];

    for (int i = 0; i < n; i++)
    {
        cin >> s[i].name >> s[i].cls >> s[i].sec >> s[i].roll >> s[i].math_marks >> s[i].eng_marks;
        s[i].total_marks = s[i].math_marks + s[i].eng_marks;
    }

    sort(s, s + n, comp);

    for (int i = 0; i < n; i++)
    {
        cout << s[i].name << " " << s[i].cls << " " << s[i].sec << " " << s[i].roll << " " << s[i].math_marks << " " << s[i].eng_marks << endl;
    }
}