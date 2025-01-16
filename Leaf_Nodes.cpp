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

vector<int> arr;

void desc(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        arr.push_back(root->data);
    }
    desc(root->left);
    desc(root->right);
}

int main()
{
    tree *root;
    input_tree(root);

    desc(root);

    sort(arr.rbegin(), arr.rend());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}