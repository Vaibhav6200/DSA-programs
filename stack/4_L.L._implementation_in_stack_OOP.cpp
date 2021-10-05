// linked list implementation of stack in OOP

#include<bits/stdc++.h>
using namespace std;

// first we will make a class for our node
class node{

// private:
public:     // here we will use concept of encapsulation 
    int Data;
    node* Link;

    // we will create a constructor fo that har baar hume link aur data set na krna pde code m
    node(int data){
        Data = data;
        Link = NULL;
    }

    // creating some setters and getters to access our private data
    // void setData(int data){
    //     Data = data;
    // }
    // int getData(){
    //     return Data;
    // }
    // node* getLink(){
    //     return Link;
    // }
    // node* setLink(node* link){
    //     Link = link;
    // }
};

node * Top;     // its pointer to the top of our stack

// Creating Push function for our stack
// NOTE: push will push our data to head
void push(int data){
    node* temp = new node(data);    // this will create a new node for us with data given by user

    // condition if Top == null
    if(Top == NULL){
        Top = temp;
        return;
    }
    temp->Link = Top;
    Top = temp;
}

// This function returns top value of our stack
int peek(){
    if(Top == NULL){
        cout << "No element in stack" << endl;
        return 0;
    }
    return Top->Data;
}

// This function pops top value
void pop(){
    node * Delete = Top;
// we have stored node which we have to delete in this pointer
// now we set Top top next node
// Delete->getLink() gives the address of next node

    if(Top == NULL){
        cout << "No element to pop" << endl;
        return;
    }
    Top =  Delete->Link; 
    delete Delete;
}

int main()
{
    Top = NULL;

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