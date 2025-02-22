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

tree *convert(vector<int> v, int n, int l, int r)
{
    int mid = (l + r) / 2;
    tree *root = new tree(v[mid]);
    convert(v, n, l, mid - 1);
    convert(v, n, mid + 1, r);
    return root;
}

int main()
{
    vector<int> v = {2, 5, 8, 11, 15, 18};
    int n = v.size();
    tree *root = convert(v, n, 0, n - 1);
    printLevelOrder(root);
}
