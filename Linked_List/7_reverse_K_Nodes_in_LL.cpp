
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

node* reverseK(node* head , int k){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

// We will reverse first k nodes
    int count=0;
    while(currptr != NULL && count < k){
        nextptr = currptr->link;
        currptr->link = prevptr;
        prevptr = currptr;
        currptr = nextptr;

        count++;
    }
    // hum recursive call tab tak krenge jab tak nextptr/currptr NULL nhi ho jate
    // because if they become null that means our linked list ended so we have to return 
    if(nextptr != NULL)
        head->link = reverseK(nextptr , k);
    
return prevptr;
}

int main()
{
    node* head;
    head = NULL;
    head = Insert(head , 1);
    head = Insert(head , 2);
    head = Insert(head , 3);
    head = Insert(head , 4);
    head = Insert(head , 5);
    head = Insert(head , 6);
    Print(head);
    cout  << endl;

    head = reverseK(head , 3);
    Print(head);

    return 0;
}