#include <iostream>
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

void insert_at_head(linked_list *&head, ll data, linked_list *&tail)
{
    linked_list *new_node = new linked_list(data);

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

void delete_at_anypoistion(linked_list *&head, ll pos, linked_list *&tail)
{
    if (head == NULL)
    {
        return;
    }

    if (pos == 0)
    {
        linked_list *temp = head;
        head = head->next;
        if (head == NULL) // If the list becomes empty, update the tail
        {
            tail = NULL;
        }
        delete temp;
        return;
    }

    linked_list *temp = head;
    ll count = 0;
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL)
    {
        return;
    }

    linked_list *temp2 = temp->next;
    temp->next = temp->next->next;
    if (temp->next == NULL) // If the last element is deleted, update the tail
    {
        tail = temp;
    }
    delete temp2;
}

int main()
{
    linked_list *head = NULL;
    linked_list *tail = NULL;

    ll t;
    cin >> t;
    while (t--)
    {
        ll indx, value;
        cin >> indx >> value;
        if (indx == 0)
        {
            insert_at_head(head, value, tail);
            print_linked_list(head);
        }
        else if (indx == 1)
        {
            insert_at_tail(head, value, tail);
            print_linked_list(head);
        }
        else
        {
            delete_at_anypoistion(head, value, tail);
            print_linked_list(head);
        }
    }
}