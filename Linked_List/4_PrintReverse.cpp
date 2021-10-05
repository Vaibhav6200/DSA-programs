// YOU WILL FIND REVERSE CODE AT BOTTOM

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* link;
};

node* head;

void Insert(int val , int pos){

    node* temp1 = new node();
    temp1->data = val;
    temp1->link = NULL;

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

void Delete(int pos){
    if(pos == 1){
        node* del;
        del = head;
        head = head->link;
        delete del;
        return;
    }
    node* temp = head;
    node* del;
    for(int i=1 ; i<pos-1 ; i++){
        temp = temp->link;
    }
    del = temp->link;
    temp->link = temp->link->link;
    delete del;
}

// Code of REVERSING linked list
void Reverse(){
// we need 3 pointers prev,cutt, and next and initialize prev pointer to NULL and current to head
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    
// start a loop while(curr!= null)
    while(currptr != NULL){
// set next to curr->link
    nextptr = currptr->link;
// now change link of curr to prev pointer
    currptr->link = prevptr;
    
// now set prev ptr = curr ptr and curr = next
    prevptr = currptr;
    currptr = nextptr;
    }
// set head to prevptr
    head = prevptr;
}


int main()
{
    head = NULL;
    Insert(2,1);
    Insert(3,2);
    Insert(4,1);
    Insert(5,2);
    cout << "Before reversing : ";
    Print();        // 4 5 2 3
    
    cout << "\nAfter reversing : ";
    Reverse();
    Print();       // 3 2 5 4

    cout << "\nAgain reversing we will get our original list : ";
    Reverse();
    Print();        // 3 2 5 4
    return 0;
}