// we have to swap last and first node in our linked list

// Input:
// head->[1]->[2]->[3]->[4]->NULL

// Output:
// head->[4]->[2]->[3]->[1]->NULL



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


// Insert Node at Tail
node* Insert(node* head, int val){
    node* temp = new node(val);
    
    if(head == NULL){
        head = temp;
        return head;
    }
    node * temp1 = head;
    while(temp1->link != NULL)
        temp1 = temp1->link;
    
    temp1->link = temp;

    return head;
}

// print complete linked list
void Print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->link;
    }cout <<"NULL" << endl;
}

node* swapNodes(node* head){
    node* temp = head;
    node*ptr = head;

    while(ptr->link->link != NULL)
        ptr = ptr->link;

    head = ptr->link;
    ptr->link = temp;
    head->link = temp->link;
    temp->link = NULL;

    return head;
}

int main()
{
    node* head = NULL;

    head = Insert(head , 1);
    head = Insert(head , 2);
    head = Insert(head , 3);
    head = Insert(head , 4);
    head = Insert(head , 5);
    head = Insert(head , 6);

    Print(head);

    head = swapNodes(head);
    Print(head);

    return 0;
}