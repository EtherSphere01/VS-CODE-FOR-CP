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
    queue<tree *> q;
    int x;
    cin >> x;
    root = new tree(x);
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

int calculatesum(tree *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if(root->left == NULL && root->right == NULL){
        return 0;
    }

    int left = calculatesum(root->left);
    int right = calculatesum(root->right);
    return left + right + root->data;
}

int main()
{
    tree *root;
    input_tree(root);

    int sum = calculatesum(root);

    cout << sum << endl;
}