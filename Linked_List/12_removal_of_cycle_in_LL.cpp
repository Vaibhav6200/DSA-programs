// make linked list cyclic at a given position

// INPUT:
// head->[1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->NULL

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

// making our linked list cyclic at given position
void makeCycle(int pos){
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
}

// detecting our linked list using floid's algorithm or hare and tortoise algorithm
int detectCycle(){
    node* fast = head;
    node* slow = head;

    while(fast != NULL && fast->link != NULL){
        // moving fast by 2 count and slow by 1 count
        slow = slow->link;
        fast = fast->link->link;

        if(fast == slow){
            return 1;
        }
    }
    return 0;
}


void removeCycle(){
    node* fast = head;
    node* slow = head;

    while(fast != NULL && fast->link != NULL){
        // moving fast by 2 count and slow by 1 count
        slow = slow->link;
        fast = fast->link->link;

        if(fast == slow){
            break;
        }
    }
    // now reset fast to head and iterate a loop and increment both fast and slow pointer by 1
    fast = head;
    while(1){
        fast = fast->link;
        slow = slow->link;

        if(fast->link == slow->link){
            slow->link = NULL;
            break;
        }
    }
}

int main()
{
    head = NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Insert(6);
    Insert(7);
    Insert(8);
    Insert(9);

    Print();

    int n;
    cout << "\nEnter position from where you want to start cycle : ";
    cin >> n;

    makeCycle(n);

    cout << "Before executing removeCycle function" << endl;
    cout << detectCycle() << endl;

    removeCycle();
    cout << "After executing removeCycle function" << endl;
    cout << detectCycle() << endl;
    Print();

    return 0;
}