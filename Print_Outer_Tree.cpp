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

void input_tree(tree *&root)
{
    int x;
    cin >> x;
    root = new tree(x);
    queue<tree *> q;
    q.push(root);

    while (!q.empty())
    {
        tree *temp = q.front();
        q.pop();

        int left, right;
        cin >> left >> right;

        tree *left_node, *right_node;

        if (left != -1)
        {
            left_node = new tree(left);
            temp->left = left_node;
            q.push(left_node);
        }
        if (right != -1)
        {
            right_node = new tree(right);
            temp->right = right_node;
            q.push(right_node);
        }
    }
}

void left_side(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left)
    {
        left_side(root->left);
    }
    else if (root->right)
    {
        left_side(root->right);
    }
    cout << root->data << " ";
}

void right_side(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    if (root->right)
    {
        right_side(root->right);
    }
    else if (root->left)
    {
        right_side(root->left);
    }
}

int main()
{

    tree *root = NULL;
    input_tree(root);

    left_side(root->left);
    cout << root->data << " ";
    right_side(root->right);
}