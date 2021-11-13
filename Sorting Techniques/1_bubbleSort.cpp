#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int A[], int n){
    bool flag;
    for(int i=0 ; i<n-1 ; i++){
        flag = false;
        for(int j=0 ; j<n-1-i ; j++){
            if(A[j] > A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false) 
            break;
    }
}

int main()
{
    int A[] = {8, 5, 7, 3, 2};

    cout << "Before sorting : ";
    for(int i=0 ; i<5 ; i++)
        cout << A[i] << " ";
    cout << endl;

    bubbleSort(A, 5);

    cout << "After sorting : ";
    for(int i=0 ; i<5 ; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}