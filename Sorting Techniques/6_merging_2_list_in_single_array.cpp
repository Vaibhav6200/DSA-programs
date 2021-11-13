#include<bits/stdc++.h>
using namespace std;

void merge(int A[], int l, int h){
    int i, j, k, mid;
    int B[l+h+1];

    mid = (l+h)/2;
    i=k=l;
    j=mid+1;

    // our 1st list is from l to mid and 2nd list is from mid+1 to h
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

    // coping all values of B in A
    for(int i=l ; i<=h ; i++)
        A[i] = B[i];
}

int main()
{
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};

    cout << "Before Merging : ";
    for(int i=0 ; i<=7 ; i++)
        cout << A[i] << " ";
    cout << endl;

    merge(A, 0, 7);

    cout << "After Merging  : ";
    for(int i=0 ; i<=7 ; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}