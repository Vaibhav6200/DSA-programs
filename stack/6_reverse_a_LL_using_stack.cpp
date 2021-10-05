// reversing a linked list using stack




// INCOMPLETE




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

// STACK
#define MAX_SIZE 100
int arr[MAX_SIZE];
int top = -1;

void push(node* value){
    if(top == MAX_SIZE - 1){
        cout << "Error: Stack Overflow" << endl;
        return;
    }
    arr[++top] = (int)value;
}

void pop(){
    if(top == -1){
        cout << "Error: No element to pop" << endl;
        return;
    }
    top--;
}

int Top(){
    return arr[top];
}

bool empty(){
    return (top == -1);
}

void Print(){
    cout << "Stack: ";
    for(int i=0 ; i<=top ; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void reverse(){
    
    // now we will store address elements from starting to end 
    node* temp = head;
    
    while(temp->link != NULL){
        push(temp);
        temp = temp->link;
    }
    push(temp); // this is done to push last node
    head = temp;
    pop();

    while(!empty()){
        temp->link = (node *)Top();
        temp = temp->link;
        pop();
    }
    temp->link = NULL;

}

// Inserting element in linked list
void Insert(int val){

    node* temp = new node(val);
    if(head == NULL){
        head = temp;
        return;
    }

    node* temp1 = head;
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp1->link = temp;
}

// to print elements of linked list
void Print(){
    node * temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->link;
    }
}

int main()
{
    head = NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    cout << "Before reversing : " << endl;
    Print();

    reverse();

    cout << "After reversing : " << endl;
    Print(); 


    return 0;
}