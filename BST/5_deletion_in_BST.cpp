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

node *Rinsert(node *t, int value)
{

    if (t == NULL)
    {
        node *temp = new node(value);
        return temp;
    }

    if (t->data > value)
        t->left = Rinsert(t->left, value);

    else if (t->data < value)
        t->right = Rinsert(t->right, value);

    return t;
}

void inOrder(node *p)
{
    if (p == NULL)
        return;

    inOrder(p->left);
    cout << p->data << " ";
    inOrder(p->right);
}

int Height(node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->left);
    y = Height(p->right);

    if (x > y)
        return x + 1;
    else
        return y + 1;
}

node *InPre(node *p)
{

    while (p->right != NULL)
        p = p->right;

    return p;
}
node *InSucc(node *p)
{
    while (p->left != NULL)
        p = p->left;

    return p;
}

node *Delete(node *p, int key)
{

    // STEP 4:- if we reached to last node (leaf node) then we have to just delete that node
    if (p->left == NULL && p->right == NULL)
    {
        delete p;
        return NULL;
    }

    // STEP 1:- if key is less than p->data means its present in left subtree of p so we will perform delete operation on left subtree
    if (key < p->data)
        p->left = Delete(p->left, key);

    // STEP 2:- if key is greater than p->data means its present in right subtree of p so we will perform delete operation on right subtree
    else if (key > p->data)
        p->right = Delete(p->right, key);

    // STEP 3:- if this else part gets executed means we found the key
    else
    {

        // now check height of left and right subtree and then jiski height jyada hogi uss subtree me se hum element replace krenge(inorder successor/predecessor)
        if (Height(p->left) > Height(p->right))
        {
            // find inorder predecessor of p and replace its data with p's data
            node *q = InPre(p->left);
            p->data = q->data;
            p->left = Delete(p->left, q->data);
        }
        else
        {
            // find inorder Successor of p and replace its data with p's data
            node *q = InSucc(p->right);
            p->data = q->data;
            p->right = Delete(p->right, q->data);
        }
    }
    return p;
}

int main()
{
    node *root = NULL;
    root = Rinsert(root, 30);
    root = Rinsert(root, 20);
    root = Rinsert(root, 40);
    root = Rinsert(root, 10);
    root = Rinsert(root, 25);
    root = Rinsert(root, 35);
    root = Rinsert(root, 45);
    root = Rinsert(root, 42);
    root = Rinsert(root, 43);

    inOrder(root);
    cout << endl;
    root = Delete(root, 40);
    inOrder(root);

    return 0;
}