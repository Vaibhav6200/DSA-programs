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


node* Insert(node* root, int value){
    // NOTE:- first search for the element which you want to insert in BST, if not found insert it

    node * prev;        // holds previous pointer address
    node * p = root;

    if(root == NULL){       // means no element in tree
         node * temp = new node(value);
         return temp;        
    }

    while(p!=NULL){  
        prev = p;   // updating prev pointer
        
        if(p->data == value)
            return root;

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

    return root;
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
    
    root = Insert(root, 10);
    root = Insert(root, 5);
    root = Insert(root, 20);
    root = Insert(root, 8);
    root = Insert(root, 30);
    
    cout << "Inorder Traversal : ";
    inOrder(root);

    return 0;
}