#include <bits/stdc++.h>
using namespace std;

class LinkedList
{
public:
    LinkedList *next;
    LinkedList *prev;
    int data;
    LinkedList(int val) : data(val), next(nullptr), prev(nullptr) {}
    LinkedList() : data(0), next(nullptr), prev(nullptr) {}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    LinkedList *head = new LinkedList();
    LinkedList *temp = head;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        LinkedList *newNode = new LinkedList(val);
        if (i == 0)
        {
            temp->data = val;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    int key;
    cin >> key;
    temp = head;
    while (temp != NULL)
    {
        if (head->data == key)
        {
            head = head->next;
            free(temp);
            temp = head;
        }
        else
        {
            if (temp->data == key)
            {
                LinkedList *prevNode = temp->prev;
                LinkedList *nextNode = temp->next;

                if (prevNode)
                {
                    prevNode->next = nextNode;
                }
                if (nextNode)
                {
                    nextNode->prev = prevNode;
                }
                free(temp);
                temp = nextNode;
            }
            else
            {
                temp = temp->next;
            }
        }
    }

    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
