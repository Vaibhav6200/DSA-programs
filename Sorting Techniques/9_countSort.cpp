#include<bits/stdc++.h>
using namespace std;

int findMax(int A[], int n){
    int max = INT_MIN;
    for(int i=0 ; i<n ; i++){
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

void countSort(int A[], int n){

    int max = findMax(A, n);
    int count[max + 1] = {0};

    for(int i=0 ; i<n ; i++)
        count[A[i]]++;

    int i=0, j=0;       // j will iterate over array : "A" and i will iterate over array : "count"
    while(i < max+1){
        if(count[i] > 0){
            A[j++] = i;
            count[i]--;
        }
        else
            i++;
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
    
    countSort(A, n);

    cout << "After sorting : ";
    for(int i=0 ; i<n ; i++)
        cout << A[i] << " ";
    cout << endl;
    
    return 0;
}