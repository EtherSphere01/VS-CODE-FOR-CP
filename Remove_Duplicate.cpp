#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class linked_list
{
public:
    ll data;
    linked_list *next;

    linked_list(ll data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print_linked_list(linked_list *head)
{
    linked_list *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert_at_tail(linked_list *&head, ll data, linked_list *&tail)
{
    linked_list *new_node = new linked_list(data);

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
}

void remove_duplicates(linked_list *&head, linked_list *&tail)
{
    if (head == NULL)
    {
        return;
    }

    linked_list *current = head;

    while (current != NULL)
    {
        linked_list *previous = current;
        while (previous->next != NULL)
        {
            if (previous->next->data == current->data)
            {
                linked_list *temp = previous->next;
                previous->next = previous->next->next;
                if (previous->next == NULL)
                {
                    tail = previous;
                }
                delete temp;
            }
            else
            {
                previous = previous->next;
            }
        }
        current = current->next;
    }
}

int main()
{
    linked_list *head = NULL;
    linked_list *tail = NULL;

    while (1)
    {
        ll x;
        cin >> x;

        if (x == -1)
        {
            break;
        }

        insert_at_tail(head, x, tail);
    }

    remove_duplicates(head, tail);
    print_linked_list(head);
}