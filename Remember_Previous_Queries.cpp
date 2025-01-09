#include <bits/stdc++.h>
using namespace std;

void print_reverse(const list<int> node)
{
    cout << "R -> ";
    for (auto i = node.rbegin(); i != node.rend(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

void print(const list<int> node)
{
    cout << "L -> ";
    for (auto i : node)
    {
        cout << i << " ";
    }
    cout << endl;
    print_reverse(node);
}

int main()
{
    list<int> node;
    int count = 0;

    int n;
    cin >> n;
    while (n--)
    {
        int indx, value;
        cin >> indx >> value;

        if (indx == 0)
        {
            node.push_front(value);
            count++;
            print(node);
        }
        else if (indx == 1)
        {
            node.push_back(value);
            count++;
            print(node);
        }
        else if (indx == 2)
        {
            if (value >= count)
            {
                print(node);
                continue;
            }
            node.erase(next(node.begin(), value));
            count--;
            print(node);
        }
    }

    return 0;
}