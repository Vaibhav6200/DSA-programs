// Que. Given a singly linked list consisting of N nodes. The task is to remove duplicates 
// (nodes with duplicate values) from the given list (if exists).
// Note: Try not to use extra space. Expected time complexity is O(N). 
// The nodes are arranged in a sorted way.

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

// Insert Node at Tail
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

// print complete linked list
void Print(){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->link;
    }cout <<"NULL" << endl;
}

// function to remove duplicates from a sorted linked list
void removeDuplicate(){

     node* temp = head;
     node* del;
    
    while(temp->link != NULL){
        if(temp->data == temp->link->data){
            del = temp->link;
            temp->link = temp->link->link;
            delete del;
        }
        else{
            temp = temp->link;
        }
    }
}
int main()
{
    head = NULL;
    Insert(1);
    Insert(1);
    Insert(2);
    Insert(2);
    Insert(5);
    Print();

    removeDuplicate();
    Print();
    return 0;
}