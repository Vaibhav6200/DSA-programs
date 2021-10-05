// Converting an Infix expression to its Prefix expression with parenthesis
// Example : 
// INPUT: (a-b/c)*(a/k-l)
// OUTPUT: *-a/bc-/akl


#include<bits/stdc++.h>
using namespace std;

// Function to return precedency
int precedency(char c){
    if(c == '^')
        return 3;

    else if(c == '*' || c == '/')
        return 2;

    else if(c == '+' || c == '-')
        return 1;
    else 
        return -1;
}

// Function to reverse a string 
string reverse(string s){
    stack<char> st;
    string reverseString;
    for(int i=0 ; i<s.length() ; i++){
        st.push(s[i]);
    }
    
    while(!st.empty()){
        reverseString += st.top();
        st.pop();
    }
    return reverseString;
}

string InfixToPrefix(string str){
    stack<char> st;
    string result;

    str = reverse(str);

    for(int i=0 ; i<str.length() ; i++){
        if( (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') ){
            result += str[i];
        }
        else if(str[i] == ')')
            st.push(str[i]);

        else if(str[i] == '('){
            while(st.top() != ')'){
                result += st.top();
                st.pop();
            }
        st.pop();  // done to remove '(' opening parenthesis
        }

    // operator
        else{
            while(!st.empty() && precedency(st.top()) >= precedency(str[i])){
                result += st.top();
                st.pop();
            }
            st.push(str[i]);   //now we will push our current operator
        }
    }
    // now we have to check whether our stack is empty or not if not we have to pop everything out
    while(!st.empty()){
        result += st.top();
        st.pop();
    }

    result = reverse(result);
    return result;
}

int main()
{
    string str = "(a-b/c)*(a/k-l)";
    string result = InfixToPrefix(str);

    cout << "Infix Expression = " << str << endl;
    cout << "Postfix Expression = " << result << endl;

    return 0;
}