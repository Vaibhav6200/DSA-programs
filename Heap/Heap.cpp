#include<bits/stdc++.h>
using namespace std;

void Insert(int A[], int n){
    int i = n;
    int temp = A[i];

    while(i>1 && temp > A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}   

int Delete(int A[] , int n){       // n = size of array (used for purpose of heap sort)
    int x = A[n];
    int val = A[1];     // this is the value which is to be deleted
    A[1] = A[n];
    A[n] = val;

    int i=1;
    int j = 2*i;

    // Now compare x 
    while(j < n-1){
        if(A[j+1] > A[j])
            j = j + 1;
        
        if(A[i] < A[j]){
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;

            i = j;
            j = 2*i;
        }
        else 
            break;

    }
    return val;
}

void display(int H[], int n){
    for(int i=1 ; i<=n ; i++)
        cout << H[i] << " ";
    cout << endl;
}

int main()
{
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};

    for(int i=2 ; i<=7 ; i++)
        Insert(H, i);

    cout << "Given Array : ";
    display(H, 7);

    // cout << "Deleted value : " << Delete(H, 7) << "\n";

    // Heap sort
    cout << "Heap Sorted Array : ";
    for(int i=7 ; i>1 ; i--){
        Delete(H, i);
    }
    display(H, 7);


    return 0;
}