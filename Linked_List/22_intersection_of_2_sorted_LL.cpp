// Que 21. Given two lists sorted in increasing order, create a new list representing the intersection of 
// the two lists. The new list should be made with its own memory — the original lists should not be changed.

// Example 1:
// Input:
// L1 = 1->2->3->4->6
// L2 = 2->4->6->8
// Output: 2 4 6

// Example 2:
// Input:
// L1 = 10->20->40->50
// L2 = 15->40
// Output: 40


// IDEA:- 
    // make idx array and initialize it to zero
    // LL1 : [1]->[2]->[3]->[4]->[6]
    // iterate LL1 and increment frequency of each number like this:
    // [1,1,1,1,0,1]    // 1,2,3,4 and 6 are incremented by 1
    // LL2 : [2]->[4]->[6]->[8]
    // now iterate LL2 and again increment freq of each number in same idx array
    // [1,2,1,2,0,2,0,1]  // 2,4 and 6 occurs in both list so their count will be 2 in idx array
    // now make a new linkedlist which contains data whose count is 2 in idx array

    // NOTE : for size of idx array we have to find max element in LL1 and LL2



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

// node* findIntersection(node* head1, node* head2){

//     node* temp = head1;
//     int max = 0;
//     while(temp != NULL){
//         if(max < temp->data)
//             max = temp->data;
//         temp = temp->link;
//     }
//     temp = head2;
//     while(temp != NULL){
//         if(max < temp->data)
//             max = temp->data;
//         temp = temp->link;
//     }
    
    
//     // if max = 40  our index array should have index till 40 so make idx array of (max+1)
//     int idx[max + 1] = {0};  
//     int index;
//     temp = head1;
//     while(temp != NULL){
//         index = temp->data;
//         idx[index]++;
//         temp = temp->link;
//     }
//     temp = head2;
//     while(temp != NULL){
//         index = temp->data;
//         idx[index]++;
//         temp = temp->link;
//     }
    
//     // now we have to make linked list of those number whose count is 2 in idx array
//     node* head = NULL;
//     for(int i=0 ; i<max+1 ; i++){
//         if(idx[i] == 2){
            
//             node* newNode = new node(i);
//             if(head == NULL){
//                 head = newNode;
//             }
//             else{
//                 node * temp1 = head;
//                 while(temp1->link != NULL)
//                     temp1 = temp1->link;
                
//                 temp1->link = newNode;
//             }
        
//         }
//     }
//     return head;
// }

node* findIntersection(node* head1, node* head2){
    node* p1 = head1;
    node* p2 = head2;
    node* head = NULL;
    node* tail = NULL;
    
    while(p1 != NULL && p2 != NULL){
        if(p1->data > p2->data)
            p2 = p2->link;
        
        else if(p2->data > p1->data)
            p1 = p1->link;
        
        else{
            // this means both pointers data matches so we will add it to our intersection LL
            node* newNode = new node(p1->data);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->link = newNode;
                tail = tail->link;
            
            }
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    
    return head;
}

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    node* result = NULL;

    head1 = Insert(head1 , 1);
    head1 = Insert(head1 , 3);
    head1 = Insert(head1 , 7);
    head1 = Insert(head1 , 8);
    head1 = Insert(head1 , 9);

    head2 = Insert(head2 , 3);
    head2 = Insert(head2 , 5);
    head2 = Insert(head2 , 9);
    head2 = Insert(head2 , 9);
    head2 = Insert(head2 , 13);
    head2 = Insert(head2 , 14);
    head2 = Insert(head2 , 16);

    Print(head1);
    Print(head2);

    result = findIntersection(head1 , head2);
    Print(result);

    return 0;
}