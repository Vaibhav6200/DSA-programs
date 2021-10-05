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

node* add_2_numbers_in_LL(node* head1, node* head2){
    node *temp1 = head1;
        string s1 ="";
         while(temp1 != NULL){
            s1 += to_string(temp1->data);
            temp1 = temp1->link;
        }

    node *temp2 = head2;
        string s2 ="";
         while(temp2 != NULL){
            s2 += to_string(temp2->data);
            temp2 = temp2->link;
        }

// again reinitillizing temp's to head's
        temp1 = head1;
        temp2 = head2;
// till now we have strings like this : s1 = "4596" & s2 = "3957"
        int n1 = stoi(s1);          // n1 = 4596 
        int n2 = stoi(s2);          // n2 = 3957 
        int result = n1 + n2;       // result = 8553
        string resultString = "";   
        resultString = to_string(result);   //  resultString = "8553"

// now we have to make a resultant linked list containg summed numbers
        int i=0;
        node* resultant = NULL;      // this is head of resultant string 
        while(i < resultString.length()){
            resultant = Insert(resultant , resultString[i] - '0');
            i++;
        }
    return resultant;
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
    node* head1 = NULL;
    node* head2 = NULL;
    node* result = NULL;

    head1 = Insert(head1 , 4);
    head1 = Insert(head1 , 9);
    head1 = Insert(head1 , 6);

    head2 = Insert(head2 , 3);
    head2 = Insert(head2 , 9);
    head2 = Insert(head2 , 5);
    head2 = Insert(head2 , 7);

cout << "Before adding: " << endl; 
    Print(head1);
    Print(head2);

    result = add_2_numbers_in_LL(head1 , head2);
    Print(result);

    return 0;
}