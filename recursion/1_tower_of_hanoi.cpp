// METHOD 1

#include<bits/stdc++.h>
using namespace std;

void hanoi(int n , int start , int end , int other){
    if(n == 0){
        return;
    }
    hanoi(n-1 , start , other , end);
    cout << "Move From "<<start << " to " << end << endl;
    hanoi(n-1 , other , end , start);
}

int main()
{
    int n;
    cout << "enter value of n : ";
    cin >> n;
    hanoi(n,1,3,2);       // hanoi(n , source rod , destination rod , helper rod)
    return 0;
}



// METHOD 2

// #include<bits/stdc++.h>
// using namespace std;

// void hanoi(int n , int start , int end){
//     if(n == 0){
//         return;
//     }
//     int other = 6 - (start + end);
//     hanoi(n-1 , start , other);
//     cout << "Move From "<<start << " to " << end << endl;
//     hanoi(n-1 , other , end);
// }

// int main()
// {
//     int n;
//     cout << "enter value of n : ";
//     cin >> n;
//     hanoi(n,1,3);       // hanoi(n , source rod , destination rod)
//     return 0;
// }

