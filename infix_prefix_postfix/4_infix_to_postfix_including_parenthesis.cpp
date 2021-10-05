// Example : (a-b/c)*(a/k-l)
// Converting INFIX expression to POSTFIX expression with parenthesis

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

string InfixToPostfix(string str){
    stack<char> st;
    string result;

    for(int i=0 ; i<str.length() ; i++){
        if( (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') ){
            result += str[i];
        }
        else if(str[i] == '(')
            st.push(str[i]);

        else if(str[i] == ')'){
            while(st.top() != '('){
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

    return result;
}

int main()
{
    string str = "(a-b/c)*(a/k-l)";
    string result = InfixToPostfix(str);

    cout << "Infix Expression = " << str << endl;
    cout << "Postfix Expression = " << result << endl;

    return 0;
}