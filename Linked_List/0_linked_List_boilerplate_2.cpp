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

node* head = NULL;
node* tail = NULL;

// Insert Node at Tail
void Insert(int val){
    node* temp = new node(val);
    
    if(head == NULL){
        head = tail = temp;
        return;
    }
    tail->link = temp;
    tail = temp;

    return;
}

// print complete linked list
void Print(){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->link;
    }cout <<"NULL" << endl;
}


int main()
{

    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Insert(6);

    Print();


    return 0;
}