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

int Levels(node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = Levels(p->left);
        y = Levels(p->right);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}

int main()
{
    node *root = NULL;
    root = createTree(root);
    int L = Levels(root);
    cout << "\n\nTotal Levels in our BT : " << L << endl;
    cout << "Height of BT : " << L - 1 << "\n\n";

    return 0;
}