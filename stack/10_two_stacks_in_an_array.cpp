#include<iostream>
using namespace std;

class TwoStack{
public:
    int n;
    int top1, top2;
    int *arr;

    TwoStack(int size){
        arr = new int[size];
        top1 = -1;
        top2 = size;
        n = size;       // making a variable n, so that we can access size all over the class
    }

    void push1(int value){
        if(top1 < top2-1){
            arr[++top1] = value;
        }
        else{
            cout << "Stack Overflow in stack 1" << endl;
        }
    }

    void push2(int value){
        if(top1 < top2-1){
            arr[--top2] = value;
        }
        else{
            cout << "Stack Overflow in stack 2" << endl;
        }
    }

    void pop1(){
        if(top1 == -1){
            cout << "Stack 1 is empty" << endl;
            return;
        }
        top1--;
    }

    void pop2(){
        if(top2 == n){
            cout << "Stack 2 is empty" << endl;
            return;
        }
        top2++;
    }

    void printStack1(){
        if(top1 != -1){
            cout << "Stack 1 : ";
            for(int i=0; i<=top1 ; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    void printStack2(){
        if(top2 != n){
            cout << "Stack 2 : ";
            for(int i=n-1; i>=top2 ; i--){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // int n;
    // cout << "Input Size of array: ";
    // cin >> n;

    TwoStack st(5);

    st.push1(1);
    st.push1(2);

    st.push2(3);
    st.push2(4);
    st.push2(5);

    // st.push1(6);
    st.pop1();
    st.pop1();
    st.pop1();
    st.pop2();
    st.pop2();
    st.pop2();
    st.pop2();

    st.printStack1();
    st.printStack2();


    return 0;
}