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
    }
}

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
    // after completion of this loop out temp pointer will be at end of our linked list 
    // so we will point it to startNode to start cycle

    temp->link = startNode;
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
    Print();

    return 0;
}