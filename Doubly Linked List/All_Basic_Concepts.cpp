// Following operations are performed below:
// (i) InsertAtHead
// (ii) InsertAtTail
// (iii) print
// (iv) ReversePrint

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

node* head;

void InsertAtHead(int val){
    node* temp = new node();
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if(head == NULL){
        head = temp;
        return;      
    }
    
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void InsertAtTail(int val){
    node* temp = new node();
    temp->data = val;
    temp->prev = NULL;
    temp->next = NULL;
    // write initial condition
    if(head == NULL){
        head = temp;
        return;
    }
    // now if we already have an element in our linked list 
    // we will first traverse towards the end of the linked list using a pointer
    // then we will change the links
    node* read = head;      // read is a pointer variable to traverse over our linked list to the end
    while(read->next != NULL){
        read = read->next;
    }
    // now we have reached to end of our linked list, now we have to change our links
    read->next = temp;
    temp->prev = read;
}

void Print(node * p){
    node* temp = p;      
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void ReversePrint(node * p){
    // base condition
    if(p == NULL) return;

    // recursive call
    ReversePrint(p->next);
    cout << p->data <<" ";
    return;
}

int main()
{
    head = NULL;
    
    InsertAtTail(5);
    InsertAtTail(6);
    InsertAtTail(2);

    InsertAtHead(7);
    InsertAtHead(8);
    InsertAtHead(9);
    cout << "Before Reversing: ";
    Print(head);
    cout << "\nAfter Reversing: ";
    ReversePrint(head);
    return 0;
}