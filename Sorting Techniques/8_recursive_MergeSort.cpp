#include<bits/stdc++.h>
using namespace std;

void merge(int A[], int l, int mid, int h){
    int i, j, k;
    int B[l+h+1];

    i=k=l;
    j=mid+1;

    while(i<=mid && j<=h){
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while(i<=mid)
        B[k++] = A[i++];

    while(j<=h)
        B[k++] = A[j++];

    for(int i=l ; i<=h ; i++)
        A[i] = B[i];
}

void recursive_MergeSort(int A[], int l, int h){
    int mid;
    if(l<h){

        // Mid will break our array in 2 parts
        mid = (l+h)/2;

        // sort LHS list 
        recursive_MergeSort(A, l, mid);

        // sort RHS list 
        recursive_MergeSort(A, mid+1, h);

        // Now merge our lists
        merge(A, l, mid, h);
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
    
    recursive_MergeSort(A, 0, n-1);

    cout << "After sorting : ";
    for(int i=0 ; i<n ; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}