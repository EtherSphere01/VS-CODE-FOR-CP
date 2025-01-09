#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sp " "

class Student
{
public:
    int id;
    string name;
    char sec;
    int marks;

    // Student(int id, string name, char sec, int marks)
    // {
    //     this->id = id;
    //     this->name = name;
    //     this->sec = sec;
    //     this->marks = marks;
    // }
};

void solve()
{
    Student s[4];
    for (int i = 0; i < 3; i++)
    {
        int id;
        string name;
        char sec;
        int marks;
        cin >> id >> name >> sec >> marks;
        s[id].id = id;
        s[id].name = name;
        s[id].sec = sec;
        s[id].marks = marks;
    }

    int ID, max_marks = 0;
    for (int i = 1; i < 4; i++)
    {
        if (s[i].marks > max_marks)
        {

            max_marks = s[i].marks;
            ID = s[i].id;
        }
        else if (s[i].marks == max_marks)
        {
            if (s[i].id < ID)
            {
                ID = s[i].id;
            }
        }
    }

    cout << s[ID].id << " " << s[ID].name << " " << s[ID].sec << " " << s[ID].marks << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}