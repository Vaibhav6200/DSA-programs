#include<bits/stdc++.h>
using namespace std;


class node{
public:
    int data;
    node *left;
    node *right;
    node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};


node *createTree(node *root){
    queue<node *> q;
    node *p, *t;
    int x;

    // creating root node
    cout << "Enter root Node: ";
    cin >> x;
    root = new node(x);
    q.push(root);

    // now iterating a while loop to take all nodes of Tree as input
    while (!q.empty()){
        p = q.front();
        q.pop();
        cout << "Enter Left Child of " << p->data << " : ";
        cin >> x;

        if (x != -1){
            t = new node(x);
            p->left = t;
            q.push(t);
        }

        cout << "Enter Right Child of " << p->data << " : ";
        cin >> x;
        if (x != -1){
            t = new node(x);
            p->right = t;
            q.push(t);
        }
    }
    return root;
}




// ALERT !  This function is WRONG






node* Insert(node* p, int value){

    // NOTE:- first search for the element which you want to insert in BST, if not found insert it

    node * prev = NULL;        // holds previous pointer address

    while(p!=NULL){  
        prev = p;   // updating prev pointer
        
        if(p->data == value)
            return p;

        else if (p->data > value)
            p = p->left;

        else
            p = p->right;
    }
    p = prev;
    node * temp = new node(value);
    if(p->data > value)
         p->left = temp;
    else
         p->right = temp;

    return p;
}

void preOrder(node* p){
    if(p == NULL)
        return;
    
    cout << p->data << " ";
    preOrder(p->left);
    preOrder(p->right);
}

int main()
{
    node* root = NULL;
    
    root = createTree(root);
    cout << "PreOrder Before Insertion of 25: ";
    preOrder(root);
    root = Insert(root, 25);
    cout << "\n\nPreOrder After Insertion of 25: ";
    preOrder(root);

    preOrder(root);

    return 0;
}