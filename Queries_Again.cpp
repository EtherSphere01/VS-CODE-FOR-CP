#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_reverse(Node *tail)
{
    cout << "R -> ";
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void print(Node *head, Node *tail)
{
    cout << "L -> ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
    print_reverse(tail);
}

void insert_at_head(Node *&head, int value, Node *&tail)
{
    Node *newnode = new Node(value);
    newnode->next = head;
    if (head != NULL)
    {
        head->prev = newnode;
    }
    head = newnode;
    if (tail == NULL)
    {
        tail = head;
    }

    print(head, tail);
}

void insert_at_tail(Node *&head, int value, Node *&tail)
{
    if (head == NULL)
    {
        insert_at_head(head, value, tail);
        return;
    }
    Node *newnode = new Node(value);
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;

    print(head, tail);
}

void insert_at_middle(Node *&head, int value, Node *&tail, int indx)
{
    Node *temp = head;
    while (indx-- && temp != NULL)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        insert_at_tail(head, value, tail);
        return;
    }
    Node *newnode = new Node(value);
    newnode->next = temp;
    newnode->prev = temp->prev;
    if (temp->prev != NULL)
    {
        temp->prev->next = newnode;
    }
    else
    {
        head = newnode;
    }
    temp->prev = newnode;

    print(head, tail);
}

int main()
{
    int count = 0;

    Node *head = NULL;
    Node *tail = NULL;
    int n;
    cin >> n;
    while (n--)
    {
        int indx, value;
        cin >> indx >> value;

        if (indx == 0)
        {
            insert_at_head(head, value, tail);
            count++;
        }
        else
        {
            if (count == 0)
            {
                cout << "Invalid" << endl;
            }
            else if (count == indx)
            {
                insert_at_tail(head, value, tail);
                count++;
            }
            else if (count < indx)
            {
                cout << "Invalid" << endl;
            }
            else
            {
                insert_at_middle(head, value, tail, indx);
                count++;
            }
        }
    }
}