#include <bits/stdc++.h>
using namespace std;

#define ll long long

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

ll get_answer(linked_list *head, ll x)
{
    if (head == NULL)
    {
        return -1;
    }

    linked_list *temp = head;
    ll count = 0;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }
    return -1;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
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

        ll x;
        cin >> x;
        cout << get_answer(head, x) << endl;
    }
}
