#include <iostream>
#include <cstring>
using namespace std;

int i = 1, j = 0, no = 0, tmpch = 90;
char str[100], left[15], right[15];

void findopr();
void explore();
void fleft(int);
void fright(int);

struct exp
{
    int pos;
    char op;
} k[15];

int main()
{
    cout << "\t\tINTERMEDIATE CODE GENERATION\n\n";
    cout << "Enter the Expression: ";
    cin >> str;
    cout << "The intermediate code:\n";

    findopr();
    explore();

    return 0;
}

void findopr()
{
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ':')
        {
            k[j].pos = i;
            k[j++].op = ':';
        }
    }
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '/')
        {
            k[j].pos = i;
            k[j++].op = '/';
        }
    }
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '*')
        {
            k[j].pos = i;
            k[j++].op = '*';
        }
    }
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '+')
        {
            k[j].pos = i;
            k[j++].op = '+';
        }
    }
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '-')
        {
            k[j].pos = i;
            k[j++].op = '-';
        }
    }
}

void explore()
{
    i = 1;
    while (k[i].op != '\0')
    {
        fleft(k[i].pos);
        fright(k[i].pos);
        str[k[i].pos] = tmpch--;
        cout << "\t" << str[k[i].pos] << " := " << left << k[i].op << right << "\t\t" << endl;
        i++;
    }

    fright(-1);
    if (no == 0)
    {
        fleft(strlen(str));
        cout << "\t" << right << " := " << left;
        return;
    }

    cout << "\t" << right << " := " << str[k[--i].pos];
}

void fleft(int x)
{
    int w = 0, flag = 0;
    x--;
    while (x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '=' && str[x] != '\0' && str[x] != '-' && str[x] != '/' && str[x] != ':')
    {
        if (str[x] != '$' && flag == 0)
        {
            left[w++] = str[x];
            left[w] = '\0';
            str[x] = '$';
            flag = 1;
        }
        x--;
    }
}

void fright(int x)
{
    int w = 0, flag = 0;
    x++;
    while (x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '\0' && str[x] != '=' && str[x] != ':' && str[x] != '-' && str[x] != '/')
    {
        if (str[x] != '$' && flag == 0)
        {
            right[w++] = str[x];
            right[w] = '\0';
            str[x] = '$';
            flag = 1;
        }
        x++;
    }
}