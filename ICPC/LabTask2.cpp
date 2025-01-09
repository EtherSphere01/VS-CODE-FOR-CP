#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

bool check_identifier(string s)
{

    bool f = true;
    if (s[0] >= 'a' && s[0] <= 'z' || s[0] >= 'A' && s[0] <= 'Z' || s[0] == '_')
    {
        int sz = s.size();
        for (int i = 1; i < sz; i++)
        {
            if (s[i] == ' ')
            {
                f = false;
                break;
            }
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] == '_' || s[i] >= '0' && s[i] <= '9')
                continue;
            else
            {
                f = false;
                break;
            }
        }
    }
    else
    {
        f = false;
    }
    if (f)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool keywords(string s)
{
    vector<string> keyword = {
        "int", "float", "double", "char", "void",
        "if", "else", "for", "while", "do",
        "switch", "case", "break", "continue",
        "return", "struct", "class", "public",
        "private", "protected", "virtual", "static", "long long",
        "cout", "cin", "return", "string", "bool", "true", "false", "static", "public"};

    for (int i = 0; i < keyword.size(); i++)
    {
        if (s == keyword[i])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    string s;
    cin >> s;

    bool check_id = check_identifier(s);
    if (check_id)
    {
        bool check_key = keywords(s);
        if (check_key)
        {
            cout << "Invalid Variable Name" << endl;
        }
        else
        {
            cout << "Valid Variable Name" << endl;
        }
    }
    else
    {
        cout << "Invalid Variable Name" << endl;
    }
}
