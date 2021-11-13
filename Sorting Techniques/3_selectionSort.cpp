#include<bits/stdc++.h>
using namespace std;

# define I INT_MAX

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp; 
}

void selectionSort(int A[], int n){
    int k, min;
    for(int i=0 ; i<n ; i++){
        min = I;
        for(int j=i ; j<n ; j++){
            if(A[j] < min){
                min = A[j];
                k = j;
            }
        }
        swap(&A[k], &A[i]);
    }
}

int main()
{
    int A[] = {11, 13, 7, 2, 6, 9, 4, 5, 10, 3};
    cout << "Before sorting : ";
    for(int i=0 ; i<10 ; i++)
        cout << A[i] << " ";
    cout << endl;

    selectionSort(A, 10);

    cout << "After sorting : ";
    for(int i=0 ; i<10 ; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}