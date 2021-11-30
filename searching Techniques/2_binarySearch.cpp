// for binary search first we need to sort our array 
// Best Case O(1)
// Worst Case O(N)

#include<bits/stdc++.h>
using namespace std;

void insertionSort(int A[], int n){
    int i, j, temp;

    for(i=1 ; i<n ; i++)
    {   
        temp = A[i];
        j=i-1; 
        while(j>=0 && A[j]>temp){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    }
}

bool binarySearch(int A[], int n, int key){
    int st = 0;
    int end = n-1;
    int mid;

    while(st <= end){
        mid = (st + end) / 2;

        if(A[mid] < key)
            st = mid+1;

        else if (A[mid] > key)
            end = mid - 1;

        else 
            return true;
    }

    return false;
}

int main()
{
    int A[] = {7, 12 , 5, 22, 13, 32};
    int n = 6;
    int target;

    cout << "Array : ";
    for(int i=0 ; i<n ; i++)
        cout << A[i] << " ";

    cout << "\nEnter Target : ";
    cin >> target;

    // first we need to sort our array
    insertionSort(A, n);

    // now we can apply binary search her
    bool flag = binarySearch(A, n, target);
    if(flag)
        cout << "Target Found " << endl;
    else
        cout << "Target NOT Found " << endl;

    return 0;
}