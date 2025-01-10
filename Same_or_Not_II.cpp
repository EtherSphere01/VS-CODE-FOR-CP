#include <bits/stdc++.h>
using namespace std;

class mystack
{
    vector<int> v;

public:
    void push(int x)
    {
        v.push_back(x);
    }
    void pop()
    {
        v.pop_back();
    }
    int top()
    {
        return v.back();
    }
    bool empty()
    {
        return v.empty();
    }
    int size()
    {
        return v.size();
    }
};

class myqueue
{
public:
    int sz = 0;
    class Node
    {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    Node *head = NULL;
    Node *tail = NULL;

    void push(int x)
    {
        Node *n = new Node(x);
        sz++;
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void pop()
    {
        if (head == NULL)
        {
            return;
        }
        if (head == tail)
        {
            Node *del = head;
            head = NULL;
            tail = NULL;
            delete del;
        }
        else
        {
            Node *del = head;
            head = head->next;
            head->prev = NULL;
            delete del;
        }
        sz--;
    }

    int front()
    {
        return head->data;
    }

    bool empty()
    {
        return head == NULL;
    }

    int size()
    {
        return sz;
    }
};

int main()
{

    int n, m;
    cin >> n >> m;

    mystack s;
    myqueue q;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    if (n != m)
    {
        cout << "NO" << endl;
        return 0;
    }

    bool f = true;

    while (!s.empty() and !q.empty())
    {
        if (s.top() != q.front())
        {
            f = false;
            break;
        }
        s.pop();
        q.pop();
    }

    if (f)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}