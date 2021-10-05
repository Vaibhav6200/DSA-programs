// Que Given a singly linked list of size N of integers. 
// The task is to check if the given linked list is palindrome or not.

// Idea:
// first we will duplicate given linkedlist
// then reverse duplicated linked list
// compare both linkedlist

// Example 1 (if list is not panildrone) 
// LL1: [1]->[2]->[3]->[4]->[5]->[6]->NULL
// LL2: [6]->[5]->[4]->[3]->[2]->[1]->NULL

// Example 2 (if list is panildrone)
// LL1: [1]->[2]->[3]->[3]->[2]->[1]->NULL
// LL2: [1]->[2]->[3]->[3]->[2]->[1]->NULL
// In this case we will get both LL1 and LL2 same

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

bool isPalindrome(node *head){
        
        
        
        // step 1 : duplicating our linkedlist
        node* temp = head;
        node* head2 = NULL;     // head of our duplicated linkedlist
        
        while(temp != NULL){
            node* newNode = new node(temp->data);
            if(head2 == NULL){
                head2 = newNode;
            }
           else{
                node * temp1 = head2;
                while(temp1->link != NULL)
                    temp1 = temp1->link;
                
                temp1->link = newNode;
           }
           temp = temp->link;
        }
    
    // step 2: reversing our second linkedlist
        node* prevptr = NULL;
        node* currptr = head2;
        node* nextptr;
        
        while(currptr != NULL ){
            nextptr = currptr->link;
            currptr->link = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        head2 = prevptr;
    
    // step 3: now compare LL1 and LL2 (if same then :-> palindrone)
    node* temp1 = head;
    node* temp2 = head2;
    
    while(temp1 != NULL){
        if(temp1->data != temp2->data){
            return 0;
        }  
        temp1 = temp1->link;
        temp2 = temp2->link;
    }
    return 1;
}
int main()
{
    node* head = NULL;

    head = Insert(head , 1);
    head = Insert(head , 2);
    head = Insert(head , 3);
    // head = Insert(head , 3);
    // head = Insert(head , 2);
    head = Insert(head , 1);

    Print(head);

    bool result;
    result = isPalindrome(head);
    cout << result;

    return 0;
}