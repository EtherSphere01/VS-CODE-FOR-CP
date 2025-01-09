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

ll get_answer(linked_list *head, linked_list *head2)
{
    if (head == NULL && head2 == NULL)
    {
        return 1;
    }
    else if (head == NULL or head2 == NULL)
    {
        return 0;
    }

    linked_list *temp = head;
    linked_list *temp2 = head2;
    ll count = 0;
    while (temp != NULL && temp2 != NULL)
    {
        if (temp->data != temp2->data)
        {
            return 0;
        }
        temp = temp->next;
        temp2 = temp2->next;
    }

    if (temp == NULL and temp2 == NULL)
    {
        return 1;
    }
    return 0;
}

int main()
{

    linked_list *head1 = NULL;
    linked_list *tail1 = NULL;
    linked_list *head2 = NULL;
    linked_list *tail2 = NULL;

    while (1)
    {
        ll x;
        cin >> x;

        if (x == -1)
        {
            break;
        }

        insert_at_tail(head1, x, tail1);
    }

    while (1)
    {
        ll x;
        cin >> x;

        if (x == -1)
        {
            break;
        }

        insert_at_tail(head2, x, tail2);
    }

    if(get_answer(head1, head2))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
}
