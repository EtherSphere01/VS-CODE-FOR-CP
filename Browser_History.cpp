#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string value;
    Node *next;
    Node *prev;

    Node(string value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_head(Node *&head, string value)
{
    Node *newnode = new Node(value);
    newnode->next = head;
    if (head != NULL)
    {
        head->prev = newnode;
    }
    head = newnode;
}

void insert_at_tail(Node *&head, string value, Node *&tail)
{
    if (head == NULL)
    {
        insert_at_head(head, value);
        tail = head;
        return;
    }
    Node *newnode = new Node(value);
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void visit(Node *&head, Node *&tail, string value, Node *&current)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->value == value)
        {
            cout << temp->value << endl;
            current = temp;
            return;
        }
        if (temp->next == NULL)
        {
            cout << "Not Available" << endl;
            return;
        }
        temp = temp->next;
    }
}

void next(Node *&current)
{
    if (current->next == NULL)
    {
        cout << "Not Available" << endl;
        return;
    }
    current = current->next;
    cout << current->value << endl;
}

void prev(Node *&current)
{
    if (current->prev == NULL)
    {
        cout << "Not Available" << endl;
        return;
    }
    current = current->prev;
    cout << current->value << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    while (1)
    {
        string s;
        cin >> s;

        if (s == "end")
            break;

        insert_at_tail(head, s, tail);
    }

    int n;
    cin >> n;

    Node *temp = head;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "visit")
        {
            string value;
            cin >> value;
            visit(head, tail, value, temp);
        }
        else if (s == "next")
        {
            next(temp);
        }
        else if (s == "prev")
        {
            prev(temp);
        }
    }
}