#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
    Node(int val, Node *nxt, Node *prv)
    {
        data = val;
        next = nxt;
        prev = prv;
    }
};

Node *convertDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->prev = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete (temp);
    return head;
}

Node *deleteTail(Node *head)
{
    if (head->next == NULL || head == NULL)
        return NULL;

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *prev = temp->prev;
    prev->next = NULL;
    temp->prev = NULL;
    delete (temp);

    return head;
}

Node *deleteAnyPos(Node *head, int pos)
{

    if (head == NULL)
        return NULL;

    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (count == pos)
            break;
        temp = temp->next;
    }

    Node *left = temp->prev;
    Node *right = temp->next;

    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    else if (right == NULL)
    {
        return deleteTail(head);
    }
    else if (left == NULL)
    {
        return deleteHead(head);
    }
    else
    {
        left->next = right;
        right->prev = left;
        temp->next = NULL;
        temp->prev = NULL;
        delete (temp);
        return head;
    }
    return head;
}

int main()
{

    vector<int> arr = {1, 2, 5, 3, 4};

    Node *head = convertDLL(arr);
    print(head);
    head = deleteAnyPos(head, 6);
    print(head);
}