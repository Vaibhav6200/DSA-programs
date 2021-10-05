// IDEA :->
// input: [1]->[2]->[3]->[4]->NULL
// output: NULL<-[1]<-[2]<-[3]<-[4]<-NewHead

// we will store first node in head of and will call function recursively for head->next
// and we assume that remaining list reverse ho k aa gyi hai like this:
// Head->[1]->[2]<-[3]<-[4]<-NewHead
// ab hum first node node ka link change kr denge
// head->next->next = head;   
// Head->[1]<-[2]<-[3]<-[4]<-NewHead
// now we have to point first node to NULL
// head->next = NULL; after this we will get
// NULL<-[1]<-[2]<-[3]<-[4]<-NewHead
// we will return newHead



#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* link;

    node(int value){
        data = value;
        link = NULL;
    }
};


node* reverse(node* head){
      if(head == NULL || head->link == NULL){
        return head;
    }

    node* newHead = reverse(head->link);
    head->link->link = head;
    head->link = NULL;

    return newHead;
}

node* Insert(node*head , int val){

    node* temp = new node(val);
    if(head == NULL){
        head = temp;
        return head;
    }
    node* temp1 = head;
    while(temp1->link != NULL){
        temp1 = temp1->link;
    }
    temp1->link = temp;

    return head;
}

void Print(node* head){
    node * temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->link;
    }
}

int main()
{
    node* head;
    head = NULL;
    head = Insert(head , 2);
    head = Insert(head , 3);
    head = Insert(head , 4);
    head = Insert(head , 5);
    cout << "Before reversing : ";
    Print(head);        // 2,3,4,5
    
    cout << "\nAfter reversing : ";
    head = reverse(head);
    Print(head);       // 5,4,3,2
}