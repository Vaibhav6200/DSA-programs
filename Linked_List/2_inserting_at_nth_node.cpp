#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* link;
};

node* head;

void Insert(int val , int pos){
    // if we have to insert any element at head, then we have to perform different operation 
    // because in that case we need to chand value of head
    // for rest of the position we have to change link of node

    // first we will create a node
    node* temp1 = new node();
    temp1->data = val;
    temp1->link = NULL;

    // writing code for inserting at position 1
    if(pos == 1){
        temp1->link = head;
        head = temp1;
        return;
    }

    node* temp2 = head;
    for(int i=1 ; i<pos-1 ; i++){
        temp2 = temp2->link;
    }
    temp1->link = temp2->link;
    temp2->link = temp1;

}

void Print(){
    node * temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->link;
    }
}

int main()
{
    head = NULL;
    Insert(2,1);  // passing value and position as argument
    Insert(3,2);
    Insert(4,1);
    Insert(5,2);
    Print();
    return 0;
}