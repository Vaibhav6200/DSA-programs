#include<iostream>
using namespace std;

#define MAX_SIZE 100
int arr[MAX_SIZE];
int top = -1;

void push(int x){
    if(top == MAX_SIZE - 1){
        cout << "Error: Stack Overflow" << endl;
        return;
    }
    arr[++top] = x;
}

void pop(){
    if(top == -1){
        cout << "Error: No element in stack" << endl;
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

int main()
{   
    push(1);
    push(2);
    push(3);
    push(4);
    Top();
    
    pop();
    Top();

    pop();
    pop();
    Top();

    return 0;
}