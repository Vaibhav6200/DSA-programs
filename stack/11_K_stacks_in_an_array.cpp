#include<iostream>
using namespace std;

class kStacks{
public:

    int n, top1, top2;
    int * arr;
    int * next;

    kStacks(int size){
        arr = new int[size];
        next = new int[size];
        top1 = top2 = -1;
        n = size;
    }

    void push(int value, int no){
        // no is the stack no in which value is pushed

        if(top1 == n-1)
            cout << "Stack Overflow" << endl;

        next[++top2] = no;
        arr[++top1] = value;
    }

// pop function: this will pop element of that stack whose number user specifies 
    void pop(int no){
        
    }

// Print Function: this will print that stack whose number user specifies
    void Print(int no){

        cout << "Stack " << no << " : ";
        for(int i=0 ; i<n ; i++){
            if(next[i] == no)
                cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    
    kStacks st(9);

    st.push(5, 1);
    st.push(63, 4);
    st.push(8, 3);
    st.push(9, 1);
    st.push(15, 2);
    st.push(12, 2);
    st.push(3, 1);
    st.push(19, 3);
    st.push(21, 2);

    st.Print(1);        // this will print 1st stack
    st.Print(2);
    st.Print(3);
    st.Print(4);

    return 0;
}