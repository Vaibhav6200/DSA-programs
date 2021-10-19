#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    int height;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = right = NULL;
        height = 0;
    }  
};

node* root = NULL;

int Height(node* p){
    if(p == NULL) 
        return 0;

    int x, y;
    x = Height(p->left);
    y = Height(p->right);

    return (x>y ? x+1 : y+1);
}

int BalanceFactor(node* p){
    int Hleft, Hright;

    Hleft = Height(p->left);
    Hright = Height(p->right);
    
    return Hleft - Hright;
}

node* LLRotation(node* p){
    node* pl = p->left;
    node* plr = pl->right;
    
    pl->right = p;
    p->left = plr;
    p->height = Height(p);      // updating height
    pl->height = Height(pl);      // updating p's left child height

    if(p == root)
        root = pl;

    return pl;
}

node* LRRotation(node* p){
    node* pl = p->left;
    node* plr = pl->right;
    
    pl->right = plr->left;
    p->left = plr->right;
    plr->left = pl;      
    plr->right = p;      

    pl->height = Height(pl);
    p->height = Height(p);
    plr->height = Height(plr);      // updating p's left child height

    if(root == p)
        root = plr;

    return plr;
}

node* RRRotation(node* p){
    node* pr = p->right;
    node* prl = pr->left;
    
    p->right = prl;
    pr->left = p;
    
    p->height = Height(p);      // updating height
    pr->height = Height(pr);      // updating p's left child height

    if(p == root)
        root = pr;

    return pr;
}

node* RLRotation(node* p){
    node* pr = p->right;
    node* prl = pr->left;
    
    p->right = prl->left;
    pr->left = prl->right;

    prl->left = p;
    prl->right = pr;
    
    p->height = Height(p);      // updating height
    pr->height = Height(pr);     
    prl->height = Height(prl);    

    if(p == root)
        root = prl;

    return prl;
}

node* Rinsert(node*p, int key){

    if(p == NULL){
        node* temp = new node(key);
        return temp;
    }

    if(key < p->data)
        p->left = Rinsert(p->left, key);

    else if(key > p->data)
        p->right = Rinsert(p->right, key);

    p->height = Height(p);

    if(BalanceFactor(p) == 2 && BalanceFactor(p->left) == 1)
        LLRotation(p);

    else if(BalanceFactor(p) == 2 && BalanceFactor(p->left) == -1)
        LRRotation(p);

    else if(BalanceFactor(p) == -2 && BalanceFactor(p->right) == -1)
        RRRotation(p);

    else if(BalanceFactor(p) == -2 && BalanceFactor(p->right) == 1)
        RLRotation(p);

    return p;
}

void preorder(node* p){
    if(p == NULL)
        return;
    cout << p->data << " ";
    preorder(p->left);
    preorder(p->right);
}

int main()
{
// LL ROTATION
    // root = Rinsert(root, 10);
    // Rinsert(root, 5);
    // Rinsert(root, 2);

// LR ROTATION
    // root = Rinsert(root, 50);
    // Rinsert(root, 10);
    // Rinsert(root, 60);
    // Rinsert(root, 5);
    // Rinsert(root, 30);
    // Rinsert(root, 20);
    // Rinsert(root, 40);

// RR ROTATION
    // root = Rinsert(root, 10);
    // Rinsert(root, 20);
    // Rinsert(root, 30);

// RL ROTATION
    root = Rinsert(root, 10);
    Rinsert(root, 5);
    Rinsert(root, 20);
    Rinsert(root, 15);
    Rinsert(root, 30);
    Rinsert(root, 12);
    Rinsert(root, 16);

    cout << "PreOrder : ";
    preorder(root);
    return 0;
}