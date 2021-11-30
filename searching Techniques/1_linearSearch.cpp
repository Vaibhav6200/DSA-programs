// Best Case O(1)
// Worst Case O(N)


#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int A[], int n, int target){

    for(int i=0 ; i<n ; i++){
        if(A[i] == target)
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

    bool flag = linearSearch(A, n, target);
    if(flag)
        cout << "Target Found " << endl;
    else
        cout << "Target NOT Found " << endl;

    return 0;
}