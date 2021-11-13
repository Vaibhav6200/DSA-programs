#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp; 
}

int partition(int A[], int l, int h){
    int pivot = A[l];
    int i=l, j=h;

    do{
        do{ i++; }while(A[i] <= pivot);
        do{ j--; }while(A[j] > pivot);

        if(i<j) swap(&A[i], &A[j]);
    }while(i<j);

    swap(&A[l], &A[j]);

    return j;
}

void quickSort(int A[], int l, int h){
    int j;
    if(l<h){
        j = partition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j+1, h);
    }
}

int main()
{
    int A[] = {11, 13, 7, 2, 6, 9, 4, 5, 10, 3, INT_MAX};
    cout << "Before sorting : ";
    for(int i=0 ; i<10 ; i++)
        cout << A[i] << " ";
    cout << endl;
    
    quickSort(A, 0, 10);

    cout << "After sorting : ";
    for(int i=0 ; i<10 ; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}