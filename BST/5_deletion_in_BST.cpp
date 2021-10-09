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

int Height(node* t){

    if(t != NULL){
        int x=0, y=0;
        x = Height(t->left);
        y = Height(t->right);
        return (x>y ? x+1 : y+1);
    }
    return 0;
}

node* inPre(node* t){
    while(t && t->right != NULL)
        t = t->right;
    return t;
}

node* inSucc(node* t){
    
    while(t && t->left != NULL)
        t = t->left;
    return t;
}

node* Delete(node *p , int key){


// Now if there is no element in tree and then also user is trying to delete any element then just return NULL
    if(p==NULL)
        return NULL;

// now if our node is a leaf node then just delete that node
    if(p->left == NULL && p->right == NULL){
        delete p;
        return NULL;
    }

// DELETING A NODE
    if(p->data > key)
        p->left = Delete(p->left, key);
    
    else if(p->data < key)
        p->right = Delete(p->right, key);

    else{
        if(Height(p->left) > Height(p->right)){
            // now delete element from left subtree
            node* q = inPre(p->left);
            p->data = q->data;
            p->left = Delete(p->left, q->data);
        }
        else{
            node* q = inPre(p->right);
            p->data = q->data;
            p->right = Delete(p->right, q->data);
        }
    }
    return p;
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