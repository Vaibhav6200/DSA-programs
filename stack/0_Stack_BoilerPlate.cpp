#include<iostream>
using namespace std;

#define n 100

class stack{
    int top;
    char * arr;

public: 
    stack(){
        arr = new char[n];
        top = -1;
    }

    void push(int val){
        if(top == n-1){
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = val; 
    }

    void pop(){
        if(top == -1){
            cout << "No element to POP" << endl;
            return;
        }
        top--;
    }

    char Top(){
        return arr[top];
    }
    bool empty(){
        return (top == -1);
    }
};

int main()
{
    stack st;
    
    return 0;
}