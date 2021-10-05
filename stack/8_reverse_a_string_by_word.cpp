// input :- Hey! How are you doing?
// output :- doing? you are How Hey!

#include<bits/stdc++.h>
using namespace std;

void reverse(string str){
    stack<string> st;
    int stIdx = 0;
    
    for(int i=0 ; i<str.length() ; i++){
        string word = "";
        while(str[i] != ' ' && i<str.length()){
            word += str[i];
            i++;
        }  
        st.push(word);
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }cout << endl;
}

int main()
{
    
    string s = "Hey! Vaibhav How are you doing?";
    cout << s << endl;
    reverse(s);

    return 0;
}