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

    cout << "Enter root Node: ";
    cin >> x;
    root = new node(x);
    q.push(root);

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

node* Rsearch(node* p, int key){
    
    if(p == NULL)
        return NULL;
    
    if (p->data == key)
        return p;   

    else if(p->data > key)
        p = Rsearch(p->left, key);

    else 
        p = Rsearch(p->right, key);
}

int main()
{
    node* root = NULL;
    root = createTree(root);
    
    node * position1 = Rsearch(root, 25);
    node * position2 = Rsearch(root, 26);
    
    if(position1)
        cout << "Key 1 found : " << position1->data << endl;
    else
        cout << "Key 1 not Found" << endl;

    if(position2)
        cout << "Key 2 found : " << position2->data << endl;
    else
        cout << "Key 2 not Found" << endl;
        
    return 0;
}