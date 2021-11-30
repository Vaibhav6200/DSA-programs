#include<bits/stdc++.h>
using namespace std;

void shellSort(int A[], int n){
    int gap, i, j, temp;

    for(gap = n/2 ; gap >= 1 ; gap /= 2)
    {
        for(i=gap ; i<n ; i++){
            temp = A[i]; 
            j = i - gap;

            while(j>=0 && A[j] > temp){
                A[j + gap] = A[j];
                j = j-gap;
            }
            A[j + gap] = temp;
        }
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n=10;

    shellSort(A, n);
    
    for(int i=0 ; i<n ; i++)
        cout << A[i] << " ";

    return 0;
}