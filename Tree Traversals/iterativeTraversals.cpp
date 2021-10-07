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

// Preorder Iterative Traversal
void preOrder(node *root)
{
    node *t = root;
    stack<node *> st;

    while (t != NULL || !st.empty())
    {
        if (t != NULL)
        {
            cout << t->data << " ";
            st.push(t);
            t = t->left;
        }
        else
        {
            t = st.top();
            st.pop();
            t = t->right;
        }
    }
}

// Inorder Iterative Traversal
void inOrder(node *root)
{
    node *t = root;
    stack<node *> st;

    while (t != NULL || !st.empty())
    {
        if (t != NULL)
        {
            st.push(t);
            t = t->left;
        }
        else
        {
            t = st.top();
            st.pop();
            cout << t->data << " ";
            t = t->right;
        }
    }
}

// PostOrder Iterative Traversal
void postOrder(node *curr){
    node* prev;
    stack<node*> st;
    while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            curr = st.top();
            if((curr->right == NULL) || (curr->right == prev)){
                cout << curr->data << " ";
                st.pop();
                prev = curr;
                curr = NULL; 
            }
            else 
                curr = curr->right;
        }
    }
}

int main()
{
    node *root = NULL;
    root = createTree(root);

    cout << "\n\nPreOrder  : ";
    preOrder(root);
    cout << endl;

    cout << "InOrder   : ";
    inOrder(root);
    cout << endl;

    cout << "PostOrder : ";
    postOrder(root);
    cout << "\n\n";

    return 0;
}