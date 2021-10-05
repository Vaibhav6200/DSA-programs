#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* link;

    node(int val){
        data = val;
        link = NULL;
    }
};

node* head;         

void Insert(int val){
    node* temp = new node(val);
    
    if(head == NULL){
        head = temp;
        return;
    }
    node * temp1 = head;
    while(temp1->link != NULL)
        temp1 = temp1->link;
    
    temp1->link = temp;
}

void Print(){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->link;
    }
}

int main()
{
    head = NULL;
    
    return 0;
}