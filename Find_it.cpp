#include<bits/stdc++.h>
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

void leaf_node(tree *root, map<int, int> &m)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        m[root->data]++;
    }

    leaf_node(root->left, m);
    leaf_node(root->right, m);
}

int main()
{
    tree *root = NULL;
    input_tree(root);

    map<int, int> m;
    leaf_node(root, m);

    int value = INT_MAX;
    int count = INT_MIN;

    for(auto i :m){
        if(i.second > count){
            count = max(count, i.second);
            value = i.first;
        }
        else if(i.second == count){
            value = min(value, i.first);
        }
    }
    cout << value << endl;
}