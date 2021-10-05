// Expression =>  23*54*+9-

// Procedure:
// make a function for postfix evaluation and pass a string to it 
// make a stack to store operand
// loop through each and every character of string 
// and check if s[i] is an operand or a operator 
// for operand push that character in our stack
// if you get any operator , pop out 2 values from stack and perform operation on them
//  and push result again in stack
// finally return top of the stack

#include<bits/stdc++.h>
using namespace std;

int postfixEvaluation(string exp){
    stack<int> S;
    int op1 , op2;
    for(int i=0 ; i<exp.length() ; i++){
        if(exp[i] >= '0' && exp[i] <='9'){
            S.push(exp[i] - '0');
        }
        else{
            op2 = S.top();
            S.pop();

            op1 = S.top();
            S.pop();

            switch(exp[i]){
                case '+':
                    S.push(op1 + op2);
                    break;

                case '-':
                    S.push(op1 - op2);
                    break;

                case '*':
                    S.push(op1 * op2);
                    break;

                case '/':
                    S.push(op1 / op2);
                    break;

                case '^':
                    S.push(op1 ^ op2);
                    break;
            }
        }
    }

    return S.top();
}

int main()
{
    string str = "46+2/5*7+";
    cout << postfixEvaluation(str);
    return 0;
}