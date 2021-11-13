#include<bits/stdc++.h>
using namespace std;

int * merge(int A[], int B[], int m, int n){
    int i, j, k;
    i=j=k=0;
    int * C = new int[m+n];
    while(i<m && j<n){
        if(A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while(i<m)
        C[k++] = A[i++];

    while(j<n)
        C[k++] = B[j++];

    return C;
}

int main()
{
    int A[] = {2, 10, 18, 20, 23};
    int B[] = {4, 9, 19, 25};

    int * C = merge(A, B, 5, 4);

    cout << "List A : ";
    for(int i=0 ; i<5 ; i++)
        cout << A[i] << " ";
    cout << endl;

    cout << "List B : ";
    for(int i=0 ; i<4 ; i++)
        cout << B[i] << " ";
    cout << endl;

    cout << "merged List C : ";
    for(int i=0 ; i<9 ; i++)
        cout << C[i] << " ";
    cout << endl;

    return 0;
}