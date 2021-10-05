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

node* mid;      // this will point to middle element
node* top = NULL;
node* head = NULL;

void insert(int val){
    node* temp = new node(val);

    if(head == NULL){
        head = top = mid = temp;
    }
    else{
        top->link = temp;
        top = top->link;
    

        // after inserting we have to update our mid pointer
        int count = 0;
        temp = head;
        while(temp != NULL){
            count++;
            temp = temp->link;
        }
        // so total elements we have => count
        int midPosition = ceil(count/2);
        cout << midPosition;
        // temp = head;
        // int i=1;
        // while(i < midPosition){
        //     i++;
        //     temp = temp->link;
        // }
        // mid = temp;
    }
}

void print(){
    node* temp = head;
    while(temp->link != NULL){
        cout << temp->data << "->";
        temp = temp->link;
    }cout << temp->data << endl;
}

void pop(){
    node* del;

    if(top == head){
        del = top;
        head = top = NULL;
        delete del;
        return;
    }
    del = top;
    node* temp = head;
    while(temp->link != top){
        temp = temp->link;
    }
    top = temp;
    temp->link = NULL;
    delete del;
}

int main()
{
    // insert(1);    
    // insert(2);    
    // insert(3);    
    // insert(4);    
    // print();
    // pop();
    // print();
    // insert(5);    
    // insert(6);    
    // insert(7);    
    // print();
    // pop();
    // pop();
    // print();



    insert(1);    
    insert(2);    
    // cout << "Mid element = " << mid->data << endl;
    insert(3);    
    // cout << "Mid element = " << mid->data << endl;



    return 0;
}