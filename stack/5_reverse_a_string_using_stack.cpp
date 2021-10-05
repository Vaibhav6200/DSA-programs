// reversing a string using stack
#include<bits/stdc++.h>
using namespace std;

void reverse(string  &str , int n){
    stack<char> S;
    
    // push characters of string in stack
    for(int i=0 ; i<n ; i++){
        S.push(str[i]);
    }

    // reversing string 
    for(int i=0 ; i<n ; i++){
        str[i] = S.top();
        S.pop();
    }
}

int main()
{
    string str = "Hello";
    cout << "Before reversing: " << str << endl;
    
    reverse(str, str.length());
    cout << "After reversing: " << str << endl;
    return 0;
}