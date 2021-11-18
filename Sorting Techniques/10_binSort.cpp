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

// deletion from head
node* Delete(node* head){
    if(head->link == NULL){
        delete head;
        return NULL;
    }
    node* del = head;
    head = head->link;
    delete del;
    
    return head;
}

// Finds the Maxumum element from the array : "A"
int findMax(int A[], int n){
    int max = INT_MIN;
    for(int i=0 ; i<n ; i++){
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

void binSort(int A[], int n){

    int i, j;
    node ** bins;
    int max = findMax(A, n);
    bins = new node*[max + 1];

// initializing all elements of array "bin" with null pointer
    for(i=0 ; i<max+1 ; i++)
        bins[i] = NULL;

// now iterating over array "A" and making lists in array "bins"
    for(i=0 ; i<n ; i++){
        bins[A[i]] = Insert(bins[A[i]], A[i]);
    }

    i = j = 0;      // i : points to "bins" and j : points to "A" 
    while(i < max+1)
    {
        while(bins[i] != NULL){
            A[j++] = i;
            bins[i] = Delete(bins[i]);
        }
        i++;
    }
}

int main()
{
    int A[] = {11, 13, 7, 2, 6, 9, 4, 5, 10, 3};
    int n=10;

    cout << "Before sorting : ";
    for(int i=0 ; i<n ; i++)
        cout << A[i] << " ";
    cout << endl;
    
    binSort(A, n);

    cout << "After sorting : ";
    for(int i=0 ; i<n ; i++)
        cout << A[i] << " ";
    cout << endl;
    
    return 0;
}