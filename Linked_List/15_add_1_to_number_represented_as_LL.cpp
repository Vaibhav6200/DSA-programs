#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* link;

    node(int val){
        data = val;
        link = NULL;
    }
};


// Insert Node at Tail
node* Insert(node* head, int val){
    node* temp = new node(val);
    
    if(head == NULL){
        head = temp;
        return head;
    }
    node * temp1 = head;
    while(temp1->link != NULL)
        temp1 = temp1->link;
    
    temp1->link = temp;

    return head;
}

node* add1(node* head){
    node *temp = head;
        string s ="";
         while(temp != NULL){
            s += to_string(temp->data);
            temp = temp->link;
        }

        temp = head;
        int n = stoi(s);
        n++;

        s = to_string(n);   //again converting to string after incrementing by 1
        int i=0;

        while(i<s.length()){

            if(temp != NULL){
                temp->data = s[i]-'0';
                i++;
                temp = temp->link;
            }
            else{
                // this is condition where our linked list is 9 9 9 9
                node* temp1 = new node(0);
                head = Insert(head , 0);
                i++;
            }
        }
    return head;
}
// print complete linked list
void Print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->link;
    }cout <<"NULL" << endl;
}


int main()
{
    node* head = NULL;

    head = Insert(head , 9);
    head = Insert(head , 9);
    head = Insert(head , 9);
    head = Insert(head , 7);

// here problem is that if we add to this number 9 9 9 9 we get  1 0 0 0 0  but new node is not inserting

    Print(head);

    head = add1(head);
    Print(head);

    head = add1(head);
    Print(head);

    head = add1(head);
    Print(head);

    head = add1(head);
    Print(head);

    head = add1(head);
    Print(head);

    head = add1(head);
    Print(head);

    return 0;
}