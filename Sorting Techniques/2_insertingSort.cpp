#include<bits/stdc++.h>
using namespace std;

void insertionSort(int A[], int n){

    int i, j, curr, x;;

    // first for loop is for passes this loop will run n-1 times 
    for(i=1 ; i<n ; i++){
        j = i-1;
        x = A[i];
        while(j>=0 && A[j] > x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }


    // Method 2
    // for(i=0 ; i<n-1 ; i++){
    //    curr = A[i+1];
    //    for(j=i; j>=0 ; j--)
    //    {
    //        if(A[j] > curr)
    //            A[j+1] = A[j];
    //        else
    //            break;
    //    }
    //    A[j+1] = curr;
    // }
}

int main()
{
    int A[] = {11, 13, 7, 2, 6, 9, 4, 5, 10, 3};
    cout << "Before sorting : ";
    for(int i=0 ; i<10 ; i++)
        cout << A[i] << " ";
    cout << endl;

    insertionSort(A, 10);

    cout << "After sorting : ";
    for(int i=0 ; i<10 ; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}