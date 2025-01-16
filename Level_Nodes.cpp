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

vector<int> v;

void print_(int level, tree *root, int depth)
{
    if (root == NULL)
    {
        return;
    }
    if (level == depth)
    {
       v.push_back(root->data);
       return;
    }

    print_(level, root->left, depth + 1);
    print_(level, root->right, depth + 1);
}

int main()
{

    tree *root;
    input_tree(root);

    int level;
    cin >> level;

    print_(level, root, 0);

    if(v.size()==0){
        cout << "Invalid" << endl;
    }
    else{
        for(auto i:v){
            cout << i << " ";
        }
        cout << endl;
    }
}