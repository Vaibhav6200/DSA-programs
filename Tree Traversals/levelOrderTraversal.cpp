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

void levelOrder(node *root) {
    node* p;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        p = q.front();
        q.pop();
        cout << p->data << " ";
        if(p->left)
            q.push(p->left);
        if(p->right)
            q.push(p->right);
    }
}


int main()
{
    node *root = NULL;
    root = createTree(root);

    cout << "\n\nLevelOrder Traversal of tree  is = ";
    levelOrder(root);
    cout << "\n\n";

    return 0;
}