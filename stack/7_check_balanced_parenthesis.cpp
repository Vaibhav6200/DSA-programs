// CHECK WHETHER BRACKETS OF A STRING ARE BALANCED OR NOT

// TEST CASES:
//      }][}}(}][))]
//      [](){()}
//      ()
//      ({}([][]))[]()
//      {)[](}]}]}))}(())(
//      ([[)

#include<bits/stdc++.h>
using namespace std;

#define MaxSize 100
char arr[MaxSize];
int top = -1;

void push(char c){
    if(top == MaxSize-1){
        cout<< "Stack Overflow" << endl;
        return;
    }
    arr[++top] = c;
}

void pop(){
    if(top == -1){
        cout << "No element to pop " << endl;
        return;
    }
    top--;
}

char peek(){
    return arr[top];
}

bool empty(){
    return top == -1;
}

bool checkBalance(string str){
    
    for(int i=0 ; i<str.length() ; i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            push(str[i]);
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
            if(empty()){
                return false;
            }

            else if(str[i] == ')' && peek() != '(' ){
                return false;
            }
            else if(str[i] == '}' && peek() != '{' ){
                return false;
            }
            else if(str[i] == ']' && peek() != '[' ){
                return false;
            }

            else{
                pop();
            }
        }
    }
    return true;
}

int main()
{
    string str = "}][}}(}][))]";
    bool b;
    b = checkBalance(str);
    if(b){
        cout << "Yes! brackets are balanced" << endl;
    }
    else{
        cout << "Brackets are not balanced" << endl;
    }
    return 0;
}