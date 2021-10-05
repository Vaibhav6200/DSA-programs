// Que. Given a Cirular Linked List of size N, split it into two halves circular lists. 
// If there are odd number of nodes in the given circular linked list then out of the resulting 
// two halved lists, first list should have one node more than the second list. 
// The resultant lists should also be circular lists and not linear lists.








// Incomplete







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

// function to make given linkedlist cyclic
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

node* removeCycle(node* head){
    // using floyd's algorithm
    node* fast = head;
    node* slow = head;

    while(fast!= NULL && fast->link != NULL ){
        fast = fast->link->link;
        slow = slow->link;
        if(fast == slow)
            break;
    }
    fast = head;
    while(fast->link != slow->link){
        fast = fast->link;
        slow = slow->link;
    }
    slow->link = NULL;

    return head;
}



// Function to split a circular linkedlist into 2 halves
node* split(node* head){
    node* head1;        // these are pointer to head for resultant 2 halves linkedlist
    node* head2;
// first we will break circular linked list into linear form
    head = removeCycle(head);

// count number of elements in them
    node* temp = head;
    int count = 0;
    while(temp != NULL){
       count++;
       temp = temp->link;
    }
    temp = head;    // again initializing temp to head so that we can reuse it

    int middleElement = count/2 + 1;
// if count == odd =>       (e.g.  [1]->[2]->[3]->[4]->[5] )
//   linkedlist 1 will have count/2 + 1; elements     (e.g.  5/2 + 1 == 3)
//   linkedlist 2 will have count/2; elements
    if(count % 2 == 1){     // code if : odd element are there in original linkedlist
        head1 = head;

        for(int i=1 ; i< middleElement ; i++){
            temp = temp->link;
        }
        head2 = temp->link;
        temp->link = NULL;  //  head1-> []->[]->[]->NULL  head2->[2]->[3]->NULL
        // so till now we have seperated both linked lists

        // now we have to make them circular
        head1 = makeCycle(head1,1);
        head2 = makeCycle(head2,2);
    }
    else{       // code if : even element are there in original linkedlist
        head1 = head;

        for(int i=1 ; i< count/2 ; i++){
            temp = temp->link;
        }

        head2 = temp->link;
        temp->link = NULL;

        head1 = makeCycle(head1,1);
        head2 = makeCycle(head2,2);
    }

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

    head = makeCycle(head , 1);
    Print(head);


    return 0;
}