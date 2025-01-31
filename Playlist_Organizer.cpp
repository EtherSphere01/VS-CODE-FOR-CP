#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node
{
public:
    string data;
    Node *next;
    Node(string data)
    {
        this->data = data;
        next = NULL;
    }
};

void insert_at_head(Node *&head, string data)
{
    Node *n = new Node(data);
    n->next = head;
    head = n;
}

void insert_at_tail(Node *&head, string data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

void insert_at_middle(Node *&head, string data, ll pos)
{
    if (pos == 0)
    {
        insert_at_head(head, data);
    }
    else
    {
        Node *temp = head;
        for (ll i = 0; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return;
        }
        Node *n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

void delete_at_head(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *todelete = head;
    head = head->next;
    delete todelete;
}

void delete_at_tail(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *todelete = temp->next;
    temp->next = NULL;
    delete todelete;
}

void delete_at_any_position(Node *&head, ll pos)
{
    if (head == NULL)
    {
        return;
    }
    if (pos == 0)
    {
        delete_at_head(head);
    }
    else
    {
        Node *temp = head;
        for (ll i = 0; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL)
        {
            return;
        }
        Node *todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
    }
}

int main()
{
    ll t;
    cin >> t;
    ll count = 0;
    Node *head = NULL;

    while (t--)
    {
        string operation;
        cin >> operation;

        if (operation == "ADD")
        {
            ll index;
            string name;
            cin >> index >> name;

            if (index > count || index < 0)
            {
                cout << "Invalid" << endl;
            }
            else
            {
                insert_at_middle(head, name, index);
                count++;
            }
        }
        else if (operation == "DELETE")
        {
            ll index;
            cin >> index;

            if (index < 0 || index >= count)
            {
                cout << "Invalid" << endl;
            }
            else
            {
                delete_at_any_position(head, index);
                count--;
            }
        }
        else if (operation == "PRINT")
        {
            Node *temp = head;
            if (temp == NULL)
            {
                cout << "EMPTY" << endl;
            }
            else
            {
                while (temp != NULL)
                {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }

}