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


node* Rinsert(node* t, int value){

    if(t == NULL){
        node* temp = new node(value);
        return temp;
    }

    if(t->data > value)
        t->left = Rinsert(t->left, value);

    else if(t->data < value)
        t->right = Rinsert(t->right, value);

    return t;
}

void inOrder(node* p){
    if(p == NULL)
        return;
    
    inOrder(p->left);
    cout << p->data << " ";
    inOrder(p->right);
}

int main()
{
    node* root = NULL;
    
    root = Rinsert(root, 10);
    root = Rinsert(root, 5);
    root = Rinsert(root, 20);
    root = Rinsert(root, 8);
    root = Rinsert(root, 30);
    
    cout << "Inorder Traversal : ";
    inOrder(root);

    return 0;
}