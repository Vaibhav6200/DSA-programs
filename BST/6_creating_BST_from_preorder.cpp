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

node * preorder_tree(int pre[], int n){

    stack<node*> st;
    // Creating root node
    node* root = new node(pre[0]);
    node* p = root;
    node* temp;

    int i=1;
    while(i<n){
        if(pre[i] < p->data){
            temp = new node(pre[i++]);
            st.push(p);
            p->left = temp;
            p = temp;
        }
        else{
            if(pre[i] > p->data){
                if(!st.empty()){
                    if(pre[i] < st.top()->data){
                        temp = new node(pre[i++]);
                        p->right = temp;
                        p = temp;
                    }
                    else{
                        p = st.top();
                        st.pop();
                    }
                }
                else{
                    temp = new node(pre[i++]);
                    p->right = temp;
                    p = temp;
                }
            }
        }
    }
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
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    node* root = NULL;

    root = preorder_tree(pre, 8);
    inOrder(root);
    return 0;
}