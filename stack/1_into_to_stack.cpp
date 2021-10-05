#include<iostream>
using namespace std;

#define MAX_SIZE 100
int arr[MAX_SIZE];
int top = -1;

void push(int value){
    if(top == MAX_SIZE - 1){
        cout << "Error: Stack Overflow" << endl;
        return;
    }
    arr[++top] = value;
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

int main()
{   
    push(1); Print();
    push(2); Print();
    push(3); Print();
    push(4); Print();
    cout << Top() << endl;
    
    pop();
    cout << Top() << endl;

    pop();
    pop();
    cout << Top() << endl;
    pop();
    
    if(empty()){
        cout << "Your stack is now empty" << endl;
    }
    

    return 0;
}