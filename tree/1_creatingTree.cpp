#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

node *createTree(node *root)
{
    queue<node *> q;
    node *p, *t;
    int x;

    // creating root node
    cout << "Enter root Node: ";
    cin >> x;
    root = new node(x);
    q.push(root);

    // now iterating a while loop to take all nodes of Tree as input
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter Left Child of " << p->data << " : ";
        cin >> x;

        if (x != -1)
        {
            t = new node(x);
            p->left = t;
            q.push(t);
        }

        cout << "Enter Right Child of " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            t = new node(x);
            p->right = t;
            q.push(t);
        }
    }
    return root;
}

void preOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrder(node *root) {}

// SEE HOW TO IMPLEMENT IT
int countHeight(node *root)
{
    int x = 0, y = 0;
    if (root == NULL)
        return 0;

    x = countHeight(root->left);
    y = countHeight(root->right);

    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int main()
{
    node *root = NULL;
    root = createTree(root);

    cout << "PreOrder Traversal of tree  = ";
    preOrder(root);
    cout << endl;

    cout << "PostOrder Traversal of tree  = ";
    postOrder(root);
    cout << endl;

    cout << "InOrder Traversal of tree  = ";
    inOrder(root);
    cout << endl;

    return 0;
}