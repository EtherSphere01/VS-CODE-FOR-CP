#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

Node *insert_at_head(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        return newNode;
    }

    newNode->next = head;
    return newNode;
}

Node *insert_at_tail(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        return newNode;
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node *insert_at_mid(Node *head, int pos, int data)
{
    Node *newNode = new Node(data);

    if (pos == 1)
    {
        return insert_at_head(head, data);
    }

    int count = 0;
    Node *temp = head;
    Node *prev = head;
    while (temp)
    {
        count++;
        if (count == pos)
        {
            newNode->next = prev->next;
            prev->next = newNode;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5};
    Node *head = new Node(arr[0]);
    int n = arr.size();

    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }

    printLL(head);
    head = insert_at_mid(head, 7, 100);
    printLL(head);
}