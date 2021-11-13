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

void iterative_MergeSort(int A[], int n){
    int p, i, mid, l, h;

    for(p=2 ; p<=n ; p=p*2){
        for(i=0 ; i+p-1 < n ; i=i+p){
            l = i;
            h = i+p-1;
            mid = (l+h)/2;

            merge(A, l, mid, h);
        }
    }
    if(p/2 < n)
        merge(A, 0, (p/2 - 1) , n-1);
}

int main()
{
    int A[] = {11, 13, 7, 2, 6, 9, 4, 5, 10, 3};
    int n=10;

    cout << "Before sorting : ";
    for(int i=0 ; i<n ; i++)
        cout << A[i] << " ";
    cout << endl;
    
    iterative_MergeSort(A, n);

    cout << "After sorting : ";
    for(int i=0 ; i<n ; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}