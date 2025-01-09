#include <bits/stdc++.h>
using namespace std;

void valid_operators(string s)
{
    int n = s.length();

    string before_eq = "";
    string after_eq = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '=')
        {
            before_eq = s.substr(0, i);
            after_eq = s.substr(i + 1, n);
            break;
        }
    }

    int opcount = 0;
    if (before_eq.size() > 1)
    {
        cout << "invalid" << endl;
        return;
    }
    else
    {
        for (int i = 1; i < after_eq.size(); i += 2)
        {
            if (after_eq[i] == '+' || after_eq[i] == '-' || after_eq[i] == '*' || after_eq[i] == '/')
            {
                opcount++;
            }
            else
            {
                cout << "invalid" << endl;
                return;
            }
        }
    }

    if (opcount > 2)
    {
        cout << "invalid" << endl;
    }
    else
    {
        cout << "valid" << endl;
    }
}

void valid_expression(string s)
{
    int n = s.length();
    int opcount = 0;
    if (n != 3)
    {
        cout << "invalid" << endl;
        return;
    }

    if (s[0] == '+' || s[0] == '-')
    {
        if (s[0] == '+')
        {
            if (s[1] == '+' && s[2] != '+' && s[2] != '-')
            {
                cout << "valid" << endl;
                return;
            }
            else
            {
                cout << "invalid" << endl;
                return;
            }
        }
        else if (s[0] == '-')
        {
            if (s[1] == '-' && s[2] != '+' && s[2] != '-')
            {
                cout << "valid" << endl;
                return;
            }
            else
            {
                cout << "invalid" << endl;
                return;
            }
        }
    }
    else
    {
        if (s[1] == '+')
        {
            if (s[2] == '+')
            {
                cout << "valid" << endl;
                return;
            }
            else
            {
                cout << "invalid" << endl;
                return;
            }
        }
        else if (s[1] == '-')
        {
            if (s[2] == '-')
            {
                cout << "valid" << endl;
                return;
            }
            else
            {
                cout << "invalid" << endl;
                return;
            }
        }
    }
}

int main()
{
    string s;
    getline(cin, s);
    valid_operators(s);

    string ss;
    getline(cin, ss);

    valid_expression(ss);
}