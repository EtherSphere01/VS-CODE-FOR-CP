#include <bits/stdc++.h>
using namespace std;

class tree
{
public:
    int data;
    tree *left;
    tree *right;

    tree(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void printInorder(tree *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPreorder(tree *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(tree *root)
{
    if (root == NULL)
        return;

    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

void printLevelOrder(tree *root)
{
    if (root == NULL)
        return;

    queue<tree *> q;
    q.push(root);

    while (!q.empty())
    {
        tree *temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

tree *input_tree()
{
    int data;
    cin >> data;
    tree *root;
    if (data == -1)
        root = NULL;
    else
        root = new tree(data);

    queue<tree *> q;
    if (root != NULL)
        q.push(root);

    while (!q.empty())
    {
        tree *temp = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        tree *myleft, *myright;

        if (l != -1)
        {
            myleft = new tree(l);
            temp->left = myleft;
            q.push(myleft);
        }
        else
        {
            myleft = NULL;
            temp->left = myleft;
        }

        if (r != -1)
        {
            myright = new tree(r);
            temp->right = myright;
            q.push(myright);
        }
        else
        {
            myright = NULL;
            temp->right = myright;
        }
    }
    return root;
}

int main()
{
    tree *root = input_tree();
    printPostorder(root);
    cout << endl;
    printLevelOrder(root);
}
