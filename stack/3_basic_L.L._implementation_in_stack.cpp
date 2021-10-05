#include<iostream>
using namespace std;

struct node{
    int data;
    node* link;
};

node* top;

void push(int data){
    node* temp = new node();
    temp->data = data;
    temp->link = NULL;

    if(top == NULL){
        top = temp;    
        return;
    }
    temp->link = top;
    top = temp;
}

void pop(){
    node* Delete = top;
    if(top == NULL){
        cout << "No element to pop" << endl;
        return;
    }
    top = Delete->link;
    // top->link = top->link->link;
    delete Delete;
}

int peek(){
    if(top == NULL){
        cout << "No element in stack " << endl;
        return 0;
    }
    return top->data;
}

bool empty(){
    return top->link == NULL;
}

int main()
{
    top = NULL;

    push(1);
    push(2);
    push(3);
    push(4);
    cout << peek() << endl;
    pop();
    cout << peek() << endl;
    pop();
    pop();
    pop();
    cout << peek() << endl;
    pop();
    return 0;
}