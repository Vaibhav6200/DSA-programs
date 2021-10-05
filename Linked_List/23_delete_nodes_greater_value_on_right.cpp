





// incomplete
// Getting wrong output for higher values

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

node* compute(node *head){

    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    node* temp;
    
    while(currptr->link != NULL){
        nextptr = currptr->link;
        
        if(head->link->data > head->data){
            head = nextptr;
            delete currptr;
            currptr = nextptr;
        }   
        else if(currptr->link->data > currptr->data){
            temp = prevptr;
            temp->link = nextptr;
            delete currptr;
            currptr = nextptr;
        }
        else{
            prevptr = currptr;
            currptr = nextptr;
        }
    }
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


    return 0;
}