#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* link;
};

node* head;

void Insert(int val , int pos){

    node* temp1 = new node();
    temp1->data = val;
    temp1->link = NULL;

    if(pos == 1){
        temp1->link = head;
        head = temp1;
        return;
    }

    node* temp2 = head;
    for(int i=1 ; i<pos-1 ; i++){
        temp2 = temp2->link;
    }
    temp1->link = temp2->link;
    temp2->link = temp1;

}

void Print(){
    node * temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->link;
    }
}

void Delete(int pos){
    if(pos == 1){
        node* del;
        del = head;
        head = head->link;
        delete del;
        return;
    }
    node* temp = head;
    node* del;
    for(int i=1 ; i<pos-1 ; i++){
        temp = temp->link;
    }
    del = temp->link;
    temp->link = temp->link->link;
    delete del;
}

int main()
{
    head = NULL;
    Insert(2,1);
    Insert(3,2);
    Insert(4,1);
    Insert(5,2);
    Print();        // 4 5 2 3
    Delete(1);
    Print();        // 5  2 3
    return 0;
}