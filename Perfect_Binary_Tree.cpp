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

int d = 0, node = 0;

int total_node(tree *root, int depth)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = total_node(root->left, depth + 1);
    int right = total_node(root->right, depth + 1);
    d = max(d, depth);
    return left + right + 1;
    
}

int main()
{
    tree *root = NULL;
    input_tree(root);

    int total = total_node(root, 1);
    // cout << total << endl;

    int calc = pow(2, d) - 1;
    // cout << calc << endl;

    if (total == calc)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}