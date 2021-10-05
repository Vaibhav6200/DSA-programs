// Merge 2 sorted linked list

// INPUT:
// head1->[1]->[4]->[5]->[7]->NULL
// head2->[2]->[3]->[6]->NULL

// OUTPUT:
// head->[1]->[2]->[3]->[4]->[5]->[6]->[7]->NULL


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
        

// INSERT NODE
node* Insert(node* head , int val){
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

// PRINT NODES
void Print(node* p){
    node* temp = p;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->link;
    }
}

node* merge(node* head1 , node* head2){
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* dummyNode = new node(-1);
    node* ptr3 = dummyNode;


    while(ptr1 != NULL && ptr2!=NULL){
        if(ptr1->data < ptr2->data){
            ptr3->link = ptr1;
            ptr1 = ptr1->link;
            ptr3 = ptr3->link;
        }
        else{
            ptr3->link = ptr2;
            ptr2 = ptr2->link;
            ptr3 = ptr3->link;
        }
    }
    while(ptr1 != NULL){
        ptr3->link = ptr1;
        ptr1 = ptr1->link;
        ptr3 = ptr3->link;
    }
    while(ptr2 != NULL){
        ptr3->link = ptr2;
        ptr2 = ptr2->link;
        ptr3 = ptr3->link;
    }
    return dummyNode->link;
}

int main()
{
    node* head1; 
    node* head2; 
    head1 = NULL;
    head2 = NULL;

    head1 = Insert(head1 , 1);
    head1 = Insert(head1 , 4);
    head1 = Insert(head1 , 5);
    head1 = Insert(head1 , 7);

    head2 = Insert(head2 , 2);
    head2 = Insert(head2 , 3);
    head2 = Insert(head2 , 6);

cout << "Before merging : " << endl;
cout << "List 1 : ";
    Print(head1);
    cout << endl;
cout << "List 2 : ";
    Print(head2);
    cout << endl << endl;
    
cout << "After merging our new list will be : " << endl;
cout << "New List : ";
    node* newHead = NULL;
    newHead = merge(head1 , head2);
    Print(newHead);


    return 0;
}