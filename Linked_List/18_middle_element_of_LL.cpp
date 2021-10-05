// Que. Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

// Example 1: 
// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.

// Example 2: 
// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

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

 node* middleNode(node* head) {
        node* temp = head;
        
        int count = 0;
        while(temp!= NULL){
            count++;
            temp = temp->link;
        }
        temp = head;
        int middleElement = count/2 + 1;   // see from example of geeks for geeks
        
        for(int i=1 ; i<middleElement ; i++)
            temp = temp->link;
        
        // now our temp is pointing to middle element so we will set it to head
        head = temp;
        
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


    head = middleNode(head);
    Print(head);

    return 0;
}