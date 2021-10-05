#include<bits/stdc++.h>
using namespace std;

stack<int> st;

void insertAtBottom(int n){
    
    if(st.empty()){
        st.push(n);
        return;
    }
    int curr = st.top();
    st.pop();
    insertAtBottom(n);
    st.push(curr);
    return;
}

int main()
{
    st.push(2);
    st.push(1);

cout << "Before" << endl;
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    insertAtBottom(3);

cout << endl << "After" << endl;
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    return 0;
}