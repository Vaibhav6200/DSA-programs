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

int totalCount(node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = totalCount(p->left);
        y = totalCount(p->right);
        return x + y + 1;
    }
    return 0;
}

int countLeaf(node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countLeaf(p->left);
        y = countLeaf(p->right);
        if ((p->left == NULL) && (p->right == NULL))
            return x + y + 1;
        return x + y;
    }
    return 0;
}

int countDegree1(node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countDegree1(p->left);
        y = countDegree1(p->right);
        // if ((p->left != NULL && p->right == NULL) || (p->left == NULL && p->right != NULL))
        if (p->left != NULL ^ p->right != NULL) // using XOR
            return x + y + 1;
        return x + y;
    }
    return 0;
}

int countDegree2(node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countDegree2(p->left);
        y = countDegree2(p->right);
        if (p->left && p->right)
            return x + y + 1;
        return x + y;
    }
    return 0;
}

int countInternalNodes(node *p) // this will count all nodes with degree 2 and degree 1
{
    int x, y;
    if (p != NULL)
    {
        x = countInternalNodes(p->left);
        y = countInternalNodes(p->right);
        if (p->left || p->right)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int main()
{
    node *root = NULL;
    root = createTree(root);
    int total = totalCount(root);
    int degree1 = countDegree1(root);
    int degree2 = countDegree2(root);
    int leaf = countLeaf(root);
    int internalCount = countInternalNodes(root);

    cout << "\n\nTotal Nodes                  : " << total << endl;
    cout << "Total Leaf Nodes             : " << leaf << endl;
    cout << "Total Nodes of degree 1      : " << degree1 << endl;
    cout << "Total Nodes of degree 2      : " << degree2 << endl;
    cout << "Total No. of Internal Nodes  : " << internalCount << "\n\n";

    return 0;
}