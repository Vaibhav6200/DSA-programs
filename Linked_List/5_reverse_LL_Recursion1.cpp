#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* link;
};
node * head;

void reverse(node* p){
    // base condition: if p->next == NULL change head to p and return; 
    if(p->link == NULL){
        head = p;
        return;
    }
    reverse(p->link);   // by this recursion we will reach to end of the linked list
    node* q = p->link;
    q->link = p;
    // p->link->link = p;
    p->link = NULL;
}

node * Insert(node*head , int val , int pos){

    node* temp1 = new node();
    temp1->data = val;
    temp1->link = NULL;

    if(pos == 1){
        temp1->link = head;
        head = temp1;
    }
    else{
        node* temp2 = head;
        for(int i=1 ; i<pos-1 ; i++){
            temp2 = temp2->link;
        }
        temp1->link = temp2->link;
        temp2->link = temp1;
    }
return head;
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
    head = Insert(head , 2 , 1);
    head = Insert(head , 3 , 2);
    head = Insert(head , 4 , 1);
    head = Insert(head , 5 , 2);
    cout << "Before reversing : ";
    Print();        // 4 5 2 3
    
    cout << "\nAfter reversing : ";
    reverse(head);
    Print();       // 3 2 5 4
}