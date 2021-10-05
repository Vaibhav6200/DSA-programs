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
}

string InfixToPostfix(string str){
    stack<char> st;
    string result;

    for(int i=0 ; i<str.length() ; i++){
        if( (str[i] >= 'A' && str[i] <= 'Z') ){
// this means our element is an operand so we will append it to our result
            result += str[i];
        }
        else{
// now our element is an operator so we will add it to our stack
// before it we must check that there is an operator of higher precedency already present in stack
// if yes then we have to make our string empty
        while(!st.empty() && precedency(st.top()) >= precedency(str[i]) ){
                result += st.top();
                st.pop();
            }
// now our stack became empty so now we can push our operator
        st.push(str[i]);
        }
    }

// after completion of this loop we have to chaek, that our stack is empty or not
// if not then pop elements and append it to our result
    while(!st.empty()){
        result += st.top();
        st.pop();
    }

    return result;
}

int main()
{
    string str = "A+B*C-D*E/F";
    string result = InfixToPostfix(str);

    cout << "Infix Expression = " << str << endl;
    cout << "Postfix Expression = " << result << endl;

    return 0;
}