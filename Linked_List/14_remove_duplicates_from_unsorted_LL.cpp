// //Function to remove duplicates from unsorted linked list.
   

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


// Insert node at Tail
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

node * removeDuplicates( node *head){
   
    node* currptr = head;
    node* prevptr = NULL;
    node* nextptr;      // pointer to delete duplicate node
    node* temp;
    int key;
    int idx[10] = {0};  // frequency array to note occurance of each number
    
    while(currptr != NULL){
        nextptr = currptr->link; 
        
        key = currptr->data;
        if(idx[key] != 0){
            // we have to remove this node
            temp = prevptr;
            temp->link = nextptr;
            delete currptr;
            currptr = nextptr;
        }
        else{
            idx[key]++;
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
    head = Insert(head , 1);
    head = Insert(head , 3);
    head = Insert(head , 4);
    head = Insert(head , 4);
    head = Insert(head , 4);
    head = Insert(head , 4);
    head = Insert(head , 4);
    head = Insert(head , 6);

    Print(head);

    head = removeDuplicates(head);
    Print(head);

    return 0;
}