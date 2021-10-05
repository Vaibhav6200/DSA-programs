#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node * link;
};

struct node * head;     // global variable, can be accessed anywhere

void Insert(int x){
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->link = NULL;
    temp->link = head;
    head = temp;
}

void Print(){
    struct node* temp = head; 
    while(temp->link != NULL){
        printf("%d" , temp->data);
        temp = temp->link;
    }
}

int main(){
    head = NULL;
    int n,x;
    printf("Enter how many numbers you want to insert : ");
    scanf("%d",n);
    for(int i=0 ; i<n ; i++){
        printf("Enter number %d : " , i+1);
        scanf("%d",&x);
        Insert(x);      // we will insert this element in our linked list 
        Print();        // we will print all elements of our linked list
    }
    return 0;
}