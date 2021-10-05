#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * link;
};

node* head;         // declaring it globally so that we do not need to pass it every time in functions as an agrument

void Insert(int val){
    node* temp = new node();
    
    // (*temp).data = val;
    temp->data = val;
    // (*temp).link = NULL;
    temp->link = NULL;
    
    temp->link = head;
    head = temp;
}

void Print(){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->link;
    }
}

int main()
{
    head = NULL;
    int n,val;
    cout << "Enter value of N: ";
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cout << "Enter element " << (i+1) << ": ";
        cin >> val;
        Insert(val);
    }
        Print();
    return 0;
}