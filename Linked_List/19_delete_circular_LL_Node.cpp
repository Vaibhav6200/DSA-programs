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


node* makeCycle(node* head , int pos){
    node* temp = head;
    node* startNode;

    int count = 1;
    while(temp->link != NULL){
        if(count == pos){
            startNode = temp;
        }

        count++;
        temp = temp->link;
    }
    temp->link = startNode;

    return head;
}

node* Delete(node* head , int key){
    node* temp = head;
    while(temp->link->data != key)
        temp = temp->link;

    node* del = temp->link;
    temp->link = temp->link->link;
    delete del;

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

    head = makeCycle(head , 1);
    // head = Delete(head , 4);
    // Print(head);

    head = Delete(head , 3);
    Print(head);

    return 0;
}